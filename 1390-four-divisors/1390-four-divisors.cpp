class Solution {
public:
    int find(int num){
       
       
            int c=0;
            int sum=0;
            for(int j=1;j*j<=num;j++){
                if(num%j==0){
               if(num/j!=j){
                      c+=2;
                    sum+=j;
                    sum+=num/j;
               }
               else{
                   c+=1;
                   sum+=j;
               }}}
        if(c==4)return sum;
        return 0;
        
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            int curans=find(i);
           
            sum+=curans;
        }
        return sum;
    }
};