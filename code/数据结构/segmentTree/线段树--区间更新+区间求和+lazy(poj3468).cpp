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
 * poj3468
 * �������(��),�����ѯ(���)
 *
 * ����: arr[]���  (1...n)
 *
 * build()     ����
 * update()    ����ֵ
 * query()     ��ѯ�����
 * PushUp()    (�����͸���ʱ)����ά��value
 * PushDown()  (��ѯ������н���ʱ�Ż��õ�)���¸���lazy,value
 * 
 * ����: ����պø���һ���ڵ�,������lazyֵ,�������value,�ټ����´�
 *       �����Ͳ���ÿ�ζ����µ�Ҷ�ӽڵ�
 * ��ѯ: ����������ø���һ���ڵ�,��lazy���´�,��lazy�ӵ�value��Ȼ��lazy����,
 *       ���ż������²�ѯ
 *
 *
 * LAZY���(�ӳٱ��)
 * ��lazy��ǵķ�Ҷ�ӽڵ�������������Ҷ�ӽڵ������ͬ�����ʣ�
 * �����»��ѯ��������ʱ���������µݹ飬���Ե�ǰ�ڵ��lazy��ǽ����޸ġ�
 */

typedef long long ll;

inline int L(int l) {return l<<1;}
inline int R(int r) {return (r<<1)+1;}
inline int MID(int l, int r) {return (l+r)>>1;}
struct {
    int l,r;
    ll val;   //�ڵ�����ֵ,�����������
    ll lazy;  //�ýڵ��Ӧ�����ӽڵ�Ӧ�ü��ϵ�ֵ,�Ų���һֱ���µ�Ҷ��
}tree[maxn<<2];     //tree[1..2^n-1]
int arr[maxn];      //��ų�ʼ�ڵ�arr[1..n]
ll sum = 0;         //��ѯ���ĺ�


//"��������"��"��������"���ĵݹ����ʱ���ϸ���value
void PushUp(int rt)
{
    tree[rt].val = tree[L(rt)].val + tree[R(rt)].val;
}


//"��ѯ"��"����"ʱ��PushDownһ�´����������lazy��value
void PushDown(int rt)
{
    if (tree[rt].lazy)
    {
        tree[L(rt)].lazy += tree[rt].lazy;
        tree[R(rt)].lazy += tree[rt].lazy;
        tree[L(rt)].val += (tree[L(rt)].r-tree[L(rt)].l+1)*tree[rt].lazy;
        tree[R(rt)].val += (tree[R(rt)].r-tree[R(rt)].l+1)*tree[rt].lazy;

        tree[rt].lazy = 0;
    }
}

void build(int l, int r, int rt)
{
    tree[rt].l=l; tree[rt].r=r;
    tree[rt].lazy = 0;
    if (l==r) //�ҵ�Ҷ��,��ֵ
    { 
        tree[rt].val = arr[l];
        return;
    }

    //����
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));

    //����ά��value(�����)
    PushUp(rt);
}

//�������(ÿ�����һ��ֵ)
void update(int l, int r, int val, int rt)//���·�Χ[l,r],��ǰ���ڵĸ�rt
{
    //if (l<=L(rt) && R(rt)<=r) ??? ��Ϊ(tree[rt].l,tree[rt].r)�Ǳ�ʾ�ýڵ��Ӧ�����䷶Χ;��L(rt),R(rt)���������Ҷ��ӽڵ�
    //��root=1�����Ӿͺ�������,(1,n);(2,3);
    if (l<=tree[rt].l && tree[rt].r<=r)//������µĻ�,������õ���
    {
        //����ڵ��ڸ��µ���������,ֱ������lazy��valueȻ���˳�
        tree[rt].lazy += val;
        tree[rt].val += (tree[rt].r-tree[rt].l+1)*val;
        return;
    }

    PushDown(rt);
    if (tree[rt].l == tree[rt].r) return;


    //����
    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) update(l,r,val,R(rt));        //����������
    else if (mid>=r) update(l,r,val,L(rt));  //����������
    else                                     //������������
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }

    //����ά��value
    PushUp(rt);
}

//��ѯ����(��)
void query(int l, int r, int rt)//���ҵķ�Χ[l,r],��ǰ���ڸ�rt
{
    if (l<=tree[rt].l && tree[rt].r<=r)
    {
        sum += tree[rt].val;
        return;
    }

    PushDown(rt);
    if (tree[rt].l == tree[rt].r) return;


    //����
    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) query(l,r,R(rt));
    else if (mid>=r) query(l,r,L(rt));
    else
    {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}

int main()
{
    freopen("in","r",stdin);
    int n, q;
    while (scanf("%d%d",&n,&q) != EOF)
    {
        for (int i=1; i<=n;i++)
            scanf("%d",&arr[i]);
        build(1,n,1);//left,right,rt

        while (q--)
        {
            getchar();
            char qq = getchar();
            if ('C' == qq) //update
            {
                int idxl,idxr;
                ll val;
                scanf("%d%d%lld",&idxl,&idxr,&val);
                update(idxl,idxr,val,1);//left,right,value,rt
            }
            else //sum
            {
                int l, r;
                scanf("%d%d",&l,&r);
                sum = 0;
                query(l, r, 1);//left,right,rt
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}
