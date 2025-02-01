class Solution {
public:
    unordered_set<int>vis;
    bool isHappy(int n) {
        if(n==1)return 1;
        if(vis.find(n)!=vis.end())return 0;
        vis.insert(n);
        auto x=to_string(n);
        int p=0;
        for(auto i:x){
            auto k=i-'0';
            p+=(k*k);
        }return isHappy(p);
    }
};