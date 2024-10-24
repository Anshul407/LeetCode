class Solution {
public:
    vector<int>solve(string &num,int i,int cnt,int k,vector<long long>&ans){
        if(i>=num.size()){
            if(cnt>=num.size()&&k>=3){
                vector<int>res(ans.begin(),ans.end());
                return res;
            }
            return {};
        }
        for(int j=i;j<num.size();j++){
            if(num[i]=='0'&&j>i)break;
            string cur_s=num.substr(i,j-i+1);
            if(cur_s.length()>10||(cur_s.length()==10&&cur_s>"2147483647"))break;
            long long cur=stoi(cur_s);
            if(ans.empty()||ans.size()==1||ans.back()+ans[ans.size()-2]==cur){
                ans.push_back(cur);
                vector<int>cur_ans=solve(num,j+1,cnt+(j-i+1),k+1,ans);
                if(cur_ans.size())return cur_ans;
                ans.pop_back();
            }
           
        }
       
       
        return {};
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<long long>ans;
        int cnt=0;
        return solve(num,0,cnt,0,ans);
    }
};