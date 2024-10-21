class Solution {
public:
    int n;
    string solve(map<string,int>&mp,string &temp){
        if(temp.size()==n){
            if(mp.find(temp)==mp.end())return temp;
            return "";
        }
        temp.push_back('0');
        string op1=solve(mp,temp);
        if(op1.size()==n)return op1;
        temp.pop_back();
        temp.push_back('1');
        string op2=solve(mp,temp);
        temp.pop_back();
        return op2;

    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>mp;
        n=nums[0].size();
        for(auto i:nums){
            mp[i]++;
        }
        string temp="";
       return solve(mp,temp);
    }
};