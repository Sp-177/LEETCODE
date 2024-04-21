class Solution {
public:
    void nextPermutation(vector<int>& A) {
         bool f=false;
    int index=0;
    for(int i=A.size()-1;i>=1;i--){
      if(A[i]>A[i-1]){
          index=i-1;
          f=true;
          break;
      }
    }
    // cout<<index<<endl;
   
    if (f) {
         int least_max=INT_MAX,index1=index+1;
        for(int i=index+1;i<A.size();i++){
          if (A[i] > A[index]) {
            least_max = min(least_max, A[i]);
            index1 = (least_max == A[i]) ? i : index1;
          }
      }
    //   cout<<index<<index1<<endl;
        swap(A[index],A[index1]);
        sort(A.begin()+index+1,A.end());
    }
    else{
        sort(A.begin(),A.end());
    }}
    
};