#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n;
int num[50],res[10];

void dfs(int cur, int cnt){
    if(cnt ==6){
        for(int i=0;i<5;i++){
            printf("%d ",res[i]);
        }
        printf("%d",res[5]);
        printf("\n");
    }
    else{
        for(int i = cur;i < n;i++){
            res[cnt] = num[i];
            dfs(i+1,cnt+1);
        }
    }
}

int main(){
    do{
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&num[i]);
        dfs(0,0);
        printf("\n");
    }while(n);
}