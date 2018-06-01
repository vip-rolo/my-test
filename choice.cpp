#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int x[2001],l,r;
int choice(int v)
{
	if(x[l+1]>x[r-1]){v+=x[r];r--;}
	else if(x[l+1]<x[r-1]){v+=x[l];l++;}
	else
	{
		if(x[l]>x[r]){v+=x[l];l++;}
		else{v+=x[r];r--;}
	}
	return v;
}
int main()
{
	int n,i,j,a=0,b=0;
	freopen("choice.in","r",stdin);
	freopen("choice.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=2*n;i++)cin>>x[i];
	l=1;r=2*n;
	while(l<=r)
	{
		for(i=1;i<=2;i++)
		{
			if(i==1)a=choice(a);
			else b=choice(b);
		}
		//cout<<a<<' '<<b<<endl;
	}
	if(a>b)cout<<"YES";
	else cout<<"NO";
	return 0;
}
