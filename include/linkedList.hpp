/**
* @file G201210073
* @description
* @course 1/A
* @assignment 1.Odev
* @date 23-24-25-26 Temmuz 2023
* @author Muhammed Sefa Ozdemir-muhammedsefaozdemir50@gmail.com
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.hpp"

class LinkedList
{
	private:
	Node* head;
	
	public:
	LinkedList()
	{
		head = nullptr;
	}

	Node* getHead() const;
	void insert(int data);
	void printList();
	double calculateAverageAtIndex(LinkedList** lists, int numLists, int index);
};

#endif