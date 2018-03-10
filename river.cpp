#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
int a[100000];
using namespace std;
int main()
{
    freopen("river.in","r",stdin);
	freopen("river.out","w",stdout);
	int n,m,v,i,x=0;
	cin>>v>>m>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	a[n+1]=a[n];
	while(x!=n+1)
	{
		if(a[x+1]<=a[x+2])x+=2;
		else x+=1;
		v=v-m+a[x];
		if(v<0){cout<<"NO";return 0;}
	}
	cout<<v-a[n];
    return 0;
}
