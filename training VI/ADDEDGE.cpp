#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;
const int N = 1e5+1;
vector<int> adj_vertexes[N];

vector<int> forest_adj_vertexes[N];
vector<int> low,entry_time;
vector<int> is_visited;
int curr_time;

int n,m;

void dfs(int ver, int prev_vertex){ // find bridges
    is_visited[ver]=true;
    low[ver]=entry_time[ver]=curr_time++;
    for (int adj : adj_vertexes[ver]){
        if (adj != prev_vertex){
            if (is_visited[adj]){
                low[ver] = min(low[ver],entry_time[adj]);
            } else {
                dfs(adj, ver);
                low[ver] = min(low[ver], low[adj]);
                if (low[adj]>entry_time[ver]){
                    // cout<<"found edge: "<<adj<<" "<<ver<<"\n";
                    forest_adj_vertexes[adj].push_back(ver);
                    forest_adj_vertexes[ver].push_back(adj);
                }
            }
        }
    }
}

int dfs(int ver){
    is_visited[ver]=true;
    int children=1;
    for (int adj: forest_adj_vertexes[ver]){
        if (!is_visited[adj]){
            children+=dfs(adj);
        }
    }
    return children;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/ADDEDGE.txt","r",stdin);
    #endif
    cin>>n>>m;
    int i,j;

    int first_ver, second_ver;
    for (int i=0;i<m;++i){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
        adj_vertexes[second_ver].push_back(first_ver);
    }

    curr_time=1;
    low.assign((n+1),-1);
    entry_time.assign((n+1),-1);
    is_visited.assign((n+1),false);
    for (int i=1;i<=n;++i){
        if (!is_visited[i]){
            dfs(i,-1);
        }
    }
    is_visited.assign((n+1),false);
    
    int tmp;
    long long count_pair = 0;
    for (int i=1;i<=n;++i){
        if (!is_visited[i]){
            tmp = dfs(i);
            // cout<<"number of node on tree : "<<tmp<<"\n";
            count_pair += 1LL*tmp*(tmp-1)/2 - (tmp-1);
        }
    }
    cout<<count_pair<<"\n";
    return 0;
}