#ifndef DIAL2_ABSTRACT_ILED_H
#define DIAL2_ABSTRACT_ILED_H

#include "Initializable.h"
#include "dataholders/ColorData.h"
#include <cstdint>

namespace AbstractSensors {

/**
 * @class   ILed
 * @brief   Interface to decouple the actual single led from the task processing it.
 *
 * @author  Igor Voronin
 * @date    20.11.2023
 */
class ILed : public Initializable {
public:
  /**
   * @brief Returns the index of the led.
   *
   * @return (uint8_t) index of the led
   */
  [[nodiscard]] virtual uint8_t getIndex() const = 0;

  /**
   * @return array of four <code>uint8_t</code> values (red, blue, green, brightness)
   */
  [[nodiscard]] virtual const uint8_t (&getColor() const)[4] = 0;

  /**
   * @brief Sets the ColorData of this led.
   *
   * @param colorData (ColorData) color data to set this led to
   */
  virtual void setColor(std::initializer_list<uint8_t> values) = 0;
};

} // namespace AbstractSensors

#endif //DIAL2_ABSTRACT_ILED_H
