#include<iostream>

using namespace std;

const int not_exists = -1e6;
int N;
int a[100001];
int even_sum = not_exists, odd_sum = not_exists;
int max_even_sum =not_exists,  max_odd_sum = not_exists;

int main(){
    cin>>N;
    int sum=0;
    for (int i=1;i<=N;++i){
        cin>>a[i];
        sum+=a[i];
        if (a[i]%2==0){
            if (even_sum==not_exists){
                even_sum = a[i];
            } else {
                even_sum = max(a[i], even_sum+a[i]);                
            }
            max_even_sum = max(max_even_sum, even_sum);

            if (odd_sum!=not_exists){
                odd_sum = odd_sum+a[i];
                max_odd_sum = max(max_odd_sum, odd_sum);
            }
        } else {
            if (odd_sum != not_exists) {
                even_sum = odd_sum + a[i];
                max_even_sum = max(max_even_sum, even_sum);
            } 

            if (even_sum == not_exists){
                odd_sum = a[i];
            } else {
                odd_sum = max(a[i], odd_sum+a[i]);
            }
            max_odd_sum = max(max_odd_sum, odd_sum);
        }
        if (sum%2==0){
            max_even_sum = max(max_even_sum,sum);
        } else {
            max_odd_sum = max(max_odd_sum, sum);
        }       
    }
    cout<<max_even_sum<<"\n";
    return 0;
}

