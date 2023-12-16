#include "ICapacitiveTask.h" // needed so CLion recognizes the template

namespace AbstractTasks {

template <typename CapacitiveType>
ICapacitiveTask<CapacitiveType>::ICapacitiveTask(CapacitiveType &sensor)
    : ISensoricTask<CapacitiveType>(sensor, ISensoricTask<CapacitiveType>::DEFAULT_NAME) {
}

} // namespace AbstractTasks