#include <iostream>

using namespace std;
const int mod=1e9+7;
const int N=1001;
int res[N][N];
string s;
int cal_res(int i, int j, int len){
    if (j<0 || j>len){
        return 0;
    } else if (res[i][j]!=-1){
        return res[i][j];
    }
    if (s[i-1]=='?'){
        res[i][j]=(cal_res(i-1,j-1, len)+cal_res(i-1,j+1,len))%mod;
    } else if (s[i-1]=='('){
        res[i][j]=cal_res(i-1,j-1,len);
    } else if (s[i-1]==')'){
        res[i][j]=cal_res(i-1,j+1,len);
    }
    return res[i][j]%mod;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    int len = (int)s.length();
    for (int i=1;i<=len;++i){
        for (int j=0;j<=len;++j){
            res[i][j]=-1;
        }
    }
    res[0][0]=1;
    cout<<cal_res(len,0,len)<<"\n";
    return 0;
}