class Solution {
public:
    int takeCharacters(string s, int k) {
        int count_a=0;
        int count_b=0;
        int count_c=0;

        //get total-count;
        for(auto &it:s){
            if(it=='a') count_a++;
            else if(it=='b') count_b++;
            else count_c++;
        }
        int total_count=count_a+count_b+count_c;

        if(count_a<k || count_b<k || count_c<k) return -1;
        int bestWindow=0;

        int i=0;
        int j=0;

        while(j<s.size()){
            if(s[j]=='a') count_a--;
            else if(s[j]=='b') count_b--;
            else if(s[j]=='c') count_c--;

            while(i<=j && (count_a<k || count_b<k || count_c<k)){
                if(s[i]=='a') count_a++;
                else if(s[i]=='b') count_b++;
                else if(s[i]=='c') count_c++;
                i++;
            }
            
            bestWindow=max(bestWindow,j-i+1);
            j++;

        }

        return total_count-bestWindow;

    }
};