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
#include <stdlib.h>
#include <stdbool.h>

char x[3];
char z[3];
int locx;
int locz;
void ssd1306_TestBorder() {

}
void fetchLocation(){

	 char x[3];
	 		char z[3];
	 		for(int index =0; index <3; index++){
	 				x[index]=testing[index+1];
	 				z[index]= testing[index+5];
	 		}
	 		 sscanf(x, "%d", &locx);
	 		 sscanf(z, "%d", &locz);
	 		 ssd1306_DrawPixel(locx, locz, White);
	 		//GPIOA -> ODR |= GPIO_PIN_5;
}

void ssd1306_TestFonts() {
	time_t t;
	srand((unsigned) &t);
	char score = '0';
		 bool doorgaan = 1;
	 while(1){
		 int randx = rand()%128;
		 int randy = rand()%50 + 10;
	while(doorgaan){
		ssd1306_Fill(Black);
		fetchLocation();

		for(int index =0; index <3; index++){
				x[index]=testing[index+1];
				z[index]= testing[index+5];
		}

		 sscanf(x, "%d", &locx);
		 sscanf(z, "%d", &locz);
		 ssd1306_DrawPixel(locx, locz, White);
		 ssd1306_DrawPixel(randx, randy, White);
		 ssd1306_UpdateScreen();
		 if( (locx == randx) && (locz == randy)){
			 	 doorgaan = 0;
			 	 score++;
			 	 break;
		 }
	 }

    ssd1306_SetCursor(2, 18);
    ssd1306_Fill(Black);
    ssd1306_WriteString("punt erbij...", Font_6x8, White);
    ssd1306_SetCursor(2, 18+8);
    ssd1306_WriteString("Wil je doorgaan?", Font_6x8, White);
    ssd1306_SetCursor(2, 18+18+18);
    ssd1306_WriteString("ja?", Font_6x8, White);
    ssd1306_SetCursor(80, 18+18+18);
    ssd1306_WriteString("nee?", Font_6x8, White);
    fetchLocation();
    ssd1306_UpdateScreen();
    if( locx <= 20){
    	 doorgaan=1;
 		ssd1306_Fill(Black);

    	 }
    if (locx >= 100){
    	ssd1306_Fill(Black);
    	ssd1306_SetCursor(2, 18);
    	ssd1306_WriteString("einde", Font_6x8, White);
        ssd1306_UpdateScreen();

    	break;
    	}


}
}

void ssd1306_TestFPS() {

}

void ssd1306_TestAll() {
    ssd1306_Init();
    ssd1306_TestFonts();
}
