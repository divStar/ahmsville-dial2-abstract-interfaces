#ifndef DIALER_IALLSENSORS_H
#define DIALER_IALLSENSORS_H

#include "ICapacitiveSensorAdapter.h"
#include "IHapticSensorAdapter.h"
#include "IMacroKeys.h"
#include "IRotaryEncoderAdapter.h"
#include "ISpaceNavigatorSensorAdapter.h"

/**
 * @namespace   AbstractSensors
 * @brief       This namespace contains all abstractions of the sensors of the AhmsVille Dial 2 device.
 *
 * @author      Igor Voronin
 * @date        20.08.2023
 */
namespace AbstractSensors {

/**
 * @class   IAllSensors
 * @brief   Interface to decouple all actual sensors.
 *
 * @author  Igor Voronin
 * @date    13.08.2023
 */
class IAllSensors {
public:
  /**
   * @return (IMacroKeys) returns the macro keys sensor adapter
   */
  virtual AbstractSensors::IMacroKeys &getMacroKeys() = 0;

  /**
   * @return (IRotaryEncoderAdapter) returns the upper knob sensor adapter
   */
  virtual AbstractSensors::IRotaryEncoderAdapter &getUpperKnobSensor() = 0;

  /**
   * @return (IRotaryEncoderAdapter) returns the lower knob sensor adapter
   */
  virtual AbstractSensors::IRotaryEncoderAdapter &getLowerKnobSensor() = 0;

  /**
   * @return (IHapticSensorAdapter) returns the haptic sensor adapter
   */
  virtual AbstractSensors::IHapticSensorAdapter &getHapticSensor() = 0;

  /**
   * @return (ICapacitiveSensorAdapter) returns the capacitive sensor adapter
   */
  virtual AbstractSensors::ICapacitiveSensorAdapter &getCapacitiveSensor() = 0;

  /**
   * @return (ISpaceNavigatorSensorAdapter) returns the space navigator sensor adapter
   */
  virtual AbstractSensors::ISpaceNavigatorSensorAdapter &getSpaceNavigatorSensors() = 0;
};

} // namespace AbstractSensors

#endif // DIALER_IALLSENSORS_H
