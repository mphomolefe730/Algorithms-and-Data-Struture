#include <iostream>
#include <thread>
#include <chrono>
#include <string.h>
#include <vector>
using namespace std;

struct emp{
	char name[20], surname[30];
	int salary = 0;
	int age = 0;
};

class EmployeeManager{
	vector<emp> employee_library = {};
public:
	void addEmployee(void){
		emp employee_object;
		cout<<"Enter emplyee name and surname: "<<endl;
		cin>>employee_object.name>>employee_object.surname;
		cout<<"Enter "<<employee_object.name<<" "<<employee_object.surname <<"'s salary"<<endl;
		cin>>employee_object.salary;
		employee_library.push_back(employee_object);
		cout<<"Employee successfully added!\n";
	};

	void showSalary(){
		for(auto &emp:employee_library){
			cout<<emp.name<<" "<<emp.surname<<"'s salary is:  "<<emp.salary<<endl;
		}
	};
};

int main(){
	EmployeeManager manager;
	int choice;
	while(choice != 3){
		cout << "\n1. Add Employee\n2. Show Salaries\n3. Exit\nChoose an option: ";
		cin>>choice;
		switch(choice){
			case 1:
				manager.addEmployee();
				break;
			case 2:
				manager.showSalary();
				break;
			case 3:
				cout<<"Session ended "<<endl;
				this_thread::sleep_for(chrono::seconds(1));
				system("clear");
				break;
		}
	};
	//int *p = &choice;
	//cout<<"adress of p: "<< p <<endl<< "value of p: "<< *p <<endl;
	//cout<<"enter new value for choice: ";
	//cin>>choice;
	//cout<<"adress of p: "<< p <<endl<< "value of p: "<< *p <<endl;
	//cout<<"enter new value for p: ";
	//cin>>*p;
	//cout<<"adress of choice: "<< &choice <<endl<< "value of choice: "<< choice <<endl;
	return 0;
}
