class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n2>n1)return findMedianSortedArrays(nums2,nums1);
        int want=(n1+n2)/2;
        int low=want-n2,high=min(want,n1);
        int l=-1,r=-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int num1=mid;
            int num2=want-num1;
            int ind1=mid-1,ind2=num2-1;
            // cout<<ind1<<" "<<ind2<<endl;
            double l1=(ind1<0?INT_MIN:nums1[ind1]);
            double r1=(ind1+1>=n1?INT_MAX:nums1[ind1+1]);
            double l2=(ind2<0?INT_MIN:nums2[ind2]);
            double r2=(ind2+1>=n2?INT_MAX:nums2[ind2+1]);
            // cout<<l1<<" , "<<r1 <<" "<<l2<<" , "<<r2<<endl;
            if(l1<=r2&&l2<=r1){
                l=max(l1,l2);
                r=min(r1,r2);
                break;
            }
            if(l1>r2)high=mid-1;
            else low=mid+1;
        }
        if((n1+n2)&1)return r;
        return (l+r)/2.0;
    }
};