############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
set_directive_interface -mode s_axilite "TNN"
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" batch
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" labels
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" seq_out
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" nheads_out
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" nlayers_out
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" embed_out
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" hidden_out
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" outdim_out
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" tile
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" over
set_directive_interface -mode m_axi -bundle ins -depth 49152 "TNN" inStream
set_directive_interface -mode m_axi -bundle outs -depth 49152 "TNN" out_stream
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" tile_score1
set_directive_interface -mode s_axilite -bundle bus_bundle "TNN" tile_score2
set_directive_array_partition -type complete -dim 1 "TNN" bq1
set_directive_array_partition -type complete -dim 1 "TNN" bk1
set_directive_array_partition -type complete -dim 1 "TNN" bv1
set_directive_array_partition -type complete -dim 1 "TNN" bq2
set_directive_array_partition -type complete -dim 1 "TNN" bk2
set_directive_array_partition -type complete -dim 1 "TNN" bv2
set_directive_array_partition -type complete -dim 1 "TNN" bq3
set_directive_array_partition -type complete -dim 1 "TNN" bk3
set_directive_array_partition -type complete -dim 1 "TNN" bv3
set_directive_array_partition -type complete -dim 1 "TNN" bq4
set_directive_array_partition -type complete -dim 1 "TNN" bk4
set_directive_array_partition -type complete -dim 1 "TNN" bv4
set_directive_array_partition -type complete -dim 1 "TNN" bff_1
set_directive_array_partition -type complete -dim 1 "TNN" bff_2
set_directive_array_partition -type complete -dim 1 "TNN" bff_3
set_directive_pipeline -off "TNN/weightClass1"
set_directive_pipeline "TNN/weightClass2"
set_directive_pipeline "TNN/bias_pool"
set_directive_pipeline "TNN/bias_class"
set_directive_pipeline "TNN/readInputs"
set_directive_inline -off "TNN/layers"
set_directive_pipeline -off "TNN/inputs1_1"
set_directive_pipeline "TNN/inputs2_1"
set_directive_pipeline -off "TNN/Tiles"
set_directive_pipeline -off "TNN/concat1"
set_directive_pipeline "TNN/concat2"
set_directive_pipeline -off "TNN/tile1"
set_directive_pipeline -off "TNN/tile2"
set_directive_pipeline -off "TNN/tile3"
set_directive_pipeline -off "TNN/tile4"
set_directive_pipeline -off "TNN/reset1"
set_directive_pipeline "TNN/reset2"
set_directive_pipeline -off "TNN/tile5"
set_directive_pipeline -off "TNN/tile6"
set_directive_pipeline -off "TNN/inputs2_out"
set_directive_pipeline "TNN/inputs2_in"
set_directive_pipeline -off "TNN/inputs3_out"
set_directive_pipeline "TNN/inputs3_in"
set_directive_pipeline -off "TNN/tile7"
set_directive_pipeline -off "TNN/tile8"
set_directive_pipeline -off "TNN/finalLoop1"
set_directive_pipeline "TNN/finalLoop2"
set_directive_pipeline "TNN/biasQ1"
set_directive_pipeline "TNN/biasK1"
set_directive_pipeline "TNN/biasV1"
set_directive_pipeline "TNN/weightQ1"
set_directive_pipeline "TNN/weightK1"
set_directive_pipeline "TNN/weightV1"
set_directive_inline -off "relu"
set_directive_inline -off "gelu"
set_directive_inline -off "addNorm1"
set_directive_pipeline -off "addNorm1/add_norm_seq1"
set_directive_pipeline "addNorm1/add_norm_embed1"
set_directive_inline -off "addNorm2"
set_directive_pipeline -off "addNorm2/add_norm_seq2"
set_directive_pipeline "addNorm2/add_norm_embed2"
set_directive_inline -off "sig"
set_directive_inline -off "tan"
set_directive_inline -off "biasAdd"
set_directive_inline -off "biasAdd2"
set_directive_inline -off "biasAdd3"
set_directive_inline -off "biasAdd4"
set_directive_pipeline -off "biasAdd/bias_loop1"
set_directive_pipeline -off "biasAdd2/bias_loop3"
set_directive_pipeline "biasAdd/bias_loop2"
set_directive_pipeline "biasAdd2/bias_loop4"
set_directive_pipeline -off "biasAdd3/bias_loop5"
set_directive_pipeline "biasAdd3/bias_loop6"
set_directive_pipeline -off "biasAdd4/bias_loop7"
set_directive_pipeline "biasAdd4/bias_loop8"
set_directive_inline -off "feedforward_last"
set_directive_pipeline -off "feedforward_last/seq1"
set_directive_pipeline "feedforward_last/col1"
set_directive_inline -off "feedforward1_1"
set_directive_pipeline -off "feedforward1_1/seq1"
set_directive_pipeline "feedforward1_1/col1"
set_directive_inline -off "feedforward2_1"
set_directive_pipeline -off "feedforward2_1/seq1"
set_directive_pipeline "feedforward2_1/col1"
set_directive_inline -off "feedforward3_1"
set_directive_pipeline -off "feedforward3_1/seq1"
set_directive_pipeline "feedforward3_1/col1"
set_directive_inline -off "layerNorm"
set_directive_pipeline -off "layerNorm/mean_out"
set_directive_pipeline -off "layerNorm/variance_out"
set_directive_pipeline -off "layerNorm/norm_out1"
set_directive_pipeline -off "layerNorm/norm_out2"
set_directive_pipeline "layerNorm/mean_in"
set_directive_pipeline "layerNorm/variance_in"
set_directive_pipeline "layerNorm/norm_in1"
set_directive_pipeline "layerNorm/norm_in2"
set_directive_inline -off "loadBiasAll"
set_directive_pipeline "loadBiasAll/encode_bias_all"
set_directive_inline -off "loadBiasInter"
set_directive_pipeline "loadBiasInter/encode_bias"
set_directive_inline -off "loadBq1"
set_directive_inline -off "loadBq2"
set_directive_inline -off "loadBq3"
set_directive_pipeline "loadBq1/query_bias1"
set_directive_pipeline "loadBq2/query_bias2"
set_directive_pipeline "loadBq3/query_bias3"
set_directive_pipeline "loadBq4/query_bias4"
set_directive_inline -off "loadBq4"
set_directive_inline -off "loadIn"
set_directive_inline -off "loadIn2"
set_directive_inline -off "loadIn3"
set_directive_pipeline "loadIn/inputs2_1"
set_directive_pipeline -off "loadIn/inputs1_1"
set_directive_pipeline -off "loadIn2/inputs1_2"
set_directive_pipeline "loadIn2/inputs2_2"
set_directive_pipeline -off "loadIn3/inputs1_3"
set_directive_pipeline "loadIn3/inputs2_3"
set_directive_inline -off "loadWn"
set_directive_pipeline "loadWn/weight_LN1"
set_directive_inline -off "loadWo1"
set_directive_inline -off "loadWo2"
set_directive_pipeline -off "loadWo1/weightO1"
set_directive_pipeline -off "loadWo2/weightO1"
set_directive_pipeline "loadWo1/weightO2"
set_directive_pipeline "loadWo2/weightO2"
set_directive_inline -off "loadWq1"
set_directive_inline -off "loadWq2"
set_directive_inline -off "loadWq3"
set_directive_inline -off "loadWq4"
set_directive_pipeline -off "loadWq1/weightQ1_1"
set_directive_pipeline -off "loadWq2/weightQ1_2"
set_directive_pipeline -off "loadWq3/weightQ1_3"
set_directive_pipeline "loadWq1/weightQ2_1"
set_directive_pipeline "loadWq2/weightQ2_2"
set_directive_pipeline "loadWq3/weightQ2_3"
set_directive_pipeline "loadWq4/weightQ2_4"
set_directive_pipeline -off "loadWq4/weightQ1_4"
set_directive_inline -off "attention_score"
set_directive_inline -off "attention_score2"
set_directive_inline -off "attention_score3"
set_directive_inline -off "attention_score4"
set_directive_pipeline -off "attention_score/Score"
set_directive_pipeline -off "attention_score2/Score2"
set_directive_pipeline -off "attention_score3/Score3"
set_directive_pipeline -off "attention_score4/Score4"
set_directive_pipeline -off "attention_score4/VS4"
set_directive_pipeline -off "attention_score3/VS3"
set_directive_pipeline "attention_score/col5"
set_directive_pipeline -off "attention_score/VS"
set_directive_pipeline "attention_score/row6"
set_directive_pipeline "attention_score2/col52"
set_directive_pipeline -off "attention_score2/VS2"
set_directive_pipeline "attention_score2/row62"
set_directive_pipeline "attention_score3/col53"
set_directive_pipeline "attention_score3/row63"
set_directive_pipeline "attention_score4/col54"
set_directive_pipeline "attention_score4/row64"
set_directive_inline -off "self_attention1"
set_directive_pipeline -off "self_attention1/QKV1"
set_directive_pipeline "self_attention1/col41"
set_directive_inline -off "self_attention2"
set_directive_pipeline -off "self_attention2/QKV2"
set_directive_pipeline "self_attention2/col42"
set_directive_inline -off "self_attention3"
set_directive_pipeline -off "self_attention3/QKV3"
set_directive_pipeline "self_attention3/col43"
set_directive_inline -off "self_attention4"
set_directive_pipeline -off "self_attention4/QKV4"
set_directive_pipeline "self_attention4/col44"
set_directive_inline -off "softmax"
set_directive_pipeline -off "softmax/loop1"
set_directive_pipeline -off "softmax/loop2"
set_directive_pipeline -off "softmax/loop3"
set_directive_top -name TNN "TNN"
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ1
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ2
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ3
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ4
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK1
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK2
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK3
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK4
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV1
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV2
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV3
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV4
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ1
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK1
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV1
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ2
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK2
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV2
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ3
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK3
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV3
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ4
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK4
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV4
set_directive_interface -mode m_axi -bundle w1 -depth 63719424 "TNN" weight_stream1
set_directive_pipeline "softmax/loop1_2"
set_directive_pipeline "softmax/loop2_1"
set_directive_pipeline "softmax/loop3_1"
set_directive_interface -mode m_axi -bundle b1 -depth 73728 "TNN" bias_stream
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ5
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ6
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ7
set_directive_interface -mode m_axi -bundle wQ -depth 1769472 "TNN" weight_streamQ8
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK5
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK6
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK7
set_directive_interface -mode m_axi -bundle wK -depth 1769472 "TNN" weight_streamK8
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV5
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV6
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV7
set_directive_interface -mode m_axi -bundle wV -depth 1769472 "TNN" weight_streamV8
set_directive_array_partition -type complete -dim 1 "TNN" bq5
set_directive_array_partition -type complete -dim 1 "TNN" bk5
set_directive_array_partition -type complete -dim 1 "TNN" bv5
set_directive_array_partition -type complete -dim 1 "TNN" bq6
set_directive_array_partition -type complete -dim 1 "TNN" bk6
set_directive_array_partition -type complete -dim 1 "TNN" bv6
set_directive_array_partition -type complete -dim 1 "TNN" bq7
set_directive_array_partition -type complete -dim 1 "TNN" bk7
set_directive_array_partition -type complete -dim 1 "TNN" bv7
set_directive_array_partition -type complete -dim 1 "TNN" bq8
set_directive_array_partition -type complete -dim 1 "TNN" bk8
set_directive_array_partition -type complete -dim 1 "TNN" bv8
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ5
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK5
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV5
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ6
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK6
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV6
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ7
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK7
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV7
set_directive_interface -mode m_axi -bundle bQ -depth 2304 "TNN" bias_streamQ8
set_directive_interface -mode m_axi -bundle bK -depth 2304 "TNN" bias_streamK8
set_directive_interface -mode m_axi -bundle bV -depth 2304 "TNN" bias_streamV8
set_directive_inline -off "loadBq5"
set_directive_pipeline "loadBq5/query_bias5"
set_directive_inline -off "loadBq6"
set_directive_pipeline "loadBq6/query_bias6"
set_directive_inline -off "loadBq7"
set_directive_pipeline "loadBq7/query_bias7"
set_directive_inline -off "loadBq8"
set_directive_pipeline "loadBq8/query_bias8"
set_directive_inline -off "self_attention5"
set_directive_pipeline -off "self_attention5/QKV5"
set_directive_pipeline "self_attention5/col45"
set_directive_inline -off "self_attention6"
set_directive_pipeline -off "self_attention6/QKV6"
set_directive_pipeline "self_attention6/col46"
set_directive_inline -off "self_attention7"
set_directive_pipeline -off "self_attention7/QKV7"
set_directive_pipeline "self_attention7/col47"
set_directive_inline -off "self_attention8"
set_directive_pipeline -off "self_attention8/QKV8"
set_directive_pipeline "self_attention8/col48"
set_directive_inline -off "attention_score5"
set_directive_pipeline -off "attention_score5/Score5"
set_directive_pipeline "attention_score5/col55"
set_directive_pipeline -off "attention_score5/VS5"
set_directive_pipeline "attention_score5/row65"
set_directive_inline -off "attention_score6"
set_directive_pipeline -off "attention_score6/Score6"
set_directive_pipeline -off "attention_score6/VS6"
set_directive_pipeline "attention_score6/col56"
set_directive_pipeline "attention_score6/row66"
set_directive_inline -off "attention_score7"
set_directive_pipeline -off "attention_score7/Score7"
set_directive_pipeline -off "attention_score7/VS7"
set_directive_pipeline "attention_score7/col57"
set_directive_pipeline "attention_score7/row67"
set_directive_inline -off "attention_score8"
set_directive_pipeline -off "attention_score8/Score8"
set_directive_pipeline "attention_score8/col58"
set_directive_pipeline -off "attention_score8/VS8"
set_directive_pipeline "attention_score8/row68"
set_directive_pipeline -off "loadWq5/weightQ1_5"
set_directive_inline -off "loadWq5"
set_directive_pipeline "loadWq5/weightQ2_5"
set_directive_inline -off "loadWq6"
set_directive_pipeline -off "loadWq6/weightQ1_6"
set_directive_pipeline "loadWq6/weightQ2_6"
set_directive_inline -off "loadWq7"
set_directive_pipeline -off "loadWq7/weightQ1_7"
set_directive_pipeline "loadWq7/weightQ2_7"
set_directive_inline -off "loadWq8"
set_directive_pipeline -off "loadWq8/weightQ1_8"
set_directive_pipeline "loadWq8/weightQ2_8"
