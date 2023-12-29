class Solution {
public:
    int minInsertions(string &s)
    {
	string s2;
	for(int i=0;i<s.size();i++)s2=s[i]+s2;
	vector<int>prev(s.size()+1,0);vector<int>curr(s.size()+1,0);
	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=s.size();j++){
			if(s[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
			else curr[j]=max(prev[j],curr[j-1]);
		}
        prev=curr;
	}
	return s.size()-prev[s.size()];
    }
};