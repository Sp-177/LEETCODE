class Solution {
public:
    string largestGoodInteger(string num) {
     string ans="";
     int a=-1;
     for(int i=2;i<num.size();i++){
         if(num[i-2]==num[i]&& num[i]==num[i-1] && a<(num[i]-'0'))
         {
             a=num[i]-'0';
         }
      }if(a!=-1){
          ans=to_string(a);
          ans=ans+ans+ans;
      }
      return ans;
    }
};