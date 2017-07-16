
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
/*
��Ϊÿ�������໥����,���Դ���2^n
������֪����32^n
*/
const int maxn = 3e4 + 5;
const int mod = 100;
int num[maxn];
int len;

void solve(int n) //�����˷�  32^n
{
	memset(num, 0, sizeof(num));
	num[1] = 1; len = 1;
	for (int i = 1; i <= n; i++)
	{
		int c = 0;
		for (int j = 1; j <= len; j++)
		{
			num[j] *= 32;
			num[j] += c;
			c = num[j] / mod;
			num[j] %= mod;
		}
		while (c)
		{
			num[++len] = c%mod;
			c /= mod;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	int n;
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		solve(n);
		printf("Case #%d: ", cas);
		for (int i = len; i > 0; i--)
		{
			if (i!=len)
				printf("%02d", num[i]);
			else
				printf("%d", num[i]);
		}
		puts("");
	}
	return 0;
}
