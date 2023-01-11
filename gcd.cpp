#include "gcd.h"
void gcd::gcd_main()
{
	gcd_tmp=0;
	ready_tmp=0;
	x=0;
	y=0;
	wait();
	while(true)
	{
		if(valid.read() == 1)
		{
			x= a.read();
			y= b.read();
		}
		else
		{
			if(x>y)
				x= x-y;
			else if(y>x)
				y=y-x;
			else
			{
				ready_tmp = (x==0)? 0 : 1;
				gcd_tmp = (x==0)? gcd_tmp : x;
				x=0;
				y=0;
			}
		}
		gcd_out.write(gcd_tmp);
		ready.write(ready_tmp);
		wait();
	}

}