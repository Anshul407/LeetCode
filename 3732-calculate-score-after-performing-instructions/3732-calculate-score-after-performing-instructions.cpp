class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int i=0;
        long long ans=0;
        unordered_set<int>vis;
        while(i>=0&&i<values.size()&&vis.find(i)==vis.end()){
            vis.insert(i);
            auto cur=instructions[i];
            if(cur=="add")ans+=values[i],i++;
            else i+=values[i];
        }return ans;
    }
};