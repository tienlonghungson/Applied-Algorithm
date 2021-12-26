//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int, int> > radar1, radar2;

const int N=1000;
int cur[2*N][2*N];
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int numTest, L, C, i,j;
    int point;

    cin>>numTest;
    while(numTest--){
        cin>>L>>C;
        radar1.clear(); radar2.clear();
        for(i=0;i<L;++i){
            for(j=0;j<C;++j){
                cin>>point;
                if(point) radar1.push_back(pair<int,int> (i,j));
            }
        }
        
        
        for(i=0;i<L;++i){
            for(j=0;j<C;++j){
                cin>>point;
                if(point) radar2.push_back(pair<int,int> (i,j));
            }
        }
        

        memset(cur, 0, 2*N*2*N*sizeof cur[0][0]);

        for(auto e1: radar1){
            for(auto e2: radar2){
                cur[e1.first - e2.first+N][e1.second-e2.second+N]++;
            }
        }
        
        int maxObj = 0;
        for(i=0;i<2*N;++i){
            for(j=0;j<2*N;++j){
                maxObj =  max(maxObj, cur[i][j]);
            }
        }
        
        
        cout<<maxObj<<"\n";
    }
    return 0;
}
