class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre=INT_MIN;
        int num=-1;
        for(auto i:s){
             if(isdigit(i)){
                if(num==-1)num=0;
                num=(num*10)+(i-'0');
                continue;
             }
             else{
                if(num!=-1){
                    cout<<num<<" ";
                    if(num<=pre)return 0;
                    pre=num;
                    num=-1;
                }
             }
             

        }
        if(num!=-1&&num<=pre){
           return 0;
        }

        return 1;
    }
};