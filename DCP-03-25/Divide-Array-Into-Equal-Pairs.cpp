class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> mp(501,0);
        for(int x: nums) {
            mp[x]++;
        }

        for(int i=0;i<501;i++){
            if(mp[i] % 2 != 0) return false;
        }

        return true;
    }
};