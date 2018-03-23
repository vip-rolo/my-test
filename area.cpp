#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[10000][10000][3],maxn=0,b[10000][3],n,m;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
void bfs(int x,int y)
{
	int v=1,t=1,w=2;
	a[x][y][2]=0;
	b[t][1]=x;b[t][2]=y;
	while(t!=w)
	{
		for(int i=1;i<=4;i++)
	    {
		    if((x+dx[i]>0)&&(x+dx[i]<=n)&&(y+dy[i]>0)&&(y+dy[i]<=m)&&(a[x+dx[i]][y+dy[i]][1]==1)&&(a[x+dx[i]][y+dy[i]][2]==0))
		    {
		    	v++;
		        a[x+dx[i]][y+dy[i]][2]=1;w++;
		        b[w][1]=x+dx[i];b[w][2]=y+dy[i];
		    }
	    }
	    t++;
	}
	for(int i=1;i<=v;i++)
	{
	    a[b[i][1]][b[i][2]][2]=0;
	    b[i][2]=b[i][1]=0;
	}
	if(v>maxn)maxn=v;
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int i,j;
	scanf("%d%d\n",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)scanf("%d",&a[i][j][1]);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(a[i][j][1]==1&&a[i][j][2]==0)bfs(i,j);
	}
	printf("%d",maxn);
	return 0;
}
