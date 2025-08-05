class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int pos=arr[mid]-mid-1;
            if(pos<k)low=mid+1;
            else high=mid-1;
            
        }
        return low+k;
    }
};