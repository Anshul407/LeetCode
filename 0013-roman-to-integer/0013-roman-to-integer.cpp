class Solution {
   
public:
     int dig(char c){
        int xx;
        if(c=='I') xx=1;
        else if(c=='V') xx=5;
        else if(c=='X') xx= 10;
        else if(c=='L') xx=50;
        else if(c=='C')xx=100;
        else if(c=='D') xx=500;
        else if(c=='M') xx= 1000;
        return xx;
    }
    
    int romanToInt(string s) {
        int x=0;
        int i;
        int cnt=0;
        int n=s.length();
        if(n==1)return dig(s[0]);
        for(i=0;i<s.length()-1;i++){
    
            if(s[i]=='I'&&s[i+1]=='V')x+=4;
            else if(s[i]=='I'&&s[i+1]=='X'){x+=9;}
            else if(s[i]=='X'&&s[i+1]=='L'){
            x+=40;
            i++;
           }
              else if(s[i]=='X'&&s[i+1]=='C'){x+=90;
              i++;
              }

             else if(s[i]=='C'&&s[i+1]=='D'){x+=400;
             i++;
             }
             else if(s[i]=='C'&&s[i+1]=='M'){x+=900;
             i=i+1;
             }
             else if(s[i]=='D')x+=500;
            else if(s[i]=='M') {
                x+=1000;
            }
            else if(s[i]=='C')x+=100;
            else if(s[i]=='I')x+=1;
            else if(s[i]=='V')x+=5;
              else if(s[i]=='X')x+=10;
            else if(s[i]=='L')x+=50;
            cnt++;
          

        }
        if((s[n-1]=='V'&&s[n-2]=='I')||(s[n-1]=='X'&&s[n-2]=='I')||(s[n-1]=='L'&&s[n-2]=='X')||(s[n-1]=='C'&&s[n-2]=='X')||(s[n-1]=='D'&&s[n-2]=='C')||(s[n-1]=='M'&&s[n-2]=='C'))return x;
       
       return x+dig(s[n-1]);
        
    }
};