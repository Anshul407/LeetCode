class Solution {
public:
    int minFlips(string target) {
        int cnt=0;
        int flag=0;
        int index=-1;
        for(int i=0;i<target.length();i++){
              if(target[i]=='1'){
                index=i;
                break;
              }
        }
        for(int i=index;i<target.length();i++){
             if(flag&&target[i]=='1')continue;
            if(target[i]=='1'){
                cnt++;
                flag=1;
            }else
            flag=0;
        }
        flag=0;
        if(cnt==0)return 0;
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