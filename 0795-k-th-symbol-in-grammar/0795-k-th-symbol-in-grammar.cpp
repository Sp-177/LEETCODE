class Solution {
public:
    int help(int n,int k,int x,int p,int c){
        if(n==0){return p;}
        if(p==0){
            if(k<=(x+c)/2){
               return help(n-1,k,(x+c)/2,0,c);
            }
            else{
               return help(n-1,k,x,1,(x+c)/2);
            }
        }
        else{
            if(k<=(x+c)/2){
               return help(n-1,k,(x+c)/2,1,c);
            }
            else{
                return help(n-1,k,x,0,(x+c)/2);
            }
        }


    }
    int kthGrammar(int n, int k) {
        return help(n-1,k,pow(2,n-1),0,1);
    }
};