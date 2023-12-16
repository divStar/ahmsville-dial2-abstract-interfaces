//
// Created by Igor Voronin on 07.12.23.
//

#include <unity.h>
#include "dataholders/MotionData.h"
#include "sensoric_tasks/ISpaceNavigatorTask.h"

class DummySpaceNavigatorSensor : AbstractSensors::ISpaceNavigator {
public:
  DummySpaceNavigatorSensor() = default;
  ~DummySpaceNavigatorSensor() override = default;

private:
  void initialize() override {
  }
  void calibrateSensors() override {
  }
  bool testConnection() override {
    return false;
  }
  bool isDmpInitDone() override {
    return false;
  }
  DataHolders::MotionData getMotionData() override {
    return DataHolders::MotionData();
  }
};

class DummySpaceNavigatorTask : AbstractTasks::ISpaceNavigatorTask<DummySpaceNavigatorSensor> {
public:
  DummySpaceNavigatorTask(DummySpaceNavigatorSensor &sensor) : AbstractTasks::ISpaceNavigatorTask<DummySpaceNavigatorSensor>(sensor) {
  }
  DummySpaceNavigatorSensor &getSensor() {
    return ISensoricTask::getSensor();
  }
  const char *getName() {
    return ISensoricTask::getName();
  }
};

DummySpaceNavigatorSensor *dummySpaceNavigatorSensor = nullptr;
DummySpaceNavigatorTask *dummySpaceNavigatorTask = nullptr;

void setUp() {
}

void tearDown() {
  delete dummySpaceNavigatorTask;
  delete dummySpaceNavigatorSensor;
}

void test_can_construct() {
  dummySpaceNavigatorSensor = new DummySpaceNavigatorSensor();
  TEST_ASSERT_NOT_NULL(dummySpaceNavigatorSensor);

  dummySpaceNavigatorTask = new DummySpaceNavigatorTask(*dummySpaceNavigatorSensor);
  TEST_ASSERT_NOT_NULL(dummySpaceNavigatorTask);

  TEST_ASSERT_EQUAL(&dummySpaceNavigatorTask->getSensor(), dummySpaceNavigatorSensor);
  TEST_ASSERT_EQUAL(dummySpaceNavigatorTask->getName(), AbstractTasks::ISensoricTask<DummySpaceNavigatorSensor>::DEFAULT_NAME);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_can_construct);
  UNITY_END();
}