#include "ILedsTask.h" // needed so CLion recognizes the template

namespace AbstractTasks {

template <typename LedType, typename LedsType>
ILedsTask<LedType, LedsType>::ILedsTask(LedsType &sensor) : ISensoricTask<LedsType>(sensor, ISensoricTask<LedsType>::DEFAULT_NAME) {
}

} // namespace AbstractTasks