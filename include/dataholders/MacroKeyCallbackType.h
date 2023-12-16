#ifndef DIAL2_ABSTRACT_MACROKEYCALLBACKTYPE_H
#define DIAL2_ABSTRACT_MACROKEYCALLBACKTYPE_H

#include <functional>

namespace DataHolders {

/**
 * @brief Callback function type, that is used when a MacroKey changes its state.
 */
using MacroKeyCallbackType =
    std::function<void(const char *type, int keyId, int pin, unsigned long riseTime, unsigned long fallTime, bool isPressed)>;

} // namespace DataHolders

#endif // DIAL2_ABSTRACT_MACROKEYCALLBACKTYPE_H
