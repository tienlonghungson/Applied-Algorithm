#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct disjoint_set{
    vector<int> parents;

    disjoint_set(int n){
        parents= vector<int>(n);
        for (int i=0;i<n;++i){
            parents[i]=-1;
        }
    } 

    int find_parent(int i){
        return (parents[i]<0)?i:(parents[i]=find_parent(parents[i]));
    }

    void merge(int x, int y){
        if ( (x=find_parent(x)) == (y=find_parent(y))){
            return;
        }
        if (parents[y]<parents[x]){
            swap(x,y);
        }
        parents[x]+=parents[y];
        parents[y]=x;
    }
};
vector<pair<int,int> > edges;
int n,m;
int count_st=0;

void add_edge(disjoint_set djs, int num_edge,int first_ver=0,int second_ver=0,int index_prev_edge=-1){
    if (num_edge==n){
        count_st++;
        return;
    }
    if (first_ver!=0){
        djs.merge(first_ver,second_ver);
    }
    int last_index=m-(n-num_edge);
    pair<int,int > tmp_edge;
    int u,v;
    for (int i=index_prev_edge+1;i<=last_index;++i){
        tmp_edge = edges[i];
        u = tmp_edge.first; v= tmp_edge.second;
        if (djs.find_parent(u)!=djs.find_parent(v)){
            // cout<<"edge #"<<num_edge<<": "<<u<<", "<<v<<"\n";
            // cout<<"check djs\n";
            // for (int j=1;j<=n;++j){
            //     cout<<djs.parents[j]<<" ";
            // }
            // cout<<"\n";
            add_edge(djs,(num_edge+1),u,v,i);
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
        edges.push_back({first_ver,second_ver});
    }

    disjoint_set djs((n+1));
    add_edge(djs,1);
    cout<<count_st<<"\n";
    return 0;
}