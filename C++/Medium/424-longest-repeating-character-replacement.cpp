#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLength = 0;
        int maxFreq = 0;
        vector<int> freq(26,0);
    
        for(int right = 0; right < s.size(); right++){
            freq[s[right]-'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main(){
    Solution solution;

    string letters = "AABBA";
    int k = 1;

    cout << solution.characterReplacement(letters, k);
}