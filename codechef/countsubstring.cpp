#include<iostream>
#include<cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);	
		char str[n];
		scanf("%s",str);
		long long count=0;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='1')
				count++;
		}
		count=(count)*(count+1)/2;
		printf("%lld\n",count);
	}
	return 0;
}
