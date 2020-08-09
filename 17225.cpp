#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
queue<int> q1,q2;
vector<char> v[86500];
bool cant[86500];
int sangmin,jisu,n;
int cnt=1,last=-1;

bool comp(char a, char b){
    return a<b;
}

int main(){
    scanf("%d %d %d",&sangmin,&jisu,&n);
    for(int i=0;i<n;i++){
        int t,m;
        char c;
        scanf("%d %c %d",&t, &c,&m);
        for(int j=0;j<m;j++){
            if(c == 'B'){
                if(!cant[t+sangmin*j]){
                    v[t+sangmin*j].push_back('B');
                    if(sangmin)
                        for(int k=t+sangmin*j;k<t+sangmin*(1+j);k++) cant[k]=true;
                    last = max(last,t+sangmin*j);
                } else{
                    v[t+sangmin*(j+m)].push_back('B');
                    if(sangmin)
                        for(int k=t+sangmin*j;k<t+sangmin*(1+j);k++) cant[k]=true;
                    last = max(last,t+sangmin*j);
                }
            }
            else {
                v[t+jisu*j].push_back('R');
                if(jisu)
                    for(int k=t+jisu*j;k<t+jisu*(1+j);k++) cant[k]=true;
                last = max(last,t+jisu*j);
            }
        }
    }
    for(int j=0;j<=last;j++){
        sort(v[j].begin(),v[j].end(),comp);
        for(int k=0;k<v[j].size();k++){
            if(v[j][k] == 'B') q1.push(cnt++);
            else if(v[j][k] == 'R') q2.push(cnt++);
        }
    }
    printf("%d\n",q1.size());
    while(!q1.empty()){
        printf("%d ",q1.front()); q1.pop();
    }
    printf("\n%d\n",q2.size());
    while(!q2.empty()){
        printf("%d ",q2.front()); q2.pop();
    }
}