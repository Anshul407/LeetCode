class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i=0;
        char prev=' ';
        while(i<sentence.size()){
            while(i<sentence.size()&&sentence[i]==' ')i++;
            if(i>=sentence.size())return sentence[0]==sentence.back();
            if(prev!=' '&&prev!=sentence[i])return 0;
            while(i<sentence.size()&&sentence[i]!=' '){
                prev=sentence[i];
                i++;
            }
            if(i>=sentence.size())sentence[0]==sentence.back();
        }
        return sentence[0]==sentence.back();
    }
};