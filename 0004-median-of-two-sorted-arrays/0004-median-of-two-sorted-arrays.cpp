class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int size1=nums1.size();
        int size2=nums2.size();
        int median1=((size1+size2)/2) ;
        int median2=-1;
        if((size1+size2)%2==0){median1--;median2=median1+1;}
        int i=0,j=0,index=0,x=1;
        while(j+i<=size1+size2-1){
            if(index==median1){
                
                if(i<size1 && j<size2){
                    ans=(ans+min(nums1[i],nums2[j]))/x;
                }
                else if(i<size1){
                    ans=(ans+nums1[i])/x;
                }
                else if(j<size2){
                    ans=(ans+nums2[j])/x;
                }
                if(median2!=-1 ){
                    median1=median2;
                    median2=-1;
                    x++;
                }
                else{
                    break;
                }

            }
            if(i<size1 && j<size2 && nums1[i]<nums2[j]){i++;}
            else if(i<size1 && j<size2 && nums1[i]>nums2[j]){j++;}
            else if(j<size2){j++;}
            else{i++;}
            index++;
        }
        return ans;
    }
};