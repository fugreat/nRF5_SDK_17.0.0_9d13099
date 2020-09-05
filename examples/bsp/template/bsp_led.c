/*********************************************************************
 * INCLUDES
 */
#include "nrf_gpio.h"
#include "nordic_common.h"
#include "bsp_led.h"

 /*********************************************************************
  * PUBLIC FUNCTIONS
  */
  /**
   @brief 蜂鸣器驱动初始化
   @param 无
   @return 无
  */
void Board_LED0Init(void)
{
    nrf_gpio_cfg_output(BSP_LED0_IO);
    nrf_gpio_pin_write(BSP_LED0_IO, 0);
}

/**
 @brief 配置蜂鸣器工作模式
 @param beepMode -[in] 工作模式
 @return 无
*/
void Board_LED0Set(uint8_t LED0Mode)
{
    switch (LED0Mode)                                                        // 执行模式
    {
    case BSP_LED0_OFF:                                                          // 蜂鸣器不响模式
        nrf_gpio_pin_write(BSP_LED0_IO, 0);
        break;

    case BSP_LED0_ON:                                                           // 蜂鸣器响模式
        nrf_gpio_pin_write(BSP_LED0_IO, 1);
        break;

    default:
        break;
    }
}

/**
 @brief LED灯驱动初始化
 @param 无
 @return 无
*/
void Board_LedInit(void)
{
    nrf_gpio_cfg_output(BSP_LED1_IO);
    nrf_gpio_pin_write(BSP_LED1_IO, 1);
}

/**
 @brief 配置LED灯工作模式
 @param ledMode -[in] 工作模式
 @return 无
*/
void Board_LedSet(uint8_t ledMode)
{
    switch (ledMode)                                                         // 执行模式
    {
    case BSP_LED1_OFF:                                                           // LED灭模式
        nrf_gpio_pin_write(BSP_LED1_IO, 0);
        break;

    case BSP_LED1_ON:                                                            // LED亮模式
        nrf_gpio_pin_write(BSP_LED1_IO, 1);
        break;

    default:
        break;
    }
}

/****************************************************END OF FILE****************************************************/
