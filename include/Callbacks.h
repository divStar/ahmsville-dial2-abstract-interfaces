//
// Created by Igor Voronin on 18.08.23.
//

#ifndef DIAL2HARDWARESENSORS_CALLBACKS_H
#define DIAL2HARDWARESENSORS_CALLBACKS_H

#include <functional>

namespace Callbacks {
using MacroKeyCallbackType =
    std::function<void(const char *type, int keyId, int pin, unsigned long riseTime, unsigned long fallTime, bool isPressed)>;
}

#endif // DIAL2HARDWARESENSORS_CALLBACKS_H
