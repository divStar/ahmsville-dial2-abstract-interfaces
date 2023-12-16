#ifndef DIAL2_ABSTRACT_HAPTICTASK_H
#define DIAL2_ABSTRACT_HAPTICTASK_H

#include <sensors/IHaptic.h>
#include "general_tasks/ISensoricTask.h"
#include <type_traits>

namespace AbstractTasks {

template <typename HapticType> class IHapticTask : public ISensoricTask<HapticType> {
  static_assert(std::is_base_of<AbstractSensors::IHaptic, HapticType>::value,
                "HapticType must be derived from AbstractSensors::IHaptic");

public:
  explicit IHapticTask(HapticType &sensor);
};

} // namespace AbstractTasks

#include "IHapticTask.ipp"

#endif // DIAL2_ABSTRACT_HAPTICTASK_H
