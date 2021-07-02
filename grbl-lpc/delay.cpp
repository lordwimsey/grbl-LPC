// Copyright 2017 Todd Fleming
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include "delay.h"

void delay_init()
{
    LPC_TIM3->CTCR = 0;   // Count Control (0=TimerMode, 1-3=EdgeCounterMode)
    LPC_TIM3->PR = 0;     // no Prescale (TC increments ever PR+1 clocks)
    LPC_TIM3->MCR = 0;    // no Match Control actions
    LPC_TIM3->CCR = 0;    // no Capture Control actions
    LPC_TIM3->EMR = 0;    // no External Match (controls external match pins)
    LPC_TIM3->TCR = 0b10; // reset Timer Control (0b10=Reset, 0b01=Enable)
    LPC_TIM3->TCR = 0b01; // enable Timer Control (0b10=Reset, 0b01=Enable)
}
