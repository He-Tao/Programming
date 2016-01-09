# include <stdio.h>
# include <string.h>

/*
��Ŀ���� Description
saffahʮ�ְ���ͬѧ�Ǵ�ֽ���������ݾ��ɴ�д��ĸ��ɣ��������о����漰һЩ���ɸ��˵����ܣ�
����saffah������һ�ּ򵥵ļ����㷨�����ڶ���ͬһ�����ģ�������Ӧ��������Ωһ�ģ���saffah���ǳ����ּ��ܷ���Ϊ��
��̬���롱��static password�����stpass����
 
���ּ����㷨�ĺ�����һ������ĸ����A��..��Z�����䱾���һһӳ��f�����磬���ĵġ�ABCDEFGHIJKLMNOPQRSTUVWXYZ��
��Ӧ���ĵġ�QWERTYUIOPASDFGHJKLZXCVBNM������һ�ֺϷ���ӳ�䡣����֮��һ�����Ĳ����ܶ�Ӧ������ģ�һ������Ҳ��
�����ж��������֮��Ӧ��
 
��Ϊһ��������saffah���ˣ������ҽػ���һ��saffah����ĳ���˵�ֽ��������һ�������ģ���һ�������Ӧ�����ġ�����ͼ
����������Ӧ���򣬼����ĵġ�ABCDEFGHIJKLMNOPQRSTUVWXYZ���ֱ��Ӧ��ʲô���ġ�
 
ע�⣬ֽ���е����ݿ���������ì�ܵģ����磬��������ǡ�AAC���������ǡ�ACC������ô���ǲ��Ϸ��ģ���Ϊ����A��Ӧ��
��������A��C������CҲ��Ӧ����������A��C���������û������ì�ܵ�������֣����Ǿͼٶ�ֽ���е��������ݶ�����ȷ�ġ�
*/

int main()
{
	int i,len,t,flag,mark;
	char s1[100],s2[100];
	int haxi1[26], haxi2[26];
	for(i = 0; i < 26; i++)
	{
		haxi1[i] = -1;
		haxi2[i] = -1;
	}
	gets(s1);
	gets(s2);
	len = strlen(s1);
	for(i = 0; i < len; i++)
	{
		if(haxi1[s1[i]-'A'] == -1)
		{
			haxi1[s1[i]-'A'] = s2[i] - 'A';
		}
		else
		{
			if((s2[i] - 'A') != haxi1[s1[i]-'A'])
			{
				printf("'\n");
				return 0;
			}
		}
		if(haxi2[s2[i]-'A'] == -1)
		{
			haxi2[s2[i]-'A'] = s1[i] - 'A';
		}
		else
		{
			if((s1[i] - 'A') != haxi2[s2[i]-'A'])
			{
				printf("'\n");
				return 0;
			}
		}
	}
	t = 0;
	for(i = 0; i < 26; i++)
	{
		if(haxi1[i] == -1)
		{
			t ++;
		}
	}
	if(t >= 2)
	{
		printf("No_Solution\n");
		return 0;
	}
	else if(t == 1)
	{
		for(i = 0; i < 26; i++)
		{
			if(haxi1[i] == -1)
			{
				flag = i;
				break;
			}
		}
		for(i = 0; i < 26; i++)
		{
			if(haxi2[i] == -1)
			{
				mark = i;
				break;
			}
		}
		haxi1[flag] = mark;
	}
	for(i = 0; i < 26; i++)
		printf("%c", haxi1[i] + 'A');
	printf("\n");
	
	return 0;
}

/*
�������� Input Description
�����ļ������У�Ϊ�������Ⱦ�ΪN���ַ���S1��S2�����н�������д��ĸ��
������� Output Description
����ļ�ֻ��һ�У�Ϊһ���ַ�����
���ֽ���г���������ì�ܵ�������ֻ���һ�������ţ�'����
���û�г�������ì�ܵ����󣬵������������㣬�޷�ȷ������Ӧ��������������ַ�������No_Solution�����������ţ���
������������ġ�ABCDEFGHIJKLMNOPQRSTUVWXYZ������Ӧ�����ġ�
�������� Sample Input
Input1:
AAC
ACC
Input2:
ABCDE
FGHIJ
Input3:
THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
ZITJXOEAWKGVFYGBPXDHLGCTKZITSQMNRGU
������� Sample Output
Output1:
'
Output2:
No_Solution
Output3:
QWERTYUIOPASDFGHJKLZXCVBNM
���ݷ�Χ����ʾ Data Size & Hint
����100%�����ݣ�1��N��63��
����60%�����ݣ�S1�����ٳ�����26����ĸ��һ�Ρ�
*/
/*
���ݵ㣺
THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
ZITJXOEAWKGVFYGBPXDHLGCTKZITSQMNRGU

BCDEFGHIJKLMNOPQRSTUVWXYZ
CDEFGHIJKLMNOPQRSTUVWXYZZ

QWERTYUIOPASDFGHJKLZXCVBN
BCDEFGHIJKLMNOPQRSTUVWXYZ

Q
Q

RANGWOQINGHEYIKANA
FZYBSLAKYBNDHKPZYZ

ABCDEFFFFFGHIJKLMNOPQRSTUVWXYZ
QWERTYYYYYUIOPASDFGHJKLZXCVBMN

QQQQWERTYUIOPASDFGHJKLZXCVBNM
ZZZZXCVBNMASDFGHJKLQQWERTYUIO

QWEWEWEWERASDFZXCVTYUIGHJKBNMOPL
POIOIOIOIULKJHMNBVYTREGFDSCXZWQA

ABCDEFGHIJKLMNOPQRSTUVWXY
QWERTYUIOPASDFGHJKLZXCVNB

QWERTYUIOPASDFGHJKLZXCVBN
BACDEFGHIJKLMNOPQRSTUVWXY
*/
