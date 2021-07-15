// priority_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://www.codezclub.com/cpp-implement-priority-queue/
//https://www.sanfoundry.com/cpp-program-implements-priority-queue/
#include <iostream>
#include "queue.h"
#include <string.h>
#include "utils.h"

using namespace std;

void pr_queue::display()
{
	if (front == NULL)
	{
		std::cout << "Priority queue is empty \n";
	}
	else
	{
		node* tmp;
		tmp = front;
		int nr = 0;
		while (tmp->link != NULL)
		{
			std::cout << (formatDisplay(nr, tmp->name, tmp->age, tmp->sanitaryConditions, tmp->city, tmp->priority));
			tmp = tmp->link;
			nr++;
		}
		std::cout << (formatDisplay(nr, tmp->name, tmp->age, tmp->sanitaryConditions, tmp->city, tmp->priority));
																															
		std::cout << std::endl;
																															
	}
}
void pr_queue::dequeue()
{
	node* tmp;
	if (front == NULL)
	{
		std::cout << "Priority queue is empty \n";
	}
	else
	{
		tmp = front;	
		std::cout << "Vaccination done. Removed from waiting list: " << tmp->name << endl;	//print out the oldest element
		front = front->link; //on the adress of the oldest element we copy the adress of the next element that was inserted
		free(tmp); //free up the memory space allocated for the oldest element
	}
}

void pr_queue::enqueue(string name_p, int age_p, int cond_p, string city_p)
{
	node* tmp, * q;
	int priority = calculatePriority(age_p, cond_p);
	int info = cond_p;
	tmp = new node;
	tmp->name = name_p;
	tmp->age = age_p;
	tmp->sanitaryConditions = cond_p;
	tmp->city = city_p;
	tmp->priority = calculatePriority(age_p, cond_p);
	if (front == NULL || priority > front->priority) //the queue is empty, the new element will pe inserted based on it`s priority
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while (q->link != NULL && q->link->priority >= priority) //we will insert the new element at the end of the queue OR where it`s priority allows it (lower then the next elements priorirty)
		{
			q = q->link;
		}
		tmp->link = q->link;
		q->link = tmp;
	}
}

pr_queue::pr_queue() //consturctor for the queue
{
	front = NULL;
}
