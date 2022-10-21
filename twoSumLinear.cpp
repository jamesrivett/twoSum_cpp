#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<int> twoSumLinear(vector<int> nums, int target) {
    vector<int> answers;

    // Ensure vector is sorted (not counted in time complexity)
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    // Create two pointers at the top and bottom
    int bottom = 0;
    int top = sorted.size() - 1;

    while (top != bottom) {
        // Return if we've found the answer
        if (sorted[bottom] + sorted[top] == target) {
            answers.push_back(bottom);
            answers.push_back(top);
            return answers;
        }

        // Iterate bottom pointer if result is too low
        else if (sorted[bottom] + sorted[top] < target) {
            bottom++;
        }

        // De-Iterate top pointer if result is too high
        else if (sorted[bottom] + sorted[top] > target) {
            top--;
        }

    }

    // Base case (something went wrong)
    return vector<int>({-1});

}

int main(int c, char *v[]) {
    vector<int> input = vector<int>({0,1,2,7,11,15});
    vector<int> answer = twoSumLinear(input, 9);

    cout << to_string(answer[0]) + ", " + to_string(answer[1]) + "\n";
}
