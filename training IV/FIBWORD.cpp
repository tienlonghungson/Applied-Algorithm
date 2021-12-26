#include<iostream>
#include<string>

using namespace std;

const int N=100;
const int n_prepare =25;
int n;
string pattern;
string fib_words[n_prepare];
long long fib_num[n_prepare];
long long mid_count[2];
long long occurrence_in_string[101];

void initiate(){
    fib_words[0]='0'; fib_words[1]='1';
    fib_num[0]=1; fib_num[1]=1;
    for (int i=2;i<n_prepare;++i){
        fib_words[i] = fib_words[i-1]+fib_words[i-2];
        fib_num[i] = fib_num[i-1]+fib_num[i-2];
    }
}

long long count(string my_string, string pattern){
    int my_length = my_string.size();
    int length_p = pattern.length();
    long long count = 0; 
    bool check;
    for (int i=0;i<=my_length-length_p;++i){
        check = true;
        for (int k=0;k<length_p;++k){
            if(my_string[k+i]!=pattern[k]){
                check = false ;
            }
        }
        if (check){
            count++;
        }
    }
    return count;
}

long long count(int n, string pattern){
    if (occurrence_in_string[n]<0){
        occurrence_in_string[n] = count(n-1, pattern)+ count(n-2, pattern)+mid_count[n%2];
    }
    return occurrence_in_string[n];
}

long long solve(int n, string pattern){
    int length_p = pattern.length();
    if (n<n_prepare&&fib_num[n]<length_p) {
        return 0;
    }
    for (int j=0;j<=n;++j){
        occurrence_in_string[j]=-1;
    }
    int i=1;
    while(fib_num[i-1]<length_p){
        i++;
    }
    occurrence_in_string[i-1] = count(fib_words[i-1], pattern);
    occurrence_in_string[i] = count(fib_words[i], pattern);
    // cout<<"fib "<<i-1<<" "<<fib_words[i-1]<<" "<<occurrence_in_string[i-1]<<"\n";
    // cout<<"fib "<<i<<" "<<fib_words[i]<<" "<<occurrence_in_string[i]<<"\n";
    string x = fib_words[i].substr(0,length_p-1);
    string a = fib_words[i-1].substr(fib_words[i-1].size()-(length_p-1));
    string b = fib_words[i].substr(fib_words[i].size()-(length_p-1));
    mid_count[i%2] = count(a+x, pattern);
    mid_count[(i+1)%2] = count(b+x, pattern);
    // cout<<"x "<<x<<"\na "<<a<<"\nb "<<b<<"\n";
    // cout<<"mid count "<<i%2<<" "<<mid_count[i%2]<<"\n"<<"mid count "<<(i+1)%2<<" "<<mid_count[(i+1)%2]<<"\n";
    return count(n,pattern);
}

int main(){
    int test=0;
    // cin>>test;
    initiate();
    while(cin>>n){
        cin>>pattern;
        test++;
        cout<<"Case "<<test<<": "<<solve(n,pattern)<<"\n";
    }
    return 0;
}