#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
/*
* hdu 2053
* by : mazicwong
* creat on: 2016/12/10
*/

/*
���Լ������Ϊż��,��״̬����,����0.
���Լ������Ϊ����,��״̬�ı�,���1

�ַ���

��������Ϊƽ����ʱ,��Լ����Ϊ����,�����ǳɶԴ��ڵ�
*/
int main()
{
	int n;
	while (scanf("%d", &n)!=EOF)
	{
		int x = sqrt(n);
		if (x*x == n) puts("1");
		else puts("0");
	}
	return 0;
}