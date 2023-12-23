class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_set<int>>map;
        map[0].insert(0);
        int x=0,y=0;
        for(auto i:path){
            if(i=='N')y++;
            else if(i=='S')y--;
            else if(i=='E')x++;
            else if(i=='W')x--;
            //cout<<x<<y<<endl;
            if(map[x].count(y)!=0){return true;}
            map[x].insert(y);
        }
        return false;
    }
};