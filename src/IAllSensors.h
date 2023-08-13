#ifndef DIALER_IALLSENSORS_H
#define DIALER_IALLSENSORS_H

#include "ICapacitiveSensorAdapter.h"
#include "IHapticSensorAdapter.h"
#include "IMacroKeys.h"
#include "IRotaryEncoderAdapter.h"
#include "ISpaceNavigatorSensorAdapter.h"

class IAllSensors {
public:
  /**
   * @brief Creates the sensor adapters depending on the concrete implementation.
   */
  virtual void createSensorAdapters() = 0;

  /**
   * @return (IMacroKeys) returns the macro keys sensor adapter
   */
  virtual IMacroKeys &getMacroKeys() = 0;

  /**
   * @return (IRotaryEncoderAdapter) returns the upper knob sensor adapter
   */
  virtual IRotaryEncoderAdapter &getUpperKnobSensor() = 0;

  /**
   * @return (IRotaryEncoderAdapter) returns the lower knob sensor adapter
   */
  virtual IRotaryEncoderAdapter &getLowerKnobSensor() = 0;

  /**
   * @return (IHapticSensorAdapter) returns the haptic sensor adapter
   */
  virtual IHapticSensorAdapter &getHapticSensor() = 0;

  /**
   * @return (ICapacitiveSensorAdapter) returns the capacitive sensor adapter
   */
  virtual ICapacitiveSensorAdapter &getCapacitiveSensor() = 0;

  /**
   * @return (ISpaceNavigatorSensorAdapter) returns the space navigator sensor adapter
   */
  virtual ISpaceNavigatorSensorAdapter &getSpaceNavigatorSensors() = 0;
};

#endif // DIALER_IALLSENSORS_H
