//
// Created by Igor Voronin on 07.12.23.
//

// clang-format off
#include <list>
#include <assert.h>
#include <unity.h>
#include "general_tasks/IInputProcessingTask.h"
#include "general_tasks/IReadInputTask.h"
#include "general_tasks/ILoopingTask.h"
// clang-format on

static const uint8_t NO_MESSAGES_COUNT = 0;
static const uint8_t ONE_MESSAGE_COUNT = 1;
static const char *PROCESSING_TASK_NAME = "DT";
static const char *SINGLE_MESSAGE = "\1DT\x0D\xE8\x00\0"; // \1DT013255000\0; dummy values are: 13, 232, 0

class DummyReadInputTask : public AbstractTasks::IReadInputTask {
public:
  explicit DummyReadInputTask() : AbstractTasks::IReadInputTask() {
  }
  void onLoop() override {
  }
  unsigned long getMessagesCount() {
    return this->messages.size();
  }
  unsigned long getMessagesCount(const char *taskName) {
    assert(this->messages[taskName] && "[DummyReadInputTask#getMessagesCount] List does not exist!");
    return this->messages[taskName]->size();
  }
  void addMessage(const char *taskName, const char *message) {
    AbstractTasks::IReadInputTask::addMessage(taskName, message);
  }
};

class DummyProcessingTask : public AbstractTasks::IInputProcessingTask, public AbstractTasks::ILoopingTask {
public:
  uint8_t dummyValue1;
  uint8_t dummyValue2;
  uint8_t dummyValue3;

  explicit DummyProcessingTask(const char *taskName) : AbstractTasks::IInputProcessingTask(taskName) {
  }
  void parseMessage(const char *message) override {
    if (message[0] != '\1')
      return; // Check start marker
    size_t taskNameLength = std::strlen(getTaskName());

    // Calculate the position of the first value
    size_t firstValuePos = 1 + taskNameLength; // +1 for start marker

    // Check end marker
    if (message[firstValuePos + 3] != '\0') {
      return;
    }

    if (strncmp(message + 1, getTaskName(), taskNameLength) == 0) {
      // Adjusted to handle variable length task names
      dummyValue1 = static_cast<uint8_t>(message[firstValuePos]);
      dummyValue2 = static_cast<uint8_t>(message[firstValuePos + 1]);
      dummyValue3 = static_cast<uint8_t>(message[firstValuePos + 2]);
    }
  }
  void onLoop() override {
    while (!this->messages->empty()) {
      const char *message = this->messages->front();
      this->parseMessage(message);
      this->messages->pop_front();
    }
  }
  unsigned long getMessagesCount() {
    assert(this->messages && "[DummyInputProcessingTask#getMessagesCount] List does not exist!");
    return this->messages->size();
  }
  const char *getFirstMessage() {
    assert(this->messages && "[getFirstMessage] List does not exist!");
    return this->messages->front();
  }
};

DummyProcessingTask *dummyProcessingTask = nullptr;
DummyReadInputTask *dummyReadInputTask = nullptr;

void setUp() {
  dummyProcessingTask = new DummyProcessingTask(PROCESSING_TASK_NAME);
  dummyReadInputTask = new DummyReadInputTask();
}

void tearDown() {
  delete dummyReadInputTask;
  delete dummyProcessingTask;
}

void test_can_construct() {
  TEST_ASSERT_EQUAL(PROCESSING_TASK_NAME, dummyProcessingTask->getTaskName());
  dummyReadInputTask->registerProcessingTask(*dummyProcessingTask);
}

void test_register_processing_task_and_process_dummy_message() {
  TEST_ASSERT_EQUAL(PROCESSING_TASK_NAME, dummyProcessingTask->getTaskName());
  dummyReadInputTask->registerProcessingTask(*dummyProcessingTask);

  // add message to the ReadInputTask; usually a derived ReadInputTask would add the messages when such are read
  dummyReadInputTask->addMessage(PROCESSING_TASK_NAME, SINGLE_MESSAGE);
  TEST_ASSERT_EQUAL(ONE_MESSAGE_COUNT, dummyReadInputTask->getMessagesCount(PROCESSING_TASK_NAME));
  TEST_ASSERT_EQUAL(ONE_MESSAGE_COUNT, dummyProcessingTask->getMessagesCount());

  // retrieve the message and assert the returned pointer is not a nullptr
  auto processingMessage_ptr = dummyProcessingTask->getFirstMessage();
  TEST_ASSERT_NOT_NULL(&processingMessage_ptr);

  // assert it's the same object instance
  TEST_ASSERT_EQUAL(SINGLE_MESSAGE, processingMessage_ptr);

  // assert dummy values are unset / have a default value
  TEST_ASSERT_EQUAL(0, dummyProcessingTask->dummyValue1);
  TEST_ASSERT_EQUAL(0, dummyProcessingTask->dummyValue2);
  TEST_ASSERT_EQUAL(0, dummyProcessingTask->dummyValue3);

  // process loop (usually done by the TaskScheduler on the device); in this case the message is parsed and removed
  dummyProcessingTask->onLoop();

  // assert dummy values are set as expected
  TEST_ASSERT_EQUAL(13, dummyProcessingTask->dummyValue1);
  TEST_ASSERT_EQUAL(232, dummyProcessingTask->dummyValue2);
  TEST_ASSERT_EQUAL(0, dummyProcessingTask->dummyValue3);

  // assert message count is 0
  TEST_ASSERT_EQUAL(0, dummyReadInputTask->getMessagesCount(PROCESSING_TASK_NAME));
  TEST_ASSERT_EQUAL(0, dummyProcessingTask->getMessagesCount());
}

void test_fail_to_register_processing_task_no_taskname() {
  DummyProcessingTask *nullPtrProcessingTask = new DummyProcessingTask(nullptr);

  // try registering a task with no taskname
  dummyReadInputTask->registerProcessingTask(*nullPtrProcessingTask);

  // registration should've failed and there should be no entries in the unordered_map
  TEST_ASSERT_EQUAL(0, dummyReadInputTask->getMessagesCount());
}

void test_fail_to_register_processing_task_no_message_taskname() {
  TEST_ASSERT_EQUAL(PROCESSING_TASK_NAME, dummyProcessingTask->getTaskName());
  dummyReadInputTask->registerProcessingTask(*dummyProcessingTask);

  // try calling addMessage with a nullptr as message
  dummyReadInputTask->addMessage(nullptr, SINGLE_MESSAGE);

  // adding the message should've failed and there should be no messages in the task-related list of messages
  TEST_ASSERT_EQUAL(0, dummyReadInputTask->getMessagesCount(PROCESSING_TASK_NAME));
  TEST_ASSERT_EQUAL(0, dummyProcessingTask->getMessagesCount());
}

void test_fail_to_register_processing_task_no_message() {
  TEST_ASSERT_EQUAL(PROCESSING_TASK_NAME, dummyProcessingTask->getTaskName());
  dummyReadInputTask->registerProcessingTask(*dummyProcessingTask);

  // try calling addMessage with a nullptr as message
  dummyReadInputTask->addMessage(PROCESSING_TASK_NAME, nullptr);

  // adding the message should've failed and there should be no messages in the task-related list of messages
  TEST_ASSERT_EQUAL(0, dummyReadInputTask->getMessagesCount(PROCESSING_TASK_NAME));
  TEST_ASSERT_EQUAL(0, dummyProcessingTask->getMessagesCount());
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_can_construct);
  RUN_TEST(test_register_processing_task_and_process_dummy_message);
  RUN_TEST(test_fail_to_register_processing_task_no_taskname);
  RUN_TEST(test_fail_to_register_processing_task_no_message_taskname);
  RUN_TEST(test_fail_to_register_processing_task_no_message);
  UNITY_END();
}