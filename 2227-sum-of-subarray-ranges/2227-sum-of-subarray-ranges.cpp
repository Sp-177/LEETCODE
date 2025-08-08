#define ll long long 
class Solution {
public:
    ll sumMin(vector<int>& nums,int n){
        stack<ll>s1,s2;
        vector<ll>l(n),r(n);
        for(int i=0;i<n;i++){
            while(s1.size()&&nums[s1.top()]>nums[i])s1.pop();
            l[i]=(s1.size())?s1.top():-1;
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(s2.size()&&nums[s2.top()]>=nums[i])s2.pop();
            r[i]=(s2.size())?s2.top():n;
            s2.push(i);
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            ll left=i-l[i],right=r[i]-i;
            sum+=(nums[i]*left*right);
        }
        return sum;
    }
    ll sumMax(vector<int>& nums,int n){

        stack<ll>s1,s2;
        vector<ll>l(n),r(n);
        for(int i=0;i<n;i++){
            while(s1.size()&&nums[s1.top()]<nums[i])s1.pop();
            l[i]=(s1.size())?s1.top():-1;
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(s2.size()&&nums[s2.top()]<=nums[i])s2.pop();
            r[i]=(s2.size())?s2.top():n;
            s2.push(i);
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            ll left=i-l[i],right=r[i]-i;
            sum+=(nums[i]*left*right);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        return sumMax(nums,n)-sumMin(nums,n);
    }
};