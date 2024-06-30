/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Jun 30 10:31:17 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "6bf22785a15d9fdc54030d6cb4e23ba0"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Jun 30 10:31:17 2024"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

static ai_ptr g_network_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14400, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19200, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19200, AI_STATIC)
/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)
/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 15552, AI_STATIC)
/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)
/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)
/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)
/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)
/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)
/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_58_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)
/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)
/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)
/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)
/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)
/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_62_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)
/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12096, AI_STATIC)
/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)
/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20480, AI_STATIC)
/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  pool_67_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)
/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  gemm_68_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8, AI_STATIC)
/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)
/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  nl_69_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8, AI_STATIC)
/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conversion_70_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 8, AI_STATIC)
/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)
/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)
/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)
/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)
/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)
/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)
/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)
/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)
/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)
/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)
/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)
/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)
/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)
/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)
/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)
/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)
/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)
/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)
/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)
/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)
/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)
/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)
/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)
/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)
/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)
/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)
/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)
/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)
/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)
/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)
/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)
/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)
/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)
/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)
/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)
/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)
/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)
/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)
/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)
/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)
/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)
/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)
/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)
/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)
/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)
/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)
/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)
/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)
/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)
/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)
/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)
/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)
/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)
/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1328, AI_STATIC)
/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)
/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)
/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)
/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)
/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)
/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)
/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)
/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)
/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)
/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)
/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)
/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)
/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)
/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)
/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)
/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)
/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)
/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)
/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)
/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)
/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)
/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)
/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)
/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2464, AI_STATIC)
/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)
/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)
/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13248, AI_STATIC)
/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)
/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)
/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20480, AI_STATIC)
/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)
/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)
/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  gemm_68_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 1280, AI_STATIC)
/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)
/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)
/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  nl_69_scratch0_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)
/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)
/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)
/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)
/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)
/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)
/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)
/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)
/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)
/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)
/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)
/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)
/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)
/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)
/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)
/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)
/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)
/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)
/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_59_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)
/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)
/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)
/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)
/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)
/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)
/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_63_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)
/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)
/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)
/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)
/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 112, AI_STATIC)
/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 143360, AI_STATIC)
/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1280, AI_STATIC)
/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  gemm_68_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)
/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  gemm_68_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)
/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)
/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)
/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)
/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)
/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_input_10_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 49152, AI_STATIC)
/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49153, AI_STATIC)
/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)
/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)
/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 69696, AI_STATIC)
/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 196608, AI_STATIC)
/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)
/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)
/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 196608, AI_STATIC)
/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)
/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 202800, AI_STATIC)
/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 55488, AI_STATIC)
/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)
/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)
/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)
/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 52272, AI_STATIC)
/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)
/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)
/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 31104, AI_STATIC)
/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)
/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)
/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)
/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 31104, AI_STATIC)
/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)
/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)
/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)
/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)
/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 27744, AI_STATIC)
/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)
/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)
/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14400, AI_STATIC)
/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)
/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)
/* Array#258 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#259 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14400, AI_STATIC)
/* Array#260 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)
/* Array#262 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#263 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)
/* Array#264 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)
/* Array#265 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/* Array#266 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14400, AI_STATIC)
/* Array#267 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)
/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07227042317390442f),
    AI_PACK_INTQ_ZP(-22)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_39_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1740693747997284f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0959068164229393f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017750903964042664f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017750903964042664f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019916679710149765f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0700037032365799f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_46_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10786440968513489f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_47_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015995057299733162f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015995057299733162f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022461436688899994f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1024823933839798f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_50_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12379078567028046f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06538684666156769f),
    AI_PACK_INTQ_ZP(27)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014617988839745522f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014617988839745522f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01898842677474022f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07395899295806885f),
    AI_PACK_INTQ_ZP(14)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_58_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09007714688777924f),
    AI_PACK_INTQ_ZP(36)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_59_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01668418012559414f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01668418012559414f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019626092165708542f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0695195347070694f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_62_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07964996993541718f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_63_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018390053883194923f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018390053883194923f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0589074082672596f),
    AI_PACK_INTQ_ZP(-13)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_67_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023517493158578873f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_68_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011389384977519512f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_69_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005714218597859144f, 0.007307932712137699f, 0.0021998111624270678f, 8.969741998043901e-07f, 0.003337143687531352f, 0.0027391177136451006f, 7.39017593787139e-07f, 7.768459653334503e-08f, 3.3937345733647817e-07f, 7.17248838100204e-08f, 9.760049834994788e-08f, 0.014352942816913128f, 7.550114311527523e-09f, 2.9610365714916043e-08f, 0.004223909694701433f, 0.024509921669960022f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00757900346070528f, 0.00667955819517374f, 0.009534644894301891f, 0.3139938414096832f, 0.01017471682280302f, 0.0035282683093100786f, 0.06294555217027664f, 0.336553156375885f, 0.6555811762809753f, 0.01130108442157507f, 0.33615633845329285f, 0.004090350121259689f, 0.3032977879047394f, 0.01352775003761053f, 0.002971520647406578f, 0.0025094295851886272f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07427730411291122f, 0.043750014156103134f, 0.10243388265371323f, 0.04025603458285332f, 0.10025058686733246f, 0.039632149040699005f, 0.047637686133384705f, 0.06723038852214813f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.937008052901092e-09f, 0.0016437878366559744f, 0.0015594469150528312f, 0.002818780718371272f, 0.0014898428926244378f, 0.0016853264532983303f, 0.002845008624717593f, 0.0031470218673348427f, 0.001748637412674725f, 0.002385150408372283f, 0.0013528763083741069f, 0.0008371855947189033f, 0.0004974916810169816f, 0.000714674883056432f, 0.001207480439916253f, 0.0017138440161943436f, 3.937008052901092e-09f, 0.0008119196863844991f, 0.002620520070195198f, 0.0006576663581654429f, 0.0011674683773890138f, 0.0005547254113480449f, 0.0006418940611183643f, 0.0017487367149442434f, 0.00046650104923173785f, 3.937008052901092e-09f, 0.0014452955219894648f, 0.0012331533944234252f, 0.00047908039414323866f, 0.0007917761104181409f, 0.001556172501295805f, 0.0015153430867940187f, 2.1423941731768537e-08f, 0.0011465545976534486f, 0.001016238471493125f, 0.002542654052376747f, 0.002992757596075535f, 0.001346452860161662f, 0.003926602192223072f, 0.0005864862469024956f, 0.0005527011817321181f, 0.0007557786884717643f, 0.0012808553874492645f, 0.0008739684708416462f, 0.0011040811659768224f, 0.0006210759747773409f, 0.0007849025423638523f, 0.002156137954443693f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.035710372030735016f, 0.012564068660140038f, 0.0076755499467253685f, 0.0022173889447003603f, 0.01293453760445118f, 0.0021419781260192394f, 0.0018176650628447533f, 0.0009159664041362703f, 0.010091796517372131f, 0.004151238594204187f, 0.007309692911803722f, 0.02524654194712639f, 0.01676987297832966f, 0.004602468106895685f, 0.004847642034292221f, 0.005462410859763622f, 0.0026014659088104963f, 0.00828492734581232f, 0.00458384258672595f, 0.0025457863230258226f, 0.037004757672548294f, 0.007258194033056498f, 0.015889950096607208f, 0.0030497433617711067f, 0.00967337191104889f, 0.00805377122014761f, 0.010932964272797108f, 0.006358807906508446f, 0.00901111401617527f, 0.02497938834130764f, 0.003767899237573147f, 0.00674733892083168f, 0.003981629386544228f, 0.006342389155179262f, 0.0027004352305084467f, 0.004342146683484316f, 0.0016758464043959975f, 0.002619324717670679f, 0.0017537095118314028f, 0.009581629186868668f, 0.010199164040386677f, 0.013854342512786388f, 0.005984445568174124f, 0.00944496039301157f, 0.03516044467687607f, 0.009928200393915176f, 0.01021618489176035f, 0.01301551517099142f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02732785791158676f, 0.021867509931325912f, 0.031966131180524826f, 0.0285703893750906f, 0.02597631886601448f, 0.030163845047354698f, 0.036174237728118896f, 0.03457535803318024f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005074846558272839f, 0.001249194610863924f, 3.937008052901092e-09f, 0.00114387646317482f, 0.0009242924861609936f, 0.0006437629926949739f, 0.0008648837101645768f, 0.0006878037820570171f, 0.0006542903138324618f, 0.0012614150764420629f, 0.00022903205535840243f, 0.001961799804121256f, 0.000252502562943846f, 0.002378755481913686f, 0.0010664159199222922f, 0.0005292993155308068f, 0.009933503344655037f, 0.004623770248144865f, 0.0017190820071846247f, 0.0006207122933119535f, 0.0008174960967153311f, 0.0008407325949519873f, 0.0011087697930634022f, 0.0037609918508678675f, 0.0007930087158456445f, 0.0016068416880443692f, 0.001309810671955347f, 0.0012267653364688158f, 0.0015649647684767842f, 0.0003400508430786431f, 0.000594356853980571f, 0.005464424844831228f, 0.0006850603967905045f, 0.001564611797221005f, 0.0014189912471920252f, 0.0005656199646182358f, 0.0016850174870342016f, 0.000738676346372813f, 0.000626404769718647f, 0.003843545913696289f, 0.0031313272193074226f, 3.937008052901092e-09f, 0.0006364296423271298f, 0.0006194888264872134f, 0.002267455914989114f, 0.0009358564857393503f, 0.004233742132782936f, 0.001169794239103794f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005579360295087099f, 0.0020833625458180904f, 0.0005155862309038639f, 0.009609628468751907f, 0.005816595163196325f, 0.007233471609652042f, 0.007113430183380842f, 0.0052009462378919125f, 0.010324576869606972f, 0.004771088249981403f, 0.008538291789591312f, 0.006440948694944382f, 0.008439851924777031f, 0.004229712765663862f, 0.005242523271590471f, 0.012576309964060783f, 0.004163390025496483f, 0.0017952858470380306f, 0.006230869330465794f, 0.003007178194820881f, 0.002813174622133374f, 0.00870117824524641f, 0.003502880921587348f, 0.006564117036759853f, 0.01033867709338665f, 0.006282545626163483f, 0.0018423943547531962f, 0.007257301826030016f, 0.005136243999004364f, 0.0078025441616773605f, 0.004216035827994347f, 0.001740046194754541f, 0.00842028483748436f, 0.0039072586223483086f, 0.007807038724422455f, 0.006719550117850304f, 0.0023847687989473343f, 0.007765599526464939f, 0.006993668153882027f, 0.0030277592595666647f, 0.004492002539336681f, 0.11410766839981079f, 0.0055764177814126015f, 0.013564201071858406f, 0.004070590250194073f, 0.005394370295107365f, 0.001364281983114779f, 0.004403187893331051f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02735564112663269f, 0.03534423187375069f, 0.025989234447479248f, 0.023500019684433937f, 0.042085759341716766f, 0.028304051607847214f, 0.07017899304628372f, 0.06589893996715546f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006165471859276295f, 0.000914356904104352f, 0.000995383132249117f, 0.0009171952260658145f, 0.0008889760938473046f, 0.00044903066009283066f, 0.00010907356045208871f, 0.00029302696930244565f, 0.000376625859644264f, 0.0007662019343115389f, 0.0031835068948566914f, 0.00039150213706307113f, 0.00034701390541158617f, 0.0004774048866238445f, 0.00042062802822329104f, 0.0027926552575081587f, 0.002202005125582218f, 0.0004553425242193043f, 0.0004014914156869054f, 0.0003125155926682055f, 0.0005967037286609411f, 0.00275217741727829f, 0.00036006042500957847f, 0.0003031965752597898f, 0.000462068390334025f, 0.002544194692745805f, 0.0005084405420348048f, 0.001100059482268989f, 0.0008866770076565444f, 0.0003521362377796322f, 0.0007180361426435411f, 0.0003692992904689163f, 0.0015811575576663017f, 0.0003631357685662806f, 0.0003979248576797545f, 0.0002923719584941864f, 0.0033688072580844164f, 0.0010529592400416732f, 0.00048792202142067254f, 0.0011393303284421563f, 0.0020662122406065464f, 0.0009560995968058705f, 0.0016784908948466182f, 0.0004621467087417841f, 0.0007136213243938982f, 0.00015230926510412246f, 0.002100033685564995f, 0.0005980707937851548f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003209961112588644f, 0.0028405089396983385f, 0.0022436410654336214f, 0.003977537155151367f, 0.0016716185491532087f, 0.005019441246986389f, 0.013333799317479134f, 0.00752747617661953f, 0.0058746044524014f, 0.0046453941613435745f, 0.001504607149399817f, 0.005177588667720556f, 0.006646296009421349f, 0.003124835668131709f, 0.005141780711710453f, 0.0013121700612828135f, 0.0010070460848510265f, 0.003050717059522867f, 0.0057509709149599075f, 0.008459306322038174f, 0.004681166261434555f, 0.0011725795920938253f, 0.0064229355193674564f, 0.006041473243385553f, 0.005044225603342056f, 0.0010722436709329486f, 0.0040436084382236f, 0.002134260954335332f, 0.0035349861718714237f, 0.0056083546951413155f, 0.0035284680780023336f, 0.006056679412722588f, 0.0019716492388397455f, 0.005391788203269243f, 0.004481467884033918f, 0.005388982594013214f, 0.0009439967689104378f, 0.0030941481236368418f, 0.004664558917284012f, 0.0027705514803528786f, 0.0011481443652883172f, 0.0030034848023205996f, 0.0015051272930577397f, 0.005014731548726559f, 0.003629498416557908f, 0.015775371342897415f, 0.0017326968954876065f, 0.0039154947735369205f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04443444684147835f, 0.03478139266371727f, 0.040131740272045135f, 0.03861455246806145f, 0.026344897225499153f, 0.052823446691036224f, 0.036641474813222885f, 0.043218355625867844f, 0.02232813835144043f, 0.024685410782694817f, 0.03457645699381828f, 0.04107110947370529f, 0.03365728631615639f, 0.037548623979091644f, 0.02203379198908806f, 0.026399023830890656f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008686547516845167f, 0.002111651236191392f, 0.0009017603588290513f, 0.0017055057687684894f, 0.0007320131990127265f, 0.0005828093271702528f, 0.0013928014086559415f, 0.00120187783613801f, 0.0008002251270227134f, 0.000607869413215667f, 0.0014841919764876366f, 0.00044137085205875337f, 0.0013195632491260767f, 0.0011481179390102625f, 0.001449602423235774f, 0.0006818558904342353f, 0.0015388629399240017f, 0.001684058690443635f, 0.0017240309389308095f, 0.0007658367976546288f, 0.0004007918469142169f, 0.000643180392216891f, 0.0005004779086448252f, 0.0009184840018860996f, 0.0002862465917132795f, 0.0016459375619888306f, 0.001188277150504291f, 0.0010955596808344126f, 0.0020729333627969027f, 0.0012013331288471818f, 0.0013041712809354067f, 0.0010527722770348191f, 0.0009212176082655787f, 0.0004617768572643399f, 0.0008732997812330723f, 0.0008067224407568574f, 0.0007921630749478936f, 0.0013481919886544347f, 0.0007056457106955349f, 0.0011439415393397212f, 0.001495723845437169f, 0.0005296256858855486f, 0.0008660146850161254f, 0.0005495697841979563f, 0.0008095424855127931f, 0.00048595666885375977f, 0.0002987401676364243f, 0.00173926108982414f, 0.00037444487679749727f, 0.0009992866544052958f, 0.0014921865658834577f, 0.0006940228631719947f, 0.0009509144583716989f, 0.00036435629590414464f, 0.0009145842050202191f, 0.0008503865683451295f, 0.0008691696566529572f, 0.001253583817742765f, 0.002942729275673628f, 0.0008093391661532223f, 0.0007124058320187032f, 0.0009747425210662186f, 0.000996316666714847f, 0.001133145298808813f, 0.000600531289819628f, 0.002393784001469612f, 0.0007063273224048316f, 0.0005362718948163092f, 0.0009095307905226946f, 0.0005009667365811765f, 0.0008528334437869489f, 0.0009262233506888151f, 0.0006381828570738435f, 0.00035110683529637754f, 0.0009051125380210578f, 0.000880418170709163f, 0.0005597855197265744f, 0.0013710313942283392f, 0.0006700154044665396f, 0.0010235822992399335f, 0.0005162765737622976f, 0.0007294270908460021f, 0.0005922289565205574f, 0.0015712695894762874f, 0.001803513732738793f, 0.000807036820333451f, 0.0012441567378118634f, 0.0005463390843942761f, 0.001062581199221313f, 0.0011475374922156334f, 0.0036454966757446527f, 0.0023681754246354103f, 0.0007847557426430285f, 0.0013692843494936824f, 0.0007564827683381736f, 0.0008601995068602264f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008140787482261658f, 0.014674525707960129f, 0.007888035848736763f, 0.009193968959152699f, 0.00686246482655406f, 0.004995065741240978f, 0.008789139799773693f, 0.01237358245998621f, 0.005579489748924971f, 0.010223218239843845f, 0.0016301685245707631f, 0.02456958033144474f, 0.005046133883297443f, 0.018456434831023216f, 0.009602906182408333f, 0.010616674087941647f, 0.005531176459044218f, 0.007326933089643717f, 0.009070167317986488f, 0.007336507551372051f, 0.017484568059444427f, 0.012046168558299541f, 0.010513144545257092f, 0.006761828903108835f, 0.053053710609674454f, 0.004405946005135775f, 0.008208900690078735f, 0.006842318922281265f, 0.0017054490745067596f, 0.01180176716297865f, 0.007258445955812931f, 0.009313038550317287f, 0.004078491125255823f, 0.014992358162999153f, 0.01133236289024353f, 0.01463636476546526f, 0.00830160640180111f, 0.009992646053433418f, 0.006770219188183546f, 0.0017416003393009305f, 0.004673989489674568f, 0.013442332856357098f, 0.011427854187786579f, 0.01132392231374979f, 0.005750362295657396f, 0.015068302862346172f, 0.01976940780878067f, 0.006019202992320061f, 0.021453265100717545f, 0.03417174518108368f, 0.005475442856550217f, 0.006369853392243385f, 0.009290889836847782f, 0.011784814298152924f, 0.011112969368696213f, 0.0044004288502037525f, 0.005101353861391544f, 0.004497544374316931f, 0.008289147168397903f, 0.007246720138937235f, 0.007026704493910074f, 0.0037727602757513523f, 0.003741534659639001f, 0.004224733915179968f, 0.006661216262727976f, 0.0030649718828499317f, 0.00647366838529706f, 0.009548273868858814f, 0.014429990202188492f, 0.02092018350958824f, 0.007683367468416691f, 0.006147774402052164f, 0.006676530931144953f, 0.01517738401889801f, 0.005783666390925646f, 0.00887771975249052f, 0.011759194545447826f, 0.005790644325315952f, 0.007958166301250458f, 0.00498814694583416f, 0.006864164024591446f, 0.013576632365584373f, 0.006492928601801395f, 0.024333756417036057f, 0.009028962813317776f, 0.0056329104118049145f, 0.00769338384270668f, 0.008565336465835571f, 0.00429608765989542f, 0.004654670134186745f, 0.0011787326075136662f, 0.007283021695911884f, 0.007346516940742731f, 0.006542316172271967f, 0.004445427563041449f, 0.008407169952988625f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017082948237657547f, 0.018293343484401703f, 0.025338802486658096f, 0.012014278210699558f, 0.017662782222032547f, 0.025195851922035217f, 0.015276397578418255f, 0.02536134421825409f, 0.012917324900627136f, 0.01538081094622612f, 0.015335015021264553f, 0.009243343956768513f, 0.012354963459074497f, 0.010932952165603638f, 0.011383076198399067f, 0.01161827240139246f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00027425034204497933f, 0.00028609714354388416f, 0.0005351933650672436f, 0.0004230379709042609f, 0.000655128329526633f, 0.000488175981445238f, 0.0004372970142867416f, 0.0010625000577419996f, 0.0009366718586534262f, 0.0002466634032316506f, 0.0016290155472233891f, 0.0006094058626331389f, 0.0007594602648168802f, 0.0005769157432951033f, 0.003577639115974307f, 0.0004039545019622892f, 0.0005338572664186358f, 0.00047753509716130793f, 0.0005863256519660354f, 0.0005497357342392206f, 0.0017203306779265404f, 0.00044145368156023324f, 0.00036107137566432357f, 0.000444755278294906f, 0.0006779988179914653f, 0.0005733722355216742f, 0.0006206162506714463f, 0.00036346286651678383f, 0.0005558375269174576f, 0.0017191607039421797f, 0.0008501379052177072f, 0.00061601004563272f, 0.0005586744518950582f, 0.0005803228123113513f, 0.0011006153654307127f, 0.0005173443350940943f, 0.0011958961840718985f, 0.00077068991959095f, 0.00022939704649616033f, 0.0007140442612580955f, 0.0007466646493412554f, 0.0008584086317569017f, 0.0004244150477461517f, 0.0007170855533331633f, 0.001858757808804512f, 0.0007799787563271821f, 0.0007773821707814932f, 0.000918046513106674f, 0.0006249775760807097f, 0.0004700798017438501f, 0.0006133320275694132f, 0.00072987045859918f, 0.001047639176249504f, 0.002310867654159665f, 0.000802264257799834f, 0.0008010933524928987f, 0.000622726627625525f, 0.0003690902376547456f, 0.0014213077956810594f, 0.0004798484733328223f, 0.0007703757146373391f, 0.00027192363631911576f, 0.00037038844311609864f, 0.0005367250414565206f, 0.0015831540804356337f, 0.0008899936801753938f, 0.001936212764121592f, 0.0005810300935991108f, 0.0006839491543360054f, 0.0016719361301511526f, 0.0007669543847441673f, 0.0006132019916549325f, 0.0012561839539557695f, 0.0011710345279425383f, 0.00055677694035694f, 0.0007518286583945155f, 0.0007945441757328808f, 0.0006782528362236917f, 0.0010542336385697126f, 0.0007106764242053032f, 0.000490909325890243f, 0.0006380283157341182f, 0.0018991159740835428f, 0.0005602029268629849f, 0.000679728458635509f, 0.000658470147754997f, 0.0005012003821320832f, 0.0005338346818462014f, 0.00066827901173383f, 0.001151759410277009f, 0.0006173823494464159f, 0.0008200363954529166f, 0.0012637097388505936f, 0.0007151685422286391f, 0.0010985705303028226f, 0.0008468143059872091f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02604261040687561f, 0.01331928838044405f, 0.0062398845329880714f, 0.009756148792803288f, 0.02079005166888237f, 0.010045119561254978f, 0.008217591792345047f, 0.0029287966899573803f, 0.005066941492259502f, 0.01416960172355175f, 0.005214236676692963f, 0.013289985246956348f, 0.003786772256717086f, 0.008730222471058369f, 0.0011997950496152043f, 0.01246187835931778f, 0.010912024416029453f, 0.008537624962627888f, 0.0053040641359984875f, 0.007772429380565882f, 0.009361484088003635f, 0.020008932799100876f, 0.010785755701363087f, 0.0066672577522695065f, 0.0071036601439118385f, 0.010107855312526226f, 0.005854660179466009f, 0.0272192545235157f, 0.015094943344593048f, 0.011296429671347141f, 0.005600012838840485f, 0.007961999624967575f, 0.020009802654385567f, 0.011589550413191319f, 0.0029745958745479584f, 0.007243169937282801f, 0.00311585096642375f, 0.015603764913976192f, 0.011173794977366924f, 0.009557344019412994f, 0.010196621529757977f, 0.0028063205536454916f, 0.008232359774410725f, 0.009243465028703213f, 0.0020745431538671255f, 0.004601507447659969f, 0.010803562588989735f, 0.008476166985929012f, 0.013710626401007175f, 0.005414317827671766f, 0.0024214480072259903f, 0.018468080088496208f, 0.004637450911104679f, 0.0033286705147475004f, 0.006622171960771084f, 0.0038505836855620146f, 0.005890986882150173f, 0.005880715791136026f, 0.0021514471154659986f, 0.009588279761373997f, 0.015437149442732334f, 0.038554638624191284f, 0.011988779529929161f, 0.006633471697568893f, 0.005276309791952372f, 0.004692151211202145f, 0.0023272570688277483f, 0.010962758213281631f, 0.006558929104357958f, 0.002357825869694352f, 0.0084163723513484f, 0.007836708799004555f, 0.001671280013397336f, 0.007605085149407387f, 0.012636478990316391f, 0.012032515369355679f, 0.010167041793465614f, 0.005402881186455488f, 0.004947819281369448f, 0.004976965487003326f, 0.009145429357886314f, 0.01553995069116354f, 0.00159930728841573f, 0.023142263293266296f, 0.004001193214207888f, 0.004859034437686205f, 0.01453423872590065f, 0.006126460153609514f, 0.008944676257669926f, 0.005022864323109388f, 0.012130566872656345f, 0.006993759423494339f, 0.007900286465883255f, 0.009173218160867691f, 0.0013800911838188767f, 0.0059983995743095875f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009389534592628479f, 0.01916314661502838f, 0.03322482481598854f, 0.005284617654979229f, 0.0187351293861866f, 0.020095717161893845f, 0.00807938165962696f, 0.021112598478794098f, 0.014596633613109589f, 0.020400013774633408f, 0.011597881093621254f, 0.008772354573011398f, 0.014604008756577969f, 0.015919720754027367f, 0.009455965831875801f, 0.009011042304337025f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004314692341722548f, 0.0012439111014828086f, 0.0009615396847948432f, 0.0012168973917141557f, 0.00042240481707267463f, 0.0006076750578358769f, 0.0004180295509286225f, 0.0005583750898949802f, 0.0007024436490610242f, 0.0007593232439830899f, 0.0006263353861868382f, 0.000438205199316144f, 0.0013851580442860723f, 0.0007255031960085034f, 0.0015359787503257394f, 0.0013342367019504309f, 0.0009924797341227531f, 0.0005800898652523756f, 0.0011539972620084882f, 0.00041058604256249964f, 0.00033565235207788646f, 0.0006658214260824025f, 0.0007171418401412666f, 0.0004270964418537915f, 0.0008921189582906663f, 0.00046584897791035473f, 0.0005690694670192897f, 0.0005365558317862451f, 4.9065893108490855e-05f, 0.0005801487131975591f, 0.001488798065111041f, 0.0008488709572702646f, 0.0008795877220109105f, 0.0009622888755984604f, 0.00045172416139394045f, 0.001024494064040482f, 0.0011778833577409387f, 0.0006514299311675131f, 0.0007047515246085823f, 0.0016499364282935858f, 0.0004817586450371891f, 0.0011657646391540766f, 0.001015932415612042f, 0.001586224534548819f, 0.0005408934084698558f, 0.0007517815683968365f, 0.0005382062518037856f, 0.0004149969026912004f, 0.0013456862652674317f, 0.0006316142971627414f, 0.0006662167725153267f, 0.0012505766935646534f, 0.004034832585602999f, 0.0010437568416818976f, 0.0007604116108268499f, 0.000570611737202853f, 0.0019554258324205875f, 0.00033121620072051883f, 0.00046803176519460976f, 0.001348091522231698f, 0.0011830455623567104f, 0.0011349172564223409f, 0.001250770757906139f, 0.0008017258951440454f, 0.0004593930789269507f, 0.00028079914045520127f, 0.0012727512512356043f, 0.0024394982028752565f, 0.0009198824991472065f, 0.0007755144615657628f, 0.0013291628565639257f, 0.001358128385618329f, 0.0006446429761126637f, 0.0005278931930661201f, 0.0004120554367545992f, 0.0011131680803373456f, 0.0007552329916507006f, 0.0006780675612390041f, 0.0008816472836770117f, 0.00030651254928670824f, 0.0004943822859786451f, 0.0005867069703526795f, 0.0005922436248511076f, 0.0013347237836569548f, 0.001820807927288115f, 0.0006050026277080178f, 0.0005211702082306147f, 0.0005151723162271082f, 0.00042501394636929035f, 0.0005717736203223467f, 0.0005025219288654625f, 0.001422216882929206f, 0.0009402252617292106f, 0.0009151629637926817f, 0.0008880100795067847f, 0.0006643121014349163f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028137294575572014f, 0.0018763296538963914f, 0.0033381490502506495f, 0.0027627611998468637f, 0.006546694319695234f, 0.002227701945230365f, 0.004735232330858707f, 0.007685127668082714f, 0.004395607393234968f, 0.0031498342286795378f, 0.004886610433459282f, 0.005397345405071974f, 0.001513072638772428f, 0.0027752951718866825f, 0.0018477258272469044f, 0.0026943094562739134f, 0.0035769138485193253f, 0.004718046635389328f, 0.0021564855705946684f, 0.002936743199825287f, 0.006747237406671047f, 0.0025400251615792513f, 0.002603932050988078f, 0.009669382125139236f, 0.0037606735713779926f, 0.003406644333153963f, 0.004948808345943689f, 0.004119937773793936f, 0.03532737120985985f, 0.0029178764671087265f, 0.00112024019472301f, 0.0019520852947607636f, 0.003948257304728031f, 0.0018499615835025907f, 0.002671550726518035f, 0.0031579805072396994f, 0.0015255644684657454f, 0.002272411249577999f, 0.003714196151122451f, 0.001239190110936761f, 0.004097979981452227f, 0.0010195355862379074f, 0.0018332245526835322f, 0.0017489048186689615f, 0.004019139334559441f, 0.0027796714566648006f, 0.0036710361018776894f, 0.002412214642390609f, 0.0019535336177796125f, 0.003063304116949439f, 0.0038791452534496784f, 0.0026459526270627975f, 0.0011293858988210559f, 0.003508014837279916f, 0.0032027317211031914f, 0.0018096676794812083f, 0.001068970188498497f, 0.00303364428691566f, 0.0026218576822429895f, 0.0019064318621531129f, 0.002375443931668997f, 0.0022139111533761024f, 0.0010163860861212015f, 0.002917744917795062f, 0.0030465612653642893f, 0.008458795957267284f, 0.0014164214953780174f, 0.0012216032482683659f, 0.0016621347749605775f, 0.0020980481058359146f, 0.0046911598183214664f, 0.001908644917421043f, 0.002706727245822549f, 0.0031403228640556335f, 0.005468231160193682f, 0.0016161215025931597f, 0.0035861025098711252f, 0.0019694867078214884f, 0.0030151831451803446f, 0.0041847447864711285f, 0.0036318323109298944f, 0.002469502156600356f, 0.004612401593476534f, 0.0010780644370242953f, 0.0027185045182704926f, 0.003279689699411392f, 0.002292162738740444f, 0.0038809566758573055f, 0.00340819638222456f, 0.00299860374070704f, 0.0068433647975325584f, 0.002772519364953041f, 0.001515392679721117f, 0.0032682183664292097f, 0.0026759877800941467f, 0.002595205558463931f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017981354147195816f, 0.014385239221155643f, 0.013797329738736153f, 0.022279325872659683f, 0.01660476066172123f, 0.020261330530047417f, 0.0157150961458683f, 0.014035835862159729f, 0.015158395282924175f, 0.02473101206123829f, 0.026983357965946198f, 0.01410300750285387f, 0.026118647307157516f, 0.020144974812865257f, 0.02263101190328598f, 0.023060152307152748f, 0.0144971814006567f, 0.020352981984615326f, 0.01729319617152214f, 0.014935255981981754f, 0.014455124735832214f, 0.01445817481726408f, 0.020783966407179832f, 0.015931176021695137f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006564515642821789f, 0.0007393184350803494f, 0.0008271050173789263f, 0.0006000240100547671f, 0.0006068023503758013f, 0.0005129830678924918f, 0.0006503650220111012f, 0.0010094728786498308f, 0.001042072311975062f, 0.0007245150627568364f, 0.0005597453564405441f, 0.0005529209738597274f, 0.0009789009345695376f, 0.0020653284154832363f, 0.00040473247645422816f, 0.0002942511055152863f, 0.0004150670429226011f, 0.00040352309588342905f, 0.0005551836220547557f, 0.0004380343307275325f, 0.0005846692365594208f, 0.00037517017335630953f, 0.0007912832661531866f, 0.0011578581761568785f, 0.000423130055423826f, 0.0007530220900662243f, 0.001111497520469129f, 0.0008329007541760802f, 0.0007939304923638701f, 0.0012703541433438659f, 0.0006489091902039945f, 0.00032194124651141465f, 0.00010650869808159769f, 0.00037732001510448754f, 0.0007799245067872107f, 0.000735103152692318f, 0.0009071920649148524f, 0.0003125229850411415f, 0.0006971058319322765f, 0.00034797689295373857f, 0.00043273248593322933f, 0.0006520512979477644f, 0.0005655506975017488f, 0.00021386427397374064f, 0.0005836112541146576f, 0.001229768036864698f, 0.00031528237741440535f, 0.0008233656408265233f, 0.0009354754583910108f, 0.0005584824830293655f, 0.0005397910717874765f, 0.0005454457132145762f, 0.0006781884003430605f, 0.0006281376699917018f, 0.0007803756161592901f, 0.0003186172107234597f, 0.000586395850405097f, 0.0005067884339950979f, 0.000645725813228637f, 0.00017053604824468493f, 0.0004302185261622071f, 9.75290167843923e-05f, 0.0009528883965685964f, 0.0007465590606443584f, 0.0005476236692629755f, 0.0007443123613484204f, 0.0007111133309081197f, 0.0010386861395090818f, 0.0004301446897443384f, 0.0004726004844997078f, 0.0007956356857903302f, 0.0006782303098589182f, 0.0007534780306741595f, 0.0003898795403074473f, 0.001057997578755021f, 0.0019976934418082237f, 0.0007520564249716699f, 0.0009028913918882608f, 0.0004436580347828567f, 0.0007699274574406445f, 0.00039840227691456676f, 0.0009997206507250667f, 0.0005241287290118635f, 0.0009616399183869362f, 0.002136786002665758f, 0.001014718203805387f, 0.0002794191532302648f, 0.0006661963416263461f, 0.0007288026972673833f, 0.0009214227902702987f, 0.000405787315685302f, 0.001246010884642601f, 0.0013015859294682741f, 0.0004945474211126566f, 0.0007838086457923055f, 0.0006094493437558413f, 0.0008023890550248325f, 0.0006669766735285521f, 0.0010228748433291912f, 0.0005795663455501199f, 0.0003572197165340185f, 0.0005052543710917234f, 0.0008102752035483718f, 0.0007074144668877125f, 0.0002253546117572114f, 0.00038967482396401465f, 0.0005299263866618276f, 0.0003121795889455825f, 0.0009130396065302193f, 0.0005187640781514347f, 0.0003000744036398828f, 0.0008544220472685993f, 0.0005575542454607785f, 0.0007539487560279667f, 0.0005246114451438189f, 0.0010480285855010152f, 0.00019453965069260448f, 0.0008072282071225345f, 0.0006922503816895187f, 0.000690243614371866f, 0.0011439264053478837f, 0.0006464898469857872f, 0.0007272413349710405f, 0.0003552360867615789f, 0.0002689443645067513f, 0.0008867447031661868f, 0.0005725900991819799f, 0.0005350772407837212f, 0.00047304952749982476f, 0.0007089049322530627f, 0.00016416682046838105f, 0.0006035467376932502f, 0.0006428334163501859f, 0.0006514191045425832f, 0.0006762134726159275f, 0.0005863633123226464f, 0.0006143259815871716f, 0.0004418384633027017f, 0.00038474216125905514f, 0.00022552207519765943f, 0.0007984579424373806f, 0.000505482719745487f, 0.0006568586104549468f, 0.00035215370007790625f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007610206492245197f, 0.00869226548820734f, 0.0046976408921182156f, 0.029094649478793144f, 0.013593963347375393f, 0.01910988800227642f, 0.008741003461182117f, 0.004294222220778465f, 0.009206105954945087f, 0.008890023455023766f, 0.005626725498586893f, 0.019388288259506226f, 0.01146217342466116f, 0.0036005668807774782f, 0.017707722261548042f, 0.015173487365245819f, 0.009356176480650902f, 0.013755290769040585f, 0.00521427346393466f, 0.015233999118208885f, 0.014813657850027084f, 0.007134809624403715f, 0.006880529224872589f, 0.008042125031352043f, 0.016857286915183067f, 0.005248552653938532f, 0.009337639436125755f, 0.009166763164103031f, 0.004801962990313768f, 0.0025743255391716957f, 0.019207069650292397f, 0.022249417379498482f, 0.057325176894664764f, 0.009678687900304794f, 0.004302750341594219f, 0.008365926332771778f, 0.009725774638354778f, 0.009123343043029308f, 0.005477129481732845f, 0.013342614285647869f, 0.018413057550787926f, 0.009533492848277092f, 0.007287079934030771f, 0.022402754053473473f, 0.013858051970601082f, 0.01901894249022007f, 0.016577817499637604f, 0.005339422263205051f, 0.009305729530751705f, 0.009183532558381557f, 0.01794552244246006f, 0.017506832256913185f, 0.019524022936820984f, 0.010673311538994312f, 0.014177365228533745f, 0.01501594576984644f, 0.007766916882246733f, 0.014433732256293297f, 0.011720561422407627f, 0.05780962109565735f, 0.019037971273064613f, 0.019890014082193375f, 0.009633990004658699f, 0.008706632070243359f, 0.04094148427248001f, 0.008088549599051476f, 0.01687442511320114f, 0.020265823230147362f, 0.02587001398205757f, 0.011395779438316822f, 0.006150397006422281f, 0.0038367528468370438f, 0.007622496224939823f, 0.011788437142968178f, 0.007816973142325878f, 0.0048138475976884365f, 0.006404567509889603f, 0.00907565001398325f, 0.009017514996230602f, 0.0035240750294178724f, 0.0053789978846907616f, 0.012430447153747082f, 0.008898901753127575f, 0.010867767967283726f, 0.0030765815172344446f, 0.0023141494020819664f, 0.018025794997811317f, 0.008228713646531105f, 0.006650636438280344f, 0.006398828234523535f, 0.008163449354469776f, 0.004319227300584316f, 0.0023502050898969173f, 0.007314315997064114f, 0.006354358047246933f, 0.006961024831980467f, 0.007778595667332411f, 0.005147362593561411f, 0.0054997834376990795f, 0.005324947647750378f, 0.009975861757993698f, 0.008635924197733402f, 0.011323745362460613f, 0.010631103068590164f, 0.037193190306425095f, 0.0262262225151062f, 0.009235280565917492f, 0.019092515110969543f, 0.006575088948011398f, 0.009568563662469387f, 0.012364402413368225f, 0.003419621614739299f, 0.01089558470994234f, 0.007916613481938839f, 0.007412380538880825f, 0.014321264810860157f, 0.013098582625389099f, 0.01400157529860735f, 0.0025191756431013346f, 0.007877250202000141f, 0.01288392674177885f, 0.008490923792123795f, 0.0029527286533266306f, 0.042682845145463943f, 0.014382927678525448f, 0.011100821197032928f, 0.00662490539252758f, 0.004130740184336901f, 0.01205393299460411f, 0.00793768372386694f, 0.03944803401827812f, 0.018512358888983727f, 0.01747501827776432f, 0.007728647906333208f, 0.006263313349336386f, 0.008265158161520958f, 0.005575763061642647f, 0.007118143606930971f, 0.015012423507869244f, 0.01365516148507595f, 0.0090570617467165f, 0.009555899538099766f, 0.015582526102662086f, 0.015866007655858994f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039997282437980175f, 0.007405694108456373f, 0.014907189644873142f, 0.008230471983551979f, 0.004868758842349052f, 0.01016202475875616f, 0.004970206413418055f, 0.02962462790310383f, 0.004818160552531481f, 0.008583025075495243f, 0.006258710287511349f, 0.003681901842355728f, 0.005067272111773491f, 0.007249730639159679f, 0.0033390659373253584f, 0.004828707315027714f, 0.005358878988772631f, 0.0070867231115698814f, 0.0039721583016216755f, 0.02140829525887966f, 0.005875615868717432f, 0.004531090147793293f, 0.010457607917487621f, 0.004132025875151157f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023754866560921073f, 0.0007319764117710292f, 0.0008782638469710946f, 0.0007275941898114979f, 0.0008496507070958614f, 0.00016645679716020823f, 0.0006244341493584216f, 0.0001770465896697715f, 0.0003872835368383676f, 0.00015135602734517306f, 0.0004745929909404367f, 0.0002763047523330897f, 0.0007964664837345481f, 0.0003745989815797657f, 0.0005763875669799745f, 0.0003743451670743525f, 0.00030484466697089374f, 0.0010231098858639598f, 0.00035196830867789686f, 0.000296383019303903f, 0.0004317548591643572f, 0.00043860828736796975f, 0.0005324978847056627f, 0.0006920021842233837f, 0.0005789833376184106f, 0.0003801746934186667f, 0.0004627020098268986f, 0.00041636283276602626f, 0.00039903083234094083f, 0.0003844339807983488f, 0.0004810405953321606f, 0.0004336550773587078f, 0.0007299008429981768f, 0.0005445072893053293f, 0.0007558195502497256f, 0.0007137370994314551f, 0.000726182188373059f, 0.0006682834937237203f, 0.00029816210735589266f, 0.00046318775275722146f, 0.0005744601949118078f, 0.0004483768134377897f, 0.0007966122939251363f, 0.00019067697576247156f, 0.000582990818656981f, 0.00010605370334815234f, 0.00047422878560610116f, 0.0003702781395986676f, 0.000503361748997122f, 0.00045234267599880695f, 0.0007045419770292938f, 0.0006359380204230547f, 0.0005761082866229117f, 0.0001598340750206262f, 0.0005701966001652181f, 0.0007087229751050472f, 0.0004095326876267791f, 0.0005155473481863737f, 0.0004055626632180065f, 0.0006033297395333648f, 0.0005522941355593503f, 0.0002394645125605166f, 0.0005893774214200675f, 0.0005820774240419269f, 0.0005056345253251493f, 0.00045542101725004613f, 0.0004366209323052317f, 0.0005397084751166403f, 0.0007753692334517837f, 0.0007549691363237798f, 0.0006715765921398997f, 0.001002659322693944f, 0.0005799902719445527f, 0.00031562906224280596f, 0.0005496367230080068f, 0.0007276232354342937f, 0.0005260281614027917f, 0.00023210991639643908f, 0.0002394816547166556f, 0.0004154877387918532f, 0.000405045720981434f, 0.0008070144103839993f, 0.0003501986793708056f, 0.00021750302403233945f, 0.0003722640103660524f, 0.0005843173712491989f, 0.0006184482481330633f, 0.0007299110293388367f, 0.0006344699067994952f, 0.00035552590270526707f, 0.00046929929521866143f, 0.0008169718203134835f, 0.0004351954848971218f, 0.0003921698371414095f, 0.00157188531011343f, 0.0007295819232240319f, 0.0006070180679671466f, 0.00021225678210612386f, 0.0006943648913875222f, 0.0004592790501192212f, 0.0003763205313589424f, 0.0004641024279408157f, 0.0005295724258758128f, 0.0003179592313244939f, 0.0006904358742758632f, 0.000547383853700012f, 0.000656157557386905f, 0.000682376732584089f, 0.00038170479820109904f, 0.0006120977341197431f, 0.00037866743514314294f, 0.00029052101308479905f, 0.0004549591103568673f, 0.0008207959472201765f, 0.0004961580270901322f, 0.00026834008167497814f, 0.0006976217264309525f, 0.00032841452048160136f, 0.0004053180164191872f, 0.0003486288187559694f, 0.0007512604352086782f, 0.0008808195707388222f, 0.00040995440213009715f, 0.0006652423762716353f, 0.0004659533151425421f, 0.00034999754279851913f, 0.0007547126733697951f, 0.0007606350700370967f, 0.00040940020699054003f, 0.001066488679498434f, 0.0004961088416166604f, 0.0004448320250958204f, 0.0005022297264076769f, 0.000607794732786715f, 0.0004251536447554827f, 0.00033127577626146376f, 0.0008579499553889036f, 0.0009712210157886147f, 0.001249828259460628f, 0.0006753678317181766f, 0.0004456347960513085f, 0.00023862590023782104f, 0.0004198273236397654f, 0.0004930354189127684f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014679444022476673f, 0.01116878166794777f, 0.0030550851952284575f, 0.005101720802485943f, 0.0036934097297489643f, 0.02063450589776039f, 0.011679157614707947f, 0.013926825486123562f, 0.005487317685037851f, 0.016176220029592514f, 0.0048767211847007275f, 0.020608527585864067f, 0.020785123109817505f, 0.0044711558148264885f, 0.00749997328966856f, 0.016597583889961243f, 0.029188988730311394f, 0.016355162486433983f, 0.023693371564149857f, 0.022167082875967026f, 0.02485782839357853f, 0.007084177806973457f, 0.012799526564776897f, 0.011916563846170902f, 0.005835274234414101f, 0.012887381948530674f, 0.014673926867544651f, 0.013827291317284107f, 0.017925499007105827f, 0.006623835302889347f, 0.008732317946851254f, 0.007592699956148863f, 0.009514370933175087f, 0.005209246650338173f, 0.004211857449263334f, 0.00832586083561182f, 0.0076970867812633514f, 0.01684723049402237f, 0.019756611436605453f, 0.01749693602323532f, 0.010667553171515465f, 0.00966467522084713f, 0.009328550659120083f, 0.014159959740936756f, 0.005279622506350279f, 0.007807814981788397f, 0.005759837571531534f, 0.01230785995721817f, 0.014694362878799438f, 0.017219722270965576f, 0.008099736645817757f, 0.011359209194779396f, 0.006930622272193432f, 0.019433848559856415f, 0.003756601130589843f, 0.008242889307439327f, 0.007410331629216671f, 0.01902291737496853f, 0.006118801422417164f, 0.00651873042806983f, 0.009606027975678444f, 0.009972872212529182f, 0.004237676039338112f, 0.004771581385284662f, 0.015402075834572315f, 0.013146989047527313f, 0.005474740639328957f, 0.004488514270633459f, 0.006081319414079189f, 0.004064629320055246f, 0.007333565969020128f, 0.004471735563129187f, 0.013583973050117493f, 0.009493974037468433f, 0.005755765829235315f, 0.00261477823369205f, 0.022159960120916367f, 0.006534619256854057f, 0.01551591046154499f, 0.007949890568852425f, 0.010707490146160126f, 0.009744779206812382f, 0.017478343099355698f, 0.009934953413903713f, 0.01631292700767517f, 0.007833334617316723f, 0.0096407076343894f, 0.0064298235811293125f, 0.0017891275929287076f, 0.012048015370965004f, 0.01825718767940998f, 0.004545662086457014f, 0.0063072191551327705f, 0.005861263256520033f, 0.011310623958706856f, 0.0024642148055136204f, 0.010526936501264572f, 0.016971800476312637f, 0.008097978308796883f, 0.009361295029520988f, 0.012102938257157803f, 0.013909289613366127f, 0.03520997613668442f, 0.03131721913814545f, 0.007049938663840294f, 0.0036040921695530415f, 0.008560827001929283f, 0.009241867810487747f, 0.009202762506902218f, 0.010171489790081978f, 0.010725126601755619f, 0.009825879707932472f, 0.015310019254684448f, 0.009556475095450878f, 0.009888766333460808f, 0.013896352611482143f, 0.006009915377944708f, 0.00894220918416977f, 0.008711216039955616f, 0.02719074673950672f, 0.019959617406129837f, 0.010236116126179695f, 0.006439016666263342f, 0.01914208196103573f, 0.026781823486089706f, 0.019887547940015793f, 0.003658861853182316f, 0.006210207939147949f, 0.006823084317147732f, 0.004744696896523237f, 0.00917329266667366f, 0.008912891149520874f, 0.0031422595493495464f, 0.0064039165154099464f, 0.010801177471876144f, 0.025121938437223434f, 0.0061210631392896175f, 0.008675686083734035f, 0.020136650651693344f, 0.00555524742230773f, 0.011223684065043926f, 0.015563827008008957f, 0.018076298758387566f, 0.006337663624435663f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00605746079236269f, 0.006618704181164503f, 0.01880469173192978f, 0.006541956681758165f, 0.00780083704739809f, 0.008207501843571663f, 0.007069039158523083f, 0.038919124752283096f, 0.005465226713567972f, 0.00897750910371542f, 0.005349886137992144f, 0.0037055430002510548f, 0.009141706861555576f, 0.013102782890200615f, 0.0058362651616334915f, 0.004798505920916796f, 0.006801902782171965f, 0.004578536842018366f, 0.007678252644836903f, 0.02607550472021103f, 0.0065446216613054276f, 0.005170414224267006f, 0.009179617278277874f, 0.005679783411324024f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005878520314581692f, 0.000283417000900954f, 0.0007926388643682003f, 0.0011468720622360706f, 0.001037751673720777f, 0.0014270280953496695f, 0.0005953071522526443f, 0.0005985682946629822f, 0.0005018364172428846f, 0.0008084594155661762f, 0.0003625742101576179f, 0.0006050685769878328f, 0.0012350535253062844f, 0.00033471855567768216f, 0.0003830137720797211f, 0.0006140994955785573f, 0.00020829957793466747f, 0.0005434311460703611f, 0.0005336821777746081f, 0.0008486307342536747f, 0.0005647112848237157f, 0.0009807997848838568f, 0.0009334607748314738f, 0.00029033023747615516f, 0.0004337193095125258f, 0.0008055837824940681f, 0.0007528857095167041f, 0.0005138525739312172f, 0.000599841121584177f, 0.0004988821456208825f, 0.00017628766363486648f, 0.0005613864632323384f, 0.0004424596263561398f, 0.0004128270666114986f, 0.0003296614158898592f, 0.000303372711641714f, 0.0009404293959960341f, 0.0004761765885632485f, 0.0006221463554538786f, 0.0005757465842179954f, 0.00121893675532192f, 0.00030563518521375954f, 0.0006277672364376485f, 0.00031553159351460636f, 0.0010869824327528477f, 0.001547107007354498f, 0.0008025700808502734f, 0.0007252785726450384f, 0.0006943251355551183f, 0.000533721991814673f, 0.0003024742181878537f, 0.0009589017136022449f, 0.0006035944097675383f, 0.00038972197216935456f, 0.00042328733252361417f, 0.00024343492987100035f, 0.0005331379361450672f, 0.0007042865618132055f, 0.00030171178514137864f, 0.0008745912928134203f, 0.0007377016008831561f, 0.0004259888955857605f, 0.0004779556766152382f, 0.0006480286829173565f, 0.0007460989872924984f, 0.0008066730806604028f, 0.000790222140494734f, 0.00034573901211842895f, 0.0005987717304378748f, 0.0005069618346169591f, 0.0007780013256706297f, 0.0003221779188606888f, 0.0005791637231595814f, 0.0004383318591862917f, 0.00022904554498381913f, 0.0006253478932194412f, 0.0005617225542664528f, 0.0004954118048772216f, 0.00038429631968028843f, 0.0014775170711800456f, 0.0006534179556183517f, 0.0005285333027131855f, 0.0009392192005179822f, 0.00043443244067020714f, 0.0010347733041271567f, 0.0002571607183199376f, 0.000591305666603148f, 0.0006536117289215326f, 0.0003563105419743806f, 0.00028027661028318107f, 0.00030805522692389786f, 0.0010572801111266017f, 0.000496496562846005f, 0.0008453121990896761f, 0.0006783424760214984f, 0.0007134186453185976f, 0.0005148999043740332f, 0.0006129369721747935f, 0.0010813364060595632f, 0.00041673268424347043f, 0.0011069822357967496f, 0.0005613166722469032f, 0.000951819762121886f, 0.0008689470705576241f, 0.00099387695081532f, 0.00045081364805810153f, 0.000393845810322091f, 0.0005268900422379375f, 0.00020837952615693212f, 0.0007457221508957446f, 0.0008029865566641092f, 0.00037382752634584904f, 0.0007491292199119925f, 0.0005864215199835598f, 0.0008407256100326777f, 0.0006788592436350882f, 0.0006177587201818824f, 0.001684201299212873f, 0.0007191511103883386f, 0.0002943500003311783f, 0.0007324523176066577f, 0.0007021946366876364f, 0.00028891616966575384f, 0.000498154025990516f, 0.00019296270329505205f, 0.0006433820235542953f, 0.0001987736759474501f, 0.0008511428022757173f, 0.0005682113114744425f, 0.0003871953231282532f, 0.0004133244219701737f, 0.0005217317957431078f, 0.0005898582166992128f, 0.0007970843580551445f, 0.0005351761938072741f, 0.00027022341964766383f, 0.0006732816691510379f, 0.0003981435438618064f, 0.0008889136370271444f, 0.0009135321015492082f, 0.0007261318969540298f, 0.0003232891031075269f, 0.0001995380880543962f, 0.00039649440441280603f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0030549042858183384f, 0.005270378664135933f, 0.006058754399418831f, 0.004700976889580488f, 0.009391951374709606f, 0.004164968151599169f, 0.007526009809225798f, 0.007015991490334272f, 0.007170245982706547f, 0.004513462074100971f, 0.010687111876904964f, 0.006598364561796188f, 0.005200657062232494f, 0.009768685325980186f, 0.016635339707136154f, 0.005909279454499483f, 0.017903760075569153f, 0.013262473046779633f, 0.01592947356402874f, 0.009228549897670746f, 0.005234797950834036f, 0.010436058044433594f, 0.004755605012178421f, 0.015976691618561745f, 0.018221288919448853f, 0.01481296494603157f, 0.009392487816512585f, 0.00972040556371212f, 0.007317116484045982f, 0.007811609655618668f, 0.027726026251912117f, 0.008579165674746037f, 0.007318992633372545f, 0.007223188877105713f, 0.014048692770302296f, 0.016546649858355522f, 0.0026876968331635f, 0.00951923243701458f, 0.010968998074531555f, 0.01651332713663578f, 0.006151969078928232f, 0.012017914094030857f, 0.002879907377064228f, 0.008395722135901451f, 0.004922750871628523f, 0.004497600253671408f, 0.009407784789800644f, 0.004233927931636572f, 0.006553277838975191f, 0.007616278249770403f, 0.009618713520467281f, 0.008319406770169735f, 0.01067535113543272f, 0.005580774042755365f, 0.006919235922396183f, 0.01924038678407669f, 0.006321580149233341f, 0.005535672884434462f, 0.01502676960080862f, 0.006674944423139095f, 0.0026338575407862663f, 0.010387695394456387f, 0.010046185925602913f, 0.004528576508164406f, 0.004904978442937136f, 0.0034069132525473833f, 0.007993889041244984f, 0.010220254771411419f, 0.004530020523816347f, 0.005404312163591385f, 0.004950372502207756f, 0.01618763990700245f, 0.00613057054579258f, 0.010013737715780735f, 0.023825667798519135f, 0.02847980707883835f, 0.006497884634882212f, 0.007924576289951801f, 0.02953309938311577f, 0.002101046498864889f, 0.024006329476833344f, 0.013622721657156944f, 0.006991351954638958f, 0.011226309463381767f, 0.006866236217319965f, 0.017967158928513527f, 0.003778466721996665f, 0.006722775753587484f, 0.00862184539437294f, 0.018863361328840256f, 0.00965504813939333f, 0.006339686457067728f, 0.004789101891219616f, 0.004247826989740133f, 0.006303267553448677f, 0.002885327208787203f, 0.004549017641693354f, 0.01589067652821541f, 0.016468148678541183f, 0.010198530741035938f, 0.014225050806999207f, 0.003982354421168566f, 0.006027547176927328f, 0.01419738121330738f, 0.008141282014548779f, 0.009888354688882828f, 0.01539704017341137f, 0.007550142705440521f, 0.02828902192413807f, 0.0042357658967375755f, 0.005596477072685957f, 0.005920620635151863f, 0.00526955584064126f, 0.004689814522862434f, 0.010572725906968117f, 0.009629079140722752f, 0.009913410991430283f, 0.003479595994576812f, 0.007796524092555046f, 0.011372528970241547f, 0.011276488192379475f, 0.006280885078012943f, 0.015953920781612396f, 0.008533278480172157f, 0.037002239376306534f, 0.009666342288255692f, 0.01810968667268753f, 0.003025981830433011f, 0.008085479959845543f, 0.01297089271247387f, 0.00972835160791874f, 0.008505899459123611f, 0.005118860397487879f, 0.009363356977701187f, 0.011027463711798191f, 0.006999744102358818f, 0.009452778846025467f, 0.01194776501506567f, 0.0030752329621464014f, 0.005139667075127363f, 0.005940632428973913f, 0.019194133579730988f, 0.016252830624580383f, 0.007388533558696508f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010201995261013508f, 0.004922478925436735f, 0.018837936222553253f, 0.010228517465293407f, 0.006896029692143202f, 0.007385038770735264f, 0.004365608096122742f, 0.02303524874150753f, 0.004216544795781374f, 0.006967616267502308f, 0.00605266448110342f, 0.0037004027981311083f, 0.005760294385254383f, 0.008279301226139069f, 0.0038819306064397097f, 0.004305263049900532f, 0.005403495859354734f, 0.01326296478509903f, 0.006142990197986364f, 0.024319538846611977f, 0.005144244059920311f, 0.004511899780482054f, 0.006640596315264702f, 0.004484010394662619f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_40_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006150907138362527f, 0.0009825677843764424f, 0.0003967561642639339f, 0.0008248527301475406f, 0.0004602064727805555f, 0.0007701494032517076f, 0.0005700949113816023f, 0.0008672191761434078f, 0.0007804404012858868f, 0.0008603879832662642f, 0.0003497892466839403f, 0.0013612544862553477f, 0.0006746185827068985f, 0.0006658920901827514f, 0.000733821711037308f, 0.0007519307546317577f, 0.000915129785425961f, 0.00042666203808039427f, 0.0008098179823718965f, 0.0005570277571678162f, 0.0005793292075395584f, 0.0003652570303529501f, 0.0005221012979745865f, 0.0008820108487270772f, 0.0004889213596470654f, 0.0010292791994288564f, 0.0006111973780207336f, 0.0009363529970869422f, 0.0007034223526716232f, 0.0010276588145643473f, 0.000649465131573379f, 0.001288252999074757f, 0.0007812475669197738f, 0.0007795190904289484f, 0.0007885759114287794f, 0.0006843028240837157f, 0.001147422706708312f, 0.0008767602266743779f, 0.000435881462180987f, 0.0008453080663457513f, 0.0004912861622869968f, 0.0007845854270271957f, 0.0008985294261947274f, 0.0006167658139020205f, 0.0012270502047613263f, 0.001038620132021606f, 0.0006466537597589195f, 0.0005323633085936308f, 0.0007903233636170626f, 0.0005643432959914207f, 0.0004976550117135048f, 0.0006671958253718913f, 0.000959674536716193f, 0.0006250800215639174f, 0.0007112750899977982f, 0.0009704995900392532f, 0.0006736911018379033f, 0.0008170699584297836f, 0.0010407792869955301f, 0.000582203094381839f, 0.0004650011542253196f, 0.0007995972991921008f, 0.0006405660533346236f, 0.0007046631071716547f, 0.0006641776999458671f, 0.0007418685127049685f, 0.0006158935138955712f, 0.00023754616267979145f, 0.000478971196571365f, 0.0006345041911117733f, 0.0006428722408600152f, 0.0006885406910441816f, 0.000548016163520515f, 0.0005643779295496643f, 0.0006111921975389123f, 0.0009424790041521192f, 0.0002530803030822426f, 0.0007166513823904097f, 0.0006799317197874188f, 0.0006830212660133839f, 0.00031080617918632925f, 0.000606970745138824f, 0.000751602347008884f, 0.0002328775735804811f, 0.00042114368989132345f, 0.0012333288323134184f, 0.0005976273096166551f, 0.0008580292924307287f, 0.0007372577674686909f, 0.0006708306609652936f, 0.0008705827058292925f, 0.0008567656623199582f, 0.000860069296322763f, 0.0011036880314350128f, 0.0004791410465259105f, 0.0008112131617963314f, 0.0010909326374530792f, 0.0016261932905763388f, 0.0007362182950600982f, 0.0005597778945229948f, 0.0005409646546468139f, 0.0006636645412072539f, 0.00039316629408858716f, 0.0010322274174541235f, 0.0005580194410867989f, 0.0008787713013589382f, 0.0009665168472565711f, 0.0007054400630295277f, 0.00043326104059815407f, 0.0008997652330435812f, 0.0006237689522095025f, 0.0006912355893291533f, 0.0006732349866069853f, 0.001351205981336534f, 0.0006653851014561951f, 0.0013903341023251414f, 0.0007378174923360348f, 0.0007263123407028615f, 0.0006292045582085848f, 0.0005964586162008345f, 0.00043745088623836637f, 0.0011018164223060012f, 0.0008290789555758238f, 0.0003421090659685433f, 0.0009013625094667077f, 0.0005559819983318448f, 0.0008538864203728735f, 0.0008350738207809627f, 0.000685901555698365f, 0.0008705336367711425f, 0.0006084360065869987f, 0.0007768509676679969f, 0.0005854303017258644f, 0.0005429190350696445f, 0.0003253780887462199f, 0.0008069569012150168f, 0.0010786402272060513f, 0.0012175479205325246f, 0.0005596227711066604f, 0.0006986113148741424f, 0.0005422477843239903f, 0.0010198834352195263f, 0.0007564764237031341f, 0.0010837599402293563f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029378668405115604f, 0.005974737927317619f, 0.006984129082411528f, 0.0035738591104745865f, 0.006969102192670107f, 0.004163928795605898f, 0.010377802886068821f, 0.0024077461566776037f, 0.006710275076329708f, 0.0048086391761898994f, 0.010996083728969097f, 0.0032236017286777496f, 0.003159788902848959f, 0.010029791854321957f, 0.009340103715658188f, 0.006610744632780552f, 0.00534891989082098f, 0.003143521025776863f, 0.003672008402645588f, 0.003376950277015567f, 0.008815005421638489f, 0.007811523508280516f, 0.010228955186903477f, 0.003999683540314436f, 0.010464747436344624f, 0.0038222423754632473f, 0.0040042889304459095f, 0.010401474311947823f, 0.007109654601663351f, 0.0038234766107052565f, 0.0015261631924659014f, 0.004205984529107809f, 0.007476548198610544f, 0.0036025794688612223f, 0.0011714305728673935f, 0.003538429504260421f, 0.0034247899893671274f, 0.004198684822767973f, 0.0055440692231059074f, 0.005529081914573908f, 0.005551071837544441f, 0.004516973625868559f, 0.007477662526071072f, 0.00987513829022646f, 0.005885670892894268f, 0.002268066629767418f, 0.0025939163751900196f, 0.011071152053773403f, 0.0051942989230155945f, 0.006196295842528343f, 0.0025159032084047794f, 0.008646354079246521f, 0.003717208979651332f, 0.008276327513158321f, 0.001798801007680595f, 0.006326618604362011f, 0.01048921886831522f, 0.006389014422893524f, 0.0014960069674998522f, 0.008382825180888176f, 0.01118803583085537f, 0.003111290279775858f, 0.006726123858243227f, 0.006321912165731192f, 0.004690744914114475f, 0.0025439998134970665f, 0.0038328608497977257f, 0.01100115105509758f, 0.006415065843611956f, 0.008538899011909962f, 0.007856883108615875f, 0.00961560569703579f, 0.0033219396136701107f, 0.00497074518352747f, 0.005295211914926767f, 0.0027041968423873186f, 0.010924783535301685f, 0.005294514819979668f, 0.006754056550562382f, 0.004977535922080278f, 0.01356851402670145f, 0.0076889763586223125f, 0.0025003752671182156f, 0.0146408686414361f, 0.006648448295891285f, 0.004412948153913021f, 0.003671640297397971f, 0.0029563650023192167f, 0.007471287157386541f, 0.00790577381849289f, 0.001484642387367785f, 0.003003139514476061f, 0.0017579717095941305f, 0.006885603070259094f, 0.008741607889533043f, 0.00645052595064044f, 0.002389292698353529f, 0.006901306100189686f, 0.0028278687968850136f, 0.008696135133504868f, 0.010966123081743717f, 0.005054187029600143f, 0.009023088030517101f, 0.007139703258872032f, 0.0037895748391747475f, 0.00611497275531292f, 0.0031520321499556303f, 0.006592449266463518f, 0.008022582158446312f, 0.0018519358709454536f, 0.009722735732793808f, 0.0034554810263216496f, 0.005320191849023104f, 0.0067152101546525955f, 0.008372225798666477f, 0.0021094707772135735f, 0.004612092860043049f, 0.005099839996546507f, 0.009637550450861454f, 0.002668562578037381f, 0.022315703332424164f, 0.0019500472117215395f, 0.002042582957074046f, 0.016562802717089653f, 0.006073919590562582f, 0.003772218246012926f, 0.0067016854882240295f, 0.005683965049684048f, 0.0031122856307774782f, 0.005027499049901962f, 0.0033980917651206255f, 0.0030394908972084522f, 0.0075882175005972385f, 0.006414896808564663f, 0.012835524044930935f, 0.009348398074507713f, 0.0043274457566440105f, 0.005387976765632629f, 0.0037191123701632023f, 0.00788046047091484f, 0.012019413523375988f, 0.0035214617382735014f, 0.005423010792583227f, 0.0018378952518105507f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01303776167333126f, 0.017933087423443794f, 0.01226895209401846f, 0.011307962238788605f, 0.015932802110910416f, 0.013693023473024368f, 0.016024839133024216f, 0.010500277392566204f, 0.01139986701309681f, 0.014677142724394798f, 0.010510193184018135f, 0.012766970321536064f, 0.011209421791136265f, 0.01401553489267826f, 0.012245153076946735f, 0.015061440877616405f, 0.012068190611898899f, 0.014252017252147198f, 0.012302624061703682f, 0.01110837608575821f, 0.016991199925541878f, 0.02047867327928543f, 0.012225989252328873f, 0.01180193480104208f, 0.0152390506118536f, 0.02646428905427456f, 0.011435721069574356f, 0.011865630745887756f, 0.010777706280350685f, 0.015190670266747475f, 0.017213979735970497f, 0.01428381260484457f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003654086613096297f, 0.0022268490865826607f, 0.0009418668341822922f, 0.00041777719161473215f, 0.0007341487798839808f, 0.0012948907678946853f, 0.0005568175110965967f, 0.0008127799956128001f, 0.00047496965271420777f, 0.0010595633648335934f, 0.001970963552594185f, 0.0004483171505853534f, 0.0004727934719994664f, 0.00035451503936201334f, 0.0006839990965090692f, 0.0005737432511523366f, 0.0008994695381261408f, 0.0010244834702461958f, 0.0007921200594864786f, 0.0010908609256148338f, 0.0011153530795127153f, 0.0007362723699770868f, 0.0009628567495383322f, 0.00044241483556106687f, 0.0023593336809426546f, 0.00040720481774769723f, 0.0008236383437179029f, 0.0007486934773623943f, 0.000768483558204025f, 0.0011078228708356619f, 0.0003921118041034788f, 0.0005094033549539745f, 0.0011460285168141127f, 0.0023219657596200705f, 0.0007144085830077529f, 0.0008883229456841946f, 0.0015013632364571095f, 0.0004898009938187897f, 0.0005432639154605567f, 0.001320762443356216f, 0.0008327484829351306f, 0.0008319431799463928f, 0.0011380090145394206f, 0.0007277908152900636f, 0.0006223901873454452f, 0.001289299107156694f, 0.0008208490326069295f, 0.0009078371222130954f, 0.0008944388246163726f, 0.000662823673337698f, 0.000981341116130352f, 0.0008444758132100105f, 0.00048290903214365244f, 0.00083963293582201f, 0.0007828848902136087f, 0.0007880930788815022f, 0.0006466899649240077f, 0.0009479809086769819f, 0.0005029229796491563f, 0.0011626789346337318f, 0.0005838588112965226f, 0.0008084020228125155f, 0.0009269221336580813f, 0.0009238286293111742f, 0.0010105733526870608f, 0.001093264203518629f, 0.0008282889029942453f, 0.0006847945041954517f, 0.0009820812847465277f, 0.0007180780521593988f, 0.0018725768895819783f, 0.0010810645762830973f, 0.0013285541208460927f, 0.0005267062224447727f, 0.0004037113976664841f, 0.0009651731816120446f, 0.0010260193375870585f, 0.0005991359939798713f, 0.0012289354344829917f, 0.001070536789484322f, 0.0013419868191704154f, 0.0004538274079095572f, 0.001429528696462512f, 0.00047754720435477793f, 0.0003276366333011538f, 0.0009942407486960292f, 0.0008489085012115538f, 0.0002929773472715169f, 0.00027525765472091734f, 0.0008772775763645768f, 0.00030476751271635294f, 0.0006545805372297764f, 0.00047299099969677627f, 0.00044980726670473814f, 0.0007499969215132296f, 0.0006559222238138318f, 0.0010933264857158065f, 0.001397807733155787f, 0.000691756431479007f, 0.0006652994779869914f, 0.0005437118234112859f, 0.0003829867928288877f, 0.0014685695059597492f, 0.00045165582560002804f, 0.0011606923071667552f, 0.0007045411039143801f, 0.000536060833837837f, 0.0005036203074268997f, 0.00037774493102915585f, 0.00030400475952774286f, 0.0010523275705054402f, 0.0006736379582434893f, 0.0006703464314341545f, 0.0007540329825133085f, 0.0006166305392980576f, 0.0003529874375090003f, 0.0008532525971531868f, 0.0002856414648704231f, 0.0007991762831807137f, 0.0007253671064972878f, 0.00044001356582157314f, 0.0008685901411809027f, 0.0006043051253072917f, 0.00037428829818964005f, 0.0009611091227270663f, 0.0008577260305173695f, 0.0007820061291567981f, 0.000882698514033109f, 0.00044923962559551f, 0.00019886798691004515f, 0.000955889408942312f, 0.0010994942858815193f, 0.0003689098230097443f, 0.000452112581115216f, 0.00032464158721268177f, 0.0006432365626096725f, 0.0011308708926662803f, 0.00036845990689471364f, 0.0005586096085608006f, 0.0007365363417193294f, 0.001177978003397584f, 0.0006265798583626747f, 0.0003659499925561249f, 0.0014956097584217787f, 0.0009645771933719516f, 0.0008905610884539783f, 0.00038479053182527423f, 0.001155695179477334f, 0.0006822072900831699f, 0.0010069170966744423f, 0.0005351037252694368f, 0.0028652718756347895f, 0.0008123877923935652f, 0.0005640335730277002f, 0.0009081923635676503f, 0.00042744074016809464f, 0.0012969024246558547f, 0.0004887391114607453f, 0.0012049202341586351f, 0.0012565422803163528f, 0.0010097550693899393f, 0.0007339371368288994f, 0.0008489825413562357f, 0.000931336369831115f, 0.0005267684464342892f, 0.0009181994828395545f, 0.0015628279652446508f, 0.0007374814595095813f, 0.0010466980747878551f, 0.000948962289839983f, 0.00080691440962255f, 0.0011040082899853587f, 0.0005881097167730331f, 0.0008010455640032887f, 0.0010746173793449998f, 0.0009583591599948704f, 0.0009161725174635649f, 0.0007791817770339549f, 0.001109166070818901f, 0.0008062591659836471f, 0.001983263995498419f, 0.0019848986994475126f, 0.00078230892540887f, 0.0008235275745391846f, 0.0004958506906405091f, 0.000726844766177237f, 0.000864059547893703f, 0.00030446788878180087f, 0.00040787033503875136f, 0.0009699402726255357f, 0.0012608987744897604f, 0.0002928937610704452f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.047280922532081604f, 0.00464929873123765f, 0.0024155371356755495f, 0.0073586986400187016f, 0.014389471150934696f, 0.004191878717392683f, 0.007793400902301073f, 0.003590779146179557f, 0.010789868421852589f, 0.008681599982082844f, 0.0030955877155065536f, 0.010818871669471264f, 0.012499133124947548f, 0.016691187396645546f, 0.0041083721444010735f, 0.007597561459988356f, 0.017669038847088814f, 0.0022648863960057497f, 0.0070395697839558125f, 0.00942634604871273f, 0.014277264475822449f, 0.0071173785254359245f, 0.0051455446518957615f, 0.009851853363215923f, 0.003751451149582863f, 0.005167254712432623f, 0.009348846971988678f, 0.009994369931519032f, 0.006069841794669628f, 0.002820933237671852f, 0.012834499590098858f, 0.007716780994087458f, 0.002475431654602289f, 0.003379835281521082f, 0.00958254374563694f, 0.008184771053493023f, 0.0021075797267258167f, 0.006547539494931698f, 0.00983437243849039f, 0.008975788950920105f, 0.01479221973568201f, 0.002138114534318447f, 0.001958314562216401f, 0.004444013349711895f, 0.010940258391201496f, 0.0022882167249917984f, 0.006587473209947348f, 0.005882641766220331f, 0.015107628889381886f, 0.002875739010050893f, 0.007492826785892248f, 0.012087884359061718f, 0.00579373212531209f, 0.006555819883942604f, 0.009032194502651691f, 0.006082430016249418f, 0.0037374873645603657f, 0.009551729075610638f, 0.006550735794007778f, 0.016582757234573364f, 0.012238521128892899f, 0.003393706167116761f, 0.009378763847053051f, 0.0065451376140117645f, 0.012210400775074959f, 0.0038934610784053802f, 0.0015708871651440859f, 0.009390013292431831f, 0.009918693453073502f, 0.005178721155971289f, 0.011052155867218971f, 0.005972445476800203f, 0.012615746818482876f, 0.008131556212902069f, 0.010443422012031078f, 0.006544817239046097f, 0.005403805058449507f, 0.0026443128008395433f, 0.010039187967777252f, 0.011192870326340199f, 0.0017015374032780528f, 0.01668577268719673f, 0.004436900839209557f, 0.01356535218656063f, 0.01257755421102047f, 0.0051964689046144485f, 0.0017048692097887397f, 0.02298637107014656f, 0.020068276673555374f, 0.0032324776984751225f, 0.016551552340388298f, 0.005876611918210983f, 0.03733598440885544f, 0.008335843682289124f, 0.006999393459409475f, 0.014908264391124249f, 0.0013295012759044766f, 0.001340530114248395f, 0.008352819830179214f, 0.003946739714592695f, 0.004644778557121754f, 0.008410024456679821f, 0.007010573986917734f, 0.013974263332784176f, 0.0069197434931993484f, 0.006287955678999424f, 0.014952228404581547f, 0.008036014623939991f, 0.014301983639597893f, 0.0061605460941791534f, 0.010638274252414703f, 0.008959569968283176f, 0.004797819536179304f, 0.0056326366029679775f, 0.014379345811903477f, 0.01529793068766594f, 0.014909452758729458f, 0.014117260463535786f, 0.010971388779580593f, 0.010496447794139385f, 0.009806276299059391f, 0.0077064745128154755f, 0.012781312689185143f, 0.010181546211242676f, 0.006650250870734453f, 0.004677377641201019f, 0.010995021089911461f, 0.009563158266246319f, 0.008283287286758423f, 0.02524567022919655f, 0.002648858120664954f, 0.008171262219548225f, 0.013397988863289356f, 0.018371889367699623f, 0.015767298638820648f, 0.006282326299697161f, 0.0036115585826337337f, 0.018157318234443665f, 0.013838555663824081f, 0.012632181867957115f, 0.006349356845021248f, 0.011250928975641727f, 0.019092118367552757f, 0.004311056807637215f, 0.008221704512834549f, 0.006013873033225536f, 0.013798341155052185f, 0.010397966019809246f, 0.0050584133714437485f, 0.011213758029043674f, 0.006675035692751408f, 0.003106016432866454f, 0.00786508433520794f, 0.009866341017186642f, 0.01030751783400774f, 0.01079544611275196f, 0.0055367229506373405f, 0.007570577785372734f, 0.00755828944966197f, 0.003794382093474269f, 0.002693412359803915f, 0.005125061608850956f, 0.012133334763348103f, 0.006176566239446402f, 0.01327542494982481f, 0.012152697890996933f, 0.0014356839237734675f, 0.020266402512788773f, 0.0032810179982334375f, 0.011516214348375797f, 0.008081634528934956f, 0.0015880299033597112f, 0.012512704357504845f, 0.008294460363686085f, 0.004938971251249313f, 0.0017716259462758899f, 0.004786962177604437f, 0.01332338061183691f, 0.01096300594508648f, 0.013637874275445938f, 0.004373764619231224f, 0.005781447980552912f, 0.011861531063914299f, 0.011525186710059643f, 0.0071905311197042465f, 0.010072754696011543f, 0.005432484205812216f, 0.009973125532269478f, 0.009023651480674744f, 0.004157784394919872f, 0.0020205669570714235f, 0.015100731514394283f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0038242824375629425f, 0.004543221089988947f, 0.006646124646067619f, 0.005168990232050419f, 0.0046652029268443584f, 0.005286220461130142f, 0.005689685698598623f, 0.012313933111727238f, 0.014215606264770031f, 0.017426662147045135f, 0.004450263921171427f, 0.011668923310935497f, 0.004695703275501728f, 0.01546990592032671f, 0.0059691304340958595f, 0.0036801507230848074f, 0.015193707309663296f, 0.004280731547623873f, 0.008286001160740852f, 0.005353518296033144f, 0.0063743917271494865f, 0.018883975222706795f, 0.01272050105035305f, 0.013420812785625458f, 0.013262033462524414f, 0.011259200051426888f, 0.01432140450924635f, 0.0052427686750888824f, 0.004308011848479509f, 0.005014642141759396f, 0.009147397242486477f, 0.004999084863811731f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_47_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00038382361526601017f, 0.00042873117490671575f, 0.00037247923319227993f, 0.000555243925191462f, 0.00030438313842751086f, 0.0004839663452003151f, 0.0006617378094233572f, 0.0009137928718701005f, 0.0006268214783631265f, 0.0007373362896032631f, 0.0005337926559150219f, 0.0007060308125801384f, 0.0007289128843694925f, 0.00046421607839874923f, 0.0008141492144204676f, 0.00034881371539086103f, 0.0008540136041119695f, 0.0006387194734998047f, 0.0009536432917229831f, 0.000955890049226582f, 0.0002853608166333288f, 0.0003772081690840423f, 0.0008028735173866153f, 0.0006231390871107578f, 0.0001862070639617741f, 0.0004634767828974873f, 0.000711059954483062f, 0.0006440668948926032f, 0.0006283958209678531f, 0.0006874691462144256f, 0.000687477586325258f, 0.0010703389998525381f, 0.0003454245161265135f, 0.000285873917164281f, 0.00047125507262535393f, 0.0012007454643025994f, 0.00031907728407531977f, 0.0005440489039756358f, 0.0006694452604278922f, 0.0005620180163532495f, 0.00040686663123779f, 0.0007377658039331436f, 0.0009081677417270839f, 0.00022378006542567164f, 0.0007542007369920611f, 0.0006018573185428977f, 0.0003623956872615963f, 0.0006526430952362716f, 0.0009484236943535507f, 0.0010627413867041469f, 0.0009044589824043214f, 0.0007659400580450892f, 0.00032977788941934705f, 0.0012137379962950945f, 0.000728845305275172f, 0.0007785456255078316f, 0.0006350787589326501f, 0.00028331816429272294f, 0.00047828088281676173f, 0.0006960222381167114f, 0.0006275263731367886f, 0.0008112927316688001f, 0.000666439940687269f, 0.0007794483099132776f, 0.0005754745216108859f, 0.0004485753015615046f, 0.0007151716272346675f, 0.0006362691055983305f, 0.0005409200675785542f, 0.0010687350295484066f, 0.0003171866701450199f, 0.00021274159371387213f, 0.0008547640754841268f, 0.0004600465181283653f, 0.0001365889038424939f, 0.00022627341968473047f, 0.000266834074864164f, 0.00036924934829585254f, 0.0007571874302811921f, 0.0003146574308630079f, 0.000619969330728054f, 0.0005332849104888737f, 0.0004418960597831756f, 0.0005951071507297456f, 0.0005911829066462815f, 0.0007020661141723394f, 0.0011981495190411806f, 9.847354522207752e-05f, 0.0008022160036489367f, 0.0008381266961805522f, 0.0010309115750715137f, 0.0009147734381258488f, 0.0005591801018454134f, 0.0007890837150625885f, 0.00047409802209585905f, 0.0007685902528464794f, 0.0011101728305220604f, 0.0006585211376659572f, 0.000346721411915496f, 0.0007146949646994472f, 0.0008341355132870376f, 0.00026599023840390146f, 0.0010306589538231492f, 0.0007213707431219518f, 0.0010047355899587274f, 0.0003351164050400257f, 0.0008708300883881748f, 0.00043406934128142893f, 0.0006837842520326376f, 0.0007243781583383679f, 0.0005055792280472815f, 0.0008348313858732581f, 0.0007447277312166989f, 0.0006614807643927634f, 0.0007839769823476672f, 0.0009966654470190406f, 0.0002732959110289812f, 0.000990935368463397f, 0.000685185834299773f, 0.001055693719536066f, 0.0004024335939902812f, 0.0007144404808059335f, 0.000799379195086658f, 0.0007981364615261555f, 0.0005982360453344882f, 0.0007286123582161963f, 0.000317923171678558f, 0.001343396259471774f, 0.00022817081480752677f, 0.0011890263995155692f, 0.000794953724835068f, 0.0009176722960546613f, 0.0007054008892737329f, 0.00037633616011589766f, 0.0002751708962023258f, 0.00027889362536370754f, 0.0005511031486093998f, 0.0008541213464923203f, 0.0006978825549595058f, 0.0005125668249092996f, 0.0003519551537465304f, 0.00038954135379754007f, 0.0008274049614556134f, 0.0006829776684753597f, 0.0004564845294225961f, 0.0009447580086998641f, 0.0006136574666015804f, 0.000848058785777539f, 0.0008961748681031168f, 0.0007254211814142764f, 0.001327384146861732f, 0.0004652246134355664f, 0.0010513649322092533f, 0.0010002072667703032f, 0.0010836037108674645f, 0.0008257522713392973f, 0.0009621190256439149f, 0.0009013518574647605f, 0.0006009102216921747f, 0.00031086563831195235f, 0.0006319895619526505f, 0.00019656948279589415f, 0.0008771964348852634f, 0.0006306191207841039f, 0.0003503749321680516f, 0.0006160998600535095f, 0.000606867135502398f, 0.001024016528390348f, 0.0006088823429308832f, 0.0005570331704802811f, 0.0008992533548735082f, 0.00048431282630190253f, 0.0004351120151113719f, 0.001012452645227313f, 0.0007177922525443137f, 0.0004312202800065279f, 0.000323592423228547f, 0.0007146032294258475f, 0.0009875936666503549f, 0.0005657938891090453f, 0.0006035318365320563f, 0.0007594381459057331f, 0.0008731724228709936f, 0.00045014306670054793f, 0.0008879578090272844f, 0.00032376861781813204f, 0.00040903661283664405f, 0.0009638774790801108f, 0.0007249368354678154f, 0.0005811578594148159f, 0.0005438731168396771f, 0.0007591784815303981f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0076323640532791615f, 0.011606518179178238f, 0.02349180355668068f, 0.017240971326828003f, 0.008921640925109386f, 0.007939951494336128f, 0.011203264817595482f, 0.001501436228863895f, 0.008933227509260178f, 0.007779879495501518f, 0.003472417825832963f, 0.01163577288389206f, 0.004939479753375053f, 0.009827904403209686f, 0.009600717574357986f, 0.010504486970603466f, 0.0023189622443169355f, 0.008342781104147434f, 0.01103220321238041f, 0.011756318621337414f, 0.011164725758135319f, 0.00712791969999671f, 0.006373586133122444f, 0.0034197436179965734f, 0.010648488998413086f, 0.008846978656947613f, 0.013933765701949596f, 0.007458713371306658f, 0.005650905426591635f, 0.011702061630785465f, 0.005438888445496559f, 0.0026180159766227007f, 0.00711321085691452f, 0.021646080538630486f, 0.009570161812007427f, 0.00623673852533102f, 0.011225462891161442f, 0.016542011871933937f, 0.001956257037818432f, 0.006259523797780275f, 0.004403343889862299f, 0.008021929301321507f, 0.004008992109447718f, 0.004792004358023405f, 0.005264256615191698f, 0.004085138440132141f, 0.013850233517587185f, 0.011704834178090096f, 0.0060477121733129025f, 0.004495219327509403f, 0.004202692769467831f, 0.004632084630429745f, 0.008090593852102757f, 0.008853517472743988f, 0.009719686582684517f, 0.0051654307171702385f, 0.00792492926120758f, 0.013540038838982582f, 0.012474273331463337f, 0.0020068087615072727f, 0.0022300772834569216f, 0.00704445643350482f, 0.008239771239459515f, 0.0033894383814185858f, 0.009836278855800629f, 0.0037568756379187107f, 0.0097753731533885f, 0.0050885784439742565f, 0.01686202920973301f, 0.0027517101261764765f, 0.01553133875131607f, 0.02081371285021305f, 0.002879091538488865f, 0.009049477986991405f, 0.033595528453588486f, 0.008323997259140015f, 0.01213617529720068f, 0.005116700194776058f, 0.0018356736982241273f, 0.011787510477006435f, 0.008674772456288338f, 0.005571568850427866f, 0.008024751208722591f, 0.009794703684747219f, 0.012386824004352093f, 0.009966371580958366f, 0.004119396209716797f, 0.05840671434998512f, 0.011964752338826656f, 0.006670024711638689f, 0.0024673808366060257f, 0.004070803057402372f, 0.00871871318668127f, 0.0032012728042900562f, 0.007250613067299128f, 0.00689508905634284f, 0.006895032245665789f, 0.016179095953702927f, 0.019716517999768257f, 0.01846477761864662f, 0.006450034212321043f, 0.02245655283331871f, 0.01511302962899208f, 0.0064962017349898815f, 0.004480088595300913f, 0.02113918960094452f, 0.01182053703814745f, 0.009760838933289051f, 0.007552507799118757f, 0.0071190036833286285f, 0.0049859266728162766f, 0.0047818501479923725f, 0.006986618973314762f, 0.003944578114897013f, 0.010015955194830894f, 0.0034542952198535204f, 0.011265537701547146f, 0.005352452863007784f, 0.0016817532014101744f, 0.00738017400726676f, 0.005549719091504812f, 0.010528766550123692f, 0.004319703206419945f, 0.0055932095274329185f, 0.004040478728711605f, 0.010647604241967201f, 0.008513332344591618f, 0.0023319399915635586f, 0.009800460189580917f, 0.005766627844423056f, 0.00626519275829196f, 0.002609407529234886f, 0.004730657674372196f, 0.01179453544318676f, 0.017318272963166237f, 0.013126639649271965f, 0.010640022344887257f, 0.008080767467617989f, 0.0028188268188387156f, 0.0021435306407511234f, 0.0045616161078214645f, 0.006014424841850996f, 0.004022238310426474f, 0.005884112790226936f, 0.02332051284611225f, 0.00750656658783555f, 0.004606626927852631f, 0.006342951208353043f, 0.004624238703399897f, 0.003413588274270296f, 0.004465640988200903f, 0.010672548785805702f, 0.0023921048268675804f, 0.004715297371149063f, 0.007671356201171875f, 0.01087296660989523f, 0.010651507414877415f, 0.005265230778604746f, 0.0071202535182237625f, 0.020444627851247787f, 0.006478708237409592f, 0.010969343595206738f, 0.006407950073480606f, 0.009439676068723202f, 0.006874865386635065f, 0.004274803679436445f, 0.00567639572545886f, 0.013056247495114803f, 0.006570666097104549f, 0.008861267007887363f, 0.007177240680903196f, 0.01894782856106758f, 0.0072616334073245525f, 0.007530796807259321f, 0.0030045523308217525f, 0.006332981865853071f, 0.013439273461699486f, 0.007603819947689772f, 0.0030520835425704718f, 0.005007762927561998f, 0.0034235860221087933f, 0.005590467713773251f, 0.008394078351557255f, 0.007966181263327599f, 0.006864318624138832f, 0.015033643692731857f, 0.006931949406862259f, 0.004002672154456377f, 0.00855096336454153f, 0.005698089022189379f, 0.003771710442379117f, 0.0020516987424343824f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005443176254630089f, 0.0057284473441541195f, 0.01071915589272976f, 0.006772302091121674f, 0.006204579956829548f, 0.010661141015589237f, 0.0067681013606488705f, 0.011537839658558369f, 0.012530325911939144f, 0.01777602918446064f, 0.006016647908836603f, 0.015923405066132545f, 0.005118935834616423f, 0.015854790806770325f, 0.006724098231643438f, 0.004666498396545649f, 0.02175997942686081f, 0.005262621212750673f, 0.009491975419223309f, 0.005668627098202705f, 0.007475739810615778f, 0.020318686962127686f, 0.018817920237779617f, 0.012139390222728252f, 0.014022591523826122f, 0.012625180184841156f, 0.01246686652302742f, 0.006849466357380152f, 0.0047438181936740875f, 0.006751607172191143f, 0.008510776795446873f, 0.009694498032331467f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009513862314634025f, 0.0009057263960130513f, 0.0009184282971546054f, 0.0011355793103575706f, 0.0007057804032228887f, 0.0005935255903750658f, 0.0005598057759925723f, 0.0006904804613441229f, 0.0011041316902264953f, 0.0007424200884997845f, 0.0007091056322678924f, 0.0005276823067106307f, 0.000813388149254024f, 0.0008658075821585953f, 0.001101164729334414f, 0.00046201172517612576f, 0.0005662903422489762f, 0.0005004577687941492f, 0.0009098791633732617f, 0.0008126386092044413f, 0.0007538361824117601f, 0.00044213695218786597f, 0.0010981361847370863f, 0.0008504196302965283f, 0.001081583322957158f, 0.0009216021280735731f, 0.0007744009490124881f, 0.0006797394016757607f, 0.0007502702646888793f, 0.000958758348133415f, 0.0005969757330603898f, 0.0007117114728316665f, 0.000654028553981334f, 0.0007070577703416348f, 0.00038744756602682173f, 0.0006971720140427351f, 0.0007045961683616042f, 0.0011092639761045575f, 0.0006628002738580108f, 0.000850957294460386f, 0.0007362447213381529f, 0.0004847041273023933f, 0.0010213759960606694f, 0.0015114509733393788f, 0.0005763464723713696f, 0.0006038688006810844f, 0.0006495731067843735f, 0.0006303422851487994f, 0.00012165358202764764f, 0.0006365688168443739f, 0.000536867359187454f, 0.00059332704404369f, 0.0006240086513571441f, 0.000512725324369967f, 0.001328993123024702f, 0.0006335389916785061f, 0.0004980991361662745f, 0.0006199052440933883f, 0.0008336532628163695f, 0.000822574773337692f, 0.0011889387387782335f, 0.0008327302639372647f, 0.00113762600813061f, 0.0005726069794036448f, 0.0003237721393816173f, 0.0008877640939317644f, 0.0005773709854111075f, 0.0010572480969130993f, 0.0009752435726113617f, 0.0007885490776970983f, 0.0009283287799917161f, 0.0007609897875227034f, 0.0011225328780710697f, 0.0005248172674328089f, 0.00043793785152956843f, 0.0006796757224947214f, 0.0008492545457556844f, 0.001139167812652886f, 0.0003427014744374901f, 0.0007290019420906901f, 0.0009325401624664664f, 0.0006770436302758753f, 0.001033121021464467f, 0.0010523798409849405f, 0.0005408285651355982f, 0.0009263479732908309f, 0.0004893554141744971f, 0.0006859726272523403f, 0.0005129299242980778f, 0.0007593140471726656f, 0.0005448600859381258f, 0.0007756243576295674f, 0.0007529013091698289f, 0.0008276441949419677f, 0.000602720829192549f, 0.0007196816150099039f, 0.0004303421883378178f, 0.0006276255589909852f, 0.0006509199738502502f, 0.0005841419333592057f, 0.0006559753092005849f, 0.0006073149270378053f, 0.0007594682392664254f, 0.0006550138350576162f, 0.0006531207473017275f, 0.0010695145465433598f, 0.0012362609850242734f, 0.0007585162529721856f, 0.0007455531158484519f, 0.0007776201819069684f, 0.0007224855944514275f, 0.0008423712570220232f, 0.0007429723045788705f, 0.000557311053853482f, 0.0006242264644242823f, 0.0007438057800754905f, 0.0007751574739813805f, 0.0006178996409289539f, 0.0008141855942085385f, 0.0007928741979412735f, 0.0011419375659897923f, 0.0009303289698436856f, 0.0010215647052973509f, 0.0009312903275713325f, 0.0010131823364645243f, 0.0007055519381538033f, 0.0006904968176968396f, 0.000820166664198041f, 0.0006072353571653366f, 0.0008522539283148944f, 0.0011045082937926054f, 0.000538790482096374f, 0.0017283029155805707f, 0.0006230311701074243f, 0.0008309225086122751f, 0.0016119341598823667f, 0.000471282284706831f, 0.0008123409352265298f, 0.0007182565168477595f, 0.0007754035759717226f, 0.0007810572278685868f, 0.0005443647387437522f, 0.0007942108786664903f, 0.0006886202609166503f, 0.0007799054146744311f, 0.0008997871191240847f, 0.0006976748118177056f, 0.000905124528799206f, 0.0007755360566079617f, 0.0007129674195311964f, 0.0006639151833951473f, 0.0004809717938769609f, 0.0006741594988852739f, 0.0006039985455572605f, 0.0008216315764002502f, 0.0018407560419291258f, 0.000617636542301625f, 0.0006170791457407176f, 0.0008359758649021387f, 0.00044455306488089263f, 0.0007819071179255843f, 0.0009378010872751474f, 0.0009565424406901002f, 0.0006236726185306907f, 0.0009116994915530086f, 0.001447533373720944f, 0.0009124856442213058f, 0.00037097526364959776f, 0.0008149634231813252f, 0.00012847298057749867f, 0.0009761388064362109f, 0.0007900671334937215f, 0.0011807128321379423f, 0.0008930523181334138f, 0.00044633724610321224f, 0.00061304826522246f, 0.0007111967424862087f, 0.0004945564433000982f, 0.0006166069651953876f, 0.0006406963802874088f, 0.000831412326078862f, 0.0009970238897949457f, 0.000925121596083045f, 0.000516431697178632f, 0.00014138496771920472f, 0.0011738745961338282f, 0.0006250488804653287f, 0.0009041312150657177f, 0.0009128768579103053f, 0.0006313449121080339f, 0.0010564757976680994f, 0.0008063279674388468f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005199425853788853f, 0.004094801377505064f, 0.0031173292081803083f, 0.002877193968743086f, 0.0039737895131111145f, 0.004486665595322847f, 0.0031764493323862553f, 0.005240158643573523f, 0.0033360894303768873f, 0.00236852141097188f, 0.0026464262045919895f, 0.004313748795539141f, 0.0047653974033892155f, 0.003466783557087183f, 0.003137310268357396f, 0.004302437417209148f, 0.004696880467236042f, 0.003118928987532854f, 0.0024234706070274115f, 0.006241369992494583f, 0.004783284850418568f, 0.005849165376275778f, 0.0019482673378661275f, 0.004421267658472061f, 0.004960940685123205f, 0.004532292485237122f, 0.006054578814655542f, 0.004483618773519993f, 0.004592082463204861f, 0.003057473339140415f, 0.003252016380429268f, 0.004425322636961937f, 0.004322175867855549f, 0.0034217152278870344f, 0.005889575462788343f, 0.005815770477056503f, 0.004395391792058945f, 0.0037673504557460546f, 0.00694294786080718f, 0.0018381348345428705f, 0.003627620404586196f, 0.003154854057356715f, 0.0031694460194557905f, 0.004198022186756134f, 0.004447633866220713f, 0.005443056579679251f, 0.004073418211191893f, 0.0068391356617212296f, 0.020887186750769615f, 0.003152037039399147f, 0.0047218590043485165f, 0.002995923859998584f, 0.002855932107195258f, 0.004602455534040928f, 0.002007596893236041f, 0.0038974808994680643f, 0.005124254152178764f, 0.004902109038084745f, 0.0032744393683969975f, 0.002023995155468583f, 0.0033661879133433104f, 0.004197033122181892f, 0.003978946711868048f, 0.005159445106983185f, 0.003552369074895978f, 0.002431881846860051f, 0.0034653248731046915f, 0.004812088329344988f, 0.0032862802036106586f, 0.002028144197538495f, 0.004491426981985569f, 0.0026381227653473616f, 0.006279610097408295f, 0.005257871933281422f, 0.004698490258306265f, 0.003977510612457991f, 0.0037784932646900415f, 0.0035991910845041275f, 0.006730333901941776f, 0.003972368780523539f, 0.0037932414561510086f, 0.0026666363701224327f, 0.0046032024547457695f, 0.0060930075123906136f, 0.0051015825010836124f, 0.0031063666101545095f, 0.004315569531172514f, 0.004536787047982216f, 0.004594872239977121f, 0.0052713751792907715f, 0.006169380620121956f, 0.004460309166461229f, 0.006116876844316721f, 0.004212013445794582f, 0.0031324552837759256f, 0.0025809069629758596f, 0.003406995441764593f, 0.005278893746435642f, 0.004448923747986555f, 0.003529927460476756f, 0.004623455926775932f, 0.0036841647233814f, 0.0029481365345418453f, 0.004466571845114231f, 0.004284303169697523f, 0.005685972981154919f, 0.0055406056344509125f, 0.003794117597863078f, 0.002042714273557067f, 0.003687771502882242f, 0.006530905142426491f, 0.005181019194424152f, 0.004420336335897446f, 0.004107865039259195f, 0.005711809266358614f, 0.003261932637542486f, 0.0037095684092491865f, 0.004096389748156071f, 0.0042837089858949184f, 0.005640993360430002f, 0.004961108323186636f, 0.004075831733644009f, 0.006595426704734564f, 0.004641756881028414f, 0.0020738004241138697f, 0.0033456336241215467f, 0.002220942173153162f, 0.0034954522270709276f, 0.004002237226814032f, 0.004657421726733446f, 0.0033093143720179796f, 0.00365307810716331f, 0.002464236691594124f, 0.0027560500893741846f, 0.005977688357234001f, 0.001447149901650846f, 0.005468588322401047f, 0.002823567483574152f, 0.0029899408109486103f, 0.004073259420692921f, 0.003090940648689866f, 0.0029976549558341503f, 0.0034621618688106537f, 0.004382738843560219f, 0.003271062159910798f, 0.004936205223202705f, 0.0030704904347658157f, 0.005056840367615223f, 0.004654455464333296f, 0.003513839328661561f, 0.003900242270901799f, 0.00577737158164382f, 0.0026355795562267303f, 0.0036596893332898617f, 0.0032163807190954685f, 0.0024472002405673265f, 0.005052999127656221f, 0.004836986772716045f, 0.0029021273367106915f, 0.0031462775077670813f, 0.005702819675207138f, 0.0020339416805654764f, 0.0028166351839900017f, 0.0021903603337705135f, 0.0051728300750255585f, 0.0037724394351243973f, 0.0026085544377565384f, 0.005437539424747229f, 0.0017237912397831678f, 0.008394000120460987f, 0.00362119497731328f, 0.0026582051068544388f, 0.004818991757929325f, 0.0030166860669851303f, 0.0035981920082122087f, 0.00423418078571558f, 0.004568906035274267f, 0.005126012954860926f, 0.003264519851654768f, 0.00511973025277257f, 0.0025939950719475746f, 0.005191676318645477f, 0.004971669986844063f, 0.004195571411401033f, 0.0239038597792387f, 0.005210337229073048f, 0.004324917681515217f, 0.002722271019592881f, 0.0038124187849462032f, 0.003859970485791564f, 0.0027727424167096615f, 0.005055122077465057f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009535127319395542f, 0.008102224208414555f, 0.011105886660516262f, 0.007146470248699188f, 0.008564263582229614f, 0.009823639877140522f, 0.009032649919390678f, 0.006565830670297146f, 0.00783620961010456f, 0.007088548969477415f, 0.008163649588823318f, 0.007782917935401201f, 0.008052722550928593f, 0.01042854879051447f, 0.010570448823273182f, 0.008981866762042046f, 0.008572349324822426f, 0.008896443992853165f, 0.012308904901146889f, 0.008806664496660233f, 0.011192708276212215f, 0.012304648756980896f, 0.007767065893858671f, 0.009574806317687035f, 0.008133888244628906f, 0.009331769309937954f, 0.010419811122119427f, 0.010401037521660328f, 0.008220264688134193f, 0.010506385006010532f, 0.008991116657853127f, 0.009947367012500763f, 0.009033427573740482f, 0.00910587515681982f, 0.012289431877434254f, 0.010269628837704659f, 0.011106053367257118f, 0.006622843910008669f, 0.008329854346811771f, 0.012367935851216316f, 0.013255251571536064f, 0.008165120147168636f, 0.011317049153149128f, 0.011278774589300156f, 0.012923268601298332f, 0.007862331345677376f, 0.0075880479998886585f, 0.009934186935424805f, 0.006747180130332708f, 0.008776955306529999f, 0.007840791717171669f, 0.009253903292119503f, 0.0078016784973442554f, 0.01014153566211462f, 0.008764149621129036f, 0.006688473280519247f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004477972397580743f, 0.0013176704524084926f, 0.0007930932333692908f, 0.0006823724252171814f, 0.0007557503413408995f, 0.0007996151107363403f, 0.0006644698441959918f, 0.0006358927930705249f, 0.0006095648277550936f, 0.0006393988151103258f, 0.0005035637295804918f, 0.0004496687324717641f, 0.0008333961595781147f, 0.0003735278733074665f, 0.0006987964152358472f, 0.0005984317976981401f, 0.0008685777429491282f, 0.0012564064236357808f, 0.0008254952263087034f, 0.0011359913041815162f, 0.0007856311276555061f, 0.0008954675286076963f, 0.0004169348394498229f, 0.00012069130752934143f, 0.00033168739173561335f, 0.0007765778573229909f, 0.0009152036509476602f, 0.0005931219784542918f, 0.0002503681753296405f, 0.0005073303473182023f, 0.0003022666787728667f, 0.0003532051632646471f, 0.0007579541415907443f, 0.0005370691069401801f, 0.0007447822717949748f, 0.000297715567285195f, 0.0013426868245005608f, 0.000548197072930634f, 0.0005303172511048615f, 0.0010185096180066466f, 0.0006431370857171714f, 0.0006305098067969084f, 0.0005074661457911134f, 0.00100770965218544f, 0.0003843994054477662f, 0.0008758713956922293f, 0.0007408226956613362f, 0.0004410175315570086f, 0.0011487272568047047f, 0.0004128839646000415f, 0.0006779686082154512f, 0.0006963115883991122f, 0.00034850797965191305f, 0.0010530869476497173f, 0.0005711960839107633f, 0.0005878482479602098f, 0.0005177321727387607f, 0.0003310267929919064f, 0.0005380907678045332f, 0.0009974141139537096f, 0.0004993805778212845f, 0.000814627215731889f, 0.0005369552527554333f, 0.00041185211739502847f, 0.0003786097513511777f, 0.0006960943574085832f, 0.00048745927051641047f, 0.0003363388532306999f, 0.0009651098516769707f, 0.0005584756727330387f, 0.0004293345264159143f, 0.0006286308052949607f, 0.0007335273548960686f, 0.0004938933998346329f, 0.000919604382943362f, 0.0006209020502865314f, 0.0011373115703463554f, 0.00048342320951633155f, 0.0003652712912298739f, 0.00047873175935819745f, 0.0005321372300386429f, 0.0009235267643816769f, 0.0009739504312165082f, 0.0006873253732919693f, 0.0004052536969538778f, 0.0007684573065489531f, 0.0006185313104651868f, 0.0007579761440865695f, 0.0005285455263219774f, 0.0003860703727696091f, 0.0010640363907441497f, 0.0010858745081350207f, 0.00033672014251351357f, 0.0004528188146650791f, 0.0016096315812319517f, 0.0009175136801786721f, 0.0005957105313427746f, 0.0009338516974821687f, 0.00023129394685383886f, 0.0010674857767298818f, 0.001207128050737083f, 0.0004616201331373304f, 0.00037949453690089285f, 0.0006655778852291405f, 0.0010053401347249746f, 0.0010824629571288824f, 0.0004732880333904177f, 0.0007692105718888342f, 0.00106266257353127f, 0.0008987286128103733f, 0.0010660482803359628f, 0.0006240897346287966f, 0.0005116529646329582f, 0.0008091746713034809f, 0.0007606968865729868f, 0.0004577537183649838f, 0.0002515248488634825f, 0.0007538289646618068f, 0.0011597245465964079f, 0.0010515231406316161f, 0.0007466849638149142f, 0.0004447788232937455f, 0.0006569843972101808f, 0.001059995498508215f, 0.0005672706174664199f, 0.00046071401447989047f, 0.0010184195125475526f, 0.00032318028388544917f, 0.0014035525964573026f, 0.0005950680933892727f, 0.000938056327868253f, 0.0006734678172506392f, 0.0008870880701579154f, 0.0004302184679545462f, 0.0008919541724026203f, 0.0010314997052773833f, 0.0004671334754675627f, 0.0005887334118597209f, 0.00048823453835211694f, 0.0004099432553630322f, 0.000468050769995898f, 0.0005267118685878813f, 0.0009220829815603793f, 0.000502276758197695f, 0.0019017031881958246f, 0.0008915590005926788f, 0.0006583583308383822f, 0.0010700034908950329f, 0.00040516903391107917f, 0.0013193723279982805f, 0.0006511894753202796f, 0.0005584223545156419f, 0.0008224863559007645f, 0.0006708938162773848f, 0.00047758413711562753f, 0.00033772073220461607f, 0.0009251961018890142f, 0.0008464209386147559f, 0.0007182470289990306f, 0.0006164813530631363f, 0.0006592528661713004f, 0.0008045091526582837f, 0.0003804365114774555f, 0.0006675295298919082f, 0.0004489321436267346f, 0.0009720813832245767f, 0.0005175823462195694f, 0.0003167295944876969f, 0.00033936623367480934f, 0.0009832339128479362f, 0.0011622600723057985f, 0.0005993457743898034f, 0.00021890070638619363f, 0.00043373179505579174f, 0.0004213277134113014f, 0.0003183896478731185f, 0.0007157073123380542f, 0.0010046858806163073f, 0.0005836305790580809f, 0.0011211095843464136f, 0.000978299998678267f, 0.0004456300812307745f, 0.0009574805153533816f, 0.0011783592635765672f, 0.001111093908548355f, 0.001002567121759057f, 0.000976772396825254f, 0.0005062995478510857f, 0.0006978154415264726f, 0.00040599185740575194f, 0.0003635007597040385f, 0.0013105436228215694f, 0.0006824907613918185f, 0.000656705058645457f, 0.001482532825320959f, 0.0008924426510930061f, 0.0006454410613514483f, 0.0007699213456362486f, 0.0007508259732276201f, 0.0009898670250549912f, 0.0005699185421690345f, 0.001066436991095543f, 0.0008115286473184824f, 0.000494192645419389f, 0.000997096300125122f, 0.0008197998395189643f, 0.000503484916407615f, 0.001454656943678856f, 0.0006655695615336299f, 0.000654921808745712f, 0.0011144725140184164f, 0.0007618197123520076f, 0.0005751030403189361f, 0.0004265631432645023f, 0.001657972577959299f, 0.00037714504287578166f, 0.00021424595615826547f, 0.0007189910975284874f, 0.0006863930029794574f, 0.00060401571681723f, 0.0009454453829675913f, 0.0006099482998251915f, 0.000817261403426528f, 0.0007977726054377854f, 0.0006734142662025988f, 0.0007091621519066393f, 0.0005109503399580717f, 0.0008832954918034375f, 0.0007266786997206509f, 0.000577806553337723f, 0.00025699540856294334f, 0.0011012296890839934f, 0.00020083699200768024f, 0.0014971006894484162f, 0.0005024319980293512f, 0.0007606721483170986f, 0.0005785280372947454f, 0.000618344871327281f, 0.0008965934976004064f, 0.00070533761754632f, 0.001794581301510334f, 0.0005993651575408876f, 0.0005409414297901094f, 0.0006134664872661233f, 0.000591671618167311f, 0.0006396002136170864f, 0.0010841666953638196f, 0.0003343055141158402f, 0.0005575459799729288f, 0.0011643756879493594f, 0.0007589521119371057f, 0.001001533237285912f, 0.0006004392635077238f, 0.00015744537813588977f, 0.0010737664997577667f, 0.0006126523949205875f, 0.00039216314326040447f, 0.0009075017878785729f, 0.0009078299626708031f, 0.0006465851911343634f, 0.0006799467955715954f, 0.0009295684867538512f, 0.0009764248970896006f, 0.0009677773341536522f, 0.0004785784112755209f, 0.0005869847373105586f, 0.0008138725534081459f, 0.0008759190095588565f, 0.0009046048508025706f, 0.0004764413752127439f, 0.00032651948276907206f, 0.0006966666551306844f, 0.0003697564243339002f, 0.001153569552116096f, 0.00044990837341174483f, 0.0005205912166275084f, 0.0012327342992648482f, 0.0008751918794587255f, 0.00039242312777787447f, 0.0007641399861313403f, 0.000268093979684636f, 0.0009709543664939702f, 0.0005604737089015543f, 0.0008882189285941422f, 0.0008078941027633846f, 0.000488320249132812f, 0.0005518305697478354f, 0.0002851421304512769f, 0.0007088008569553494f, 0.0009486513445153832f, 0.0006718203076161444f, 0.000545723654795438f, 0.0005972218932583928f, 0.0004534577310550958f, 0.0007267938926815987f, 0.0005000804667361081f, 0.0006472792010754347f, 0.0005878856172785163f, 0.0010055270977318287f, 0.00047509337309747934f, 0.0008196380804292858f, 0.000525212730281055f, 0.0009286785498261452f, 0.0006319880485534668f, 0.0006347033777274191f, 0.0005589043139480054f, 0.0006925209891051054f, 0.000658592558465898f, 0.00039208366069942713f, 0.001004277728497982f, 0.0005247832741588354f, 0.0010161611717194319f, 0.0003007400955539197f, 0.00033169888774864376f, 0.0005059397662989795f, 0.0011856509372591972f, 0.0006318404339253902f, 0.000490441219881177f, 0.0005254569696262479f, 0.0011989326449111104f, 0.0004242942959535867f, 0.0006394904921762645f, 0.0005084219155833125f, 0.0005093383952043951f, 0.0009743307018652558f, 0.0005571714136749506f, 0.0004671872593462467f, 0.0005097179091535509f, 0.0012440625578165054f, 0.0012571885017678142f, 0.0006587306852452457f, 0.0005122193833813071f, 0.001154285273514688f, 0.0017263232730329037f, 0.0011968750040978193f, 0.0003757899394258857f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004981280770152807f, 0.008654067292809486f, 0.006502027623355389f, 0.01186247169971466f, 0.005828334949910641f, 0.005749703850597143f, 0.004360727500170469f, 0.008732864633202553f, 0.008208931423723698f, 0.007629203610122204f, 0.010299810208380222f, 0.009298699907958508f, 0.0020874927286058664f, 0.011620134115219116f, 0.006907789036631584f, 0.006525223609060049f, 0.009290431626141071f, 0.004139785189181566f, 0.006748676300048828f, 0.01007644459605217f, 0.004701158497482538f, 0.007364411372691393f, 0.00934545323252678f, 0.012764444574713707f, 0.012149136513471603f, 0.011449049226939678f, 0.009568169713020325f, 0.004813295789062977f, 0.014321899972856045f, 0.007842984050512314f, 0.00995638594031334f, 0.008846611715853214f, 0.005413671489804983f, 0.01709141582250595f, 0.008808818645775318f, 0.015223524533212185f, 0.01292939018458128f, 0.008590723387897015f, 0.00898075383156538f, 0.006253375671803951f, 0.011376778595149517f, 0.012080089189112186f, 0.008564628660678864f, 0.007772382814437151f, 0.019402140751481056f, 0.015056321397423744f, 0.007494068238884211f, 0.007235008757561445f, 0.0023513531778007746f, 0.009313932619988918f, 0.006861078552901745f, 0.0027972962707281113f, 0.009904390200972557f, 0.005985716357827187f, 0.008253230713307858f, 0.006948916241526604f, 0.007344122510403395f, 0.008452937938272953f, 0.005114487372338772f, 0.012548435479402542f, 0.013621503487229347f, 0.00653355848044157f, 0.013326447457075119f, 0.011060643941164017f, 0.023159267380833626f, 0.003731373930349946f, 0.011068525724112988f, 0.010322421789169312f, 0.003491166513413191f, 0.011680095456540585f, 0.013906612992286682f, 0.005660158582031727f, 0.0037680829409509897f, 0.013782759197056293f, 0.007601977791637182f, 0.007854210212826729f, 0.007946758531033993f, 0.005073280073702335f, 0.010632598772644997f, 0.007495795842260122f, 0.01752159185707569f, 0.011764097958803177f, 0.008913407102227211f, 0.00568919163197279f, 0.011771026067435741f, 0.003513141768053174f, 0.003088196739554405f, 0.0063111381605267525f, 0.009374366141855717f, 0.013460165821015835f, 0.009563847444951534f, 0.008968386799097061f, 0.005535766948014498f, 0.01645200327038765f, 0.009703129529953003f, 0.012266725301742554f, 0.008196706883609295f, 0.014784584753215313f, 0.01506002526730299f, 0.0037339136470109224f, 0.0037007227074354887f, 0.012037702836096287f, 0.00849107839167118f, 0.005832941271364689f, 0.006762043572962284f, 0.005765277426689863f, 0.007805985864251852f, 0.01291196420788765f, 0.00897266250103712f, 0.004474604036659002f, 0.01170368678867817f, 0.007361569907516241f, 0.0062104775570333f, 0.00197294307872653f, 0.007144446484744549f, 0.02006586082279682f, 0.020153101533651352f, 0.0051084705628454685f, 0.007548774126917124f, 0.009435208514332771f, 0.007104699034243822f, 0.00832893792539835f, 0.0065246992744505405f, 0.0033798273652791977f, 0.005981995724141598f, 0.011080019176006317f, 0.012164633721113205f, 0.01829841360449791f, 0.0028033521957695484f, 0.009743288159370422f, 0.006605483125895262f, 0.006378346122801304f, 0.003068455494940281f, 0.013588585890829563f, 0.008041152730584145f, 0.013404839672148228f, 0.01914988085627556f, 0.006861443631350994f, 0.007264659274369478f, 0.010675260797142982f, 0.009205052629113197f, 0.010128135792911053f, 0.0031864175107330084f, 0.008619784377515316f, 0.005580168217420578f, 0.004753141198307276f, 0.008043109439313412f, 0.00811726599931717f, 0.01197175681591034f, 0.003362279152497649f, 0.007557580713182688f, 0.004397934768348932f, 0.00451740063726902f, 0.0043434216640889645f, 0.011201715096831322f, 0.012400740757584572f, 0.010804717428982258f, 0.00801812019199133f, 0.008592571131885052f, 0.006689161527901888f, 0.007825441658496857f, 0.00583578459918499f, 0.011723232455551624f, 0.004714827984571457f, 0.007697198074311018f, 0.009026841260492802f, 0.009128022007644176f, 0.013150151818990707f, 0.009507454000413418f, 0.007073509972542524f, 0.004802970215678215f, 0.008599437773227692f, 0.015590164810419083f, 0.007802714593708515f, 0.010754283517599106f, 0.01392486970871687f, 0.006963798310607672f, 0.0022148462012410164f, 0.014369961805641651f, 0.013408481143414974f, 0.0049806018359959126f, 0.011776183731853962f, 0.0028140125796198845f, 0.0104880565777421f, 0.018114496022462845f, 0.007335714064538479f, 0.00722287455573678f, 0.004544264171272516f, 0.004993505775928497f, 0.014024912379682064f, 0.13749068975448608f, 0.009012574329972267f, 0.008776303380727768f, 0.009147459641098976f, 0.006716592703014612f, 0.006575808860361576f, 0.00494755944237113f, 0.004506153520196676f, 0.010687272995710373f, 0.008503217250108719f, 0.0077133490704f, 0.008124724961817265f, 0.005147491581737995f, 0.008944753557443619f, 0.003305537160485983f, 0.0065693240612745285f, 0.008146868087351322f, 0.00208429922349751f, 0.00748135382309556f, 0.0057543921284377575f, 0.002782000694423914f, 0.010510406456887722f, 0.005018002353608608f, 0.011915602721273899f, 0.008756694383919239f, 0.007867034524679184f, 0.014963241294026375f, 0.0032379645854234695f, 0.010310133919119835f, 0.00666982913389802f, 0.005272748414427042f, 0.007938122376799583f, 0.009508524090051651f, 0.007612640969455242f, 0.004900965373963118f, 0.005479708779603243f, 0.007758730091154575f, 0.0074234833009541035f, 0.0050279549323022366f, 0.007631159387528896f, 0.01129706110805273f, 0.003689012723043561f, 0.01414850726723671f, 0.0022933136206120253f, 0.01029787678271532f, 0.00619627395644784f, 0.009086934849619865f, 0.007428591139614582f, 0.002389919711276889f, 0.007325933314859867f, 0.014979499392211437f, 0.008274936117231846f, 0.007401272654533386f, 0.004594829399138689f, 0.005167481955140829f, 0.013647702522575855f, 0.00501176668331027f, 0.009606311097741127f, 0.010054459795355797f, 0.012953780591487885f, 0.0039575896225869656f, 0.0025942956563085318f, 0.009997754357755184f, 0.014175894670188427f, 0.006379497703164816f, 0.007782522588968277f, 0.01614227332174778f, 0.0015538472216576338f, 0.004641300532966852f, 0.010955670848488808f, 0.0056936657056212425f, 0.0077468352392315865f, 0.004913688637316227f, 0.0017684547929093242f, 0.00907656829804182f, 0.024486133828759193f, 0.008569787256419659f, 0.0057987309992313385f, 0.01104196347296238f, 0.009096796624362469f, 0.015529707074165344f, 0.0074291108176112175f, 0.008183646015822887f, 0.008502128534018993f, 0.008761602453887463f, 0.006594119593501091f, 0.01874963380396366f, 0.011738448403775692f, 0.008171026594936848f, 0.0066034821793437f, 0.014905299060046673f, 0.011471576988697052f, 0.0072174337692558765f, 0.015908436849713326f, 0.006354850251227617f, 0.008280159905552864f, 0.01008409634232521f, 0.010745934210717678f, 0.006528794765472412f, 0.01444973424077034f, 0.010487562976777554f, 0.00990847498178482f, 0.013092795386910439f, 0.008062646724283695f, 0.00771756935864687f, 0.008317656815052032f, 0.0050318799912929535f, 0.007533041760325432f, 0.012487867847084999f, 0.010130109265446663f, 0.004825970157980919f, 0.007468334399163723f, 0.006316099315881729f, 0.007761193439364433f, 0.006073686294257641f, 0.004470902495086193f, 0.007009740918874741f, 0.0044166818261146545f, 0.0068578519858419895f, 0.006253195460885763f, 0.010608500801026821f, 0.0057211825624108315f, 0.014376365579664707f, 0.009206688031554222f, 0.00794809777289629f, 0.015511687844991684f, 0.006225730758160353f, 0.01183983776718378f, 0.007217716425657272f, 0.0045443326234817505f, 0.015020813792943954f, 0.01165900006890297f, 0.012298247776925564f, 0.006182512734085321f, 0.01683317869901657f, 0.01242305338382721f, 0.009462944231927395f, 0.009055662900209427f, 0.005968847312033176f, 0.008005780167877674f, 0.009461870416998863f, 0.00749734602868557f, 0.007815759629011154f, 0.003390766680240631f, 0.012647822499275208f, 0.017318012192845345f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010947585105895996f, 0.008155073039233685f, 0.0046454002149403095f, 0.01151810958981514f, 0.008036036975681782f, 0.008220207877457142f, 0.009633964858949184f, 0.008200573734939098f, 0.0034267734736204147f, 0.01376306265592575f, 0.005430963356047869f, 0.004944419022649527f, 0.006966349668800831f, 0.0063274516724050045f, 0.003975479863584042f, 0.004851733800023794f, 0.011169503442943096f, 0.0036803975235670805f, 0.011041172780096531f, 0.005128099583089352f, 0.006851898040622473f, 0.006760973948985338f, 0.01280047558248043f, 0.009267759509384632f, 0.008348038420081139f, 0.006135175470262766f, 0.0048604789189994335f, 0.0032601335551589727f, 0.006475436966866255f, 0.0032982858829200268f, 0.00490764994174242f, 0.0036762927193194628f, 0.005882779136300087f, 0.004714421462267637f, 0.009801875799894333f, 0.005257186479866505f, 0.005752112250775099f, 0.004335782025009394f, 0.007948433980345726f, 0.003919293638318777f, 0.006507717538625002f, 0.0044499230571091175f, 0.006223906762897968f, 0.0049193548038601875f, 0.0035682502202689648f, 0.005210903473198414f, 0.009289314039051533f, 0.0037117116153240204f, 0.0030689069535583258f, 0.005076293833553791f, 0.004306989721953869f, 0.007160975132137537f, 0.004940486047416925f, 0.011627903208136559f, 0.005788369104266167f, 0.005456011276692152f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_59_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000777989684138447f, 0.0005557097611017525f, 0.0006032480159774423f, 0.0002783033123705536f, 0.0006923713372088969f, 0.00034935359144583344f, 0.0002554617531131953f, 0.0006050583906471729f, 0.0006389714544638991f, 0.0008246283396147192f, 0.00031861572642810643f, 0.00039120367728173733f, 0.00041036654147319496f, 0.00017772305000107735f, 0.0002728319668676704f, 0.0005170400836504996f, 0.0006062324973754585f, 0.0006894654361531138f, 0.0006246932898648083f, 0.0009299026569351554f, 0.0008387485286220908f, 0.0006854748353362083f, 0.000537018000613898f, 0.0008540143608115613f, 0.0005675360444001853f, 0.00273566460236907f, 0.0005047487211413682f, 0.000685524835716933f, 0.0004683127044700086f, 0.00015686244296375662f, 0.00028538054903037846f, 0.0006745135760866106f, 0.0007577185169793665f, 0.0002360018261242658f, 0.0004070191062055528f, 0.0004105517000425607f, 0.0009854277595877647f, 0.0007534443284384906f, 0.0004330447409301996f, 0.0009663745877332985f, 0.0007353586843237281f, 0.0007393831037916243f, 0.0005913221393711865f, 0.00052361172856763f, 0.0005700380424968898f, 0.0004144549311604351f, 0.00034363919985480607f, 0.0007398121524602175f, 0.0006066467612981796f, 0.0003617441398091614f, 0.00027945658075623214f, 0.0003582891367841512f, 0.0004473049775697291f, 0.0005014801863580942f, 0.0005665726494044065f, 0.0004187929444015026f, 0.0001905013486975804f, 0.0005487386370077729f, 0.0004463067161850631f, 0.0007063171360641718f, 0.000640900048892945f, 0.0003823612933047116f, 0.0006567181553691626f, 0.0006429804489016533f, 0.000773511768784374f, 0.00043961385381408036f, 0.0003858479321934283f, 0.0006739243981428444f, 0.0007310029468499124f, 0.0003136151353828609f, 0.00028466168441809714f, 0.0003768343012779951f, 0.0004581942339427769f, 0.0006905051413923502f, 0.0006786135490983725f, 0.0006848786142654717f, 0.0008918896201066673f, 0.0007887363899499178f, 0.0002660735044628382f, 0.0006675941403955221f, 0.0006495366105809808f, 0.0007183538982644677f, 0.0008036926737986505f, 0.0007118826033547521f, 0.000687727122567594f, 0.0004179571697022766f, 0.0005451158504001796f, 0.000792253646068275f, 0.0007849516696296632f, 0.00048610451631247997f, 0.0005600306903943419f, 0.0006530812242999673f, 0.0005576079129241407f, 0.0005795354954898357f, 0.0006498049478977919f, 0.0009178464533761144f, 0.00035040281363762915f, 0.00042824543197639287f, 0.00031076036975719035f, 0.0005380809889174998f, 0.0002336884499527514f, 0.0004053589655086398f, 0.00036598939914256334f, 0.00035371145349927247f, 0.0003780036058742553f, 0.0006660852814093232f, 0.0007524070679210126f, 0.0006805926677770913f, 0.00071305176243186f, 0.0005702025955542922f, 0.00045126600889489055f, 0.0006408590124920011f, 0.0007457548636011779f, 0.0015020756982266903f, 0.0005460036336444318f, 0.0004284334136173129f, 0.0005869591259397566f, 0.0006429451750591397f, 0.0007367850630544126f, 0.00033890953636728227f, 0.0005584913888014853f, 0.000901558028999716f, 0.00043767120223492384f, 0.0006426020991057158f, 0.00038066343404352665f, 0.0006386569002643228f, 0.00036458909744396806f, 0.00024246139219030738f, 0.0006001236033625901f, 0.0005362550728023052f, 0.0012437953846529126f, 0.000407461600843817f, 0.0007133212056942284f, 0.0003684459952637553f, 0.000704727484844625f, 0.0005864140694029629f, 0.0003246055857744068f, 0.0004640279512386769f, 0.00021035528334323317f, 0.0005738189211115241f, 0.0005453040939755738f, 0.00037064182106405497f, 0.0006422727601602674f, 0.0007396756554953754f, 0.0003837745462078601f, 0.0006894611869938672f, 0.0005730566335842013f, 0.0007837870507501066f, 0.00041775862337090075f, 0.0009075350826606154f, 0.0006464461330324411f, 0.0004547142016235739f, 0.0006951579707674682f, 0.000660139019601047f, 0.00015253362653311342f, 0.0006878755521029234f, 0.000996944261714816f, 0.0006471755914390087f, 0.00021974046831019223f, 0.0005798838101327419f, 0.00042599605512805283f, 0.0005409904406405985f, 0.00045550268259830773f, 0.0004403139464557171f, 0.0008579493151046336f, 0.0013440016191452742f, 0.0007250129710882902f, 0.0016626921715214849f, 0.0003337824600748718f, 0.0004498928028624505f, 0.0007607804145663977f, 0.000656567164696753f, 0.0008363013039343059f, 0.0007410785183310509f, 0.0005359294591471553f, 0.0008790253777988255f, 0.0007312785019166768f, 0.0003125893999822438f, 0.0004717888659797609f, 0.0004884364898316562f, 0.000528352742549032f, 0.0004652939678635448f, 0.000653990835417062f, 0.0007283117738552392f, 0.0008358314516954124f, 0.0005962260183878243f, 0.0007964764954522252f, 0.0006061311578378081f, 0.0007452726713381708f, 0.0006483004544861615f, 0.0009671663865447044f, 0.0013886543456465006f, 0.0006726158317178488f, 0.0008299170294776559f, 0.0011312835849821568f, 0.00037963909562677145f, 0.0012452206574380398f, 0.0006567758391611278f, 0.0006517010042443871f, 0.00032163012656383216f, 0.00017582236614543945f, 0.000761835603043437f, 0.0008261218317784369f, 0.0005168969510123134f, 0.0006587238749489188f, 0.0006368355243466794f, 0.0008124294690787792f, 0.0003718106308951974f, 0.0006510161911137402f, 0.00041671021608635783f, 0.0006809146143496037f, 0.0008880618261173368f, 0.0003478413273114711f, 0.0008973097428679466f, 0.00043747920426540077f, 0.0006190876010805368f, 0.00020957799279130995f, 0.0002116242831107229f, 0.0004584799462463707f, 0.0006394932279363275f, 0.0005959963309578598f, 0.0002064491418423131f, 0.0005257635493762791f, 0.0004701137950178236f, 0.00043933806591667235f, 0.0003452576929703355f, 0.0005505848675966263f, 0.0007630169857293367f, 0.0006344311987049878f, 0.000615054159425199f, 0.0008886954165063798f, 0.000665158499032259f, 0.0009838782716542482f, 0.0006648034905083477f, 0.0006485506892204285f, 0.000550319324247539f, 0.0006911980453878641f, 0.00036698280018754303f, 0.0007798889419063926f, 0.00022690162586513907f, 0.0002473305503372103f, 0.0006677721394225955f, 0.0009201853536069393f, 0.0009677843772806227f, 0.0006395678501576185f, 0.0009489195072092116f, 0.0008703728090040386f, 0.0009505843045189977f, 0.0004802517651114613f, 0.0006694638868793845f, 0.0006138620665296912f, 0.0004789775121025741f, 0.0008382602245546877f, 0.0007630932959727943f, 0.0008617718704044819f, 0.0007067385595291853f, 0.0003090987738687545f, 0.000732436659745872f, 0.0008800330688245595f, 0.0006178928888402879f, 0.0004519314388744533f, 0.00054416578495875f, 0.0004163395205978304f, 0.0005431217723526061f, 0.0007474063895642757f, 0.0003920264425687492f, 0.000869411276653409f, 0.0008378716302104294f, 0.0007417647284455597f, 0.0005974267260171473f, 0.00031992283766157925f, 0.0007012732676230371f, 0.001222100225277245f, 0.00031580255017615855f, 0.000985347549431026f, 0.0005327773396857083f, 0.001171905780211091f, 0.0005384577671065927f, 0.0012881335569545627f, 0.0005968197947368026f, 0.0006413088995032012f, 0.0007603277917951345f, 0.0008409982547163963f, 0.00040052650729194283f, 0.0008225221536122262f, 0.00024905067402869463f, 0.0007210550829768181f, 0.0005916958907619119f, 0.0011565728345885873f, 0.0007221827981993556f, 0.0005997918779030442f, 0.0010626275325194001f, 0.0007420470356009901f, 0.0005783363012596965f, 0.0007228010217659175f, 0.0008759006741456687f, 0.0006169063854031265f, 0.0006227457197383046f, 0.0006786868907511234f, 0.00038093916373327374f, 0.0005482819397002459f, 0.0004935680772177875f, 0.0005124477320350707f, 0.0006552624399773777f, 0.0007915806490927935f, 0.0003265242266934365f, 0.0009710672893561423f, 0.0004870662814937532f, 0.0009218303021043539f, 0.0006947425426915288f, 0.0007386086508631706f, 0.0003775948425754905f, 0.0006589978584088385f, 0.0006689275032840669f, 0.0014451700262725353f, 0.0006042581517249346f, 0.0006442503072321415f, 0.0009860239224508405f, 0.0006110454560257494f, 0.00020753721764776856f, 0.0004961150698363781f, 0.0005136954132467508f, 0.0009388618636876345f, 0.00022844356135465205f, 0.0005399662186391652f, 0.0006086966604925692f, 0.0005791372968815267f, 0.000489044701680541f, 0.00038380376645363867f, 0.0006363050197251141f, 0.000553352409042418f, 0.0002994299284182489f, 0.0006535905413329601f, 0.0006622610962949693f, 0.000484275195049122f, 0.0006120515754446387f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013577842153608799f, 0.00937715359032154f, 0.002705054124817252f, 0.00985556561499834f, 0.0052315653301775455f, 0.0076862298883497715f, 0.015205753967165947f, 0.008755244314670563f, 0.00525158504024148f, 0.008148972876369953f, 0.009106706827878952f, 0.005099643021821976f, 0.006669545080512762f, 0.009791377931833267f, 0.013610263355076313f, 0.008938366547226906f, 0.005166301969438791f, 0.004595105070620775f, 0.004258004017174244f, 0.003470661584287882f, 0.004012634977698326f, 0.023849207907915115f, 0.006546739488840103f, 0.006589161232113838f, 0.0014056524960324168f, 0.002243221737444401f, 0.007294307928532362f, 0.005932816304266453f, 0.01520528458058834f, 0.01379495020955801f, 0.0074899583123624325f, 0.0039047598838806152f, 0.000854646903462708f, 0.00688899215310812f, 0.006278053391724825f, 0.009160005487501621f, 0.0078412014991045f, 0.005839267745614052f, 0.006633881479501724f, 0.010210967622697353f, 0.032660212367773056f, 0.004832062404602766f, 0.014471202157437801f, 0.00802187155932188f, 0.01310853660106659f, 0.007452056743204594f, 0.011212964542210102f, 0.006750634405761957f, 0.0026625986211001873f, 0.008656134828925133f, 0.015670523047447205f, 0.007050787098705769f, 0.0064010475762188435f, 0.009208939038217068f, 0.003488823538646102f, 0.009368942119181156f, 0.07959485799074173f, 0.009924858808517456f, 0.012254443019628525f, 0.00409722002223134f, 0.0015586877707391977f, 0.014677637256681919f, 0.011423027142882347f, 0.0025466831866651773f, 0.005972452461719513f, 0.010003848932683468f, 0.0040549929253757f, 0.009490426629781723f, 0.00591288274154067f, 0.009786133654415607f, 0.009632323868572712f, 0.010118045844137669f, 0.00422705290839076f, 0.004453863017261028f, 0.007705933880060911f, 0.010830516926944256f, 0.007016504183411598f, 0.006946583744138479f, 0.011677972972393036f, 0.011547958478331566f, 0.009282556362450123f, 0.009552378207445145f, 0.006858944892883301f, 0.006600541993975639f, 0.004194933921098709f, 0.004851251374930143f, 0.01318260096013546f, 0.0012885290198028088f, 0.00427722092717886f, 0.00897158496081829f, 0.004016290884464979f, 0.0047342912293970585f, 0.006976609118282795f, 0.0028250636532902718f, 0.0183686763048172f, 0.007123698014765978f, 0.002139829099178314f, 0.012557310052216053f, 0.01501129474490881f, 0.002724197693169117f, 0.014410195872187614f, 0.003192279255017638f, 0.010782225988805294f, 0.017643077298998833f, 0.021171575412154198f, 0.0040603396482765675f, 0.008184397593140602f, 0.005444185808300972f, 0.006705557461827993f, 0.012538734823465347f, 0.006131833419203758f, 0.005683418828994036f, 0.006236270070075989f, 0.003782453713938594f, 0.007192986086010933f, 0.010954572819173336f, 0.006709324661642313f, 0.004066233057528734f, 0.010641905479133129f, 0.00474299443885684f, 0.013998900540173054f, 0.002315488178282976f, 0.002577356994152069f, 0.007727477233856916f, 0.0041006808169186115f, 0.0073089078068733215f, 0.0036836881190538406f, 0.011771484278142452f, 0.011032567359507084f, 0.010344263166189194f, 0.010881176218390465f, 0.010448310524225235f, 0.011166321113705635f, 0.03395671769976616f, 0.0045393058098852634f, 0.00557396886870265f, 0.005922459997236729f, 0.007752843666821718f, 0.025615723803639412f, 0.0035668793134391308f, 0.00870527047663927f, 0.015446887351572514f, 0.007109449710696936f, 0.0048950184136629105f, 0.013247762806713581f, 0.006509170401841402f, 0.013414116576313972f, 0.008667908608913422f, 0.008086716756224632f, 0.00381642859429121f, 0.007211072836071253f, 0.01747245155274868f, 0.0039367154240608215f, 0.009458247572183609f, 0.005831753369420767f, 0.010204421356320381f, 0.008728577755391598f, 0.008049329742789268f, 0.0059127225540578365f, 0.011042116209864616f, 0.0046033067628741264f, 0.008026788011193275f, 0.017399227246642113f, 0.011216426268219948f, 0.0045970166102051735f, 0.0033907066099345684f, 0.009312736801803112f, 0.005020459648221731f, 0.010381764732301235f, 0.00534580834209919f, 0.00507165165618062f, 0.011709296144545078f, 0.0013753031380474567f, 0.005905984900891781f, 0.0036264294758439064f, 0.006773941684514284f, 0.008844343945384026f, 0.004350082483142614f, 0.007445854600518942f, 0.00702593382447958f, 0.007639109622687101f, 0.010959725826978683f, 0.010984484106302261f, 0.0034702238626778126f, 0.007909218780696392f, 0.0024530452210456133f, 0.0067701335065066814f, 0.008571548387408257f, 0.004486312624067068f, 0.011925019323825836f, 0.008449834771454334f, 0.0039054714143276215f, 0.003171337768435478f, 0.003912349697202444f, 0.010539882816374302f, 0.005943342112004757f, 0.0079560037702322f, 0.006486313883215189f, 0.01427455898374319f, 0.022523732855916023f, 0.02214537002146244f, 0.008749299682676792f, 0.008684382773935795f, 0.005632816813886166f, 0.012316994369029999f, 0.005168913397938013f, 0.002817029831930995f, 0.011034737341105938f, 0.00831594504415989f, 0.007226158399134874f, 0.0029377604369074106f, 0.0030096147675067186f, 0.007449817378073931f, 0.0040135690942406654f, 0.011605042032897472f, 0.004162101540714502f, 0.013477267697453499f, 0.018803203478455544f, 0.007908233441412449f, 0.006318936124444008f, 0.008136480115354061f, 0.010499266907572746f, 0.01163738314062357f, 0.015545818954706192f, 0.009811239317059517f, 0.013423181138932705f, 0.014604960568249226f, 0.005226070526987314f, 0.0069653806276619434f, 0.0027261569630354643f, 0.0017196143744513392f, 0.009853004477918148f, 0.011356544680893421f, 0.005671125371009111f, 0.012336629442870617f, 0.00314899068325758f, 0.007687049452215433f, 0.0046986667439341545f, 0.005427882075309753f, 0.011006059125065804f, 0.016542935743927956f, 0.004391977097839117f, 0.0025179728399962187f, 0.007400484289973974f, 0.007860792800784111f, 0.007606460712850094f, 0.008332597091794014f, 0.007519104052335024f, 0.004636934958398342f, 0.010060043074190617f, 0.012743892148137093f, 0.0038863145746290684f, 0.018479429185390472f, 0.006017202045768499f, 0.0054670278914272785f, 0.01404917798936367f, 0.00651078624650836f, 0.0024038604460656643f, 0.005714473780244589f, 0.00932958535850048f, 0.011744437739253044f, 0.009767329320311546f, 0.015918735414743423f, 0.006861461326479912f, 0.007779358886182308f, 0.0141877057030797f, 0.006429890636354685f, 0.0031908724922686815f, 0.004827894736081362f, 0.007301763165742159f, 0.008729781955480576f, 0.006131551694124937f, 0.003018723800778389f, 0.03599629923701286f, 0.00799700990319252f, 0.004795270040631294f, 0.008266330696642399f, 0.009530031122267246f, 0.011428280733525753f, 0.0024193660356104374f, 0.006389682646840811f, 0.008228982798755169f, 0.0033104035537689924f, 0.005723440088331699f, 0.006282444577664137f, 0.015200491063296795f, 0.00751490518450737f, 0.006280442234128714f, 0.006956198718398809f, 0.004252675920724869f, 0.0019513106672093272f, 0.004520924296230078f, 0.011926621198654175f, 0.010940252803266048f, 0.0037079609464854f, 0.005919836927205324f, 0.008583394810557365f, 0.01036094594746828f, 0.01209939457476139f, 0.0032042257953435183f, 0.003536294912919402f, 0.015751497820019722f, 0.011878973804414272f, 0.00819435529410839f, 0.006286521442234516f, 0.011266418732702732f, 0.005020308308303356f, 0.00704636937007308f, 0.007065332494676113f, 0.004232237581163645f, 0.0062274024821817875f, 0.005223209038376808f, 0.00890339259058237f, 0.006558832246810198f, 0.005882674362510443f, 0.013852984644472599f, 0.00218389555811882f, 0.006410147529095411f, 0.007458155509084463f, 0.007561771664768457f, 0.010560235939919949f, 0.015032532624900341f, 0.005413693841546774f, 0.01818905770778656f, 0.003823252860456705f, 0.004698967561125755f, 0.005515355616807938f, 0.010564128868281841f, 0.00796247087419033f, 0.00326060620136559f, 0.006456542760133743f, 0.009293803945183754f, 0.010696380399167538f, 0.007366087753325701f, 0.004427506122738123f, 0.014673469588160515f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02611956000328064f, 0.009513875469565392f, 0.007924342527985573f, 0.014568115584552288f, 0.011116888374090195f, 0.011900371871888638f, 0.013375168666243553f, 0.01946166530251503f, 0.006973758805543184f, 0.02456892468035221f, 0.009387505240738392f, 0.006870597135275602f, 0.011625614017248154f, 0.009349559433758259f, 0.006340549793094397f, 0.007630535401403904f, 0.011094416491687298f, 0.007014007773250341f, 0.012227063067257404f, 0.007109716068953276f, 0.006881149020045996f, 0.006016701925545931f, 0.02750079706311226f, 0.017582817003130913f, 0.015991315245628357f, 0.009753957390785217f, 0.007765268441289663f, 0.008080614730715752f, 0.009134707041084766f, 0.00558182317763567f, 0.005557331722229719f, 0.008647902868688107f, 0.009991978295147419f, 0.008638941682875156f, 0.00752989761531353f, 0.008464875631034374f, 0.010684719309210777f, 0.007597507443279028f, 0.012299256399273872f, 0.009749256074428558f, 0.008072695694863796f, 0.008061962202191353f, 0.006675858981907368f, 0.006808992940932512f, 0.00784386321902275f, 0.008134953677654266f, 0.021168895065784454f, 0.009959309361875057f, 0.005304078571498394f, 0.00816880539059639f, 0.006898378487676382f, 0.008289240300655365f, 0.006724813487380743f, 0.009786088950932026f, 0.006803667638450861f, 0.0106377974152565f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_63_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00042004112037830055f, 0.0006103779305703938f, 0.0004989144508726895f, 0.00037517418968491256f, 0.0007269259658642113f, 0.00044252871884964406f, 0.0005033999914303422f, 0.0005867758300155401f, 0.0007337270071730018f, 0.0009101832401938736f, 0.0006896976847201586f, 0.0007140494417399168f, 0.000706125982105732f, 0.0004939204663969576f, 0.000836192280985415f, 0.0004775509878527373f, 0.0009343047277070582f, 0.0005963948788121343f, 0.0006445487961173058f, 0.0008296702872030437f, 0.0006427022162824869f, 0.0006222587544471025f, 0.0007071102154441178f, 0.0006162667996250093f, 0.001130864373408258f, 0.0005083094001747668f, 0.0005258926539681852f, 0.0006756408256478608f, 0.0009224986424669623f, 0.0005931431078352034f, 0.0005105652962811291f, 0.0008725402294658124f, 0.000562647997867316f, 0.0006101027247495949f, 0.0011285861255601048f, 0.0004228149482514709f, 0.0006584238144569099f, 0.0009158588363789022f, 0.000496204593218863f, 0.0005785731482319534f, 0.00048605198389850557f, 0.0006685761618427932f, 0.0007459821063093841f, 0.000535521365236491f, 0.0007393694249913096f, 0.0005721264751628041f, 0.0006102152983658016f, 0.0009100676979869604f, 0.000678700627759099f, 0.0004516620538197458f, 0.0007040746277198195f, 0.0007431972189806402f, 0.0008182774181477726f, 0.0005071940831840038f, 0.0006661590887233615f, 0.00045342944213189185f, 0.0007533102761954069f, 0.0007565711275674403f, 0.000525240262504667f, 0.0005287034437060356f, 0.0005126220057718456f, 0.00037054484710097313f, 0.0006658548954874277f, 0.00041114509804174304f, 0.0005768431001342833f, 0.0003837614203803241f, 0.0009744878625497222f, 0.0007366165518760681f, 0.0005491071497090161f, 0.0008211272652260959f, 0.00092969840625301f, 0.0008214391418732703f, 0.0006278397631831467f, 0.0004820814647246152f, 0.0008574023377150297f, 0.0006753114867024124f, 0.0005195698468014598f, 0.0007149307639338076f, 0.0010660113766789436f, 0.0006057655555196106f, 0.0006698512006551027f, 0.00053884502267465f, 0.0010134631302207708f, 0.0008116080425679684f, 0.000519858265761286f, 0.0006221398361958563f, 0.0006588801625184715f, 0.0005844935076311231f, 0.0006852339138276875f, 0.0006728831795044243f, 0.0005735908052884042f, 0.000517639797180891f, 0.000379249599063769f, 0.0007661564741283655f, 0.0005989707424305379f, 0.000470215076347813f, 0.0004854904254898429f, 0.0003077801375184208f, 0.0006372697534970939f, 0.0005279896431602538f, 0.00048183530452661216f, 0.0008742292411625385f, 0.0006186525570228696f, 0.0006986610242165625f, 0.0005203860346227884f, 0.0007517027552239597f, 0.0005495476652868092f, 0.0005622587050311267f, 0.0004119642253499478f, 0.0007806894718669355f, 0.00040993219590745866f, 0.0005518679972738028f, 0.0006010598735883832f, 0.0006100809550844133f, 0.0008310300763696432f, 0.0012672172160819173f, 0.00048744489322416484f, 0.0007360224844887853f, 0.0007460657507181168f, 0.0005717459134757519f, 0.0006814223015680909f, 0.0005133245140314102f, 0.0007056232425384223f, 0.0004572478646878153f, 0.0007773900870233774f, 0.00038956894422881305f, 0.0005798478377982974f, 0.0008035429636947811f, 0.00046624589595012367f, 0.0003963456838391721f, 0.0005557317053899169f, 0.0005860871751792729f, 0.0005157047999091446f, 0.0005531787755899131f, 0.0007654371438547969f, 0.0006733862101100385f, 0.0007691386854276061f, 0.0006703381659463048f, 0.000709529675077647f, 0.0005743505316786468f, 0.0005786398542113602f, 0.000497389817610383f, 0.0004496523761190474f, 0.0005080616101622581f, 0.0007049089181236923f, 0.000883944914676249f, 0.0008626903872936964f, 0.0010106473928317428f, 0.0008868166478350759f, 0.0006862911395728588f, 0.00045572425005957484f, 0.000708344450686127f, 0.0005488694296218455f, 0.0005632255342788994f, 0.000599640712607652f, 0.000598559679929167f, 0.0004870750999543816f, 0.0008455073111690581f, 0.0007218734244816005f, 0.00047105655539780855f, 0.0006652914453297853f, 0.0009813782526180148f, 0.0007694958476349711f, 0.0006048100767657161f, 0.0006674068863503635f, 0.0005890410393476486f, 0.0004680574929807335f, 0.0005880582612007856f, 0.000804300419986248f, 0.0007653289358131588f, 0.0005475138314068317f, 0.0009424975141882896f, 0.0007241606945171952f, 0.0008366590482182801f, 0.00046063095214776695f, 0.000840027816593647f, 0.0006113096023909748f, 0.0005504215369001031f, 0.0005787590052932501f, 0.000593068078160286f, 0.0006730701425112784f, 0.0005342505755834281f, 0.0004985429695807397f, 0.0006056544953025877f, 0.000680804078001529f, 0.0006654148455709219f, 0.0005384154501371086f, 0.00046512007247656584f, 0.00042872707126662135f, 0.0005661376053467393f, 0.0006603991496376693f, 0.0008217673166655004f, 0.0006406967877410352f, 0.0006648175185546279f, 0.00039212271803990006f, 0.0006235918845050037f, 0.0005850447341799736f, 0.000617019017226994f, 0.0006869397475384176f, 0.000632727809716016f, 0.0005341892247088253f, 0.0006149414693936706f, 0.0005247739609330893f, 0.0006997226737439632f, 0.0005806509288959205f, 0.0009599433396942914f, 0.0005289230612106621f, 0.0005961526767350733f, 0.0005476286169141531f, 0.0008356751059181988f, 0.0006233283784240484f, 0.0006304505513980985f, 0.0008569626370444894f, 0.0006840917048975825f, 0.0005395828047767282f, 0.0007175164064392447f, 0.0007053163717500865f, 0.0008849359001033008f, 0.0005554813542403281f, 0.0007086580153554678f, 0.0008373060263693333f, 0.0004818234301637858f, 0.0010957549093291163f, 0.0007178981904871762f, 0.000491828250233084f, 0.0006023483583703637f, 0.0004883420770056546f, 0.000486011675093323f, 0.000704356876667589f, 0.0008828667923808098f, 0.000874564575497061f, 0.0010364881018176675f, 0.0005415835767053068f, 0.00043805272434838116f, 0.0006052207318134606f, 0.0005872370093129575f, 0.000595679332036525f, 0.0006068385555408895f, 0.0009115582215599716f, 0.0005991666694171727f, 0.0005216689314693213f, 0.0006098839221522212f, 0.0005801260704174638f, 0.0010210114996880293f, 0.0006439731805585325f, 0.0005863202386535704f, 0.0007825308130122721f, 0.0005470449104905128f, 0.0009610822889953852f, 0.0005830834270454943f, 0.0005643212352879345f, 0.0005927909514866769f, 0.000801067566499114f, 0.0005579827120527625f, 0.0005641456809826195f, 0.0006078362930566072f, 0.0007094634347595274f, 0.0005696917069144547f, 0.0005974368541501462f, 0.0005952009814791381f, 0.0005119804991409183f, 0.0006517586880363524f, 0.0008783414377830923f, 0.0005421870155259967f, 0.000689169391989708f, 0.0004362237814348191f, 0.0005079861148260534f, 0.0007145331474021077f, 0.0002889562747441232f, 0.0007676499662920833f, 0.000731059699319303f, 0.0007603997364640236f, 0.0006878111162222922f, 0.00044929084833711386f, 0.0004322342574596405f, 0.0007794757839292288f, 0.0005150242941454053f, 0.0006165195954963565f, 0.0009202732471749187f, 0.0005938378744758666f, 0.0005726713570766151f, 0.00044542408431880176f, 0.0005656065768562257f, 0.000731605221517384f, 0.0008259105961769819f, 0.000574679346755147f, 0.0006984578212723136f, 0.000719372765161097f, 0.0006095317658036947f, 0.0008503800490871072f, 0.0006605794769711792f, 0.0005864933482371271f, 0.0005099488189443946f, 0.00037628953577950597f, 0.0005192540702410042f, 0.0005810794536955655f, 0.0006689641741104424f, 0.0006959129241295159f, 0.0004727860214188695f, 0.0004631176416296512f, 0.0008187142084352672f, 0.0004156265640631318f, 0.0006419485434889793f, 0.00032978036324493587f, 0.0007084679091349244f, 0.00039869677857495844f, 0.0005046807928010821f, 0.0006713166367262602f, 0.0007454127189703286f, 0.000716071983333677f, 0.000797282496932894f, 0.0005809097201563418f, 0.0006929434603080153f, 0.0005480515537783504f, 0.000639215693809092f, 0.000553180871065706f, 0.000528680277056992f, 0.0010651841294020414f, 0.0005049747414886951f, 0.0006548320525325835f, 0.000545957766007632f, 0.0006592684076167643f, 0.0006088989321142435f, 0.00048405956476926804f, 0.0007775590056553483f, 0.000899320759344846f, 0.0005333519075065851f, 0.0006219008937478065f, 0.0005475489306263626f, 0.0005091679049655795f, 0.0009853721130639315f, 0.00048299928312189877f, 0.0006369191687554121f, 0.0010591584723442793f, 0.0004907890106551349f, 0.0004752368840854615f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010801776312291622f, 0.005315135233104229f, 0.005258276592940092f, 0.00667059188708663f, 0.009484703652560711f, 0.00652276212349534f, 0.00757143460214138f, 0.007962552830576897f, 0.0072274236008524895f, 0.005014269147068262f, 0.007693303748965263f, 0.006105794571340084f, 0.0049117561429739f, 0.005377905908972025f, 0.0038969821762293577f, 0.006926213391125202f, 0.007700399961322546f, 0.0034500588662922382f, 0.009538424201309681f, 0.005951393861323595f, 0.0073572974652051926f, 0.005947674624621868f, 0.003574258415028453f, 0.006623477675020695f, 0.003370832884684205f, 0.007910131476819515f, 0.0038533953484147787f, 0.004509418737143278f, 0.004602822009474039f, 0.005145763512700796f, 0.0054129427298903465f, 0.0054442184045910835f, 0.008670782670378685f, 0.00495986919850111f, 0.0038232768420130014f, 0.0076715764589607716f, 0.005236434284597635f, 0.003420489141717553f, 0.004902793560177088f, 0.007344961166381836f, 0.006522969342768192f, 0.004690526053309441f, 0.0044036079198122025f, 0.006376986857503653f, 0.009222362190485f, 0.007176986895501614f, 0.0065654730424284935f, 0.003945576027035713f, 0.0035041675437241793f, 0.006830974016338587f, 0.003376597771421075f, 0.0046292622573673725f, 0.005237177014350891f, 0.0056809913367033005f, 0.004215209279209375f, 0.005991592071950436f, 0.0051430645398795605f, 0.003264734987169504f, 0.004076249431818724f, 0.0042344555258750916f, 0.006233994849026203f, 0.004616924561560154f, 0.004779994487762451f, 0.006836158223450184f, 0.006151024252176285f, 0.01067070197314024f, 0.004580347333103418f, 0.0042934296652674675f, 0.005315243732184172f, 0.007800474762916565f, 0.005681113339960575f, 0.004718223121017218f, 0.004875031765550375f, 0.008515678346157074f, 0.005741653963923454f, 0.0031816158443689346f, 0.006304258015006781f, 0.004983841907233f, 0.002895921003073454f, 0.0032222748268395662f, 0.004401841666549444f, 0.0050307372584939f, 0.003826550440862775f, 0.004281674046069384f, 0.0044625382870435715f, 0.00543835898861289f, 0.007056496571749449f, 0.004770456347614527f, 0.004774609114974737f, 0.009560110047459602f, 0.004417587071657181f, 0.007890203036367893f, 0.008111833594739437f, 0.0035059733781963587f, 0.0036414144560694695f, 0.005210816860198975f, 0.006030571646988392f, 0.003956710919737816f, 0.007216120138764381f, 0.009232317097485065f, 0.006654871162027121f, 0.002931885188445449f, 0.007457355037331581f, 0.004740537144243717f, 0.006729684770107269f, 0.004776704125106335f, 0.006878874730318785f, 0.005437957122921944f, 0.006630929186940193f, 0.004863929934799671f, 0.0045759063214063644f, 0.004554926883429289f, 0.006460052914917469f, 0.0047867861576378345f, 0.0033081769943237305f, 0.005351614207029343f, 0.0042747678235173225f, 0.004817945417016745f, 0.0029652316588908434f, 0.004783266689628363f, 0.00403275340795517f, 0.008094941265881062f, 0.006178080104291439f, 0.005762035027146339f, 0.0029423728119581938f, 0.004403102211654186f, 0.007521685212850571f, 0.006881157401949167f, 0.008419838733971119f, 0.004337700083851814f, 0.007226938381791115f, 0.00415807357057929f, 0.004751842003315687f, 0.004357314668595791f, 0.006348078139126301f, 0.004034061450511217f, 0.005223823711276054f, 0.005565345752984285f, 0.006848540157079697f, 0.0054399920627474785f, 0.0038081028033047915f, 0.0039007060695439577f, 0.00890012551099062f, 0.0036166927311569452f, 0.003178622107952833f, 0.010508086532354355f, 0.004182347096502781f, 0.004809480160474777f, 0.0053668878972530365f, 0.005044857040047646f, 0.007278775330632925f, 0.00631772680208087f, 0.007560815196484327f, 0.00619024271145463f, 0.005130971781909466f, 0.006258989684283733f, 0.005407080519944429f, 0.0031848058570176363f, 0.004550761077553034f, 0.008822149597108364f, 0.0022599927615374327f, 0.004855624865740538f, 0.006066232454031706f, 0.006254072301089764f, 0.004195605870336294f, 0.005120547953993082f, 0.007830039598047733f, 0.005101167131215334f, 0.0029670181684195995f, 0.005125356838107109f, 0.009763517417013645f, 0.0037053374107927084f, 0.0047845602966845036f, 0.0027749515138566494f, 0.004021738190203905f, 0.004114279989153147f, 0.00395166827365756f, 0.004444228485226631f, 0.006095575168728828f, 0.006310809403657913f, 0.004449719097465277f, 0.0034185985568910837f, 0.004567707423120737f, 0.005435346160084009f, 0.007850595749914646f, 0.0053137983195483685f, 0.006562106776982546f, 0.005635041277855635f, 0.005561919882893562f, 0.005495782010257244f, 0.0035091403406113386f, 0.005483656190335751f, 0.005587178748100996f, 0.005179983098059893f, 0.009076954796910286f, 0.00552792102098465f, 0.009685206227004528f, 0.004594421945512295f, 0.0024738586507737637f, 0.004670947324484587f, 0.008284659124910831f, 0.005755922757089138f, 0.004382681101560593f, 0.004748713690787554f, 0.008789453655481339f, 0.002833128208294511f, 0.007221412844955921f, 0.0049422490410506725f, 0.00808561872690916f, 0.004583061207085848f, 0.005342587362974882f, 0.011168322525918484f, 0.004412541631609201f, 0.004907633643597364f, 0.004738504532724619f, 0.004851406440138817f, 0.003564798040315509f, 0.005178983323276043f, 0.03228276968002319f, 0.0043242680840194225f, 0.006496442947536707f, 0.007691121660172939f, 0.004752154927700758f, 0.003502792213112116f, 0.006919072475284338f, 0.00565453851595521f, 0.006927641108632088f, 0.00669243186712265f, 0.0047728377394378185f, 0.003934622276574373f, 0.0036801276728510857f, 0.004708209540694952f, 0.006357300560921431f, 0.0070393565110862255f, 0.008981363847851753f, 0.00648771645501256f, 0.005447756499052048f, 0.004563128110021353f, 0.005096001084893942f, 0.007248681038618088f, 0.007819131016731262f, 0.006407349836081266f, 0.004503563512116671f, 0.002649079542607069f, 0.004771331325173378f, 0.004263789858669043f, 0.006771351210772991f, 0.005422601010650396f, 0.004740697331726551f, 0.003924443386495113f, 0.005988434422761202f, 0.004706051200628281f, 0.0056069823913276196f, 0.0068364436738193035f, 0.006016419734805822f, 0.004121161065995693f, 0.005688374862074852f, 0.006341028027236462f, 0.008080849424004555f, 0.009927956387400627f, 0.010427005589008331f, 0.005235881544649601f, 0.0037686380092054605f, 0.00583626190200448f, 0.004887653514742851f, 0.006895394995808601f, 0.005688678007572889f, 0.006640673149377108f, 0.008369510062038898f, 0.0050424071960151196f, 0.006627748254686594f, 0.002546857111155987f, 0.006021518260240555f, 0.008177272975444794f, 0.011311477050185204f, 0.005136188119649887f, 0.007485434878617525f, 0.004852042067795992f, 0.0051925452426075935f, 0.006080270279198885f, 0.004235961474478245f, 0.007704290095716715f, 0.005751678720116615f, 0.0038914717733860016f, 0.0036844818387180567f, 0.00508624454960227f, 0.004357627127319574f, 0.008524852804839611f, 0.008370800875127316f, 0.0018243755912408233f, 0.004713357426226139f, 0.00472979387268424f, 0.006699705496430397f, 0.007189333438873291f, 0.006730339955538511f, 0.007754083722829819f, 0.0049657318741083145f, 0.005594191607087851f, 0.009362632408738136f, 0.00786268338561058f, 0.00617590919137001f, 0.0108717055991292f, 0.0069091240875422955f, 0.009657845832407475f, 0.003998539876192808f, 0.015795039013028145f, 0.0053117903880774975f, 0.007385075092315674f, 0.008363611996173859f, 0.005903253331780434f, 0.006293893791735172f, 0.007389022037386894f, 0.004551323130726814f, 0.005924539174884558f, 0.005326253827661276f, 0.010491425171494484f, 0.005534722004085779f, 0.003411828074604273f, 0.005753266625106335f, 0.0058107562363147736f, 0.005209055263549089f, 0.0042359973303973675f, 0.005832944996654987f, 0.0052429744973778725f, 0.005476959049701691f, 0.003238805802538991f, 0.0064524575136601925f, 0.004672002047300339f, 0.0052172401919960976f, 0.0071120792999863625f, 0.004987571854144335f, 0.005517601501196623f, 0.004215526394546032f, 0.003746470669284463f, 0.005875930655747652f, 0.0058479816652834415f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006730011198669672f, 0.003283383324742317f, 0.004072525072842836f, 0.00362160406075418f, 0.003830167232081294f, 0.005486620590090752f, 0.004729683976620436f, 0.006144530605524778f, 0.003831226611509919f, 0.0037393500097095966f, 0.0060845063999295235f, 0.00586165115237236f, 0.005620474461466074f, 0.006417076103389263f, 0.005916133988648653f, 0.003907791338860989f, 0.005974015220999718f, 0.00587335554882884f, 0.0039028204046189785f, 0.005565306171774864f, 0.00566504243761301f, 0.003754592267796397f, 0.005351658910512924f, 0.007007286883890629f, 0.00603558961302042f, 0.003884031204506755f, 0.00470338761806488f, 0.0037034894339740276f, 0.0036073634400963783f, 0.006524509750306606f, 0.007022777106612921f, 0.004682989325374365f, 0.0037260905373841524f, 0.003961487673223019f, 0.0053278482519090176f, 0.004726454149931669f, 0.0038506232667714357f, 0.006384072359651327f, 0.006036399397999048f, 0.004239319358021021f, 0.005711541976779699f, 0.005458804778754711f, 0.0038040392100811005f, 0.004584547132253647f, 0.007108351681381464f, 0.0058898418210446835f, 0.006128543056547642f, 0.004320212639868259f, 0.0054807099513709545f, 0.004075462929904461f, 0.0071435486897826195f, 0.005207294598221779f, 0.004800597205758095f, 0.005492314696311951f, 0.005411580670624971f, 0.004977808799594641f, 0.0050247409380972385f, 0.004535605199635029f, 0.006435089278966188f, 0.005178950726985931f, 0.006546978838741779f, 0.003711517434567213f, 0.005387345794588327f, 0.004699764773249626f, 0.005253609735518694f, 0.003513476811349392f, 0.00425580982118845f, 0.006376973818987608f, 0.0032361627090722322f, 0.008434150367975235f, 0.0031475748401135206f, 0.00567969074472785f, 0.0050329300574958324f, 0.006300816312432289f, 0.003753923811018467f, 0.005316905211657286f, 0.003920290153473616f, 0.006486544385552406f, 0.0051528518088161945f, 0.005407029762864113f, 0.004440578166395426f, 0.0034361430443823338f, 0.004783176351338625f, 0.005356878507882357f, 0.005899407435208559f, 0.0028483550995588303f, 0.00682488176971674f, 0.004575167782604694f, 0.0031044413335621357f, 0.004587472882121801f, 0.0037918745074421167f, 0.004205566830933094f, 0.005503099411725998f, 0.004920976236462593f, 0.004550506826490164f, 0.005197684280574322f, 0.006746254861354828f, 0.004853441379964352f, 0.006348306313157082f, 0.0050343782640993595f, 0.0038414441514760256f, 0.00797827634960413f, 0.004516337066888809f, 0.0042954543605446815f, 0.005481077823787928f, 0.005763563793152571f, 0.004330430645495653f, 0.0037298009265214205f, 0.006050646770745516f, 0.005548638757318258f, 0.009267987683415413f, 0.0065141343511641026f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002962268190458417f, 0.002840793924406171f, 0.0037930512335151434f, 0.003789645852521062f, 0.003457811428233981f, 0.0034427151549607515f, 0.0026907806750386953f, 0.003073127707466483f, 0.002732408232986927f, 0.004207152407616377f, 0.0032185176387429237f, 0.0033027338795363903f, 0.003987176343798637f, 0.003173299366608262f, 0.0036081308498978615f, 0.002665514126420021f, 0.0038378422614187002f, 0.0030422022100538015f, 0.003404553048312664f, 0.003197207348421216f, 0.004905278794467449f, 0.0029287978541105986f, 0.002804460469633341f, 0.0035360101610422134f, 0.0033443968277424574f, 0.0029558902606368065f, 0.002899263985455036f, 0.0030269629787653685f, 0.002947898581624031f, 0.004419379401952028f, 0.0039056288078427315f, 0.002730767475441098f, 0.0035086916759610176f, 0.0032129506580531597f, 0.0038610061164945364f, 0.0027159852907061577f, 0.0034003567416220903f, 0.003536452539265156f, 0.0025250643957406282f, 0.003226032480597496f, 0.0032457539346069098f, 0.0038763016927987337f, 0.002409397391602397f, 0.004991341847926378f, 0.002881892491132021f, 0.005471846088767052f, 0.0026434771716594696f, 0.0030212216079235077f, 0.002923601306974888f, 0.004114771261811256f, 0.0034950454719364643f, 0.003721995512023568f, 0.0035345403011888266f, 0.0036123653408139944f, 0.00331511371769011f, 0.002983592916280031f, 0.003088025376200676f, 0.0030162797775119543f, 0.002879700856283307f, 0.0028169164434075356f, 0.004693405237048864f, 0.003985478077083826f, 0.003510348731651902f, 0.003047702834010124f, 0.003160809399560094f, 0.0039025272708386183f, 0.0035280489828437567f, 0.002805770840495825f, 0.004141694866120815f, 0.0043583819642663f, 0.0035690900404006243f, 0.0030912079382687807f, 0.0035715701524168253f, 0.0031081505585461855f, 0.003453386016190052f, 0.0036057550460100174f, 0.005024351645261049f, 0.004735821392387152f, 0.0026848861016333103f, 0.003090861951932311f, 0.003089758101850748f, 0.0030889508780092f, 0.0031823660247027874f, 0.0030044892337173223f, 0.00274836178869009f, 0.003113712416961789f, 0.0025379788130521774f, 0.003058074740692973f, 0.003848839784041047f, 0.0031314732041209936f, 0.0038780812174081802f, 0.0028417641296982765f, 0.002785631688311696f, 0.004245089832693338f, 0.002924924250692129f, 0.004293258301913738f, 0.002881873631849885f, 0.0031766060274094343f, 0.003536021336913109f, 0.003239865880459547f, 0.003429720876738429f, 0.0032754300627857447f, 0.002865432994440198f, 0.0029327794909477234f, 0.0029945254791527987f, 0.004089141730219126f, 0.0030578533187508583f, 0.003989146091043949f, 0.0032166449818760157f, 0.003128024749457836f, 0.00409915205091238f, 0.003636750392615795f, 0.0037787174805998802f, 0.0033201950136572123f, 0.0034347602631896734f, 0.002915957011282444f, 0.004277757368981838f, 0.0031341444700956345f, 0.0052056871354579926f, 0.002946192631497979f, 0.0026882514357566833f, 0.003714227117598057f, 0.0036812114994972944f, 0.0034060170873999596f, 0.0027264603413641453f, 0.0032252168748527765f, 0.003553357208147645f, 0.003492264775559306f, 0.0034190670121461153f, 0.004203982185572386f, 0.003913362044841051f, 0.0030039327684789896f, 0.0036959892604500055f, 0.003189509967342019f, 0.003363111987709999f, 0.003073249477893114f, 0.003377661807462573f, 0.004588605370372534f, 0.002704717917367816f, 0.0031836729031056166f, 0.00343597074970603f, 0.003918089438229799f, 0.002719347598031163f, 0.002841389738023281f, 0.003977985121309757f, 0.005055560264736414f, 0.0032851900905370712f, 0.0024113620165735483f, 0.0037989674601703882f, 0.003974366467446089f, 0.0031077193561941385f, 0.003555787494406104f, 0.002802353585138917f, 0.002692567417398095f, 0.003395708044990897f, 0.0026943571865558624f, 0.004258893895894289f, 0.003199822036549449f, 0.0036346353590488434f, 0.0032779790926724672f, 0.0027826784644275904f, 0.0033191062975674868f, 0.003173757577314973f, 0.004082619212567806f, 0.002635209821164608f, 0.002622431144118309f, 0.0035084765404462814f, 0.003019702387973666f, 0.0033491163048893213f, 0.004029254894703627f, 0.003276512725278735f, 0.004451939836144447f, 0.0028959515038877726f, 0.0036894092336297035f, 0.0025242783594876528f, 0.002901098458096385f, 0.002855573082342744f, 0.0036090274807065725f, 0.003080956405028701f, 0.0030477175023406744f, 0.003025614656507969f, 0.0024921537842601538f, 0.0044068749994039536f, 0.0033237857278436422f, 0.0032429443672299385f, 0.0029487295541912317f, 0.0032598082907497883f, 0.0035043542739003897f, 0.002793854335322976f, 0.003058692440390587f, 0.0028465171344578266f, 0.0034684808924794197f, 0.002976936288177967f, 0.0036020891275256872f, 0.003030691994354129f, 0.002847942989319563f, 0.003199027618393302f, 0.002907180693000555f, 0.0037364866584539413f, 0.0029218995478004217f, 0.0033388191368430853f, 0.0036096349358558655f, 0.002781620481982827f, 0.002812376245856285f, 0.004108406603336334f, 0.004115478601306677f, 0.003356836037710309f, 0.0034674974158406258f, 0.002966867759823799f, 0.003730557393282652f, 0.0032611521892249584f, 0.0033938761334866285f, 0.0034415076952427626f, 0.003096514381468296f, 0.004730448592454195f, 0.0030280014034360647f, 0.0028942208737134933f, 0.003454117337241769f, 0.0027579800225794315f, 0.003261126112192869f, 0.003593534231185913f, 0.002996081719174981f, 0.0032311617396771908f, 0.003647967241704464f, 0.002626366913318634f, 0.0028151797596365213f, 0.0032367242965847254f, 0.0038764076307415962f, 0.0033294865861535072f, 0.0028005181811749935f, 0.0034818651620298624f, 0.004002671223133802f, 0.003421671688556671f, 0.002904027933254838f, 0.003551850328221917f, 0.0023851455189287663f, 0.0028838247526437044f, 0.003162629436701536f, 0.0035207115579396486f, 0.0031158565543591976f, 0.003827351378276944f, 0.0032259151339530945f, 0.003378581488505006f, 0.004113413859158754f, 0.004059802740812302f, 0.0030956664122641087f, 0.0037216804921627045f, 0.0036243917420506477f, 0.0031918815802782774f, 0.0023453591857105494f, 0.0032878085039556026f, 0.0029261698946356773f, 0.003175443736836314f, 0.0033451335038989782f, 0.003229762427508831f, 0.0024762949906289577f, 0.003210157621651888f, 0.004598734900355339f, 0.004568631760776043f, 0.0039720297791063786f, 0.002954289549961686f, 0.0033332917373627424f, 0.004749038722366095f, 0.0026692929677665234f, 0.004181106574833393f, 0.0038737428840249777f, 0.004212476313114166f, 0.0032068798318505287f, 0.003484284272417426f, 0.0032500335946679115f, 0.003322786884382367f, 0.0029607717879116535f, 0.004031026735901833f, 0.0026405686512589455f, 0.004203383810818195f, 0.0029385010711848736f, 0.002751910826191306f, 0.004399679135531187f, 0.002897008555009961f, 0.0035427568946033716f, 0.0029809672851115465f, 0.0027745352126657963f, 0.003202300751581788f, 0.0032114610075950623f, 0.0035045072436332703f, 0.0027534293476492167f, 0.00384423672221601f, 0.0026543447747826576f, 0.0036587214563041925f, 0.003481886349618435f, 0.002948552370071411f, 0.0027480486314743757f, 0.0023097421508282423f, 0.0035043449606746435f, 0.003396394895389676f, 0.004371199756860733f, 0.002816712250933051f, 0.003496530232951045f, 0.002947727683931589f, 0.002848518081009388f, 0.0028982965741306543f, 0.003025509649887681f, 0.003237964352592826f, 0.0033155176788568497f, 0.0038028948474675417f, 0.0031017388682812452f, 0.0034014254342764616f, 0.002840803936123848f, 0.0033653152640908957f, 0.004016829188913107f, 0.0032798047177493572f, 0.002983464626595378f, 0.0030542712192982435f, 0.0033836262300610542f, 0.002824309980496764f, 0.0032822382636368275f, 0.0038066974375396967f, 0.004571909550577402f, 0.0027662781067192554f, 0.004902167711406946f, 0.00283983675763011f, 0.004814766813069582f, 0.0027451785281300545f, 0.003068444551900029f, 0.003484586952254176f, 0.003522941144183278f, 0.0036850415635854006f, 0.0030256297904998064f, 0.0036016267258673906f, 0.0029177386313676834f, 0.00405856454744935f, 0.0029017720371484756f, 0.004548053722828627f, 0.00480260606855154f, 0.00350779527798295f, 0.0028343561571091413f, 0.003460736945271492f, 0.004928180482238531f, 0.0034456863068044186f, 0.0029693583492189646f, 0.004505882505327463f, 0.0030330403242260218f, 0.004043902270495892f, 0.0026042438112199306f, 0.0037599618081003428f, 0.004056314937770367f, 0.0036871186457574368f, 0.0030498020350933075f, 0.002841716865077615f, 0.003547132248058915f, 0.003418003674596548f, 0.004583185538649559f, 0.003226686967536807f, 0.002936656353995204f, 0.003995522391051054f, 0.0028000979218631983f, 0.003337329486384988f, 0.0031114460434764624f, 0.0039694043807685375f, 0.0030449656769633293f, 0.0030756292399019003f, 0.0028560266364365816f, 0.0029998880345374346f, 0.0027125300839543343f, 0.0026339145842939615f, 0.0033886039163917303f, 0.002494496526196599f, 0.003050526138395071f, 0.0027748821303248405f, 0.0032833709847182035f, 0.003606240963563323f, 0.00397655600681901f, 0.0033622216433286667f, 0.002536442596465349f, 0.0032177201937884092f, 0.0027768812142312527f, 0.002592384349554777f, 0.0033615969587117434f, 0.0033833140041679144f, 0.003230617381632328f, 0.0033477465622127056f, 0.0036545773036777973f, 0.003295964328572154f, 0.0028599028009921312f, 0.003148590447381139f, 0.0032046015840023756f, 0.002722633769735694f, 0.0027122481260448694f, 0.0030989288352429867f, 0.0031373759265989065f, 0.0031426860950887203f, 0.003862028941512108f, 0.0038515033666044474f, 0.0029490534216165543f, 0.0029774580616503954f, 0.0030841429252177477f, 0.003640732727944851f, 0.0034169855061918497f, 0.003232618561014533f, 0.0031837308779358864f, 0.003526704153046012f, 0.002844403265044093f, 0.0036693194415420294f, 0.003588965628296137f, 0.0030851312913000584f, 0.004005701746791601f, 0.002690568333491683f, 0.0032278820872306824f, 0.002875368343666196f, 0.0029882173985242844f, 0.0032700621522963047f, 0.0028194899205118418f, 0.0030904358718544245f, 0.0032540897373110056f, 0.003616023575887084f, 0.0034376061521470547f, 0.004134075716137886f, 0.0027535490226000547f, 0.003972922917455435f, 0.002947439206764102f, 0.0030100797303020954f, 0.0032269246876239777f, 0.0034315078519284725f, 0.0037165989633649588f, 0.0031695542857050896f, 0.002590221120044589f, 0.0036965245380997658f, 0.003301103599369526f, 0.003276584902778268f, 0.00331939198076725f, 0.003243442391976714f, 0.003323606913909316f, 0.004151311237365007f, 0.002750623971223831f, 0.0027735477779060602f, 0.0032127650920301676f, 0.0030412969645112753f, 0.0036478256806731224f, 0.003740638727322221f, 0.003288756590336561f, 0.0037987895775586367f, 0.0037788108456879854f, 0.002950406866148114f, 0.003959710244089365f, 0.003528671571984887f, 0.002695881761610508f, 0.002975550014525652f, 0.003382987342774868f, 0.002880420535802841f, 0.0033462627325206995f, 0.0027954105753451586f, 0.0034394157119095325f, 0.0030632992275059223f, 0.0037869459483772516f, 0.003000885248184204f, 0.0038033046294003725f, 0.0032764533534646034f, 0.00341482600197196f, 0.0029441986698657274f, 0.0034135307651013136f, 0.004668691195547581f, 0.0031057705637067556f, 0.0030870563350617886f, 0.0037833640817552805f, 0.002652838360518217f, 0.003402855945751071f, 0.0027850240003317595f, 0.0034045435022562742f, 0.0031560342758893967f, 0.002421524841338396f, 0.0033152091782540083f, 0.0031581176444888115f, 0.002951055997982621f, 0.0029549698811024427f, 0.002606684574857354f, 0.0037425304763019085f, 0.0032840361818671227f, 0.004659722093492746f, 0.003680726746097207f, 0.0030150101520121098f, 0.0034737796522676945f, 0.003488162299618125f, 0.004076892975717783f, 0.003541169920936227f, 0.0029675846453756094f, 0.002963234204798937f, 0.003073402214795351f, 0.0028783013112843037f, 0.003030880820006132f, 0.003959920257329941f, 0.003320336574688554f, 0.003116866573691368f, 0.003761145519092679f, 0.0029570674523711205f, 0.0037101476918905973f, 0.002592930570244789f, 0.0031698483508080244f, 0.003251255489885807f, 0.00385737675242126f, 0.0034322456922382116f, 0.003715597791597247f, 0.003271345281973481f, 0.004171207081526518f, 0.002885441528633237f, 0.003403408220037818f, 0.0023422755766659975f, 0.0036910446360707283f, 0.0033460212871432304f, 0.002534331986680627f, 0.003082818118855357f, 0.0027768854051828384f, 0.0034948610700666904f, 0.004632541444152594f, 0.0032705378253012896f, 0.003519374178722501f, 0.003007326740771532f, 0.0036357652861624956f, 0.002989480271935463f, 0.0033982577733695507f, 0.0024749734438955784f, 0.003507975721731782f, 0.0030322943348437548f, 0.0034731498453766108f, 0.003618731861934066f, 0.003035713452845812f, 0.0035658152773976326f, 0.003018937073647976f, 0.003174236509948969f, 0.002833389909937978f, 0.0030072371009737253f, 0.0036632907576858997f, 0.0034947835374623537f, 0.0030095260590314865f, 0.0032440100330859423f, 0.0034968657419085503f, 0.0030538528226315975f, 0.00362970819696784f, 0.0031910783145576715f, 0.0033362077083438635f, 0.002870668889954686f, 0.0027317595668137074f, 0.0028558599296957254f, 0.00481909466907382f, 0.0030683951918035746f, 0.0029765551444143057f, 0.002890239004045725f, 0.0032327810768038034f, 0.003266013925895095f, 0.002749843057245016f, 0.00368686905130744f, 0.002482810290530324f, 0.0030895646195858717f, 0.003533170558512211f, 0.003631638130173087f, 0.003037188434973359f, 0.0029527749866247177f, 0.00338025763630867f, 0.003006793325766921f, 0.0030327714048326015f, 0.003254336304962635f, 0.003966948017477989f, 0.004362426232546568f, 0.002870012540370226f, 0.003334975801408291f, 0.0031921076588332653f, 0.0034197468776255846f, 0.003239539684727788f, 0.0025974404998123646f, 0.0030399004463106394f, 0.004337167367339134f, 0.0035717005375772715f, 0.003827329259365797f, 0.003541413461789489f, 0.004004315007477999f, 0.0036004188004881144f, 0.003873272566124797f, 0.0030638836324214935f, 0.0034967425744980574f, 0.0030946123879402876f, 0.0029832443688064814f, 0.0027155533898621798f, 0.002741382224485278f, 0.0030543850734829903f, 0.0027954040560871363f, 0.0034327604807913303f, 0.0031368981581181288f, 0.0027323367539793253f, 0.0035742567852139473f, 0.002966428641229868f, 0.002470992971211672f, 0.0035963032860308886f, 0.0027837466914206743f, 0.003329194150865078f, 0.0028873272240161896f, 0.002412964589893818f, 0.003097675507888198f, 0.0033737041521817446f, 0.0031709517352283f, 0.00311017083004117f, 0.003656927263364196f, 0.003991789650171995f, 0.004261659923940897f, 0.003952374681830406f, 0.0034711218904703856f, 0.0030232910066843033f, 0.002912970259785652f, 0.003046187339350581f, 0.003143716137856245f, 0.003193228505551815f, 0.003934118431061506f, 0.0035155569203197956f, 0.0036318472120910883f, 0.003926070407032967f, 0.0027090199291706085f, 0.0027023248840123415f, 0.004226491320878267f, 0.003361926879733801f, 0.0028873623814433813f, 0.0036784475669264793f, 0.003917803056538105f, 0.002751026302576065f, 0.00364630832336843f, 0.0035107056610286236f, 0.003787811379879713f, 0.002827136777341366f, 0.003751408774405718f, 0.003406256902962923f, 0.00305282324552536f, 0.0033598714508116245f, 0.0031472998671233654f, 0.003148886142298579f, 0.0037229852750897408f, 0.0030602985061705112f, 0.0036277608014643192f, 0.0036187164951115847f, 0.0033705667592585087f, 0.0033224858343601227f, 0.00372292404063046f, 0.0028794149402529f, 0.003464567009359598f, 0.0040014865808188915f, 0.002679139608517289f, 0.003083926159888506f, 0.0031499643810093403f, 0.0027717098128050566f, 0.003032947890460491f, 0.004366324748843908f, 0.0038701461162418127f, 0.0032990092877298594f, 0.0024579414166510105f, 0.00230871862731874f, 0.002945816144347191f, 0.0031815776601433754f, 0.0034083323553204536f, 0.0029995879158377647f, 0.0032722840551286936f, 0.0025598066858947277f, 0.0030133752152323723f, 0.0030359290540218353f, 0.004603583365678787f, 0.003237904282286763f, 0.003496842458844185f, 0.003777182660996914f, 0.0036301121581345797f, 0.003127496689558029f, 0.0033593266271054745f, 0.002720671007409692f, 0.005047993268817663f, 0.003953231032937765f, 0.0033547773491591215f, 0.0033080969005823135f, 0.004479867871850729f, 0.0035584501456469297f, 0.0032355869188904762f, 0.003040177281945944f, 0.00294434349052608f, 0.0027125696651637554f, 0.004220471251755953f, 0.0027848200406879187f, 0.0024756973143666983f, 0.0033559296280145645f, 0.004083971958607435f, 0.0025245577562600374f, 0.003018523333594203f, 0.002954612486064434f, 0.0030730972066521645f, 0.003199776401743293f, 0.003425419330596924f, 0.0030280104838311672f, 0.0031633046455681324f, 0.0038252086378633976f, 0.0030085663311183453f, 0.003199277212843299f, 0.0030123363249003887f, 0.0030541052110493183f, 0.0038405470550060272f, 0.002457643859088421f, 0.0034031434915959835f, 0.004047560505568981f, 0.003729407675564289f, 0.0034581543877720833f, 0.0031875448767095804f, 0.0028907794039696455f, 0.0033499656710773706f, 0.0031660564709454775f, 0.0035062450915575027f, 0.00352103472687304f, 0.004587059840559959f, 0.0035393480211496353f, 0.003090783255174756f, 0.0035785501822829247f, 0.0028834121767431498f, 0.004656127188354731f, 0.00272444449365139f, 0.0033472145441919565f, 0.0028078248724341393f, 0.0026147784665226936f, 0.0034198244102299213f, 0.004674132913351059f, 0.002659653080627322f, 0.0036172831896692514f, 0.003111218800768256f, 0.002730228006839752f, 0.0038850039709359407f, 0.002839550608769059f, 0.003114321269094944f, 0.0028497804887592793f, 0.004461418371647596f, 0.0034340061247348785f, 0.0033402536064386368f, 0.004186119418591261f, 0.0051588076166808605f, 0.0034650475718080997f, 0.003368728794157505f, 0.0027021821588277817f, 0.002550013130530715f, 0.0028425431810319424f, 0.002723061479628086f, 0.0025092908181250095f, 0.002951266709715128f, 0.0033235731534659863f, 0.0036475115921348333f, 0.0031364404130727053f, 0.0029416093602776527f, 0.0035859285853803158f, 0.0028643107507377863f, 0.002774875843897462f, 0.0038383621722459793f, 0.0036921934224665165f, 0.004057202022522688f, 0.0027297420892864466f, 0.002928657690063119f, 0.0032609645277261734f, 0.004028182942420244f, 0.003087301505729556f, 0.00251030083745718f, 0.0038135279901325703f, 0.0028253330383449793f, 0.004956354852765799f, 0.002937342505902052f, 0.003239047946408391f, 0.003579734591767192f, 0.0030523298773914576f, 0.0036120759323239326f, 0.0032155911903828382f, 0.003126933006569743f, 0.002948947250843048f, 0.0027064653113484383f, 0.0031545194797217846f, 0.0032486312557011843f, 0.0030864132568240166f, 0.0037283836863934994f, 0.003543980186805129f, 0.003219164442270994f, 0.0040757437236607075f, 0.0033355734776705503f, 0.003154526697471738f, 0.004479872528463602f, 0.003301668679341674f, 0.004183533601462841f, 0.0032987748272717f, 0.0028115275781601667f, 0.00273882201872766f, 0.00267807743512094f, 0.0028140468057245016f, 0.0033641732297837734f, 0.0031611721497029066f, 0.004145477432757616f, 0.0038185412995517254f, 0.0030179410241544247f, 0.003570847911760211f, 0.0033797009382396936f, 0.002958326367661357f, 0.003382484894245863f, 0.002556433202698827f, 0.003716125153005123f, 0.00358598493039608f, 0.0037785586901009083f, 0.002970333443954587f, 0.0027843653224408627f, 0.0031756998505443335f, 0.0034714876674115658f, 0.0030629849061369896f, 0.004015173297375441f, 0.003434961661696434f, 0.0033051283098757267f, 0.0035327496007084846f, 0.003327624872326851f, 0.003155935788527131f, 0.0031484696082770824f, 0.0031285227742046118f, 0.002941085724160075f, 0.0037361716385930777f, 0.003994327504187822f, 0.00284269149415195f, 0.003138575702905655f, 0.0034375691320747137f, 0.0029068528674542904f, 0.003290105378255248f, 0.0037118536420166492f, 0.003976224455982447f, 0.003546551102772355f, 0.0031808745115995407f, 0.003736766055226326f, 0.0025979941710829735f, 0.0036686507519334555f, 0.004224369302392006f, 0.00385750038549304f, 0.0028036844450980425f, 0.003907285630702972f, 0.0032157613895833492f, 0.0030555787961930037f, 0.0033223768696188927f, 0.003951746039092541f, 0.0032084952108561993f, 0.0038948445580899715f, 0.003459690138697624f, 0.003657160559669137f, 0.003385598072782159f, 0.002951735630631447f, 0.0033839154057204723f, 0.0030852570198476315f, 0.0032077960204333067f, 0.002781457733362913f, 0.003769504139199853f, 0.003586540464311838f, 0.003777632722631097f, 0.0037009778898209333f, 0.00413112947717309f, 0.002729718806222081f, 0.003550844732671976f, 0.004535219166427851f, 0.0034476895816624165f, 0.0033216034062206745f, 0.0029577824752777815f, 0.002380936872214079f, 0.002829776844009757f, 0.003317490452900529f, 0.002692263340577483f, 0.003457194659858942f, 0.0027097745332866907f, 0.003618218470364809f, 0.0029465185943990946f, 0.004593569319695234f, 0.0035963181871920824f, 0.003376025939360261f, 0.0039060504641383886f, 0.004091854207217693f, 0.0031222363468259573f, 0.0035071212332695723f, 0.0037736264057457447f, 0.0033898157998919487f, 0.0025745192542672157f, 0.003598575945943594f, 0.0024273423478007317f, 0.0026293897535651922f, 0.004591926466673613f, 0.0029537964146584272f, 0.0040033431723713875f, 0.004073000978678465f, 0.0027359365485608578f, 0.003365426789969206f, 0.002833819715306163f, 0.0038284449838101864f, 0.00320211099460721f, 0.0031533553265035152f, 0.0036374125629663467f, 0.003051059553399682f, 0.003538830205798149f, 0.0024824682623147964f, 0.0030175428837537766f, 0.0029206324834376574f, 0.002773028565570712f, 0.003389798104763031f, 0.0035138686653226614f, 0.003263522172346711f, 0.0029679681174457073f, 0.0031033868435770273f, 0.0030046405736356974f, 0.0030451675411313772f, 0.004791914485394955f, 0.0036477113608270884f, 0.002767939120531082f, 0.0031373107340186834f, 0.0034491855185478926f, 0.0030697856564074755f, 0.003306497121229768f, 0.0031922408379614353f, 0.003967286087572575f, 0.0031800223514437675f, 0.0028226689901202917f, 0.003291286528110504f, 0.0028908108361065388f, 0.0038039847277104855f, 0.0030429780017584562f, 0.003566696308553219f, 0.0030739801004529f, 0.0027082490269094706f, 0.0032510573510080576f, 0.00355596374720335f, 0.003600483061745763f, 0.003310912288725376f, 0.003068115096539259f, 0.0024648704566061497f, 0.003059757174924016f, 0.003282820340245962f, 0.0030425691511482f, 0.0042131878435611725f, 0.00323037663474679f, 0.0033322249073535204f, 0.0027935593388974667f, 0.0028507006354629993f, 0.002355072181671858f, 0.0030410224571824074f, 0.0037429321091622114f, 0.004081218037754297f, 0.0028973997104912996f, 0.0028292147908359766f, 0.00257346429862082f, 0.0038345640059560537f, 0.00352787459269166f, 0.0028491138946264982f, 0.0034058208111673594f, 0.003016560571268201f, 0.0026730576064437628f, 0.003223525360226631f, 0.002960679354146123f, 0.004014117177575827f, 0.003390256082639098f, 0.003631712170317769f, 0.004141038749366999f, 0.0024661878123879433f, 0.0026563038118183613f, 0.0037643981631845236f, 0.002869007410481572f, 0.0035529963206499815f, 0.003356719156727195f, 0.003808720503002405f, 0.0029628712218254805f, 0.0027096576523035765f, 0.004050597082823515f, 0.0032151537016034126f, 0.0032611635979264975f, 0.0037339318078011274f, 0.002413197187706828f, 0.0027398995589464903f, 0.0026678540743887424f, 0.0034899916499853134f, 0.0028990847058594227f, 0.0035960348322987556f, 0.002728824969381094f, 0.002985191298648715f, 0.002916513942182064f, 0.003960136324167252f, 0.0028076753951609135f, 0.0031183562241494656f, 0.0029415027238428593f, 0.0031832801178097725f, 0.002578763524070382f, 0.0037878029979765415f, 0.004281411413103342f, 0.0028803786262869835f, 0.00317752780392766f, 0.004071288742125034f, 0.003027701983228326f, 0.0026038303039968014f, 0.003690138692036271f, 0.003038487397134304f, 0.0026026014238595963f, 0.0030469608027487993f, 0.002940614242106676f, 0.004226501565426588f, 0.00302157923579216f, 0.003768744645640254f, 0.0037501640617847443f, 0.003918807487934828f, 0.003511707065626979f, 0.0033141039311885834f, 0.004606390837579966f, 0.003035618457943201f, 0.003195101860910654f, 0.0038411717396229506f, 0.0029820005875080824f, 0.003471491625532508f, 0.0030579667072743177f, 0.003181858453899622f, 0.002960456069558859f, 0.0033815482165664434f, 0.0030431144405156374f, 0.003971402533352375f, 0.004193492233753204f, 0.0029077096842229366f, 0.0030984836630523205f, 0.003243690123781562f, 0.0032659133430570364f, 0.003133761463686824f, 0.0028197518549859524f, 0.0038197024259716272f, 0.0031164013780653477f, 0.0027187739033252f, 0.0031083018984645605f, 0.002568058902397752f, 0.0034567660186439753f, 0.0032676204573363066f, 0.0029751500114798546f, 0.0037938090972602367f, 0.0029676840640604496f, 0.002900470979511738f, 0.0023123035207390785f, 0.003462431486696005f, 0.0030010307673364878f, 0.002938562072813511f, 0.003362623043358326f, 0.0032243523746728897f, 0.0032206091564148664f, 0.0025351778604090214f, 0.005068007856607437f, 0.002604452660307288f, 0.0024503490421921015f, 0.0031304527074098587f, 0.0035264950711280107f, 0.003136807819828391f, 0.003269599284976721f, 0.003654949367046356f, 0.003310893662273884f, 0.0033694542944431305f, 0.004839828237891197f, 0.0034104858059436083f, 0.003216717392206192f, 0.0030106983613222837f, 0.003266834421083331f, 0.0046689691953361034f, 0.002825140254572034f, 0.0026037057396024466f, 0.002803682815283537f, 0.0034956291783601046f, 0.0030800397507846355f, 0.0029794720467180014f, 0.003395097330212593f, 0.00305871176533401f, 0.0033183202613145113f, 0.0030593140982091427f, 0.002929137321189046f, 0.004246315453201532f, 0.0031844573095440865f, 0.0032472051680088043f, 0.003175638848915696f, 0.003090815618634224f, 0.0031481406185775995f, 0.0024910394567996264f, 0.002790398895740509f, 0.0031621227972209454f, 0.0036281850188970566f, 0.003277453826740384f, 0.003015697468072176f, 0.0034462977200746536f, 0.0031102728098630905f, 0.003397191409021616f, 0.0031570205464959145f, 0.003273146227002144f, 0.002814952749758959f, 0.0034049046225845814f, 0.0038459727074950933f, 0.002677361946552992f, 0.0043163299560546875f, 0.003022640012204647f, 0.0027727154083549976f, 0.0029304579365998507f, 0.0030272160656750202f, 0.0037761451676487923f, 0.0032565463334321976f, 0.003913601394742727f, 0.003669912228360772f, 0.00319452746771276f, 0.002897024853155017f, 0.002901059342548251f, 0.0034743540454655886f, 0.0038037877529859543f, 0.0032576473895460367f, 0.0028040651232004166f, 0.0031292045023292303f, 0.0034171470906585455f, 0.0028586622793227434f, 0.004212166182696819f, 0.0029109360184520483f, 0.0037839417345821857f, 0.003109068376943469f, 0.0036031061317771673f, 0.0025887563824653625f, 0.0038003060035407543f, 0.004608431365340948f, 0.003395691281184554f, 0.0035266533959656954f, 0.003113130107522011f, 0.0035571125335991383f, 0.0041593583300709724f, 0.002683056518435478f, 0.003880035597831011f, 0.00428356695920229f, 0.0033893242944031954f, 0.003206647699698806f, 0.002893319819122553f, 0.0033057008404284716f, 0.004218989051878452f, 0.0028660192620009184f, 0.0042281304486095905f, 0.004151653032749891f, 0.00450354116037488f, 0.0025692270137369633f, 0.003465719288215041f, 0.002918610582128167f, 0.003812346374616027f, 0.00350026972591877f, 0.004042963497340679f, 0.002208726480603218f, 0.003947373945266008f, 0.003465613815933466f, 0.002896531019359827f, 0.005295803304761648f, 0.002810909878462553f, 0.0038208679761737585f, 0.003306129015982151f, 0.004092233255505562f, 0.0035644439049065113f, 0.004116897936910391f, 0.004572142846882343f, 0.0030743307434022427f, 0.0030694217421114445f, 0.0031332161743193865f, 0.002874230733141303f, 0.004282372072339058f, 0.005622797645628452f, 0.00325135700404644f, 0.003590012900531292f, 0.0031413277611136436f, 0.003607082413509488f, 0.0035594787914305925f, 0.004298664163798094f, 0.0032559391111135483f, 0.003268999280408025f, 0.0032280574087053537f, 0.0038270188961178064f, 0.003946307115256786f, 0.003233830677345395f, 0.0026923809200525284f, 0.0031023912597447634f, 0.0038035304751247168f, 0.003099702997133136f, 0.0025886339135468006f, 0.0027748483698815107f, 0.0030509859789162874f, 0.0036200496833771467f, 0.005848211701959372f, 0.004235915374010801f, 0.0036915966775268316f, 0.003350256010890007f, 0.003859836608171463f, 0.0035529392771422863f, 0.00316097610630095f, 0.0028713804204016924f, 0.004134997259825468f, 0.003870827378705144f, 0.003472996409982443f, 0.0037333983927965164f, 0.0034891015384346247f, 0.003856122959405184f, 0.0038934280164539814f, 0.0037056247238069773f, 0.0034304247237741947f, 0.00434857839718461f, 0.002935157623142004f, 0.0033862809650599957f, 0.0031862857285887003f, 0.004091243725270033f, 0.003366529941558838f, 0.004217255860567093f, 0.002535049570724368f, 0.0032831572461873293f, 0.003993600141257048f, 0.0032632702495902777f, 0.003543269354850054f, 0.003315709065645933f, 0.004774396773427725f, 0.0028589172288775444f, 0.0031613961327821016f, 0.0031898757442831993f, 0.0030628673266619444f, 0.003660280490294099f, 0.0036086165346205235f, 0.0031876126304268837f, 0.004361347295343876f, 0.0027221182826906443f, 0.0025929126422852278f, 0.0029644889291375875f, 0.0037970084231346846f, 0.003692592028528452f, 0.003664606250822544f, 0.0037901178002357483f, 0.0034989689011126757f, 0.0030168069060891867f, 0.002881163265556097f, 0.0036631212569773197f, 0.0033224693033844233f, 0.003938768990337849f, 0.00309197255410254f, 0.002576361643150449f, 0.003224592190235853f, 0.0032267714850604534f, 0.003308352315798402f, 0.002765335375443101f, 0.0027938124258071184f, 0.004584081470966339f, 0.005816732533276081f, 0.003364868462085724f, 0.003343162825331092f, 0.0036993699613958597f, 0.003168651135638356f, 0.003651381004601717f, 0.002943258499726653f, 0.0034705125726759434f, 0.003019787138327956f, 0.0033439535181969404f, 0.002978353062644601f, 0.0034630801528692245f, 0.003236118471249938f, 0.0025991725269705057f, 0.003290768014267087f, 0.0030509443022310734f, 0.0045387702994048595f, 0.00392566155642271f, 0.0039696721360087395f, 0.002715624403208494f, 0.0029979990795254707f, 0.0026872321031987667f, 0.002713198307901621f, 0.002676131669431925f, 0.002783756237477064f, 0.003084277268499136f, 0.003985033370554447f, 0.0026441896334290504f, 0.0032070546876639128f, 0.0028584941755980253f, 0.003969877026975155f, 0.002697455231100321f, 0.004424865823239088f, 0.0027002457063645124f, 0.002925747772678733f, 0.002996645402163267f, 0.0034634172916412354f, 0.0038252449594438076f, 0.0029889096040278673f, 0.0033726890105754137f, 0.00334586831741035f, 0.003235739190131426f, 0.0030656016897410154f, 0.0028542170766741037f, 0.003300389973446727f, 0.0034754564985632896f, 0.002583600115031004f, 0.0032657322008162737f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_68_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005373790045268834f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_input_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921537194401026f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921537194401026f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01873144321143627f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01873144321143627f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.26953989267349243f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.21631301939487457f),
    AI_PACK_INTQ_ZP(16)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22243109345436096f),
    AI_PACK_INTQ_ZP(16)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_11_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2848900258541107f),
    AI_PACK_INTQ_ZP(13)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #128 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15266786515712738f),
    AI_PACK_INTQ_ZP(-19)))

/* Int quant #129 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #130 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #131 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #132 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #133 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12994810938835144f),
    AI_PACK_INTQ_ZP(14)))

/* Int quant #134 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_19_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.21163423359394073f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #135 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #136 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #137 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #138 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16959400475025177f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #139 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_23_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2478455752134323f),
    AI_PACK_INTQ_ZP(27)))

/* Int quant #140 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #141 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #142 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #143 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02323860116302967f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #144 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.152186319231987f),
    AI_PACK_INTQ_ZP(28)))

/* Int quant #145 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #146 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #147 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #148 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #149 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15751464664936066f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #150 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_31_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17536960542201996f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #151 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #153 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #154 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1413068324327469f),
    AI_PACK_INTQ_ZP(60)))

/* Int quant #155 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_35_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17267818748950958f),
    AI_PACK_INTQ_ZP(16)))

/* Int quant #156 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #157 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023445334285497665f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #158 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023445334285497665f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #159 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_38_output_array, &conv2d_38_output_array_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_39_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &eltwise_39_output_array, &eltwise_39_output_array_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch1, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_17_scratch1_array, &conv2d_17_scratch1_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_40_output_array, &conv2d_40_output_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_pad_before_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 10, 10), AI_STRIDE_INIT(4, 1, 1, 144, 1440),
  1, &conv2d_41_pad_before_output_array, &conv2d_41_pad_before_output_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_41_output_array, &conv2d_41_output_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &conv2d_42_output_array, &conv2d_42_output_array_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_43_output_array, &conv2d_43_output_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_pad_before_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 10, 10), AI_STRIDE_INIT(4, 1, 1, 192, 1920),
  1, &conv2d_44_pad_before_output_array, &conv2d_44_pad_before_output_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_44_output_array, &conv2d_44_output_array_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &conv2d_45_output_array, &conv2d_45_output_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch1, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_20_scratch1_array, &conv2d_20_scratch1_array_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_46_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &eltwise_46_output_array, &eltwise_46_output_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_47_output_array, &conv2d_47_output_array_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_pad_before_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 10, 10), AI_STRIDE_INIT(4, 1, 1, 192, 1920),
  1, &conv2d_48_pad_before_output_array, &conv2d_48_pad_before_output_array_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_48_output_array, &conv2d_48_output_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &conv2d_49_output_array, &conv2d_49_output_array_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch1, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_21_scratch1_array, &conv2d_21_scratch1_array_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_50_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &eltwise_50_output_array, &eltwise_50_output_array_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_51_output_array, &conv2d_51_output_array_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_pad_before_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 9, 9), AI_STRIDE_INIT(4, 1, 1, 192, 1728),
  1, &conv2d_53_pad_before_output_array, &conv2d_53_pad_before_output_array_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 4, 4), AI_STRIDE_INIT(4, 1, 1, 192, 768),
  1, &conv2d_53_output_array, &conv2d_53_output_array_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &conv2d_54_output_array, &conv2d_54_output_array_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_55_output_array, &conv2d_55_output_array_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_pad_before_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_56_pad_before_output_array, &conv2d_56_pad_before_output_array_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_56_output_array, &conv2d_56_output_array_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch1, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_24_scratch1_array, &conv2d_24_scratch1_array_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &conv2d_57_output_array, &conv2d_57_output_array_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_58_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &eltwise_58_output_array, &eltwise_58_output_array_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_59_output_array, &conv2d_59_output_array_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_pad_before_output, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_60_pad_before_output_array, &conv2d_60_pad_before_output_array_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_output, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_60_output_array, &conv2d_60_output_array_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &conv2d_61_output_array, &conv2d_61_output_array_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_62_output, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &eltwise_62_output_array, &eltwise_62_output_array_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_63_output_array, &conv2d_63_output_array_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_pad_before_output, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 6, 6), AI_STRIDE_INIT(4, 1, 1, 336, 2016),
  1, &conv2d_64_pad_before_output_array, &conv2d_64_pad_before_output_array_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_output, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_64_output_array, &conv2d_64_output_array_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 4, 4), AI_STRIDE_INIT(4, 1, 1, 112, 448),
  1, &conv2d_65_output_array, &conv2d_65_output_array_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch1, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_28_scratch1_array, &conv2d_28_scratch1_array_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_output, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 4, 4), AI_STRIDE_INIT(4, 1, 1, 1280, 5120),
  1, &conv2d_66_output_array, &conv2d_66_output_array_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  pool_67_output, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &pool_67_output_array, &pool_67_output_array_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  gemm_68_output, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8, 8),
  1, &gemm_68_output_array, &gemm_68_output_array_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  nl_69_output, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8, 8),
  1, &nl_69_output_array, &nl_69_output_array_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conversion_70_output, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conversion_70_output_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch1, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_29_scratch1_array, &conv2d_29_scratch1_array_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 48, 144),
  1, &conv2d_1_weights_array, &conv2d_1_weights_array_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_1_bias_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 16, 48),
  1, &conv2d_2_weights_array, &conv2d_2_weights_array_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_scratch0, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_32_scratch0_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 8), AI_STRIDE_INIT(4, 1, 16, 128, 128),
  1, &conv2d_3_weights_array, &conv2d_3_weights_array_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_scratch1, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_32_scratch1_array, &conv2d_32_scratch1_array_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_3_bias_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 384, 384),
  1, &conv2d_4_weights_array, &conv2d_4_weights_array_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_4_bias_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch1, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_33_scratch1_array, &conv2d_33_scratch1_array_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 48, 144),
  1, &conv2d_6_weights_array, &conv2d_6_weights_array_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  69, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_6_bias_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 384, 384),
  1, &conv2d_7_weights_array, &conv2d_7_weights_array_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_7_bias_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  73, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_36_scratch0_array, NULL)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 384, 384),
  1, &conv2d_8_weights_array, &conv2d_8_weights_array_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  75, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_8_bias_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 48, 144),
  1, &conv2d_9_weights_array, &conv2d_9_weights_array_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_9_bias_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch1, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_37_scratch1_array, &conv2d_37_scratch1_array_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 384, 384),
  1, &conv2d_10_weights_array, &conv2d_10_weights_array_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_10_bias_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 384, 384),
  1, &conv2d_12_weights_array, &conv2d_12_weights_array_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_12_bias_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_scratch0, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_40_scratch0_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 48, 144),
  1, &conv2d_14_weights_array, &conv2d_14_weights_array_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_scratch1, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_40_scratch1_array, &conv2d_40_scratch1_array_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_14_bias_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 1, 48, 768, 768),
  1, &conv2d_15_weights_array, &conv2d_15_weights_array_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_15_bias_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch1, AI_STATIC,
  92, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_41_scratch1_array, &conv2d_41_scratch1_array_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 1536, 1536),
  1, &conv2d_16_weights_array, &conv2d_16_weights_array_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_16_bias_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 96, 288),
  1, &conv2d_17_weights_array, &conv2d_17_weights_array_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_17_bias_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 1536, 1536),
  1, &conv2d_18_weights_array, &conv2d_18_weights_array_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_18_bias_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch0, AI_STATIC,
  101, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_44_scratch0_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 1536, 1536),
  1, &conv2d_20_weights_array, &conv2d_20_weights_array_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  103, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_20_bias_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch0, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_45_scratch0_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 96, 288),
  1, &conv2d_21_weights_array, &conv2d_21_weights_array_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_21_bias_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_scratch0, AI_STATIC,
  107, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_47_scratch0_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 1536, 1536),
  1, &conv2d_22_weights_array, &conv2d_22_weights_array_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_22_bias_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 1536, 1536),
  1, &conv2d_24_weights_array, &conv2d_24_weights_array_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_24_bias_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  114, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 96, 288),
  1, &conv2d_26_weights_array, &conv2d_26_weights_array_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  115, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_26_bias_array, NULL)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_scratch0, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_51_scratch0_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 2304, 2304),
  1, &conv2d_27_weights_array, &conv2d_27_weights_array_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_27_bias_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_scratch1, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_51_scratch1_array, &conv2d_51_scratch1_array_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  120, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_28_weights_array, &conv2d_28_weights_array_intq)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_28_bias_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_scratch0, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_53_scratch0_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_29_weights_array, &conv2d_29_weights_array_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_scratch1, AI_STATIC,
  124, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 4, 4), AI_STRIDE_INIT(4, 1, 1, 192, 768),
  1, &conv2d_53_scratch1_array, &conv2d_53_scratch1_array_intq)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_29_bias_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  126, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 3456, 3456),
  1, &conv2d_30_weights_array, &conv2d_30_weights_array_intq)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch0, AI_STATIC,
  127, 0x0,
  AI_SHAPE_INIT(4, 1, 1328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1328, 1328),
  1, &conv2d_54_scratch0_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_30_bias_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_weights, AI_STATIC,
  129, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_32_weights_array, &conv2d_32_weights_array_intq)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_scratch0, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_55_scratch0_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_bias, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_32_bias_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  132, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_33_weights_array, &conv2d_33_weights_array_intq)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_33_bias_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 3456, 3456),
  1, &conv2d_34_weights_array, &conv2d_34_weights_array_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch0, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_57_scratch0_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  137, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_34_bias_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  138, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_36_weights_array, &conv2d_36_weights_array_intq)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_scratch0, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_59_scratch0_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_36_bias_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_37_weights_array, &conv2d_37_weights_array_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch0, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_60_scratch0_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_37_bias_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  144, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 3456, 3456),
  1, &conv2d_38_weights_array, &conv2d_38_weights_array_intq)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch0, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_61_scratch0_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_38_bias_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_weights, AI_STATIC,
  147, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 3456, 3456),
  1, &conv2d_40_weights_array, &conv2d_40_weights_array_intq)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_scratch0, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_63_scratch0_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_bias, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_40_bias_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  150, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 144, 432),
  1, &conv2d_41_weights_array, &conv2d_41_weights_array_intq)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch0, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_64_scratch0_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_41_bias_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch1, AI_STATIC,
  153, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_64_scratch1_array, &conv2d_64_scratch1_array_intq)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  154, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 32), AI_STRIDE_INIT(4, 1, 144, 4608, 4608),
  1, &conv2d_42_weights_array, &conv2d_42_weights_array_intq)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_42_bias_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch0, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 1, 2464, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2464, 2464),
  1, &conv2d_65_scratch0_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  157, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 6144, 6144),
  1, &conv2d_43_weights_array, &conv2d_43_weights_array_intq)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_43_bias_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_scratch0, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 13248, 1, 1), AI_STRIDE_INIT(4, 1, 1, 13248, 13248),
  1, &conv2d_66_scratch0_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_weights, AI_STATIC,
  160, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 192, 576),
  1, &conv2d_44_weights_array, &conv2d_44_weights_array_intq)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_bias, AI_STATIC,
  161, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_44_bias_array, NULL)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_scratch1, AI_STATIC,
  162, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 4, 4), AI_STRIDE_INIT(4, 1, 1, 1280, 5120),
  1, &conv2d_66_scratch1_array, &conv2d_66_scratch1_array_intq)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_weights, AI_STATIC,
  163, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 6144, 6144),
  1, &conv2d_45_weights_array, &conv2d_45_weights_array_intq)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_bias, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_45_bias_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  gemm_68_scratch0, AI_STATIC,
  165, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 2, 2, 2560, 2560),
  1, &gemm_68_scratch0_array, NULL)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_weights, AI_STATIC,
  166, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 6144, 6144),
  1, &conv2d_47_weights_array, &conv2d_47_weights_array_intq)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_bias, AI_STATIC,
  167, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_47_bias_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  nl_69_scratch0, AI_STATIC,
  168, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &nl_69_scratch0_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  169, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 192, 576),
  1, &conv2d_48_weights_array, &conv2d_48_weights_array_intq)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  170, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_48_bias_array, NULL)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  171, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 6144, 6144),
  1, &conv2d_49_weights_array, &conv2d_49_weights_array_intq)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  172, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_49_bias_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_weights, AI_STATIC,
  173, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 6144, 6144),
  1, &conv2d_51_weights_array, &conv2d_51_weights_array_intq)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_bias, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_51_bias_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_weights, AI_STATIC,
  175, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 192, 576),
  1, &conv2d_53_weights_array, &conv2d_53_weights_array_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_bias, AI_STATIC,
  176, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_53_bias_array, NULL)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_weights, AI_STATIC,
  177, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 56), AI_STRIDE_INIT(4, 1, 192, 10752, 10752),
  1, &conv2d_54_weights_array, &conv2d_54_weights_array_intq)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_bias, AI_STATIC,
  178, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_54_bias_array, NULL)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_weights, AI_STATIC,
  179, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 18816, 18816),
  1, &conv2d_55_weights_array, &conv2d_55_weights_array_intq)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_bias, AI_STATIC,
  180, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_55_bias_array, NULL)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_weights, AI_STATIC,
  181, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 336, 1008),
  1, &conv2d_56_weights_array, &conv2d_56_weights_array_intq)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_bias, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_56_bias_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_weights, AI_STATIC,
  183, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 18816, 18816),
  1, &conv2d_57_weights_array, &conv2d_57_weights_array_intq)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_bias, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_57_bias_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_weights, AI_STATIC,
  185, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 18816, 18816),
  1, &conv2d_59_weights_array, &conv2d_59_weights_array_intq)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_59_bias, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_59_bias_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_weights, AI_STATIC,
  187, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 336, 1008),
  1, &conv2d_60_weights_array, &conv2d_60_weights_array_intq)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_bias, AI_STATIC,
  188, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_60_bias_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_weights, AI_STATIC,
  189, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 18816, 18816),
  1, &conv2d_61_weights_array, &conv2d_61_weights_array_intq)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_bias, AI_STATIC,
  190, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_61_bias_array, NULL)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_weights, AI_STATIC,
  191, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 18816, 18816),
  1, &conv2d_63_weights_array, &conv2d_63_weights_array_intq)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_63_bias, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_63_bias_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_weights, AI_STATIC,
  193, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 336, 1008),
  1, &conv2d_64_weights_array, &conv2d_64_weights_array_intq)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_bias, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_64_bias_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_weights, AI_STATIC,
  195, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 112), AI_STRIDE_INIT(4, 1, 336, 37632, 37632),
  1, &conv2d_65_weights_array, &conv2d_65_weights_array_intq)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_bias, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &conv2d_65_bias_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_weights, AI_STATIC,
  197, 0x1,
  AI_SHAPE_INIT(4, 112, 1, 1, 1280), AI_STRIDE_INIT(4, 1, 112, 143360, 143360),
  1, &conv2d_66_weights_array, &conv2d_66_weights_array_intq)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_bias, AI_STATIC,
  198, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &conv2d_66_bias_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  gemm_68_weights, AI_STATIC,
  199, 0x1,
  AI_SHAPE_INIT(4, 1280, 8, 1, 1), AI_STRIDE_INIT(4, 1, 1280, 10240, 10240),
  1, &gemm_68_weights_array, &gemm_68_weights_array_intq)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  gemm_68_bias, AI_STATIC,
  200, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &gemm_68_bias_array, NULL)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  203, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_array_intq)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 1, 1, 144, 144),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_input_10_output, AI_STATIC,
  205, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 128, 128), AI_STRIDE_INIT(4, 1, 1, 3, 384),
  1, &serving_default_input_10_output_array, &serving_default_input_10_output_array_intq)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  206, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 128, 128), AI_STRIDE_INIT(4, 1, 1, 3, 384),
  1, &conversion_0_output_array, &conversion_0_output_array_intq)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  207, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  208, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_1_output_array, &conv2d_1_output_array_intq)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_pad_before_output, AI_STATIC,
  209, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 66, 66), AI_STRIDE_INIT(4, 1, 1, 16, 1056),
  1, &conv2d_2_pad_before_output_array, &conv2d_2_pad_before_output_array_intq)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch1, AI_STATIC,
  210, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 64, 64), AI_STRIDE_INIT(4, 1, 1, 48, 3072),
  1, &conv2d_4_scratch1_array, &conv2d_4_scratch1_array_intq)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  211, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_2_output_array, &conv2d_2_output_array_intq)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  212, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 64, 64), AI_STRIDE_INIT(4, 1, 1, 8, 512),
  1, &conv2d_3_output_array, &conv2d_3_output_array_intq)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  213, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 64, 64), AI_STRIDE_INIT(4, 1, 1, 48, 3072),
  1, &conv2d_4_output_array, &conv2d_4_output_array_intq)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_pad_before_output, AI_STATIC,
  215, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 65, 65), AI_STRIDE_INIT(4, 1, 1, 48, 3120),
  1, &conv2d_6_pad_before_output_array, &conv2d_6_pad_before_output_array_intq)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  216, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_6_output_array, &conv2d_6_output_array_intq)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch1, AI_STATIC,
  217, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_6_scratch1_array, &conv2d_6_scratch1_array_intq)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  218, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &conv2d_7_output_array, &conv2d_7_output_array_intq)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  219, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_8_output_array, &conv2d_8_output_array_intq)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_pad_before_output, AI_STATIC,
  220, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 34, 34), AI_STRIDE_INIT(4, 1, 1, 48, 1632),
  1, &conv2d_9_pad_before_output_array, &conv2d_9_pad_before_output_array_intq)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  222, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_9_output_array, &conv2d_9_output_array_intq)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  223, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &conv2d_10_output_array, &conv2d_10_output_array_intq)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_output, AI_STATIC,
  224, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &eltwise_11_output_array, &eltwise_11_output_array_intq)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  225, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  226, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_12_output_array, &conv2d_12_output_array_intq)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_pad_before_output, AI_STATIC,
  227, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 33, 33), AI_STRIDE_INIT(4, 1, 1, 48, 1584),
  1, &conv2d_14_pad_before_output_array, &conv2d_14_pad_before_output_array_intq)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch1, AI_STATIC,
  228, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_8_scratch1_array, &conv2d_8_scratch1_array_intq)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  229, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 1, 1, 48, 768),
  1, &conv2d_14_output_array, &conv2d_14_output_array_intq)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  230, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_15_output_array, &conv2d_15_output_array_intq)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  231, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_16_output_array, &conv2d_16_output_array_intq)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  232, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_pad_before_output, AI_STATIC,
  233, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 18, 18), AI_STRIDE_INIT(4, 1, 1, 96, 1728),
  1, &conv2d_17_pad_before_output_array, &conv2d_17_pad_before_output_array_intq)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  234, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_17_output_array, &conv2d_17_output_array_intq)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch1, AI_STATIC,
  235, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_9_scratch1_array, &conv2d_9_scratch1_array_intq)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  236, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_18_output_array, &conv2d_18_output_array_intq)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_19_output, AI_STATIC,
  237, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &eltwise_19_output_array, &eltwise_19_output_array_intq)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  238, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_20_output_array, &conv2d_20_output_array_intq)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  239, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_pad_before_output, AI_STATIC,
  240, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 18, 18), AI_STRIDE_INIT(4, 1, 1, 96, 1728),
  1, &conv2d_21_pad_before_output_array, &conv2d_21_pad_before_output_array_intq)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  241, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_21_output_array, &conv2d_21_output_array_intq)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  242, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_22_output_array, &conv2d_22_output_array_intq)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  243, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_23_output, AI_STATIC,
  244, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &eltwise_23_output_array, &eltwise_23_output_array_intq)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  245, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_24_output_array, &conv2d_24_output_array_intq)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch1, AI_STATIC,
  246, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_12_scratch1_array, &conv2d_12_scratch1_array_intq)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_pad_before_output, AI_STATIC,
  247, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 17, 17), AI_STRIDE_INIT(4, 1, 1, 96, 1632),
  1, &conv2d_26_pad_before_output_array, &conv2d_26_pad_before_output_array_intq)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  248, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 8, 8), AI_STRIDE_INIT(4, 1, 1, 96, 768),
  1, &conv2d_26_output_array, &conv2d_26_output_array_intq)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  249, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_27_output_array, &conv2d_27_output_array_intq)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  250, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  251, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_28_output_array, &conv2d_28_output_array_intq)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_pad_before_output, AI_STATIC,
  252, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 10, 10), AI_STRIDE_INIT(4, 1, 1, 144, 1440),
  1, &conv2d_29_pad_before_output_array, &conv2d_29_pad_before_output_array_intq)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch1, AI_STATIC,
  253, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 1, 1, 48, 768),
  1, &conv2d_14_scratch1_array, &conv2d_14_scratch1_array_intq)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  254, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_29_output_array, &conv2d_29_output_array_intq)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  255, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_30_output_array, &conv2d_30_output_array_intq)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_31_output, AI_STATIC,
  256, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &eltwise_31_output_array, &eltwise_31_output_array_intq)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  257, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_output, AI_STATIC,
  258, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_32_output_array, &conv2d_32_output_array_intq)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_pad_before_output, AI_STATIC,
  259, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 10, 10), AI_STRIDE_INIT(4, 1, 1, 144, 1440),
  1, &conv2d_33_pad_before_output_array, &conv2d_33_pad_before_output_array_intq)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  260, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_33_output_array, &conv2d_33_output_array_intq)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  261, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #262 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  262, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_34_output_array, &conv2d_34_output_array_intq)

/* Tensor #263 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_35_output, AI_STATIC,
  263, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &eltwise_35_output_array, &eltwise_35_output_array_intq)

/* Tensor #264 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch1, AI_STATIC,
  264, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_16_scratch1_array, &conv2d_16_scratch1_array_intq)

/* Tensor #265 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  265, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_36_output_array, &conv2d_36_output_array_intq)

/* Tensor #266 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_pad_before_output, AI_STATIC,
  266, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 10, 10), AI_STRIDE_INIT(4, 1, 1, 144, 1440),
  1, &conv2d_37_pad_before_output_array, &conv2d_37_pad_before_output_array_intq)

/* Tensor #267 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  267, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_37_output_array, &conv2d_37_output_array_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_70_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_70_layer, 70,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_70_chain,
  NULL, &conversion_70_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i32 nl_69_nl_params_data[] = { 1565345152, 20, -1984 };
AI_ARRAY_OBJ_DECLARE(
    nl_69_nl_params, AI_ARRAY_FORMAT_S32,
    nl_69_nl_params_data, nl_69_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_69_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_69_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  nl_69_layer, 69,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm_integer,
  &nl_69_chain,
  NULL, &conversion_70_layer, AI_STATIC, 
  .nl_params = &nl_69_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_68_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_68_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_68_weights, &gemm_68_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_68_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_68_layer, 68,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_68_chain,
  NULL, &nl_69_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_67_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_67_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_67_layer, 67,
  POOL_TYPE, 0x0, NULL,
  pool, forward_ap_integer_INT8,
  &pool_67_chain,
  NULL, &gemm_68_layer, AI_STATIC, 
  .pool_size = AI_SHAPE_2D_INIT(4, 4), 
  .pool_stride = AI_SHAPE_2D_INIT(4, 4), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_66_weights, &conv2d_66_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_66_scratch0, &conv2d_66_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_66_layer, 66,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_66_chain,
  NULL, &pool_67_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_65_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_65_weights, &conv2d_65_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_65_layer, 65,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_65_chain,
  NULL, &conv2d_66_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_64_weights, &conv2d_64_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_64_scratch0, &conv2d_64_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_64_layer, 64,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_64_chain,
  NULL, &conv2d_65_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_64_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_64_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_64_pad_before_value_data, conv2d_64_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_64_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_63_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_64_pad_before_layer, 64,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_64_pad_before_chain,
  NULL, &conv2d_64_layer, AI_STATIC, 
  .value = &conv2d_64_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_63_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_63_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_63_weights, &conv2d_63_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_63_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_63_layer, 63,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_63_chain,
  NULL, &conv2d_64_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_58_output, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_62_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_62_layer, 62,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_62_chain,
  NULL, &conv2d_63_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_61_weights, &conv2d_61_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_61_layer, 61,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_61_chain,
  NULL, &eltwise_62_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_60_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_60_weights, &conv2d_60_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_60_layer, 60,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_60_chain,
  NULL, &conv2d_61_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_60_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_60_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_60_pad_before_value_data, conv2d_60_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_60_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_60_pad_before_layer, 60,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_60_pad_before_chain,
  NULL, &conv2d_60_layer, AI_STATIC, 
  .value = &conv2d_60_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_58_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_59_weights, &conv2d_59_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_59_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_59_layer, 59,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_59_chain,
  NULL, &conv2d_60_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_54_output, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_58_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_58_layer, 58,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_58_chain,
  NULL, &conv2d_59_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_57_weights, &conv2d_57_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_57_layer, 57,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_57_chain,
  NULL, &eltwise_58_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_56_weights, &conv2d_56_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_layer, 56,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_56_chain,
  NULL, &conv2d_57_layer, AI_STATIC, 
  .groups = 336, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_56_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_56_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_56_pad_before_value_data, conv2d_56_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_pad_before_layer, 56,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_56_pad_before_chain,
  NULL, &conv2d_56_layer, AI_STATIC, 
  .value = &conv2d_56_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_55_weights, &conv2d_55_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_55_layer, 55,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_55_chain,
  NULL, &conv2d_56_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_54_weights, &conv2d_54_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_54_layer, 54,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_54_chain,
  NULL, &conv2d_55_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_53_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_53_weights, &conv2d_53_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_53_scratch0, &conv2d_53_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_53_layer, 52,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_53_chain,
  NULL, &conv2d_54_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_53_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_53_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_53_pad_before_value_data, conv2d_53_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_53_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_53_pad_before_layer, 53,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_53_pad_before_chain,
  NULL, &conv2d_53_layer, AI_STATIC, 
  .value = &conv2d_53_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_51_weights, &conv2d_51_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_51_scratch0, &conv2d_51_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_51_layer, 51,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_51_chain,
  NULL, &conv2d_53_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_46_output, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_50_layer, 50,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_50_chain,
  NULL, &conv2d_51_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_49_weights, &conv2d_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_49_layer, 49,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_49_chain,
  NULL, &eltwise_50_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_48_weights, &conv2d_48_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_layer, 48,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_48_chain,
  NULL, &conv2d_49_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_48_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_48_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_48_pad_before_value_data, conv2d_48_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_pad_before_layer, 48,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_48_pad_before_chain,
  NULL, &conv2d_48_layer, AI_STATIC, 
  .value = &conv2d_48_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_47_weights, &conv2d_47_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_47_layer, 47,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_47_chain,
  NULL, &conv2d_48_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_42_output, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_46_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_46_layer, 46,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_46_chain,
  NULL, &conv2d_47_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_45_weights, &conv2d_45_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_45_layer, 45,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_45_chain,
  NULL, &eltwise_46_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_44_weights, &conv2d_44_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_layer, 44,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_44_chain,
  NULL, &conv2d_45_layer, AI_STATIC, 
  .groups = 192, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_44_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_44_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_44_pad_before_value_data, conv2d_44_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_pad_before_layer, 44,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_44_pad_before_chain,
  NULL, &conv2d_44_layer, AI_STATIC, 
  .value = &conv2d_44_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_43_weights, &conv2d_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_43_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_43_chain,
  NULL, &conv2d_44_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_42_weights, &conv2d_42_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_42_layer, 42,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_42_chain,
  NULL, &conv2d_43_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_41_weights, &conv2d_41_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_41_scratch0, &conv2d_41_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_layer, 41,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_41_chain,
  NULL, &conv2d_42_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_41_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_41_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_41_pad_before_value_data, conv2d_41_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_pad_before_layer, 41,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_41_pad_before_chain,
  NULL, &conv2d_41_layer, AI_STATIC, 
  .value = &conv2d_41_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_40_weights, &conv2d_40_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_40_scratch0, &conv2d_40_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_40_layer, 40,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_40_chain,
  NULL, &conv2d_41_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_35_output, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_39_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_39_layer, 39,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_39_chain,
  NULL, &conv2d_40_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_38_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 38,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_38_chain,
  NULL, &eltwise_39_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_37_scratch0, &conv2d_37_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 37,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_37_chain,
  NULL, &conv2d_38_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_37_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_37_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_37_pad_before_value_data, conv2d_37_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_pad_before_layer, 37,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_37_pad_before_chain,
  NULL, &conv2d_37_layer, AI_STATIC, 
  .value = &conv2d_37_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 36,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_36_chain,
  NULL, &conv2d_37_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_31_output, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_35_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_35_layer, 35,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_35_chain,
  NULL, &conv2d_36_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 34,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_34_chain,
  NULL, &eltwise_35_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_33_scratch0, &conv2d_33_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_33_chain,
  NULL, &conv2d_34_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_33_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_33_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_33_pad_before_value_data, conv2d_33_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_pad_before_layer, 33,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_33_pad_before_chain,
  NULL, &conv2d_33_layer, AI_STATIC, 
  .value = &conv2d_33_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_32_weights, &conv2d_32_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_32_scratch0, &conv2d_32_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_32_layer, 32,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_32_chain,
  NULL, &conv2d_33_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_output, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_31_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_31_layer, 31,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_31_chain,
  NULL, &conv2d_32_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_30_chain,
  NULL, &eltwise_31_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_29_scratch0, &conv2d_29_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 29,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_29_chain,
  NULL, &conv2d_30_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_29_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_29_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_29_pad_before_value_data, conv2d_29_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_pad_before_layer, 29,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_29_pad_before_chain,
  NULL, &conv2d_29_layer, AI_STATIC, 
  .value = &conv2d_29_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_28_scratch0, &conv2d_28_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_28_chain,
  NULL, &conv2d_29_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_27_chain,
  NULL, &conv2d_28_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 26,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_26_chain,
  NULL, &conv2d_27_layer, AI_STATIC, 
  .groups = 96, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_26_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_26_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_26_pad_before_value_data, conv2d_26_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_pad_before_layer, 25,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_26_pad_before_chain,
  NULL, &conv2d_26_layer, AI_STATIC, 
  .value = &conv2d_26_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_24_scratch0, &conv2d_24_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_24_chain,
  NULL, &conv2d_26_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_19_output, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_23_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_23_layer, 23,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_23_chain,
  NULL, &conv2d_24_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_22_chain,
  NULL, &eltwise_23_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_scratch0, &conv2d_21_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_21_chain,
  NULL, &conv2d_22_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_21_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_21_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_21_pad_before_value_data, conv2d_21_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_pad_before_layer, 21,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_21_pad_before_chain,
  NULL, &conv2d_21_layer, AI_STATIC, 
  .value = &conv2d_21_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_20_scratch0, &conv2d_20_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_20_chain,
  NULL, &conv2d_21_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_output, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_19_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_19_layer, 19,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_19_chain,
  NULL, &conv2d_20_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_18_chain,
  NULL, &eltwise_19_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_scratch0, &conv2d_17_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_17_chain,
  NULL, &conv2d_18_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_17_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_17_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_17_pad_before_value_data, conv2d_17_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_pad_before_layer, 17,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_17_pad_before_chain,
  NULL, &conv2d_17_layer, AI_STATIC, 
  .value = &conv2d_17_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_scratch0, &conv2d_16_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_16_chain,
  NULL, &conv2d_17_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_15_chain,
  NULL, &conv2d_16_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_14_scratch0, &conv2d_14_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_14_chain,
  NULL, &conv2d_15_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_14_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_14_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_14_pad_before_value_data, conv2d_14_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_pad_before_layer, 14,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_14_pad_before_chain,
  NULL, &conv2d_14_layer, AI_STATIC, 
  .value = &conv2d_14_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_12_scratch0, &conv2d_12_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_12_chain,
  NULL, &conv2d_14_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_output, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_11_layer, 11,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_11_chain,
  NULL, &conv2d_12_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_10_chain,
  NULL, &eltwise_11_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_scratch0, &conv2d_9_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_9_chain,
  NULL, &conv2d_10_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_9_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_9_pad_before_value_data, conv2d_9_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_pad_before_layer, 9,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_9_pad_before_chain,
  NULL, &conv2d_9_layer, AI_STATIC, 
  .value = &conv2d_9_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_scratch0, &conv2d_8_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_8_chain,
  NULL, &conv2d_9_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_7_chain,
  NULL, &conv2d_8_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_scratch0, &conv2d_6_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_6_chain,
  NULL, &conv2d_7_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_6_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_6_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_6_pad_before_value_data, conv2d_6_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_pad_before_layer, 6,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_6_pad_before_chain,
  NULL, &conv2d_6_layer, AI_STATIC, 
  .value = &conv2d_6_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_4_scratch0, &conv2d_4_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_4_chain,
  NULL, &conv2d_6_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_pw_sssa8_ch,
  &conv2d_3_chain,
  NULL, &conv2d_4_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_dw_3x3_sssa8_ch,
  &conv2d_2_chain,
  NULL, &conv2d_3_layer, AI_STATIC, 
  .groups = 16, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_2_pad_before_value_data[] = { -128 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_2_pad_before_value_data, conv2d_2_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_pad_before_layer, 2,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_2_pad_before_chain,
  NULL, &conv2d_2_layer, AI_STATIC, 
  .value = &conv2d_2_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 1,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_rgb_sssa8_ch,
  &conv2d_1_chain,
  NULL, &conv2d_2_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_0_chain,
  NULL, &conv2d_1_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 420480, 1, 1),
    420480, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 229888, 1, 1),
    229888, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_input_10_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &conversion_70_output),
  &conversion_0_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 420480, 1, 1),
      420480, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 229888, 1, 1),
      229888, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_input_10_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &conversion_70_output),
  &conversion_0_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_input_10_output_array.data = AI_PTR(g_network_activations_map[0] + 23124);
    serving_default_input_10_output_array.data_start = AI_PTR(g_network_activations_map[0] + 23124);
    
    conversion_0_output_array.data = AI_PTR(g_network_activations_map[0] + 23120);
    conversion_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 23120);
    
    conv2d_1_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 72276);
    conv2d_1_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 72276);
    
    conv2d_1_output_array.data = AI_PTR(g_network_activations_map[0] + 5696);
    conv2d_1_output_array.data_start = AI_PTR(g_network_activations_map[0] + 5696);
    
    conv2d_2_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 1536);
    conv2d_2_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1536);
    
    conv2d_2_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 71232);
    conv2d_2_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 71232);
    
    conv2d_2_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 512);
    conv2d_2_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 512);
    
    conv2d_2_output_array.data = AI_PTR(g_network_activations_map[0] + 512);
    conv2d_2_output_array.data_start = AI_PTR(g_network_activations_map[0] + 512);
    
    conv2d_3_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 66048);
    conv2d_3_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 66048);
    
    conv2d_3_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_3_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_4_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 32768);
    conv2d_4_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 32768);
    
    conv2d_4_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 33280);
    conv2d_4_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 33280);
    
    conv2d_4_output_array.data = AI_PTR(g_network_activations_map[0] + 33280);
    conv2d_4_output_array.data_start = AI_PTR(g_network_activations_map[0] + 33280);
    
    conv2d_6_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 27088);
    conv2d_6_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 27088);
    
    conv2d_6_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_6_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_6_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 25552);
    conv2d_6_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 25552);
    
    conv2d_6_output_array.data = AI_PTR(g_network_activations_map[0] + 25552);
    conv2d_6_output_array.data_start = AI_PTR(g_network_activations_map[0] + 25552);
    
    conv2d_7_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_7_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_7_output_array.data = AI_PTR(g_network_activations_map[0] + 272);
    conv2d_7_output_array.data_start = AI_PTR(g_network_activations_map[0] + 272);
    
    conv2d_8_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 8464);
    conv2d_8_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 8464);
    
    conv2d_8_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 8976);
    conv2d_8_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 8976);
    
    conv2d_8_output_array.data = AI_PTR(g_network_activations_map[0] + 58128);
    conv2d_8_output_array.data_start = AI_PTR(g_network_activations_map[0] + 58128);
    
    conv2d_9_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 107280);
    conv2d_9_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 107280);
    
    conv2d_9_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 8464);
    conv2d_9_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 8464);
    
    conv2d_9_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 10244);
    conv2d_9_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 10244);
    
    conv2d_9_output_array.data = AI_PTR(g_network_activations_map[0] + 162768);
    conv2d_9_output_array.data_start = AI_PTR(g_network_activations_map[0] + 162768);
    
    conv2d_10_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_10_output_array.data = AI_PTR(g_network_activations_map[0] + 8464);
    conv2d_10_output_array.data_start = AI_PTR(g_network_activations_map[0] + 8464);
    
    eltwise_11_output_array.data = AI_PTR(g_network_activations_map[0] + 16656);
    eltwise_11_output_array.data_start = AI_PTR(g_network_activations_map[0] + 16656);
    
    conv2d_12_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_12_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 24848);
    conv2d_12_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 24848);
    
    conv2d_12_output_array.data = AI_PTR(g_network_activations_map[0] + 74000);
    conv2d_12_output_array.data_start = AI_PTR(g_network_activations_map[0] + 74000);
    
    conv2d_14_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_14_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_14_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 52272);
    conv2d_14_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 52272);
    
    conv2d_14_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 54052);
    conv2d_14_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 54052);
    
    conv2d_14_output_array.data = AI_PTR(g_network_activations_map[0] + 66340);
    conv2d_14_output_array.data_start = AI_PTR(g_network_activations_map[0] + 66340);
    
    conv2d_15_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_15_output_array.data = AI_PTR(g_network_activations_map[0] + 352);
    conv2d_15_output_array.data_start = AI_PTR(g_network_activations_map[0] + 352);
    
    conv2d_16_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 4448);
    conv2d_16_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 4448);
    
    conv2d_16_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 5472);
    conv2d_16_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 5472);
    
    conv2d_16_output_array.data = AI_PTR(g_network_activations_map[0] + 30048);
    conv2d_16_output_array.data_start = AI_PTR(g_network_activations_map[0] + 30048);
    
    conv2d_17_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 54624);
    conv2d_17_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 54624);
    
    conv2d_17_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 4448);
    conv2d_17_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 4448);
    
    conv2d_17_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 8004);
    conv2d_17_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 8004);
    
    conv2d_17_output_array.data = AI_PTR(g_network_activations_map[0] + 85728);
    conv2d_17_output_array.data_start = AI_PTR(g_network_activations_map[0] + 85728);
    
    conv2d_18_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 4448);
    conv2d_18_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 4448);
    
    conv2d_18_output_array.data = AI_PTR(g_network_activations_map[0] + 4992);
    conv2d_18_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4992);
    
    eltwise_19_output_array.data = AI_PTR(g_network_activations_map[0] + 9088);
    eltwise_19_output_array.data_start = AI_PTR(g_network_activations_map[0] + 9088);
    
    conv2d_20_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_20_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_20_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 13184);
    conv2d_20_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 13184);
    
    conv2d_20_output_array.data = AI_PTR(g_network_activations_map[0] + 37760);
    conv2d_20_output_array.data_start = AI_PTR(g_network_activations_map[0] + 37760);
    
    conv2d_21_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 62336);
    conv2d_21_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 62336);
    
    conv2d_21_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_21_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 13184);
    conv2d_21_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 13184);
    
    conv2d_21_output_array.data = AI_PTR(g_network_activations_map[0] + 37760);
    conv2d_21_output_array.data_start = AI_PTR(g_network_activations_map[0] + 37760);
    
    conv2d_22_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_22_output_array.data = AI_PTR(g_network_activations_map[0] + 544);
    conv2d_22_output_array.data_start = AI_PTR(g_network_activations_map[0] + 544);
    
    eltwise_23_output_array.data = AI_PTR(g_network_activations_map[0] + 4640);
    eltwise_23_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4640);
    
    conv2d_24_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_24_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_24_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 8736);
    conv2d_24_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 8736);
    
    conv2d_24_output_array.data = AI_PTR(g_network_activations_map[0] + 33312);
    conv2d_24_output_array.data_start = AI_PTR(g_network_activations_map[0] + 33312);
    
    conv2d_26_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_26_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_26_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 27744);
    conv2d_26_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 27744);
    
    conv2d_26_output_array.data = AI_PTR(g_network_activations_map[0] + 31300);
    conv2d_26_output_array.data_start = AI_PTR(g_network_activations_map[0] + 31300);
    
    conv2d_27_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_27_output_array.data = AI_PTR(g_network_activations_map[0] + 624);
    conv2d_27_output_array.data_start = AI_PTR(g_network_activations_map[0] + 624);
    
    conv2d_28_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2160);
    conv2d_28_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2160);
    
    conv2d_28_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 3696);
    conv2d_28_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 3696);
    
    conv2d_28_output_array.data = AI_PTR(g_network_activations_map[0] + 12912);
    conv2d_28_output_array.data_start = AI_PTR(g_network_activations_map[0] + 12912);
    
    conv2d_29_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 22128);
    conv2d_29_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 22128);
    
    conv2d_29_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2160);
    conv2d_29_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2160);
    
    conv2d_29_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 7492);
    conv2d_29_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 7492);
    
    conv2d_29_output_array.data = AI_PTR(g_network_activations_map[0] + 36528);
    conv2d_29_output_array.data_start = AI_PTR(g_network_activations_map[0] + 36528);
    
    conv2d_30_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2160);
    conv2d_30_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2160);
    
    conv2d_30_output_array.data = AI_PTR(g_network_activations_map[0] + 2976);
    conv2d_30_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2976);
    
    eltwise_31_output_array.data = AI_PTR(g_network_activations_map[0] + 4512);
    eltwise_31_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4512);
    
    conv2d_32_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_32_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_32_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 6048);
    conv2d_32_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 6048);
    
    conv2d_32_output_array.data = AI_PTR(g_network_activations_map[0] + 15264);
    conv2d_32_output_array.data_start = AI_PTR(g_network_activations_map[0] + 15264);
    
    conv2d_33_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 24480);
    conv2d_33_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 24480);
    
    conv2d_33_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 6048);
    conv2d_33_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 6048);
    
    conv2d_33_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 11380);
    conv2d_33_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 11380);
    
    conv2d_33_output_array.data = AI_PTR(g_network_activations_map[0] + 38880);
    conv2d_33_output_array.data_start = AI_PTR(g_network_activations_map[0] + 38880);
    
    conv2d_34_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_34_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_34_output_array.data = AI_PTR(g_network_activations_map[0] + 816);
    conv2d_34_output_array.data_start = AI_PTR(g_network_activations_map[0] + 816);
    
    eltwise_35_output_array.data = AI_PTR(g_network_activations_map[0] + 2352);
    eltwise_35_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2352);
    
    conv2d_36_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_36_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_36_output_array.data = AI_PTR(g_network_activations_map[0] + 3888);
    conv2d_36_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3888);
    
    conv2d_37_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 13104);
    conv2d_37_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 13104);
    
    conv2d_37_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 3888);
    conv2d_37_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 3888);
    
    conv2d_37_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 27504);
    conv2d_37_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 27504);
    
    conv2d_37_output_array.data = AI_PTR(g_network_activations_map[0] + 36720);
    conv2d_37_output_array.data_start = AI_PTR(g_network_activations_map[0] + 36720);
    
    conv2d_38_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_38_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_38_output_array.data = AI_PTR(g_network_activations_map[0] + 816);
    conv2d_38_output_array.data_start = AI_PTR(g_network_activations_map[0] + 816);
    
    eltwise_39_output_array.data = AI_PTR(g_network_activations_map[0] + 3888);
    eltwise_39_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3888);
    
    conv2d_40_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_40_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_40_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 5424);
    conv2d_40_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 5424);
    
    conv2d_40_output_array.data = AI_PTR(g_network_activations_map[0] + 14640);
    conv2d_40_output_array.data_start = AI_PTR(g_network_activations_map[0] + 14640);
    
    conv2d_41_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_41_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_41_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 14400);
    conv2d_41_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 14400);
    
    conv2d_41_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 19732);
    conv2d_41_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 19732);
    
    conv2d_41_output_array.data = AI_PTR(g_network_activations_map[0] + 28948);
    conv2d_41_output_array.data_start = AI_PTR(g_network_activations_map[0] + 28948);
    
    conv2d_42_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_42_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_42_output_array.data = AI_PTR(g_network_activations_map[0] + 896);
    conv2d_42_output_array.data_start = AI_PTR(g_network_activations_map[0] + 896);
    
    conv2d_43_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2944);
    conv2d_43_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2944);
    
    conv2d_43_output_array.data = AI_PTR(g_network_activations_map[0] + 4992);
    conv2d_43_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4992);
    
    conv2d_44_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 17280);
    conv2d_44_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 17280);
    
    conv2d_44_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2944);
    conv2d_44_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2944);
    
    conv2d_44_output_array.data = AI_PTR(g_network_activations_map[0] + 36480);
    conv2d_44_output_array.data_start = AI_PTR(g_network_activations_map[0] + 36480);
    
    conv2d_45_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2944);
    conv2d_45_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2944);
    
    conv2d_45_output_array.data = AI_PTR(g_network_activations_map[0] + 4032);
    conv2d_45_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4032);
    
    eltwise_46_output_array.data = AI_PTR(g_network_activations_map[0] + 6080);
    eltwise_46_output_array.data_start = AI_PTR(g_network_activations_map[0] + 6080);
    
    conv2d_47_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_47_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_47_output_array.data = AI_PTR(g_network_activations_map[0] + 8128);
    conv2d_47_output_array.data_start = AI_PTR(g_network_activations_map[0] + 8128);
    
    conv2d_48_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 20416);
    conv2d_48_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 20416);
    
    conv2d_48_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 8128);
    conv2d_48_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 8128);
    
    conv2d_48_output_array.data = AI_PTR(g_network_activations_map[0] + 39616);
    conv2d_48_output_array.data_start = AI_PTR(g_network_activations_map[0] + 39616);
    
    conv2d_49_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_49_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_49_output_array.data = AI_PTR(g_network_activations_map[0] + 1088);
    conv2d_49_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1088);
    
    eltwise_50_output_array.data = AI_PTR(g_network_activations_map[0] + 3136);
    eltwise_50_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3136);
    
    conv2d_51_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_51_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_51_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 5184);
    conv2d_51_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 5184);
    
    conv2d_51_output_array.data = AI_PTR(g_network_activations_map[0] + 17472);
    conv2d_51_output_array.data_start = AI_PTR(g_network_activations_map[0] + 17472);
    
    conv2d_53_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_53_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_53_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 15552);
    conv2d_53_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 15552);
    
    conv2d_53_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 22660);
    conv2d_53_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 22660);
    
    conv2d_53_output_array.data = AI_PTR(g_network_activations_map[0] + 25732);
    conv2d_53_output_array.data_start = AI_PTR(g_network_activations_map[0] + 25732);
    
    conv2d_54_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_54_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_54_output_array.data = AI_PTR(g_network_activations_map[0] + 1328);
    conv2d_54_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1328);
    
    conv2d_55_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 2224);
    conv2d_55_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 2224);
    
    conv2d_55_output_array.data = AI_PTR(g_network_activations_map[0] + 5808);
    conv2d_55_output_array.data_start = AI_PTR(g_network_activations_map[0] + 5808);
    
    conv2d_56_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 11184);
    conv2d_56_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 11184);
    
    conv2d_56_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 23280);
    conv2d_56_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 23280);
    
    conv2d_56_output_array.data = AI_PTR(g_network_activations_map[0] + 2224);
    conv2d_56_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2224);
    
    conv2d_57_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 7600);
    conv2d_57_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 7600);
    
    conv2d_57_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_57_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    eltwise_58_output_array.data = AI_PTR(g_network_activations_map[0] + 2224);
    eltwise_58_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2224);
    
    conv2d_59_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 3120);
    conv2d_59_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 3120);
    
    conv2d_59_output_array.data = AI_PTR(g_network_activations_map[0] + 6704);
    conv2d_59_output_array.data_start = AI_PTR(g_network_activations_map[0] + 6704);
    
    conv2d_60_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 12080);
    conv2d_60_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 12080);
    
    conv2d_60_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 24176);
    conv2d_60_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 24176);
    
    conv2d_60_output_array.data = AI_PTR(g_network_activations_map[0] + 3120);
    conv2d_60_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3120);
    
    conv2d_61_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_61_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_61_output_array.data = AI_PTR(g_network_activations_map[0] + 8496);
    conv2d_61_output_array.data_start = AI_PTR(g_network_activations_map[0] + 8496);
    
    eltwise_62_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    eltwise_62_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_63_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 896);
    conv2d_63_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 896);
    
    conv2d_63_output_array.data = AI_PTR(g_network_activations_map[0] + 4480);
    conv2d_63_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4480);
    
    conv2d_64_pad_before_output_array.data = AI_PTR(g_network_activations_map[0] + 9856);
    conv2d_64_pad_before_output_array.data_start = AI_PTR(g_network_activations_map[0] + 9856);
    
    conv2d_64_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 21952);
    conv2d_64_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 21952);
    
    conv2d_64_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_64_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_64_output_array.data = AI_PTR(g_network_activations_map[0] + 34388);
    conv2d_64_output_array.data_start = AI_PTR(g_network_activations_map[0] + 34388);
    
    conv2d_65_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conv2d_65_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    conv2d_65_output_array.data = AI_PTR(g_network_activations_map[0] + 2464);
    conv2d_65_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2464);
    
    conv2d_66_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 4256);
    conv2d_66_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 4256);
    
    conv2d_66_scratch1_array.data = AI_PTR(g_network_activations_map[0] + 17504);
    conv2d_66_scratch1_array.data_start = AI_PTR(g_network_activations_map[0] + 17504);
    
    conv2d_66_output_array.data = AI_PTR(g_network_activations_map[0] + 37984);
    conv2d_66_output_array.data_start = AI_PTR(g_network_activations_map[0] + 37984);
    
    pool_67_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    pool_67_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    gemm_68_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 1280);
    gemm_68_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 1280);
    
    gemm_68_output_array.data = AI_PTR(g_network_activations_map[0] + 3840);
    gemm_68_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3840);
    
    nl_69_scratch0_array.data = AI_PTR(g_network_activations_map[0] + 0);
    nl_69_scratch0_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    nl_69_output_array.data = AI_PTR(g_network_activations_map[0] + 32);
    nl_69_output_array.data_start = AI_PTR(g_network_activations_map[0] + 32);
    
    conversion_70_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    conversion_70_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(g_network_weights_map[0] + 0);
    conv2d_1_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 0);
    
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(g_network_weights_map[0] + 432);
    conv2d_1_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 432);
    
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(g_network_weights_map[0] + 496);
    conv2d_2_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 496);
    
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(g_network_weights_map[0] + 640);
    conv2d_2_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 640);
    
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(g_network_weights_map[0] + 704);
    conv2d_3_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 704);
    
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(g_network_weights_map[0] + 832);
    conv2d_3_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 832);
    
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(g_network_weights_map[0] + 864);
    conv2d_4_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 864);
    
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(g_network_weights_map[0] + 1248);
    conv2d_4_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1248);
    
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(g_network_weights_map[0] + 1440);
    conv2d_6_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1440);
    
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(g_network_weights_map[0] + 1872);
    conv2d_6_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1872);
    
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(g_network_weights_map[0] + 2064);
    conv2d_7_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 2064);
    
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(g_network_weights_map[0] + 2448);
    conv2d_7_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 2448);
    
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(g_network_weights_map[0] + 2480);
    conv2d_8_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 2480);
    
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(g_network_weights_map[0] + 2864);
    conv2d_8_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 2864);
    
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(g_network_weights_map[0] + 3056);
    conv2d_9_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 3056);
    
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(g_network_weights_map[0] + 3488);
    conv2d_9_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 3488);
    
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(g_network_weights_map[0] + 3680);
    conv2d_10_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 3680);
    
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(g_network_weights_map[0] + 4064);
    conv2d_10_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 4064);
    
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(g_network_weights_map[0] + 4096);
    conv2d_12_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 4096);
    
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(g_network_weights_map[0] + 4480);
    conv2d_12_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 4480);
    
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(g_network_weights_map[0] + 4672);
    conv2d_14_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 4672);
    
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(g_network_weights_map[0] + 5104);
    conv2d_14_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 5104);
    
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(g_network_weights_map[0] + 5296);
    conv2d_15_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 5296);
    
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(g_network_weights_map[0] + 6064);
    conv2d_15_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 6064);
    
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(g_network_weights_map[0] + 6128);
    conv2d_16_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 6128);
    
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(g_network_weights_map[0] + 7664);
    conv2d_16_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 7664);
    
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(g_network_weights_map[0] + 8048);
    conv2d_17_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 8048);
    
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(g_network_weights_map[0] + 8912);
    conv2d_17_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 8912);
    
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(g_network_weights_map[0] + 9296);
    conv2d_18_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 9296);
    
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(g_network_weights_map[0] + 10832);
    conv2d_18_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 10832);
    
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(g_network_weights_map[0] + 10896);
    conv2d_20_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 10896);
    
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(g_network_weights_map[0] + 12432);
    conv2d_20_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 12432);
    
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(g_network_weights_map[0] + 12816);
    conv2d_21_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 12816);
    
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(g_network_weights_map[0] + 13680);
    conv2d_21_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 13680);
    
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(g_network_weights_map[0] + 14064);
    conv2d_22_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 14064);
    
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(g_network_weights_map[0] + 15600);
    conv2d_22_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 15600);
    
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(g_network_weights_map[0] + 15664);
    conv2d_24_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 15664);
    
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(g_network_weights_map[0] + 17200);
    conv2d_24_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 17200);
    
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(g_network_weights_map[0] + 17584);
    conv2d_26_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 17584);
    
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(g_network_weights_map[0] + 18448);
    conv2d_26_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 18448);
    
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(g_network_weights_map[0] + 18832);
    conv2d_27_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 18832);
    
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(g_network_weights_map[0] + 21136);
    conv2d_27_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 21136);
    
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(g_network_weights_map[0] + 21232);
    conv2d_28_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 21232);
    
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(g_network_weights_map[0] + 24688);
    conv2d_28_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 24688);
    
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(g_network_weights_map[0] + 25264);
    conv2d_29_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 25264);
    
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(g_network_weights_map[0] + 26560);
    conv2d_29_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 26560);
    
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(g_network_weights_map[0] + 27136);
    conv2d_30_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 27136);
    
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(g_network_weights_map[0] + 30592);
    conv2d_30_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 30592);
    
    conv2d_32_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_weights_array.data = AI_PTR(g_network_weights_map[0] + 30688);
    conv2d_32_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 30688);
    
    conv2d_32_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_bias_array.data = AI_PTR(g_network_weights_map[0] + 34144);
    conv2d_32_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 34144);
    
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(g_network_weights_map[0] + 34720);
    conv2d_33_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 34720);
    
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(g_network_weights_map[0] + 36016);
    conv2d_33_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 36016);
    
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(g_network_weights_map[0] + 36592);
    conv2d_34_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 36592);
    
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(g_network_weights_map[0] + 40048);
    conv2d_34_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 40048);
    
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(g_network_weights_map[0] + 40144);
    conv2d_36_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 40144);
    
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(g_network_weights_map[0] + 43600);
    conv2d_36_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 43600);
    
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(g_network_weights_map[0] + 44176);
    conv2d_37_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 44176);
    
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(g_network_weights_map[0] + 45472);
    conv2d_37_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 45472);
    
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(g_network_weights_map[0] + 46048);
    conv2d_38_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 46048);
    
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(g_network_weights_map[0] + 49504);
    conv2d_38_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 49504);
    
    conv2d_40_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_weights_array.data = AI_PTR(g_network_weights_map[0] + 49600);
    conv2d_40_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 49600);
    
    conv2d_40_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_bias_array.data = AI_PTR(g_network_weights_map[0] + 53056);
    conv2d_40_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 53056);
    
    conv2d_41_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_weights_array.data = AI_PTR(g_network_weights_map[0] + 53632);
    conv2d_41_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 53632);
    
    conv2d_41_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_bias_array.data = AI_PTR(g_network_weights_map[0] + 54928);
    conv2d_41_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 54928);
    
    conv2d_42_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_weights_array.data = AI_PTR(g_network_weights_map[0] + 55504);
    conv2d_42_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 55504);
    
    conv2d_42_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_bias_array.data = AI_PTR(g_network_weights_map[0] + 60112);
    conv2d_42_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 60112);
    
    conv2d_43_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_weights_array.data = AI_PTR(g_network_weights_map[0] + 60240);
    conv2d_43_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 60240);
    
    conv2d_43_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_bias_array.data = AI_PTR(g_network_weights_map[0] + 66384);
    conv2d_43_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 66384);
    
    conv2d_44_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_weights_array.data = AI_PTR(g_network_weights_map[0] + 67152);
    conv2d_44_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 67152);
    
    conv2d_44_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_bias_array.data = AI_PTR(g_network_weights_map[0] + 68880);
    conv2d_44_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 68880);
    
    conv2d_45_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_weights_array.data = AI_PTR(g_network_weights_map[0] + 69648);
    conv2d_45_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 69648);
    
    conv2d_45_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_bias_array.data = AI_PTR(g_network_weights_map[0] + 75792);
    conv2d_45_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 75792);
    
    conv2d_47_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_weights_array.data = AI_PTR(g_network_weights_map[0] + 75920);
    conv2d_47_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 75920);
    
    conv2d_47_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_bias_array.data = AI_PTR(g_network_weights_map[0] + 82064);
    conv2d_47_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 82064);
    
    conv2d_48_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_weights_array.data = AI_PTR(g_network_weights_map[0] + 82832);
    conv2d_48_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 82832);
    
    conv2d_48_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_bias_array.data = AI_PTR(g_network_weights_map[0] + 84560);
    conv2d_48_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 84560);
    
    conv2d_49_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_weights_array.data = AI_PTR(g_network_weights_map[0] + 85328);
    conv2d_49_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 85328);
    
    conv2d_49_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_bias_array.data = AI_PTR(g_network_weights_map[0] + 91472);
    conv2d_49_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 91472);
    
    conv2d_51_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_weights_array.data = AI_PTR(g_network_weights_map[0] + 91600);
    conv2d_51_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 91600);
    
    conv2d_51_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_bias_array.data = AI_PTR(g_network_weights_map[0] + 97744);
    conv2d_51_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 97744);
    
    conv2d_53_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_weights_array.data = AI_PTR(g_network_weights_map[0] + 98512);
    conv2d_53_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 98512);
    
    conv2d_53_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_bias_array.data = AI_PTR(g_network_weights_map[0] + 100240);
    conv2d_53_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 100240);
    
    conv2d_54_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_weights_array.data = AI_PTR(g_network_weights_map[0] + 101008);
    conv2d_54_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 101008);
    
    conv2d_54_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_bias_array.data = AI_PTR(g_network_weights_map[0] + 111760);
    conv2d_54_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 111760);
    
    conv2d_55_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_weights_array.data = AI_PTR(g_network_weights_map[0] + 111984);
    conv2d_55_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 111984);
    
    conv2d_55_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_bias_array.data = AI_PTR(g_network_weights_map[0] + 130800);
    conv2d_55_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 130800);
    
    conv2d_56_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_weights_array.data = AI_PTR(g_network_weights_map[0] + 132144);
    conv2d_56_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 132144);
    
    conv2d_56_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_bias_array.data = AI_PTR(g_network_weights_map[0] + 135168);
    conv2d_56_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 135168);
    
    conv2d_57_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_weights_array.data = AI_PTR(g_network_weights_map[0] + 136512);
    conv2d_57_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 136512);
    
    conv2d_57_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_bias_array.data = AI_PTR(g_network_weights_map[0] + 155328);
    conv2d_57_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 155328);
    
    conv2d_59_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_59_weights_array.data = AI_PTR(g_network_weights_map[0] + 155552);
    conv2d_59_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 155552);
    
    conv2d_59_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_59_bias_array.data = AI_PTR(g_network_weights_map[0] + 174368);
    conv2d_59_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 174368);
    
    conv2d_60_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_weights_array.data = AI_PTR(g_network_weights_map[0] + 175712);
    conv2d_60_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 175712);
    
    conv2d_60_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_bias_array.data = AI_PTR(g_network_weights_map[0] + 178736);
    conv2d_60_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 178736);
    
    conv2d_61_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_weights_array.data = AI_PTR(g_network_weights_map[0] + 180080);
    conv2d_61_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 180080);
    
    conv2d_61_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_bias_array.data = AI_PTR(g_network_weights_map[0] + 198896);
    conv2d_61_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 198896);
    
    conv2d_63_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_63_weights_array.data = AI_PTR(g_network_weights_map[0] + 199120);
    conv2d_63_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 199120);
    
    conv2d_63_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_63_bias_array.data = AI_PTR(g_network_weights_map[0] + 217936);
    conv2d_63_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 217936);
    
    conv2d_64_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_weights_array.data = AI_PTR(g_network_weights_map[0] + 219280);
    conv2d_64_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 219280);
    
    conv2d_64_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_bias_array.data = AI_PTR(g_network_weights_map[0] + 222304);
    conv2d_64_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 222304);
    
    conv2d_65_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_weights_array.data = AI_PTR(g_network_weights_map[0] + 223648);
    conv2d_65_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 223648);
    
    conv2d_65_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_bias_array.data = AI_PTR(g_network_weights_map[0] + 261280);
    conv2d_65_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 261280);
    
    conv2d_66_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_weights_array.data = AI_PTR(g_network_weights_map[0] + 261728);
    conv2d_66_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 261728);
    
    conv2d_66_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_bias_array.data = AI_PTR(g_network_weights_map[0] + 405088);
    conv2d_66_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 405088);
    
    gemm_68_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_68_weights_array.data = AI_PTR(g_network_weights_map[0] + 410208);
    gemm_68_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 410208);
    
    gemm_68_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_68_bias_array.data = AI_PTR(g_network_weights_map[0] + 420448);
    gemm_68_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 420448);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 19103760,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 19103760,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_data_params_get(&params) != true) {
        err = ai_network_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_init(*network, &params) != true) {
        err = ai_network_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

