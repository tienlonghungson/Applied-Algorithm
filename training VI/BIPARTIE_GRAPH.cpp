#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
const int N=1e5+1;

vector<int> adj_vertexes[N];
int color[N];
int n,m;

void dfs(int vertex){
    for (int adj : adj_vertexes[vertex]){
        if (color[adj]==-1){
            color[adj] = 1-color[vertex];
            dfs(adj);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif

    cin>>n>>m;
    int first_ver,second_ver;
    for (int i=0;i<m;++i){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
        adj_vertexes[second_ver].push_back(first_ver);
    }

    memset(color,-1,(n+1)*sizeof(*color));

    for (int i=1;i<=n;++i){
        if (color[i]==-1){
            color[i]=0;
            dfs(i);
        }
    }

    bool is_biparitie= true;
    for (int i=1;i<=n;++i){
        for (int adj:adj_vertexes[i]){
            is_biparitie &= (color[adj]!=color[i]);
        }
    }

    cout<<is_biparitie<<"\n";

    return 0;
}