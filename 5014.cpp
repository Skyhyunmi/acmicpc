#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

queue<int> q;
int lift[1'000'006];
int f,s,g,u,d;
bool flag=0;


int main(){
    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
    q.push(s);
    lift[s] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(temp == g) {
            flag=true;
            break;
        }
        if(temp + u <= f && !lift[temp + u]){
            lift[temp + u] = lift[temp] +1;
            q.push(temp + u);
        }
        if(temp - d > 0 && !lift[temp - d]){
            lift[temp - d] = lift[temp] +1;
            q.push(temp - d);
        }
    }
    if(flag) printf("%d\n",lift[g]-1);
    else printf("use the stairs\n");
}