#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
n*m����,�ص����е�,ÿ��·���Ƶ�״̬��ת��
ÿ�δ����Ͻ��ߵ�һ��1,Ȼ�󷵻ص����Ͻ�,ÿ������һ��1
*/
int main()
{
	int t;
	int n, m;
	int qq;
	cin >> t;
	while(t--)
	{
		int cnt = n + m - 1;//���Ҫ������һ��n+m-1��,�൱��ȥ��n+m-1���ٷ���
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &qq);
				if (qq) cnt++; //Ҫ�����һ��,����cnt++
			}
		}
		printf("%s\n", cnt & 1 ? "NO" : "YES");
	}
}
