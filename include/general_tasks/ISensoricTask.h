//
// Created by Igor Voronin on 06.12.23.
//

#ifndef DIAL2_ABSTRACT_SENSORICTASK_H
#define DIAL2_ABSTRACT_SENSORICTASK_H

namespace AbstractTasks {

template <typename SensorType> class ISensoricTask {
public:
  static constexpr auto DEFAULT_NAME = "default";

  virtual ~ISensoricTask() = default;

protected:
  explicit ISensoricTask(SensorType &sensor, const char *name);

  SensorType &getSensor();

  const char *getName();

private:
  [[maybe_unused]] SensorType &sensor;
  [[maybe_unused]] const char *name;
};

} // namespace AbstractTasks

#include "ISensoricTask.ipp"

#endif // DIAL2_ABSTRACT_SENSORICTASK_H
