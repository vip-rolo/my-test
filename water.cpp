#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,l[10000][2];
char a[100][100];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int c[1000][1000];
void bfs(int x,int y)
{
	int h=0,t=1;l[1][0]=x;l[1][1]=y;
	while(h!=t)
	{
		if(h==10000)h=1;else h++;
		for(int i=0;i<4;i++)
		{
			int ddx=dx[i]+l[h][0],ddy=dy[i]+l[h][1];
			if(ddx<=n&&ddy<=m&&ddx>0&&ddy>0&&a[ddx][ddy]>=a[l[h][0]][l[h][1]]&&c[ddx][ddy]!=1&&(ddx!=x||ddy!=y))
			{
				if(t==10000)t=1;else t++;
				l[t][0]=ddx;l[t][1]=ddy;
				c[l[t][0]][l[t][1]]=1;
			}
		}
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)cout<<a[i][j];
			cout<<endl;
		}
		cout<<endl;
		*/
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(1);
	int i,j;
	cin>>k;
	for(int _i=1;_i<=k;_i++)
	{
		cin>>n>>m;ans=0;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
		for(char _j='a';_j<='z';_j++)
		{
			for(i=1;i<=n;i++)for(j=1;j<=m;j++)
			{
				if(a[i][j]==_j&&c[i][j]!=1)
				{
					bfs(i,j);
				}
			}
		}
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)
		if(c[i][j]!=1)ans++;
		cout<<ans<<endl;
		memset(c,0,sizeof(c));
	}
	return 0;
}
