#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e5+5;
/*
����:
Alice��Bob�ĸ���n������������
ÿ�ζԱ�,A��˳�򲻱�,B��������˳��,
AӮ�Ļ�"+X��",ƽ"+Y��",��"-Z��"
��A���յ÷ֵ�����,2 decimal digits

give: n x y z 
	  a1,a2.....an
	  b1,b2.....bn

˼·:�ֱ�ͳ��Aÿ�����ĵ÷�����,�����ᳬʱ
	 �����ȶ�B����
	 ��B�ж��ֲ��ҷֽ��
���Ӷ�:  O(n*log(n))
*/
/*
3 3 2 5
2 5 6
3 4 5
----
0.67
*/
vector<int> a1, a2;
map<int,int> mp;
int a;
int main()
{
	int n, x, y, z;
	while (scanf("%d%d%d%d", &n, &x, &y, &z) != EOF)
	{
		double ans = 0;
		mp.clear(),a1.clear(), a2.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			a1.push_back(a);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			a2.push_back(a);
			mp[a]++;
		}
		sort(a2.begin(), a2.end());
		vector<int>::iterator index, beg, en;
		for (int i = 0; i < n; i++)
		{//lower_bound() : not compare less than val
			beg = lower_bound(a2.begin(), a2.end(), a1[i]);
			en = upper_bound(a2.begin(), a2.end(), a1[i]);
			ans += x*(beg - a2.begin()) + y*(en - beg) - z*(a2.end() - en);
		}
		ans /= n;
		printf("%.2lf\n", ans);
	}
	return 0;
}