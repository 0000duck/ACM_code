#include <iostream>
using namespace std;
/*
�����˺ܶ�����ݲſ���ͨ��
1 3
1 0 0

2 5
0 0 1 1 1 

2 5
1 1 1 1 1
 
2 5��
0 1 1 1 1
�����ѧ������֪ʶ...�Լ���Щ���ݲ���ų�������...
��Ȼǰ�������������ܹ��ֶ�����𰸵���Ŀ
*/
const int maxn = 35;
typedef long long ll;
int main()
{
	int t;
	scanf("%d", &t);
	int n, m;
	int x[maxn];
	ll cnt = 0;//���˼���
	ll ans = 0;
	while (t--)
	{
		ans = 0;
		cnt = 0;
		scanf("%d%d", &m, &n);
		//һ����n��
		//0��Ů,1����
		bool flag = false;//��ʼ����
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
			if (!flag)
			{
				if (i > m)
				{
					flag = true;
					cnt = 1;
				}

				else if (1 == x[i])
				{
					flag = true;
					cnt = 0;
				}
			}
			if (flag)
			{
				if (cnt)
				{
					ans = ans + cnt;
					cnt *= 2;
				}
				else
				{
					cnt = 1;
				}
			}
		}
		if (ans)
			printf("%I64d0000 RMB\n", ans);
		else
			puts("0 RMB");
	}
	//system("pause");
	return 0;
}