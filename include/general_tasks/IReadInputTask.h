#ifndef DIAL2_ABSTRACT_READINPUTTASK_H
#define DIAL2_ABSTRACT_READINPUTTASK_H

#include "IInputProcessingTask.h"
#include "ILoopingTask.h"
#include <list>
#include <memory>
#include <unordered_map>

namespace AbstractTasks {

/**
 * @class   IReadInputTask
 * @brief   Interface, that defines, that a task should implement an <code>onLoop()</code> member function.
 *
 * The <code>onLoop()</code> is called whenever a scheduler (on the Arduino Zero chip)
 * executes a particular task during the <code>loop()</code> function.
 *
 * @author  Igor Voronin
 * @date    14.12.2023
 */
class IReadInputTask : public ILoopingTask {
public:
  ~IReadInputTask() override = default;

  void registerProcessingTask(AbstractTasks::IInputProcessingTask &task);

  void unregisterProcessingTask(AbstractTasks::IInputProcessingTask &task);

protected:
  void addMessage(const char *taskName, const char *message);

  std::unordered_map<const char *, std::shared_ptr<std::list<const char *>>> messages;
};

} // namespace AbstractTasks

#endif // DIAL2_ABSTRACT_READINPUTTASK_H