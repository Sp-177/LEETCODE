class Solution {
public:
    int split_check(vector<int>&a,int i,int j){
    // cout<<i<<j<<endl;
    if(i==j)return 0;
    int mid=(i+j)/2;
    int x=split_check(a,i, mid);
    int y=split_check(a, mid+1,  j);
    int ans=0;
    int start1=i,start2=mid+1;
    while(start1<mid+1&&start2<=j){
        long long c=a[start2];
        c+=a[start2];
        if(a[start1]>c){
            ans+=mid-start1+1;
            start2++;
        }
        else start1++;
    }
    vector<int>new_a;
    start1=i,start2=mid+1;
    while(start1<mid+1&&start2<=j){
        if(a[start1]<=a[start2]){
            new_a.push_back(a[start1]);
            start1++;
        }
        else{
           new_a.push_back(a[start2]);
            start2++;
        }
    }
    while(start1<mid+1)new_a.push_back(a[start1++]);
    while(start2<=j)new_a.push_back(a[start2++]);
    int w=0;
    for (int z = i; z <= j; z++) {
        a[z]=new_a[w++];
    }
    return ans+x+y;
}
    int reversePairs(vector<int>& nums) {
        return split_check(nums,0,nums.size()-1);
    }
};