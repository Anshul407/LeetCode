class Solution {
public:
    int minOperations(int n) {
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back((2 * i) + 1);
        }
        int mid=n/2;
       
        
      
        int pointer=(2 * mid) + 1;
        if(n%2==0)pointer--;
        int ans=0;
        for(int i=n-1;i>=mid;i--){
         
            ans+=(((2 * i) + 1)-pointer);
        }
        return ans;
    

    }
};