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
	ios::sync_with_stdio(0);
	cin>>a>>b>>c>>d;
	for(double i=-100;i<=100;i+=0.01)
	{
		if(fabs(f(i))<=0.00001)printf("%0.2f ",i);
	}
	return 0;
}
