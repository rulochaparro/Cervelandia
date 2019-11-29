/* Copyright 2017, Pablo Ridolfi, Juan Esteban Alarcón, Juan Manuel Cruz
 * All rights reserved.
 *
 * This file is part of Workspace.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
 
/** @brief This is a simple statechart example using Yakindu Statechart Tool
 * Plug-in (update site: http://updates.yakindu.org/sct/mars/releases/).
 */

/** \addtogroup statechart Simple UML Statechart example.
 ** @{ */

/*==================[inclusions]=============================================*/

#include "main.h"
#include "sapi.h"       // <= sAPI header
#include "Nextion.h"
#include "Utilities.h"
#include "sol_AdHoc.h"
#include "sapi_ultrasonic_hcsr04.h"
#include "onewire.h"
#include "prefix.h"
#include "TimerTicks.h"

/* Select a TimeEvents choise	*/
//#define __USE_TIME_EVENTS (false)	/* "false" without TimeEvents */
#define __USE_TIME_EVENTS (true)	/* or "true" with TimerEvents */

DEBUG_PRINT_ENABLE;

#define TICKRATE_1MS	(1000)				/* 1000 ticks per second */
#define TICKRATE_MS		(TICKRATE_1MS)	/* 1000 ticks per second */

/*! This is a timed state machine that requires timer services */
#if (__USE_TIME_EVENTS == true)
	#define NOF_TIMERS (sizeof(PrefixTimeEvents)/sizeof(sc_boolean))
#else
	#define NOF_TIMERS 0
#endif
TimerTicks ticks[NOF_TIMERS];
/*! This is a state machine */
static Prefix statechart;
volatile bool SysTick_Time_Flag = false;
volatile bool Volver_Control_Flag = false;

/*!
 * This is a timed state machine that requires timer services
 */

#if (__USE_TIME_EVENTS == true)
/*! This function has to set up timers for the time events that are required by the state machine. */
/*!
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milli seconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset
*/
//extern void prefixIface_selec_Pantalla(const Prefix* handle, const sc_integer OpPantalla);

void prefix_setTimer(Prefix* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic)
{
	SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

/*! This function has to unset timers for the time events that are required by the state machine. */
/*!
	This function will be called for each time event taht is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
void prefix_unsetTimer(Prefix* handle, const sc_eventid evid)
{
	UnsetTimerTick(ticks, NOF_TIMERS, evid);
}
#endif

/**
 * @brief	Hook on Handle interrupt from SysTick timer
 * @return	Nothing
 */
void myTickHook( void *ptr ){
	SysTick_Time_Flag = true;
}



struct NexObject Bienvenida,Control,Eleccion,Embotellado,Calentar,Abrir_electrov,Densidad,Correccion,btn_volver_ctr,btn_embotellar,btn_producir,btn_control,btn_volver_emb,btn_330,btn_750,btn_volver_cal,btn_prox_cal,btn_volver_ele,btn_prox_ele;
struct NexObject btn_0,btn_1,btn_2,btn_3,btn_4,btn_5,btn_6,btn_7,btn_8,btn_9,btn_punt,btn_enter,btn_del,btn_ctr_corr;
struct NexObject Temp_01_ctr,Temp_02_ctr,Temp_03_ctr,Vol_01_ctr,Vol_02_ctr,Vol_03_ctr,num_330,num_750,Temp_01_cal,Vol_01_cal,Temp_01_abr;
struct NexObject Temp_03_abr,Vol_01_abr,Vol_03_abr,densidad_txt,Temp_03_corr,Vol_03_corr;

struct NexObject *nex_listen_list[]=
{
		/* Primero los nombres de las pantallas*/
		&Bienvenida,
		&Control,
		&Eleccion,
		&Embotellado,
		&Calentar,
		&Abrir_electrov,
		&Densidad,
		&Correccion,
		/* Segundo los botones de las pantallas*/
		/*Pantalla control*/
		&btn_volver_ctr,
		/* Pantalla Eleccion*/
		&btn_embotellar,
		&btn_producir,
		&btn_control,
		/* Pantalla Embotellado*/
		&btn_volver_emb,
		&btn_330,
		&btn_750,
		/* Pantalla Calentar*/
		&btn_volver_cal,
		&btn_prox_cal,
		/* Pantalla Ebrir_electrov*/
		&btn_volver_ele,
		&btn_prox_ele,
		/* Pantalla desnidad*/
		&btn_0,
		&btn_1,
		&btn_2,
		&btn_3,
		&btn_4,
		&btn_5,
		&btn_6,
		&btn_7,
		&btn_8,
		&btn_9,
		&btn_punt,
		&btn_enter,
		&btn_del,
		/* Pantalla Correccion*/
		&btn_ctr_corr,

		/*Objetos de las pantallas*/
		/*Pantalla Control*/
		&Temp_01_ctr,
		&Temp_02_ctr,
		&Temp_03_ctr,
		&Vol_01_ctr,
		&Vol_02_ctr,
		&Vol_03_ctr,
		/*Pantalla Embotellado*/
		&num_330,
		&num_750,
		/*Pantalla Calentar olla*/
		&Temp_01_cal,
		&Vol_01_cal,
		/*Pantala Abrir_electrov*/
		&Temp_01_abr,
		&Temp_03_abr,
		&Vol_01_abr,
		&Vol_03_abr,
		/*Pantalla Densidad*/
		&densidad_txt,
		/*Pantalla Correccion*/
		&Temp_03_corr,
		&Vol_03_corr


};
/* PROTOTIPOS DE FUNCIONES
/*Pantalla Control */
void btn_volver_ctr_CallBack(void *ptr);

/*Pantalla Eleccion */
void btn_Embotellar_CallBack(void *ptr);
void btn_producir_CallBack(void *ptr);
void btn_control_CallBack(void *ptr);

/*Pantalla Embotellado */

void btn_330_CallBack(void *ptr);
void btn_750_CallBack(void *ptr);
void btn_volver_emb_CallBack(void *ptr);

/*Pantalla Calentar */

void btn_volver_cal_CallBack(void *ptr);
void btn_prox_cal_CallBack(void *ptr);

/*Pantalla Abrir_electrov */

void btn_volver_ele_CallBack(void *ptr);
void btn_prox_ele_CallBack(void *ptr);

/*Pantalla Densidad */

void btn_1_CallBack(void *ptr);
void btn_2_CallBack(void *ptr);
void btn_3_CallBack(void *ptr);
void btn_4_CallBack(void *ptr);
void btn_5_CallBack(void *ptr);
void btn_6_CallBack(void *ptr);
void btn_7_CallBack(void *ptr);
void btn_8_CallBack(void *ptr);
void btn_9_CallBack(void *ptr);
void btn_0_CallBack(void *ptr);
void btn_punt_CallBack(void *ptr);
void btn_enter_CallBack(void *ptr);
void btn_del_CallBack(void *ptr);

/*Pantalla Correccion */

void btn_ctr_corr_CallBack(void *ptr);

void prefixIface_opLED(Prefix* , sc_integer , sc_boolean );
void prefixIface_opGPIO(Prefix* , sc_integer , sc_boolean );
void prefixIface_pantalla_Control(Prefix*, sc_integer);
void prefixIface_pantalla_Calentar(Prefix*, sc_integer);
void prefixIface_pantalla_Abrir(Prefix*, sc_integer);
void prefixIface_pantalla_Correccion(Prefix*, sc_integer);
void prefixIface_pantalla_Embotellado(Prefix*, sc_integer, sc_integer, sc_integer);
void prefixIface_pantalla_Densidad(Prefix*, sc_integer,sc_boolean);

/*Variables globales*/
int densidad=0,densidad_dec=0;

int main(void){

		#if (__USE_TIME_EVENTS == true)
		uint32_t i;
		#endif

		/*Creo las pantallas*/
        CreateNexObject(Bienvenida,0,0,"Bienvenida");
		CreateNexObject(Control,1,0,"Control");
		CreateNexObject(Eleccion,2,0,"Eleccion");
		CreateNexObject(Embotellado,3,0,"Embotellado");
		CreateNexObject(Calentar,4,0,"Calentar");
		CreateNexObject(Abrir_electrov,5,0,"Abrir_electrov");
		CreateNexObject(Densidad,6,0,"Densidad");
		CreateNexObject(Correccion,7,0,"Correccion");

		/* Creo los botones numeros y texto*/
		/*Botones de la pantalla Control*/
		CreateNexObject(btn_volver_ctr,1,4,"btn_volver_ctr");
		CreateNexObject(Temp_01_ctr,1,1,"Temp_01_ctr");
		CreateNexObject(Temp_02_ctr,1,2,"Temp_02_ctr");
		CreateNexObject(Temp_03_ctr,1,3,"Temp_03_ctr");
		CreateNexObject(Vol_01_ctr,1,4,"Vol_01_ctr");
		CreateNexObject(Vol_02_ctr,1,5,"Vol_02_ctr");
		CreateNexObject(Vol_03_ctr,1,6,"Vol_03_ctr");
		/*Botones de la pantalla Eleccion*/
		CreateNexObject(btn_embotellar,2,1,"btn_embotellar");
		CreateNexObject(btn_producir,2,2,"btn_producir");
		CreateNexObject(btn_control,2,3,"btn_control");

		/*Botonesde la pantalla Embotellado*/
		CreateNexObject(btn_330,3,1,"btn_330");
		CreateNexObject(btn_750,3,2,"btn_750");
		CreateNexObject(btn_volver_emb,3,3,"btn_volver_emb");
		CreateNexObject(num_330,3,4,"num_330");
		CreateNexObject(num_750,3,5,"num_750");
		/*Botones de la pantalla Calentar*/
		CreateNexObject(btn_volver_cal,4,1,"btn_volver_cal");
		CreateNexObject(btn_prox_cal,4,2,"btn_prox_cal");
		CreateNexObject(Temp_01_cal,4,3,"Temp_01_cal");
		CreateNexObject(Vol_01_cal,4,4,"Vol_01_cal");
		/*Botones de la pantalla Abrir_electrov*/
		CreateNexObject(btn_volver_ele,5,1,"btn_volver_ele");
		CreateNexObject(btn_prox_ele,5,2,"btn_prox_ele");
		CreateNexObject(Temp_01_abr,5,3,"Temp_01_abr");
		CreateNexObject(Vol_01_abr,5,4,"Vol_01_abr");
		CreateNexObject(Temp_03_abr,5,5,"Temp_03_abr");
		CreateNexObject(Vol_03_abr,5,6,"Vol_03_abr");
		/*Botones de la pantalla Densidad*/
		CreateNexObject(btn_1,6,1,"btn_1");
		CreateNexObject(btn_2,6,2,"btn_2");
		CreateNexObject(btn_3,6,3,"btn_3");
		CreateNexObject(btn_4,6,4,"btn_4");
		CreateNexObject(btn_5,6,5,"btn_5");
		CreateNexObject(btn_6,6,6,"btn_6");
		CreateNexObject(btn_7,6,7,"btn_7");
		CreateNexObject(btn_8,6,8,"btn_8");
		CreateNexObject(btn_9,6,9,"btn_9");
		CreateNexObject(btn_0,6,10,"btn_0");
		CreateNexObject(btn_punt,6,11,"btn_punt");
		CreateNexObject(btn_enter,6,12,"btn_enter");
		CreateNexObject(btn_del,6,13,"btn_del");
		CreateNexObject(densidad_txt,6,14,"densidad_txt");
		/*Botones de la pantalla Correccion*/
		CreateNexObject(btn_ctr_corr,7,1,"btn_ctr_corr");
		CreateNexObject(Temp_03_corr,7,2,"Temp_03_corr");
		CreateNexObject(Vol_03_corr,7,3,"Vol_03_corr");

		/* Inicializar la placa */
	   boardConfig();
	   /*Configuro el puerto del sensor de temperatura como entrada.*/
	   //gpioConfig( GPIO7, GPIO_INPUT );
	   gpioConfig( GPIO3, GPIO_OUTPUT );
	   /*Configuro el puerto del sensor de temperatura como entrada.*/
	   gpioConfig( GPIO8, GPIO_INPUT );
	   /*Configuro el puerto del sensor de Salida electroválvula 1.*/
	   gpioConfig( GPIO5, GPIO_OUTPUT );
	   gpioWrite(GPIO5, true);
	   /*Configuro el puerto del sensor de Salida electroválvula 2.*/
	   gpioConfig( GPIO6, GPIO_OUTPUT );
	   gpioWrite(GPIO6, true);
	   	/* ------------- INICIALIZACIONES ------------- */

	   	/* Inicializar UART_USB como salida de consola */
//	   uartConfig( UART_USB, 115200 );
	   	/* UART for debug messages. */
	   	debugPrintConfigUart( UART_USB, 115200 );
	   	debugPrintString( "DEBUG c/sAPI\r\n" );

	   /* Inicializar el sensor ultrasonico #0 */
	   ultrasonicSensorConfig(ULTRASONIC_SENSOR_0, ULTRASONIC_SENSOR_ENABLE);

	   /* Configurar PWM */
	   pwmConfig( 0, PWM_ENABLE );
	   pwmConfig( PWM7, PWM_ENABLE_OUTPUT );

	   /*Configuro owire para sensor de temp*/


	   //SystemCoreClockUpdate();
	   //SysTick_Config(SystemCoreClock / 1000);
	   //SysTick_Config(SystemCoreClock / 1000000);



	   /* Init Ticks counter => TICKRATE_MS */
		tickConfig( TICKRATE_MS );

		/* Add Tick Hook */
		tickCallbackSet( myTickHook, (void*)NULL );
		/* Statechart Initialization */
		#if (__USE_TIME_EVENTS == true)
		InitTimerTicks(ticks, NOF_TIMERS);
		#endif
		   //owInit(2,8);
		   owInit(3,7);
	   prefix_init(&statechart);
	   prefix_enter(&statechart);

	   nexInit();
	   /*Pantalla Control*/
	   NexTouch_attachPush(&btn_volver_ctr,btn_volver_ctr_CallBack,0);

	   /*Pantalla Elleccion*/
	   NexTouch_attachPush(&btn_embotellar,btn_Embotellar_CallBack,0);
	   NexTouch_attachPush(&btn_producir,btn_producir_CallBack,0);
	   NexTouch_attachPush(&btn_control,btn_control_CallBack,0);

	   /*Pantalla Embotellado*/
	   NexTouch_attachPush(&btn_330,btn_330_CallBack,0);
	   NexTouch_attachPush(&btn_750,btn_750_CallBack,0);
	   NexTouch_attachPush(&btn_volver_emb,btn_volver_emb_CallBack,0);

	   /*Pantalla Calentar*/
	   NexTouch_attachPush(&btn_volver_cal,btn_volver_cal_CallBack,0);
	   NexTouch_attachPush(&btn_prox_cal,btn_prox_cal_CallBack,0);

	   /*Pantalla Abrir_electrov*/
	   NexTouch_attachPush(&btn_volver_ele,btn_volver_ele_CallBack,0);
	   NexTouch_attachPush(&btn_prox_ele,btn_prox_ele_CallBack,0);

	   /*Pantalla Densidad*/
	   NexTouch_attachPush(&btn_1,btn_1_CallBack,0);
	   NexTouch_attachPush(&btn_2,btn_2_CallBack,0);
	   NexTouch_attachPush(&btn_3,btn_3_CallBack,0);
	   NexTouch_attachPush(&btn_4,btn_4_CallBack,0);
	   NexTouch_attachPush(&btn_5,btn_5_CallBack,0);
	   NexTouch_attachPush(&btn_6,btn_6_CallBack,0);
	   NexTouch_attachPush(&btn_7,btn_7_CallBack,0);
	   NexTouch_attachPush(&btn_8,btn_8_CallBack,0);
	   NexTouch_attachPush(&btn_9,btn_9_CallBack,0);
	   NexTouch_attachPush(&btn_0,btn_0_CallBack,0);
	   NexTouch_attachPush(&btn_punt,btn_punt_CallBack,0);
	   NexTouch_attachPush(&btn_enter,btn_enter_CallBack,0);
	   NexTouch_attachPush(&btn_del,btn_del_CallBack,0);

	   /*Pantalla Correccion*/
	   NexTouch_attachPush(&btn_ctr_corr,btn_ctr_corr_CallBack,0);



	   gpioWrite(LEDB,ON);
	   delay(500);
	   gpioWrite(LED3,ON);
	   gpioWrite(LEDB,OFF);
	   /* ------------- REPETIR POR SIEMPRE ------------- */
	   while(1) {
		   //gpioToggle(GPIO3);
		   nexLoop(nex_listen_list);

		   if (SysTick_Time_Flag == true) {
			   SysTick_Time_Flag = false;

			   #if (__USE_TIME_EVENTS == true)
				UpdateTimers(ticks, NOF_TIMERS);
				for (i = 0; i < NOF_TIMERS; i++) {
					if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true) {

						prefix_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
						MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
					}
				}
				#else
				prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK
				#endif


		   prefix_runCycle(&statechart);

		   }

		}

	   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	      por ningun S.O. */

   return 0 ;
}

/*Pantalla Control */
void btn_volver_ctr_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 0);
	prefix_runCycle(&statechart);
}
/*Pantalla Eleccion */
void btn_Embotellar_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 1);
	prefix_runCycle(&statechart);
}
void btn_producir_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 2);
	prefix_runCycle(&statechart);
}
void btn_control_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 3);
	prefix_runCycle(&statechart);
}
/*Pantalla Embotellado */

void btn_330_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 6);
	prefix_runCycle(&statechart);
}

void btn_750_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 7);
	prefix_runCycle(&statechart);
}

void btn_volver_emb_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 5);
	prefix_runCycle(&statechart);
}

/*Pantalla Calentar */

void btn_volver_cal_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 8);
	prefix_runCycle(&statechart);
}

void btn_prox_cal_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 9);
	prefix_runCycle(&statechart);
}

/*Pantalla Abrir_electrov */

void btn_volver_ele_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 10);
	prefix_runCycle(&statechart);
}

void btn_prox_ele_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 11);
	prefix_runCycle(&statechart);
}

/*Pantalla Densidad */

void btn_1_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 12);
	prefix_runCycle(&statechart);
}

void btn_2_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 13);
	prefix_runCycle(&statechart);
}

void btn_3_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 14);
	prefix_runCycle(&statechart);
}

void btn_4_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 15);
	prefix_runCycle(&statechart);
}

void btn_5_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 16);
	prefix_runCycle(&statechart);
}

void btn_6_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 17);
	prefix_runCycle(&statechart);
}

void btn_7_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 18);
	prefix_runCycle(&statechart);
}

void btn_8_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 19);
	prefix_runCycle(&statechart);
}

void btn_9_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 20);
	prefix_runCycle(&statechart);
}

void btn_0_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 21);
	prefix_runCycle(&statechart);
}

void btn_punt_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 22);
	prefix_runCycle(&statechart);
}

void btn_enter_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 23);
	prefix_runCycle(&statechart);
}

void btn_del_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 24);
	prefix_runCycle(&statechart);
}


/*Pantalla Correccion */

void btn_ctr_corr_CallBack(void *ptr){
	prefixIface_raise_evTECXOprimido(&statechart, 25);
	prefix_runCycle(&statechart);
}

void prefixIface_opLED(Prefix* handle, sc_integer LEDNumber, sc_boolean State)
{
	gpioWrite( (LEDR + LEDNumber), State);
}
void prefixIface_opGPIO(Prefix* handle, sc_integer GPIONumber, sc_boolean State)
{
	gpioWrite( GPIONumber, State);
}
extern void prefixIface_selec_Pantalla(const Prefix* handle, const sc_integer OpPantalla)
{
	switch(OpPantalla)
	{
		case 1:
			NexPage_show(&Control);
			prefixIface_raise_evTECXNoOprimido(&statechart);
			prefix_runCycle(&statechart);
			break;
		case 2:
			NexPage_show(&Eleccion);
			prefixIface_raise_evTECXNoOprimido(&statechart);
			prefix_runCycle(&statechart);
			break;
		case 3:
			NexPage_show(&Embotellado);
			prefixIface_raise_evTECXNoOprimido(&statechart);
			prefix_runCycle(&statechart);
			break;
		case 4:
			NexPage_show(&Calentar);
			prefixIface_raise_evTECXNoOprimido(&statechart);
			prefix_runCycle(&statechart);
			break;
		case 5:
			NexPage_show(&Abrir_electrov);
			prefixIface_raise_evTECXNoOprimido(&statechart);
			prefix_runCycle(&statechart);
			break;
		case 6:
			NexPage_show(&Densidad);
			prefixIface_raise_evTECXNoOprimido(&statechart);
			prefix_runCycle(&statechart);
			break;
		case 7:
			NexPage_show(&Correccion);
			prefixIface_raise_evTECXNoOprimido(&statechart);
			prefix_runCycle(&statechart);
			break;
	}

}
void prefixIface_pantalla_Control(Prefix* handle, sc_integer nada)
{
	/*Variables necesarias*/
	int temp_1,temp_2,temp_3;
	float h_t=17.55,r2=17.2059,dist,Vol_1;
	char vol_1_txt[5],vol_2_txt[5],vol_3_txt[5],d_txt[5],str[5];

		nexLoop(nex_listen_list);

		temp_1 = owReadTemperature(2,8);

		temp_2 = owReadTemperature(3,7);
		temp_2 = temp_2 >> 4;
		//temp_1= temp_1 >> 4;
		dist = ultrasonicSensorGetDistance(ULTRASONIC_SENSOR_0, CM);
		sprintf(d_txt,"%f",dist);
		sprintf(str, "%d.%04d\r\n", temp_1 >> 4, (temp_1 & 0xF) * 625);
		debugPrintString(str);
		Vol_1 = (h_t-dist)*r2*3.1416;
		sprintf(vol_1_txt,"%f",Vol_1);
		NexNumber_setValue(&Temp_01_ctr,temp_1);
		NexNumber_setValue(&Temp_02_ctr,temp_2);
		NexText_setText(&Vol_01_ctr,vol_1_txt);
		NexText_setText(&Vol_02_ctr,str);

}

void prefixIface_pantalla_Calentar(Prefix* handle, sc_integer nada)
{
	/*Variables necesarias*/
	int temp_1,temp_2,temp_3;
	float h_t=17.55,r2=17.2059,dist,Vol_1;
	char vol_1_txt[5],vol_2_txt[5],vol_3_txt[5],d_txt[5];

		nexLoop(nex_listen_list);
		//gpioWrite(GPIO3,TRUE);
		temp_1 = owReadTemperature(2,8);
		//gpioWrite(GPIO3,FALSE);
		temp_1= temp_1 >> 4;
		dist = ultrasonicSensorGetDistance(ULTRASONIC_SENSOR_0, CM);
		sprintf(d_txt,"%f",dist);

		Vol_1 = (h_t-dist)*r2*3.1416;
		sprintf(vol_1_txt,"%f",Vol_1);
		NexNumber_setValue(&Temp_01_cal,temp_1);
		NexText_setText(&Vol_01_cal,vol_1_txt);
}

void prefixIface_pantalla_Abrir(Prefix* handle, sc_integer nada)
{
	/*Variables necesarias*/
	int temp_1,temp_2,temp_3;
	float h_t=17.55,r2=17.2059,dist,Vol_1;
	char vol_1_txt[5],vol_2_txt[5],vol_3_txt[5],d_txt[5];
	/*Activo electrovalvula, se activa con un 0*/
	gpioWrite(GPIO5, false);
	gpioWrite(GPIO6, false);
		nexLoop(nex_listen_list);
		temp_1 = owReadTemperature(2,8);
		temp_1= temp_1 >> 4;
		dist = ultrasonicSensorGetDistance(ULTRASONIC_SENSOR_0, CM);
		sprintf(d_txt,"%f",dist);

		Vol_1 = (h_t-dist)*r2*3.1416;
		sprintf(vol_1_txt,"%f",Vol_1);
		NexNumber_setValue(&Temp_01_abr,temp_1);
		NexText_setText(&Vol_01_abr,vol_1_txt);
}
void prefixIface_pantalla_Correccion(Prefix* handle, sc_integer nada)
{
	/*Variables necesarias*/
	volatile int temp_1,temp_2,temp_3;
	float h_t=17.55,r2=17.2059,dist,Vol_1;
	char vol_1_txt[5],vol_2_txt[5],vol_3_txt[5],d_txt[5];

		nexLoop(nex_listen_list);
		temp_1 = owReadTemperature(2,8);
		temp_1= temp_1 >> 4;
		dist = ultrasonicSensorGetDistance(ULTRASONIC_SENSOR_0, CM);
		sprintf(d_txt,"%f",dist);

		Vol_1 = (h_t-dist)*r2*3.1416;
		sprintf(vol_1_txt,"%f",Vol_1);
		NexNumber_setValue(&Temp_03_corr,temp_1);
		NexText_setText(&Vol_03_corr,vol_1_txt);
}

void prefixIface_pantalla_Embotellado(Prefix* handle, sc_integer cant_330, sc_integer cant_750, sc_integer op)
{
	switch(op)
	{
		case 0:
			NexNumber_setValue(&num_330,cant_330);
			/*Activo electrovalvula, se activa con un 0*/
			gpioWrite(GPIO5, false);
			delay(1000);
			/*desactivo electrovalvula, se desactiva con un 1*/
			gpioWrite(GPIO5, true);
			break;

		case 1:
			NexNumber_setValue(&num_750,cant_750);
			/*Activo electrovalvula, se activa con un 0*/
			gpioWrite(GPIO5, false);
			delay(1000);
			/*desactivo electrovalvula, se desactiva con un 1*/
			gpioWrite(GPIO5, true);
			break;
	}
	prefixIface_raise_evTECXNoOprimido(&statechart);
	prefix_runCycle(&statechart);
}
void prefixIface_pantalla_Densidad(Prefix* handle, sc_integer num,sc_boolean coma)
{
	char den[5];
	if(coma==false)
		densidad =densidad*10+num;
	else
		densidad_dec = densidad_dec*10+num;

	sprintf(den,"%d.%d",densidad,densidad_dec);
	NexText_setText(&densidad_txt,den);
	prefixIface_raise_evTECXNoOprimido(&statechart);
	prefix_runCycle(&statechart);
}
