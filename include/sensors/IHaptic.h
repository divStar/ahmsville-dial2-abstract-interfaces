#ifndef DIAL2_ABSTRACT_IHAPTIC_H
#define DIAL2_ABSTRACT_IHAPTIC_H

#include "Initializable.h"
#include <cstdint>

namespace AbstractSensors {

/**
 * @class   IHaptic
 * @brief   Interface to decouple the actual haptic sensor from the task processing it.
 *
 * This interface decouples the haptic sensor from the task, that uses it, and allows for proper testing.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class IHaptic : public Initializable {
public:
  /**
   * @brief Destructor.
   */
  ~IHaptic() override = default;

  /**
   * @brief Writes the given strength value to the haptic sensor.
   *
   * @param strength    (uint8_t) strength value for the haptic sensor; 0 to 255 seem like sensible values
   */
  virtual void setStrength(uint8_t strength) = 0;

  /**
   * @brief Resets the strength value of the haptic sensor to 0.
   */
  virtual void resetStrength() = 0;
};

} // namespace AbstractSensors

#endif // DIAL2_ABSTRACT_IHAPTIC_H
