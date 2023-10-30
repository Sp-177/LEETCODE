class Solution {
public:
    static int def(int n){
        if(n==0){return 0;}
        if(n<3){return 1;}
        if(n==3){return 2;}
        if(n%2==0){return def(n/2);}
        else{return def(n/2)+1;}
    }
    static bool cmp(int a,int b){
        int x=def(a),y=def(b);
        if(x<y){
            return true;
        }
        else if(x==y){
            return a<b;
        }
        return false;
    }

    vector<int> sortByBits(vector<int>& arr) {
       
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};