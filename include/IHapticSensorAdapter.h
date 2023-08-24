#ifndef DIALER_IHAPTICSENSORADAPTER_H
#define DIALER_IHAPTICSENSORADAPTER_H

#ifdef ARDUINO
#include <stdint.h>
#else
#include <cstdint>
#endif

namespace AbstractSensors {

/**
 * @class   IHapticSensorAdapter
 * @brief   Interface to decouple the actual haptic sensor from the task
 * processing it.
 *
 * This interface decouples the haptic sensor from the task, that uses it, and
 * allows for proper testing.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class IHapticSensorAdapter {
public:
  /**
   * @brief Destructor.
   */
  virtual ~IHapticSensorAdapter() = default;

  /**
   * @brief Writes the given strength value to the haptic sensor.
   *
   * @param strength    (uint8_t) strength value for the haptic sensor; 0 to 255 seem
   * like sensible values
   */
  virtual void writeStrength(uint8_t strength) = 0;
};

} // namespace AbstractSensors

#endif // DIALER_IHAPTICSENSORADAPTER_H
