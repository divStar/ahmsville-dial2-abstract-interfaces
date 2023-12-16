//
// Created by Igor Voronin on 07.12.23.
//

#include <unity.h>
#include "sensoric_tasks/ICapacitiveTask.h"

class DummyCapacitiveSensor : AbstractSensors::ICapacitive {
public:
  DummyCapacitiveSensor() = default;
  ~DummyCapacitiveSensor() override = default;

private:
  void initialize() override {
  }
  void set_CS_AutocaL_Millis(unsigned long millis) override {
  }
  long getData(uint8_t samples) override {
    return 0;
  }
};

class DummyCapacitiveTask : AbstractTasks::ICapacitiveTask<DummyCapacitiveSensor> {
public:
  DummyCapacitiveTask(DummyCapacitiveSensor &sensor) : AbstractTasks::ICapacitiveTask<DummyCapacitiveSensor>(sensor) {
  }
  DummyCapacitiveSensor &getSensor() {
    return ISensoricTask::getSensor();
  }
  const char *getName() {
    return ISensoricTask::getName();
  }
};

DummyCapacitiveSensor *dummyCapacitiveSensor = nullptr;
DummyCapacitiveTask *dummyCapacitiveTask = nullptr;

void setUp() {
}

void tearDown() {
  delete dummyCapacitiveTask;
  delete dummyCapacitiveSensor;
}

void test_can_construct() {
  dummyCapacitiveSensor = new DummyCapacitiveSensor();
  TEST_ASSERT_NOT_NULL(dummyCapacitiveSensor);

  dummyCapacitiveTask = new DummyCapacitiveTask(*dummyCapacitiveSensor);
  TEST_ASSERT_NOT_NULL(dummyCapacitiveTask);

  TEST_ASSERT_EQUAL(&dummyCapacitiveTask->getSensor(), dummyCapacitiveSensor);
  TEST_ASSERT_EQUAL(dummyCapacitiveTask->getName(), AbstractTasks::ISensoricTask<DummyCapacitiveSensor>::DEFAULT_NAME);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_can_construct);
  UNITY_END();
}