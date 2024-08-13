class Solution {
public:
    bool solve(int x,int y,bool a){

        
            if(!x)return !a;
            
            if(y<4)return !a;

            return solve(x-1,y-4,!a);  
        

    }
    string losingPlayer(int x, int y) {
        bool a=solve(x,y,true);
        if(a)return "Alice";
        return "Bob";
    }
};