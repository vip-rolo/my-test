#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double v)
{
	return a*v*v*v+b*v*v+c*v+d;
}
int main()
{
	freopen("equ.in","r",stdin);
	freopen("equ.out","w",stdout);
	double l,r,mid,x,y,z;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	for(int i=1;i<=3;i++)
	{
		l=-100,r=100;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if(f(mid)==0)
			{
				if(i==1){x=mid;break;}
				if(i==2&&mid!=x){y=mid;break;}
				if(i==3&&mid!=x&&mid!=y){z=mid;break;}
			}
			if(f(mid)<0)l=mid;
			else r=mid;
		}
	}
	printf("%0.2f %0.2f %0.2f",x,y,z);
	return 0;
}
