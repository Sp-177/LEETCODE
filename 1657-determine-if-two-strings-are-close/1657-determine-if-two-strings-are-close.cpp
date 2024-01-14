class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())return false;
        unordered_map<char,int>m_1;
        for(auto i:word1)m_1[i]++;
        vector<int>v_1;
        for(auto i:m_1)v_1.push_back(i.second);
        sort(v_1.begin(),v_1.end());
        unordered_map<char,int>m_2;
        for(auto i:word2){
            if(m_1.count(i)!=0)m_2[i]++;
        }
        vector<int>v_2;
        for(auto i:m_2){v_2.push_back(i.second);}
        sort(v_2.begin(),v_2.end());
        if(v_1.size()!=v_2.size())return false;
        for(int i=0;i<v_1.size();i++)if(v_1[i]!=v_2[i])return false;
        return true;
    }
};