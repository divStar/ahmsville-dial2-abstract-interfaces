#ifndef DIAL2_ABSTRACT_IBASEVARIANT_H
#define DIAL2_ABSTRACT_IBASEVARIANT_H

#include "IDevice.h"
#include "sensors/ICapacitive.h"
#include "sensors/IHaptic.h"
#include "sensors/ILeds.h"
#include "sensors/IMacroKeys.h"
#include "sensors/IRotaryEncoder.h"
#include "sensors/ISpaceNavigator.h"

/**
 * @namespace   DeviceVariants
 * @brief       This namespace contains all abstractions of the sensors of the AhmsVille Dial 2 device.
 *
 * @author      Igor Voronin
 * @date        20.08.2023
 */
namespace DeviceVariants {

/**
 * @class   IBaseVariant
 * @brief   Interface for the base variant of the device.
 *
 * @author  Igor Voronin
 * @date    13.08.2023
 */
// clang-format off
template <
  /**
   * @tparam  LedType             ILed implementation to use
   */
  typename LedType,
  /**
   * @tparam  LedsType            ILeds implementation to use
   */
  typename LedsType,
  /**
   * @tparam  RotaryEncoderType   IRotaryEncoder implementation to use
   */
  typename RotaryEncoderType,
  /**
   * @tparam  HapticType          IHaptic implementation to use
   */
  typename HapticType,
  /**
   * @tparam  CapacitiveType      ICapacitive implementation to use
   */
  typename CapacitiveType
>
// clang-format on
class IBaseVariant : public IDevice {
  static_assert(std::is_base_of<AbstractSensors::ILed, LedType>::value, "LedType must be derived from AbstractSensors::ILed");
  static_assert(std::is_base_of<AbstractSensors::ILeds<LedType>, LedsType>::value,
                "LedsType<LedType> must be derived from AbstractSensors::ILeds<AbstractSensors::ILed>");
  static_assert(std::is_base_of<AbstractSensors::IRotaryEncoder, RotaryEncoderType>::value,
                "RotaryEncoderType must be derived from AbstractSensors::IRotaryEncoder");
  static_assert(std::is_base_of<AbstractSensors::IHaptic, HapticType>::value,
                "HapticType must be derived from AbstractSensors::IHaptic");
  static_assert(std::is_base_of<AbstractSensors::ICapacitive, CapacitiveType>::value,
                "CapacitiveType must be derived from AbstractSensors::ICapacitive");

public:
  /**
   * @brief Default destructor
   */
  ~IBaseVariant() override = default;

  DeviceVariants getVariant() override;

  /**
   * @return (ILeds) returns the leds sensor
   */
  virtual LedsType &getLeds() = 0;

  /**
   * @return (IRotaryEncoderAdapter) returns the lower knob sensor
   */
  virtual RotaryEncoderType &getLowerKnob() = 0;

  /**
   * @return (IHaptic) returns the haptic sensor
   */
  virtual HapticType &getHaptic() = 0;

  /**
   * @return (ICapacitive) returns the capacitive sensor
   */
  virtual CapacitiveType &getCapacitive() = 0;
};

} // namespace DeviceVariants

#include "IBaseVariant.ipp"

#endif // DIAL2_ABSTRACT_IBASEVARIANT_H
