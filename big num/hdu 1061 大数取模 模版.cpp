#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
/*
 * hdu 1061
 * by : mazicwong
 * creat on: 2016/12/10
 */

/*
��n��n�η������һ������,ֱ����ģ��P28
����ȡģ

����ģ�涼������.�ڶ�����������һ��
*/

/*
int mod_exp(int a, int b0, int n)  //return a^b0 & n
{
	if (a > n) a %= n;
	int i, d = 1, b[35];
	for (i = 0; i < 35; i++)
	{
		b[i] = b0 % 2;
		b0 /= 2;
		if (b0 == 0) break;
	}//b[i] b[i-1] ...b[0]Ϊb0�Ķ����Ʊ�ʾ
	for (; i >= 0; i--)
	{
		d = (d*d) % n;
		if (b[i] == 1) d = (d*a) % n;
	}
	return d;
}
*/

int mod_exp(int a, int b, int c)
{
	int ans = 1;
	a = a%c;
	while (b > 0)
	{
		if (b & 1)
			ans = (ans*a) % c;
		b = b >> 1;
		a = (a*a) % c;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", mod_exp(n, n, 10));//return n^n % 10
	}
	return 0;
}