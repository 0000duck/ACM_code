#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;

/*
 * problem :hdu 1754
 * �������(��),�����ѯ(����ֵ)
 *
 * ����: arr[]��Ҷ�ӽڵ�  (1...n)
 * build()  ����
 * update() ����ֵ
 * query()  ��ѯ��ֵ
 */

inline int L(int l) { return l<<1;}
inline int R(int r) { return (r<<1)+1;}
inline int MID(int l, int r) { return (l+r)>>1;}
struct node{
    int l,r;
    int Max;//���������ֵ
}tree[maxn<<2];     //tree[1..2^n-1]
int arr[maxn];      //��ų�ʼ�ڵ�arr[1..n]
int ans = 0;        //��ѯ�������ֵ

void PushUp(int rt)
{
    //����ʱ,���������Ƚڵ�PushUp������ֵ
    tree[rt].Max = max(tree[L(rt)].Max, tree[R(rt)].Max);
}

//��ʼ�����ڵ�,�ݹ���Ҷ��,���ݸ���ÿ���ڵ��ֵ(l,r,val)
//��Щ�������϶��¾Ͷ�����,��ЩҪ��ȷ�����ӵ�,����Ҫ���ݲ�ȷ��
void build(int l, int r, int rt)
{
    //l,rֻ��һ��,���治����,ֻ������ֵ
	tree[rt].l=l;  tree[rt].r=r;
	if (l==r) //��Ҷ����,ֱ�Ӹ�����ֵ
    {
        tree[rt].Max = arr[l];
        return;
    }

    //����,��������
    int mid = MID(l,r);
    build(l, mid, L(rt));
    build(mid+1, r, R(rt));

    //���ݸ�����ֵ
    PushUp(rt);
}

//��������(�����������Ӧ�ڵ��Լ�������������);�����ڻ���ʱ�����
void update(int l, int r, int val, int rt)
{
    if (l==tree[rt].l && tree[rt].r==r)//�ҵ�
    {
        tree[rt].Max = val;
        return;
    }

    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) update(l,r,val,R(rt));        //��������
    else if (mid>=r) update(l,r,val,L(rt));  //��������
    else                                     //ͬʱ����������
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }

    PushUp(rt);
}

//�����ѯ(��ֵ--�ڵ������ֵMax���)
void query(int l, int r, int rt)//���ҵķ�Χ[l,r],��ǰ���ڵĸ�rt
{
    if (l==tree[rt].l && tree[rt].r==r)//�ҵ�����(<=)
    {
        ans = max(ans,tree[rt].Max);
        return;
    }
    //if (tree[rt].l==tree[rt].r) return;

    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) query(l,r,R(rt));             //��������
    else if (mid>=r) query(l,r,L(rt));       //��������
    else                                     //ͬʱ����������
    {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}

int main()
{
    //freopen("in","r",stdin);
    int n,q;
    while (scanf("%d%d",&n,&q)!=EOF)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        build(1,n,1);//left,right,root
        while (q--)
        {
            getchar();
            char qq = getchar();
            if ('U' == qq)
            {
                int idx,val;
                scanf("%d%d",&idx,&val);//��������������¾͸��������һ����
                update(idx,idx,val,1);//left,right,value,root
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                ans = 0;
                query(l,r,1);//left,right,root
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
