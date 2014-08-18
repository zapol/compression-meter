#ifndef LCD_HW_H_INCLUDED
#define LCD_HW_H_INCLUDED

#define LCD_BKLT                            GPIOA
#define LCD_BKLT_PIN                        GPIO_Pin_0

#define LCD_DC                              GPIOA
#define LCD_DC_PIN                          GPIO_Pin_1

#define LCD_CS                              GPIOA
#define LCD_CS_PIN                          GPIO_Pin_4
#define LCD_SCK                             GPIOA
#define LCD_SCK_PIN                         GPIO_Pin_5
#define LCD_MISO                            GPIOA
#define LCD_MISO_PIN                        GPIO_Pin_6
#define LCD_MOSI                            GPIOA
#define LCD_MOSI_PIN                        GPIO_Pin_7
#define LCD_SPI                             SPI1

void lcdInit(void);
void lcdSetBklight(uint8_t brightness);

#endif // LCD_HW_H_INCLUDED
