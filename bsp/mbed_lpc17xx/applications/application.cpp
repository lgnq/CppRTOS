/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 * 2010-03-04     Magicoe      for LPC1766 version
 * 2010-05-02     Aozima       add led function
 * 2010-05-24     Bernard      add filesystem initialization and move led function to led.c
 * 2012-04-15     Bernard      enable components_init.
 */

#include "application.h"

/* thread phase init */
void rt_init_thread_entry(void *parameter)
{
	/* initialize platform */
	platform_init();

	while (1)
	{
		rt_hw_led_on(LED1);
		rt_hw_led_on(LED3);
		rt_thread_delay(100);
		rt_hw_led_off(LED1);
		rt_hw_led_off(LED3);
		rt_thread_delay(100);
	}
}

int rt_application_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("init", rt_init_thread_entry, RT_NULL, 2048, RT_THREAD_PRIORITY_MAX/3, 20);
    if (tid != RT_NULL) 
		rt_thread_startup(tid);

    return 0;
}

