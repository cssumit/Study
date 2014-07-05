#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[1024];
		scanf("%s",str);
		int k=0;
		for(int i=0;str[i]!='\0';i++)
		{
			int r=(int)str[i]-97;
			if(r>=k)
				k=r-k;
			else 
				k=(26+r)-k;
			if(k>13)
				k=-(26-k);
			printf("%d ",k);
			k=r;
		}
		printf("\n");
	}
	return 0;
}
