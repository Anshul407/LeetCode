class Solution {
public:
    vector<int>ans;
    void solve(int low,int high,int cur,int p){
        if(cur>high)return ;
        if(cur>=low&&cur<=high)ans.push_back(cur);
        for(int i=1;i<=9;i++){
            if(p==-1)solve(low,high,i,i);
            else if(i==p+1)solve(low,high,cur*10+i,i);  
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        solve(low,high,0,-1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};