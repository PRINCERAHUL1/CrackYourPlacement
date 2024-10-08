class Solution {
public:

    string one[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight"," Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string ten[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousand[4] = {"", " Thousand", " Million", " Billion"};

    string words(int n)
    {
        if(n < 20)
            return one[n];
        
        if(n < 100)
            return ten[n/10] + words(n%10);
        
        if(n < 1000)
            return words(n/100) + " Hundred" + words(n%100);
        
        for(int i=3; i>=0; i--)
        {
            if(n >= pow(1000, i))
                return words(n/pow(1000, i)) + thousand[i] + words(n% (int)pow(1000, i));
        }

        return "";
    }

    string numberToWords(int num) {
        if(num == 0)
            return "Zero";

        return words(num).substr(1);   
    }
};
