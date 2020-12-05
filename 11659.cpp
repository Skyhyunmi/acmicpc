#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int v[400005];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        int t; scanf("%d",&t);
        v.push_back(t);
    }
    init();
    while(m--){
        int i,j;
        scanf("%d %d",&i,&j);
    }
}