//#include "util.h"
//#include "OSA.h"
#define UTIL_GOBAL
#include "util.h"


void Delay(ulong delay_count_max)
{
    ulong delay_count = 0;

    for (delay_count = 0; delay_count < delay_count_max; delay_count++) 
    {
        ;
    }

}

uchar calculateCRC8(uchar * inData, uchar dataLen)
{
    uchar i = 0, j = 0, crc = 0;

    for (j = 0; j < dataLen; j++) 
    {
        crc ^= *inData++;
        for (i = 0; i < 8; i++) 
        {
            if ((crc & 0x80) != 0) 
            {
                crc <<= 1;
                crc ^= 0x07;
            } 
            else 
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

