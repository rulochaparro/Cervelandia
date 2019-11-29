
#ifndef __NEXCONFIG_H__
#define __NEXCONFIG_H__
//#include "Serial.h"
#include "sapi.h"

#define nexSerial_init(b)        uartConfig( UART_ENET, b)
#define nexSerial_available()    uartRxReady(UART_ENET)//Serial_Available()
#define nexSerial_read()         uartRxRead(UART_ENET)//Serial_Read()
#define nexSerial_write(d)       uartWriteByte(UART_ENET,d)//Serial_Write(d)
#define nexSerial_print(p)       uartWriteString(UART_ENET,p)//Serial_Print(p)
#define nexSerial_readBytes(b,l) uartReadByte(UART_ENET,b)//Serial_ReadBytes(b, l)
#define nexDelay(d)              delay(d)

#endif /* #ifndef __NEXCONFIG_H__ */
