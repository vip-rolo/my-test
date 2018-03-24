#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[100][100],maxn=0,b[10000][3],n,m;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
void bfs(int x,int y)
{
	int v=1,t=0,w=1;
	a[x][y]=0;
	b[1][1]=x;b[1][2]=y;
	while(t<w)
	{
	    t++;
		for(int i=1;i<=4;i++)
	    {
	    	int ddx=x+dx[i],ddy=y+dy[i];
		    if((ddx>=1)&&(ddx<=n)&&(ddy>=1)&&(ddy<=m)&&(a[ddx][ddy]==1))
		    { 
		        a[ddx][ddy]=0;w++;
		        b[w][1]=ddx;b[w][2]=ddy;
		    }
	    }
	}
	maxn=max(maxn,w);
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int i,j;
	scanf("%d%d\n",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(a[i][j]==1)bfs(i,j);
	}
	printf("%d",maxn);
	return 0;
}
