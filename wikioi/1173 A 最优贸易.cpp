#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 0x3fffff
using namespace std;
/*
题目描述 Description
【问题描述】
C 国有n 个大城市和m 条道路，每条道路连接这n 个城市中的某两个城市。任意两个
城市之间最多只有一条道路直接相连。这m 条道路中有一部分为单向通行的道路，一部分
为双向通行的道路，双向通行的道路在统计条数时也计为1 条。
C 国幅员辽阔，各地的资源分布情况各不相同，这就导致了同一种商品在不同城市的价
格不一定相同。但是，同一种商品在同一个城市的买入价和卖出价始终是相同的。
商人阿龙来到 C 国旅游。当他得知同一种商品在不同城市的价格可能会不同这一信息
之后，便决定在旅游的同时，利用商品在不同城市中的差价赚回一点旅费。设C 国n 个城
市的标号从1~ n，阿龙决定从1 号城市出发，并最终在n 号城市结束自己的旅行。在旅游的
过程中，任何城市可以重复经过多次，但不要求经过所有n 个城市。阿龙通过这样的贸易方
式赚取旅费：他会选择一个经过的城市买入他最喜欢的商品——水晶球，并在之后经过的另
一个城市卖出这个水晶球，用赚取的差价当做旅费。由于阿龙主要是来C 国旅游，他决定
这个贸易只进行最多一次，当然，在赚不到差价的情况下他就无需进行贸易。
假设 C 国有5 个大城市，城市的编号和道路连接情况如下图，单向箭头表示这条道路
为单向通行，双向箭头表示这条道路为双向通行。
假设 1~n 号城市的水晶球价格分别为4，3，5，6，1。
阿龙可以选择如下一条线路：1->2->3->5，并在2 号城市以3 的价格买入水晶球，在3
号城市以5 的价格卖出水晶球，赚取的旅费数为2。
阿龙也可以选择如下一条线路 1->4->5->4->5，并在第1 次到达5 号城市时以1 的价格
买入水晶球，在第2 次到达4 号城市时以6 的价格卖出水晶球，赚取的旅费数为5。
现在给出 n 个城市的水晶球价格，m 条道路的信息（每条道路所连接的两个城市的编号
以及该条道路的通行情况）。请你告诉阿龙，他最多能赚取多少旅费。
*/
vector <int> Map[100005];
vector <int> MapReverse[100005];
int price[100005];

void spfa(int n, int *dist, int *price)
{
	bool isVisit[n+1];
	queue <int> Q;
 	memset(isVisit, 0, sizeof(isVisit));
	isVisit[1] = true;
	Q.push(1);
	dist[1] = price[1];
	while(!Q.empty())
	{
		int tmp = Q.front();
		Q.pop();
		isVisit[tmp] = false;
		for(int i = 0; i < (int)Map[tmp].size(); ++i)
		{
			if(dist[Map[tmp][i]] > min(dist[tmp], price[Map[tmp][i]]))
			{
				dist[Map[tmp][i]] = min(dist[tmp], price[Map[tmp][i]]);
				if(!isVisit[Map[tmp][i]])
				{
					Q.push(Map[tmp][i]);
					isVisit[Map[tmp][i]] = true;
				}
			}
		}
	}
}
void spfaReverse(int n, int *distReverse, int *price)
{
	bool isVisit[n+1];
	queue <int> Q;
 	memset(isVisit, 0, sizeof(isVisit));
	isVisit[n] = true;
	Q.push(n);
	distReverse[n] = price[n];
	while(!Q.empty())
	{
		int tmp = Q.front();
		for(int i = 0; i < (int)MapReverse[tmp].size(); ++i)
		{
			if(distReverse[MapReverse[tmp][i]] < max(distReverse[tmp], price[MapReverse[tmp][i]]))
			{
				distReverse[MapReverse[tmp][i]] = max(distReverse[tmp], price[MapReverse[tmp][i]]);
				if(!isVisit[MapReverse[tmp][i]])
				{
					Q.push(MapReverse[tmp][i]);
 					isVisit[MapReverse[tmp][i]] = true;
				}
			}
		}
		Q.pop();
		isVisit[tmp] = false;
	}
}

int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", price+i);
	}
	int tmp1, tmp2, tmp3;
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		Map[tmp1].push_back(tmp2);
		if(tmp3 == 2)
			Map[tmp2].push_back(tmp1);
		MapReverse[tmp2].push_back(tmp1);
		if(tmp3 == 2)
			MapReverse[tmp1].push_back(tmp2);
	}

	int dist[n+1], distReverse[n+1];
	for(int i = 0; i <= n; ++i)
	{
		dist[i] = INF;
		distReverse[i] = 0;
	}
	
	spfa(n, dist, price);
	spfaReverse(n, distReverse, price);
	
	int max = distReverse[1] - dist[1];
	for(int i = 1; i <= n; ++i)
	{
		if(max < distReverse[i] - dist[i])
			max = distReverse[i] - dist[i];
	}
	if(max < 0)
		max = 0;
	printf("%d", max);

	return 0;
}

/*
输入描述 Input Description
第一行包含 2 个正整数n 和m，中间用一个空格隔开，分别表示城市的数目和道路的
数目。
第二行 n 个正整数，每两个整数之间用一个空格隔开，按标号顺序分别表示这n 个城
市的商品价格。
接下来 m 行，每行有3 个正整数，x，y，z，每两个整数之间用一个空格隔开。如果z=1，
表示这条道路是城市x 到城市y 之间的单向道路；如果z=2，表示这条道路为城市x 和城市
y 之间的双向道路。
输出描述 Output Description
包含1 个整数，表示最多能赚取的旅费。如果没有进行贸易，
则输出0。
样例输入 Sample Input
5 5
4 3 5 6 1
1 2 1
1 4 1
2 3 2
3 5 1
4 5 2
样例输出 Sample Output
5
数据范围及提示 Data Size & Hint
【数据范围】
输入数据保证 1 号城市可以到达n 号城市。
对于 10%的数据，1≤n≤6。
对于 30%的数据，1≤n≤100。
对于 50%的数据，不存在一条旅游路线，可以从一个城市出发，再回到这个城市。
对于 100%的数据，1≤n≤100000，1≤m≤500000，1≤x，y≤n，1≤z≤2，1≤各城市
水晶球价格≤100。
*/
