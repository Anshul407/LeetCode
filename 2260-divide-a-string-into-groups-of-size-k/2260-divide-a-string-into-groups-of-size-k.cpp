class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp="";
        for(auto i:s){
            temp.push_back(i);
            if(temp.size()==k){
                ans.push_back(temp);
                temp="";
            }
        }
        if(temp!=""){
            while(temp.size()<k)temp.push_back(fill);
            ans.push_back(temp);
        }return ans;
    }
};