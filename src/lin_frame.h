#ifndef LIN_FRAME_H
#define LIN_FRAME_H

#include <stdbool.h>
#include <stdint.h>

#define LIN_SYNC_BYTE 0x55u
#define LIN_MAX_DATA_LEN 8u

typedef struct
{
    uint8_t pid;
    uint8_t data[LIN_MAX_DATA_LEN];
    uint8_t dataLen;
    uint8_t checksum;
} lin_frame_t;

uint8_t lin_compute_pid(uint8_t id);
uint8_t lin_compute_checksum(const lin_frame_t *frame, bool enhanced);

#endif /*LIN_FRAME_H*/