// Project: Assignment 8 Applications using Queues CMPR131
// Due: October 25, 2022
// By: Victor Huerta 
#include <iostream> 
#include <queue>
#include <vector>
#include "input.h"
#include "Patient.h"
using namespace std;

int menuOption();
void challenge2();

int main() {
	
	bool flag = true;
	do {
		system("cls");
		switch (menuOption())
		{
		case 0: flag = false; break;
		case 2: challenge2(); break;
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

void challenge2() {

    cout << "\n\t2> Simulation of an emergency room (ER) using priority queue STL\n";

    priority_queue<Patient> pq2;
    vector<Patient> submit;
    bool flag2 = true;
    do
    {
        cout << "\n\t\t  A> Register a patient";
        cout << "\n\t\t  B> Transfer patient(s) to the designation";
        cout << "\n\t\t  C> Display transferred patients";
        cout << "\n\t\t  X> return\n";

        switch (toupper(inputChar("\t\t  Option: ", "ABC0")))
        {
        case 'X': flag2 = false; break;
        case 'A':
        {
            Patient patient;
            string name;
            cout << "\n\t\tEnter the patient's name: ";
            getline(cin, name);
            patient.setName(name);
            patient.setAge(inputInteger("\t\tEnter the patient's age: ", true));
            patient.setCheckedInTime(time(0));
            patient.setGender(toupper(inputChar("\t\tChoose the patient's gender (F-female  or M - male) : ", 'F', 'M'))); 
                patient.setPriority(inputInteger("\t\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5)); 

                pq2.push(patient); // enqueue 
            cout << "\n\t\tPatient information has been registered.\n";
        }
        break;
        case 'B':
        {
            if (pq2.empty()) {
                cout << "\n\tThere are no patients to transfer.";
            }
            else
            {
                if (pq2.top().getPriority() == 5)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to ICU...\n" ; 
                        pq2.pop(); // dequeue 
                    break;
                }
                else if (pq2.top().getPriority() == 4)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to surgery room...\n"; 
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 3)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to emergency room...\n"; 
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 2)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - transfers to x- ray lab...\n"; 
                        pq2.pop();
                    break;
                }
                else if (pq2.top().getPriority() == 1)
                {
                    submit.push_back(pq2.top());
                    cout << "\n\t\t" << pq2.top().getName() << " - examines and gives prescription...\n"; 
                        pq2.pop();
                    break;
                }
            }
        }
        break;
        case 'C':
        {
            if (!submit.empty())
            {

                sort(submit.begin(), submit.end());
                reverse(submit.begin(), submit.end());
                cout << '\n';
                for (int i = 0; i < submit.size(); i++)
                    cout << "\t\t" << i + 1 << " - " << submit[i] << '\n';
            }
            else
                cout << "\n\t\tNo patient has been transferred.\n";
        }
        default: {
            cout << "\nError invalid option. Please chose again.\n"; break;
        }
        break;
        }


    } while (flag2);

}