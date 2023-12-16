#ifndef DIAL2_ABSTRACT_CAPACITIVETASK_H
#define DIAL2_ABSTRACT_CAPACITIVETASK_H

#include <sensors/ICapacitive.h>
#include "general_tasks/ISensoricTask.h"
#include <type_traits>

namespace AbstractTasks {

template <typename CapacitiveType> class ICapacitiveTask : public ISensoricTask<CapacitiveType> {
  static_assert(std::is_base_of<AbstractSensors::ICapacitive, CapacitiveType>::value,
                "CapacitiveType must be derived from AbstractTasks::ICapacitive");

public:
  explicit ICapacitiveTask(CapacitiveType &sensor);
};

} // namespace AbstractTasks

#include "ICapacitiveTask.ipp"

#endif // DIAL2_ABSTRACT_CAPACITIVETASK_H
