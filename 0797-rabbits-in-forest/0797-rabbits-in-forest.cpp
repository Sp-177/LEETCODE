class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int ans=0;
        int n=answers.size();
        int i=0;
        while(i<n){
            int cnt=answers[i];
            while(cnt&&i+1<n&&answers[i]==answers[i+1]){
                i++;
                cnt--;
            }
            ans+=answers[i]+1;
            i++;
        }
        return ans;
    }
};