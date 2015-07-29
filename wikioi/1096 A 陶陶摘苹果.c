# include <stdio.h>
# define H 30
/*
题目描述 Description
陶陶家的院子里有一棵苹果树，每到秋天树上就会结出10个苹果。苹果成熟的时候，陶陶就会跑去摘苹果。
陶陶有个30厘米高的板凳，当她不能直接用手摘到苹果的时候，就会踩到板凳上再试试。
现在已知10个苹果到地面的高度，以及陶陶把手伸直的时候能够达到的最大高度，请帮陶陶算一下她能够摘到
的苹果的数目。假设她碰到苹果，苹果就会掉下来。
*/

int main()
{
	int h[10];
	int high,i,t;
	for(i = 0; i < 10; i++)
		scanf("%d",&h[i]);
	scanf("%d",&high);
	t = 0;
	for(i = 0; i < 10; i++)
	{
		if(h[i] <= high + H)
			t++;
	}
	printf("%d\n",t);
	
	return 0;	
}

/*输入描述 Input Description
输入包括两行数据。第一行包含10个100到200之间（包括100和200）的整数（以厘米为单位）
分别表示10个苹果到地面的高度，两个相邻的整数之间用一个空格隔开。第二行只包括一个100到120之间
（包含100和120）的整数（以厘米为单位），表示陶陶把手伸直的时候能够达到的最大高度。
输出描述 Output Description
 
输出包括一行，这一行只包含一个整数，表示陶陶能够摘到的苹果的数目。

样例输入 Sample Input
100 200 150 140 129 134 167 198 200 111

110
样例输出 Sample Output
5
*/
