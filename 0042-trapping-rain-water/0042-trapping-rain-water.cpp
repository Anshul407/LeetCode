class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>l(height.size(),-1);
        vector<int>r(height.size(),-1);
        stack<pair<int,int>>st,st2;
        auto cur=0;
        for(int i=0;i<height.size();i++){
            cur=max(cur,height[i]);
            l[i]=max(l[i],cur);
        }
        cur=0;
        for(int i=height.size()-1;i>=0;i--){
            cur=max(cur,height[i]);
            r[i]=max(r[i],cur);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            if(l[i]==-1||r[i]==-1)continue;
            ans+=(min(l[i],r[i])-height[i]);
        }return ans;
    }
};