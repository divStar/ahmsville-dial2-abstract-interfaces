#ifndef DIAL2_ABSTRACT_MOTIONDATATYPE_H
#define DIAL2_ABSTRACT_MOTIONDATATYPE_H

#include <cstdint>

namespace DataHolders {

/**
 * @enum    MotionDataType
 * @brief   This enumeration describes all the possible motion data types, that can be retrieved from the MPU6050.
 *
 * @author  Igor Voronin
 * @date    19.11.2023
 */
enum class MotionDataType { GYROSCOPE, ACCELEROMETER };

/**
 * @brief Count of MotionDataType enum values.
 */
constexpr static uint8_t MOTION_DATA_TYPE_COUNT = 2;

} // namespace DataHolders

#endif // DIAL2_ABSTRACT_MOTIONDATATYPE_H
