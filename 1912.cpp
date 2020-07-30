#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
long long tab[100'005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        if(i == 0) tab[i] = t;
        else tab[i] = tab[i-1] + t;
    }
}