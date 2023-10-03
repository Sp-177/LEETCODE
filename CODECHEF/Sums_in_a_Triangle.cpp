#include <iostream>
using namespace std;
#include<vector>
#include<climits>
int solution(vector<vector<int>>&v,int r){
    for(int i=r-1;i>=0;i--){
            
            for(int j=r-1;j>=0;j--){
               if(i+1<=r-1){
                int t=INT_MIN;
                if(j+1<=i+1){
                    t=v[i+1][j+1];
                }
                v[i][j]+=max(t,v[i+1][j]);
               }
            }
        }
        int ans=v[0][0];
        v.clear();
        return ans;
}
int main() {
	int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int r;cin>>r;
        vector<vector<int>>v(r,vector<int>(r,0));
        for(int i=0;i<r;i++){
            v[i].resize(i+1);
            for(int j=0;j<i+1;j++){
                int t;cin>>t;
                v[i][j]=t;
            }
        }
        cout<<solution(v,r)<<endl;
    }
}
