class Solution {
public:
    int distributeCandies(vector<int>& candies) {
         unordered_set<int>s;
   int n=candies.size();
   for(int i:candies)s.insert(i);
   int size=s.size();
   return min(size,n/2);
    }
};