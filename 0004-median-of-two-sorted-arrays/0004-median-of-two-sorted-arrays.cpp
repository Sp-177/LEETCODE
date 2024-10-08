class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m)return findMedianSortedArrays(nums2,nums1);
        int low=0,high=n;
        double m1=0,m2=0;
        int total=(n+m)/2 +(n+m)%2;
        while(low<=high){
            int mid1=(low+high)/2,mid2=total-mid1;
            int l1=mid1-1<0?INT_MIN:nums1[mid1-1],r1=mid1==n?INT_MAX:nums1[mid1];
            int l2= mid2-1<0?INT_MIN:nums2[mid2-1],r2=mid2==m?INT_MAX:nums2[mid2];
            bool lhs=l1<=r2?true:false;
            bool rhs=l2<=r1?true:false;
            cout<<low<<"  "<<high<<endl;
            cout<<l1<<" "<<r1<<endl;
            cout<<l2<<" "<<r2<<endl;
            if(lhs&&rhs){
                m1=1.0*max(l1,l2);
                m2=1.0*min(r1,r2);
                break;
            }
            if(lhs){
                low=mid1+1;
            }
            else{
                high=mid1-1;
            }
        }
        if((n+m)&1)return m1;
        return (m1+m2)/2.0;
    }
};