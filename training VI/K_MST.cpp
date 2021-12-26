#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
const int N= 21;
int n,m,k;
vector<pair<int,int> > adj_vertexes[N];// first is weight, second is adjacent vertex
int k_mst=1e9;

void find_k_mst(int i){
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> bestW((n+1),1e9);
    bestW[i]=0;
    int num_edge=0, tmp_weight=0;
    pq.push({bestW[i],i});
    while(num_edge<k){
        if (pq.empty()){
            break;
        }
        int w = pq.top().first, v = pq.top().second;
        pq.pop();
        if (w!=bestW[v]){
            continue;
        }

        bestW[v]=0;

        for (pair<int,int> edge: adj_vertexes[v]){
            if (bestW[edge.second]>edge.first){
                bestW[edge.second]=edge.first;
                pq.push({bestW[edge.second],edge.second});
            }
        }

        if (v!=i){
            num_edge++;
            tmp_weight+=w;
        }
    }
    if (num_edge==k){
        k_mst= min(k_mst,tmp_weight);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    cin>>n>>m>>k;
    int i;
    int first_ver, second_ver, weight;
    for (i=0;i<m;++i){
        cin>>first_ver>>second_ver>>weight;
        adj_vertexes[first_ver].push_back({weight,second_ver});
        adj_vertexes[second_ver].push_back({weight,first_ver});
    }

    for (i=1;i<=n;++i){
        find_k_mst(i);
    }
    
    cout<<((k_mst<1e9)?k_mst:-1)<<"\n";

    return 0;
}