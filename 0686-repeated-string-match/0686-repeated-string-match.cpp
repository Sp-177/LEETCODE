class Solution {
public:
    vector<int>pi;
    void lps(string&str){
        int m=str.size();
        pi.resize(m,0);
        int b_ind=0;
        for(int i=1;i<str.size();i++){
            while(b_ind>0&&str[b_ind]!=str[i])b_ind=pi[b_ind-1];
            if(str[b_ind]==str[i]){ 
                pi[i]=b_ind+1;
                b_ind++;
            }
        }
    }
    bool check(string &a,int freq,string &b){
        string str="";
        for(int i=0;i<freq;i++)str+=a;
        int b_ind=0;
        for(int i=0;i<str.size();i++){
            if(b_ind==b.size())break;
            while(b_ind>0&&b[b_ind]!=str[i])b_ind=pi[b_ind-1];
            if(b[b_ind]==str[i])b_ind++;
        }
        return b_ind==b.size();
    }
    int repeatedStringMatch(string a, string b) {
        int n=a.size(),m=b.size();
        lps(b);
        int fq=(max(0,m-2)/n)+2;
        if(check(a,fq-1,b))return fq-1;
        if(check(a,fq,b))return fq;
        return -1;
    }
};