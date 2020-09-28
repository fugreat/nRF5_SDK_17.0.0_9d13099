#ifndef _BOARD_SPI_H_
#define _BOARD_SPI_H_

/*********************************************************************
 * INCLUDES
 */
#include <stdbool.h>
#include <stdint.h>
#include "nordic_common.h"
#include "board_spi.h"
/*********************************************************************
 * DEFINITIONS
 */
#define BOARD_SPI_CS_ON             0
#define BOARD_SPI_CS_OFF            1

#define SPI_CS_HIGH                 SPI_CsnSet(BOARD_SPI_CS_OFF)
#define SPI_CS_LOW                  SPI_CsnSet(BOARD_SPI_CS_ON)

#define BOARD_SPI0_MISO_IO          17
#define BOARD_SPI0_MOSI_IO          18
#define BOARD_SPI0_CLK_IO           20
#define BOARD_SPI0_CSN_IO           19

#define SPI_INSTANCE  				0			// SPI instance index 

/*********************************************************************
 * API FUNCTIONS
 */
void SPI_Init(void);
void SPI_CsnSet(bool pinState);
void SPI_ReadWriteData(uint8_t *pWriteData, uint8_t *pReadData, uint8_t writeDataLen);
void SPI_Enable(void);
void SPI_Disable(void);

#endif /* _BOARD_SPI_H_ */
