#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
/*
gems : ��ʯ
����:��������,��һ�θ���Ҫ1����ʯ,������ÿ�η���(��n��)
	 ���������Ļ����Լ���ÿ�ε����� m �� (�ȼ�Ϊm)
	 ����,����ı�ʯ��������Ϊ1

give : 
	t
	n (1...30)
	m (0...5)

˼·:�򵥹�ʽ
*/
int main()
{
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		ll ans = (1ll << n - 1) - m;
		if (ans < 1) ans = 1;
		printf("%I64d\n", ans);
	}
	return 0;
}