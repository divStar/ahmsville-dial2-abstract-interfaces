//
// Created by Igor Voronin on 07.12.23.
//

#include <unity.h>
#include "sensoric_tasks/IMacroKeysTask.h"

class DummyMacroKeysSensor : AbstractSensors::IMacroKeys {
public:
  DummyMacroKeysSensor() = default;
  ~DummyMacroKeysSensor() override = default;

private:
  void initialize() override {
  }
};

class DummyMacroKeysTask : AbstractTasks::IMacroKeysTask<DummyMacroKeysSensor> {
public:
  DummyMacroKeysTask(DummyMacroKeysSensor &sensor) : AbstractTasks::IMacroKeysTask<DummyMacroKeysSensor>(sensor) {
  }
  DummyMacroKeysSensor &getSensor() {
    return ISensoricTask::getSensor();
  }
  const char *getName() {
    return ISensoricTask::getName();
  }
};

DummyMacroKeysSensor *dummyMacroKeysSensor = nullptr;
DummyMacroKeysTask *dummyMacroKeysTask = nullptr;

void setUp() {
}

void tearDown() {
  delete dummyMacroKeysTask;
  delete dummyMacroKeysSensor;
}

void test_can_construct() {
  dummyMacroKeysSensor = new DummyMacroKeysSensor();
  TEST_ASSERT_NOT_NULL(dummyMacroKeysSensor);

  dummyMacroKeysTask = new DummyMacroKeysTask(*dummyMacroKeysSensor);
  TEST_ASSERT_NOT_NULL(dummyMacroKeysTask);

  TEST_ASSERT_EQUAL(&dummyMacroKeysTask->getSensor(), dummyMacroKeysSensor);
  TEST_ASSERT_EQUAL(dummyMacroKeysTask->getName(), AbstractTasks::ISensoricTask<DummyMacroKeysSensor>::DEFAULT_NAME);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_can_construct);
  UNITY_END();
}