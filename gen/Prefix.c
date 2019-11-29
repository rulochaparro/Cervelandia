
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr3_tr3(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr4_tr4(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr5_tr5(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr6_tr6(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr7_tr7(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr8_tr8(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr9_tr9(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr10_tr10(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr11_tr11(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr12_tr12(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr13_tr13(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr14_tr14(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr15_tr15(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr16_tr16(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr17_tr17(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr18_tr18(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr19_tr19(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr20_tr20(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr21_tr21(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr22_tr22(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr23_tr23(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr24_tr24(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Bienvenida_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Elecci_n_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Elecci_n_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Elecci_n_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Control_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Control_lr1_lr1(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Embotellado_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Calentar_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Calentar_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Calentar_lr1_lr1(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Abrir_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Abrir_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Abrir_lr1_lr1(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Densidad_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Correccion_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Bienvenida_Correccion_lr1_lr1(const Prefix* handle);
static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr0(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr1(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr2(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr3(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr4(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr5(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr6(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr7(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr8(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr9(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr10(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr11(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr12(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr13(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr14(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr15(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr16(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr17(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr18(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr19(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr20(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr21(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr22(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr23(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr24(Prefix* handle);
static void prefix_effect_Bienvenida_Bienvenida_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Elecci_n_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Elecci_n_tr1(Prefix* handle);
static void prefix_effect_Bienvenida_Elecci_n_tr2(Prefix* handle);
static void prefix_effect_Bienvenida_Control_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Control_lr1_lr1(Prefix* handle);
static void prefix_effect_Bienvenida_Embotellado_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Calentar_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Calentar_tr1(Prefix* handle);
static void prefix_effect_Bienvenida_Calentar_lr1_lr1(Prefix* handle);
static void prefix_effect_Bienvenida_Abrir_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Abrir_tr1(Prefix* handle);
static void prefix_effect_Bienvenida_Abrir_lr1_lr1(Prefix* handle);
static void prefix_effect_Bienvenida_Densidad_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Correccion_tr0(Prefix* handle);
static void prefix_effect_Bienvenida_Correccion_lr1_lr1(Prefix* handle);
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_enact_Bienvenida_Bienvenida(Prefix* handle);
static void prefix_enact_Bienvenida_Elecci_n(Prefix* handle);
static void prefix_enact_Bienvenida_Control(Prefix* handle);
static void prefix_enact_Bienvenida_Embotellado(Prefix* handle);
static void prefix_enact_Bienvenida_Calentar(Prefix* handle);
static void prefix_enact_Bienvenida_Abrir(Prefix* handle);
static void prefix_enact_Bienvenida_Densidad(Prefix* handle);
static void prefix_enact_Bienvenida_Correccion(Prefix* handle);
static void prefix_exact_Bienvenida_Bienvenida(Prefix* handle);
static void prefix_exact_Bienvenida_Control(Prefix* handle);
static void prefix_exact_Bienvenida_Embotellado(Prefix* handle);
static void prefix_exact_Bienvenida_Calentar(Prefix* handle);
static void prefix_exact_Bienvenida_Abrir(Prefix* handle);
static void prefix_exact_Bienvenida_Correccion(Prefix* handle);
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_IDLE_ESPERA_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Bienvenida_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Elecci_n_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Control_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Embotellado_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Calentar_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Abrir_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Densidad_default(Prefix* handle);
static void prefix_enseq_Bienvenida_Correccion_default(Prefix* handle);
static void prefix_enseq_TECX_default(Prefix* handle);
static void prefix_enseq_IDLE_default(Prefix* handle);
static void prefix_enseq_Bienvenida_default(Prefix* handle);
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exseq_IDLE_ESPERA(Prefix* handle);
static void prefix_exseq_Bienvenida_Bienvenida(Prefix* handle);
static void prefix_exseq_Bienvenida_Elecci_n(Prefix* handle);
static void prefix_exseq_Bienvenida_Control(Prefix* handle);
static void prefix_exseq_Bienvenida_Embotellado(Prefix* handle);
static void prefix_exseq_Bienvenida_Calentar(Prefix* handle);
static void prefix_exseq_Bienvenida_Abrir(Prefix* handle);
static void prefix_exseq_Bienvenida_Densidad(Prefix* handle);
static void prefix_exseq_Bienvenida_Correccion(Prefix* handle);
static void prefix_exseq_TECX(Prefix* handle);
static void prefix_exseq_IDLE(Prefix* handle);
static void prefix_exseq_Bienvenida(Prefix* handle);
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_OPRIMIDO(Prefix* handle);
static void prefix_react_IDLE_ESPERA(Prefix* handle);
static void prefix_react_Bienvenida_Bienvenida(Prefix* handle);
static void prefix_react_Bienvenida_Elecci_n(Prefix* handle);
static void prefix_react_Bienvenida_Control(Prefix* handle);
static void prefix_react_Bienvenida_Embotellado(Prefix* handle);
static void prefix_react_Bienvenida_Calentar(Prefix* handle);
static void prefix_react_Bienvenida_Abrir(Prefix* handle);
static void prefix_react_Bienvenida_Densidad(Prefix* handle);
static void prefix_react_Bienvenida_Correccion(Prefix* handle);
static void prefix_react_TECX__entry_Default(Prefix* handle);
static void prefix_react_IDLE__entry_Default(Prefix* handle);
static void prefix_react_Bienvenida__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_PANT_BIENVENIDA = 0;
const sc_integer PREFIX_PREFIXIFACE_PANT_CONTROL = 1;
const sc_integer PREFIX_PREFIXIFACE_PANT_ELECCION = 2;
const sc_integer PREFIX_PREFIXIFACE_PANT_EMBOTELLADO = 3;
const sc_integer PREFIX_PREFIXIFACE_PANT_CALENTAR = 4;
const sc_integer PREFIX_PREFIXIFACE_PANT_ABRIR = 5;
const sc_integer PREFIX_PREFIXIFACE_PANT_DENSIDAD = 6;
const sc_integer PREFIX_PREFIXIFACE_PANT_CORRECCION = 7;
const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_CTR = 0;
const sc_integer PREFIX_PREFIXIFACE_BTN_EMBOTELLAR = 1;
const sc_integer PREFIX_PREFIXIFACE_BTN_PRODUCIR = 2;
const sc_integer PREFIX_PREFIXIFACE_BTN_CONTROL = 3;
const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_EMB = 5;
const sc_integer PREFIX_PREFIXIFACE_BTN_330 = 6;
const sc_integer PREFIX_PREFIXIFACE_BTN_750 = 7;
const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_CAL = 8;
const sc_integer PREFIX_PREFIXIFACE_BTN_PROX_CAL = 9;
const sc_integer PREFIX_PREFIXIFACE_BTN_VOLVER_ELE = 10;
const sc_integer PREFIX_PREFIXIFACE_BTN_PROX_ELE = 11;
const sc_integer PREFIX_PREFIXIFACE_BTN_1 = 12;
const sc_integer PREFIX_PREFIXIFACE_BTN_2 = 13;
const sc_integer PREFIX_PREFIXIFACE_BTN_3 = 14;
const sc_integer PREFIX_PREFIXIFACE_BTN_4 = 15;
const sc_integer PREFIX_PREFIXIFACE_BTN_5 = 16;
const sc_integer PREFIX_PREFIXIFACE_BTN_6 = 17;
const sc_integer PREFIX_PREFIXIFACE_BTN_7 = 18;
const sc_integer PREFIX_PREFIXIFACE_BTN_8 = 19;
const sc_integer PREFIX_PREFIXIFACE_BTN_9 = 20;
const sc_integer PREFIX_PREFIXIFACE_BTN_0 = 21;
const sc_integer PREFIX_PREFIXIFACE_BTN_PUNT = 22;
const sc_integer PREFIX_PREFIXIFACE_BTN_ENTER = 23;
const sc_integer PREFIX_PREFIXIFACE_BTN_DEL = 24;
const sc_integer PREFIX_PREFIXIFACE_BTN_CTR_CORR = 25;
const sc_integer PREFIX_PREFIXIFACE_LEDR = 0;
const sc_integer PREFIX_PREFIXIFACE_LEDG = 1;
const sc_integer PREFIX_PREFIXIFACE_LEDB = 2;
const sc_integer PREFIX_PREFIXIFACE_LED1 = 3;
const sc_integer PREFIX_PREFIXIFACE_LED2 = 4;
const sc_integer PREFIX_PREFIXIFACE_LED3 = 5;
const sc_integer PREFIX_PREFIXIFACE_GPIO5 = 13;
const sc_integer PREFIX_PREFIXIFACE_GPIO6 = 29;
const sc_boolean PREFIX_PREFIXIFACE_LED_ON = bool_true;
const sc_boolean PREFIX_PREFIXIFACE_LED_OFF = bool_false;
const sc_integer PREFIX_PREFIXIFACE_OP_330 = 0;
const sc_integer PREFIX_PREFIXIFACE_OP_750 = 1;
const sc_integer PREFIX_PREFIXIFACE_TEC1 = 1 << 0;
const sc_integer PREFIX_PREFIXIFACE_TEC2 = 1 << 1;
const sc_integer PREFIX_PREFIXIFACE_TEC3 = 1 << 2;
const sc_integer PREFIX_PREFIXIFACE_TEC4 = 1 << 3;

void prefix_init(Prefix* handle)
{
	sc_integer i;

	for (i = 0; i < PREFIX_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Prefix_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	prefix_clearInEvents(handle);
	prefix_clearOutEvents(handle);

	/* Default init sequence for statechart prefix */
	handle->internal.viTecla = 0;
	handle->internal.viOp_Volver = 0;
	handle->internal.cant_330 = 0;
	handle->internal.cant_750 = 0;
	handle->internal.densidad_entero = 0;
	handle->internal.densidad_decimal = 0;
	handle->internal.Op_coma = bool_false;
	handle->internal.eleccion_btn_med = 2;

}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_TECX_default(handle);
	prefix_enseq_IDLE_default(handle);
	prefix_enseq_Bienvenida_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_TECX(handle);
	prefix_exseq_IDLE(handle);
	prefix_exseq_Bienvenida(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state || handle->stateConfVector[1] != Prefix_last_state || handle->stateConfVector[2] != Prefix_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean prefix_isFinal(const Prefix* handle)
{
   return bool_false;
}

static void prefix_clearInEvents(Prefix* handle)
{
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evPantalla_Control_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siControl_raised = bool_false;
	handle->internal.siEleccion_raised = bool_false;
	handle->internal.siEmbotellado_raised = bool_false;
	handle->internal.siCalentar_raised = bool_false;
	handle->internal.siAbrir_raised = bool_false;
	handle->internal.siDensidad_raised = bool_false;
	handle->internal.siCorreccion_raised = bool_false;
	handle->internal.TecNoOprimido_raised = bool_false;
	handle->internal.siVolver_C_raised = bool_false;
	handle->internal.siVolver_Emb_raised = bool_false;
	handle->internal.siVolver_Cal_raised = bool_false;
	handle->internal.siVolver_Abrir_raised = bool_false;
	handle->timeEvents.prefix_Bienvenida_Bienvenida_tev0_raised = bool_false;
	handle->timeEvents.prefix_Bienvenida_Control_tev0_raised = bool_false;
	handle->timeEvents.prefix_Bienvenida_Calentar_tev0_raised = bool_false;
	handle->timeEvents.prefix_Bienvenida_Abrir_tev0_raised = bool_false;
	handle->timeEvents.prefix_Bienvenida_Correccion_tev0_raised = bool_false;
}

static void prefix_clearOutEvents(Prefix* handle)
{
}

void prefix_runCycle(Prefix* handle)
{
	
	prefix_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PREFIX_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_react_TECX_OPRIMIDO(handle);
			break;
		}
		case Prefix_IDLE_ESPERA :
		{
			prefix_react_IDLE_ESPERA(handle);
			break;
		}
		case Prefix_Bienvenida_Bienvenida :
		{
			prefix_react_Bienvenida_Bienvenida(handle);
			break;
		}
		case Prefix_Bienvenida_Elecci_n :
		{
			prefix_react_Bienvenida_Elecci_n(handle);
			break;
		}
		case Prefix_Bienvenida_Control :
		{
			prefix_react_Bienvenida_Control(handle);
			break;
		}
		case Prefix_Bienvenida_Embotellado :
		{
			prefix_react_Bienvenida_Embotellado(handle);
			break;
		}
		case Prefix_Bienvenida_Calentar :
		{
			prefix_react_Bienvenida_Calentar(handle);
			break;
		}
		case Prefix_Bienvenida_Abrir :
		{
			prefix_react_Bienvenida_Abrir(handle);
			break;
		}
		case Prefix_Bienvenida_Densidad :
		{
			prefix_react_Bienvenida_Densidad(handle);
			break;
		}
		case Prefix_Bienvenida_Correccion :
		{
			prefix_react_Bienvenida_Correccion(handle);
			break;
		}
		default:
			break;
		}
	}
	
	prefix_clearInEvents(handle);
}

void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(PrefixTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Prefix_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_NO_OPRIMIDO
			);
			break;
		case Prefix_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_OPRIMIDO
			);
			break;
		case Prefix_IDLE_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_IDLE_ESPERA
			);
			break;
		case Prefix_Bienvenida_Bienvenida :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Bienvenida
			);
			break;
		case Prefix_Bienvenida_Elecci_n :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Elecci_n
			);
			break;
		case Prefix_Bienvenida_Control :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Control
			);
			break;
		case Prefix_Bienvenida_Embotellado :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Embotellado
			);
			break;
		case Prefix_Bienvenida_Calentar :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Calentar
			);
			break;
		case Prefix_Bienvenida_Abrir :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Abrir
			);
			break;
		case Prefix_Bienvenida_Densidad :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Densidad
			);
			break;
		case Prefix_Bienvenida_Correccion :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_Bienvenida_Correccion
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}
void prefixIface_raise_evTECXNoOprimido(Prefix* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void prefixIface_raise_evPantalla_Control(Prefix* handle)
{
	handle->iface.evPantalla_Control_raised = bool_true;
}


const sc_integer prefixIface_get_pant_Bienvenida(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_BIENVENIDA;
}
const sc_integer prefixIface_get_pant_Control(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_CONTROL;
}
const sc_integer prefixIface_get_pant_Eleccion(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_ELECCION;
}
const sc_integer prefixIface_get_pant_Embotellado(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_EMBOTELLADO;
}
const sc_integer prefixIface_get_pant_Calentar(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_CALENTAR;
}
const sc_integer prefixIface_get_pant_Abrir(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_ABRIR;
}
const sc_integer prefixIface_get_pant_Densidad(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_DENSIDAD;
}
const sc_integer prefixIface_get_pant_Correccion(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_PANT_CORRECCION;
}
const sc_integer prefixIface_get_btn_volver_ctr(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_VOLVER_CTR;
}
const sc_integer prefixIface_get_btn_Embotellar(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_EMBOTELLAR;
}
const sc_integer prefixIface_get_btn_Producir(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_PRODUCIR;
}
const sc_integer prefixIface_get_btn_Control(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_CONTROL;
}
const sc_integer prefixIface_get_btn_volver_emb(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_VOLVER_EMB;
}
const sc_integer prefixIface_get_btn_330(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_330;
}
const sc_integer prefixIface_get_btn_750(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_750;
}
const sc_integer prefixIface_get_btn_volver_cal(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_VOLVER_CAL;
}
const sc_integer prefixIface_get_btn_prox_cal(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_PROX_CAL;
}
const sc_integer prefixIface_get_btn_volver_ele(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_VOLVER_ELE;
}
const sc_integer prefixIface_get_btn_prox_ele(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_PROX_ELE;
}
const sc_integer prefixIface_get_btn_1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_1;
}
const sc_integer prefixIface_get_btn_2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_2;
}
const sc_integer prefixIface_get_btn_3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_3;
}
const sc_integer prefixIface_get_btn_4(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_4;
}
const sc_integer prefixIface_get_btn_5(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_5;
}
const sc_integer prefixIface_get_btn_6(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_6;
}
const sc_integer prefixIface_get_btn_7(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_7;
}
const sc_integer prefixIface_get_btn_8(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_8;
}
const sc_integer prefixIface_get_btn_9(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_9;
}
const sc_integer prefixIface_get_btn_0(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_0;
}
const sc_integer prefixIface_get_btn_punt(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_PUNT;
}
const sc_integer prefixIface_get_btn_enter(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_ENTER;
}
const sc_integer prefixIface_get_btn_del(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_DEL;
}
const sc_integer prefixIface_get_btn_ctr_corr(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_BTN_CTR_CORR;
}
const sc_integer prefixIface_get_lEDR(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDR;
}
const sc_integer prefixIface_get_lEDG(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDG;
}
const sc_integer prefixIface_get_lEDB(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDB;
}
const sc_integer prefixIface_get_lED1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED1;
}
const sc_integer prefixIface_get_lED2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED2;
}
const sc_integer prefixIface_get_lED3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED3;
}
const sc_integer prefixIface_get_gPIO5(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_GPIO5;
}
const sc_integer prefixIface_get_gPIO6(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_GPIO6;
}
const sc_boolean prefixIface_get_lED_ON(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_ON;
}
const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_OFF;
}
const sc_integer prefixIface_get_op_330(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_OP_330;
}
const sc_integer prefixIface_get_op_750(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_OP_750;
}
const sc_integer prefixIface_get_tEC1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC1;
}
const sc_integer prefixIface_get_tEC2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC2;
}
const sc_integer prefixIface_get_tEC3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC3;
}
const sc_integer prefixIface_get_tEC4(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC4;
}

/* implementations of all internal functions */

static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return (handle->iface.evTECXNoOprimido_raised || handle->internal.TecNoOprimido_raised) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_EMBOTELLAR)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_PRODUCIR)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr2_tr2(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_CONTROL)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr3_tr3(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_VOLVER_CTR && handle->internal.viOp_Volver == PREFIX_PREFIXIFACE_PANT_ELECCION)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr4_tr4(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_PROX_CAL)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr5_tr5(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_PROX_ELE)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr6_tr6(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_CTR_CORR)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr7_tr7(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_ENTER)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr8_tr8(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_VOLVER_CAL && handle->internal.viOp_Volver == PREFIX_PREFIXIFACE_PANT_ELECCION)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr9_tr9(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_VOLVER_EMB && handle->internal.viOp_Volver == PREFIX_PREFIXIFACE_PANT_ELECCION)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr10_tr10(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_VOLVER_ELE && handle->internal.viOp_Volver == PREFIX_PREFIXIFACE_PANT_CALENTAR)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr11_tr11(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_330)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr12_tr12(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_750)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr13_tr13(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr14_tr14(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_2)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr15_tr15(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_3)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr16_tr16(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_4)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr17_tr17(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_5)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr18_tr18(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_6)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr19_tr19(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_7)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr20_tr20(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_8)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr21_tr21(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_9)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr22_tr22(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_0)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr23_tr23(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_DEL)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr24_tr24(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_BTN_PUNT)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_Bienvenida_Bienvenida_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_Bienvenida_Bienvenida_tev0_raised;
}

static sc_boolean prefix_check_Bienvenida_Elecci_n_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siControl_raised;
}

static sc_boolean prefix_check_Bienvenida_Elecci_n_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siEmbotellado_raised;
}

static sc_boolean prefix_check_Bienvenida_Elecci_n_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siCalentar_raised;
}

static sc_boolean prefix_check_Bienvenida_Control_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siVolver_C_raised;
}

static sc_boolean prefix_check_Bienvenida_Control_lr1_lr1(const Prefix* handle)
{
	return handle->timeEvents.prefix_Bienvenida_Control_tev0_raised;
}

static sc_boolean prefix_check_Bienvenida_Embotellado_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siVolver_Emb_raised;
}

static sc_boolean prefix_check_Bienvenida_Calentar_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siVolver_Cal_raised;
}

static sc_boolean prefix_check_Bienvenida_Calentar_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siAbrir_raised;
}

static sc_boolean prefix_check_Bienvenida_Calentar_lr1_lr1(const Prefix* handle)
{
	return handle->timeEvents.prefix_Bienvenida_Calentar_tev0_raised;
}

static sc_boolean prefix_check_Bienvenida_Abrir_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siVolver_Abrir_raised;
}

static sc_boolean prefix_check_Bienvenida_Abrir_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDensidad_raised;
}

static sc_boolean prefix_check_Bienvenida_Abrir_lr1_lr1(const Prefix* handle)
{
	return handle->timeEvents.prefix_Bienvenida_Abrir_tev0_raised;
}

static sc_boolean prefix_check_Bienvenida_Densidad_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siCorreccion_raised;
}

static sc_boolean prefix_check_Bienvenida_Correccion_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siEleccion_raised;
}

static sc_boolean prefix_check_Bienvenida_Correccion_lr1_lr1(const Prefix* handle)
{
	return handle->timeEvents.prefix_Bienvenida_Correccion_tev0_raised;
}

static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_NO_OPRIMIDO(handle);
	prefix_enseq_TECX_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_OPRIMIDO(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr0(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siEmbotellado_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr1(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siCalentar_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr2(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siControl_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr3(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siVolver_C_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr4(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siAbrir_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr5(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siDensidad_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr6(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siEleccion_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr7(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siCorreccion_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr8(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siVolver_Cal_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr9(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siVolver_Emb_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr10(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siVolver_Abrir_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr11(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.cant_330 += 1;
	handle->internal.eleccion_btn_med = PREFIX_PREFIXIFACE_OP_330;
	prefixIface_pantalla_Embotellado(handle, handle->internal.cant_330, handle->internal.cant_750, handle->internal.eleccion_btn_med);
	handle->internal.eleccion_btn_med = 2;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr12(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.cant_750 += 1;
	handle->internal.eleccion_btn_med = PREFIX_PREFIXIFACE_OP_750;
	prefixIface_pantalla_Embotellado(handle, handle->internal.cant_330, handle->internal.cant_750, handle->internal.eleccion_btn_med);
	handle->internal.eleccion_btn_med = 2;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr13(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 1, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr14(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 2, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr15(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 3, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr16(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 4, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr17(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 5, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr18(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 6, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr19(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 7, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr20(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 8, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr21(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 9, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr22(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefixIface_pantalla_Densidad(handle, 0, handle->internal.Op_coma);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr23(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr24(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.Op_coma = bool_true;
	handle->internal.TecNoOprimido_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_Bienvenida_Bienvenida_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Bienvenida(handle);
	prefix_enseq_Bienvenida_Elecci_n_default(handle);
}

static void prefix_effect_Bienvenida_Elecci_n_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Elecci_n(handle);
	prefix_enseq_Bienvenida_Control_default(handle);
}

static void prefix_effect_Bienvenida_Elecci_n_tr1(Prefix* handle)
{
	prefix_exseq_Bienvenida_Elecci_n(handle);
	prefix_enseq_Bienvenida_Embotellado_default(handle);
}

static void prefix_effect_Bienvenida_Elecci_n_tr2(Prefix* handle)
{
	prefix_exseq_Bienvenida_Elecci_n(handle);
	prefix_enseq_Bienvenida_Calentar_default(handle);
}

static void prefix_effect_Bienvenida_Control_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Control(handle);
	prefix_enseq_Bienvenida_Elecci_n_default(handle);
}

static void prefix_effect_Bienvenida_Control_lr1_lr1(Prefix* handle)
{
	prefixIface_pantalla_Control(handle, PREFIX_PREFIXIFACE_PANT_CONTROL);
}

static void prefix_effect_Bienvenida_Embotellado_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Embotellado(handle);
	prefix_enseq_Bienvenida_Elecci_n_default(handle);
}

static void prefix_effect_Bienvenida_Calentar_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Calentar(handle);
	prefix_enseq_Bienvenida_Elecci_n_default(handle);
}

static void prefix_effect_Bienvenida_Calentar_tr1(Prefix* handle)
{
	prefix_exseq_Bienvenida_Calentar(handle);
	prefix_enseq_Bienvenida_Abrir_default(handle);
}

static void prefix_effect_Bienvenida_Calentar_lr1_lr1(Prefix* handle)
{
	prefixIface_pantalla_Calentar(handle, PREFIX_PREFIXIFACE_PANT_CALENTAR);
}

static void prefix_effect_Bienvenida_Abrir_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Abrir(handle);
	prefix_enseq_Bienvenida_Calentar_default(handle);
}

static void prefix_effect_Bienvenida_Abrir_tr1(Prefix* handle)
{
	prefix_exseq_Bienvenida_Abrir(handle);
	prefix_enseq_Bienvenida_Densidad_default(handle);
}

static void prefix_effect_Bienvenida_Abrir_lr1_lr1(Prefix* handle)
{
	prefixIface_pantalla_Abrir(handle, PREFIX_PREFIXIFACE_PANT_ABRIR);
}

static void prefix_effect_Bienvenida_Densidad_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Densidad(handle);
	prefix_enseq_Bienvenida_Correccion_default(handle);
}

static void prefix_effect_Bienvenida_Correccion_tr0(Prefix* handle)
{
	prefix_exseq_Bienvenida_Correccion(handle);
	prefix_enseq_Bienvenida_Elecci_n_default(handle);
}

static void prefix_effect_Bienvenida_Correccion_lr1_lr1(Prefix* handle)
{
	prefixIface_pantalla_Correccion(handle, PREFIX_PREFIXIFACE_PANT_CORRECCION);
}

/* Entry action for state 'OPRIMIDO'. */
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'Bienvenida'. */
static void prefix_enact_Bienvenida_Bienvenida(Prefix* handle)
{
	/* Entry action for state 'Bienvenida'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Bienvenida_tev0_raised) , 1500, bool_false);
}

/* Entry action for state 'Elección'. */
static void prefix_enact_Bienvenida_Elecci_n(Prefix* handle)
{
	/* Entry action for state 'Elección'. */
	prefixIface_selec_Pantalla(handle, PREFIX_PREFIXIFACE_PANT_ELECCION);
}

/* Entry action for state 'Control'. */
static void prefix_enact_Bienvenida_Control(Prefix* handle)
{
	/* Entry action for state 'Control'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Control_tev0_raised) , 500, bool_true);
	prefixIface_selec_Pantalla(handle, PREFIX_PREFIXIFACE_PANT_CONTROL);
	handle->internal.viOp_Volver = PREFIX_PREFIXIFACE_PANT_ELECCION;
}

/* Entry action for state 'Embotellado'. */
static void prefix_enact_Bienvenida_Embotellado(Prefix* handle)
{
	/* Entry action for state 'Embotellado'. */
	prefixIface_selec_Pantalla(handle, PREFIX_PREFIXIFACE_PANT_EMBOTELLADO);
	handle->internal.viOp_Volver = PREFIX_PREFIXIFACE_PANT_ELECCION;
}

/* Entry action for state 'Calentar'. */
static void prefix_enact_Bienvenida_Calentar(Prefix* handle)
{
	/* Entry action for state 'Calentar'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Calentar_tev0_raised) , 500, bool_true);
	prefixIface_selec_Pantalla(handle, PREFIX_PREFIXIFACE_PANT_CALENTAR);
	handle->internal.viOp_Volver = PREFIX_PREFIXIFACE_PANT_ELECCION;
}

/* Entry action for state 'Abrir'. */
static void prefix_enact_Bienvenida_Abrir(Prefix* handle)
{
	/* Entry action for state 'Abrir'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Abrir_tev0_raised) , 500, bool_true);
	prefixIface_selec_Pantalla(handle, PREFIX_PREFIXIFACE_PANT_ABRIR);
	handle->internal.viOp_Volver = PREFIX_PREFIXIFACE_PANT_CALENTAR;
}

/* Entry action for state 'Densidad'. */
static void prefix_enact_Bienvenida_Densidad(Prefix* handle)
{
	/* Entry action for state 'Densidad'. */
	prefixIface_selec_Pantalla(handle, PREFIX_PREFIXIFACE_PANT_DENSIDAD);
	handle->internal.viOp_Volver = PREFIX_PREFIXIFACE_PANT_ABRIR;
}

/* Entry action for state 'Correccion'. */
static void prefix_enact_Bienvenida_Correccion(Prefix* handle)
{
	/* Entry action for state 'Correccion'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Correccion_tev0_raised) , 500, bool_true);
	prefixIface_selec_Pantalla(handle, PREFIX_PREFIXIFACE_PANT_CORRECCION);
	handle->internal.viOp_Volver = PREFIX_PREFIXIFACE_PANT_DENSIDAD;
}

/* Exit action for state 'Bienvenida'. */
static void prefix_exact_Bienvenida_Bienvenida(Prefix* handle)
{
	/* Exit action for state 'Bienvenida'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Bienvenida_tev0_raised) );		
}

/* Exit action for state 'Control'. */
static void prefix_exact_Bienvenida_Control(Prefix* handle)
{
	/* Exit action for state 'Control'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Control_tev0_raised) );		
}

/* Exit action for state 'Embotellado'. */
static void prefix_exact_Bienvenida_Embotellado(Prefix* handle)
{
	/* Exit action for state 'Embotellado'. */
	handle->internal.cant_330 = 0;
	handle->internal.cant_750 = 0;
}

/* Exit action for state 'Calentar'. */
static void prefix_exact_Bienvenida_Calentar(Prefix* handle)
{
	/* Exit action for state 'Calentar'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Calentar_tev0_raised) );		
}

/* Exit action for state 'Abrir'. */
static void prefix_exact_Bienvenida_Abrir(Prefix* handle)
{
	/* Exit action for state 'Abrir'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Abrir_tev0_raised) );		
	prefixIface_opGPIO(handle, PREFIX_PREFIXIFACE_GPIO5, bool_true);
	prefixIface_opGPIO(handle, PREFIX_PREFIXIFACE_GPIO6, bool_true);
}

/* Exit action for state 'Correccion'. */
static void prefix_exact_Bienvenida_Correccion(Prefix* handle)
{
	/* Exit action for state 'Correccion'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_Bienvenida_Correccion_tev0_raised) );		
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	prefix_enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Prefix_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void prefix_enseq_IDLE_ESPERA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_IDLE_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Bienvenida */
static void prefix_enseq_Bienvenida_Bienvenida_default(Prefix* handle)
{
	/* 'default' enter sequence for state Bienvenida */
	prefix_enact_Bienvenida_Bienvenida(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Bienvenida;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Elección */
static void prefix_enseq_Bienvenida_Elecci_n_default(Prefix* handle)
{
	/* 'default' enter sequence for state Elección */
	prefix_enact_Bienvenida_Elecci_n(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Elecci_n;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Control */
static void prefix_enseq_Bienvenida_Control_default(Prefix* handle)
{
	/* 'default' enter sequence for state Control */
	prefix_enact_Bienvenida_Control(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Control;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Embotellado */
static void prefix_enseq_Bienvenida_Embotellado_default(Prefix* handle)
{
	/* 'default' enter sequence for state Embotellado */
	prefix_enact_Bienvenida_Embotellado(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Embotellado;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Calentar */
static void prefix_enseq_Bienvenida_Calentar_default(Prefix* handle)
{
	/* 'default' enter sequence for state Calentar */
	prefix_enact_Bienvenida_Calentar(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Calentar;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Abrir */
static void prefix_enseq_Bienvenida_Abrir_default(Prefix* handle)
{
	/* 'default' enter sequence for state Abrir */
	prefix_enact_Bienvenida_Abrir(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Abrir;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Densidad */
static void prefix_enseq_Bienvenida_Densidad_default(Prefix* handle)
{
	/* 'default' enter sequence for state Densidad */
	prefix_enact_Bienvenida_Densidad(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Densidad;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Correccion */
static void prefix_enseq_Bienvenida_Correccion_default(Prefix* handle)
{
	/* 'default' enter sequence for state Correccion */
	prefix_enact_Bienvenida_Correccion(handle);
	handle->stateConfVector[2] = Prefix_Bienvenida_Correccion;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for region TECX */
static void prefix_enseq_TECX_default(Prefix* handle)
{
	/* 'default' enter sequence for region TECX */
	prefix_react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region IDLE */
static void prefix_enseq_IDLE_default(Prefix* handle)
{
	/* 'default' enter sequence for region IDLE */
	prefix_react_IDLE__entry_Default(handle);
}

/* 'default' enter sequence for region Bienvenida */
static void prefix_enseq_Bienvenida_default(Prefix* handle)
{
	/* 'default' enter sequence for region Bienvenida */
	prefix_react_Bienvenida__entry_Default(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void prefix_exseq_IDLE_ESPERA(Prefix* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state Bienvenida */
static void prefix_exseq_Bienvenida_Bienvenida(Prefix* handle)
{
	/* Default exit sequence for state Bienvenida */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
	prefix_exact_Bienvenida_Bienvenida(handle);
}

/* Default exit sequence for state Elección */
static void prefix_exseq_Bienvenida_Elecci_n(Prefix* handle)
{
	/* Default exit sequence for state Elección */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state Control */
static void prefix_exseq_Bienvenida_Control(Prefix* handle)
{
	/* Default exit sequence for state Control */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
	prefix_exact_Bienvenida_Control(handle);
}

/* Default exit sequence for state Embotellado */
static void prefix_exseq_Bienvenida_Embotellado(Prefix* handle)
{
	/* Default exit sequence for state Embotellado */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
	prefix_exact_Bienvenida_Embotellado(handle);
}

/* Default exit sequence for state Calentar */
static void prefix_exseq_Bienvenida_Calentar(Prefix* handle)
{
	/* Default exit sequence for state Calentar */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
	prefix_exact_Bienvenida_Calentar(handle);
}

/* Default exit sequence for state Abrir */
static void prefix_exseq_Bienvenida_Abrir(Prefix* handle)
{
	/* Default exit sequence for state Abrir */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
	prefix_exact_Bienvenida_Abrir(handle);
}

/* Default exit sequence for state Densidad */
static void prefix_exseq_Bienvenida_Densidad(Prefix* handle)
{
	/* Default exit sequence for state Densidad */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state Correccion */
static void prefix_exseq_Bienvenida_Correccion(Prefix* handle)
{
	/* Default exit sequence for state Correccion */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
	prefix_exact_Bienvenida_Correccion(handle);
}

/* Default exit sequence for region TECX */
static void prefix_exseq_TECX(Prefix* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of prefix.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_exseq_TECX_OPRIMIDO(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region IDLE */
static void prefix_exseq_IDLE(Prefix* handle)
{
	/* Default exit sequence for region IDLE */
	/* Handle exit of all possible states (of prefix.IDLE) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_IDLE_ESPERA :
		{
			prefix_exseq_IDLE_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Bienvenida */
static void prefix_exseq_Bienvenida(Prefix* handle)
{
	/* Default exit sequence for region Bienvenida */
	/* Handle exit of all possible states (of prefix.Bienvenida) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_Bienvenida_Bienvenida :
		{
			prefix_exseq_Bienvenida_Bienvenida(handle);
			break;
		}
		case Prefix_Bienvenida_Elecci_n :
		{
			prefix_exseq_Bienvenida_Elecci_n(handle);
			break;
		}
		case Prefix_Bienvenida_Control :
		{
			prefix_exseq_Bienvenida_Control(handle);
			break;
		}
		case Prefix_Bienvenida_Embotellado :
		{
			prefix_exseq_Bienvenida_Embotellado(handle);
			break;
		}
		case Prefix_Bienvenida_Calentar :
		{
			prefix_exseq_Bienvenida_Calentar(handle);
			break;
		}
		case Prefix_Bienvenida_Abrir :
		{
			prefix_exseq_Bienvenida_Abrir(handle);
			break;
		}
		case Prefix_Bienvenida_Densidad :
		{
			prefix_exseq_Bienvenida_Densidad(handle);
			break;
		}
		case Prefix_Bienvenida_Correccion :
		{
			prefix_exseq_Bienvenida_Correccion(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void prefix_react_TECX_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (prefix_check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state ESPERA. */
static void prefix_react_IDLE_ESPERA(Prefix* handle)
{
	/* The reactions of state ESPERA. */
	if (prefix_check_IDLE_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_IDLE_ESPERA_tr0(handle);
	}  else
	{
		if (prefix_check_IDLE_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_IDLE_ESPERA_tr1(handle);
		}  else
		{
			if (prefix_check_IDLE_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_IDLE_ESPERA_tr2(handle);
			}  else
			{
				if (prefix_check_IDLE_ESPERA_tr3_tr3(handle) == bool_true)
				{ 
					prefix_effect_IDLE_ESPERA_tr3(handle);
				}  else
				{
					if (prefix_check_IDLE_ESPERA_tr4_tr4(handle) == bool_true)
					{ 
						prefix_effect_IDLE_ESPERA_tr4(handle);
					}  else
					{
						if (prefix_check_IDLE_ESPERA_tr5_tr5(handle) == bool_true)
						{ 
							prefix_effect_IDLE_ESPERA_tr5(handle);
						}  else
						{
							if (prefix_check_IDLE_ESPERA_tr6_tr6(handle) == bool_true)
							{ 
								prefix_effect_IDLE_ESPERA_tr6(handle);
							}  else
							{
								if (prefix_check_IDLE_ESPERA_tr7_tr7(handle) == bool_true)
								{ 
									prefix_effect_IDLE_ESPERA_tr7(handle);
								}  else
								{
									if (prefix_check_IDLE_ESPERA_tr8_tr8(handle) == bool_true)
									{ 
										prefix_effect_IDLE_ESPERA_tr8(handle);
									}  else
									{
										if (prefix_check_IDLE_ESPERA_tr9_tr9(handle) == bool_true)
										{ 
											prefix_effect_IDLE_ESPERA_tr9(handle);
										}  else
										{
											if (prefix_check_IDLE_ESPERA_tr10_tr10(handle) == bool_true)
											{ 
												prefix_effect_IDLE_ESPERA_tr10(handle);
											}  else
											{
												if (prefix_check_IDLE_ESPERA_tr11_tr11(handle) == bool_true)
												{ 
													prefix_effect_IDLE_ESPERA_tr11(handle);
												}  else
												{
													if (prefix_check_IDLE_ESPERA_tr12_tr12(handle) == bool_true)
													{ 
														prefix_effect_IDLE_ESPERA_tr12(handle);
													}  else
													{
														if (prefix_check_IDLE_ESPERA_tr13_tr13(handle) == bool_true)
														{ 
															prefix_effect_IDLE_ESPERA_tr13(handle);
														}  else
														{
															if (prefix_check_IDLE_ESPERA_tr14_tr14(handle) == bool_true)
															{ 
																prefix_effect_IDLE_ESPERA_tr14(handle);
															}  else
															{
																if (prefix_check_IDLE_ESPERA_tr15_tr15(handle) == bool_true)
																{ 
																	prefix_effect_IDLE_ESPERA_tr15(handle);
																}  else
																{
																	if (prefix_check_IDLE_ESPERA_tr16_tr16(handle) == bool_true)
																	{ 
																		prefix_effect_IDLE_ESPERA_tr16(handle);
																	}  else
																	{
																		if (prefix_check_IDLE_ESPERA_tr17_tr17(handle) == bool_true)
																		{ 
																			prefix_effect_IDLE_ESPERA_tr17(handle);
																		}  else
																		{
																			if (prefix_check_IDLE_ESPERA_tr18_tr18(handle) == bool_true)
																			{ 
																				prefix_effect_IDLE_ESPERA_tr18(handle);
																			}  else
																			{
																				if (prefix_check_IDLE_ESPERA_tr19_tr19(handle) == bool_true)
																				{ 
																					prefix_effect_IDLE_ESPERA_tr19(handle);
																				}  else
																				{
																					if (prefix_check_IDLE_ESPERA_tr20_tr20(handle) == bool_true)
																					{ 
																						prefix_effect_IDLE_ESPERA_tr20(handle);
																					}  else
																					{
																						if (prefix_check_IDLE_ESPERA_tr21_tr21(handle) == bool_true)
																						{ 
																							prefix_effect_IDLE_ESPERA_tr21(handle);
																						}  else
																						{
																							if (prefix_check_IDLE_ESPERA_tr22_tr22(handle) == bool_true)
																							{ 
																								prefix_effect_IDLE_ESPERA_tr22(handle);
																							}  else
																							{
																								if (prefix_check_IDLE_ESPERA_tr23_tr23(handle) == bool_true)
																								{ 
																									prefix_effect_IDLE_ESPERA_tr23(handle);
																								}  else
																								{
																									if (prefix_check_IDLE_ESPERA_tr24_tr24(handle) == bool_true)
																									{ 
																										prefix_effect_IDLE_ESPERA_tr24(handle);
																									} 
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

/* The reactions of state Bienvenida. */
static void prefix_react_Bienvenida_Bienvenida(Prefix* handle)
{
	/* The reactions of state Bienvenida. */
	if (prefix_check_Bienvenida_Bienvenida_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Bienvenida_tr0(handle);
	} 
}

/* The reactions of state Elección. */
static void prefix_react_Bienvenida_Elecci_n(Prefix* handle)
{
	/* The reactions of state Elección. */
	if (prefix_check_Bienvenida_Elecci_n_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Elecci_n_tr0(handle);
	}  else
	{
		if (prefix_check_Bienvenida_Elecci_n_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_Bienvenida_Elecci_n_tr1(handle);
		}  else
		{
			if (prefix_check_Bienvenida_Elecci_n_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_Bienvenida_Elecci_n_tr2(handle);
			} 
		}
	}
}

/* The reactions of state Control. */
static void prefix_react_Bienvenida_Control(Prefix* handle)
{
	/* The reactions of state Control. */
	if (prefix_check_Bienvenida_Control_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Control_tr0(handle);
	}  else
	{
		if (prefix_check_Bienvenida_Control_lr1_lr1(handle) == bool_true)
		{ 
			prefix_effect_Bienvenida_Control_lr1_lr1(handle);
		} 
	}
}

/* The reactions of state Embotellado. */
static void prefix_react_Bienvenida_Embotellado(Prefix* handle)
{
	/* The reactions of state Embotellado. */
	if (prefix_check_Bienvenida_Embotellado_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Embotellado_tr0(handle);
	} 
}

/* The reactions of state Calentar. */
static void prefix_react_Bienvenida_Calentar(Prefix* handle)
{
	/* The reactions of state Calentar. */
	if (prefix_check_Bienvenida_Calentar_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Calentar_tr0(handle);
	}  else
	{
		if (prefix_check_Bienvenida_Calentar_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_Bienvenida_Calentar_tr1(handle);
		}  else
		{
			if (prefix_check_Bienvenida_Calentar_lr1_lr1(handle) == bool_true)
			{ 
				prefix_effect_Bienvenida_Calentar_lr1_lr1(handle);
			} 
		}
	}
}

/* The reactions of state Abrir. */
static void prefix_react_Bienvenida_Abrir(Prefix* handle)
{
	/* The reactions of state Abrir. */
	if (prefix_check_Bienvenida_Abrir_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Abrir_tr0(handle);
	}  else
	{
		if (prefix_check_Bienvenida_Abrir_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_Bienvenida_Abrir_tr1(handle);
		}  else
		{
			if (prefix_check_Bienvenida_Abrir_lr1_lr1(handle) == bool_true)
			{ 
				prefix_effect_Bienvenida_Abrir_lr1_lr1(handle);
			} 
		}
	}
}

/* The reactions of state Densidad. */
static void prefix_react_Bienvenida_Densidad(Prefix* handle)
{
	/* The reactions of state Densidad. */
	if (prefix_check_Bienvenida_Densidad_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Densidad_tr0(handle);
	} 
}

/* The reactions of state Correccion. */
static void prefix_react_Bienvenida_Correccion(Prefix* handle)
{
	/* The reactions of state Correccion. */
	if (prefix_check_Bienvenida_Correccion_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Bienvenida_Correccion_tr0(handle);
	}  else
	{
		if (prefix_check_Bienvenida_Correccion_lr1_lr1(handle) == bool_true)
		{ 
			prefix_effect_Bienvenida_Correccion_lr1_lr1(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void prefix_react_TECX__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_IDLE__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_IDLE_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_Bienvenida__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_Bienvenida_Bienvenida_default(handle);
}


