class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank != 0){
            while(mainTank / 5 > 0 && additionalTank > 0){
                ans += 50;
                additionalTank--;
                mainTank -= 5;
                mainTank++;
            }
            if(mainTank >= 1){
                ans += 10;
                mainTank--;
            }
        }
        return ans;
    }
};