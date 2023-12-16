#ifndef DIAL2_ABSTRACT_IROTARYENCODER_H
#define DIAL2_ABSTRACT_IROTARYENCODER_H

#include "Initializable.h"

namespace AbstractSensors {

/**
 * @class   IRotaryEncoder
 * @brief   Interface to decouple the actual rotary encoder adapter-interfaces from the task processing it.
 *
 * This interface decouples the rotary encoder adapter-interfaces from the task, that uses it, and allows for proper testing.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class IRotaryEncoder : public Initializable {
public:
  /**
   * @brief Destructor.
   */
  ~IRotaryEncoder() override = default;

  /**
   * @return (float) Gets the positive or negative rotation angle delta between
   * the current and the previous angle.
   */
  [[nodiscard]] virtual float getRotationAngleDelta() const = 0;

  /**
   * @brief Update sensor data.
   */
  virtual void updateSensorData() = 0;
};

} // namespace AbstractSensors

#endif // DIAL2_ABSTRACT_IROTARYENCODER_H
