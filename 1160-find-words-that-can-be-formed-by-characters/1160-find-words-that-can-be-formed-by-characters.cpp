class Solution {
    private: 
    int func(string &word,unordered_map<char,int>&map){
        int s=word.size();
        for(int i=0;i<s;i++){
            if(map[word[i]]<count(word.begin(),word.end(),word[i])){return 0;}
        }
        return s;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int>map;
        for(int i=0;i<chars.size();i++){
            map[chars[i]]++;
        }
        for(int i=0;i<words.size();i++){
            ans+=func(words[i],map);
        }return ans;
    }
};