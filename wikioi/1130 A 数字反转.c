# include <stdio.h>
# include <string.h>

/*
��Ŀ���� Description
����һ���������뽫��������λ�����ַ�ת�õ�һ������������ҲӦ���������ĳ�����
ʽ�������Ǹ�����ԭ��Ϊ�㣬����ת��õ������������λ���ֲ�ӦΪ��.
*/

int main()
{
	char ch[12];
	int len,i,j,k,t;
	scanf("%s",ch);
	len = strlen(ch);
	if(ch[0] == '-')
	{
		printf("-");
		i = len - 1;
		while(ch[i] == '0')
			i--;
		if(i == 0)
			printf("0");
		else
		{
			for(;i > 0; i--)
			printf("%c",ch[i]);
		}
	}
	else
	{
		i = len - 1;
		while(ch[i] == '0' && i>=0)
			i--;
		if(i == 0)
			printf("%c",ch[i]);
		else
		{
			for(;i >= 0; i--)
			printf("%c",ch[i]);
		}
	}
	
	return 0;
}

/*
�������� Input Description
���빲 1 �У�һ������N
������� Output Description
����� 1 �У�һ����������ʾ��ת���������
�������� Sample Input
-380
������� Sample Output
-83
���ݷ�Χ����ʾ Data Size & Hint
���ݷ�Χ
-1,000,000,000 �� N�� 1,000,000,000��
*/
