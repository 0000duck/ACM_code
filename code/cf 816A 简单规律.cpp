/*************************************************************************
> File Name: a.cpp
> Author: mazicwong
> Mail: mazicwong@gmail.com
> Created Time: 2017��06��17�� ������ 22ʱ18��46��
************************************************************************/
/*
����һ��hh:mm�������ʾСʱ�ͷ���,Ȼ��ÿ��mm����һ��,60��λ,
��ʲôʱ��hh��mm�γ�һ�����Ĵ�

WA��,05:51�����,������69,��ʵ����06:60��ʱ�������,������,�����¾ͺ���
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int h, m;
	char str[6];
	cin >> str;
	scanf("%d:%d", &h, &m);
	int cnt = 0;
	while (1)
	{
		if (str[3]>'5')
		{
			str[1]++;
			str[3] = '0';
			continue;
		}
		else if (str[4]>'9')
		{
			str[3]++;
			str[4] = '0';
			continue;
		}
		else if (str[0] == '2' && str[1] == '4')
		{
			str[0] = '0';
			str[1] = '0';
			continue;
		}
		else if (str[1]>'9')
		{
			str[0]++;
			str[1] = '0';
			continue;
		}
		if (str[0] == str[4] && str[1] == str[3])
			break;
		cnt++;
		str[4]++;

	}
	cout << cnt << endl;
	return 0;
}