# include <stdio.h>

int main(int argc,char*argv[])
{
    int i,n,s=0,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        s += t;
    }
    printf("%d",s);

    return 0;
}
