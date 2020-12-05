#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

long long tab[100'005];
long long res[100'005];
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&tab[i]);
    }
    res[0] = tab[0];
    long long ret=-214700000;
    for(int i=0;i<n;i++){
        res[i] = max(tab[i],res[i-1] + tab[i]);
        ret = max(ret,res[i]);
    }
    printf("%lld\n",ret);
}