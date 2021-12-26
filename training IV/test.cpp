#include<iostream>

using namespace std;

int main(){
    int a[10] = {4,4,4,4,4,5,5,5,5,5} ;
    int j=0;
    while(a[j]==a[++j]){
        cout<<j<< " ";
    }
    cout<<"\n";
    return 0;
}