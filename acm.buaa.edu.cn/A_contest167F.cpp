#include <cstdio>#include <cstring>#include <cstdlib>#include <iostream>using namespace std;int array[2000010] = {0};int main(int argc, char **argv) {    int n, m, t;    while(~scanf("%d %d", &n, &m)) {        memset(array, 0, sizeof(array));        for(int i = 0; i < n; ++i) {            scanf("%d", &t);            if(array[t] == 0) {                array[t] = i+1;            }        }        for(int i = 0; i < m; ++i) {            scanf("%d", &t);            if(array[t] == 0) {                printf("error\n");            }            else {                printf("%d\n", array[t]);            }        }    }    return 0;}