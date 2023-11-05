class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int x=0;
        int y=arr[0];
        for(int i=1;i<arr.size();i++){
           if(y<arr[i]){
               y=arr[i];
               x=1;
           }
           else{
               x++;
           }
           if(x==k){
               return y;
           }
        }
        return y;
    }
};