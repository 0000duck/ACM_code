//http://blog.csdn.net/u013480600/article/details/44646517
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <string>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <math.h>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <deque>  
#include <set>  
#include <map>  
#include <time.h>;

/*************************MPģ��****************************/
char T[1000];//��ƥ�䴮  
char P[100];//ģ�崮  

			//ʧ��ָ��,��ס����fҪ��P��һλ  
			//��ΪP��m-1����,����f��Ҫ�����m��ʧ��ָ��  
int f[101];

void find(char *T, char *P, int *f) //�ҵ�����ƥ���  
{
	int n = strlen(T), m = strlen(P);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j && T[i] != P[j]) j = f[j];
		if (T[i] == P[j]) j++;
		if (j == m) printf("%d\n", i - m + 1);//����j��m�ˣ�Ҳ��f[m]����ƥ��  
	}
}
void getFail(char *P, int *f) //f��failʧ������
{
	int m = strlen(P);
	f[0] = f[1] = 0;
	for (int i = 1; i < m; i++)//��Ȼ�ַ�����0��m-1������Ҫ���f[m]��ֵ  
	{
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}
/*************************MPģ��****************************/

http://blog.csdn.net/u013480600/article/details/44646517
http://blog.csdn.net/u013480600/article/details/22929489
http://acm.hdu.edu.cn/showproblem.php?pid=2594
http://blog.csdn.net/libin56842/article/category/1433736
http://blog.csdn.net/xingyeyongheng/article/details/9285989