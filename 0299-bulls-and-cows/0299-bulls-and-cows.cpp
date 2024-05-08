class Solution {
public:
    string getHint(string secret, string guess) {
         vector<int>map(10,0);
        int bulls=0;
        for(int i=0;i<secret.size();i++){
            if(guess[i]!=secret[i])map[guess[i]-'0']++;
            else bulls++;
        }
        int cows=0;
        for(int i=0;i<secret.size();i++){
            if(guess[i]!=secret[i]){
                if(map[secret[i]-'0']>0){
                    cows++;
                    map[secret[i]-'0']--;
                }
            }
            
        }
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};