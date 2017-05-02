#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <cctype>
#include <iomanip>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>

using namespace std;
const int maxn = 5000 + 5;
char a[maxn];
char b[maxn];
//priority_queue <char>pque;
vector<char>vec;
map<char,int>mp;
map<char, int>mpb;
/*
��Ϊֻ��abc�������,�ǵ��ж�ʣ���������ǲ���ֻ���������е�һ��
*/
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char x;
		mp['a'] = mp['b'] = mp['c'] = 0;
		mpb['a'] = mpb['b'] = mpb['c'] = 0;
		vec.clear();

		getchar();
		for (int i = 0; i < n; i++)
		{
			x = getchar();
			mp[x]++;
			vec.push_back(x);
		}
		getchar();
		scanf("%s", b);
		for (int i = 0; i < n; i++)
			mpb[b[i]]++;

		//��a����
		sort(vec.begin(), vec.end());
		//����b��,�ı�a��,ʹ���ֵ�����С�Ҷ�Ӧλ�ò�ͬ
		for (int i = 0; i < n; i++)
		{
			vector<char>::iterator it = vec.begin();
			while (1)
			{
				mp[*it]--;
				mpb[b[i]]--;
				if (it == vec.end()-1) //����debug�˺ܾ�...vec.end()��ָ�����һ��Ԫ�ص���һλ...�����ж�ĩβʱ����vec.end()-1
				{
					printf("%c", *it);
					vec.erase(it);
					break;
				}
				else if ((mp['a'] == 0 && mp['b'] == 0 && mp['c'] == mpb['c']) ||
					(mp['b'] == 0 && mp['c'] == 0 && mp['a'] == mpb['a']) ||
					(mp['a'] == 0 && mp['c'] == 0 && mp['b'] == mpb['b']) ||
					*it == b[i]
					)
				{
					mp[*it]++;
					mpb[b[i]]++;
					it++;
				}
				else
				{
					printf("%c", *it);
					vec.erase(it);
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}