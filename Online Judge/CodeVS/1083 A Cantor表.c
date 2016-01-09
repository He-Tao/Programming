# include <stdio.h>
# include <math.h>

/*
��Ŀ���� Description
�ִ���ѧ������֤��֮һ��Georg Cantor֤�����������ǿ�ö�ٵġ�������������һ�ű���֤����һ����ģ� 
1/1 1/2 1/3 1/4 1/5 �� 
2/1 2/2 2/3 2/4 �� 
3/1 3/2 3/3 �� 
4/1 4/2 �� 
5/1 �� �� 
������Z���θ��ϱ��ÿһ���š�
��һ����1/1��Ȼ����1/2��2/1��3/1��2/2����
*/
int main(int argc,char *argv[])
{
	int n,k,t;
	scanf("%d",&n);
	for(k = 1;; k++)
	{
		if(k * (k + 1) >= 2 * n)      //ע��ÿһб�ŷ��ӷ�ĸ֮�����
			break;
	}
	t = n - k * (k - 1) / 2;
	if(k % 2 == 1)
	{
		printf("%d/%d\n", k+1-t, t);
	}
	else
	{
		printf("%d/%d\n", t, k+1-t);
	}
	
	return 0;
}

/*
�������� Input Description
����N��1��N��10000000��
������� Output Description
���еĵ�N��
�������� Sample Input
7
������� Sample Output
1/4
*/
