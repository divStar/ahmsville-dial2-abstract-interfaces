#ifndef DIAL2_ABSTRACT_IMACROKEY_H
#define DIAL2_ABSTRACT_IMACROKEY_H

#include "Initializable.h"
#include "dataholders/MacroKeyCallbackType.h"

namespace AbstractSensors {

/**
 * @class   IMacroKey
 * @brief   Interface to decouple the actual single macro key from the task processing it.
 *
 * @author  Igor Voronin
 * @date    20.11.2023
 */
class IMacroKey : public Initializable {
  /**
   * @brief Returns the set pin.
   *
   * @return (int) number of the pin
   */
  [[nodiscard]] virtual int getPin() const = 0;

  /**
   * @brief Function, which is called upon state change via interrupt.
   */
  virtual void onChange() = 0;
};

} // namespace AbstractSensors

#endif //DIAL2_ABSTRACT_IMACROKEY_H
