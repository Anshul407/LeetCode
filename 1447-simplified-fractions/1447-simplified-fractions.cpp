class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if((j%i!=0&&i%j!=0)||j==1){
                    string a=to_string(i);
                    string b=to_string(j);
                    b+="/";
                    b+=a;
                    ans.push_back(b);
                }
            }
        }
        return ans;
    }
};