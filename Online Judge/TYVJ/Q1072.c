# include <stdio.h>

int arrange(long long int a,long long int b)//������long long int,s��ֵ�ᱬ��
{
    int k;
    long long int s = 1,t=1,i,j;
    for(i = (a+b); i >= a+1; i--)
        s = s * i;
    for(i = b; i >= 1; i--)
        t = t * i;
    k = (int)(s / t);
    return k;
}
int main()
{
    int high,h,num = 0,i,j;
    scanf("%d",&high);
    h = high / 2;
    for(i = 0; i <= h; i++)
    {
        j = high - 2 * i;
        num = num + arrange(i,j);
    }
    printf("%d",num);
    return 0;
}

//���Ӽ򵥵ķ���������ʵ������һ���Ʋ���������
