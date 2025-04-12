class Solution {
public:
//1st Solution
// unordered_set<string>dp;
// unordered_set<string>dp2;
//     bool check3(string &s,int k){
//         unordered_map<int,int>mp;
//         for(auto &i:s)mp[i-'0']++;
//         if(k==1)return 1;
//         if(k==2){
//             for(auto &i:mp)if(i.first%2==0&&i.second>1&&i.first!=0)return 1;
//             return 0;
//         }if (k==3||k==9){
//             int cur=0;
//             for(auto &i:mp)cur+=(i.first*i.second);
//             return cur%k==0;
//         }
//         if(k==5)return mp[5]>1;
//         if(k==6){
//             int cur=0;
//             for(auto &i:mp)cur+=(i.first*i.second);
//             if(cur%3==0){
//                 for(auto &i:mp)if(i.first%2==0&&i.second>1&&i.first!=0)return 1;
//             }return 0;
//         }
//         return 0;
//     }
//    bool check2(string &s, int k){
//     unordered_map<int, int>mp;
//     for(char c:s)mp[c-'0']++;
//     string num=s;
//     sort(num.begin(),num.end());
//     auto temp=num; 
//     if(k==1||k==2||k==3||k==5||k==6||k==9){
//         if(check3(s,k)){
//             dp.insert(temp);
//             return 1;
//         }else {
//             dp2.insert(temp);
//             return 0;
//         }
//     }
//     do{
//         if(num[0]=='0')continue;
//         string rev=num;
//         reverse(rev.begin(),rev.end());
//         if(num != rev)continue; 
//         long long val=stoll(num);
//         if(val%k==0){
//             dp.insert(temp);
//             return 1;}
//     }while(next_permutation(num.begin(),num.end()));
//     dp2.insert(temp);
//     return  false;
// }

//     bool check(string &st,int k){
//         string temp=st;
//         sort(temp.begin(),temp.end());
//         unordered_map<int,int>mp;
//         for(auto &i:st)mp[i-'0']++;
//         int x=0;
//         int kk=0;
//         for(auto &i:mp){
//                 if(i.second%2==1)x++;
//                 if(x>1)break;
//         }
//         if(x>1){
//             dp2.insert(temp);
//             return 0;
//         }
//         if(mp[0]>1){
//             if(mp.size()==2&&st.size()%2!=0&&st.size()-mp[0]==1){
//             dp2.insert(temp);
//             return 0;}
//         }
        
//         return check2(st,k);  
//     }
//     long long solve(int n,int k,string &st){
//         if(st.size()==n){
//             auto temp=st;
//             sort(temp.begin(),temp.end());
//             if(dp.find(temp)!=dp.end())return 1;
//             if(dp2.find(temp)!=dp2.end())return 0;
//             return check(st,k);
//         }
//         long long ans=0;
//         for(char x='0';x<='9';x++){
//             if(st.empty()&&x=='0')continue;
//             st.push_back(x);
//             ans+=solve(n,k,st);
//             st.pop_back();
//         }return ans;
//     }

    long long countGoodIntegers(int n, int k) {
        unordered_set<string> sset;
        int power = pow(10, (n - 1) / 2);
        int skip = n % 2;

        for (int i = power; i < power * 10; ++i) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            s += rev.substr(skip);
            long long pal = stoll(s);
            if (pal % k == 0) {
                sort(s.begin(), s.end());
                sset.insert(s);
            }
        }

        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }

        long long res = 0;
        for (string s : sset) {
            vector<int> cnt(10, 0);
            for (char c : s) cnt[c - '0']++;

            long long total = (n - cnt[0]) * fact[n - 1];
            for (int c : cnt) {
                if (c > 1) total /= fact[c];
            }
            res += total;
        }

        return res;
    }
};