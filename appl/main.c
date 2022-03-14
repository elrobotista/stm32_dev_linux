/* Continue funciones de configuración del reloj de periféricos
como: rcc_periph_clock_enable */
#include "libopencm3/stm32/rcc.h"

/* Contiene funciones de configuración y uso de GPIO como:
gpio_toggle */
#include "libopencm3/stm32/gpio.h"

/* Macros para ayudar en la legibilidad del código. */
#define GPIO_PORT_LED1 (GPIOA)
#define GPIO_PIN_LED1 (GPIO5)
#define RCC_PORT_LED1 (RCC_GPIOA)

int main(void)
{
  /* Habilita el reloj hacia el puerto A */
  rcc_periph_clock_enable(RCC_PORT_LED1);

  /* Configura el puerto A, pin 5 como salida,
  con las resistencias de pull-up/down desactivadas. */
  gpio_mode_setup(
    GPIO_PORT_LED1,
    GPIO_MODE_OUTPUT,
    GPIO_PUPD_NONE,
    GPIO_PIN_LED1
  );

  /* Configura el pin 5 como salida tipo push-pull,
  a baja frequencia (2MHz, la opción máxima es 100MHz) */
  gpio_set_output_options(
    GPIO_PORT_LED1,
    GPIO_OTYPE_PP,
    GPIO_OSPEED_2MHZ,
    GPIO_PIN_LED1
  );

  /* Loop infinito para que el procesador siempre esté ejecutando
  la applicación. */
  while(1) {

    /* Ocasiona que el procesador se retarde entre cada ejecución de la
    función gpio_toggle. Desperdicia tiempo a propósito. */
    for(volatile unsigned int tmr = 1e6; tmr > 0; tmr--);

    /* Enciende / apaga el LED. */
    gpio_toggle(GPIOA, GPIO5);
  }
  return 0;
}
