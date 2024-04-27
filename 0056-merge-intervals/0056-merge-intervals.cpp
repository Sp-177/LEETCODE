class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&arr) {
        sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	int start=arr[0][0],end=arr[0][1];
	ans.push_back({start,end});
	for(int i=1;i<arr.size();i++){
		if(arr[i][0]<=end){
			if(arr[i][1]>end){
				end=arr[i][1];
				ans.back()[1]=end;
			}
		}
		else{
			start=arr[i][0];
			end=arr[i][1];
			ans.push_back({start,end});
		}
	}
	return ans;
    }
};