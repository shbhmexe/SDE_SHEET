//Burte forcr - greedy , complete solve using dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int count = 0;
        
        for (int i = 0; i < coins.size(); i++) {
            if (amount == 0) break;
            if (coins[i] <= amount) {
                count += amount / coins[i];
                amount %= coins[i];
            }
        }
        
        if (amount != 0) return -1;
        return count;
    }
};