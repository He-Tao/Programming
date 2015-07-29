# include <stdio.h>
# include <string.h>
/*
��Ŀ���� Description
����һ���������������������Ⱥ͸߶ȡ�
*/
struct tree
{
	int num;
	struct tree *pl, *pr;
} s[17];

int high[17], wide[17];

int main()
{
	int n, i;
	int temp1, temp2;
	int max_high = 0, max_wide = 0;
	scanf("%d", &n);
	memset (s, 0, sizeof(struct tree) * 17);
	high[1] = 1;
	s[1].num = 1;
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		s[i].pl = &s[temp1], s[i].pr = &s[temp2];
		s[i].pl -> num = temp1, s[i].pr -> num = temp2;
		high[s[i].pl -> num] = high[i] + 1;
		high[s[i].pr -> num] = high[i] + 1;
	}
	/*
	�������һ��д��Ϊ��
	for(i = 1; i <= n; i++)
	{
		s[i].num = i;
		scanf("%d %d", &temp1, &temp2);
		high[temp1] = high[i] + 1;
		high[temp2] = high[i] + 1;
	}
	*/
	for(i = 1; i <= n; i++)
	{
		if(max_high < high[i])
		{
			max_high = high[i];
		}
		wide[high[i]] ++;
	}
	for(i = 1; i <= 16; i++)
	{
		if(max_wide < wide[i])
		{
			max_wide = wide[i];
		}
	}
	printf("%d %d\n", max_wide, max_high);

	return 0;
}

/*
�������� Input Description
��һ��һ������n��
����n��ÿ���������������ڵ�i�е���������������Ϊi�Ľڵ������ӵ��������Ҷ��ӵı�š����û��ĳ������Ϊ�գ���Ϊ0��
������� Output Description
�����һ�У����������������Ⱥ͸߶ȣ���һ���ո������
�������� Sample Input
5
2 3
4 5
0 0
0 0
0 0
������� Sample Output
2 3
���ݷ�Χ����ʾ Data Size & Hint
n<16
Ĭ�ϵ�һ���Ǹ��ڵ�
������Ĵ���Ϊ���
2-N+1��ָ��������ڵ�����Ӻ��Һ���
ע�⣺�ڶ����м������ݣ�
1
0 0
�������Ǳ���Ͷ��ȡ���ˣ���������ʵʵ������
*/
