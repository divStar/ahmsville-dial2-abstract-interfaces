#ifndef DIAL2_ABSTRACT_LEDSTASK_H
#define DIAL2_ABSTRACT_LEDSTASK_H

#include <sensors/ILed.h>
#include <sensors/ILeds.h>
#include "general_tasks/ISensoricTask.h"
#include <type_traits>

namespace AbstractTasks {

template <typename LedType, typename LedsType> class ILedsTask : public ISensoricTask<LedsType> {
  static_assert(std::is_base_of<AbstractSensors::ILed, LedType>::value, "LedType must be derived from AbstractSensors::ILed");
  static_assert(std::is_base_of<AbstractSensors::ILeds<LedType>, LedsType>::value,
                "LedsType<LedType> must be derived from AbstractSensors::ILeds<LedType>");

public:
  explicit ILedsTask(LedsType &sensor);
};

} // namespace AbstractTasks

#include "ILedsTask.ipp"

#endif // DIAL2_ABSTRACT_LEDSTASK_H
