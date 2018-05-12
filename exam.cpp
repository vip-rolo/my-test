#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000];
int main()
{
	freopen("exam.in","r",stdin);
	freopen("exam.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,i,j,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i-j+a[j]>20000)break;
			if(a[i]>i-j+a[j])
			{
				ans++;ans%=12345;
			}
		}
	}
	cout<<ans;
	return 0;
}
