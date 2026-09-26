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


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         vector<int> v(128, -1);

//         int ans = 0;
//         int tp = 0, prev = -1;

//         for (int i = 0; i < n; i++) {
//             char t=s[i];

//             if (v[t] == -1 || v[t] < prev) {
//                 tp++;
//                 v[t] = i;
//             }
//             else {
//                 ans = max(ans, tp);
//                 tp = i - v[t];
//                 prev = v[t] + 1;
//                 v[t] = i;
//             }
//         }

//         ans = max(ans, tp);
//         return ans;
//     }
// };
int main(){
    Solution solution;

    string letters = "pwwkew";
    
    cout << solution.lengthOfLongestSubstring(letters);
}
