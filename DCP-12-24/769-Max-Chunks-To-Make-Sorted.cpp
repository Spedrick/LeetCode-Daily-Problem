class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int c=0, diff=0;
        for(int i=0; i<arr.size(); i++){
            diff += arr[i] - i;
            if(diff == 0) c++;
        }
        return c;
    }
};