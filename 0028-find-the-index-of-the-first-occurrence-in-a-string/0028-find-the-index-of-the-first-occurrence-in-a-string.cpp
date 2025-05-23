class Solution {
public:
    vector<int>pi;
    void lps(string&str){
        int n=str.size();
        pi.resize(n,0);
        int pre=0;
        for(int suf=1;suf<n;suf++){
            while(pre>0&&str[pre]!=str[suf]){
                pre=pi[pre-1];
            }
            if(str[pre]==str[suf]){pi[suf]=pre+1;pre++;}
        
        }

    }
    int strStr(string h, string ne) {
    int n=h.size(),m=ne.size();
    if(m>n)return -1;
    lps(ne);
    int ne_ind=0;
    for(int i=0;i<n;i++){
        if(ne_ind==m)return i-m;
        while(ne_ind>0&&ne[ne_ind]!=h[i]){
            ne_ind=pi[ne_ind-1];
        }
        if(ne[ne_ind]==h[i]){
            ne_ind++;
        }
    }
    if(ne_ind==m)return n-m;
    return -1;    
    }
};