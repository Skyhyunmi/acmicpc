#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int tab[10003];
int main(){
    int n;
    scanf("%d",&n);
    tab[0]=1;
    tab[1]=1;
    for(int i=2;i<=n;i++){
        tab[i] = (tab[i-1]+tab[i-2])%10007;
    }
    printf("%d\n",tab[n]);
}