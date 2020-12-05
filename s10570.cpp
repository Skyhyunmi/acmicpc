#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int c[10]={1,4,9,121,484};
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int f,t,cnt=0;
        scanf("%d %d",&f,&t);
        for(int j=0;j<5;j++){
            if(f<=c[j]&& c[j]<=t) cnt++;
        }
        printf("#%d %d\n",i,cnt);
    }
}