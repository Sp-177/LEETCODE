class Solution {
public:
  
bool recur(vector<int>& nums, int start, int end, int chance, int sum1, int sum2) {
    if (start == end) {
        if (chance) sum1 += nums[start];
        else sum2 += nums[start];
        return sum1 >= sum2;
    }
    if (chance) {
        bool a1 = recur(nums, start + 1, end, 0, sum1 + nums[start], sum2);
        bool a2 = recur(nums, start, end - 1, 0, sum1 + nums[end], sum2);
        return a1 || a2;
    } else {
        bool a1 = recur(nums, start + 1, end, 1, sum1, sum2 + nums[start]);
        bool a2 = recur(nums, start, end - 1, 1, sum1, sum2 + nums[end]);
        return a1 && a2;
    }
}

bool predictTheWinner(vector<int> nums) {
    return recur(nums, 0, nums.size() - 1, 1, 0, 0);
}

};