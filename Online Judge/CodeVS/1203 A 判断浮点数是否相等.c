# include <stdio.h>

double abs(double a)    //abs���ú�д����Ϊ   # define abs (a>=0?a:(-a))    ���������Ų���©��
{
    if(a >= 0)
        return a;
    else
        return (-a);
}

int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(abs(a-b) < 0.00000001)   //����жϲ���С�������ж������Ƿ����
        printf("yes\n");          //�����þ��Ծ���ֵ����
    else
        printf("no\n");

    return 0;
}
