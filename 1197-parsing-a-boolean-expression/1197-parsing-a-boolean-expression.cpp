class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char>st1,st2;
        for(auto i:exp){
            if(i==',')continue;
            else if(i=='|')st1.push('|');
            else if(i=='!')st1.push('!');
            else if(i=='&')st1.push('&');
            else if(i=='(')st2.push('(');
            else if(i=='t')st2.push('t');
            else if(i=='f')st2.push('f');
            else if(i==')'){
                bool ans=st2.top()=='f'?false:true;
                st2.pop();
                if(st1.size()&&st1.top()=='!')ans=!ans;
                while(st2.size()&& (st2.top()!='(') && st1.size()){
                    // cout<<st2.size()<<" "<<st1.size()<<endl;
                    bool b=st2.top()=='t'?true:false;
                    if(st1.top()=='|'){
                        ans=ans||b;
                    }
                    else if(st1.top()=='&'){
                        ans=ans&&b;
                    }
                    st2.pop();
                }
                if(st2.size())st2.pop();
                st2.push((ans?'t':'f'));
                st1.pop();
            }

        }
        return ((st2.top()=='t')?true:false);

    }
};