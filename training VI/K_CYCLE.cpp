#include <iostream>
#include <vector>

using namespace std;
const int N=31;
vector<int> adj_vertexes[N];
vector<int> is_visited;
int n,m,k;
int count_cycle=0;
void find_cycle(int num_vertex, int prev_ver, int source){
    if (num_vertex==(k+1)){
        for (int adj: adj_vertexes[prev_ver]){
            if (adj==source){
                count_cycle++;
                break;
            }
        }
        return;
    }

    for (int adj : adj_vertexes[prev_ver]){
        if (!is_visited[adj]){
            is_visited[adj]=true;
            find_cycle((num_vertex+1),adj,source);
            is_visited[adj]=false;
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>n>>m>>k;
    int first_ver,second_ver;
    for (int i=0;i<m;++i){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
        adj_vertexes[second_ver].push_back(first_ver);
    }

    is_visited.assign((n+1),false);

    for (int i=1;i<=n;++i){
        is_visited[i]=true;
        find_cycle(2,i,i);
        is_visited[i]=false;
    }

    cout<<count_cycle/(2*k)<<"\n";

    return 0;
}