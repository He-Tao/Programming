# include <stdio.h>
# include <string.h>
/*
题目描述 Description   1060 搞笑世界杯
随着世界杯小组赛的结束,法国,阿根廷等世界强队都纷纷被淘汰,让人心痛不已. 于是有人组织了一场搞笑世界杯,将这些被淘汰的强队重新组织起来和
世界杯一同比赛.你和你的朋友欣然去购买球票.不过搞笑世界杯的球票出售方式也很特别,它们只准备了两种球票.A 类票------免费球票 B 类票------
双倍价钱球票.购买时由工作人员通过掷硬币决定,投到正面的买A类票, 反面的买B类票.并且由于是市场经济,主办方不可能倒贴钱,所以他们总是准备
了同样多的A类票和B类票.你和你的朋友十分幸运的排到了某场精彩比赛的最后两个位置.这时工作人员开始通过硬币售票.不过更为幸运的是当工作人员
到你们面前时他发现已无需再掷硬币了,因为剩下的这两张票全是免费票。
你和你的朋友在欣喜之余,想计算一下排在队尾的两个人同时拿到一种票的概率是多少(包括同时拿A 类票或B类票) 
假设工作人员准备了2n 张球票,其中n 张A类票,n 张B类票,并且排在队伍中的人每人必须且只能买一张球票(不管掷到的是该买A 还是该买B).
*/
double pA[2501][1251] = {{0.0}};             /*pA[i][j] 表示前 i 个人选了 j 张 A 票的概率*/

int main()     //注意是递推， 不是排列组合！！！！
{
	int n, i, j;
	scanf("%d", &n);
	n /= 2;
	
	pA[1][0] = 0.5, pA[1][1] = 0.5;      
	for(i = 2; i <= 2*n; i++)                     //扔硬币概率为 0.5
	{
		pA[i][0] = pA[i-1][0] * 0.5;
		for(j = 1; j < n; j++)
		{
			pA[i][j] = pA[i-1][j-1] * 0.5 + pA[i-1][j] * 0.5;
		}
		pA[i][n] = pA[i-1][n] + pA[i-1][j-1] * 0.5;
	}
	printf("%.4lf\n", 2.0 * pA[2*n - 2][n]);

	return 0;
}

/*
输入描述 Input Description
输入文件仅一行,包含球票数2n . 其中,0<n<=1250 ，n 为整数。
输出描述 Output Description
输出文件只包含一个数,为拿到同一种票的概率,精确到小数点后4 位。
样例输入 Sample Input
256
样例输出 Sample Output
0. 9500
数据范围及提示 Data Size & Hint
en
*/
