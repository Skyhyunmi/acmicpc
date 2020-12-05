#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string.h>
using namespace std;

set<int> ss[100'005];

int main(){
    int n,s,d;
    scanf("%d %d %d",&n,&s,&d);
    for(int i=0;i<n-1;i++){
        int f,t;
        scanf("%d %d",&f,&t);
        ss[f].insert(t);
        ss[t].insert(f);
    }
    int cnt=0;
    while(d--)
        for(int i=1;i<=n;i++){
            if(ss[i].size() == 1) {
                if(*ss[i].begin() == s) continue;
                else {
                    ss[*ss[i].begin()].erase(i);
                    ss[i].clear();
                }

            }
        }
    for(int i=1;i<=n;i++){
        if(!ss[i].empty()) {
            // printf("%d ",i);
            cnt++;
        }
    }
    printf("%d\n",(cnt-1)*2?(cnt-1)*2:0);
}