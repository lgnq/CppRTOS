#include "led.h"
#include "LPC17xx.h"
#include "lpc17xx_gpio.h"

void rt_hw_led_init(void)
{
    GPIO_SetDir(1, 1<<18, 1);
    GPIO_SetDir(1, 1<<20, 1);
    GPIO_SetDir(1, 1<<21, 1);
    GPIO_SetDir(1, 1<<23, 1);
}

void rt_hw_led_on(rt_uint32_t led)
{
    switch (led)
    {
    case 0: /* P1.18 = 1 */
        GPIO_SetValue(1, 1<<18);
        break;
    case 1: /* P1.20 = 1 */
        GPIO_SetValue(1, 1<<20);
        break;
    case 2: /* P1.21 = 1 */
        GPIO_SetValue(1, 1<<21);
        break;
    case 3: /* P1.23 = 1 */
        GPIO_SetValue(1, 1<<23);
        break;
    default:
        break;
    }
}

void rt_hw_led_off(rt_uint32_t led)
{
    switch(led)
    {
    case 0: /* P1.18 = 0 */
        GPIO_ClearValue(1, 1<<18);
        break;
    case 1: /* P1.20 = 0 */
        GPIO_ClearValue(1, 1<<20);
        break;
    case 2: /* P1.21 = 0 */
        GPIO_ClearValue(1, 1<<21);
        break;
    case 3: /* P1.23 = 0 */
        GPIO_ClearValue(1, 1<<23);
        break;
    default:
        break;
    }
}
