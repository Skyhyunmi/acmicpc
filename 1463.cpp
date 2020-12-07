#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int t[1'000'006],n;

void prnt(){
    for(int i=1;i<=n;i++) printf("%d ",t[i]);
    printf("\n");
}

int main(){
    scanf("%d",&n);
    for(int i=n-1;i>0;i--) t[i]=100000000;
    t[n]=0;
    for(int i=n;i>0;i--){
        if(i%3==0) t[i/3]=min(t[i/3],t[i]+1);
        if(i%2==0) t[i/2]=min(t[i/2],t[i]+1);
        t[i-1]=min(t[i-1],t[i]+1);
    }
    printf("%d\n",t[1]);
}