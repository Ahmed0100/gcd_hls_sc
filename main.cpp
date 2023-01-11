#include <systemc.h>

#include "gcd.h"
#include "gcd_tb.h"

int sc_main(int argc, char **argv)
{
	sc_clock clk("clk",10,SC_NS);
	sc_signal<bool> reset;
	sc_signal<bool> valid;

	sc_signal<sc_uint<8> > a;
	sc_signal<sc_uint<8> > b;
	sc_signal<bool> ready;
	sc_signal<sc_uint<8> > gcd_out;

	gcd gcd_inst("gcd_inst");
	gcd_tb gcd_tb_inst("gcd_tb_inst");

	gcd_inst.clk(clk);
	gcd_inst.reset(reset);
	gcd_inst.valid(valid);
	gcd_inst.ready(ready);
	gcd_inst.a(a);
	gcd_inst.b(b);
	gcd_inst.gcd_out(gcd_out);

	gcd_tb_inst.clk(clk);
	gcd_tb_inst.reset(reset);
	gcd_tb_inst.valid(valid);
	gcd_tb_inst.ready(ready);
	gcd_tb_inst.a(a);
	gcd_tb_inst.b(b);
	gcd_tb_inst.gcd_out(gcd_out);

	sc_start();
	return 0;
}