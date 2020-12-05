#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        int n,inc[10005],avg=0,cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&inc[i]);
            avg+=inc[i];
        }
        avg/=n;
        for(int i=0;i<n;i++){
            if(inc[i]<=avg) cnt++;
        }
        printf("#%d %d\n",tc,cnt);
    }
}