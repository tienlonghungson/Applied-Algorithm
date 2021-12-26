#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, i,q,p;
    cin>>n;
    vector<int> road(n+2);
    // road.push_back(INT_MAX);
    road[0]=INT_MAX; road[n+1]= INT_MAX;
    int res=0, input;
    for(i=1;i<=n;++i){
        cin>>road[i];
        res+= (road[i]==road[i-1])?0:1;
    }
    // road.push_back(INT_MAX);
    cin>>q;
    for(i=0;i<q;++i){
        cin>>p>>input;
        res+= (road[p]==road[p-1])?0:-1;
        res+= (road[p]==road[p+1])?0:-1;
        res+= (input==road[p-1])?0:1;
        res+= (input==road[p+1])?0:1;
        road[p] = input ;
        cout<<res<<"\n";
    }
    return 0;
}