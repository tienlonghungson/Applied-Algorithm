#include<iostream>

using namespace std;

const int SIZE = 1e5+1;

int main(){
    int N;
    int a[SIZE];
    int count = 1;

    cin>>N;
    cin>>a[1];
    for (int i=2;i<=N;++i){
        cin>>a[i];
        if (a[i]<a[i-1]) {
            count++;
        }
    }

    cout<<count<<"\n";
    return 0;
}