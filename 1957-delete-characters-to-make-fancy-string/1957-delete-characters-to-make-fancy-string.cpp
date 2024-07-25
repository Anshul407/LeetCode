class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int cnt=0;
        char cur='$';
        for(auto i:s){
            if(cur!=i){
                cur=i;
                ans.push_back(i);
                cnt=1;
            }else{
                if(cnt==2)continue;
                if(i==cur){
                    cnt++;
                    ans.push_back(i);

                }
            }
        }
        return ans;
    }
};