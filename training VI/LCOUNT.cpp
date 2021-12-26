#include <iostream>
#include <vector>

using namespace std;
const int N=1e5+1;
vector<int> adj_vertexes[N];
int n;

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

    int count_leaves=0; 
    // leaves are the node whose adjacent list has only one member;
    for (int i=2;i<=n;++i){
        if (adj_vertexes[i].size()==1){
            count_leaves++;
        }
    }
    cout<<count_leaves<<"\n";

    return 0;
}