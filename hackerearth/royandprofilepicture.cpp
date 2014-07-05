#include<iostream>
#include<cstdio>
int main()
{
	int l;
	scanf("%d",&l);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int w,h;
		scanf("%d%d",&w,&h);
		if(w<l||h<l)
			printf("UPLOAD ANOTHER\n");
		else
		{
			if(w==h)
				printf("ACCEPTED\n");
			else
				printf("CROP IT\n");
		}
	}
	return 0;
}
