
#ifndef PREFIXREQUIRED_H_
#define PREFIXREQUIRED_H_

#include "sc_types.h"
#include "Prefix.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- prefix_setTimer and
	- prefix_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- prefixIface_opLED
	- prefixIface_opGPIO
	- prefixIface_selec_Pantalla
	- prefixIface_pantalla_Control
	- prefixIface_pantalla_Calentar
	- prefixIface_pantalla_Abrir
	- prefixIface_pantalla_Correccion
	- prefixIface_pantalla_Densidad
	- prefixIface_pantalla_Embotellado
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void prefixIface_opLED(const Prefix* handle, const sc_integer LEDNumber, const sc_boolean State);
extern void prefixIface_opGPIO(const Prefix* handle, const sc_integer GPIONumber, const sc_boolean State);
extern void prefixIface_selec_Pantalla(const Prefix* handle, const sc_integer OpPantalla);
extern void prefixIface_pantalla_Control(const Prefix* handle, const sc_integer OpPantalla);
extern void prefixIface_pantalla_Calentar(const Prefix* handle, const sc_integer OpPantalla);
extern void prefixIface_pantalla_Abrir(const Prefix* handle, const sc_integer OpPantalla);
extern void prefixIface_pantalla_Correccion(const Prefix* handle, const sc_integer OpPantalla);
extern void prefixIface_pantalla_Densidad(const Prefix* handle, const sc_integer Den, const sc_boolean Opcoma);
extern void prefixIface_pantalla_Embotellado(const Prefix* handle, const sc_integer cant_330, const sc_integer cant_750, const sc_integer eleccion_btn_med);



/*!
 * This is a timed state machine that requires timer services
 */ 

/*! This function has to set up timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milli seconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset 
*/
extern void prefix_setTimer(Prefix* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! This function has to unset timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event taht is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
extern void prefix_unsetTimer(Prefix* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* PREFIXREQUIRED_H_ */
