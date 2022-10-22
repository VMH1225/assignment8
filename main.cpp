// Project: Assignment 8 Applications using Queues CMPR131
// Due: October 25, 2022
// By: Victor Huerta
#include <iostream> 
#include "input.h"
using namespace std;

int menuOption();
void challenge1();

int main() {
	
	bool flag = true;
	do {
		system("cls");
		switch (menuOption())
		{
		case 0: flag = false; break;
		case 1: challenge1(); break;
		default: "\nError invalid option. Please chose again.\n"; break;
		}

	} while (flag);
	return 0;
}

int menuOption() {

	cout << "\n\t\tCMPR131 Chapter 8: Applications using Queues by Victor Huerta(10 / 21 / 22)";
	cout << "\n\t\t" << string(75, char(205));
	cout << "\n\t\t  " << "1> Simulation of War (card game) using deque STL";
	cout << "\n\t\t  " << "2> Simulation of an emergency room (ER) using priority queue STL";
	cout << "\n\t\t  " << "3> Simulation of checkout lines at CostCo using multiple queues STL";
	cout << "\n\t\t" << string(75, char(196));
	cout << "\n\t\t  " << "0> Exit";
	cout << "\n\t\t" << string(75, 196);
	int option = inputInteger("\n\t\tEnter an option from the menu: ", 0, 3);
	return option;	
}

void challenge1() {
	cout << "\nHello\n";
	system("pause");
}