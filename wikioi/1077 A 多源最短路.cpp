#include <iostream>
#include <cstdio>
using namespace std;

#define read(x) {char ch;\
				 x = 0;\
				 while((ch = getchar()) > '9' || ch < '0');\
			     x = ch - '0';\
                 while((ch = getchar()) <= '9' && ch >= '0')\
					x = x * 10 + (ch - '0');\
				 }

/*
��Ŀ���� Description
��֪n����(n<=100)������n*n�ķ���a[i,j]��ʾ�ӵ�i���㵽��j�����ֱ�Ӿ��롣        
������Q��ѯ�ʣ�ÿ��ѯ��������������a��b��������a��b֮������·�̡�        
����a[i,j]=a[j,i];
�������� Input Description
 ��һ��һ��������n��������n��ÿ��n��������������a[i,i]=0,��һ��һ��Q��������Q�У�ÿ������������a��b��
*/
int main(int argc, char **argv)
{
	int n, map[101][101] = {{0}}, dist[101][101] = {{0}};
	read(n);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			read(map[i][j]);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			dist[i][j] = map[i][j];
	}

	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
				dist[i][j] = dist[i][j] < (dist[i][k] + dist[k][j]) 
					       ? dist[i][j] : (dist[i][k] + dist[k][j]);
		}
	}
	
	
	int q, u, v;
	read(q);
	for(int i = 1; i <= q; ++i)
	{
		read(u); read(v);
		printf("%d\n", dist[u][v]);
	}

	return 0;
}
/*
�������� Input Description
 ��һ��һ��������n��������n��ÿ��n��������������a[i,i]=0,��һ��һ��Q��������Q�У�ÿ������������a��b��
������� Output Description
һ��Q�У�ÿ��һ��������
�������� Sample Input
3
0 1 1
1 0 3
1 3 0
1
2 3
������� Sample Output
2
���ݷ�Χ����ʾ Data Size & Hint
n<=100��Q���ܷǳ���g[i][j]��>=0
��ʹ��flyod�㷨
ʹ��C/C++��ͬѧ��ע�⣺�����������ݽϴ�ʹ��cin��cout�ᵼ�³���ʱ����ʹ��scanf��printf��������������
*/
