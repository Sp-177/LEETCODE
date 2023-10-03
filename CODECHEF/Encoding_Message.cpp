#include<iostream>
#include<string>
using namespace std;
string solution(string &s){
    int i=0;
    while(i!=s.size()){
       
        if(i%2==0 && i<=s.size()-2){
        swap(s[i],s[i+1]);}
        s[i]=char(122-s[i]+97);
        i++;
    }
    return s;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int r;cin>>r;
        string s;
        cin>>s;
        cout<<solution(s)<<endl;
    }
}