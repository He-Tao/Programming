# include <stdio.h>
# include <string.h>

/*
���� Background
NOIP 2012 ����� ��1
���� Description
16 ���ͷ����⽻�� Blaise de Vigen��re �����һ�ֶ����������㷨����Vigen��re ���롣Vigen��re ����ļ��ܽ����㷨
������,�������ѶȱȽϸ�,���������ϱ�ս����Ϊ�Ͼ����㷺ʹ�á�
������ѧ��,���ǳ���Ҫ���ܵ���ϢΪ����,�� M ��ʾ;�Ƽ��ܺ����ϢΪ����,��C ��ʾ;
����Կ��һ�ֲ���,�ǽ�����ת��Ϊ���Ļ�����ת��Ϊ���ĵ��㷨�����������,��Ϊ k�� �� Vigen��re ������,��Կ k ��
һ����ĸ��, k1k2...kn��
������ M=m1m2...mn ʱ,�õ������� C=c1c2...cn,���� ci=mi?ki,����?�Ĺ������±���ʾ:
[ͼƬ]
Vigen��re �����ڲ���ʱ��Ҫע��:
1. ?������Բ����������ĸ�Ĵ�Сд,��������ĸ������ M �еĴ�Сд��ʽ;
2. ������ M �ĳ��ȴ�����Կ k �ĳ���ʱ,����Կ k �ظ�ʹ�á�
����,���� M=Helloworld,��Կ k=abc ʱ,���� C=Hfnlpyosnd��
���� H e l l o w o r l d
��Կ a b c a b c a b c a
���� H f n l p y o s n d
*/

char trs(char a)           //��Сдת��Ϊ��д��ĸ 
{
	return a>='a'?a:(a + 'a' - 'A');
}
int main()
{
	char k[1500],c[1500],w[1500];
	int i,j,len1,len2;
	scanf("%s",k);
	scanf("%s",c);
	len1 = strlen(k);
	len2 = strlen(c);
	j = 0;
	for(i = len1; i < len2; i++)
	{
		k[i] = k[j];
		j ++;
		if(j == len1)
			j = 0;
	}
	for(i = 0; i < len2; i++)
	{
		if(trs(k[i]) > trs(c[i]))
			w[i] = 'z' - trs(k[i]) + trs(c[i]) - 'a' + 'a' + 1;
		else
			w[i] = trs(c[i]) - trs(k[i]) + 'a';
	}
	for(i = 0; i < len2; i++)
	{
		if(c[i] >= 'a')
			printf("%c",w[i]);
		else
			printf("%c",w[i]-'a'+'A');
	}
	
	return 0;
}

/*
�����ʽ InputFormat
���빲 2 �С�
��һ��Ϊһ���ַ���,��ʾ��Կ k,���Ȳ����� 100,���н�������Сд��ĸ���ڶ���Ϊһ���ַ���,��ʾ�����ܺ������,����
������ 1000,���н�������Сд��ĸ��
�����ʽ OutputFormat
����� 1 ��,һ���ַ���,��ʾ������Կ����������Ӧ�����ġ�
�������� SampleInput [��������]
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm
������� SampleOutput [��������]
Wherethereisawillthereisaway
���ݷ�Χ��ע�� Hint
���� 100%������,�������Կ�ĳ��Ȳ����� 100,��������ĵĳ��Ȳ����� 1000,�Ҷ�������Ӣ����ĸ��
��Դ Source
NOIP 2012
*/
