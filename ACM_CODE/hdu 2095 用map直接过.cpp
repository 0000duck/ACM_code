#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
/*
2095 ����������
�������,�ҳ����е�����һ������
*/
int main()
{
	int n;
	map<int, int >mp;
	int a;
	while (scanf("%d", &n) && n)
	{
		mp.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			mp[a]++;
		}
		for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second == 1)
			{
				printf("%d\n", it->first);
				break;
			}
		}
	}


	return 0;
}