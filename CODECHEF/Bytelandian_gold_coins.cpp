#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution(int n){
    vector<int>V(n+1,0);
    for(int i=1;i<n+1;i++){
        V[i]=max(i,V[i/2]+V[i/3]+V[i/4]);
    }
    int ans=V[n];
    V.clear();
    return ans;
}
int main() {
    while(true){
    int r=0;cin>>r;
    if(r==0){return 0;}
    cout<<solution(r)<<endl;}
	return 0;
}
