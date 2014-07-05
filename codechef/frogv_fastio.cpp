#include<algorithm>
#include<cstdio>
using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function 
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
int Bin_search(int arr[],int num,int lim)
{
    int beg=0,mid,end=lim;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(arr[mid]==num)
        {
            break;
        }
        else if(arr[mid]>num)
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    return mid;
}
int main()
{
    int N,K,P;
    int coord[100001],temp[100001];
    inp(N);
    inp(K);
    inp(P);
    //scanf("%d%d%d",&N,&K,&P);
    for( int i = 0 ; i < N ; i++)
    {
        inp(coord[i]);
//        scanf("%d",&coord[i]);
        temp[i]=coord[i];
    }
    sort(temp,temp+N);
    int A,B,var,start,end;
    bool flag; 
    int what[100001];
    what[0]=0;
    for(int i=1;i<N;i++)
    {
	if((temp[i]-temp[i-1])<=K)
	{
		what[i]=what[i-1]+1;
	}
	else
	{
		what[i]=what[i-1];
	}
   }
	
    while(P--)
    {
        
        flag=true;
        inp(A);
        inp(B);
        //scanf("%d%d",&A,&B);
        if(B<A)
        {
            var=A;
            A=B;
            B=var;
        }
        A--;
        B--;
        
        start=Bin_search(temp,coord[A],N-1);
        end=Bin_search(temp,coord[B],N-1);
        
        if(abs(start-end)==abs(what[start]-what[end]))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
    }
    return 0;
}
