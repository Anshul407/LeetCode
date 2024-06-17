class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto i:details){
            int age=0;
            int num1=i[11]-'0';
            int num2=i[12]-'0';
            age=(age*10)+num1;
            age=(age*10)+num2;
            if(age>60)ans++;
        }
        return ans;
    }
};