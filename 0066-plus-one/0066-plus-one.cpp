class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         long long ans=0;
        long long mod=1e9+7;
        if(digits.size()==1&&digits[0]==9){
            digits[0]=1;
            digits.push_back(0);
            return digits;
        }
        if(digits[digits.size()-1]!=9){
            digits[digits.size()-1]++;
            return digits;
        }
        else{
          int i=digits.size()-2;
          while(i>=0&&digits[i]==9){
              i--;
          }
          if(i<0){
              i++;
              digits[i]=1;
                for(int j=i+1;j<digits.size();j++){
              digits[j]=0;
          }
          digits.push_back(0);
          }
          else{
          
                        digits[i]++;

          for(int j=i+1;j<digits.size();j++){
              digits[j]=0;
          }
          }
        }
        return digits;
       
    }
};