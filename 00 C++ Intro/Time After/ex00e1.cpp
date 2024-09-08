#include<stdio.h>
int h,m,x;
int main()
{
	// Input initial time (h,m) and time added (x)
	scanf("%d %d %d",&h,&m,&x);
	// Add the min by x
	m += x;
	/* Output
	Minute is m mod 60 because minutes can't exceed 60
	Hours is (h + m/60) mod 24 because m/60 is the amount and hours added and hour can't exceed 24
	*/
	printf("%02d %02d",(h+(m/60))%24 ,m%60);
	return 0;
}