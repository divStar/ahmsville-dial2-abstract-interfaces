#include "dataholders/MotionData.h"

namespace DataHolders {

int16_t &MotionData::operator()(MotionDataType type, MotionDataSpatialAxis axis) {
  return sensorData[static_cast<uint8_t>(type)][static_cast<uint8_t>(axis)];
}

const int16_t &MotionData::operator()(MotionDataType type, MotionDataSpatialAxis axis) const {
  return sensorData[static_cast<uint8_t>(type)][static_cast<uint8_t>(axis)];
}

} // namespace DataHolders
