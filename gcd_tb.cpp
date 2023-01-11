#include "gcd_tb.h"

void gcd_tb::gcd_tb_main()
{
	cout<< "@" << sc_time_stamp() << "creating vcd file "<< endl;
	sc_trace_file* trace_file = sc_create_vcd_trace_file("vcd_gcd");
	sc_trace(trace_file,clk,"clk");
	sc_trace(trace_file,reset,"reset");
	sc_trace(trace_file,valid,"valid");
	sc_trace(trace_file,ready,"ready");
	sc_trace(trace_file,a,"a");
	sc_trace(trace_file,b,"b");
	sc_trace(trace_file,gcd_out,"gcd_out");

	cout<<"@"<<sc_time_stamp <<" wait for 5 clk cycles"<<endl;
	wait(5);
	cout<<"@"<<sc_time_stamp <<" set the reset signal to 1"<<endl;
	reset.write(1);
	wait(5);
	cout<<"@"<<sc_time_stamp <<" set the reset signal to 0, input a 35 and input b 30"<<endl;

	reset.write(0);
	a.write(35);
	b.write(30);
	wait(1);
	cout<<"@"<<sc_time_stamp <<" set the valid signal to 1."<<endl;
	valid.write(1);
	wait(1);
	cout<<"@"<<sc_time_stamp <<" set the valid signal to 0."<<endl;
	valid.write(0);
	wait(1);
	cout<<"@"<<sc_time_stamp <<" wait for a few clk cycles yo see results."<<endl;
	while(ready.read()!=1)
	{
	    cout << "@" << sc_time_stamp() << " Ready not set. Wait for 1 clock cycle" << endl;
		wait(1);
	}
	cout<<"@"<<sc_time_stamp <<" ready signal is set. gcd is "<<gcd_out<<endl;
	wait(5);

	cout<<"@"<<sc_time_stamp <<" input a 50 and input b 70"<<endl;
	a.write(50);
	b.write(70);
	wait(1);
	cout<<"@"<<sc_time_stamp <<" set the valid signal to 1."<<endl;
	valid.write(1);
	wait(1);
	cout<<"@"<<sc_time_stamp <<" set the valid signal to 0."<<endl;
	valid.write(0);
	wait(1);
	cout<<"@"<<sc_time_stamp <<" wait for a few clk cycles yo see results."<<endl;
	while(ready.read()!=1)
	{
 	   cout << "@" << sc_time_stamp() << " ready not set. wait for 1 clock cycle" << endl;
		wait(1);
	}
	cout<<"@"<<sc_time_stamp <<" ready signal is set. gcd is "<<gcd_out<<endl;
	wait(5);

	sc_stop();
}