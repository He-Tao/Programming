# include <stdio.h>
# include <string.h>
# include <math.h>
/*
��Ŀ���� Description
��С��Ĵʻ�����С������ÿ����Ӣ��ѡ�����ʱ�򶼺�ͷ�ۡ��������ҵ���һ�ַ�����������֤����
�����ַ���ȥѡ��ѡ���ʱ��ѡ�Եļ��ʷǳ���
���ַ����ľ����������£�����maxn�ǵ����г��ִ���������ĸ�ĳ��ִ�����minn�ǵ����г��ִ������ٵ���ĸ�ĳ��ִ�����
���maxn-minn��һ����������ô��С�����Ϊ���Ǹ�Lucky Word�������ĵ��ʺܿ��ܾ�����ȷ�Ĵ𰸡�
*/
int ispri(int a)    //�ж����� 
{
	int i,k;
	k = sqrt(a);
	if(a == 1 || a == 0)
		return 0;
	for(i = 2;i <= k; i++)
	{
		if(a%i == 0)
		break;
	}
	if(i > k)
		return 1;
	else
		return 0;
}

int main()
{
	int len,max,min,i,j;
	char s[101];
	int t[26]={0};
	scanf("%s",s);
	len = strlen(s);
	for(i = 0; i < len; i++)
		t[s[i]-'a'] ++;
	for(j = 0; j < 26; j++)
		if(t[j] != 0)
		break;
	max = t[j];
	min = t[j];
	for(i = j; i < 26; i++)
	{
		if(t[i] != 0)
		{
			if(t[i] > max)
				max = t[i];
			if(t[i] < min)
				min = t[i];
		}
	}
	if(ispri(max-min) == 1)
		printf("Lucky Word\n%d",max-min);
	else
		printf("No Answer\n0");
		
	return 0;
}
/*
�������� Input Description
�����ļ�word.inֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100��
������� Output Description
����ļ�word.out�����У���һ����һ���ַ�������������ĵĵ�����Lucky Word����ô�����Lucky Word����
���������No Answer����
�ڶ�����һ��������������뵥����Lucky Word�����maxn-minn��ֵ���������0��
�������� Sample Input
����һ
error
������
olympic
 
������� Sample Output
����һ
Lucky Word
2
������
No Answer
0
*/
