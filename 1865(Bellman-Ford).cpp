#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
/*
1 <-> N
벨만-포드 알고리즘은 한 정점에서 다른 모든 정점의 최단 거리를 구하는 알고리즘.
음수일 경우에도 동작 가능 -> 음수 사이클을 검출할 수 있다는 뜻
Iteration은 N-1번 한다.
각 이터레이션마다 시작에서 현재 정점까지의 최단 거리와 현재 정점에서 다음 정점까지의 최단 거리를 계속 업데이트함.
seudo code -> dist[next] = min(dist[next],dist[cur] + weight[cur][next])
(플로이드 워셜 처럼 from to를 전부 돌아요~)
예를 들어 간선이 1->2 1->3 1->5 2->3 2->5 3->2 4->1 5->2 이렇게 있으면 한번 돌면 1 Iteration임.
이걸 N-1번 반복한다. 그리고 마지막으로 N번째 Iteration에서 만약 값의 갱신이 일어나면 음수 간선이 있음을 알 수 있다.
왜냐하면 음수간선이 존재하지 않으면 최대 N-1번째 Iteration에서의 값 갱신이 마지막이기 때문.
*/
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,wh;
        scanf("%d %d %d",&n,&m,&wh);
        vector<vector<pair<int,int>>> edge(n+1);
        vector<int> dist(n+1,100000);
        dist[1]=0;
        int f,t,w;
        // printf("?????? -> %d %d %d",n,m,wh);
        for(int i=0;i<m;i++){//일직선
            scanf("%d %d %d",&f,&t,&w);
            edge[f].push_back({t,w});
            edge[t].push_back({f,w});
        }
        for(int i=0;i<wh;i++){//양방향
            scanf("%d %d %d",&f,&t,&w);
            edge[f].push_back({t,w*(-1)});
        }
        int check=false;
        for(int i=1;i<=n;i++){
            for(int from=1;from<=n;from++){
                for(int to_idx=0;to_idx<edge[from].size();to_idx++){
                    int to = edge[from][to_idx].first;
                    int to_weight = edge[from][to_idx].second;
                    if(dist[to] > dist[from]+to_weight){
                        dist[to]=dist[from]+to_weight;
                        if(i==n) {
                            check=true;
                            break;
                        }
                    }
                }
            }
        }
        printf("%s\n",check?"YES":"NO");
    }
    return 0;
}