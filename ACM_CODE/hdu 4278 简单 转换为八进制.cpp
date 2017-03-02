/*
hdu 4278 ת��Ϊ�˽��Ƽ���

*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
/*


 */


int table[] = { 0,1,2,-1,3,4,5,6,-1,7 };
int n;

void solve()
{
	int ans = 0, power = 1;//ʵ����̺�ÿһλ��Ȩ
	while (n)
	{
		ans += power*table[n % 10];
		power *= 8;
		n /= 10;
	}
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%d", &n) && n)
	{
		printf("%d: ", n);
		solve();
	}
	return 0;
}