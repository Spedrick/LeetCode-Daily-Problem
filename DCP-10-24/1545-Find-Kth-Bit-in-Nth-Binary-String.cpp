class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int size = pow(2,n) - 1;   
        int mid = size/2;   

        if(k-1 == mid) return '1';
        else if (k-1 < mid) return findKthBit(n-1, k);
        else return findKthBit(n-1, size - k + 1) == '0' ? '1' : '0';
    }
};