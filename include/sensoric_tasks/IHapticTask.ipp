#include "IHapticTask.h" // needed so CLion recognizes the template

namespace AbstractTasks {

template <typename HapticType>
IHapticTask<HapticType>::IHapticTask(HapticType &sensor) : ISensoricTask<HapticType>(sensor, ISensoricTask<HapticType>::DEFAULT_NAME) {
}

} // namespace AbstractTasks