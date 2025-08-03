class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gS) {
        int n=hand.size();
        if(n%gS!=0)return 0;
        map<int,int>freq;
        for(int i:hand)freq[i]++;
        int tg=n/gS;
        for(int i=0;i<tg;i++){
            int cnt=0,last=-1;
            for(auto i:freq){
                if(cnt==gS)break;
                int curr=i.first;
                if(last!=-1&& (curr-last)!=1)return false;
                freq[curr]--;
                if(freq[curr]==0)freq.erase(curr);
                cnt++;
                last=curr;
            }
            if(cnt!=gS)return false;
        }
        return true;
    }
};