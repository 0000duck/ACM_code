#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
/*
problem: poj 3468 ����߶�������������ѯ����
solve��
thinking: 
*/


/*
����: ����պø���һ���ڵ�,������addֵ,�������value,�ټ����´�
	  �����Ͳ���ÿ�ζ����µ�Ҷ�ӽڵ�
��ѯ: ����������ø���һ���ڵ�,��add���´�,��add�ӵ�value��Ȼ��add����,
	  ���ż������²�ѯ
*/


const int maxn = 1e5 + 5;
inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	ll value, add;
}node;
node tree[maxn * 4];
ll arr[maxn];
ll sum = 0;
void Creat(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].add = 0;
	if (l == r) {tree[root].value = arr[l]; return;}
	int mid = MID(l, r);
	Creat(l, mid, L(root));
	Creat(mid + 1, r, R(root));
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

//���½ڵ�,�Ѵ������addֵ����С����
//С����add���ϴ��add,С�����valueҪ�����������������ӵ�ֵ
void Update(int node)
{
	if (tree[node].add)
	{
		tree[L(node)].add += tree[node].add;
		tree[R(node)].add += tree[node].add;
		tree[L(node)].value += (tree[L(node)].right - tree[L(node)].left + 1)*tree[node].add;
		tree[R(node)].value += (tree[R(node)].right - tree[R(node)].left + 1)*tree[node].add;
		tree[node].add = 0;
	}
}

//��������(ÿ�����һ��ֵ)
void Add(int l, int r, ll val, int root)
{
	if (l <= tree[root].left&&tree[root].right<=r)
	{//����ڵ��ڸ��µ���������,ֱ������add��valueȻ���˳�
		tree[root].add += val;
		tree[root].value += (tree[root].right - tree[root].left + 1)*val;
		return;
	}
	Update(root);
	if (tree[root].left == tree[root].right) return;

	//����rootΪ��������,��СҪ���µ����䷶Χ,�õݹ�ֱ������������ڵ�
	int mid = MID(tree[root].left, tree[root].right);
	if (mid < l) Add(l, r, val, R(root));
	else if (mid >= r) Add(l, r, val, L(root));
	else
	{
		Add(l, mid, val, L(root));
		Add(mid + 1, r, val, R(root));
	}
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

//������������ڵĺ�
void Solve(int l,int r,int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)
	{
		sum += tree[root].value;
		return;
	}
	Update(root);

	if (tree[root].left == tree[root].right)return;
	
	int mid = MID(tree[root].left, tree[root].right);
	if (mid < l) Solve(l, r, R(root));
	else if (mid >= r) Solve(l, r, L(root));
	else
	{
		Solve(l, mid, L(root));
		Solve(mid + 1, r, R(root));
	}
}

int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%I64d", &arr[i]);
		Creat(1, n, 1);
		char qq;
		while (q--)
		{
			getchar();
			qq = getchar();
			if ('C' == qq)
			{
				int l, r;
				ll val;
				scanf("%d%d%I64d", &l, &r, &val);
				Add(l, r, val, 1);//left,right,value,root
			}
			else
			{
				int l, r;
				scanf("%d%d", &l, &r);
				sum = 0;
				Solve(l, r, 1);//left,right,root
				printf("%I64d\n", sum);
			}
		}
	}
	return 0;
}