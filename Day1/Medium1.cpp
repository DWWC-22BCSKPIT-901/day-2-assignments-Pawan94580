// Count the total number of digits in a given number n. The number
can be a positive integer. For example, for the number 12345, the count of
digits is 5. For a number like 900000, the count of digits is 6.
Given an integer n, your task is to determine how many digits are present in
n. This task will help you practice working with loops, number manipulation,
and conditional logic.

#include <iostream>
using namespace std;
int countDigits(int n) {
int count = 0;
while (n > 0) {
n /= 10;
count++; 
}
return count;
}
int main() {
int n;
cout << "Enter a positive integer: ";
cin >> n;
if (n <= 0) {
cout << "Please enter a positive integer." << endl;
} 
else {
int result = countDigits(n);
cout << "The number of digits in " << n << " is: " << result << endl;
}
return 0;
}
