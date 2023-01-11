#ifndef GCD_H
#define GCD_H

#include <systemc.h>
const uint N = 8;

SC_MODULE(gcd)
{
	sc_in<bool> clk;
	sc_in<bool> reset;
	sc_in<bool> valid;
	sc_in<sc_uint<N> > a;
	sc_in<sc_uint<N> > b;

	sc_out<bool> ready;
	sc_out<sc_uint<N> > gcd_out;
	//variables
	sc_uint<N> x,y;
	sc_uint<N> gcd_tmp;
	bool ready_tmp;
	//
	void gcd_main();
	SC_CTOR(gcd)
	{
		SC_CTHREAD(gcd_main, clk.pos());
		reset_signal_is(reset,true);
		x=0;
		y=0;
		gcd_tmp=0;
		ready_tmp = 0;
	};
};
#endif