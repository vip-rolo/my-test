#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],n,m,l[1000][3];
int dx[5]={0,0,-1,0,1};
int dy[5]={0,-1,0,1,0};
int bfs(int x,int y,int v)
{
	int h=0,t=2;l[1][0]=x;l[1][1]=y;l[1][2]=v;
	while(h!=t)
	{
		if(h==1000)h=1;else h++;
		v++;
		for(int i=1;i<=4;i++)
		{
			int ddx=l[h][0]+dx[i],ddy=l[h][1]+dy[i];
			if(a[ddx][ddy]!=1)
			{
				l[t][0]=ddx;l[t][1]=ddy;l[t][2]=l[h][2]+1;
				if((l[t][0]==m&&l[t][1]==n))return l[t][2];
				a[l[t][0]][l[t][1]]=1;	
				if(t==1000)t=1;else t++;
			}
		}
	}
}
int main()
{
	freopen("mud.in","r",stdin);
	freopen("mud.out","w",stdout);
	int i,j,s,x_,y_;
	ios::sync_with_stdio(0);
	cin>>m>>n>>s;
	m+=500,n+=500;
	for(i=1;i<=s;i++)
	{
		cin>>x_>>y_;
		x_+=500;y_+=500;
		a[x_][y_]=1;
	}
	cout<<bfs(500,500,0);
	return 0;
}
