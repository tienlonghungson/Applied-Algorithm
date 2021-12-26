#include <iostream>

using namespace std;

int main(){
    int n;
    int currency[6] = {1,5,10,50,100,500};
    cin>> n ;
    n=1000-n;
    int count=0,i=5;
    while(n!=0&&i>=0){
        count+= n/currency[i];
        n=n%currency[i--];
    }
    cout<<count<<"\n";
    return 0;
}