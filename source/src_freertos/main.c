#include <stdlib.h>
#include <FreeRTOS.h>
#include <task.h>
#include "stm32f30x.h"

#define LED_PORT GPIOC
#define LED_PIN GPIO_Pin_13

#ifdef USE_OVERCLOCKING
extern uint32_t overclock_stm32f303(void);
#endif

int k = 0;

void led_init()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(LED_PORT, &GPIO_InitStructure);

	LED_PORT->ODR |= LED_PIN;
}

void task_blink(void *args __attribute__((unused)))
{
	while (1)
	{
		LED_PORT->ODR ^= LED_PIN;
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

int main(void)
{
#ifdef USE_OVERCLOCKING
    SystemCoreClock = overclock_stm32f303();
#endif
	if (SysTick_Config(SystemCoreClock / 1000)) {
		/* Capture error */
		while (1);
	}

	led_init();

	int *test_var = malloc(sizeof(int));
	*test_var = 5;

	xTaskCreate(task_blink, "blink", 200, NULL, configMAX_PRIORITIES - 1, NULL);
	vTaskStartScheduler();

	while (1);
	return 0;
}
