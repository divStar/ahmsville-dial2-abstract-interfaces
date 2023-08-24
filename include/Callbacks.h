#ifndef DIAL2HARDWARESENSORS_CALLBACKS_H
#define DIAL2HARDWARESENSORS_CALLBACKS_H

#include <functional>

/**
 * @namespace    Callbacks
 * @brief        Namespace containing callback function types.
 *
 * @author  Igor Voronin
 * @date    19.08.2023
 */
namespace Callbacks {

/**
 * @brief Callback function type, that is used when a MacroKey changes its state.
 */
using MacroKeyCallbackType =
    std::function<void(const char *type, int keyId, int pin, unsigned long riseTime, unsigned long fallTime, bool isPressed)>;

} // namespace Callbacks

#endif // DIAL2HARDWARESENSORS_CALLBACKS_H
