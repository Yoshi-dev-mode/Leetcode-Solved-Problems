#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> c;

        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++){
            
            char currentVal = s[right];
            if(c.count(currentVal) && c[currentVal] >= left){
                left = c[currentVal] + 1;
            }
            c[currentVal] = right;
            maxLength = max(maxLength, (right - left) + 1);
        }

        return maxLength;
    }
};

int main(){
    Solution solution;

    string letters = "pwwkew";
    
    cout << solution.lengthOfLongestSubstring(letters);
}
