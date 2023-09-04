/* User Defined Functions*/
#include <stdint.h>

#define SCREEN_ADDRESS 0x3C
#define MPU_ADDRESS 0x68

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

void setup_Text(int size, int w, int h);

void set_MPU6050();
void set_Screen();