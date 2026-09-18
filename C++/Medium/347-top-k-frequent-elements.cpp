#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

/*
    ============================================================
                    347. TOP K FREQUENT ELEMENTS
    ============================================================

    Goal:
    Find the K numbers that appear most frequently in the array.

    Example:
        nums = {1,1,1,2,2,3,4,4,4,4,4}
        k = 2

    Frequencies:
        1 -> 3 times
        2 -> 2 times
        3 -> 1 time
        4 -> 5 times

    The 2 most frequent numbers are:
        4 and 1


    ------------------------------------------------------------
                    STEP 1: COUNT FREQUENCIES
    ------------------------------------------------------------

    We use an unordered_map:

        unordered_map<int, int> frequency;

    The KEY   = number
    The VALUE = how many times that number appears

    Example:

        frequency[1] = 3
        frequency[2] = 2
        frequency[3] = 1
        frequency[4] = 5


    ------------------------------------------------------------
                    STEP 2: USE A MIN-HEAP
    ------------------------------------------------------------

    We use:

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minheap;

    The pair stores:

        {frequency, number}

    Example:

        {3, 1} -> number 1 appears 3 times
        {2, 2} -> number 2 appears 2 times
        {1, 3} -> number 3 appears 1 time
        {5, 4} -> number 4 appears 5 times


    Why use a MIN-HEAP?

    We only want to keep K elements.

    Since this is a MIN-HEAP, the element with the
    smallest frequency stays at the TOP.

    If the heap becomes bigger than K:

        minheap.size() > k

    we remove the top element:

        minheap.pop();

    This removes the element with the smallest frequency.

    Therefore, the heap continuously removes the weakest
    candidate and keeps the K most frequent elements.


    ------------------------------------------------------------
                    PRIORITY_QUEUE BREAKDOWN
    ------------------------------------------------------------

    priority_queue<
        pair<int, int>,              // WHAT DO I STORE?
        vector<pair<int, int>>,      // HOW DO I STORE IT?
        greater<pair<int, int>>      // HOW DO I PRIORITIZE IT?
    >

    1. pair<int, int>

       Each element inside the heap is a pair.

       pair.first  = frequency
       pair.second = number


    2. vector<pair<int, int>>

       The priority_queue uses a vector internally
       to store its elements.

       The vector is NOT the thing that decides
       which element is on top.

       The priority_queue manages the heap structure
       inside that vector.


    3. greater<pair<int, int>>

       This tells the priority_queue to behave
       like a MIN-HEAP.

       The smallest pair gets the highest priority.

       For pairs, C++ compares:

           first  -> frequency

       If the frequencies are equal, it compares:

           second -> number

       Example:

           {2, 1}
           {5, 4}
           {3, 7}

       The smallest is:

           {2, 1}

       So:

           minheap.top()

       gives:

           {2, 1}


    ------------------------------------------------------------
                    STEP 3: GET THE ANSWER
    ------------------------------------------------------------

    Once the heap contains exactly K elements, we remove
    each element one by one.

        minheap.top().second

    .top()    -> gets the pair at the top
    .second   -> gets the number from that pair

    We then put that number into the result vector.


    ------------------------------------------------------------
                    IMPORTANT IDEA
    ------------------------------------------------------------

    The heap is NOT sorting all numbers.

    Instead, it acts like a container that only keeps
    the K strongest candidates.

    For every number:

        1. Put {frequency, number} into the heap.
        2. If the heap has more than K elements,
           remove the smallest frequency.
        3. Continue until all numbers are processed.

    At the end:

        The heap contains the K most frequent numbers.


    Time Complexity:
        O(n + m log k)

        n = number of elements in nums
        m = number of unique numbers

    Space Complexity:
        O(n)

        The unordered_map and heap store information
        about the elements.
*/


/*
priority_queue<

    WHAT DO I STORE?,
    HOW DO I STORE IT?,
    HOW DO I PRIORITIZE IT?

    For this problem:

    WHAT DO I STORE?
        pair<int, int>

    HOW DO I STORE IT?
        vector<pair<int, int>>

    HOW DO I PRIORITIZE IT?
        greater<pair<int, int>>

    Result:
        A MIN-HEAP that stores {frequency, number}.
*/

using namespace std;

class Solution
{

public:

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // Stores each number and its frequency.
        // Key   = number
        // Value = number of times it appears
        unordered_map<int, int> frequency;

        // Go through every number in nums
        // and increase its frequency by 1.
        for (int num : nums)
        {
            frequency[num]++; // 1 : ....
        }

        // Min-heap:
        //
        // pair.first  = frequency
        // pair.second = number
        //
        // greater<pair<int, int>> makes this a MIN-HEAP,
        // so the smallest frequency is always at the top.
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            minheap;

        // Go through every number and its frequency
        // stored inside the unordered_map.
        for(auto& pair: frequency){ // first : second

            // pair.first is the number
            int num = pair.first; 

            // pair.second is the frequency/count
            int count = pair.second;

            // Store {frequency, number} inside the min-heap.
            //
            // Example:
            // If number 4 appears 5 times:
            // {5, 4}
            minheap.push({count,num});

            // We only want K elements in the heap.
            //
            // If the heap becomes bigger than K,
            // remove the smallest-frequency element.
            if(minheap.size() > k){

                // Because this is a MIN-HEAP,
                // the smallest frequency is at the top.
                minheap.pop();
            }
        }

        // This vector will contain the final answer.
        vector<int> result;

        // Continue until the heap becomes empty.
        while(!minheap.empty()){

            // Get the pair at the top of the heap.
            //
            // .second gives us the NUMBER,
            // because the pair is {frequency, number}.
            result.push_back(minheap.top().second);

            // Remove the top element after saving it.
            minheap.pop();
        }

        // Return the K most frequent numbers.
        return result;
    }
};

int main(){

    // Create a Solution object.
    Solution solution;

    // Input array.
    vector<int> num = {1,1,1,2,2,3,4,4,4,4,4};

    // We want the 2 most frequent numbers.
    int k = 2;

    // Call the Top K Frequent Elements function.
    vector<int> result = solution.topKFrequent(num,k);

    // Print the result in [x,y] format.
    cout << "[";

    for(int i = 0; i < result.size(); i++){

        // If this is the last element,
        // don't print a comma after it.
        if(i+1 == result.size()){

            cout << result[i];

        } else {

            // Print the number followed by a comma.
            cout << result[i] << ",";
        }
    }

    // Close the brackets.
    cout << "]";

}