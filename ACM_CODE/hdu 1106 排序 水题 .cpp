#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
substr(begin,length)
Ҫ���ǿ�ͷ��5��  556
Ҫ���ǽ�β��5��
vec.end()��������һλ,���������ʱ���ڱȽϵ�����Ӧ��ע��
*/
int main()
{
	string str;
	while (cin >> str)
	{
		vector <string> vec;
		int begin = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '5')
			{
				if (begin == j)//��ͷ��5
				{
					begin = j + 1;
					continue;
				}
				vec.push_back(str.substr(begin, j-begin));
				begin = j+1;
			}
			else if (j == (str.size() - 1))//��β��5
			{
				vec.push_back(str.substr(begin, j - begin + 1));
			}
		}

		vector<int> num;
		for (auto & w : vec)
		{
			int sum = 0;
			string ss = w;
			int i = 0;
			while (ss[i])
			{
				sum = sum * 10 + (ss[i] - '0');//(ss[i]-'0')��Ҫ��(int)ss[i]
				i++;
			}
			num.push_back(sum);
		}
		sort(num.begin(), num.end());

		//��������for (auto &w :num) ���ǲ�֪����ôȡ���һ��Ԫ��������...���Ժ�֪���ٸİ�..(Ӧ���ǲ����Ե�)
		for (vector<int>::iterator it = num.begin(); it != num.end(); it++)
		{
			if (it == num.end()-1)//�ǵ�num.end()��ָ�����һ��Ԫ�ص���һ��..
				printf("%d\n", *it);
			else
				printf("%d ", *it);
		}
	}
	return 0;
}