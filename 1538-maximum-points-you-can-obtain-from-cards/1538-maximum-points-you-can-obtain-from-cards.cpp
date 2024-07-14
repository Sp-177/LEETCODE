class Solution {
public:
    int maxScore(vector<int>& cP, int k) {
        int n=cP.size();
        int start=n-1,end=n-k,sum=0;
        for(int i=end;i<n;i++){
            sum+=cP[i];
        }
        int s=sum;
        while(end<n){
            start++;
            s+=cP[start%n];
            s-=cP[end%n];
            end++;
            
            // cout<<s<<' '<<start%n<<' '<<end%n<<endl;
            
            
            sum=max(sum,s);
        }
        return sum;
    }
};