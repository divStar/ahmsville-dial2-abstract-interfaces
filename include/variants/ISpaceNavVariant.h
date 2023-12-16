#ifndef DIAL2_ABSTRACT_ISPACENAVVARIANT_H
#define DIAL2_ABSTRACT_ISPACENAVVARIANT_H

#include "IBaseVariant.h"
#include "sensors/ISpaceNavigator.h"

namespace DeviceVariants {

/**
 * @class   ISpaceNavVariant
 * @brief   Interface for the space-nav variant of the device.
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
  typename CapacitiveType,
  /**
   * @tparam  SpaceNavigatorType  ISpaceNavigator implementation to use
   */
  typename SpaceNavigatorType
>
// clang-format on
class ISpaceNavVariant : virtual public IBaseVariant<LedType, LedsType, RotaryEncoderType, HapticType, CapacitiveType> {
  static_assert(std::is_base_of<AbstractSensors::ISpaceNavigator, SpaceNavigatorType>::value,
                "SpaceNavigatorType must be derived from AbstractSensors::ISpaceNavigator");

public:
  /**
   * @brief Default destructor
   */
  ~ISpaceNavVariant() override = default;

  DeviceVariants getVariant() override;

  /**
   * @return (IRotaryEncoderAdapter) returns the upper knob sensor
   */
  virtual RotaryEncoderType &getUpperKnob() = 0;

  /**
   * @return (ISpaceNavigator) returns the space navigator sensor
   */
  virtual SpaceNavigatorType &getSpaceNavigator() = 0;
};

} // namespace DeviceVariants

#include "ISpaceNavVariant.ipp"

#endif // DIAL2_ABSTRACT_ISPACENAVVARIANT_H
