class Solution {
public:
    void turnleft(pair<pair<int,int>,char>&p){
         if(p.second=='N')
                p.second='W';
                else if(p.second=='S'){
                    p.second='E';
                }
                else if(p.second=='E'){
                     p.second='N';
                }
                else{
                   p.second='S';
                }
    }
    void turnright(pair<pair<int,int>,char>&p){
         if(p.second=='N')
                p.second='E';
                else if(p.second=='S'){
                    p.second='W';
                }
                else if(p.second=='E'){
                     p.second='S';
                }
                else{
                   p.second='N';
                }
    }
    bool isRobotBounded(string s) {
        pair<pair<int,int>,char>p;
        p.first.first=0;
        p.first.second=0;
        p.second='N';
        for(auto i:s){
            if(i=='G'){
                if(p.second=='N')
                p.first.second+=1;
                else if(p.second=='S'){
                    p.first.second-=1;
                }
                else if(p.second=='E'){
                     p.first.first+=1;
                }
                else{
                    p.first.first-=1;
                }
            }
            if(i=='L'){
                 turnleft(p);
            }
            if(i=='R'){
                 turnright(p);
            }
        }
        if(p.first.first==0&&p.first.second==0||p.second!='N')return 1;
        return 0;
    }
};