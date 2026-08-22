class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,mul=1;
        int z=n;
        while (z!=0){
            int rem=z%10;
            sum+=rem;
            mul=mul*rem;
            z=z/10;
        }
        if(n%(sum+mul)==0){
            return true;
        }
        return false;
    }
};