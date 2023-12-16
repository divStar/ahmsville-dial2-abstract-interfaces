#ifndef DIAL2_ABSTRACT_ISPACENAVIGATOR_H
#define DIAL2_ABSTRACT_ISPACENAVIGATOR_H

#include "Initializable.h"
#include "dataholders/MotionData.h"
#include <cstdint>

namespace AbstractSensors {

/**
 * @class   ISpaceNavigator
 * @brief   Interface to decouple the actual MPU6050 sensor(s) from the task processing it.
 *
 * This interface decouples the MPU6050 sensor(s) from the task, that uses it, and allows for proper testing.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class ISpaceNavigator : public Initializable {
public:
  /**
   * @brief Destructor.
   */
  ~ISpaceNavigator() override = default;

  /**
   * @brief Calibrates the MPU6050 sensor (or a mock thereof).
   */
  virtual void calibrateSensors() = 0;

  /**
   * @brief Tests the connection to the MPU6050 sensor (or a mock thereof).
   */
  virtual bool testConnection() = 0;

  /**
   * @brief Retrieves whether the DMP initialization has finished successfully (<code>dmpInitDone = 0</code>).
   *
   * @return (bool) <code>true</code> if the DMP initialization finished successfully, <code>false</code> otherwise
   */
  virtual bool isDmpInitDone() = 0;

  /**
   * @brief Retrieves the accelerometer and gyroscope x, y and z values as a MotionData object.
   *
   * @return (MotionData) motion data object containing all the relevant motion data points
   */
  virtual DataHolders::MotionData getMotionData() = 0;
};

} // namespace AbstractSensors

#endif // DIAL2_ABSTRACT_ISPACENAVIGATOR_H
