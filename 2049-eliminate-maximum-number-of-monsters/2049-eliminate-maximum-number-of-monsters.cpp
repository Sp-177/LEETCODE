class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time;
        for(int i=0;i<dist.size();i++){
            time.push_back((double)dist[i]/(double)speed[i]);
        }
        sort(time.begin(),time.end());
        int count=1;
        for(int i=1;i<dist.size();i++){
            if(time[i]<=i){break;}
            count++;
        }
        return count;
    }
};