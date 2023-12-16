#ifndef DIAL2_ABSTRACT_MOTIONDATA_H
#define DIAL2_ABSTRACT_MOTIONDATA_H

#include "MotionDataSpatialAxis.h"
#include "MotionDataType.h"
#include <cstdint>

namespace DataHolders {

/**
 * @class   MotionData
 * @brief   Data type allowing for motion data modifications.
 *
 * You can use e.g. <code>&md(MotionDataType::ACCELEROMETER, MotionDataSpatialAxis:X) = 1</code> to set a value
 * and similarly <code>&md(MotionDataType::ACCELEROMETER, MotionDataSpatialAxis:X)</code> to retrieve it.
 *
 * @author  Igor Voronin
 * @date    20.11.2023
 */
class MotionData {
public:
  /**
   * @brief Provides modifiable access to sensor data based on type and spatial axis.
   *
   * This operator allows for direct access and modification of the sensor data stored
   * in the `MotionData` class. It uses the specified motion data type and spatial axis
   * to access the corresponding value in the `sensorData` array.
   *
   * @param type The type of motion data (e.g., accelerometer, gyroscope).
   * @param axis The spatial axis for the data (e.g., X, Y, Z).
   * @return int16_t& A reference to the `int16_t` value representing the sensor data
   *         for the given type and axis.
   */
  int16_t &operator()(MotionDataType type, MotionDataSpatialAxis axis);

  /**
   * @brief Provides read-only access to sensor data based on type and spatial axis.
   *
   * This operator allows for accessing the sensor data stored in the `MotionData` class
   * without modifying it. It is the const version of the operator and is used with const
   * instances of `MotionData`. It uses the specified motion data type and spatial axis
   * to access the corresponding value in the `sensorData` array.
   *
   * @param type The type of motion data (e.g., accelerometer, gyroscope).
   * @param axis The spatial axis for the data (e.g., X, Y, Z).
   * @return const int16_t& A const reference to the `int16_t` value representing the
   *         sensor data for the given type and axis.
   */
  const int16_t &operator()(MotionDataType type, MotionDataSpatialAxis axis) const;

private:
  /**
   * @brief Array holding the motion data.
   *
   * The first dimension is the MotionDataType, the second dimension is the spatial axis.
   */
  int16_t sensorData[MOTION_DATA_TYPE_COUNT][MOTION_DATA_SPATIAL_AXIS_COUNT];
};

} // namespace DataHolders

#endif // DIAL2_ABSTRACT_MOTIONDATA_H
