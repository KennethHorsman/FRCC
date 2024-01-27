/* Given a sorted array of n integers nums[] = [1, 3, 5, 7, 19] and a target values of 7 & 11, 
determine if the target exists in the array in logarithmic time using the binary search algorithm. 
If target exists in the array, print the index of it. If the target does not exist print Element not found.

Create a function called binarySearch that accepts three arguments and returns an integer value of the index.
Input: nums[] = [1, 3, 5, 7, 19] target = 7
Output: Element found at index 3 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int>& numbers, int target, int numbersSize) { // Not sure if you meant 3 args as in two targets or this
    int leftSide = 0, rightSide = numbersSize -1; // establishes first and last index of search
    
    while (leftSide <= rightSide) { // if the value is not present, leftSide will become greater than rightSide via the calculation below
        int middle = (leftSide + rightSide) / 2; // establishes middle index based on first and last index
        if (numbers[middle] == target) { // if the value at index middle is the target value...
            return middle; // return the index middle
        }
        else if (numbers[middle] < target) { // if the target is greater than the current value...
            leftSide = middle + 1; // discard the left side of the search and the current middle index
        }
        else { // only other option: if the target is less than the current value...
            rightSide = middle - 1; // discard the right side of the search and the current middle index
        }   
    }
    
    return -1; // -1 used as a return value to indicate that the target value was not present
}

int main() {
    vector<int> numbers(5);
    int numbersSize = numbers.size();
    int target, targetIndex;
    bool targetGiven = false;
    
    for (int numbersIndex = 0; numbersIndex < numbersSize; ++numbersIndex) { // loops for each element of the vector "numbers"
        cin >> numbers[numbersIndex];
        if (cin.fail()) { // Since the variable is an int, cin will only accept an int
            cin.clear(); // Clears the error flag to allow future cin operatoins
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This code ignores all the characters in the buffer & creates a new line
            --numbersIndex; // Returns to the same index instead of incrementing
        }
    }
    
    while (!targetGiven) { // used pre-set bool as a flag to indicate whether the user has submit a valid target value
        cin >> target;
        if (cin.fail()) { 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        else {
            targetGiven = true; // changing the bool exits the loop
        }
    }
    
    sort(numbers.begin(), numbers.end()); // Sorts in ascending order
    
    targetIndex = BinarySearch(numbers, target, numbersSize);
    if (targetIndex != -1) {
        cout << "Element found at index " << targetIndex << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}