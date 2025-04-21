class Solution {
public:
    int minimumLines(vector<vector<int>>& st) {
        if(st.size()==1)return 0;
        sort(st.begin(),st.end());
        int x1=st[0][0];
        int y1=st[0][1];
        int x2=st[1][0];
        int y2=st[1][1];
        long long dx=x2-x1;
        long long dy=y2-y1;
        int ans=1;
        for(int i=2;i<st.size();i++){
            long long dxx=st[i][0]-st[i-1][0];
            long long dyy=st[i][1]-st[i-1][1];
            if(dxx*dy!=dyy*dx){
                ans++;
                dx=dxx;
                dy=dyy;
            }
        }return ans;
    }
};