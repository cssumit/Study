#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long fib(unsigned long long n)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else 
		return fib(n-1)+fib(n-2);
}
int main()
{
	unsigned long long n;
	scanf("%llu",&n);
	printf("%llu\n",fib(n));
	return 0;
}

