/*
hdu 5038 ������

���⣺��n�����֣�����10000 - (100 - ai) ^ 2��ʽ�õ�n������
���n������Ƶ��������������в��оͰ�ֵ��С������������
���Ƶ����ͬ��������ȫ����n�����������Bad��


��⣺ͳ�����ָ�����Ƶ�ʣ�����������
*/

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e4 + 5;
int cnt[maxn];//ÿ�������ֵĴ���
int main()
{
	int t;
	int n;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		int s_cnt = 0;  //���ж�������
		int max_s = 0;  //�������������ֵ
		int min_s = maxn;  //������������Сֵ
		int max_cnt = 0;  //�������Ĵ���
		memset(cnt, 0, sizeof(cnt));
		int w;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &w);
			int s = 10000 - (100 - w)*(100 - w);
			if (s > max_s) max_s = s;
			if (s < min_s) min_s = s;
			if (!cnt[s]) s_cnt++;
			cnt[s]++;
			if (cnt[s] > max_cnt) max_cnt = cnt[s];
		}
		printf("Case #%d:\n", cas);
		if (max_cnt*s_cnt == n && s_cnt > 1)  //û��С�����Ƶ�ʵ���,���ǲ�����
			puts("Bad Mushroom");
		else
		{
			int flag = 0;
			for (int i = min_s; i <= max_s; i++)
			{
				if (cnt[i] == max_cnt)
				{
					printf(flag ? " %d" : "%d", i);
					flag = 1;
				}
			}
			puts("");
		}
	}
	return 0;
}