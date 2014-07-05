#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long x,y;
	long long ans;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		if(x<0)
			x=-x;
		if(y<0)
			y=-y;
		
		if((x+y)%2==0)
		{
			ans=(x>y)?(2*x):(2*y);
		}
		else
		{
			if(x>y)
			{
				ans=2*x+1;
			}
			else
			{
				ans=2*y-1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
