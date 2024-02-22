/**
* @file G201210073
* @description
* @course 1/A
* @assignment 1.Odev
* @date 23-24-25-26 Temmuz 2023
* @author Muhammed Sefa Ozdemir-muhammedsefaozdemir50@gmail.com
*/
#include <iostream>
#include "node.hpp"
#include "linkedList.hpp"

using namespace std;

// Function to get the head of the linked list.
Node* LinkedList::getHead() const
{
    return head;
}

// Function to insert a new node with the given data at the end of the linked list.
void LinkedList::insert(int data)
{
    // Creating a new node with the given data.
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr; // New node will be the last node, so its next should be nullptr.

    if (head == nullptr)
    {
        // If the linked list is empty, set the new node as the head.
        head = newNode;
        return;
    }

    // Traverse to the end of the linked list to find the last node.
    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Add the new node to the end of the linked list.
    current->next = newNode;
}

// Function to calculate the average of the data at the given index across multiple linked lists.
double LinkedList::calculateAverageAtIndex(LinkedList** lists, int numLists, int index)
{
    int sum = 0; // Variable to store the sum of data at the given index.
    int count = 0; // Variable to store the number of linked lists containing data at the given index.

    for (int i = 0; i < numLists; i++)
    {
        LinkedList* currentList = lists[i]; // Get the current linked list.

        Node* current = currentList->getHead(); // Get the head of the current linked list.
        int currentIndex = 0; // Variable to keep track of the current index while traversing the linked list.

        while (current != nullptr)
        {
            if (currentIndex == index)
            {
                // If the current index matches the desired index, add the data to the sum and increment the count.
                sum += current->data;
                count++;
                break; // Since the desired index is found, break out of the loop.
            }

            current = current->next; // Move to the next node in the linked list.
            currentIndex++; // Increment the current index.
        }
    }

    // Calculate and return the average value (sum / count). If count is zero, return 0.0 to avoid division by zero.
    return (count > 0) ? (double)sum / count : 0.0;
}
