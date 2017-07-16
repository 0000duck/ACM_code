#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

/*
�ο�����: 
poj 3468 ����߶�������������ѯ����
	�������: ����һ����
	�����ѯ: ���
hdu 1166
	�������: �ӻ��߼�һ����
	�����ѯ: ���
hdu 1698 
	�������: �滻Ϊ�����
	�����ѯ: ���
*/

/*
����: ����պø���һ���ڵ�,������lazyֵ,�������value,�ټ����´�
�����Ͳ���ÿ�ζ����µ�Ҷ�ӽڵ�
��ѯ: ����������ø���һ���ڵ�,��lazy���´�,��lazy�ӵ�value��Ȼ��lazy����,
���ż������²�ѯ
*/

/*
LAZY���(�ӳٱ��)
��lazy��ǵķ�Ҷ�ӽڵ�������������Ҷ�ӽڵ������ͬ�����ʣ�
�����»��ѯ��������ʱ���������µݹ飬���Ե�ǰ�ڵ��lazy��ǽ����޸ġ�
*/


inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	int value, lazy;//lazy�ǿ��Դ�ż������������ֵ,�Ų���һֱ���µ�Ҷ��
}node;
node tree[maxn * 4];
int arr[maxn];//��Žڵ�
int sum = 0;//��ѯ���ĺ�

//���½ڵ�,�Ѵ������lazyֵ����С����
//С����lazy���ϴ��lazy,С�����valueҪ�����������������ӵ�ֵ
void PushUp(int root)
{
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

void PushDown(int node)
{//������,�����������lazy
 //�����lazy,����������lazy����һ��,����������ֵҲ����һ��
	if (tree[node].lazy)
	{
		tree[L(node)].lazy += tree[node].lazy;
		tree[R(node)].lazy += tree[node].lazy;
		tree[L(node)].value += (tree[L(node)].right - tree[L(node)].left + 1)*tree[node].lazy;
		tree[R(node)].value += (tree[R(node)].right - tree[R(node)].left + 1)*tree[node].lazy;
		tree[node].lazy = 0;
	}
}

void Build(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].lazy = 0;
	if (l == r) { tree[root].value = arr[l]; return; }
	int mid = MID(l, r);
	Build(l, mid, L(root));
	Build(mid + 1, r, R(root));
	//tree[root].value = tree[L(root)].value + tree[R(root)].value;
	PushUp(root);
}


//��������(ÿ�����һ��ֵ)
void Insert(int l, int r, int val, int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)//������µĻ�,������õ���
	{//����ڵ��ڸ��µ���������,ֱ������lazy��valueȻ���˳�
		tree[root].lazy += val;
		tree[root].value += (tree[root].right - tree[root].left + 1)*val;
		return;
	}
	PushDown(root);
	if (tree[root].left == tree[root].right) return;

	//����rootΪ��������,��СҪ���µ����䷶Χ,�õݹ�ֱ������������ڵ�
	int mid = MID(tree[root].left, tree[root].right);
	//������ж�ֻ��˵��Ҫȥ�������һ�����������
	if (mid < l) Insert(l, r, val, R(root));
	else if (mid >= r) Insert(l, r, val, L(root));
	else
	{
		Insert(l, mid, val, L(root));
		Insert(mid + 1, r, val, R(root));
	}
	//tree[root].value = tree[L(root)].value + tree[R(root)].value;
	PushUp(root);
}

//������������ڵĺ�
void Query(int l, int r, int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)
	{
		sum += tree[root].value;
		return;
	}
	PushDown(root);

	if (tree[root].left == tree[root].right)return;

	int mid = MID(tree[root].left, tree[root].right);
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
PushDown ����ֵ��������
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
		char qq; // if qq=='C',Insert; if qq=='Q',calu the sum
		while (q--)
		{
			getchar();
			qq = getchar();
			if ('C' == qq)
			{
				int l, r;
				int val;
				scanf("%d%d%d", &l, &r, &val);
				Insert(l, r, val, 1);//left,right,value,root
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