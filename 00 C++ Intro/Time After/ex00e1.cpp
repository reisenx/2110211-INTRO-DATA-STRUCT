#include<stdio.h>
int h,m,x;
int main()
{
	scanf("%d %d %d",&h,&m,&x);
	m += x;
	printf("%02d %02d",(h+(m/60))%24 ,m%60);
}