#include<cstdio>
#include<cstdlib>
int main()
{
	int* a=(int*)malloc(sizeof(int)*3600000001);
	printf("%d",a[3600000000]);
	return 0;
}
