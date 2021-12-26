#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+1;
int n, L1, L2;
int a[N];
vector<long long> gold;

long long gold_mining(){
    gold[0]=a[0];
    int pre_low_index_warehouse,pre_upper_index_warehouse, j;
    long long pre_seq_warehouse, res=0;
    for (int i=1;i<n;++i){
        pre_low_index_warehouse = max(0, i-L2);
        pre_upper_index_warehouse = i-L1;
        pre_seq_warehouse=0;
        for (j=pre_low_index_warehouse;j<=pre_upper_index_warehouse;++j){
            pre_seq_warehouse = max(pre_seq_warehouse,gold[j]);
        }
        gold[i] = a[i]+pre_seq_warehouse;
        res = max(res, gold[i]);
    }
    return res;
}

int main(){
    cin>>n>>L1>>L2;
    gold.resize(n);
    for (int i=0;i<n;++i){
        cin>>a[i];
    }
    cout<<gold_mining()<<"\n";
    return 0;
}