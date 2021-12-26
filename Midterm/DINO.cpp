#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

const int MAX_DINO = 1e5+1;
int N;
int a[MAX_DINO];
string command_light;
stack<int> chuong;
queue<int> hanh_lang;

void DINO(){
    int num_command = (int)command_light.length();
//    char command;
//    int temp=0;
    for (int i=0;i<num_command;++i){
//        cout<<command_light[i]<<"\n";
        if (command_light[i]=='C') {
//            temp= chuong.top();
            if (!chuong.empty()){
//                cout<<"chuong "<< chuong.top()<<" to hanhlang\n";
                hanh_lang.push(chuong.top());
                chuong.pop();
            }
        } else {
            if (!hanh_lang.empty()) {
//                cout<<"hanh lang "<<hanh_lang.front()<<" to chuong\n";
                chuong.push(hanh_lang.front());
                hanh_lang.pop();
            }
        }
    }
}

int main(){
    cin>>N;
    for (int i=1;i<=N;++i){
        cin>>a[i];
//        chuong.push(a[i]);
    }
    for (int i=N;i>=1;--i){
        chuong.push(a[i]);
    }
    cin>>command_light;
    
    DINO();
    
    while (!chuong.empty()) {
        cout<<chuong.top()<<" ";
        chuong.pop();
    }
    return 0;
}
