class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int num1=0;
        int num2=0;
        int num3=0;
        for(auto i:firstWord){
            num1=num1*10+(i-'a');
        }

         for(auto i:secondWord){
            num2=num2*10+(i-'a');
        }
         for(auto i:targetWord){
            num3=num3*10+(i-'a');
        }

        return num1+num2==num3;


        
    }
};