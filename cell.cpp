#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[101][101],n,m,l[10000][2];
int dx[5]={0,0,-1,0,1};
int dy[5]={0,-1,0,1,0};
void bfs(int x,int y)
{
	int h=0,t=2;l[1][0]=x;l[1][1]=y;
	while(h!=t)
	{
		h++;
		a[l[h][0]][l[h][1]]=0;
		for(int i=1;i<=4;i++)
		{
			int ddx=l[h][0]+dx[i],ddy=l[h][1]+dy[i];
			if(a[ddx][ddy]!=0)
			{
				l[t][0]=ddx;l[t][1]=ddy;
				t++;
			}
		}
	}
}
int main()
{
	freopen("cell.in","r",stdin);
	freopen("cell.out","w",stdout);
	int i,j,ans=0;char x;
	ios::sync_with_stdio(1);
	cin>>m>>n;
	for(i=1;i<=m;i++)for(j=1;j<=n;j++)
	{
		cin>>x;
		if(x=='0')a[i][j]=0;
		else a[i][j]=1;
	}
	for(i=1;i<=m;i++)for(j=1;j<=n;j++)
	{
		if(a[i][j]!=0)
		{
			ans++;
			bfs(i,j);
		}
	}
	cout<<ans;
	return 0;
}
