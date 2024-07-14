class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five=0,ten=0,tt=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){five++;}
            else if(bills[i]==10&&five){five--;ten++;}
            else if(bills[i]==20&&(five>=3||(five>=1&&ten>=1))){if(ten){ten--;five--;}else{five-=3;};tt++;}
            else{return false;}
            
        }
        return true;
    }
};