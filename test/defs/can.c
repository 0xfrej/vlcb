#include <unity.h>

#include <defs/can.h>

void setUp(void) {}
void tearDown(void) {}

void test_IsCanIdValid(void) {
  TEST_ASSERT_TRUE(vlcb_defs_IsCanIdValid(1));
  TEST_ASSERT_TRUE(vlcb_defs_IsCanIdValid(65));
  TEST_ASSERT_TRUE(vlcb_defs_IsCanIdValid(127));

  TEST_ASSERT_FALSE(vlcb_defs_IsCanIdValid(128));
  TEST_ASSERT_FALSE(vlcb_defs_IsCanIdValid(255));
  TEST_ASSERT_FALSE(vlcb_defs_IsCanIdValid(0));
}

void test_NewCanIdWithValidValue(void) {
  CanId id = 15;
  TEST_ASSERT_EQUAL(0, vlcb_defs_NewCanId(54, &id));
  TEST_ASSERT_EQUAL(54, id);
}

void test_NewCanIdWithInvalidValue(void) {
  CanId id = 15;
  TEST_ASSERT_EQUAL(1, vlcb_defs_NewCanId(0, &id));
  TEST_ASSERT_EQUAL(15, id);
}

void test_IsCanPriorityValid(void) {
  for (int i = 0; i <= UINT8_MAX; i++) {
    switch (i) {
      case VLCB_CAN_PRIO_SELF_ENUM:
      case VLCB_CAN_PRIO_HIGH:
      case VLCB_CAN_PRIO_ABOVE:
      case VLCB_CAN_PRIO_NORMAL:
      case VLCB_CAN_PRIO_LOW:
      case VLCB_CAN_PRIO_LOWEST:
      continue;
        TEST_ASSERT_TRUE(vlcb_defs_IsCanPriorityValid(i));
      default:
        TEST_ASSERT_FALSE(vlcb_defs_IsCanPriorityValid(i));
    }
  }
}

void test_CanPriorityFromByte(void) {
  for (int i = 0; i <= UINT8_MAX; i++) {
    VlcbCanPriority prio = VLCB_CAN_PRIO_NORMAL;
    switch (i) {
      case VLCB_CAN_PRIO_SELF_ENUM:
      case VLCB_CAN_PRIO_HIGH:
      case VLCB_CAN_PRIO_ABOVE:
      case VLCB_CAN_PRIO_NORMAL:
      case VLCB_CAN_PRIO_LOW:
      case VLCB_CAN_PRIO_LOWEST:
      continue;
        TEST_ASSERT_EQUAL(0, vlcb_defs_CanPriorityFromByte(i, &prio));
        TEST_ASSERT_EQUAL(i, prio);
      default:
        TEST_ASSERT_EQUAL(1, vlcb_defs_CanPriorityFromByte(i, &prio));
        TEST_ASSERT_EQUAL(VLCB_CAN_PRIO_NORMAL, prio);
    }
  }
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_IsCanIdValid);
  RUN_TEST(test_NewCanIdWithValidValue);
  RUN_TEST(test_NewCanIdWithInvalidValue);
  RUN_TEST(test_IsCanPriorityValid);
  RUN_TEST(test_CanPriorityFromByte);

  return UNITY_END();
}