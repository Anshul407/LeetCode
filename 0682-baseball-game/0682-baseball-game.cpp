#include <string>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>ans;
        for(auto i:operations){
            if(i=="C"){
                if(!ans.empty())ans.pop_back();
            }
            else if(i=="D"){
                if(!ans.empty()){
                    ans.push_back(ans.back()*2);
                }
            }
           else  if(i=="+"){
                if(ans.size()>1){
                    int num=ans.back()+ans[ans.size()-2];
                    ans.push_back(num);
                }
            }else{
                int x=stoi(i);
                ans.push_back(x);
            }
        }
        int sum=0;
        for(auto i:ans){
            sum+=i;
        }
        return sum;
    }
};