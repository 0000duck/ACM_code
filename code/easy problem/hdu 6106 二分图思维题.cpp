#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>	
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
/*
����ͼ,����ûʲô��ϵ
ÿ�����ж�����һ��Ϊ��������һ��ΪŮ��
�������ǿ��԰���"Ů��A������B��Ů��C������D"�ķ�ʽ�����������ʹ�ô�*2�ͺá�
*/
int x[maxn];
int y[maxn];
int cnt1[maxn];
int cnt2[maxn];
int main()
{
	int t;
	int n, m, k;
	scanf("%d", &t);
	while (t--)
	{
		ll ans = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= k; i++)
		{//x[i]:����i�����ߵ�����ĸ���,y[i]:����i�����ߵ�����ĸ���
			scanf("%d%d", &x[i], &y[i]);
			cnt1[x[i]]++;
			cnt2[y[i]]++;
		}
		//�����ѭ��ö������B,�����Ů��C,Ů��A�ĸ���Ϊ(cnt1[x[i]]-1),������D�ĸ���Ϊ(cnt2[y[i]]-1)
		for (int i = 1; i <= k; i++)//������B��Ů��C�ǹ̶���,ȡ
			ans += 2ll*(cnt1[x[i]] - 1)*(cnt2[y[i]] - 1);
		printf("%I64d\n", ans);
		memset(cnt1, 0, sizeof(cnt1) + 1);
		memset(cnt2, 0, sizeof(cnt2) + 1);
	}
	return 0;
}