#ifndef DIAL2_ABSTRACT_IMACROKEYS_H
#define DIAL2_ABSTRACT_IMACROKEYS_H

#include "Initializable.h"

namespace AbstractSensors {

/**
 * @class   IMacroKeys
 * @brief   Interface to decouple the actual macro key adapter-interfaces from the task processing it.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class IMacroKeys : public Initializable {
public:
  /**
   * @brief Destructor.
   */
  ~IMacroKeys() override = default;
};

} // namespace AbstractSensors

#endif // DIAL2_ABSTRACT_IMACROKEYS_H
