class Solution {
public:
    bool canplace(vector<int>&pos,int cur,int m){
        int last=pos[0];
        for(int i=0;i<pos.size();i++){
            if(i==0){
                m--;
                continue;
            }
            else {
                if(pos[i]-last>=cur){
                    m--;
                    last=pos[i];
                }
            }
            if(m==0)return 1;
        }
        return 0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int i=1;
        int j=position.back()-position[0];
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(canplace(position,mid,m)){
                ans=mid;
                i=mid+1;
            }else {
                j=mid-1;
            }
        }
        return ans;
    }
    
};
