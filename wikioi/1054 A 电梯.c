# include <stdio.h>

/*��Ŀ���� Description
һ���򵥵���ѧģ����!
��һ������,������������:
����һ����Ҫ6����,�½�һ����Ҫ4����,���Ҫ����ͣ��,����ͣ5����.
���ڸ�������Ҫ��˳�򵽴�Ȼ��ͣ����N��¥��,������Ҫ��ʱ��.
���ݿ�ʼ��0��,¥�ݹ���100��.
*/
int time(int a,int b)    //ÿ������ʱ 
{
	int t;
	if(a < b)
		t = (b - a) * 6 + 5;
	if(a > b)
		t = (a - b) * 4 + 5;
	return t;
}

int main()
{
	int i,n,f[100],t;
	scanf("%d",&n);
	f[0] = 0;
	for(i = 1; i <= n; i++)
		scanf("%d",&f[i]);
	t = 0;
	for(i = 0; i < n; i++)
		t += time(f[i],f[i+1]);
	printf("%d",t);
	
	return 0;
}
/*
����(elevator.in):��һ��ΪN(N<=50),��������N������N��ͣ����¥��.
���(elevator.out):ֻ��һ��,Ϊ����Ҫ��ʱ��.
�������� Input Description
����(elevator.in):��һ��ΪN(N<=50),��������N������N��ͣ����¥��.
������� Output Description
���(elevator.out):ֻ��һ��,Ϊ����Ҫ��ʱ��.
�������� Sample Input
��������1:
1
2
��������2:
3
2
3
1
������� Sample Output
�������1:
17
�������2:
41
*/
