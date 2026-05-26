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

void test_pid3(void)
{
    TEST_ASSERT_EQUAL(0xCA, lin_compute_pid(0x0A));
}

void test_checksum1(void)
{
    lin_frame_t lin_frame;
    lin_frame.data[0] = 0x01;
    lin_frame.data[1] = 0x02;
    lin_frame.dataLen = 2;
    TEST_ASSERT_EQUAL(0xFC, lin_compute_checksum(&lin_frame, 0));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_pid1);
    RUN_TEST(test_pid2);
    RUN_TEST(test_pid3);
    RUN_TEST(test_checksum1);
    return UNITY_END();
}