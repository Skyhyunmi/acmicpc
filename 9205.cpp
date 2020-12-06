#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
//1 -> 시작점
//2 -> 편의점
//3 -> 도착점
int n;
bool print=false;

int dist(pair<int,int> f,pair<int,int> t){
    return abs(t.first - f.first) + abs(t.second - f.second);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        vector<pair<int,int>> con;
        queue<pair<int,int>> q;
        scanf("%d",&n);
        vector<bool> visit(n+2,false);
        for(int i=0;i<n+2;i++){
            int f,t;
            scanf("%d %d",&f,&t);
            con.push_back({f,t});
        }
        visit[0]=true;
        q.push({con[0].first,con[0].second});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=1;i<n+2;i++){
                if(!visit[i] && dist({x,y},con[i])<=1000){
                    visit[i] = true;
                    q.push(con[i]);
                }
            }
        }
        if(visit[n+1]) printf("happy\n");
        else printf("sad\n");
    }
}