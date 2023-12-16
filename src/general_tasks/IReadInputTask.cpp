#include "general_tasks/IReadInputTask.h"

namespace AbstractTasks {

void IReadInputTask::registerProcessingTask(AbstractTasks::IInputProcessingTask &task) {
  if (task.getTaskName() && this->messages.find(task.getTaskName()) == this->messages.end()) {
    // only add a new key->list if the key does not yet exist in the messages map
    this->messages[task.getTaskName()] = std::make_shared<std::list<const char *>>();
    task.setMessages(this->messages[task.getTaskName()]);
  }
}

void IReadInputTask::unregisterProcessingTask(AbstractTasks::IInputProcessingTask &task) {
  task.unsetMessages();
  this->messages.erase(task.getTaskName());
}

void IReadInputTask::addMessage(const char *taskName, const char *message) {
  if (taskName && this->messages.find(taskName) != this->messages.end() && message) {
    // only add push a new message to the list if taskName key exists in the messages map and a message is provided
    this->messages[taskName]->push_back(message);
  }
}

} // namespace AbstractTasks