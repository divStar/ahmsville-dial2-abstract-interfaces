#ifndef DIAL2_ABSTRACT_DEVICEVARIANTS_H
#define DIAL2_ABSTRACT_DEVICEVARIANTS_H

namespace DeviceVariants {

/**
 * @enum    DeviceVariants
 * @brief   This enumeration describes all the possible device versions.
 *
 * Device versions primarily describe the sensors used in said device version and prevent unused sensors from being initialized.
 *
 * @author  Igor Voronin
 * @date    18.11.2023
 */
enum class DeviceVariants {
  /**
   * @brief Base variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>one knob</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * </p>
   */
  BASE_VARIANT,
  /**
   * @brief MacroKeys variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>one knob</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * <li>macro keys</li>
   * </p>
   */
  MACRO_KEYS_VARIANT,
  /**
   * @brief SpaceNavigator variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>two knobs</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * <li>5-axis space navigator joystick</li>
   * </p>
   */
  SPACE_NAV_VARIANT,
  /**
   * @brief Absolute variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>two knobs</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * <li>macro keys</li>
   * <li>5-axis space navigator joystick</li>
   * </p>
   */
  ABSOLUTE_VARIANT
};

} // namespace DeviceVariants
#endif // DIAL2_ABSTRACT_DEVICEVARIANTS_H
