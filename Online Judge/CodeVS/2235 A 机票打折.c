# include <stdio.h>

int main()
{
    float barg,price;
    scanf("%f %f",&price,&barg);
    price = price * barg * 0.01;
    printf("%.0f0\n",price);    //��֪���һλΪ�㣬�ʿ���ֱ��������һλ�� 0

    return 0;
}
