# include <cstring>
# include <iostream>
#include<cstdio>
using namespace std;

int n,vis[400000],cnt[10],queue[400000],sum;
char c[20],s[20];

int id(char i)
{
    switch(i)
    {
	case 'A':    return 0;
	case 'T':    return 1;
	case 'C':    return 2;
	case 'G':    return 3;
    }
}

int exchange(int a[])
{
    int sum=0,mul=1;
    for(int i=n-1;i>=0;i--)
    {
        sum+=a[i]*mul;
        mul*=4;
    }
    return sum;
}

void decode(int re,int a[])
{
    for(int i = n-1;i>=0;i--)
    {
        a[i] = re % 4;
        re/=4;
    }
}

int hash (int a[])
{
    int t=sum,rank=0;
    int c[10];
    memcpy(c,cnt,sizeof(c));     //复制字母出现的次数;
    for(int i=0;i<n;i++)         //从第一个字母开始,开始那字典序排在它之前的字符串有哪些;
    {
        for(int j=0;j<a[i];j++)
            if(c[j])    rank += t*c[j]/(n-i);     //这里是用的是全排列的方法计算的，可以展开看看，便于理解;
			
	t = t*c[a[i]]/(n-i);
	--c[a[i]];
    }
    return rank;
}

int main()
{
    freopen("order.in","r",stdin);
	freopen("order.out","w",stdout);
    while(cin>>n&&n)
    {
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        int current[20],target[20],i,j;
        sum=1;
        scanf("%s%s",c,s);
        for(i=0;i<n;i++)
        {
            current[i]=id(c[i]);      //将字母转换为数字；
            target[i]=id(s[i]);
            sum*=i+1;                //计算当前N个无重复的字母的全排列;
            cnt[current[i]]++;       //统计每个字母出现的次数;
        } 
        int currentcode=exchange(current),targetcode=exchange(target);    //将数字转行为十进制;
		
        for(i=0;i<4;i++)     //计算给出的字符串的全排列（去重之后）
            for(j=1;j<=cnt[i];j++)
                sum/=j;
			
	if(currentcode==targetcode)   { printf("0\n"); continue; }
			
	int tail=0,head=0,step=1,ans=-1;
			
			queue[tail++] = currentcode;
			vis[hash(current)] = 1;
			
			for(;head < tail && ans==-1;step++)    //开始广搜;
			{
				int size =tail - head;
				for(; size ;head++,size--)    //从每一层开始;
				{
					for(i=0;i<2;i++)
					{
						decode(queue[head],current);     //将十进制数转换为四进制的；
						//进行两种交换;
						if(i==0)    swap(current[0],current[1]);
						else
						{
							j=current[0];
							for(int k=1;k<n;k++)
								current[k-1]=current[k];
							current[n-1]=j;
						}
						
						j=hash(current);    //求出当前则种状态的hash值;
						
						if(!vis[j])
						{
							vis[j]=1;
							currentcode=exchange(current);
							if(currentcode==targetcode)
							{
								ans=step;
								break;
							}
							queue[tail++]=currentcode;
						}
					}
				}
			}
			printf("%d\n",ans);
    }
    getchar();
    return 0;
}

