#include "ISensoricTask.h" // needed so CLion recognizes the template

namespace AbstractTasks {

template <typename SensorType> ISensoricTask<SensorType>::ISensoricTask(SensorType &sensor, const char *name) : sensor(sensor), name(name) {
}

template <typename SensorType> SensorType &ISensoricTask<SensorType>::getSensor() {
  return this->sensor;
}

template <typename SensorType> const char *ISensoricTask<SensorType>::getName() {
  return this->name;
}

} // namespace AbstractTasks
