#include "IKnobTask.h" // needed so CLion recognizes the template

namespace AbstractTasks {

template <typename RotaryEncoderType>
IKnobTask<RotaryEncoderType>::IKnobTask(RotaryEncoderType &sensor, const char *name) : ISensoricTask<RotaryEncoderType>(sensor, name) {
}

} // namespace AbstractTasks