class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n=nums.size();
	int product=1;
	int ans=INT_MIN;
	for(auto i:nums){
		product=product*i;
		
		ans=max(product,ans);
		if(product==0)product=1;

	}
	product=1;
	for(int i=n-1;i>=0;i--){
		product=product*nums[i];
		
		ans=max(product,ans);
		if(product==0)product=1;

	}	return ans;

    }
};