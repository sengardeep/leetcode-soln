class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            if(carry){
                int s=digits[i]+carry;
                carry=s/10;
                digits[i]=s%10;
            }else break;
        }
        if(carry) digits.insert(digits.begin(),carry);
        return digits;
    }
};