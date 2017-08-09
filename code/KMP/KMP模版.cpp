

/*********************KMP ģʽ��ƥ��**************************/
//http://www.cnblogs.com/zhangtianq/p/5839909.html
// O(n+m)
T[]: ĸ��
P[]: ģʽ��
next[]: ����ǰ�ַ�������ͬǰ׺��׺(λ��Ҫ��P[]��һλ,next[0]=-1)
next[j]=k: j֮ǰ���ַ���������󳤶�Ϊk����ͬǰ׺��׺

kmp˼��: Ԥ�����ģʽ��P�����next[]����;����ʱ,iֻɨһ��,��T[i]��P[j]ʧ��ʱ,P�����ƶ�j-next[j],��j=next[j]
- ���j=-1,���ߵ�ǰ�ַ�ƥ��ɹ�(��S[i]==P[j]),����i++,j++,����ƥ����һ���ַ�;
- ���j!=-1,�ҵ�ǰ�ַ�ƥ��ʧ��(��S[i] != P[j]),����i����,j=next[j]��
�˾���ζ��ʧ��ʱ��ģʽ��P������ı���S�����ƶ���j-next[j]λ��

����:
1.�Ӵ���ĸ���г��ּ���
2.����һ��P����һȺ��ͬ��T��,��P������Щ�����Ӵ�(ֻԤ����һ��P,�ܺ���)

void getNext(char *P,char *next)
{
    int pp = strlen(P);
    next[0]=-1;
    int k=-1,j=0;
    while(j<pp-1)
    {
        if (k==-1 || P[j]==P[k]) //P[k]ǰ׺,P[j]��׺
        {
            j++;k++;
            //�Ż�,����P[j]=P[next[j]]ʱ���еݹ�,k=next[k]=next[next[k]]
            if (P[j]!=P[k]) next[j]=k;
            else next[j]=next[k];
        }
        else k=next[k];
    }
}

int kmp(char *T,char *P)
{
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    while(i<tt && j<pp)
    {
        //���j=-1�����ߵ�ǰ�ַ�ƥ��ɹ�����T[i] == P[j]��,����i++,j++
        if (j==-1 || T[i]==P[j])
        {
            i++;
            j++;
        }
        //���j!=-1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���T[i] != P[j]��,����i����,j=next[j]
        else
        {
            j=next[j];
        }
    }
    if (j==pp) return i-j;
    else return -1;
}
/******************************KMP**************************/



/*************************����KMPģ��****************************/
char T[1000];//��ƥ�䴮  
char P[100];//ģ�崮  

			//ʧ��ָ��,��ס����fҪ��P��һλ  
			//��ΪP��m-1����,����f��Ҫ�����m��ʧ��ָ��  
int f[101];

void find(char *T, char *P, int *next) //�ҵ�����ƥ���  
{
	int tt = strlen(T), pp = strlen(P);
	int j = 0;
	for (int i = 0; i < tt; i++)
	{
		while (j && T[i] != P[j]) j = next[j];
		if (T[i] == P[j]) j++;
		if (j == pp) printf("%d\n", i - pp + 1);//����j��pp�ˣ�Ҳ��f[pp]����ƥ��  
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
/*************************����KMPģ��****************************/




/*************************��չKMP****************************/
s[i]: �������Ե�i��λ��Ϊ��ʼ�ĺ�׺,(KMP:��s[i]=ģʽ������ �����)
next[i]:"ģʽ���ĺ�׺"��"ģʽ��P"�������ǰ׺
extend[i]:"s[i]"��"ģʽ��P"�������ǰ׺(��next[i]��)




��չKMP˼��: ����ģ�崮T���Ӵ�B�����ȷֱ�ΪlenT��lenB��Ҫ��������ʱ���ڣ�����ÿ��T[i]��0<=i<lenT)�����T[i..lenT-1]��B�������ǰ׺���ȣ���Ϊex[i]������˵��ex[i]Ϊ����T[i..i+z-1]==T[0..z-1]������zֵ����


����:
1.��һ���ַ�����������Ӵ�����ظ��Ӵ�
2.��'������ÿһ����׺' �� 'ģʽ��' �������ǰ׺
void getNext(char *P)
{
    int a=0;
    int pp=strlen(P);
    next[0]=pp;
    while(a<pp-1 && P[a]==P[a+1]) a++;
    next[1]=a;
    a=1;
    for(int k=2;k<pp;k++)
    {
        int p=a+next[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<pp && T[k+j]==T[j]) j++;
            next[k]=j;
            a=k;
        }
        else next[k]=L;
    }
}

void GetExtend(char *S,char *T)  
{  
    int a=0;
    getNext(T);
    int Slen=strlen(S);
    int Tlen=strlen(T);
    int MinLen=Slen<Tlen? Slen:Tlen;
    while(a<MinLen && S[a]==T[a]) a++;
    extend[0]=a;
    a=0;
    for(int k=1;k<Slen;k++) 
    {
        int p=a+extend[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<Slen&&j<Tlen&&S[k+j]==T[j]) j++;
            extend[k]=j;
            a=k;
        }
        else extend[k]=L;
    }
}
/*************************��չKMP****************************/



