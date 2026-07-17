class Solution {
public:
    int brokenCalc(int& start, int target) {
        long long count = 0;
        int x = target;
        while (start !=x) {
            if(start>=x){
                return count+(start-x);
            }
            if (x % 2 == 0) {
                x /= 2;
                count++;
            } else {
                x++;
                count++;
            }
        }
        return count;
    }
};