class Solution {
public:
    int maximumScore(int a, int b, int c) {
        long long ans=0;
    while((a!=0&&b!=0)||(b!=0&&c!=0)||(c!=0&&a!=0)){
        int x=max(a,max(b,c));
        int y=(x==a)?max(b,c):x==b?max(a,c):max(a,b);
        int t=(x==a)?a--:x==b?b--:c--;
        t=(y==a)?a--:y==b?b--:c--;
     ans++;
        
    }
    return ans;
    }
};