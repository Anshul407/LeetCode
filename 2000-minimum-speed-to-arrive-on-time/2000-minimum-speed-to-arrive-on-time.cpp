class Solution {
public:
    bool canpossible(vector<int>&d,int speed,double hour){
        auto sp=speed/1.0;
        auto tot=0.0;
        auto prev=-1;
        for(int i=0;i<d.size();i++){
            if(prev==-1){
               tot+=(d[i]/sp);
               prev=0;
            }else{
                tot=ceil(tot);
                tot+=(d[i]/sp);
            }

            if(tot>hour)return 0;
        }
        return 1;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int i=1;
        int j=1e9;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(canpossible(dist,mid,hour)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        return ans;
    }
};