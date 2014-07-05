#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	unsigned long long  n;
	scanf("%llu",&n);
	unsigned long long  fib[n];
	fib[0]=1;
	fib[1]=2;
	for(int i=2;i<n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	printf("%llu\n",fib[n-1]);
	return 0;
}
