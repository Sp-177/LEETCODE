class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // cout<<hand.size()<<endl;
        if(hand.size()%groupSize!=0){return false;}
        map<int,int>m;
        for(int i :hand){
            m[i]++;
        }
        int l=hand.size()/groupSize;
        // for(auto j:m){cout<<j.first<<' '<<j.second<<endl;}
        for(int i=0;i<(hand.size()/groupSize);i++){
            int it=m.begin()->first;
            // cout<<endl<<it<<endl;
            int len=0;
            if(m.size()<groupSize){return false;}
            for(auto j:m){
                if(len==groupSize){break;}
                
                if(len>0){
                    if(j.first!=it+1){
                        return false;
                    }
                    it=j.first;
                }
                m[j.first]--;
                if(m[j.first]==0){
                    m.erase(j.first);
                }
                len++;
            }l--;
        }
        return (l==0?true:false);
    }
};