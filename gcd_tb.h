#ifndef GCD_TB_H
#define GCD_TB_H

#include <systemc.h>

SC_MODULE(gcd_tb)
{
	sc_in<bool> clk;
	sc_in<bool> ready;
	sc_in<sc_uint<8> > gcd_out;

	sc_out<bool> reset;
	sc_out<bool> valid;
	sc_out<sc_uint<8> > a;
	sc_out<sc_uint<8> > b;

	SC_CTOR(gcd_tb)
	{
		SC_CTHREAD(gcd_tb_main,clk.pos());
	}

	void gcd_tb_main();
};
#endif