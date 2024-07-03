//#include "AI_bsp.h"
//#include "network.h"
//#include "network_data.h"
//#include "main.h"
//extern ai_handle network;
//extern ai_u8 activations;
//extern ai_float in_data;
//extern ai_float out_data;

//extern ai_buffer *ai_input;
//extern ai_buffer *ai_output;

//int ai_Init(void)
//{
//	ai_error err;
//	
//	const ai_handle acts[] = { activations };
//  err = ai_network_create_and_init(&network, acts, NULL);
//	if(err.type != AI_ERROR_NONE)
//	{
//	
//	}
//	
//	ai_input = ai_network_inputs_get(network, NULL);
//	ai_output = ai_network_outputs_get(network, NULL);
//	
//	return 0;
//}