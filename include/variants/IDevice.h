#ifndef DIAL2_ABSTRACT_IDEVICE_H
#define DIAL2_ABSTRACT_IDEVICE_H

#include "DeviceVariants.h"
#include "Initializable.h"
#include <cstdint>

namespace DeviceVariants {

/**
 * @class   IDevice
 * @brief   Interface, that defines a device.
 *
 * This class is a marker interface, that also contains useful general device member functions.
 *
 * @author  Igor Voronin
 * @date    02.12.2023
 */
class IDevice : public Initializable {
public:
  /**
   * @brief Destructor.
   */
  ~IDevice() override = default;

  /**
   * @brief Returns device version.
   *
   * @return (DeviceVariants) device variant / version
   */
  virtual DeviceVariants getVariant() = 0;
};

} // namespace DeviceVariants

#endif // DIAL2_ABSTRACT_IDEVICE_H
