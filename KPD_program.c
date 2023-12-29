/********************		Author: Aziz Tarek		**************/
/********************		Layer: HAL				**************/
/********************		SWC: KPD				**************/
/********************		Version: 1.00			**************/
/********************		Date: 26-10-2023		**************/
/*****************************************************************/
/*****************************************************************/

#include"STD_TYPES.h"

#include"DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8ColIdx , Local_u8RowIdx , Local_u8PressedKey=NO_PRESSED_KEY,Local_u8PinState;
	u8 Local_KPDArr[ROW_NUMBER][COULMN_NUMBER]=KPD_BUTTONS_VAL;
	u8 Local_COLArr[COULMN_NUMBER]={COULMN_PIN0,COULMN_PIN1,COULMN_PIN2,COULMN_PIN3};
	u8 Local_ROWArr[ROW_NUMBER]={ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};

	for(Local_u8ColIdx=0;Local_u8ColIdx<COULMN_NUMBER;Local_u8ColIdx++)
	{
		DIO_u8SetPinValue(KPD_PORT,Local_COLArr[Local_u8ColIdx],DIO_u8PIN_LOW);


		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUMBER;Local_u8RowIdx++)
		{
			DIO_u8GetPinValue(KPD_PORT,Local_ROWArr[Local_u8RowIdx],&Local_u8PinState);


			if(Local_u8PinState==DIO_u8PIN_LOW)
			{
				while(Local_u8PinState==DIO_u8PIN_LOW)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_ROWArr[Local_u8RowIdx],&Local_u8PinState);
				}
				Local_u8PressedKey=Local_KPDArr[Local_u8RowIdx][Local_u8ColIdx];
				DIO_u8SetPinValue(KPD_PORT,Local_COLArr[Local_u8ColIdx],DIO_u8PIN_HIGH);
				return Local_u8PressedKey;
			}
		}
		DIO_u8SetPinValue(KPD_PORT,Local_COLArr[Local_u8ColIdx],DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
