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
int n,m; // m teachers, n courses
vector<vector<int> >teachers;
int conflict[31][31];
int tchWithSubs[11][31];
int *assignT, *tempMaxLoad;
int maxLoad = -1, minRecord = INT_MAX;
bool resultExists = false ;

void chooseAssigned(int i){
    int j;//, sizeTch;
    
    bool checkUnConflict ;
    for (j=1;j<=m;++j){
        checkUnConflict = true;
        if (tchWithSubs[j][i]) {
            for (int sub : teachers[j]) {
                if (conflict[sub][i]) {
                    checkUnConflict = false;
                    break;
                }
            }
            if (checkUnConflict) {
                assignT[i] = j;
                teachers[j].push_back(i) ;
                tempMaxLoad[i] = maxLoad;
                maxLoad = max(maxLoad, (int)teachers[j].size());
                if (maxLoad <= minRecord) {
                    if (i==n) {
                        resultExists = true;
                        minRecord = maxLoad;
                    } else {
                        chooseAssigned(i+1);
                    }
                }
                maxLoad = tempMaxLoad[i];
                teachers[j].pop_back();
            }
        }
    }
}

int main(){
    cin>>m>>n;
    assignT = new int[n+1] ;
    tempMaxLoad = new int[n+1];
    teachers.resize(n+1);
    
    int i,j, subjs, numSubjs;
    for (i=1;i<=m;++i){
        cin>>numSubjs;
        for (j=0;j<numSubjs;++j){
            cin>> subjs;
            tchWithSubs[i][subjs] = 1;
        }
    }
    
    cin>>numSubjs; // #conflicts
    for (i=0;i<numSubjs;++i) {
        cin>>j>>subjs ; // j and subjs present 2 conflict subjects
        conflict[j][subjs] = 1;
        conflict[subjs][j] = 1;
    }
    
    chooseAssigned(1);
    if (resultExists) {
        cout<<minRecord<<"\n";
    } else {
        cout<<-1<<"\n";
    }
    return 0;
}
