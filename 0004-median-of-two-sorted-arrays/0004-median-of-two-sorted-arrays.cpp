class Solution {
public:
    double find(vector<int>&a,vector<int>&b){
        int n=a.size(),m=b.size();
        int total=n+m;
        int half=(total+1)>>1;
        int left=0,right=m;
        int a1=0,a2=0;
        while(left<=right){
            int part=(left+right)>>1;
            int num_elem_left_first=part;
            int num_elem_left_second=half-num_elem_left_first;
            int index2=num_elem_left_second-1;
            int l1=(part-1>=0)?b[part-1]:INT_MIN,l2=index2>=0?a[index2]:INT_MIN;
            int r1=(part<m)?b[part]:INT_MAX,r2=(index2+1<n)?a[index2+1]:INT_MAX;
            // cout<<l1<<"     "<<r1<<endl<<l2<<"    "<<r2<<endl;
            if(l1<=r2&&l2<=r1){
                a1=max(l1,l2);
                a2=min(r1,r2);
                break;
            }
            else if(l1>r2){
                right=part-1;
            }   
            else{
                left=part+1;
            }
           
        }
        if(total&1)return a1;
        return (a1*1.0 +a2*1.0)/(2.0);

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()){
            return find(nums2,nums1);
        }
        return find(nums1,nums2);
    }
};