class Solution {
public:
    unordered_map<string,int> mp;
    int n;
    string func(string& a,string& b){
        return a.size()==0?b:a;
    }
    string solve(vector<string>& nums,string &s)
    {
        if(s.size()==n)
        {
            if(mp[s]==0)
            return s;
            else return "";
        }
        s+="0";
        string op1=solve(nums,s);
        if(op1.size()==n)return op1;
        s.pop_back();
        s+="1";
        string op2=solve(nums,s);
        s.pop_back();
       
        return op2; 
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto it:nums)
        mp[it]++;
        n=nums[0].size();
        vector<string> s{"0","1"};
        string temp="";
        return solve(s,temp);
    }
};