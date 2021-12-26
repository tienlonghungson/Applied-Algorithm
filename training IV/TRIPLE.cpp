#include<iostream>
#include<algorithm>

using namespace std;

int N,K;
int a[5000];

int count_triple(){
    sort(a,a+N);
    // for (int i=0;i<N;++i){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    int count=0, i, j, k, temp, count_left, count_right;
    int bound = K/3;
    for (int i=0; a[i]<=bound;++i){
        // cout<<i<<" ";
        j=i+1;k = N-1;
        while(j<k){
            temp = K-a[i]-a[j]-a[k];
            // cout<<"temp "<<temp<<"\n";
            if (temp>0) {
                j++;
            } else if (temp<0){
                k--;
            } else {
                if (a[j]==a[k]){
                    count+= (k-j+1)*(k-j)/2;
                    break;
                } else { 
                    count_left=1;
                    // cout<<"WHILE J "<<j<< "\n";
                    while(a[j]==a[++j]){
                        count_left++;
                        // cout<<j<<" ";
                    }
                    // cout<<"Last J "<<j<<endl;
                    count_right=1;
                    // cout<<"WHILE K "<<k<<"\n";
                    while(a[k]==a[--k]){
                        // cout<<k<<" ";
                        count_right++;
                    }
                    // cout<<"Last K "<<k<<"\n";
                    count+= count_left*count_right;
                    // cout<<"TEMP COUNT "<<count<<"\n";
                }
            }
        }
        // cout<<"\n";
    }
    return count;
}

int main(){
    int i;
    cin>>N>>K;
    for(i=0;i<N;++i){
        cin>>a[i];
    }
    cout<<count_triple()<<"\n";
    return 0;
}