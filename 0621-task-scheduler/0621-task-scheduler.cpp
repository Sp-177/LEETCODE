class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char t : tasks) freq[t - 'A']++;

        int f_max = *max_element(freq, freq + 26);
        int max_count = count(freq, freq + 26, f_max);

        int part_count = f_max - 1;
        int part_length = n + 1;
        int empty_slots = part_count * part_length + max_count;

        return max((int)tasks.size(), empty_slots);
    }
};
