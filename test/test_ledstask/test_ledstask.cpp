//
// Created by Igor Voronin on 07.12.23.
//

#include <unity.h>
#include "sensoric_tasks/ILedsTask.h"

class DummyLedSensor : AbstractSensors::ILed {
public:
  DummyLedSensor() = default;
  ~DummyLedSensor() override = default;

private:
  void initialize() override {
  }
  [[nodiscard]] uint8_t getIndex() const override {
    return 0;
  };
  [[nodiscard]] const uint8_t (&getColor() const)[4] override {
    return {0, 0, 0, 0};
  };
  void setColor(std::initializer_list<uint8_t> values) override{};
};

class DummyLedsSensor : AbstractSensors::ILeds<DummyLedSensor> {
public:
  DummyLedsSensor() = default;
  ~DummyLedsSensor() override = default;

  DummyLedSensor *getLed(uint8_t index) override {
    return nullptr;
  }
  void addLed(DummyLedSensor led) override {
  }

private:
  void initialize() override {
  }
};

class DummyLedsTask : AbstractTasks::ILedsTask<DummyLedSensor, DummyLedsSensor> {
public:
  DummyLedsTask(DummyLedsSensor &sensor) : AbstractTasks::ILedsTask<DummyLedSensor, DummyLedsSensor>(sensor) {
  }
  DummyLedsSensor &getSensor() {
    return ISensoricTask::getSensor();
  }
  const char *getName() {
    return ISensoricTask::getName();
  }
};

DummyLedsSensor *dummyLedsSensor = nullptr;
DummyLedsTask *dummyLedsTask = nullptr;

void setUp() {
}

void tearDown() {
  delete dummyLedsTask;
  delete dummyLedsSensor;
}

void test_can_construct() {
  dummyLedsSensor = new DummyLedsSensor();
  TEST_ASSERT_NOT_NULL(dummyLedsSensor);

  dummyLedsTask = new DummyLedsTask(*dummyLedsSensor);
  TEST_ASSERT_NOT_NULL(dummyLedsTask);

  TEST_ASSERT_EQUAL(&dummyLedsTask->getSensor(), dummyLedsSensor);
  TEST_ASSERT_EQUAL(dummyLedsTask->getName(), AbstractTasks::ISensoricTask<DummyLedsSensor>::DEFAULT_NAME);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_can_construct);
  UNITY_END();
}