function capitalizeFirstLetter(string) {
    return string.charAt(0).toUpperCase() + string.slice(1);
}

document.addEventListener('DOMContentLoaded', function () {
    const currentPath = window.location.pathname;

    fetch(RELPATH + '../doc-versions.json')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(versionsData => {
            const dropdown = document.getElementById('customDropdown');
            const display = dropdown.querySelector('.dropdown-display');
            const displayText = display.querySelector('span');
            const displayHintImg = display.querySelector('.display-hint');
            const optionsContainer = dropdown.querySelector('.dropdown-options');

            display.addEventListener('click', function () {
                optionsContainer.style.display = optionsContainer.style.display === 'none' ? 'flex' : 'none';
            });

            versionsData.forEach(version => {
                const optionDiv = document.createElement('div');
                optionDiv.classList.add('option');
                optionDiv.textContent = version.version;

                const hintImg = document.createElement('img');
                hintImg.src = `${RELPATH}${version.hint}.svg`;
                hintImg.alt = capitalizeFirstLetter(version.hint);
                hintImg.title = capitalizeFirstLetter(version.hint);
                hintImg.classList.add('hint');

                optionDiv.appendChild(hintImg);

                optionDiv.addEventListener('click', function () {
                    window.location.href = version.url;
                });

                optionsContainer.appendChild(optionDiv);

                // Check if the current URL path matches this version's URL
                if (currentPath.includes(version.version)) {
                    displayText.textContent = version.version;
                    displayHintImg.src = `${RELPATH}${version.hint}.svg`;
                    displayHintImg.title = capitalizeFirstLetter(version.hint);
                    displayHintImg.alt = capitalizeFirstLetter(version.hint);
                }
            });
        })
        .catch(error => {
            console.log('There was a problem fetching the versions:', error.message);
        });

    document.addEventListener('click', function (event) {
        const dropdown = document.getElementById('customDropdown');
        const display = dropdown.querySelector('.dropdown-display');
        const optionsContainer = dropdown.querySelector('.dropdown-options');

        if (!dropdown.contains(event.target)) {  // If click was outside of the dropdown
            optionsContainer.style.display = 'none';
        }
    });
});