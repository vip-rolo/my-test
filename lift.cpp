#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[1000],l[1000],x,y,n;
int bfs(int x)
{
	int h=0,t=2,v=0;l[1]=x;
	while(h!=t)
	{
		if(h==1000)h=1;else h++;v++;
		if(l[h]+a[l[h]]<=n)
		{
			l[t]=l[h]+a[l[h]];
			if(t==1000)t=1;else t++;
		}
		if(l[h]-a[l[h]]>=1)
		{
			l[t]=l[h]-a[l[h]];
			if(t==1000)t=1;else t++;
		}
		if(l[t]==y||l[t-1]==y)return v;
	}
}
int main()
{
	freopen("lift.in","r",stdin);
	freopen("lift.out","w",stdout);
	int i;
	ios::sync_with_stdio(1);
	cin>>n>>x>>y;
	for(i=1;i<=n;i++)cin>>a[i];
	cout<<bfs(x);
	return 0;
}
