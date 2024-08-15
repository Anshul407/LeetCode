class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       
        int f=0,t=0,tw=0;
        for(auto i:bills){
            if(i==5){
                f++;
            }
            else if(i==10){
                t++;
                if(f)f--;
                else return 0;
            }else{
                tw++;
                if(t&&f){
                    t--;
                    f--;
                }
                
                else if(!t&&f>=3){
                    f-=3;
                }
                else return 0;

            }
        }
        return 1;
    }
};