class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int per=(arr.size()/4)+1;
        int x=1;
        for(int i=0;i<arr.size();i++){
            if(per==x){return arr[i];}
            else if(i<arr.size()){
                if(arr[i]==arr[i+1]){x++;}
                else{x=1;}
            }
        }
        return arr[0];
    }
};