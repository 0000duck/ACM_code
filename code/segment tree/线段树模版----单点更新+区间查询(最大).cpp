#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;

/*
�ο�����:
hdu 1754 ����߶�������������ѯ����
	�������:
	�����ѯ: �����ֵ

*/

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	int value;//���������ֵ
}node;
node tree[maxn * 4];
int arr[maxn];//��Žڵ�
int sum = 0;//��ѯ���ĺ�

void Build(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	if (l == r) { tree[root].value = arr[l]; return; }//�ɵ�Ҷ���˾͸�ֵ
	int mid = MID(l, r);
	Build(l, mid, L(root));
	Build(mid + 1, r, R(root));
	tree[root].value = max(tree[L(root)].value, tree[R(root)].value);
}

//��������(ÿ�����һ��ֵ)
void Insert(int l, int r, int val, int root)
{
	if (l == tree[root].left&&tree[root].right == r)
	{//����ҵ��������,�͸�����Ȼ���˳�
		tree[root].value = val;
		return;
	}

	//���ֲ������ͬѧ...
	int mid = MID(tree[root].left, tree[root].right);
	//������ж�ֻ��˵��Ҫȥ�������һ�����������
	if (mid < l) Insert(l, r, val, R(root));
	else if (mid >= r) Insert(l, r, val, L(root));
	else
	{
		Insert(l, mid, val, L(root));
		Insert(mid + 1, r, val, R(root));
	}
	tree[root].value = max(tree[L(root)].value, tree[R(root)].value);
}

//��ѯ���ֵ,���ǽڵ����value
void Query(int l, int r, int root)
{
	if (l == tree[root].left&&tree[root].right == r)
	{
		if (sum<tree[root].value)
			sum = tree[root].value;
		return;
	}

	int mid = MID(tree[root].left, tree[root].right);
	//�����ж��ǵ�������������ǵ������������
	if (mid < l) Query(l, r, R(root));
	else if (mid >= r) Query(l, r, L(root));
	else
	{
		Query(l, mid, L(root));
		Query(mid + 1, r, R(root));
	}
}


/*
arr[]���  (1...n)
Build ����
Insert ����ֵ
Query ��ѯ�����
*/
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		Build(1, n, 1);//left,right,root
		char qq;
		while (q--)
		{
			getchar();
			qq = getchar();
			if ('U' == qq)
			{
				int a, val;
				scanf("%d%d", &a, &val);
				Insert(a, a, val, 1);//left,right,value,root
			}
			else
			{
				int l, r;
				scanf("%d%d", &l, &r);
				sum = 0;
				Query(l, r, 1);//left,right,root
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}