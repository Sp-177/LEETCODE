class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>m;
        int i=0,j=0,n=fruits.size(),ans=0;
        while(i<n&&j<n){
            m[fruits[j]]++;
            if(m.size()>2){
                while(m.size()>2){
                    m[fruits[i]]--;
                    if(m[fruits[i]]<=0){m.erase(fruits[i]);}
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};