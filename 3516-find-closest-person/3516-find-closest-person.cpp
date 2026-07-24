class Solution {
public:
    int findClosest(int x, int y, int z) {
        int speedOne=abs(x-z);
        int speedTwo=abs(y-z);

        if(speedOne>speedTwo) return 2;
        else if(speedOne<speedTwo) return 1;
        else return 0;
    }
};