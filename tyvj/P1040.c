/*
���� Description
����һ�����ʽ,���������������+,Ҫ��������ʽ������ֵ
*/

# include <stdio.h>
# include <string.h>
# define max(a,b) ((a)>=(b)?(a):(b))
 
void add(int x[],int y[],int m,int n)    //���
{
    int i,k,t;
    t = 0;
    for(i = 0;i <= max(m,n); i++)
    {
        k = (x[i] + y[i] + t);
        t = k / 10;
        x[i] = k % 10;
    }
}

int main()
{
    char s[1501];
	int d1[1500]={0},d2[1500]={0},d3[1500]={0};    //d3[]������ת������������鵹�ã�
    char op;
    int i,j,k,m,n;
    scanf("%s",s);
    j = 0;
    m = 0;
    n = 0;
    while(1)
    {
 		op = s[j];
        if(op == '\0')
        {
            for(i = 0; i < n; i++)   //����
                d2[i] = d3[n-1-i];
            add(d1,d2,m,n);
            break;
        }
        else
        {
            if(op == '+')
            {
                for(i = 0; i < n; i++)    //����
                    d2[i] = d3[n-1-i];
                add(d1,d2,m,n);
                m = max(m,n);
                for(i = 0; i <= n; i++)
                	d2[i] = 0;
                n = 0;
            }
            else
            {
                d3[n] = op - '0';
                n ++;
            }
        }
   		j++;
    }
    for(k = max(m,n)+1; k>=0; k--)   //Ѱ�ҷ������λ
        if(d1[k] != 0)
            break;
    for(i = k; i >= 0; i--)
        printf("%d",d1[i]);

    return 0;
}

/*
�����ʽ InputFormat
��һ�У���Ϊ���ʽ
�����ʽ OutputFormat
��һ�У���Ϊ���ʽ����Ľ��
�������� SampleInput [��������]
1+1
������� SampleOutput [��������]
2
���ݷ�Χ��ע�� Hint
���ʽ�ܳ���<=1500
*/
