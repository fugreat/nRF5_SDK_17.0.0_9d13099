#ifndef _BOARD_GPO_H_
#define _BOARD_GPO_H_
#include "nordic_common.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
 * DEFINITIONS
 */
#define BSP_LED0_IO               20
#define BSP_LED1_IO               18

#define BSP_LED0_OFF                    0x00
#define BSP_LED0_ON                     0x01
#define BSP_LED1_OFF                    0x00
#define BSP_LED1_ON                     0x01

/*********************************************************************
 * API FUNCTIONS
 */
void Board_LED0Init(void);
void Board_LED0Set(uint8_t beepMode);
void Board_LedInit(void);
void Board_LedSet(uint8_t ledMode);

#endif /* _BOARD_GPO_H_ */
