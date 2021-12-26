#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
const int N = 1e5+1;
int n,m,s,t;
vector<pair<int,int> > adj_vertexes[N]; 
// first is the distance ( weight), second is the adjacent vertex

void dijkstra_priority_queue(int s, int t){
    vector<int> distance((n+1),1e9);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    distance[s]=0;
    pq.push({distance[s],s});
    pair<int,int> tmp;
    int tmp_ver, tmp_weight;
    while (!pq.empty()){
        tmp= pq.top(); tmp_weight= tmp.first; tmp_ver = tmp.second;
        pq.pop();
        if (distance[tmp_ver]!=tmp_weight){
            continue;
        }
        if (tmp_ver==t){
            break;
        }
        for (pair<int,int> edge : adj_vertexes[tmp_ver]){
            if (distance[edge.second]>tmp_weight+edge.first){
                distance[edge.second]=tmp_weight+edge.first;
                pq.push({distance[edge.second],edge.second});
            }
        }
    }
    cout<<((distance[t]!=1e9)?distance[t]:-1)<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    cin>>n>>m;
    int first_ver, second_ver, weight;
    int i=0;
    while(i++<m){
        cin>>first_ver>>second_ver>>weight;
        adj_vertexes[first_ver].push_back({weight,second_ver});
    }     
    cin>>s>>t;
    dijkstra_priority_queue(s,t);
    return 0;
}