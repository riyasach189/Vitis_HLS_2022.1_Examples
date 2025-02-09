/*
 * Copyright 2021 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define __gmp_const const
#include "ap_axi_sdata.h"
#include "hls_stream.h"
#include <stdio.h>
#include "example.h"

// void example(hls::stream< ap_axis<32,2,5,6> > &A,
//	     hls::stream< ap_axis<32,2,5,6> > &B)

// void example(hls::stream< ap_axis<32,0,0,0> > &A,
//	     hls::stream< ap_axis<32,0,0,0> > &B)

void example(hls::stream<outSdCh> &A, hls::stream<outSdCh> &B)
{
#pragma HLS INTERFACE mode = s_axilite port = return
#pragma HLS INTERFACE axis port = A
#pragma HLS INTERFACE axis port = B

    outSdCh tmp;

    while (1)
    {
        A.read(tmp);
        tmp.data = tmp.data + 0.5;

        B.write(tmp);
        if (tmp.last)
        {
            break;
        }
    }
}
