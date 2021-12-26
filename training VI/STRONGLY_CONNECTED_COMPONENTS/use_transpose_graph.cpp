#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> >adj_vertexes, reverse_adj_vertexes;
vector<bool> is_visited;
vector<int> orders, components;
int n,m;

void dfs_in_origin_graph(int vertex){
    is_visited[vertex]=true;
    for (int adj:adj_vertexes[vertex]){
        if (!is_visited[adj]){
            dfs_in_origin_graph(adj);
        }
    }
    orders.push_back(vertex);
}

void dfs_in_reverse_graph(int vertex){
    is_visited[vertex]=true;
    components.push_back(vertex);
    for (int adj: reverse_adj_vertexes[vertex]){
        if (!is_visited[adj]){
            dfs_in_reverse_graph(adj);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    int i;
    adj_vertexes.resize((n+1));
    reverse_adj_vertexes.resize((n+1));
    int first_ver, second_ver;
    for (i=0;i<m;++i){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
        reverse_adj_vertexes[second_ver].push_back(first_ver);
    }

    is_visited.assign((n+1),false);
    for (i=1;i<=n;++i){
        if (!is_visited[i]){
            dfs_in_origin_graph(i);
        }
    }

    is_visited.assign((n+1),false);
    int count=0, next_ver;
    for (i=1;i<=n;++i){
        next_ver = orders[n-i];
        if (!is_visited[next_ver]){
            dfs_in_reverse_graph(next_ver);
            count++;
            components.clear();
        }
    }
    cout<<count<<"\n";
    return 0;
}