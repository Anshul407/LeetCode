class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans="";
        int i=0,carry=0;
        while(i<min(num1.size(),num2.size())){
            auto x=num1[i]-'0';
            auto y=num2[i]-'0';
            auto num=x+y;
            num+=carry;
            ans+=to_string(num%10);
            carry=num/10;
            i++;
        }
        if(num1.size()>num2.size()){
            while(i<num1.size()){
            auto x=num1[i]-'0';
            auto num=x;
            num+=carry;
            ans+=to_string(num%10);
            carry=num/10;
            i++;
            }
        }
        if(num2.size()>num1.size()){
            while(i<num2.size()){
            auto x=num2[i]-'0';
            auto num=x;
            num+=carry;
            ans+=to_string(num%10);
            carry=num/10;
            i++;
            }
        }
        if(carry!=0)ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;

       
    }
};