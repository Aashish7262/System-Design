#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
class Parent{
    public:
    void solve(string s){
            cout<<s<<endl;
    }
};
class Child : public Parent{
    public:
    void solve(string s){
            cout<<s<<endl;
    }
};
int main(){
    Child c;
    c.solve("Hello from Child");
    return 0;
}