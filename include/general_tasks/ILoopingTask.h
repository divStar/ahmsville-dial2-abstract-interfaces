//
// Created by Igor Voronin on 06.12.23.
//

#ifndef DIAL2_ABSTRACT_LOOPINGTASK_H
#define DIAL2_ABSTRACT_LOOPINGTASK_H

namespace AbstractTasks {

/**
 * @class   ILoopingTask
 * @brief   Interface, that defines, that a task should implement an <code>onLoop()</code> member function.
 *
 * The <code>onLoop()</code> is called whenever a scheduler (on the Arduino Zero chip)
 * executes a particular task during the <code>loop()</code> function.
 *
 * @author  Igor Voronin
 * @date    14.12.2023
 */
class ILoopingTask {
public:
  /**
   * @brief Destructor.
   */
  virtual ~ILoopingTask() = default;

  /**
   * @brief Member function, that is run whenever a scheduler executes the particular task.
   *
   * Usually the task in question, that implements ILoopingTask, will be executed during <code>loop()</code> function
   * of the <code>main.cpp</code> source file or indirectly when the task scheduler is executed and it decides to let
   * this task perform some processing.
   */
  [[maybe_unused]] virtual void onLoop() = 0;
};

} // namespace AbstractTasks

#endif // DIAL2_ABSTRACT_LOOPINGTASK_H
