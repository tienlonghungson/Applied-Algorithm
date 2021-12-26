#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct disjoint_set {
    vector<int> parent;
    disjoint_set(int n){
        parent =vector<int>(n);
        for (int i=0;i<n;++i){
            parent[i]=-1;
        }
    }

    int find_parent(int i){
        return (parent[i]<0)?i:(parent[i]=find_parent(parent[i]));
    }

    void merge(int x, int y){
        if ((x=find_parent(x))==(y=find_parent(y))){
            return;
        }
        if (parent[y]<parent[x]){
            swap(x,y);
        }
        parent[x]+=parent[y];
        parent[y]=x;
    }
};

const int N =1e5+1;
int n,m;
vector<pair<int,pair<int,int> > > edges;

void kruskal(){
    disjoint_set djs(n+1);
    long long mst_weight=0;
    int num_edge=0;

    bool (*cmp)(pair<int,pair<int,int> >, pair<int,pair<int,int> >) = [](pair<int,pair<int,int> > a, pair<int,pair<int,int> >b)->bool{
        return (a.first<b.first);
    };
    sort(edges.begin(), edges.end(), cmp);
    int curr_index=0;
    pair<int,pair<int,int> > edge;
    while (num_edge<n-1){
        edge = edges[curr_index];
        int u = edge.second.first, v= edge.second.second;
        if (djs.find_parent(u)!=djs.find_parent(v)){
            djs.merge(u,v);
            num_edge++;
            mst_weight+=(long long)edge.first;
        }
        curr_index++;
    }
    cout<<mst_weight<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    cin>>n>>m;
    int first_ver, second_ver, weight;
    int i=0;
    while(i++<m){
        cin>>first_ver>>second_ver>>weight;
        edges.push_back({weight,{first_ver,second_ver}});
    }         

    kruskal();

    return 0;
}