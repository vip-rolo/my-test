#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[1000000],n,m;
int check(int x)
{
	int i,ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]/x;
		if(ans>=m)return ans;
	}
	return ans;
}
int main()
{
	freopen("wood.in","r",stdin);
	freopen("wood.out","w",stdout);
	ios::sync_with_stdio(false);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	int l=0,r=2000000000,mid;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(check(mid)>=m)l=mid;
		else r=mid;
	}
	if(check(r)>m)cout<<r;
	else cout<<l;
	return 0;
}
