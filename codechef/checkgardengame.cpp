/*
Codechef

Garden Game

All bandits are afraid of Sheriff. Sheriff constantly fights crime, but when bandits lay low, he is getting bored and starts to entertain himself.
This time Sheriff gathered all the bandits in his garden and ordered them to line up. After the whistle all bandits should change the order in which they stand.
Sheriff gave all the bandits numbers from 1 to N. For each place i he determined the unique position j. After whistling the bandit staying on position i should run to the j-th position. Sheriff loved seeing how the bandits move around, and he continued whistling until the evening. He finished the game only when he noticed that the bandits are in the same order in which they were standing originally.
Now the Sheriff asks the question: How many times has he whistled?
 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of bandits. The second line contains N space-separated integers A1, A2, ..., AN denoting that the bandit staying on position i should run to the Ai-th position after the whistle.
 
Output

For each test case, output a single line containing number of times the sheriff had to whistle, print it modulo 10^9 + 7.
 
Constraints

1 ≤ T ≤ 5
1 ≤ N ≤ 100000
All Ai are distinct numbers from 1 to N
 
Example

 

Input:

2
3
1 2 3
5
2 3 1 5 4

Output:

1
6

 
Explanation

 

Example case 2.
the bandits positions are:
0. 1 2 3 4 5
1. 3 1 2 5 4
2. 2 3 1 4 5
3. 1 2 3 5 4
4. 3 1 2 4 5
5. 2 3 1 5 4
6. 1 2 3 4 5.
*/

#include <stdio.h>
#include <queue>
#include <math.h>
#define MOD 1000000007
#define ll long long

using namespace std;

//int primeNoArr[100001], factors[2][100001], noOfPrimes;

//int factors[2][100001];
struct node
{
	ll primeNo, power;
};

/*
void primeNoFinder()
{
	int i, j, sieveArr[100001];
	
	noOfPrimes = 0;
	for(i = 0 ; i <= 100000 ; i++)
		sieveArr[i] = 0;		
	for(i = 2 ; i * i <= 100000 ; i++)
		for(j = i * 2 ; j <= 100000 ; j += i)
			sieveArr[j] = 1;
	for(i = 2, j = 0 ; i <= 100000 ; i++)
		if(sieveArr[i] == 0)
		{
			primeNoArr[j++] = i;
			noOfPrimes++;
		}
}
*/

/*
ll LCM(ll a, ll b)
{
	ll r, lcm = (a * b) % 1000000007;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	lcm = (lcm / a) % MOD;

	return lcm;
}
*/

ll factorization(ll num1, ll num2)
{
	ll i, j, k, l, lcm, temp, p;

	struct node factors[2][100000];
	temp = num1;
	//for(i = 0 ; i <= 100000 && (i <= num1 || i <= num2) ; i++)
	//	factors[0][i] = factors[1][i] = 0;
	k = 0;
	if(num1 % 2 == 0)
	{
		p = 0;
		//factors[0][2] = 0;
		while(num1 % 2 == 0)
		{
			p++;
			num1 /= 2;
		}
		//factors[0][2] = p;
		factors[0][k].primeNo = 2;
		factors[0][k++].power = p;
	}
	for(i = 3 ; i * i <= temp && num1 > 1 ; i += 2)
	{
		//factors[0][i] = 0;
		if(num1 % i == 0)
		{
			p = 0;
			while(num1 % i == 0)
			{
				p++;
				num1 /= i;
			}
			factors[0][k].primeNo = i;
			factors[0][k++].power = p;
		}
	}
	if(num1 > 1)
	{
		factors[0][k].primeNo = num1; 
		factors[0][k++].power = 1;
	}

	temp = num2;
	l = 0;
	if(num2 % 2 == 0)
	{
		p = 0;
		//factors[1][2] = 0;
		while(num2 % 2 == 0)
		{
			p++;
			num2 /= 2;
		}
		factors[1][l].primeNo = 2;
		factors[1][l++].power = p;
	}
	for(i = 3 ; i * i <= temp && num2 > 1 ; i += 2)
	{
		//factors[1][i] = 0;
		if(num2 % i == 0)
		{
			p = 0;
			while(num2 % i == 0)
			{
				p++;
				num2 /= i;
			}
			factors[1][l].primeNo = i;
			factors[1][l++].power = p;
		}
	}
	if(num2 > 1)
	{
		factors[1][l].primeNo = num2;
		factors[1][l++].power = 1;
	}

	lcm = 1;
	for(i = 0, j = 0 ; i < k && j < l ;)
	{
		if(factors[0][i].primeNo == factors[1][j].primeNo)
		{
			if(factors[0][i].power >= factors[1][j].power)
				lcm = (lcm * (ll)pow(factors[0][i].primeNo, factors[0][i].power)) % MOD;
			else
				lcm = (lcm * (ll)pow(factors[1][j].primeNo, factors[1][j].power)) % MOD;
			i++; j++;
		}
		else if(factors[0][i].primeNo < factors[1][j].primeNo)
		{
			lcm = (lcm * (ll)pow(factors[0][i].primeNo, factors[0][i].power)) % MOD;
			i++;
		}
		else
		{
			lcm = (lcm * (ll)pow(factors[1][j].primeNo, factors[1][j].power)) % MOD;
			j++;
		}
	}
	for(; i < k ; i++)
		lcm = (lcm * (ll)pow(factors[0][i].primeNo, factors[0][i].power)) % MOD;
	for(; j < l ; j++)
		lcm = (lcm * (ll)pow(factors[1][j].primeNo, factors[1][j].power)) % MOD;
	/*for(i = 0 ; primeNoArr[i] <= largestPrime1 && primeNoArr[i] <= largestPrime2 ; i++)
	{
		if(factors[0][primeNoArr[i]] || factors[1][primeNoArr[i]])
		{
			if(factors[0][primeNoArr[i]] >= factors[1][primeNoArr[i]])
				lcm = (lcm * (ll)pow(primeNoArr[i], factors[0][primeNoArr[i]])) % MOD;
			else
				lcm = (lcm * (ll)pow(primeNoArr[i], factors[1][primeNoArr[i]])) % MOD;
			//printf("%d %d %d %d\n", primeNoArr[i], factors[0][primeNoArr[i]], factors[1][primeNoArr[i]], lcm);
		}
	}*/
	/*
	if(factors[0][2] || factors[1][2])
	{
		if(factors[0][2] >= factors[1][2])
			lcm = (lcm * (ll)pow(2, factors[0][2])) % MOD;
		else
			lcm = (lcm * (ll)pow(2, factors[1][2])) % MOD;
		//printf("%d %d %d %d\n", primeNoArr[i], factors[0][primeNoArr[i]], factors[1][primeNoArr[i]], lcm);
	}
	for(i = 3 ; i <= largestPrime1 && i <= largestPrime2 ; i += 2)
	{
		if(factors[0][i] || factors[1][i])
		{
			if(factors[0][i] >= factors[1][i])
				lcm = (lcm * (ll)pow(i, factors[0][i])) % MOD;
			else
				lcm = (lcm * (ll)pow(i, factors[1][i])) % MOD;
			//printf("%d %d %d %d\n", primeNoArr[i], factors[0][primeNoArr[i]], factors[1][primeNoArr[i]], lcm);
		}
	}
	j = i;
	for(; j <= largestPrime1 ; j += 2)
	{
		if(factors[0][j])
			lcm = (lcm * (ll)pow(j, factors[0][j])) % MOD;
	}
	j = i;
	for(; j <= largestPrime2 ; j++)
	{
		if(factors[1][j])
			lcm = (lcm * (ll)pow(j, factors[1][j])) % MOD;
	}
	*/

	return lcm;
}

int main()
{
	ll i, j, n, moves, testCases, arr[100010];
	ll movesArr[100010], lcm, num1, num2;
	queue <ll> q;

	scanf("%lld", &testCases);

	//primeNoFinder();
	while(testCases--)
	{
		scanf("%lld", &n);
		for(i = 1 ; i <= n ; i++)
		{
			scanf("%lld", &arr[i]);
			movesArr[i] = 0;
		}

		if(n == 1)
		{
			printf("1\n");
			continue;
		}

		for(i = 1 ; i <= n ; i++)
		{
			moves = 1;
			j = arr[i];
			if(movesArr[i] == 0)
			{
				while(j != i)
				{
					movesArr[j] = 1;
					j = arr[j];
					moves++;
				}
				if(moves != 1)
					q.push(moves);
			}
		}
		
/*		while(!q.empty())
		{
			printf("%lld ", q.front());
			q.pop();
		}
		printf("---\n");
*/		

		if(q.empty())
		{
			printf("1\n");
			continue;
		}
		num1 = q.front();
		q.pop();
		if(q.empty())
		{
			printf("%lld\n", num1 % MOD);
			continue;
		}
		num2 = q.front();
		q.pop();

		lcm = factorization(num1, num2);
		while(!q.empty())
		{
			lcm = factorization(lcm, q.front());
			q.pop();
		}


		printf("%lld\n", lcm % MOD);
		
	}

	return 0;
}
