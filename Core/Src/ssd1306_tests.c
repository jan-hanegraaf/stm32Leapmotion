/*
 * ssd1306_test.c
 *
 *  Created on: Jan 30, 2020
 *      Author: 20004719
 */
#include "usbd_cdc_if.h"
#include "ssd1306.h"
#include <string.h>
#include <stdio.h>

void ssd1306_TestBorder() {


    uint32_t start = HAL_GetTick();
    uint32_t end = start;
    uint8_t x = 0;
    uint8_t y = 0;
    do {
        ssd1306_DrawPixel(x, y, Black);

        if((y == 0) && (x < 127))
            x++;
        else if((x == 127) && (y < 63))
            y++;
        else if((y == 63) && (x > 0))
            x--;
        else
            y--;

        ssd1306_DrawPixel(x, y, White);
        ssd1306_UpdateScreen();

        HAL_Delay(5);
        end = HAL_GetTick();
    } while((end - start) < 8000);

    HAL_Delay(1000);
}

void ssd1306_TestFonts() {
	while(1){
/*		char x[3];
		char z[3];
		for(int i=0; i <Length;i++){
			char test = testing[i];
			int temp;
			if(strcmp(test,'X')==0){
				temp = i;

			}
			if(strcmp(test,'Z')==0){
				for (int j =0; j < (i-temp);j++){
					x[j]=testing[temp+j+1];
				}
				temp = i;
			}
			if(strcmp(test,'*')==0){
				for (int g =0; g < (i-temp);g++){
					z[g]=testing[temp+g+1];
				}
			}
			ssd1306_SetCursor(2, 0);
			ssd1306_WriteString(x, Font_11x18, White);
		}

		      ssd1306_SetCursor(2, 18);
		      ssd1306_WriteString(&*testing, Font_11x18, White);
		      ssd1306_UpdateScreen();
}
*/
		ssd1306_Fill(Black);
				char x[3];
				char z[3];
				x[0]=testing[1];
				x[1]=testing[2];
				x[2]=testing[3];

				z[0]= testing[5];
				z[1]= testing[6];
				z[2]= testing[7];



				// ssd1306_SetCursor(2, 18);
				// ssd1306_WriteString(x, Font_11x18, White);
				// ssd1306_SetCursor(2, 18+18);
				// ssd1306_WriteString(z, Font_11x18, White);
				// ssd1306_UpdateScreen();
				 int locx;
				 int locz;
				 sscanf(x, "%d", &locx);
				 sscanf(z, "%d", &locz);
				 ssd1306_DrawPixel(locx, locz, White);
				 ssd1306_UpdateScreen();
}
}

void ssd1306_TestFPS() {
    ssd1306_Fill(White);

    uint32_t start = HAL_GetTick();
    uint32_t end = start;
    int fps = 0;
    char message[] = "ABCDEFGHIJK";

    ssd1306_SetCursor(2,0);
    ssd1306_WriteString("Testing...", Font_11x18, Black);

    do {
        ssd1306_SetCursor(2, 18);
        ssd1306_WriteString(message, Font_11x18, Black);
        ssd1306_UpdateScreen();

        char ch = message[0];
        memmove(message, message+1, sizeof(message)-2);
        message[sizeof(message)-2] = ch;

        fps++;
        end = HAL_GetTick();
    } while((end - start) < 5000);

    HAL_Delay(1000);

    char buff[64];
    fps = (float)fps / ((end - start) / 1000.0);
    snprintf(buff, sizeof(buff), "~%d FPS", fps);

    ssd1306_Fill(White);
    ssd1306_SetCursor(2, 18);
    ssd1306_WriteString(buff, Font_11x18, Black);
    ssd1306_UpdateScreen();
}

void ssd1306_TestAll() {
    ssd1306_Init();
    ssd1306_TestFPS();
    HAL_Delay(3000);
    ssd1306_TestBorder();
    ssd1306_TestFonts();
}
