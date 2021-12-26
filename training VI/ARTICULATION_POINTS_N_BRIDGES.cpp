//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 11/12/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

const int N=1e5+1;
vector<int> adj_vertexes[N], low, entry_time;
vector<bool> is_visited;
int curt_time;
int n,m;
set<int> num_articulation_points;
int num_bridges;

void dfs(int vertex, int pre_vertex=-1){
    is_visited[vertex]=true;
    low[vertex] = entry_time[vertex] = curt_time++;
    int children=0;
    for (int adj : adj_vertexes[vertex]){
        if (adj == pre_vertex) {
            continue;
        }
        if (is_visited[adj]){ // this is a backward edge
            low[vertex] = min(low[vertex],entry_time[adj]);
        } else { // this is a forward edge
            dfs(adj,vertex);
            low[vertex] = min(low[vertex],low[adj]);
            if (low[adj]>=entry_time[vertex]&& pre_vertex!=-1){
                num_articulation_points.insert(vertex);
            } 
            if (low[adj]>entry_time[vertex]){
                cout<<"found edge: "<<adj<<" "<<vertex<<"\n";
                num_bridges++;
            }
            children++;
        }
    }

    if (children>1 && pre_vertex==-1){
        num_articulation_points.insert(vertex);
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

    curt_time=1;
    is_visited.assign((n+1),false);
    low.assign((n+1),-1);
    entry_time.assign((n+1),-1);

    for (int i=1;i<=n;++i){
        if (!is_visited[i]){
            dfs(i);
        }
    }
    cout<<num_articulation_points.size()<<" "<<num_bridges<<"\n";
    
    return 0;
}
