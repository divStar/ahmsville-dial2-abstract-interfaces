//
// Created by Igor Voronin on 07.12.23.
//

#include <unity.h>
#include "sensoric_tasks/IKnobTask.h"

class DummyRotaryEncoder : AbstractSensors::IRotaryEncoder {
public:
  DummyRotaryEncoder() = default;
  ~DummyRotaryEncoder() override = default;

private:
  void initialize() override {
  }
  [[nodiscard]] float getRotationAngleDelta() const override {
    return 0;
  }
  void updateSensorData() override {
  }
};

class DummyKnobTask : AbstractTasks::IKnobTask<DummyRotaryEncoder> {
public:
  DummyKnobTask(DummyRotaryEncoder &sensor, const char *name) : AbstractTasks::IKnobTask<DummyRotaryEncoder>(sensor, name) {
  }
  DummyRotaryEncoder &getSensor() {
    return ISensoricTask::getSensor();
  }
  const char *getName() {
    return ISensoricTask::getName();
  }
};

DummyRotaryEncoder *dummyRotaryEncoder = nullptr;
DummyKnobTask *dummyKnobTask = nullptr;

void setUp() {
}

void tearDown() {
  delete dummyKnobTask;
  delete dummyRotaryEncoder;
}

void test_can_construct() {
  dummyRotaryEncoder = new DummyRotaryEncoder();
  TEST_ASSERT_NOT_NULL(dummyRotaryEncoder);

  auto sensorName = "dummy";
  dummyKnobTask = new DummyKnobTask(*dummyRotaryEncoder, sensorName);
  TEST_ASSERT_NOT_NULL(dummyKnobTask);

  TEST_ASSERT_EQUAL(&dummyKnobTask->getSensor(), dummyRotaryEncoder);
  TEST_ASSERT_EQUAL(dummyKnobTask->getName(), sensorName);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_can_construct);
  UNITY_END();
}