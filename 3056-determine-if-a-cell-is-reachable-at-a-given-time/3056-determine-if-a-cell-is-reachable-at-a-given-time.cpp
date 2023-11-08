class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        int d=min(x,y);
        if(x+y-d==0){return t>1 ||t==0;}
        return (x+y-d)<=t;
    }
};