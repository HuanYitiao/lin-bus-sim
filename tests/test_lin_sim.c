#include "lin_frame.h"
#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_pid1(void)
{
    TEST_ASSERT_EQUAL(0x80, lin_compute_pid(0x00));
}

void test_pid2(void)
{
    TEST_ASSERT_EQUAL(0x92, lin_compute_pid(0x12));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_pid1);
    RUN_TEST(test_pid2);
    return UNITY_END();
}