#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int N=1e5+1;
vector<int> adj_vertexes[N];
vector<bool> connect(N,false);
vector<int> low(N),entry_time(N,-1);
stack<int> components;
int curt_time=0;
int count_comps=0;
int n,m;

void dfs(int vertex){
    components.push(vertex);
    connect[vertex]=true;
    low[vertex]=entry_time[vertex]=curt_time++;
    for (int adj : adj_vertexes[vertex]){
        if (entry_time[adj]==-1){
            dfs(adj);
            low[vertex]=min(low[vertex],low[adj]);
        } else if (connect[adj]){
            low[vertex]=min(low[vertex], entry_time[adj]);
        }
    }
    if (entry_time[vertex]==low[vertex]){
        int cur;
        while(1){
            cur=components.top();
            components.pop();
            connect[cur]=false;
            if (cur==vertex){
                break;
            }
        }
        count_comps++;
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
    int first_ver, second_ver;
    for (i=0;i<m;++i){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
    }

    for (i=1;i<=n;++i){
        if (entry_time[i]==-1){
            dfs(i);
        }
    }

    cout<<count_comps<<"\n";

    return 0;
}