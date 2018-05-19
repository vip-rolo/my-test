#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[1000],l[1000][2],x,y,n,b[1000];
int bfs(int x)
{
	b[x]=0;
	if(x==y)return 0;
	if(a[x]==0)return -1;
	int h=0,t=2,v=0;l[1][0]=x;
	while(h!=t)
	{
		if(h==1000)h=1;
		else h++;
		for(int i=-1;i<=1;i++)
		{
			if(i==0)continue;
			if(a[l[h][0]]*i+l[h][0]<=n&&a[l[h][0]]*i+l[h][0]>0&&b[a[l[h][0]]*i+l[h][0]]!=0)
			{
				l[t][0]=a[l[h][0]]*i+l[h][0];l[t][1]=l[h][1]+1;
				b[l[t][0]]=0;
				if(l[t][0]==y)return l[t][1];
				if(t==1000)t=1;
				else t++;
			}
		}
	}
	return -1;
}
int main()
{ 
	freopen("lift.in","r",stdin);
	freopen("lift.out","w",stdout);
	int i;
	ios::sync_with_stdio(0);
	cin>>n>>x>>y;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];if(a[i]!=0)b[i]=1;
		else b[i]=0;
	} 
	cout<<bfs(x);
	return 0;
}
