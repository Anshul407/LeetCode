class Solution {
public:
    unordered_set<int>vis;
    bool isHappy(int n) {
        if(n==1)return 1;
        if(vis.find(n)!=vis.end())return 0;
        vis.insert(n);
        auto x=to_string(n);
        int p=0;
        int i=0,j=x.size()-1;
        
        while(i<=j){
            int a=x[i]-'0';
            int b=x[j]-'0';
            p+=(a*a);
            if(i!=j)
            p+=(b*b);
            i++;
            j--;   
        }
        return isHappy(p);
    }
};