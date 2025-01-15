class Solution {
public:
    string fractionAddition(string exp) {
        vector<int> n, d;
        int flag=0;
        int i=0;
        while(i<exp.size()) {
            if(exp[i]=='-'||exp[i]=='+'||exp[i]=='/'){
                i++;
               continue;
            }
            else{
                cout<<exp[i]<<" ";
                int j=i;
                while(j<exp.size()&&exp[j]!='/')j++;
                int t=1;
                if(i>0&&exp[i-1]=='-')t=-1;
                n.push_back(t*stoi(exp.substr(i,j-i)));
                i=j+1;
                while(j<exp.size()&&exp[j]!='+'&&exp[j]!='-')j++;
                d.push_back(stoi(exp.substr(i,j-i)));
                
                i=j;
            }

        }
        int td = 1, tn = 0;
        for (int a : d)
            td *= a;
        for (int i = 0; i < n.size(); i++) {
            int m = td / d[i];
            
            tn =(tn+n[i] * m);
        }
        int g = gcd(tn, td);
        tn /= g;
        td /= g;
        return to_string(tn) + "/" + to_string(td);
    }
};