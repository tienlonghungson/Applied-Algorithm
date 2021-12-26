//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

vector<pair<int,int> > objects;
vector<int> bound;
int n, b, maxVal, tempVal,tempWeight;

bool compare(pair<int, int> pairI, pair<int, int> pairII){
    return ( ((float)pairI.first/(float)pairI.second)<((float)pairII.first/(float)pairII.second)) ;
}

void getObject(int i){
    int choose;
    for(choose=0;choose<2;++choose){
        tempWeight+= choose*objects[i].first;
        if(tempWeight<=b){
            tempVal += choose*objects[i].second;
            maxVal = max(maxVal, tempVal);
            if(i<n-1) {
                getObject(i+1);
            }
            tempVal -= choose*objects[i].second;
        }
        tempWeight-= choose*objects[i].first;
    }
}

int main(){
    cin>>n>>b;
    objects.resize(n);
    bound.resize(n);
    for(int i=0;i<n;++i){
        cin>>objects[i].first>>objects[i].second;
    }
    sort(objects.begin(), objects.end(), compare) ;
    getObject(0);
    cout<<maxVal<<"\n";
    return 0;
}