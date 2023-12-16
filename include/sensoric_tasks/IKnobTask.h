#ifndef DIAL2_ABSTRACT_KNOBTASK_H
#define DIAL2_ABSTRACT_KNOBTASK_H

#include <sensors/IRotaryEncoder.h>
#include "general_tasks/ISensoricTask.h"
#include <type_traits>

namespace AbstractTasks {

template <typename RotaryEncoderType> class IKnobTask : public ISensoricTask<RotaryEncoderType> {
  static_assert(std::is_base_of<AbstractSensors::IRotaryEncoder, RotaryEncoderType>::value,
                "RotaryEncoderType must be derived from AbstractSensors::IRotaryEncoder");

public:
  explicit IKnobTask(RotaryEncoderType &sensor, const char *name);
};

} // namespace AbstractTasks

#include "IKnobTask.ipp"

#endif // DIAL2_ABSTRACT_KNOBTASK_H
