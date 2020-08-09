#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct Res {
    int num,check;
};

int n, nth;
int sy[25],cnt=0;
void dfs1(int cur,struct Res res[]){
    if(cur == 5) {
        printf("1");
        if (cnt==nth){
            printf("1");
            for(int i=1;i<=4;i++){
                printf("%d ",res[i].num);
            }
            printf("1");
            printf("\n");
        }
        else cnt++;
    }else
    for(int i=1;i<=n;i++){
        
        if(!res[cur].check){
            res[cur].num = i;
            res[cur].check = 1;
            printf("1");
            dfs1(cur+1,res);
            res[cur].check = 0;
            res[cur].num = 0;
        }
    }
}


int main(){
    
    scanf("%d",&n);
    int t;
    scanf("%d",&t);
    if(t==1){
        scanf("%d",&nth);
        struct Res res[n+1]={{0,0},};
        dfs1(1,res);
    }
    else{
        for(int i=0;i<n;i++) scanf("%d",&sy[i]);
        // dfs2();
    }
}