#include "general_tasks/IInputProcessingTask.h"

namespace AbstractTasks {

IInputProcessingTask::IInputProcessingTask(const char *taskName) : taskName(taskName) {
}

const char *IInputProcessingTask::getTaskName() {
  return this->taskName;
}

void IInputProcessingTask::setMessages(std::shared_ptr<std::list<const char *>> taskMessages) {
  this->messages = taskMessages;
}

void IInputProcessingTask::unsetMessages() {
  this->messages = nullptr;
}

} // namespace AbstractTasks