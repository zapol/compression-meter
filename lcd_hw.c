#include "stm32f10x.h"
#include "lcd_hw.h"

void lcdInit()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);

    /* LCD_BKLT_PIN used as LCD backlight */
    GPIO_InitStructure.GPIO_Pin = LCD_BKLT_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(LCD_DC, &GPIO_InitStructure);

    TIM2->CR1 = 0;
    TIM2->CR2 = 0;
    TIM2->SMCR = 0;
    TIM2->DIER = 0;
    TIM2->EGR = 0;
    TIM2->CCMR1 = (6<<4);       // OC1 in PWM mode 1
    TIM2->CCER = TIM_CCER_CC1E;
    TIM2->PSC = 0x00;
    TIM2->ARR = 0xff;
    TIM2->CR1 |= TIM_CR1_CEN;

    /* LCD_DC_PIN used as LCD data/command select */
    GPIO_InitStructure.GPIO_Pin = LCD_DC_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(LCD_DC, &GPIO_InitStructure);

    /* LCD SPI pins */
    GPIO_InitStructure.GPIO_Pin = LCD_CS_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(LCD_CS, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LCD_SCK_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(LCD_SCK, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LCD_MISO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(LCD_MISO, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LCD_MOSI_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(LCD_MOSI, &GPIO_InitStructure);

    LCD_SPI->CR1 = SPI_CR1_MSTR;
    LCD_SPI->CR1 |= SPI_CR1_SPE;
}

void lcdSetBklight(uint8_t brightness)
{
    TIM2->CCR1 = brightness;
}
