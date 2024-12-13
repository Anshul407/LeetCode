class Solution {
public:
    bool isHappy(int n) {
        map<int,int>mp;
        mp[1]=1;
        for(int i=2;i<9;i++)mp[i]=0;
        mp[7]=1;

        while(n>=10){
            string x=to_string(n);
            int c=0;
            for(auto i:x){
                int cc=i-'0';
                c+=(cc*cc);
            }
            n=c;
        }
        return mp[n];
    }
};