#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main(){
    int n,cnt=0;
    scanf("%d",&n);
    do{
        if(!n) break;
        int trig=0,tn=n,diff=-100;
        queue<int> q;
        while(tn){
            q.push(tn%10);
            tn/=10;
        }
        int a = q.front();
        q.pop();
        while(!q.empty()){
            int b = q.front();
            q.pop();
            if(diff == -100) {
                diff=a-b;
                a=b;
                continue;
            }
            if(diff != a-b) {
                trig=1;
                break;
            }
            a=b;
        }
        if(!trig) cnt++;
    }while(n--);

    printf("%d\n",cnt);
}