class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int>m;
        for(auto i:wordList){
            m[i]=1;
        }
        if(m[endWord]==0){return 0;}
        m[beginWord]=-1;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int lvl=q.front().second;
            q.pop();
            
            for(int i=0;i<s.size();i++){
                string temp=s;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(m[temp]==1){
                        if(temp==endWord){return lvl+1;}
                        m[temp]=-1;
                        q.push({temp,lvl+1});
                    }
                }
            }
        }
        return 0;
    }
};