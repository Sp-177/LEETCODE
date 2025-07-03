class Solution {
public:
    string pp(string&s){
        string t="^";
        for(auto i:s){
            t+="#";
            t+=i;
        }
        t+="#$";
        return t;
    }
    string longestPalindrome(string s) {
        string temp=pp(s);
        int n=temp.size();
        vector<int>p(n,0);
        int c=0,r=0;
        for(int i=1;i<n-1;i++){
            int m=2*c-i;
            if(i<r){
                p[i]=min(r-i,p[m]);
            }
            while(temp[i+p[i]+1]==temp[i-p[i]-1])p[i]++;
            
            if(i+p[i]>r)c=i,r=i+p[i];
        }
        int maxi=*max_element(p.begin(),p.end());
        string ans="";
        for(auto i:p)cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
            if(maxi==p[i]){
                int start=(i-maxi)/2;
                ans=s.substr(start,maxi);
                break;
            }
        }
        return ans;

    }
};