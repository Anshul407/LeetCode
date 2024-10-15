class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int p=-1;
        for(int i=0;i<strs.size()-1;i++){
            auto s1=strs[i];
            auto s2=strs[i+1];
            if(p==-1){
                p=min((int)s1.size(),(int)s2.size());
            }
            while(p>0&&s1.substr(0,p)!=s2.substr(0,p)){
                p--;
            }
            if(p<=0)return "";
        }
        return strs[0].substr(0,p);
    }
};