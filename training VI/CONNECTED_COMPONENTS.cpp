#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int N= 1e5+1;
int n,m;
vector<int> adj_vertexes[N];
bool mark[N];

void dfs(int vertex){
    mark[vertex]=true;
    for (int adj : adj_vertexes[vertex]){
        if (!mark[adj]){
            dfs(adj);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif
    cin>>n>>m;
    int first_ver, second_ver;
    for (int i=0;i<m;++i){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
        adj_vertexes[second_ver].push_back(first_ver);
    }

    memset (mark,0,sizeof(*mark)*(n+1));

    int count=0;
    for (int i=1;i<=n;++i){
        if (!mark[i]){
            dfs(i);
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}