
/* This file was automatically generated by nrfutil on 2020-06-13 (YY-MM-DD) at 04:25:34 */

#include "stdint.h"
#include "compiler_abstraction.h"

/* This file was generated with a throwaway private key, that is only inteded for a debug version of the DFU project.
  Please see https://github.com/NordicSemiconductor/pc-nrfutil/blob/master/README.md to generate a valid public key. */

#ifdef NRF_DFU_DEBUG_VERSION 

/** @brief Public key used to verify DFU images */
__ALIGN(4) const uint8_t pk[64] =
{
    0x75, 0xce, 0xc2, 0x61, 0x07, 0x7f, 0x63, 0x2d, 0xa0, 0xed, 0x0b, 0xaa, 0xf5, 0xbc, 0x95, 0x97, 0x8d, 0x10, 0xc8, 0xa6, 0xcf, 0xce, 0x8b, 0xab, 0x26, 0x38, 0x5b, 0x3f, 0xab, 0x69, 0x47, 0xcc, 
    0x93, 0xe4, 0x7e, 0x57, 0x1c, 0xe8, 0xb4, 0xe8, 0x7c, 0x3e, 0xc9, 0xc7, 0xe4, 0xef, 0x3e, 0x35, 0xb7, 0xc6, 0xcd, 0xe5, 0x9c, 0x26, 0xd5, 0x85, 0x60, 0x7b, 0xaa, 0x3a, 0xc4, 0x9f, 0x7f, 0x87
};

#else
#error "Debug public key not valid for production. Please see https://github.com/NordicSemiconductor/pc-nrfutil/blob/master/README.md to generate it"
#endif