#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
�����ӽ�����....����⽻��21��
TLE
ԭ����.....����credits��double��,��cre��int��...����ֱ�Ӽӹ�ȥ��TLE....��������ж���....
*/
int main()
{
	int n,k,flag;
	double credits = 0, ans = 0;
	double cre, sco;
	string str;
	cin >> n;
	while(n--)
	{
		getchar();
		credits = ans = flag = 0;
		cin >> k;
		while (k--)
		{
			cin >> str >> cre >> sco;
			credits += cre;
			if (sco < 60)
				flag = 1;
			ans += (cre*sco);
		}
		if (flag)
			cout << "Sorry!\n";
		else
			printf("%.2lf\n", ans / credits);
		if (n)
			cout << endl;
	}
	return 0;
}