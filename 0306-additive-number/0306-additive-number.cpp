class Solution {
public:
    int solve(string num,int i,long long p,long long q,int cnt,int k){
        if(i>=num.size()){
            cout<<p<<" ";
            return cnt>=num.size()&&k>=3;
        }
        for(int j=i;j<num.size();j++){
            if(num[i]=='0'&&j>i)break;
            
            string cur_s=num.substr(i,j-i+1);
            if(cur_s.length()>19||(cur_s.length()==19&&cur_s>"9223372036854775807"))break;
            long long cur=stoll(cur_s);
            if(p==-1||q==-1||(p+q==cur&&p!=-1&&q!=-1)&&(to_string(cur).size()==j-i+1)){ 
                if(solve(num,j+1,cur,p,cnt+(j-i+1),k+1))return 1;
            }    
        }
        return 0;
    }
    bool isAdditiveNumber(string num) {
        return solve(num,0,-1,-1,0,0);
    }
};