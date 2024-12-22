Ques 1. Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

//Program Code:
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    if (numRows <= 0) {
        return triangle;
    }
    triangle.push_back({1});
    for (int i = 1; i < numRows; ++i) {
        vector<int> row(i + 1, 1);  
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}
int main() {
    int numRows = 5;
    vector<vector<int>> result = generate(numRows);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
