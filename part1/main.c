// a simple 8086 decoder... only works on register to register move instructions tho
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main( int argc, const char** argv ) {

    const int NUM_BYTES = 100;
    const uint8_t MOVW_FROM_REG = 0x89;
    const uint8_t MOD_REG = 0xC0;
    const char REGW[8][3] = { "ax", "cx", "dx", "bx", "sp", "bp", "si", "di" };

    if( argc < 2 ) {
        printf( "Provide a binary asm file to decode!\n" );
        return -1;
    }

    FILE *f = fopen( argv[1], "rb" );
    if( !f ) {
        printf( "Error in reading file. Abort.\n" );
        return -2;
    }

    uint8_t byte[NUM_BYTES];
    int num_bytes_read = 0;
    num_bytes_read = fread( byte, sizeof( byte[0] ), NUM_BYTES, f );
    printf( "bytes read: %d\n", num_bytes_read );
    if( byte[0] == MOVW_FROM_REG ) {
        if( byte[1] & 0xC0 == MOD_REG ) {
            printf( "mov %s, %s\n", REGW[byte[1] & 0x03], REGW[( byte[1] & 0x38 ) >> 3] );
        } else {
            printf( "Unknown MOD code.\n" );
            return -4;
        }
    } else {
        printf( "Unknown assembly opcode.\n" );
        return -3;
    }

    return 0;
}
