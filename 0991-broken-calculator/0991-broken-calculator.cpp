class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(true){
                        if(target==startValue)break;

            ans++;
            if(target%2==0&&startValue<target){
                    target/=2;
            }
            else{
                target++;
            }
        }
        return ans;

    }
};