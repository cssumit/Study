#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long  a[1000]={0};
unsigned long long fib(unsigned long long n)
{
	if(a[n-1])
	{
		return a[n-1];
	}
	else
	{
		if(n==1)
		{
			a[n-1]=1;
			return a[n-1];
		}
		else if(n==2)
		{
			a[n-1]=2;
			return a[n-1];
		}
		else
		{
			a[n-1]=fib(n-1)+fib(n-2);
			return a[n-1];
		}
	}
}
int main()
{
	unsigned long long n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}
		
