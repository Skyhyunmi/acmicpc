#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
priority_queue<pair<int,int>> pq;
/*
1 <-> N
Greedy한 한 정점에서 다른 모든 정점의 최단 거리를 구하는 알고리즘.
음수 간선이 있으면 동작하지 않는다. -> 다익스트라 자체가 양수일 때 만 정상작동 하도록 고안되어있기 때문.
pq를 사용하면 더욱 빠른 알고리즘으로 만들 수 있다. (다익스트라의 그리디는 weight가 최소인 정점에서 갱신을 하기 때문.)
한 정점의 방문을 체크한다. 그 정점에서 다음 정점을 업데이트한다. 그리고 pq에 업데이트된 정점을 pq에 넣는다.
다음 Iteration-> 만약 이미 방문했던 정점이면 넘어간다.(음수인 경우 작동하지 않는 이유) 그리고 나머지는 위와 같다.
이 Iteration을 pq에 더 이상 아무 값도 없을 때 까지(모든 정점을 방문한 경우?) 반복한다.
*/
int main(){
    int V,E,K;
    scanf("%d %d %d",&V,&E,&K);

    vector<pair<int,int>> v[V+1];
    vector<int> res(V+1,10000000);
    vector<bool> check(V+1,false);
    for(int i=0;i<E;i++){
        int f,t,w;
        scanf("%d %d %d",&f,&t,&w);
        v[f].push_back({t,w});
    }
    res[K]=0;
    pq.push({0,K}); //순서가 중요함. first를 기준으로 pq가 작동하는듯
    while(!pq.empty()){
        int from = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if(check[from]) continue;
        check[from]=true;
        for(auto & to_idx : v[from]){
            int to = to_idx.first;
            int cur_dist = to_idx.second;
            if(res[to] > weight + cur_dist) {
                res[to] = weight + cur_dist;
                pq.push({-res[to],to});
            }
        }
    }

    for(int i=1;i<=V;i++){
        if(res[i]>=10000000) printf("%s\n","INF");
        else printf("%d\n",res[i]);
    }
}