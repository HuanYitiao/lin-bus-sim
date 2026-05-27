#include "lin_frame.h"

int16_t lin_compute_pid(uint8_t id)
{
    if (63 < id)
    {
        return -1;
    }

    uint8_t bit0 = id & 1;
    uint8_t bit1 = (id >> 1) & 1;
    uint8_t bit2 = (id >> 2) & 1;
    uint8_t bit3 = (id >> 3) & 1;
    uint8_t bit4 = (id >> 4) & 1;
    uint8_t bit5 = (id >> 5) & 1;

    uint8_t parityBit0 = bit0 ^ bit1 ^ bit2 ^ bit4;
    uint8_t parityBit1 = !(bit1 ^ bit3 ^ bit4 ^ bit5);

    uint8_t pid = (parityBit1 << 7) | (parityBit0 << 6) | id;
    return pid;
}

uint8_t lin_compute_checksum(const lin_frame_t *frame, bool enhanced)
{
    uint16_t tmp;

    if (0 == enhanced)
    {
        tmp = 0;
    }
    else
    {
        tmp = frame->pid;
    }

    for (int i = 0; i < frame->dataLen; i++)
    {
        tmp += frame->data[i];
        if (tmp >= 256)
        {
            tmp -= 256;
        }
    }

    return 0xFF - tmp;
}