class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=customers[0][0];
        
       double ans2=0;
        for(auto it:customers){
             if(ans<it[0]){
                ans=it[0];
             }
            ans+=it[1];
           
            ans2+=(ans-it[0]);
            
        }
        // double sum=0;
        // for(auto it:ans2){
        //    sum+=it;
        //    cout<<it<<" ";
        // }
        
        return ans2/customers.size();
    }
};