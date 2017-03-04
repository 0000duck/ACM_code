#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
/*

����:
�޶�m*n��С�����У�����K������Ȼ������п��Խ���Insert��a����Remove��a����Find��a��������
ִ��Insert��������������������������������������Ȼ����룻Find����������Ƿ����a����

give :
	t m n (test case , row , column)
	K (�������ж��ٸ���)
	Q (Q�β���)
	������Q��  C,v (C�ǲ���,v����)

˼·:STL��set����
*/

/*
����
1
3 4
8
1 2 8 5 3 4 6 6
10
I 7
I 10
R 6
F 6
I 9
I 11
I 12
F 15
I 100
F 100
*/

/*
��Ҫע��ĵ���,multiset.erase()���ͬԪ�ص����и���ɾ��,���������ɾ��3,������������ж���һ��
Ӧ����:
int x =3;
multiset<int>::iterator pos = s.find(x);
s.erase(pos);
*/
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	multiset<int> s;
	int t, m, n;
	scanf("%d", &t);
	while (t--)
	{
		s.clear();
		scanf("%d%d", &m, &n);
		int k,a;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &a);
			s.insert(a);
		}
		int q;
		char b;
		int val;
		scanf("%d%*c", &q);
		while (q--)
		{
			scanf("%c%d%*c", &b, &val);
			if (b == 'I')
			{
				s.insert(val);
				if (s.size() > n*m)
				{
					multiset<int>::iterator pos = s.end();
					pos--;
					s.erase(pos);
				}
			}
			else if (b == 'R')
			{//����ֱ��s.erase(val); ==>>��ɾ����ֹһ��
				multiset<int>::iterator pos = s.find(val);
				if (pos!=s.end())
					s.erase(pos);
			}
			else
			{
				if (s.count(val) != 0)
					puts("Bingo");
				else
					puts("Opps");
			}
		}
	}
	return 0;
}