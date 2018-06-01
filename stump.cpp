#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[500000],b[500000];
void fi(int x)
{
	if((b[x-1]==0)&&(a[x]>a[x-1])){b[x-1]=2;fi(x-1);}
	if((b[x+1]==0)&&(a[x]>a[x+1])){b[x+1]=2;fi(x+1);}
}
int main()
{
	freopen("stump.in","r",stdin);
	freopen("stump.out","w",stdout);
	int n,i,maxn=0,ans=0;bool v;
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)maxn=a[i];
	}
	for(i=maxn;i>=1;i--)
	{
		if(v)break;
		v=true;
		int j=0;
		while(j<=n)
		{
			while((a[j]!=i)&&(j<=n))j++;
			b[j]=1;
			fi(j);
			j++;
			for(int k=1;k<=n;k++)if(b[k]==0)v=false;		
		}
	}
	for(i=1;i<=n;i++)if(b[i]==1)cout<<i<<' ';
	return 0;
}
