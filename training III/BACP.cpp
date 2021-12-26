//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>
#include<vector>

using namespace std;

int n,m;
int *credit;
int A[17][17];
int load[5];
int *assigned, minOfMaxLoad=INT_MAX;

bool check(int subj, int period) {
    for (int i=0; i<subj;++i) {
        if (A[i][subj]) {
            if (assigned[i]>=period) {
                return false;
            }
        } else if (A[subj][i]) {
            if (assigned[i]<=period) {
                return false;
            }
        }
    } 
    return true; 
}

void updateResult(){
    int temp= 0;
    for(int i=0;i<m;++i) {
        temp = max(temp, load[i]);
    }
    minOfMaxLoad = min(temp, minOfMaxLoad);
    
}

void choosePeriod(int i) {
    for (int j=0;j<m;++j) {
        if (check(i,j)) {
            assigned[i] = j;
            load[j] += credit[i];
            if (i==n-1) {
                updateResult();
            } else {
                choosePeriod(i+1);
            }
            load[j] -= credit[i];
        }
    }    
}

int main(){
    cin>>n>>m;
    credit = new int[n];
    assigned = new int[n];
    int i,j;
    for (i=0;i<n;++i){
        cin>>credit[i];
    }

    for (i=0;i<n;++i) {
        for (j=0;j<n;++j) {
            cin>>A[i][j];
        }
    }
    choosePeriod(0);
    cout<<minOfMaxLoad<<"\n";
    return 0;
}
