class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=num;i>=0;i--){
            int n=i;
            string x=to_string(n);
            reverse(x.begin(),x.end());
            int newn=stoi(x);

            if(n+newn==num)return 1;
        }
        return 0;
    }
};