class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
   vector<int>l(n,0);
   vector<int>r(n,n-1);
   stack<int>s;
   s.push(0);
   for(int i=1;i<n;i++){
     int t=0;
     while(!s.empty()){
       if(heights[i]<=heights[s.top()])s.pop();
       else break;
     }
    if(s.empty())t=-1;
    else t=s.top();
     l[i]=t+1;
     s.push(i);
   }
   s=stack<int>();
   s.push(n-1);
   for(int i=n-2;i>=0;i--){
     int t=n-1;
     while(!s.empty()){
       if(heights[i]<=heights[s.top()])s.pop();
       else break;
     }
    if(s.empty())t=n;
    else t=s.top();
     r[i]=t-1;
     s.push(i);
   }
   int ans=0;
   for(int i=0;i<n;i++)ans=max(ans,(r[i]-l[i]+1)*heights[i]);
   return ans;
    }
};