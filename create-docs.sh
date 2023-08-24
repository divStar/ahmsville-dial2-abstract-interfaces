#!/bin/bash
# Definitions
libraryJsonFilename="library.json"
doxyFilename="./doxy-config/Doxyfile"
targetDir="./public"
miscDir="./misc"

declare -A mappings
mappings["LIBRARY_JSON_NAME"]=".name"
mappings["LIBRARY_JSON_DESCRIPTION"]=".description"
mappings["LIBRARY_JSON_VERSION"]=".version"
mappings["LIBRARY_JSON_AUTHOR"]=".authors.name"
mappings["LIBRARY_JSON_LOGO"]=".logo"

ERROR_COLOR=""
SUCCESS_COLOR=""
RESET=""
if [ -t 1 ]; then
    ERROR_COLOR="\033[91m"
    SUCCESS_COLOR="\033[92m"
    RESET="\033[0m"
fi

# Functions
logError() {
    # Check if the first argument is a number (i.e., an error code)
    if [[ "$1" =~ ^[0-9]+$ ]]; then
        errorCode="$1"
        shift
    else
        unset errorCode
    fi

    printf "$ERROR_COLOR%s$RESET\n" "$*" >&2

    # If errorCode is set, then exit with that code
    if [[ -n "$errorCode" ]]; then
        exit "$errorCode"
    fi
}

logSuccess() {
    printf "$SUCCESS_COLOR%s$RESET\n" " ✔ DONE"
}

logInfo() {
    printf "%s" "$*"
}

# Main script
# Check if 'jq' is installed
logInfo "Checking if 'jq' is installed..."
if ! command -v jq > /dev/null 2>&1; then
  logError " ✖ FAILED"
  logError 1 "'jq' was not found. Aborting docs generation!"
else
  logSuccess
fi

# Check if 'doxygen' is installed
logInfo "Checking if 'doxygen' is installed..."
if ! command -v doxygen > /dev/null 2>&1; then
  logError " ✖ FAILED"
  logError 1 "'doxygen' was not found. Aborting docs generation!"
else
  logSuccess
fi

# Find mappings and build 'jq' filter
logInfo "Finding mappings and building 'jq' filter..."
jq_filter='{'
for key in "${!mappings[@]}"; do
  value="${mappings[$key]}"
  jq_filter+="$key: $value,"
done
jq_filter=${jq_filter%,}  # Remove trailing comma
jq_filter+='} | to_entries[] | "export \(.key)=\"\(.value)\""'
logSuccess

# Retrieve values using 'jq'
logInfo "Retrieving values from '$libraryJsonFilename'..."
unset PLACEHOLDERS
declare -a PLACEHOLDERS

tmpfile=$(mktemp)
trap 'rm -f "$tmpfile"' EXIT

jq_output=$(jq -r "$jq_filter" "$libraryJsonFilename" 2>"$tmpfile")
jq_exit_status=$?

if [[ $jq_exit_status -eq 0 ]]; then
    IFS=$'\n' read -rd '' -a PLACEHOLDERS <<< "$jq_output"
    logSuccess
    rm "$tmpfile"
    for placeholder in "${PLACEHOLDERS[@]}"; do
        printf "   %s\n" "${placeholder:7}"
    done
else
    jq_error=$(cat "$tmpfile")
    rm "$tmpfile"
    logError " ✖ FAILED"
    logError "$jq_error"
    logError 2 "Could not retrieve values from '$libraryJsonFilename'!"
fi
eval "${PLACEHOLDERS[*]}"

# Delete existing target directory before generating anew
logInfo "Deleting '$targetDir' directory..."
if [[ -d "$targetDir" && -n "$targetDir" ]]; then
    rm -rf "$targetDir"
fi
logSuccess

# Process environment variables on header and footer HTML templates
logInfo "Preprocess 'doxy-header-template.html' and 'doxy-footer-template.html'..."
# Extract variable names from PLACEHOLDERS (just the LIBRARY_JSON_* part), prepend each with a '$' and join using ','
VARS_TO_SUBST=""
for exp in "${PLACEHOLDERS[@]}"; do
    var_name="${exp#* }"
    var_name="${var_name%%=*}"
    if [ -z "$VARS_TO_SUBST" ]; then
        VARS_TO_SUBST="\$$var_name"
    else
        VARS_TO_SUBST="$VARS_TO_SUBST,\$$var_name"
    fi
done
# Filter header and footer HTML files
envsubst "$VARS_TO_SUBST" < "./doxy-config/doxy-header-template.html" > "./doxy-config/doxy-header.html"
envsubst "$VARS_TO_SUBST" < "./doxy-config/doxy-footer-template.html" > "./doxy-config/doxy-footer.html"
logSuccess

# Generate docs using doxygen
logInfo "Generating docs using 'doxygen $doxyFilename'..."
if DOXYGEN_RUN=$(doxygen "$doxyFilename" 2>&1 >/dev/null); then
  logSuccess
else
  logError " ✖ FAILED"
  logError "doxygen failed to generate docs!"
  logError 3 "$DOXYGEN_RUN"
fi

# Copy misc directory contents to public directory
logInfo "Copying .$miscDir/* to .$targetDir/..."
cp "$miscDir/"* "$targetDir"
logSuccess

# Remove doxy-header.html and doxy-footer.html after generating the docs
logInfo "Deleting 'doxy-header.html' and 'doxy-footer.html'..."
rm -f "./doxy-config/doxy-header.html"
rm -f "./doxy-config/doxy-footer.html"
logSuccess