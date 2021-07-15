#pragma once
#include <string.h>

using namespace std;

class pr_queue
{
private:
	struct node
	{
		int priority;
		string name;
		int age;
		int sanitaryConditions;
		string city;
		struct node* link;
	};
	node* front;
public:
	pr_queue();
	void enqueue(string name_p, int age_p, int cond_p, string city_p);
	void dequeue();
	void display();
};
