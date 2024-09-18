class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0)return 0;
        if(num<0)return 1e9;

        int ans=0;
        if(num%2==0){
            ans=1+ numberOfSteps(num/2);
        }else{
            ans=1+ numberOfSteps(num-1);
        }

        return ans;
    }
};