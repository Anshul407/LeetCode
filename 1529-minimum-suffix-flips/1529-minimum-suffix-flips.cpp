class Solution {
public:
    int minFlips(string target) {
        int cnt=0;
        int flag=0;
        int index=-1;
        //to find 1st set bit
        for(int i=0;i<target.length();i++){
              if(target[i]=='1'){
                index=i;
                break;
              }
        }
        //if set bet is not present return 0
        if(index==-1)return 0;

        //logic--just count continous group of 1s and 0s
        for(int i=index;i<target.length();i++){
             if(flag&&target[i]=='1')continue;
            if(target[i]=='1'){
                cnt++;
                flag=1;
            }else
            flag=0;
        }
        flag=0;
      
        for(int i=index;i<target.length();i++ ){
            if(flag&&target[i]=='0')continue;
            if(target[i]=='0'){
                cnt++;
                flag=1;
            }else
            flag=0;

           
            
        }
        return cnt;
    }
};