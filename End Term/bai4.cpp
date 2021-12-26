//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 11/12/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const int N=51;
int n,Q;
int dist[N][N];
int a[N];
int path[N];
int res_path[N];
long long min_cost=1e9, curr_cost;
vector<bool> check;
void printPath(int n){
    for (int i=1;i<=n;++i){
        cout<<res_path[i]<<" ";
    }
    cout<<"\n";
}
void copyPath(int n){
    for (int i=1;i<=n;++i){
        res_path[i]=path[i];
    }
}
void TSP(int index_pos){
    if (index_pos==n+1){
        curr_cost+= dist[path[n]][0];
        if (min_cost>curr_cost){
            min_cost=curr_cost;
            copyPath(n);
        }
        curr_cost -= dist[path[n]][0];
        return;
    }
    // cout<<"try pos "<<index_pos<<"\n";
    for (int i=1;i<=n;++i){
        if (!check[i]){
            check[i]=true;
            path[index_pos]=i;
            curr_cost+= dist[path[index_pos-1]][path[index_pos]];
            if (curr_cost+5*(n+1-index_pos)<min_cost){
                TSP(index_pos+1);
            }
            curr_cost-= dist[path[index_pos-1]][path[index_pos]];
            check[i]=false;
        }
    }
}

int main(){
#ifndef ONLINE_JUDGEMENT
    freopen("/Users/tienlong/Documents/Xcode/Codeforces/Codeforces/End Term/input/input_5.txt","r",stdin);
//    freopen("/Users/tienlong/Documents/Xcode/io/output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>Q;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    for (int i=0;i<=n;++i){
        for (int j=0;j<=n;++j){
            cin>>dist[i][j];
        }
    }

    check.assign((n+1),false);
    path[0]=0;
    // check[3]=check[4]=true;
    curr_cost=0;
    TSP(1);
    cout<<min_cost<<"\n";
    printPath(n);
    return 0;
}
