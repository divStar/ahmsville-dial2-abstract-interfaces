//
// Created by Igor Voronin on 07.12.23.
//

#include <unity.h>
#include "sensoric_tasks/IHapticTask.h"

class DummyHapticSensor : AbstractSensors::IHaptic {
public:
  DummyHapticSensor() = default;
  ~DummyHapticSensor() override = default;

private:
  void initialize() override {
  }
  void setStrength(uint8_t strength) override {
  }
  void resetStrength() override {
  }
};

class DummyHapticTask : AbstractTasks::IHapticTask<DummyHapticSensor> {
public:
  DummyHapticTask(DummyHapticSensor &sensor) : AbstractTasks::IHapticTask<DummyHapticSensor>(sensor) {
  }
  DummyHapticSensor &getSensor() {
    return ISensoricTask::getSensor();
  }
  const char *getName() {
    return ISensoricTask::getName();
  }
};

DummyHapticSensor *dummyHapticSensor = nullptr;
DummyHapticTask *dummyHapticTask = nullptr;

void setUp() {
}

void tearDown() {
  delete dummyHapticTask;
  delete dummyHapticSensor;
}

void test_can_construct() {
  dummyHapticSensor = new DummyHapticSensor();
  TEST_ASSERT_NOT_NULL(dummyHapticSensor);

  dummyHapticTask = new DummyHapticTask(*dummyHapticSensor);
  TEST_ASSERT_NOT_NULL(dummyHapticTask);

  TEST_ASSERT_EQUAL(&dummyHapticTask->getSensor(), dummyHapticSensor);
  TEST_ASSERT_EQUAL(dummyHapticTask->getName(), AbstractTasks::ISensoricTask<DummyHapticSensor>::DEFAULT_NAME);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_can_construct);
  UNITY_END();
}