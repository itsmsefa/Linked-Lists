/**
* @file G201210073
* @description
* @course 1/A
* @assignment 1.Odev
* @date 23-24-25-26 Temmuz 2023
* @author Muhammed Sefa Ozdemir-muhammedsefaozdemir50@gmail.com
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "node.hpp"
#include "linkedList.hpp"

using namespace std;

int main()
{
    const int initialSize = 100;
    int size = initialSize;
    LinkedList** downwardLists = new LinkedList*[size];
    LinkedList** upwardLists = new LinkedList*[size];

    // Open the file "Sayilar.txt" to read the data.
    ifstream file("Sayilar.txt");
    if (!file) {
        cout << "Failed to open the file!" << endl;
        return 0;
    }

    int data;
    string line;
    int downIndex = 0;
    int upIndex = 0;
    int maxCount = 0;

    // Read the numbers from the file line by line.
    while (getline(file, line)) {
        // Count the number of integers in the current line.
        istringstream iss11(line);
        int count = 0;
        int num;
        while (iss11 >> num) {
            count++;
        }

        // Keep track of the maximum number of integers in any line.
        if (count > maxCount) {
            maxCount = count;
        }

        // If the arrays are full, dynamically allocate more space.
        if (downIndex == size) {
            size *= 2;
            LinkedList** newDownwardLists = new LinkedList*[size];
            LinkedList** newUpwardLists = new LinkedList*[size];

            // Copy the elements from the old arrays to the new arrays.
            for (int i = 0; i < downIndex; i++) {
                newDownwardLists[i] = downwardLists[i];
                newUpwardLists[i] = upwardLists[i];
            }

            // Delete the old arrays.
            delete[] downwardLists;
            delete[] upwardLists;

            // Point to the new arrays.
            downwardLists = newDownwardLists;
            upwardLists = newUpwardLists;
        }

        // Create new linked lists for the ones and tens digits of each number.
        LinkedList* downList = new LinkedList();
        LinkedList* upList = new LinkedList();

        // Read the numbers from the line and extract ones and tens digits.
        istringstream iss(line);
        while (iss >> data) {
            int onesDigit = data % 10;
            int tensDigit = data / 10;

            // Insert the ones and tens digits into the respective linked lists.
            downList->insert(onesDigit);
            upList->insert(tensDigit);
        }

        // Add the new linked lists to the downwardLists and upwardLists arrays.
        downwardLists[downIndex] = downList;
        upwardLists[upIndex] = upList;

        // Increment the indices for downwardLists and upwardLists.
        downIndex++;
        upIndex++;
    }
    file.close();

    // Ask the user to input the indices of the linked lists to be swapped.
    int swapIndexDown, swapIndexUp;
    cout << "Enter the index of the upward list to swap: ";
    cin >> swapIndexUp;

    cout << "Enter the index of the downward list to swap: ";
    cin >> swapIndexDown;

    // Check if the provided indices are valid and perform the swap.
    if (swapIndexDown < 0 || swapIndexDown >= downIndex ||
        swapIndexUp < 0 || swapIndexUp >= upIndex) {
        cout << "Invalid indices provided!" << endl;
    } else {
        LinkedList* temp = downwardLists[swapIndexDown];
        downwardLists[swapIndexDown] = upwardLists[swapIndexUp];
        upwardLists[swapIndexUp] = temp;

        cout << "Lists swapped successfully!" << endl;
    }

    // Calculate the averages for each index in upwardLists.
    int numUpwardLists = upIndex;
    float upwardSum=0;
    for (int i = 0; i < maxCount; i++)
    {
        double average = upwardLists[i]->calculateAverageAtIndex(upwardLists, numUpwardLists, i);
        upwardSum += average;
    }

    // Print the sum of averages for the upward lists.
    cout << "UST: " << upwardSum << endl;

    // Calculate the averages for each index in downwardLists.
    int numDownwardLists = downIndex;
    float downwardSum=0;
    for (int i = 0; i < maxCount; i++)
    {
        double average = downwardLists[i]->calculateAverageAtIndex(downwardLists, numDownwardLists, i);
        downwardSum += average;
    }

    // Print the sum of averages for the downward lists.
    cout << "ALT: " << downwardSum << endl;

    // Free the dynamically allocated memory for each list.
    for (int i = 0; i < downIndex; i++)
    {
        delete downwardLists[i];
    }

    for (int k = 0; k < upIndex; k++)
    {
        delete upwardLists[k];
    }

    // Finally, release the memory for the arrays of pointers.
    delete[] downwardLists;
    delete[] upwardLists;

    return 0;
}
