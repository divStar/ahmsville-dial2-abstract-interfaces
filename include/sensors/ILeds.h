#ifndef DIAL2_ABSTRACT_ILEDS_H
#define DIAL2_ABSTRACT_ILEDS_H

#include "ILed.h"
#include "Initializable.h"
#include <initializer_list>
#include <type_traits>

namespace AbstractSensors {

/**
 * @class   ILeds
 * @brief   Interface to decouple the actual led adapter-interfaces from the task processing it.
 *
 * @tparam  LedType type, that extends ILed and represents a single Led
 *
 * @author  Igor Voronin
 * @date    20.11.2023
 */
template <typename LedType> class ILeds : public Initializable {
  static_assert(std::is_base_of<ILed, LedType>::value, "LedType must be derived from AbstractSensors::ILed");

public:
  /**
   * @brief Destructor.
   */
  ~ILeds() override = default;

  /**
   * @brief Returns the ILed with the given index.
   *
   * @param index index of the ILed you want to retrieve
   * @return ILed with the given index
   */
  virtual LedType *getLed(uint8_t index) = 0;

  /**
   * @brief Adds an ILed according to its index.
   *
   * @param led led object, that implements ILed
   */
  virtual void addLed(LedType led) = 0;
};

} // namespace AbstractSensors

#endif //DIAL2_ABSTRACT_ILEDS_H
