class Solution {
public:
    int nextGreaterElement(int N) {
        string str=to_string(N);
        int n=str.size();
        int index=-1;
        
        for(int i=n-1;i>=1;i--){
            if(str[i-1]<str[i]){
                index=i-1;
                int mini=i;
                
                for(int j=i;j<n;j++){
                    int num=str[j]-'0';
                    int m=str[mini]-'0';
                    if(m>num && num>(str[index]-'0'))mini=j;
                }
                swap(str[index],str[mini]);
                sort(str.begin()+index+1,str.end());
                break;
            }
        }
        long long ans=stoll(str);
        
        if(index==-1||ans>INT_MAX)return -1;
        return ans;

    }
};