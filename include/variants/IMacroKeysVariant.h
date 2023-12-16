#ifndef DIAL2_ABSTRACT_IMACROKEYSVARIANT_H
#define DIAL2_ABSTRACT_IMACROKEYSVARIANT_H

#include "sensors/IMacroKeys.h"
#include "sensors/ISpaceNavigator.h"
#include "variants/IBaseVariant.h"

namespace DeviceVariants {

/**
 * @class   IMacroKeysVariant
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
  typename MarcoKeysType
>
// clang-format on
class IMacroKeysVariant : virtual public IBaseVariant<LedType, LedsType, RotaryEncoderType, HapticType, CapacitiveType> {
  static_assert(std::is_base_of<AbstractSensors::IMacroKeys, MarcoKeysType>::value,
                "MarcoKeysType must be derived from AbstractSensors::IMacroKeys");

public:
  /**
   * @brief Default destructor
   */
  ~IMacroKeysVariant() override = default;

  DeviceVariants getVariant() override;

  /**
   * @return (IMacroKeys) returns the macro keys sensor
   */
  virtual MarcoKeysType &getMacroKeys() = 0;
};

} // namespace DeviceVariants

#endif // DIAL2_ABSTRACT_IMACROKEYSVARIANT_H
