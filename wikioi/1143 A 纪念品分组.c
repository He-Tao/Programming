# include <stdio.h>
# include <stdlib.h>

/*
��Ŀ���� Description
Ԫ���쵽�ˣ�Уѧ���������ָ����������ļ���Ʒ���Ź�����Ϊʹ�òμ�����ͬѧ����õļ���Ʒ��ֵ��Ծ��⣬
��Ҫ�ѹ����ļ���Ʒ���ݼ۸���з��飬��ÿ�����ֻ�ܰ�����������Ʒ������ÿ�����Ʒ�ļ۸�֮�Ͳ��ܳ���һ��������������
Ϊ�˱�֤�ھ����̵�ʱ���ڷ������м���Ʒ������ϣ���������Ŀ���١����������дһ�������ҳ����з��鷽���з�����
���ٵ�һ�֣�������ٵķ�����Ŀ��
*/

int comp(const void *a,const void *b)
{
	return *(int *) a - *(int *) b;     //��С�������� 
}
int main()
{
	int n,max,i,j,k,time;
	scanf("%d %d",&max,&n);
	int prize[n],flag[n],mark;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&prize[i]);
		flag[i] = 0;
	}
	qsort(prize,n,sizeof(int),comp);
	time = 0;
	for(i = n-1; i >= 0; i--)
	{
		if(flag[i] == 0)
		{
			mark = 0;
			if(prize[i] < max)
			{
				for(j = i-1; j >= 0; j--)
				{
					if(flag[j] == 0 && (prize[i] + prize[j] <= max))
					{
						flag[j] = 1;
						mark = 1;
						time ++;
						break;
					}
				}
			}
			if(mark == 0)
				time ++;
		}
	}
	printf("%d\n",time);
	
	return 0;
}

/*
�������� Input Description
����n+2�У�
��1�а���һ������w��Ϊÿ�����Ʒ�۸�֮�͵����ޡ�
��2��Ϊһ������n����ʾ�����ļ���Ʒ���ܼ�����
��3~n+2��ÿ�а���һ��������pi (5 <= pi <= w)����ʾ����Ӧ����Ʒ�ļ۸�
������� Output Description
��һ�У�����һ�������������ٵķ�����Ŀ��
�������� Sample Input
100
9
90
20
20
30
50
60
70
80
90
������� Sample Output
6
���ݷ�Χ����ʾ Data Size & Hint
50%���������㣺1 <= n <= 15
100%���������㣺1 <= n <= 30000, 80 <= w <= 200
*/
