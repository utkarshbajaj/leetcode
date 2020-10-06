class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N) return 1;
        int no = 0;
        int p = 0;
        
        while(N){
            int rem = N & 1;
            rem ^= 1;
            no += rem * pow(2, p++);
            N = N >> 1;
        }
        
        return no;
        
        
    }
};