#ifndef DIALER_IMACROKEYS_H
#define DIALER_IMACROKEYS_H

/**
 * @class   IMacroKeys
 * @brief   Interface to decouple the actual macro key adapter-interfaces from the task
 * processing it.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class IMacroKeys {
public:
  virtual ~IMacroKeys() = default;

  /**
   * @brief Initializes the macro keys (or mocks thereof).
   */
  virtual void initializeMacroKeys() = 0;
};

#endif // DIALER_IMACROKEYS_H
