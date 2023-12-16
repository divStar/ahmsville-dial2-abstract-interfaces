#ifndef DIAL2_ABSTRACT_IABSOLUTEVARIANT_H
#define DIAL2_ABSTRACT_IABSOLUTEVARIANT_H

#include "IMacroKeysVariant.h"
#include "ISpaceNavVariant.h"

namespace DeviceVariants {

/**
 * @class   IAbsoluteVariant
 * @brief   Interface for the absolute variant of the device.
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
   * @tparam  MarcoKeysType       IMarcoKeys implementation to use
   */
  typename MarcoKeysType,
  /**
   * @tparam  SpaceNavigatorType  ISpaceNavigator implementation to use
   */
  typename SpaceNavigatorType
>
// clang-format on
class IAbsoluteVariant
    : virtual public ISpaceNavVariant<LedType, LedsType, RotaryEncoderType, HapticType, CapacitiveType, SpaceNavigatorType>,
      virtual public IMacroKeysVariant<LedType, LedsType, RotaryEncoderType, HapticType, CapacitiveType, MarcoKeysType> {
public:
  /**
   * @brief Default destructor
   */
  ~IAbsoluteVariant() override = default;

  DeviceVariants getVariant() override;
};

} // namespace DeviceVariants

#include "IAbsoluteVariant.ipp"

#endif // DIAL2_ABSTRACT_IABSOLUTEVARIANT_H
