# include <iostream>
# include <cstdio>
using namespace std;
/*
��Ŀ���� Description		1078 ��С������
ũ��Լ����ѡΪ��������򳤣�������һ����ѡ��ŵ���������Ͻ����������������ӵ����е�ũ������Ȼ������Ҫ��İ����� Լ���Ѿ���
����ũ��������һ�����ٵ�������·�������������·���������ũ����Ϊ��ʹ�������٣�����������̵Ĺ���ȥ�������е�ũ���� �㽫��
��һ�ݸ�ũ��֮�����ӷ��õ��б�������ҳ�����������ũ�������ù�����̵ķ����� ÿ����ũ����ľ��벻�ᳬ��100000
*/
int map[105][105], ans, n;

void InitMap(void)
{
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

void Prim(void)
{
	int v, u, i, j, t, minSpanTree[105], top = 1, isvisit[105] = {0};
	minSpanTree[top++] = 1, isvisit[1] = 1;
	for(t = 2; t <= n; ++t)
	{
		v = u = 0, map[v][u] = 0x7fffffff;
		for(i = 1; i < top; ++i)
		{
			for(j = 1; j <= n; ++j)
			{
				if(!isvisit[j] && map[minSpanTree[i]][j] < map[v][u])
				{
					v = minSpanTree[i], u = j;
				}
			}
		}
		isvisit[u] = 1;
		minSpanTree[top++] = u;
		ans += map[v][u];
	}
}

int main()				//prim �㷨��MST ����, Ҳ������ Kruskal �㷨
{
	InitMap();
	Prim();
	printf("%d", ans);

	return 0;
}

/*
�������� Input Description
��һ�У� ũ���ĸ�����N��3<=N<=100����
�ڶ���..��β: ���������а�����һ��N*N�ľ���,��ʾÿ��ũ��֮��ľ��롣�����ϣ�������N�У�ÿ����N���ÿո�ָ�������ɣ�ʵ����
������ÿ��������80���ַ����ڣ���ˣ�ĳЩ�л��������һЩ�С���Ȼ���Խ��߽�����0����Ϊ��·�ӵ�i��ũ����������ľ����ڱ���
��û�����塣
������� Output Description
ֻ��һ������������ӵ�ÿ��ũ���Ĺ��˵���С���Ⱥ͡�
�������� Sample Input
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
������� Sample Output
28
���ݷ�Χ����ʾ Data Size & Hint
*/
