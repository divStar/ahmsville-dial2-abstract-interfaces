#ifndef DIAL2_ABSTRACT_SPACENAVIGATORTASK_H
#define DIAL2_ABSTRACT_SPACENAVIGATORTASK_H

#include <sensors/ISpaceNavigator.h>
#include "general_tasks/ISensoricTask.h"
#include <type_traits>

namespace AbstractTasks {

template <typename SpaceNavigatorType> class ISpaceNavigatorTask : public ISensoricTask<SpaceNavigatorType> {
  static_assert(std::is_base_of<AbstractSensors::ISpaceNavigator, SpaceNavigatorType>::value,
                "SpaceNavigatorType must be derived from AbstractSensors::ISpaceNavigator");

public:
  explicit ISpaceNavigatorTask(SpaceNavigatorType &sensor);
};

} // namespace AbstractTasks

#include "ISpaceNavigatorTask.ipp"

#endif // DIAL2_ABSTRACT_SPACENAVIGATORTASK_H
