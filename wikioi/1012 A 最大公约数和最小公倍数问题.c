# include <stdio.h>

/*
��Ŀ���� Description
�������������x0,y0(2<=x0<100000,2<=y0<=1000000),�����������������P,Q�ĸ���
����:  1.P,Q��������
2.Ҫ��P,Q��x0Ϊ���Լ��,��y0Ϊ��С������.
����:�������������п��ܵ������������ĸ���.
*/

int gcd(int a,int b)
{
	int temp;
	if(a<b)
	{
		temp = a; a = b; b = temp;	
	}
	if(a%b == 0)
		return b;
	else
		return gcd(a%b,b);
}
int mlc(int a,int b)
{
	return a * b / gcd(a,b);
}
int main()
{
	int x,y,t1,t2,temp,s;
	scanf("%d %d",&x,&y);
	temp = y / x;
	s = 0;
	for(t1 = 1; t1 <= temp; t1++)
	{
		for(t2 = 1; t2 <= temp; t2++)
		{
			if((mlc(t1*x,t2*x) == y) &&(gcd(t1*x,t2*x)) == x)
				s ++;
		}
	}
	printf("%d",s);
	
	return 0;
}
/*
�������� Input Description
����������x0,y0
������� Output Description
�������������п��ܵ������������ĸ���
�������� Sample Input
3 60
������� Sample Output
4
*/
