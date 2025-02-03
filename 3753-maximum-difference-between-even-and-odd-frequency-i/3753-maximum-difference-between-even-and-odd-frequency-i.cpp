class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(auto i:s)mp[i]++;
        int em=INT_MAX,ex=INT_MIN,om=INT_MAX,ox=INT_MIN;
        for(auto i:mp){
            if(i.second%2==0){
                em=min(em,i.second);
                ex=max(ex,i.second);
            }else{
                om=min(om,i.second);
                ox=max(ox,i.second);
            }
        }

        return max(ox-em,om-ex);

    }
};