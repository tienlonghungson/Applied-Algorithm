#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;

bool compare(pair<long, long> a, pair<long, long> b){
    return a.first < b.first;
}

vector<pair<long,long> > orders;

int main(){
#ifndef ONLINE_JUDGE
freopen("/Users/tienlong/Documents/Xcode/io/generatedInput.txt","r",stdin);
#endif
    int n;
    long long k;
    cin >>n >>k;
    
    for(long i=0;i<n;++i){
        pair<long,long> input;
        cin>>input.first>>input.second;
        orders.push_back(input);
    }

    sort(orders.begin(), orders.end(), compare);

    long long currGood = 0,count=0, numTurns, temp;

    for(long i=orders.size()-1;i>=0;--i){
        if(orders[i].first<0){
            break;
        }

        temp = orders[i].second;
        if(currGood>temp){
            currGood-= temp;
        } else {
            temp -=currGood;
            currGood = 0;
            numTurns = temp/k;
            count += 2*orders[i].first*numTurns;
            temp = temp%k;
            if (temp>0){
                currGood = k- temp;
                count+= 2*orders[i].first;
            }
        }
        // count+= max((long long)ceil((double)(orders[i].second-currGood)/(double)k),0LL)*orders[i].first*2;
        // currGood = (k-max((orders[i].second-currGood),0LL)%k)%k;
    }
    
    currGood = 0;
    for(long i=0;i<orders.size();++i){
        if(orders[i].first>0){
            break;
        }

        temp = orders[i].second;
        if(currGood>temp){
            currGood-= temp;
        } else {
            temp -=currGood;
            currGood = 0;
            numTurns = temp/k;
            count += 2*(-orders[i].first)*numTurns;
            temp = temp%k;
            if (temp>0){
                currGood = k- temp;
                count+= 2*(-orders[i].first);
            }
        }

        // count += max((long long)ceil((double)(orders[i].second-currGood)/(double)k),0LL)*abs(orders[i].first)*2; 
        // currGood  = (k-max((orders[i].second-currGood),0LL)%k)%k;
    }
    cout<<count<<"\n";
    return 0;
}
