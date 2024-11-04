class Solution {
public:
    int compress(vector<char>& chars) {
       int i=0;
       vector<char>ans;
       while(i<chars.size()){
          auto c=chars[i];
          int cnt=0;
          while(i<chars.size()&&chars[i]==c){i++;cnt++;}
          string s=to_string(cnt);
          if(cnt==1)ans.push_back(c);
          else {
            ans.push_back(c);
            for(auto ii:s){
                ans.push_back(ii);
            }
          }

       }
       int j=0;
       for(auto &i:chars){
        if(j>=ans.size())break;
        i=ans[j++];
       }
       return ans.size();
    }
};