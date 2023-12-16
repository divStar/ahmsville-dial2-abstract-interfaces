//
// Created by Igor Voronin on 14.12.23.
//

#include "IAbsoluteVariant.h" // needed so CLion recognizes the template

namespace DeviceVariants {

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
   * @tparam  MarcoKeysType       IMarcoKeys implementation to use
   */
  typename MarcoKeysType,
  /**
   * @tparam  SpaceNavigatorType  ISpaceNavigator implementation to use
   */
  typename SpaceNavigatorType
>
// clang-format on
DeviceVariants
IAbsoluteVariant<LedType, LedsType, RotaryEncoderType, HapticType, CapacitiveType, MarcoKeysType, SpaceNavigatorType>::getVariant() {
  return DeviceVariants::ABSOLUTE_VARIANT;
}

} // namespace DeviceVariants