//�߾��ȳ˷�
#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,s,t,m,n,op;
    char a[20001],b[20001];
    int c[20001],d[20001],f[40001];
    scanf("%s %s",&a,&b);
    m=strlen(a);
    n=strlen(b);
    for(i=0;i<m;i++)
        c[i]=a[m-1-i]-48;
    for(i=0;i<n;i++)
        d[i]=b[n-1-i]-48;

    for(i=0;i<m+n;i++)
        f[i]=0;             //���ã���f[i]����ֵ��Ϊ 0��
    /*Ҳ�ɵ���<string.h>�е�memset������дΪ��
    memset(f,0,sizeof(f));
    25 25*/
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            f[i+j]=f[i+j]+d[i]*c[j];    //����ʽ�˷����ҵ��Ĺ���
    for(i=0;i<m+n;i++)            //���ã����������ĵĻ���λ��С�ڵ�������������λ��֮��
        if(f[i]>9)
        {
            f[i+1]=f[i+1]+f[i]/10;
            f[i]=f[i]%10;
        }
    /*��������Ĺ���Ҳ��дΪ����ʱ�临�Ӷȴ�
    for(i=0;i<n;i++)
    {
        k=i;
        t=0;
        for(j=0;j<m;j++)
        {
            op=c[j]*d[i]+t+f[k];
            f[k]=op%10;
            t=op/10;
            k++;
        }
        f[k]=t;
    }
    */
    for(j=m+n-1;j>=0;j--)
        if(f[j]!=0)
        break;
    for(i=j;i>=0;i--)
        printf("%d",f[i]);
    return 0;
}
