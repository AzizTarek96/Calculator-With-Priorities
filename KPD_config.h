/********************		Author: Aziz Tarek		**************/
/********************		Layer: HAL				**************/
/********************		SWC: KPD				**************/
/********************		Version: 1.00			**************/
/********************		Date: 26-10-2023		**************/
/*****************************************************************/
/*****************************************************************/


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_BUTTONS_VAL  {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'A',0,'=','+'}}

#define KPD_PORT   DIO_u8PORTC

#define NO_PRESSED_KEY 0xff
#define COULMN_PIN0   DIO_u8PIN0
#define COULMN_PIN1   DIO_u8PIN1
#define COULMN_PIN2   DIO_u8PIN2
#define COULMN_PIN3   DIO_u8PIN3

#define ROW_PIN0   DIO_u8PIN4
#define ROW_PIN1   DIO_u8PIN5
#define ROW_PIN2   DIO_u8PIN6
#define ROW_PIN3   DIO_u8PIN7


#endif
