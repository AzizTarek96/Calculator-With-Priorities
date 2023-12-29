/*
 * main.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Aziz
 */

#include"../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_interface.h"
#include "../MCAL/PORT/PORT_interface.h"
#include"../HAL/CLCD/CLCD_interface.h"
#include"../HAL/KPD/KPD_interface.h"
#include<util/delay.h>

u8 Global_u8PressedKey=0;
u8 Flag=1;
u16 Global_CalcArr[15];
u8 Global_u8Index=0;
u8 i=0;
u8 Result=0;
void main()
{
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidWriteString("Enter Your");
		CLCD_voidGoToXY(0,1);
		CLCD_voidWriteString("Equation");
		_delay_ms(2000);
		CLCD_voidSendCommand(1);
		Flag=1;
		while(Flag)
		{
			Global_u8PressedKey=KPD_u8GetPressedKey();
			if(Global_u8PressedKey!=0xff)
			{
				if(Global_u8PressedKey<10)
				{
					ClCD_voidWriteInteger(Global_u8PressedKey);
					Global_CalcArr[Global_u8Index]=Global_u8PressedKey+Global_CalcArr[Global_u8Index]*10;
				}
				else if(Global_u8PressedKey=='=')
				{
					for(i=1;i<=Global_u8Index;i+=2)
					{

						if(Global_CalcArr[i]=='*')
						{
							Global_CalcArr[i+1]=Global_CalcArr[i-1]*Global_CalcArr[i+1];
							Global_CalcArr[i]='+';
							Global_CalcArr[i-1]=0;
						}
						else if(Global_CalcArr[i]=='/')
						{
							Global_CalcArr[i+1]=Global_CalcArr[i-1]/Global_CalcArr[i+1];
							Global_CalcArr[i]='+';
							Global_CalcArr[i-1]=0;
						}
					}
					for(i=1;i<=Global_u8Index;i+=2)
					{

						if(Global_CalcArr[i]=='+')
						{
							Global_CalcArr[i+1]=Global_CalcArr[i-1]+Global_CalcArr[i+1];
							Global_CalcArr[i-1]=0;
						}
						else if(Global_CalcArr[i]=='-')
						{
							Global_CalcArr[i+1]=Global_CalcArr[i-1]-Global_CalcArr[i+1];
							Global_CalcArr[i-1]=0;
						}
					}
					CLCD_voidGoToXY(0,1);
					CLCD_voidSendData(Global_u8PressedKey);
					ClCD_voidWriteInteger(Global_CalcArr[Global_u8Index]);
				}
				else
				{
					CLCD_voidSendData(Global_u8PressedKey);
					Global_u8Index++;
					Global_CalcArr[Global_u8Index]=Global_u8PressedKey;
					Global_u8Index++;
				}
			}
			if(Global_u8PressedKey=='A')
			{
				Flag=0;
				for(i=0;i<=Global_u8Index;i++)
				{
					Global_CalcArr[Global_u8Index]=0;
				}
			}
		}
	}
}
