// Joypad
// read input from SDL and excute the functions here.
// FF00

#ifndef GAMEBOY_JOYPAD_H
#define GAMEBOY_JOYPAD_H

//#include "marshmallow.h"
#include <cstdint>

#define JOYPAD_ADDRESS 0xFF00

namespace gameboy
{
class Joypad
{
public:
    // handle inputs
    // according to CPU manual and other materials:
    // Joypad doesnt need to write the 0xFF00 register through memory interface.
    // i cant change Memory, so i need to add something here

    // which column had the ROM selected
    uint8_t key_column = 0x00;

    bool column_direction = 0;
    bool column_controls = 0;

    // these variables are default to 0b0000_1111
    // as we will perform operations on the least significant 4 digits
    // case DIRECTION KEYS
    uint8_t keys_directions = 0x0F;
    // case CONTROL KEYS
    uint8_t keys_controls = 0x0F;

    // temp FF00
    uint8_t temp_ff00 = 0x00;

    // handle intrrupts
    void joypad_interrupts(void);

    // write FF00 to memory
    void write_result(void);

    // reset Joypad
    void reset_joypad(void);
};
} // namespace gameboy

#endif