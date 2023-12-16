#include "dataholders/ColorData.h"

namespace DataHolders {

uint8_t ColorData::getRed() {
  return colorData[0];
}

uint8_t ColorData::getGreen() {
  return colorData[1];
}

uint8_t ColorData::getBlue() {
  return colorData[2];
}

uint8_t ColorData::getBrightness() {
  return colorData[3];
}

const uint8_t (&ColorData::getColor() const)[4] {
  return colorData;
}

void ColorData::setColor(std::initializer_list<uint8_t> values) {
  auto it = values.begin();
  for (size_t i = 0; i < 4 && it != values.end(); ++i, ++it) {
    colorData[i] = *it;
  }
}

} // namespace DataHolders
