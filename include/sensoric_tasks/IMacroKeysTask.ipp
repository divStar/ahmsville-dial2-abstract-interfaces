#include "IMacroKeysTask.h" // needed so CLion recognizes the template

namespace AbstractTasks {

template <typename MacroKeysType>
IMacroKeysTask<MacroKeysType>::IMacroKeysTask(MacroKeysType &sensor)
    : ISensoricTask<MacroKeysType>(sensor, ISensoricTask<MacroKeysType>::DEFAULT_NAME) {
}

} // namespace AbstractTasks