class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int i=0,j=0;
        int window=0;
        int ans=0;
        
        pair<int,int>p;
        p.first=-1;
        p.second=-1;
        int f=INT_MIN;

        while(i<grumpy.size()&&j<grumpy.size()){
           
            if(window<minutes){
                ans+=customers[j]*grumpy[j];
                window++;
                j++;
               
            }
         
            if(window==minutes){
               if(f<ans){
                f=ans;
               }
               
               ans-=customers[i]*grumpy[i];
               i++;
               
               window--;
            }
        }
        for(int i=0;i<grumpy.size();i++){
            f+=customers[i]*(1-grumpy[i]);
        }
        return f;

    }
};