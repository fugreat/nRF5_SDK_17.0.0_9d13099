/*********************************************************************
 * INCLUDES
 */
#include "app_timer.h"
#include "bsp_timer.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"





static void timer_testCallback(void *arg);

/*********************************************************************
 * LOCAL VARIABLES
 */
APP_TIMER_DEF(s_testTimer);    // LED闪烁开的定时器

/*********************************************************************
 * PUBLIC FUNCTIONS
 */
/**
 @brief 创建测试的定时器
 @param 无
 @return 无
*/
void CreateTestTimer(void)
{
    app_timer_create(&s_testTimer, APP_TIMER_MODE_REPEATED, timer_testCallback);
}

/**
 @brief 开启测试的定时器
 @param 无
 @return 无
*/
void StartTestTimer(void)
{
    app_timer_start(s_testTimer, TEST_PERIOD, NULL);
}

/**
 @brief 关闭测试的定时器
 @param 无
 @return 无
*/
void StopTestTimer(void)
{
    app_timer_stop(s_testTimer);
}


/*********************************************************************
 * LOCAL FUNCTIONS
 */
/**
 @brief 测试定时器的回调函数
 @param 无
 @return 无
*/
static void timer_testCallback(void *arg)
{
    UNUSED_PARAMETER(arg);
    // 在这里加入自己的应用处理
    NRF_LOG_INFO("Template TIMER_CP.");
		uint8_t temp[1] = {0x01};
		SPI_ReadWriteData(temp, NULL, sizeof(uint8_t));

}
