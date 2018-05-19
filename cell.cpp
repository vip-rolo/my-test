#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,m,k=0,dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};
bool xb[101][101];
void bfs(int x,int y)
{
	k++;
	int h=-1,t=1;
	int dl[10000][3];
	dl[0][1]=x;
	dl[0][2]=y;
	while (h<t)
	{	
		h++;
		for (int i=1;i<=4;i++)
		{
			int ddx=dl[h][1]+dx[i],ddy=dl[h][2]+dy[i];
			if (ddx>=1&&ddx<=n&&ddy>=1&&ddy<=m&&xb[ddx][ddy]==1)
			{
				dl[t][1]=ddx;
				dl[t][2]=ddy;
				xb[ddx][ddy]=0;
				t++;
			}
		}
	}
}
int main()
{
	freopen("cell.in","r",stdin);
	freopen("cell.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	char g;
	for (int i=1;i<=n;i++)for (int j=1;j<=m;j++)
	{
		cin>>g;
		if (g=='0') xb[i][j]=0;
		else xb[i][j]=1;
	}
	for (int i=1;i<=n;i++)for (int j=1;j<=m;j++)
	{
		if (xb[i][j]==1)
		{
			bfs(i,j);
		}
	}
	cout<<k;
	return 0;
}
