class Solution {
public:
    int percentageLetter(string s, char letter) {
        double totalCount=0;
        double countLetter=0;

        for(char c:s){
            totalCount++;
            if(c==letter){
                countLetter++;
            }
            
        }
        if(totalCount==0 || countLetter==0 ) return 0;
        return ((countLetter/totalCount)*100);
    }
};