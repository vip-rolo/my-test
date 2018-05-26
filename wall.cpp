#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int h,f,a[10001][2],l[100][3];
double x_y(int x1,int y1,int x2,int y2)
{
	return sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
int bfs(int x,int y)
{
	int h=0,t=2;
	l[1][2]=1;
	while(h!=t)
	{
		if(h==100)h=1;else h++;
		for(int i=1;i<=f;i++)
		if((a[i][1]>l[h][1])&&(x_y(a[i][0],a[i][1],l[h][0],l[h][1])<1000))
		{
			if(t==100)t=1;else t++;
			l[t][0]=a[i][0];l[t][1]=a[i][1];l[t][2]=l[h][2]+1;
			if(l[t][1]+1000>=h)return l[t][2];
		}
	}
}
int main()
{
	freopen("wall.in","r",stdin);
	freopen("wall.out","w",stdout);
	ios::sync_with_stdio(1);
	int i,j;
	cin>>h>>f;
	for(i=1;i<=f;i++)cin>>a[i][0]>>a[i][1];	
	for(int i=1;i<=f;i++)
	{
		if(a[i][1]<=1000&&a[i][1]>=l[1][1])
		l[1][0]=a[i][0];l[1][1]=a[i][1];
	}
	cout<<bfs(l[1][0],l[1][1]);
	return 0;
}
