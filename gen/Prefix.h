
#ifndef PREFIX_H_
#define PREFIX_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'prefix'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Prefix_TECX_NO_OPRIMIDO,
	Prefix_TECX_OPRIMIDO,
	Prefix_IDLE_ESPERA,
	Prefix_Bienvenida_Bienvenida,
	Prefix_Bienvenida_Elecci_n,
	Prefix_Bienvenida_Control,
	Prefix_Bienvenida_Embotellado,
	Prefix_Bienvenida_Calentar,
	Prefix_Bienvenida_Abrir,
	Prefix_Bienvenida_Densidad,
	Prefix_Bienvenida_Correccion,
	Prefix_last_state
} PrefixStates;

/*! Type definition of the data structure for the PrefixIface interface scope. */
typedef struct
{
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evPantalla_Control_raised;
} PrefixIface;

/* Declaration of constants for scope PrefixIface. */
extern const sc_integer PREFIX_PREFIXIFACE_PANT_BIENVENIDA;
extern const sc_integer PREFIX_PREFIXIFACE_PANT_CONTROL;
extern const sc_integer PREFIX_PREFIXIFACE_PANT_ELECCION;
extern const sc_integer PREFIX_PREFIXIFACE_PANT_EMBOTELLADO;
extern const sc_integer PREFIX_PREFIXIFACE_PANT_CALENTAR;
extern const sc_integer PREFIX_PREFIXIFACE_PANT_ABRIR;
extern const sc_integer PREFIX_PREFIXIFACE_PANT_DENSIDAD;
extern const sc_integer PREFIX_PREFIXIFACE_PANT_CORRECCION;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_CTR;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_EMBOTELLAR;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_PRODUCIR;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_CONTROL;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_EMB;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_330;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_750;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_CAL;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_PROX_CAL;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_ELE;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_PROX_ELE;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_1;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_2;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_3;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_4;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_5;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_6;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_7;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_8;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_9;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_0;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_PUNT;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_ENTER;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_DEL;
extern const sc_integer PREFIX_PREFIXIFACE_BTN_CTR_CORR;
extern const sc_integer PREFIX_PREFIXIFACE_LEDR;
extern const sc_integer PREFIX_PREFIXIFACE_LEDG;
extern const sc_integer PREFIX_PREFIXIFACE_LEDB;
extern const sc_integer PREFIX_PREFIXIFACE_LED1;
extern const sc_integer PREFIX_PREFIXIFACE_LED2;
extern const sc_integer PREFIX_PREFIXIFACE_LED3;
extern const sc_integer PREFIX_PREFIXIFACE_GPIO5;
extern const sc_integer PREFIX_PREFIXIFACE_GPIO6;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_ON;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_OFF;
extern const sc_integer PREFIX_PREFIXIFACE_OP_330;
extern const sc_integer PREFIX_PREFIXIFACE_OP_750;
extern const sc_integer PREFIX_PREFIXIFACE_TEC1;
extern const sc_integer PREFIX_PREFIXIFACE_TEC2;
extern const sc_integer PREFIX_PREFIXIFACE_TEC3;
extern const sc_integer PREFIX_PREFIXIFACE_TEC4;

/*! Type definition of the data structure for the PrefixInternal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siControl_raised;
	sc_boolean siEleccion_raised;
	sc_boolean siEmbotellado_raised;
	sc_boolean siCalentar_raised;
	sc_boolean siAbrir_raised;
	sc_boolean siDensidad_raised;
	sc_boolean siCorreccion_raised;
	sc_boolean TecNoOprimido_raised;
	sc_boolean siVolver_C_raised;
	sc_boolean siVolver_Emb_raised;
	sc_boolean siVolver_Cal_raised;
	sc_boolean siVolver_Abrir_raised;
	sc_integer viTecla;
	sc_integer viOp_Volver;
	sc_integer cant_330;
	sc_integer cant_750;
	sc_integer densidad_entero;
	sc_integer densidad_decimal;
	sc_boolean Op_coma;
	sc_integer eleccion_btn_med;
} PrefixInternal;

/*! Type definition of the data structure for the PrefixTimeEvents interface scope. */
typedef struct
{
	sc_boolean prefix_Bienvenida_Bienvenida_tev0_raised;
	sc_boolean prefix_Bienvenida_Control_tev0_raised;
	sc_boolean prefix_Bienvenida_Calentar_tev0_raised;
	sc_boolean prefix_Bienvenida_Abrir_tev0_raised;
	sc_boolean prefix_Bienvenida_Correccion_tev0_raised;
} PrefixTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PREFIX_MAX_ORTHOGONAL_STATES 3

/*! 
 * Type definition of the data structure for the Prefix state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	PrefixStates stateConfVector[PREFIX_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	PrefixIface iface;
	PrefixInternal internal;
	PrefixTimeEvents timeEvents;
} Prefix;

/*! Initializes the Prefix state machine data structures. Must be called before first usage.*/
extern void prefix_init(Prefix* handle);

/*! Activates the state machine */
extern void prefix_enter(Prefix* handle);

/*! Deactivates the state machine */
extern void prefix_exit(Prefix* handle);

/*! Performs a 'run to completion' step. */
extern void prefix_runCycle(Prefix* handle);

/*! Raises a time event. */
extern void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXNoOprimido(Prefix* handle);

/*! Raises the in event 'evPantalla_Control' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evPantalla_Control(Prefix* handle);

/*! Gets the value of the variable 'Pant_Bienvenida' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Bienvenida(const Prefix* handle);
/*! Gets the value of the variable 'Pant_Control' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Control(const Prefix* handle);
/*! Gets the value of the variable 'Pant_Eleccion' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Eleccion(const Prefix* handle);
/*! Gets the value of the variable 'Pant_Embotellado' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Embotellado(const Prefix* handle);
/*! Gets the value of the variable 'Pant_Calentar' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Calentar(const Prefix* handle);
/*! Gets the value of the variable 'Pant_Abrir' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Abrir(const Prefix* handle);
/*! Gets the value of the variable 'Pant_Densidad' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Densidad(const Prefix* handle);
/*! Gets the value of the variable 'Pant_Correccion' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_pant_Correccion(const Prefix* handle);
/*! Gets the value of the variable 'btn_volver_ctr' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_volver_ctr(const Prefix* handle);
/*! Gets the value of the variable 'btn_Embotellar' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_Embotellar(const Prefix* handle);
/*! Gets the value of the variable 'btn_Producir' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_Producir(const Prefix* handle);
/*! Gets the value of the variable 'btn_Control' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_Control(const Prefix* handle);
/*! Gets the value of the variable 'btn_volver_emb' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_volver_emb(const Prefix* handle);
/*! Gets the value of the variable 'btn_330' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_330(const Prefix* handle);
/*! Gets the value of the variable 'btn_750' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_750(const Prefix* handle);
/*! Gets the value of the variable 'btn_volver_cal' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_volver_cal(const Prefix* handle);
/*! Gets the value of the variable 'btn_prox_cal' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_prox_cal(const Prefix* handle);
/*! Gets the value of the variable 'btn_volver_ele' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_volver_ele(const Prefix* handle);
/*! Gets the value of the variable 'btn_prox_ele' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_prox_ele(const Prefix* handle);
/*! Gets the value of the variable 'btn_1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_1(const Prefix* handle);
/*! Gets the value of the variable 'btn_2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_2(const Prefix* handle);
/*! Gets the value of the variable 'btn_3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_3(const Prefix* handle);
/*! Gets the value of the variable 'btn_4' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_4(const Prefix* handle);
/*! Gets the value of the variable 'btn_5' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_5(const Prefix* handle);
/*! Gets the value of the variable 'btn_6' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_6(const Prefix* handle);
/*! Gets the value of the variable 'btn_7' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_7(const Prefix* handle);
/*! Gets the value of the variable 'btn_8' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_8(const Prefix* handle);
/*! Gets the value of the variable 'btn_9' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_9(const Prefix* handle);
/*! Gets the value of the variable 'btn_0' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_0(const Prefix* handle);
/*! Gets the value of the variable 'btn_punt' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_punt(const Prefix* handle);
/*! Gets the value of the variable 'btn_enter' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_enter(const Prefix* handle);
/*! Gets the value of the variable 'btn_del' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_del(const Prefix* handle);
/*! Gets the value of the variable 'btn_ctr_corr' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_btn_ctr_corr(const Prefix* handle);
/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDR(const Prefix* handle);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDG(const Prefix* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDB(const Prefix* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED1(const Prefix* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED2(const Prefix* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED3(const Prefix* handle);
/*! Gets the value of the variable 'GPIO5' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_gPIO5(const Prefix* handle);
/*! Gets the value of the variable 'GPIO6' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_gPIO6(const Prefix* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_ON(const Prefix* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle);
/*! Gets the value of the variable 'Op_330' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_op_330(const Prefix* handle);
/*! Gets the value of the variable 'Op_750' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_op_750(const Prefix* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC1(const Prefix* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC2(const Prefix* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC3(const Prefix* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC4(const Prefix* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean prefix_isActive(const Prefix* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean prefix_isFinal(const Prefix* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state);

#ifdef __cplusplus
}
#endif 

#endif /* PREFIX_H_ */
