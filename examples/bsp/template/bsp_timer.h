#ifndef _BSP_TIMER_H_
#define _BSP_TIMER_H_

/*********************************************************************
 * DEFINITIONS
 */
#define TEST_PERIOD    APP_TIMER_TICKS(2000) // 定时时间（200ms）

/*********************************************************************
* API FUNCTIONS
*/
void CreateTestTimer(void);
void StartTestTimer(void);
void StopTestTimer(void);

#endif /* _BSP_TIMER_H_ */
