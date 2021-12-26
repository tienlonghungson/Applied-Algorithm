#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct disjoint_set{
    vector<int> parents;

    disjoint_set(int n){
        parents = vector<int>(n);
        for (int i=0;i<n;++i){
            parents[i]=-1;
        }
    }

    int find_parents(int i){
        return (parents[i]<0)?i:(parents[i]=find_parents(parents[i]));
    }

    void merge(int x, int y){
        if ( (x=find_parents(x)) == (y=find_parents(y))){
            return ;
        }
        if (parents[y]<parents[x]){
            swap(x,y);
        }
        parents[x]+=parents[y];
        parents[y]=x;
    }
};
const int N=16, M=25;

// use to create tree
vector<int> adj_vertexes[N];
pair<int,pair<int,int> > edges[M];
vector<int> tree_adj_vertexes[N];

// use to calculate diameter
vector<bool> is_visited;
int end_point;

int n,m,k;
int min_weight=1e9;


int bfs(int arbitrary_root){
    int longest_path=0;

    vector<int> dis_from_root((n+1));
    dis_from_root[arbitrary_root]=0;
    is_visited[arbitrary_root]=true;

    queue<int> queue_for_bfs;
    queue_for_bfs.push(arbitrary_root);

    int search_ver, adj;
    while (!queue_for_bfs.empty()){
        search_ver = queue_for_bfs.front();
        queue_for_bfs.pop();

        for (int adj : tree_adj_vertexes[search_ver]){
            if (!is_visited[adj]){
                is_visited[adj]=true;
                queue_for_bfs.push(adj);
                dis_from_root[adj]=dis_from_root[search_ver]+1;

                if (longest_path<dis_from_root[adj]){
                    longest_path=dis_from_root[adj];
                    end_point=adj;
                }
            }
        }
    }
    return longest_path;
}
int cal_diameter(){
    is_visited.assign((n+1),false);
    bfs(1);
    is_visited.assign((n+1),false);
    // int res= bfs(end_point);
    // return res;
    return bfs(end_point);
}

void add_edge_to_tree(disjoint_set djs,int num_edge,int curr_weight=0,int first_ver=0,int second_ver=0, int index_pre_edge=-1){
    if (num_edge==n){
        if (cal_diameter() <= k) {
            min_weight = min(min_weight,curr_weight);
        }
        return;
    }

    if (first_ver!=0){
        djs.merge(first_ver,second_ver);
    }

    int last_index_edge_to_search = m-(n-num_edge);
    pair<int,pair<int,int> > edge;
    int u,v,w;
    for (int i=index_pre_edge+1;i<=last_index_edge_to_search;++i){
        edge=  edges[i];u = edge.second.first; v= edge.second.second;w=edge.first;
        if (djs.find_parents(u)!=djs.find_parents(v)){
            curr_weight += w;
            if (curr_weight < min_weight){
                tree_adj_vertexes[u].push_back(v);
                tree_adj_vertexes[v].push_back(u);
                add_edge_to_tree(djs,(num_edge+1),curr_weight,u,v,i);
                tree_adj_vertexes[u].pop_back();
                tree_adj_vertexes[v].pop_back();                
            }
            curr_weight -= w;
        }
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
        adj_vertexes[first_ver].push_back(second_ver);
        adj_vertexes[second_ver].push_back(first_ver);
        edges[i] = {weight,{first_ver,second_ver}};
    }

    disjoint_set djs((n+1));
    add_edge_to_tree(djs,1);
    cout<< ((min_weight!=1e9)?min_weight:-1)<<"\n";
    return 0;
}