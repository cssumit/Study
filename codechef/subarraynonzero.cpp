#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	long long a[n];
	long long max=0;
	long long cur=0;
	for(long long i=0;i<n;i++)	
	{
		scanf("%lld",&a[i]);
	}
	for(long long i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			if(max<cur)
			{
				max=cur;
			}
			cur=0;
		}
		else
			cur++;
	}
	if(max<cur)
	{
		max=cur;
	}
	printf("%lld\n",max);
}
