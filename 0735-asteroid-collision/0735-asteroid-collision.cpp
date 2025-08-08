class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        int n=a.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(a[i]<0)st.push(a[i]);
            else{
            while(st.size()&& abs(st.top())<a[i])st.pop();

            if(st.size()&&abs(st.top())==a[i]){
                st.pop();
                continue;
            }
            else if(st.size()==0)ans.push_back(a[i]);
            }

        }
        vector<int>l;
        while(st.size()){
            l.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        l.insert(l.end(),ans.begin(),ans.end());
        return l;
    }
};