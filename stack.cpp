#include <iostream>
using namespace std;

string divider = "############################################################";
struct obj{
	int top;
	int size;
	char *stk;
};

obj *Build_Stack(unsigned int size){
	obj *stack = new obj();
	stack->size = size;
	stack->top = -1;
	stack->stk = new char[size];
	return stack;
};

void push(obj *stk_obj, char item){
	if(stk_obj->top == stk_obj->size-1){
		cout<<"stack overflow\n"<<divider<<endl;
		return;
	}
	stk_obj->stk[++stk_obj->top] = item;
	cout<<stk_obj->stk[stk_obj->top]<<" added"<<endl;
};

void pop(obj *stk_obj){
	if(stk_obj->top == -1){
		cout<<"stack underflowing\n"<<divider<<endl;
		return;
	};
	cout<< stk_obj->stk[stk_obj->top] <<" removed\n"<<divider<<endl;
	stk_obj->top--;
};

void display(obj *stk_obj){
	if(stk_obj->top == -1){
		cout<< "stack is empty\n" <<divider<<endl;
		return;
	};
	for(int i = stk_obj->top; i >= 0; i--){
		cout << stk_obj->stk[i] << " ";
	};
	cout<<"\n"<<divider<<endl;
}

int main(){
	int opt = 0;
	char element;
	obj *n = Build_Stack(5);
	while(opt != 4){
		cout<< "\nWhat would you like to do: \n1) add to stack\n2)remove from stack\n3)display\n4)exit\nYour option:";
		cin>>opt;
		switch(opt){
			case 1:
				cout<<"Enter number you'd like to add: ";
				cin>> element;
				push(n,element);
				break;
			case 2:
				pop(n);
				break;
			case 3:
				display(n);
				break;
		}
	}
	delete n->stk;
	delete n;
	return 0;
}
