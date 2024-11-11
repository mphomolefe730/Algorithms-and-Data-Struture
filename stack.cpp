#include <iostream>
#include <stack>

using namespace std;

struct learner{
	string name;
	string surname;
	int age;
};
class Year{
	stack<learner> chosenYear;
	public:
		Year(){};
		void addLearner(learner &person){
			chosenYear.push(person);
		}
		void numberOfStudents(){
			cout<<"Number of students: "<< chosenYear.size() << endl;
		}
		void printElements(){
			cout<<"Stack from top to bottom: "<<endl;
			stack<learner> stack = chosenYear;
			while(!stack.empty()){
				cout<< stack.top().name << endl;
				stack.pop();
			}
		}
};

int main()
{
	Year secondYears;
	learner one = {"mpho", "molefe", 22};
	learner two = {"kamogelo", "sashebala", 22};
	learner three = {"reabetswe", "mogela", 21};
	
	secondYears.addLearner(one);
	secondYears.addLearner(two);
	secondYears.addLearner(three);
	
	secondYears.numberOfStudents();
	secondYears.printElements();
	
	return 0;
}
