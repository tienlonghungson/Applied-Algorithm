#include<iostream>
#include<string>
#include<stack>
using namespace std;

int checkParenthesis(string input){
    stack<char> myStack;
    
    for(int i=0; i<input.length();i++){
        if (input[i]=='(') {
            myStack.push(input[i]);
        } else if (input[i]==')') {
            if (myStack.top()=='('){
                myStack.pop();
            } else {
                return 0;
            }
        } else if (input[i]=='[') {
            myStack.push(input[i]);
        } else if (input[i]==']') {
            if (myStack.top()=='[') {
                myStack.pop();
            } else {
                return 0;
            }
        } else if (input[i]=='{'){
            myStack.push(input[i]);
        } else {
            if (myStack.top()=='{') {
                myStack.pop();
            } else {
                return 0;
            }
        }
    }
    if(!myStack.empty()){
        return 0;
    }
    return 1;
}

int main(){
    int n;
    string input;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>input;
        cout<<checkParenthesis(input)<<"\n";
    }
    return 0;
}