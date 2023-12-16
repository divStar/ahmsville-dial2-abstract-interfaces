#ifndef DIAL2_ABSTRACT_INITIALIZABLE_H
#define DIAL2_ABSTRACT_INITIALIZABLE_H

/**
 * @class   Initializable
 * @brief   Interface to mark a class as initializable.
 *
 * This interface forces a class to provide a way to initialize it. This is particularly useful if the initialization is
 * not part of the creation process (within the constructor), which is the case for sensors, tasks and device variants.
 * <p>
 * In particular: you might want to initialize a sensor, task or device within Arduino's <code>setup()</code> function
 * in the <code>main.cpp</code> instead of losing control over initialization by moving that code into a constructor.
 * </p>
 *
 * @author  Igor Voronin
 * @date    18.11.2023
 */
class Initializable {
public:
  /**
   * @brief Destructor.
   */
  virtual ~Initializable() = default;

  /**
   * @brief Initializes the sensor.
   */
  virtual void initialize() = 0;
};

#endif // DIAL2_ABSTRACT_INITIALIZABLE_H
