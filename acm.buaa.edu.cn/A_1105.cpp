#include <cstdio>using namespace std;int main(int argc, char **argv) {    freopen("data.in", "r", stdin);     int cnt = 0;    char c;    while(~(scanf("%c", &c))) {        if(c == '"') {            if(cnt) {                printf("”");            }            else {                printf("“");            }            cnt = (cnt+1)%2;        }        else {            printf("%c", c);        }    }    return 0;}