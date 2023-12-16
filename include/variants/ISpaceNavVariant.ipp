//
// Created by Igor Voronin on 14.12.23.
//

#include "ISpaceNavVariant.h" // needed so CLion recognizes the template

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
   * @tparam  SpaceNavigatorType  ISpaceNavigator implementation to use
   */
  typename SpaceNavigatorType
>
// clang-format on
DeviceVariants ISpaceNavVariant<LedType, LedsType, RotaryEncoderType, HapticType, CapacitiveType, SpaceNavigatorType>::getVariant() {
  return DeviceVariants::SPACE_NAV_VARIANT;
}

} // namespace DeviceVariants