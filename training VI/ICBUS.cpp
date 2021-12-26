#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

const int N = 5001;
vector<int> adj_vertexes[N];
vector<int> extend_adj_vertexes[N];
int C[N],D[N];
int n,k;

void bfs(int vertex){
    queue<int> queue_for_bfs;
    vector<int> step((n+1),-1);
    step[vertex]=D[vertex];
    queue_for_bfs.push(vertex);

    int next_ver,i,u;
    while (!queue_for_bfs.empty()){
        next_ver = queue_for_bfs.front();
        queue_for_bfs.pop();
        if (step[next_ver]==0){
            continue;
        }
        for (int adj_to_nextver : adj_vertexes[next_ver]){
            if (step[adj_to_nextver]==-1){
                step[adj_to_nextver]=step[next_ver]-1;
                extend_adj_vertexes[vertex].push_back(adj_to_nextver);
                queue_for_bfs.push(adj_to_nextver);
            }
        }
    }
}

void dijkstra(){
    vector<int> distance((n+1),INT_MAX);
    vector<bool> check((n+1),0);
    distance[1]=0;
    int step=n;
    priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push(make_pair(distance[1],1));
    pair<int,int> tmp_pair;
    int u;
    while (!pq.empty()){
        tmp_pair = pq.top();
        u = tmp_pair.second;
        pq.pop();

        if (distance[u]!=tmp_pair.first){
            continue;
        }

        for (int v: extend_adj_vertexes[u]){
            if (distance[v]>distance[u]+C[u]){
                distance[v]=distance[u]+C[u];
                pq.push(make_pair(distance[v],v));
            }
        }
    }
    cout<<distance[n]<<"\n";
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif

    cin>>n>>k;
    int i=0;
    while (i++<n){
        cin>>C[i]>>D[i];
    }
    i=0;
    int first_ver,second_ver;
    while (i++<k){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
        adj_vertexes[second_ver].push_back(first_ver);
    }

    i=0;
    while (i++<n){
        bfs(i);
    }
    
    dijkstra();

    return 0;
}