#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;

const int N=1e3+1;
int n,k;
vector<pair<int,int> > positive_positions, negative_positions;
long long times=0, tmp_times;

void ship(vector<pair<int,int> > positions){
    int curr_good=0,x,m;
    for (int i=0;i<positions.size();++i){
        m=positions[i].second;
        x=positions[i].first;
        if (curr_good==0){
            curr_good=k;
            tmp_times = ceil(((double)m)/((double)curr_good));
            curr_good = tmp_times*curr_good-m;
        } else {
            m = max (m-curr_good,0);
            tmp_times = ceil(((double)m)/((double)k));
            curr_good = max(tmp_times*k-m,(long long)(curr_good-positions[i].second));
        }
        times += 2*tmp_times*x;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    cin>>n>>k;
    int x,m;
    for (int i=0;i<n;++i){
        cin>>x>>m;
        if (x>=0){
            positive_positions.push_back(make_pair(x,m));
        } else {
            negative_positions.push_back(make_pair(-x,m));
        }
    }

    bool (*cmp)(pair<int,int>, pair<int,int>) = [](pair<int,int> a, pair<int,int> b)->bool{
        return (a.first>b.first);
    };
    sort(positive_positions.begin(),positive_positions.end(),cmp);
    sort(negative_positions.begin(),negative_positions.end(),cmp);


    ship(positive_positions);
    ship(negative_positions);

    cout<<times<<"\n";

    return 0;
}