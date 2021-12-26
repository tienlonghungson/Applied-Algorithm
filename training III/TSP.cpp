//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>
#include<string.h>
using namespace std;

int n,m;
int minTwoCity=INT_MAX;
unsigned long long minCost = LONG_MAX, tempFee;
int cost[21][21], path[21];
bool passed[21];

void travel(int next) {
    int i;
    for(i=2;i<=n;++i){
        if (!passed[i]&&(cost[path[next-1]][i]>=0)) {
            passed[i] = true;
            path[next] = i;
            tempFee = tempFee+cost[path[next-1]][i];

            if (next==n) {
                if (cost[i][path[1]]>=0) {
                    if(tempFee+cost[i][path[1]]<minCost) {
                        minCost = tempFee+cost[i][path[1]];
                    }
                }
            } else {
                if (tempFee + (n-next+1)*minTwoCity<minCost){
                    travel(next+1);
                }
            }
            passed[i] = false;
            tempFee -= cost[path[next-1]][i];
        }
    }
}

int main(){
    cin>>n>>m;
    
    int i, start, end;
    
    memset(cost, -1, sizeof cost);
    for(i=0;i<m;++i){
        cin>>start>>end>>cost[start][end];
        minTwoCity = min(minTwoCity, cost[start][end]);
    }
    
    path[1] =1 ;
    tempFee=0LL;
    travel(2);
    cout<<minCost<<"\n";
    return 0;
}
