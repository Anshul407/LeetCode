class Solution {
public:
    string convertbin(int num){
        string x="";
        while(num){
            int n=num%2;
            n=!n;
            x+=to_string(n);
            num/=2;
        }
        
       
        return x;

    }
    int convertnum(string s){
        int num=0;
        int cnt=0;
        for(auto i:s){
            num+=pow(2,cnt)*(i-'0');
            cnt++;
        }
        return num;
    }
    int findComplement(int num) {
        string x =convertbin(num);
        cout<<x;
        return convertnum(x);
      
    }
};