#ifndef DIAL2_ABSTRACT_MACROKEYSTASK_H
#define DIAL2_ABSTRACT_MACROKEYSTASK_H

#include <sensors/IMacroKeys.h>
#include "general_tasks/ISensoricTask.h"
#include <type_traits>

namespace AbstractTasks {

template <typename MacroKeysType> class IMacroKeysTask : public ISensoricTask<MacroKeysType> {
  static_assert(std::is_base_of<AbstractSensors::IMacroKeys, MacroKeysType>::value,
                "MacroKeysType must be derived from AbstractSensors::IMacroKeys");

public:
  explicit IMacroKeysTask(MacroKeysType &sensor);
};

} // namespace AbstractTasks

#include "IMacroKeysTask.ipp"

#endif // DIAL2_ABSTRACT_MACROKEYSTASK_H
