class Solution {
public:
    bool ans(vector<int>&time,long long mid,int &tot){
        long long x=0;
        for(auto &i:time){
            x+=(mid/i);
        }
        return x>=tot;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
       long long j = (long long) *min_element(begin(time), end(time)) * totalTrips;
        long long i=1;
       
        while(i<j){
            long long mid=i+(j-i)/2;

            if(ans(time,mid,totalTrips)){
                j=mid;
            }else{
                i=mid+1;
            }
        }
        return i;
        
    }
};