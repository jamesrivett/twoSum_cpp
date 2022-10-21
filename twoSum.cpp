#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    // Create sums matrix
    vector<vector<int>> sums_matrix;
    for (int i = 0; i < nums.size(); i++) {
        vector<int> current;

        for (int j = 0; j < nums.size(); j++) {
            if (i == j) { current.push_back(0); break; }
            current.push_back(nums[i] + nums[j]);
        }

        sums_matrix.push_back(current);
    }

    // Find target
    vector<int> answer;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (sums_matrix[i][j] == target) {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }

    return vector<int>({-1});
}

int main(int c, char *v[]) {
    vector<int> input = vector<int>({2,3,4});
    int target = 6;

    vector<int> answer = twoSum(input, target);

    cout << "input vector: ";
    for (int i = 0; i < input.size(); i++) {
        if (i != 0)  { cout << ", "; }
        cout << input[i];
    }
    cout << "\ntarget: " + to_string(target);
    cout << "\n\n\n";
	
    
    cout << "result: " + to_string(answer[0]) + ", " + to_string(answer[1]) + "\n";
}
