#include<iostream>

using namespace std;

int main(){
    int N;
    int a[1001];
    cin>>N;
    int count =0, j, temp;
    cin>>a[1];
    for (int i=2;i<=N;++i){
        cin>>a[i];
        j=i-1;
        temp = a[i];
        while ((a[j]>=temp)&&(j>=1)){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        count += j;
    }
    
    cout<<count<<"\n";
    return 0;
}