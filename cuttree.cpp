#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long a[20000000],n,m,l=1,r,mid;
bool check(int x)
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>i)ans+=a[i]-x;
	}
	return ans>=m;
}
int main()
{
	freopen("cuttree.in","r",stdin);
	freopen("cuttree.out","w",stdout);
	long long i,j,k=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){cin>>a[i];if(a[i]>r)r=a[i];}
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(check(r))cout<<r<<endl;
	else cout<<l<<endl;
	return 0;
}
