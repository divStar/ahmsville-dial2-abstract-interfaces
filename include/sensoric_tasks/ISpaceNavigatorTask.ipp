#include "ISpaceNavigatorTask.h" // needed so CLion recognizes the template

namespace AbstractTasks {

template <typename SpaceNavigatorType>
ISpaceNavigatorTask<SpaceNavigatorType>::ISpaceNavigatorTask(SpaceNavigatorType &sensor)
    : ISensoricTask<SpaceNavigatorType>(sensor, ISensoricTask<SpaceNavigatorType>::DEFAULT_NAME) {
}

} // namespace AbstractTasks