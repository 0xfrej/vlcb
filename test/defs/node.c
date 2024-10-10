#include <unity.h>

#include <defs/node.h>

void setUp(void) {}
void tearDown(void) {}

void test_NewNodeAddrFromBytesUnchecked(void) {
  VlcbNodeAddr addr = vlcb_defs_NewNodeAddrFromBytesUnchecked(0b10011001, 0b01100110);

  TEST_ASSERT_EQUAL(0b1001100101100110, addr);
}

void test_NewNodeAddrUnitialized(void) {
  VlcbNodeAddr addr = 15;
  int ret = vlcb_defs_NewNodeAddr(0, &addr);

  TEST_ASSERT_EQUAL(1, ret);
  TEST_ASSERT_EQUAL(15, addr);
}

void test_NewNodeAddr(void) {
  VlcbNodeAddr addr;
  int ret;

  ret = vlcb_defs_NewNodeAddr(1, &addr);
  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_EQUAL(1, addr);

  ret = vlcb_defs_NewNodeAddr(65535, &addr);
  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_EQUAL(65535, addr);
}

void test_NewNodeAddrFromBytes(void) {
  VlcbNodeAddr addr = 15;
  int ret;

  ret = vlcb_defs_NewNodeAddrFromBytes(0, 0, &addr);
  TEST_ASSERT_EQUAL(1, ret);
  TEST_ASSERT_EQUAL(15, addr);

  ret = vlcb_defs_NewNodeAddrFromBytes(0, 1, &addr);
  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_EQUAL(1, addr);

  ret = vlcb_defs_NewNodeAddrFromBytes(255, 255, &addr);
  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_EQUAL(65535, addr);
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_NewNodeAddrFromBytesUnchecked);
  RUN_TEST(test_NewNodeAddrUnitialized);
  RUN_TEST(test_NewNodeAddr);
  RUN_TEST(test_NewNodeAddrFromBytes);

  return UNITY_END();
}