#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <format>

using namespace std;

class Solution
{
public:

    // Groups strings that are anagrams of each other.
    //
    // Anagrams have the same letters, so sorting each word
    // gives the same key for words that belong in the same group.
    //
    // Example:
    // "eat" -> "aet"
    // "tea" -> "aet"
    // "aet" -> "aet"
    //
    // These words will therefore be stored together.
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // The key is the sorted version of the word.
        // The value is a vector containing all words
        // that have the same sorted key.
        unordered_map<string, vector<string>> map;

        // Go through every word in the input vector.
        for(string word: strs){

            // Make a copy of the current word.
            // We keep the original word unchanged.
            string key = word;

            // Sort the characters to create a common key
            // for words that are anagrams.
            sort(key.begin(), key.end());

            // Add the original word to the group
            // associated with its sorted key.
            map[key].push_back(word);
        }

        // This will store all the groups of anagrams.
        vector<vector<string>> result;

        // Go through every key-value pair in the map.
        for(auto& pair: map){

            // pair.second contains the vector of words
            // belonging to the current anagram group.
            result.push_back(pair.second);
        }

        // Return all groups of anagrams.
        return result;
    }
};


int main(){

    // Create an object of the Solution class.
    Solution solution;

    // Input vector containing words.
    vector<string> anagrams = {"eat","bat","tea","aet","tab"};

    // Call groupAnagrams() and store the returned groups.
    vector<vector<string>> result = solution.groupAnagrams(anagrams);

    // Print the output in a format similar to LeetCode.
    cout << "OUTPUT:" << endl << "[";

    // Loop through each group of anagrams.
    for(int i = 0; i < result.size(); i++){

        cout << "[";

        // Loop through each word inside the current group.
        for(int j = 0; j < result[i].size(); j++){

            // Check if this is the last word in the group.
            if (j+1 == result[i].size()){

                // Print the word without a comma after it.
                cout << result[i][j];

            } else {

                // Print the word followed by a comma.
                cout << result[i][j] << ",";
            }
        }

        // Check if this is the last group.
        if (i+1 == result.size()){

             // Close the last group without a comma.
             cout << "]";

        } else{

             // Close the group and add a comma
             // before the next group.
             cout << "],";
        }
    }

    // Close the entire output.
    cout << "]";
}
