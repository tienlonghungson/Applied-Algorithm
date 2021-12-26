#include <iostream>
#include <vector>

using namespace std;

const int N =1e5+1;
vector<int> adj_vertexes[N];
vector<int> parents;
int n;

void set_parent(int vertex, int parent=1){
    parents[vertex]=parent;
    for (int adj : adj_vertexes[vertex]){
        if (parents[adj]==-1){
            set_parent(adj,vertex);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    cin>>n;
    int first_ver,second_ver;
    for (int i=0;i<n-1;++i){
        cin>>first_ver>>second_ver;
        adj_vertexes[first_ver].push_back(second_ver);
        adj_vertexes[second_ver].push_back(first_ver);
    }

    parents.assign((n+1),-1);
    set_parent(1);

    for (int i=2;i<=n;++i){
        cout<<parents[i]<<" ";
    }
    cout<<"\n";
    return 0;
}