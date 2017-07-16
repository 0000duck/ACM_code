/*
* hdu 2187
* author  : mazciwong
* creat on: 2016-12-11
*/

/*
	��̰��. ֱ������
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
struct rice {
	int p;  //��
	int w;  //��
}rr[maxn];
int cmp(rice &a, rice &b)
{
	return a.p < b.p;//�����۴�С������
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);  //�ܼ�  ������
		for (int i = 0; i < m; i++)
			scanf("%d%d", &rr[i].p, &rr[i].w);
		sort(rr, rr + m, cmp);
		double ans = 0;
		for (int i = 0; i < m; i++)
		{
			if (n > rr[i].p*rr[i].w)  //����
			{
				ans += rr[i].w;
				n -= rr[i].p*rr[i].w;
			}
			else
			{
				ans += (double)n / rr[i].p;
				break;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}