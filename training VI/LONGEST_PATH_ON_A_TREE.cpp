#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
const int N = 1e5+1;
vector<pair<int,int> > adj_vertexes[N];
// first is weight , second is adjacent vertex
int n;
vector<bool> is_visited;
int end_point;
int longest_path=0;

void bfs(int arbitrary_root){
    vector<int> dis_from_root((n+1),0);
    dis_from_root[arbitrary_root]=0;
    is_visited[arbitrary_root]=true;
    
    queue<int> queue_for_bfs;
    queue_for_bfs.push(arbitrary_root);
    
    int search_ver, adj;
    while (!queue_for_bfs.empty()){
        search_ver = queue_for_bfs.front();
        queue_for_bfs.pop();

        for (pair<int,int> edge : adj_vertexes[search_ver]){
            adj = edge.second;
            if (!is_visited[adj]){
                is_visited[adj]=true;
                queue_for_bfs.push(adj);
                dis_from_root[adj]=dis_from_root[search_ver]+edge.first;

                if (longest_path<dis_from_root[adj]){
                    longest_path=dis_from_root[adj];
                    end_point=adj;
                }
            }
        }
    }
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>n;
    int first_ver,second_ver,weight;
    for (int i=0;i<n-1;++i){
        cin>>first_ver>>second_ver>>weight;
        adj_vertexes[first_ver].push_back({weight,second_ver});
        adj_vertexes[second_ver].push_back({weight,first_ver});
    }

    is_visited.assign((n+1),false);
    bfs(1);
    is_visited.assign((n+1),false);
    bfs(end_point);
    cout<<longest_path<<"\n";
    return 0; 
}