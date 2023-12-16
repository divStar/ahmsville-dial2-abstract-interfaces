#ifndef DIAL2_ABSTRACT_MOTIONDATASPATIALAXIS_H
#define DIAL2_ABSTRACT_MOTIONDATASPATIALAXIS_H

#include <cstdint>

namespace DataHolders {

/**
 * @enum    MotionDataSpatialAxis
 * @brief   This enumeration describes all the possible motion data spatial axis, that can be retrieved from the MPU6050.
 *
 * @author  Igor Voronin
 * @date    19.11.2023
 */
enum class MotionDataSpatialAxis { X, Y, Z };

/**
 * @brief Count of MotionDataSpatialAxis enum values.
 */
constexpr static uint8_t MOTION_DATA_SPATIAL_AXIS_COUNT = 3;

} // namespace DataHolders

#endif // DIAL2_ABSTRACT_MOTIONDATASPATIALAXIS_H
