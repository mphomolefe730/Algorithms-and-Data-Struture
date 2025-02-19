#include <iostream>
using namespace std;

string divider = "############################################################";
struct obj{
	int front;
	int rear;
	int size;
	char *stk;
};

void push(obj *queue, char item){
	if (queue->rear == queue-> size-1 && queue->front == 0){
		cout<< "overflow\n"<<divider<<endl;
		return;
	};
	if(queue->rear == queue->size -1){
		queue->rear = 0;
	}else if(queue->rear == -1){
		queue->front = 0;
		queue->rear = 0;
	}else{
		queue->rear++;
	};
	queue->stk[queue->rear] = item;
	cout<< item << " added\n"<<divider<<endl;
	return;
};

void pop(obj *queue){
	if(queue->front == -1){
		cout<<"underflow\n"<<divider<<endl;
		return;
	};
	int temp = queue->front;
	if(queue->front == queue->rear){
		queue->front = -1;
		queue->rear = -1;
	}else if(queue->front == queue->size-1){
		queue->front = 0;
	}else{
		queue->front++;
	};
	cout<< queue->stk[temp] << " removed\n"<<divider<<endl;
	return;
	//queue[queue->front];
};

void display(obj *queue){
	int i = 0;
	if(queue->front == -1){
		cout<<"queue empty\n"<<divider<<endl;
		return;
	};
	if(queue->front > queue->rear){
		for(i = queue->front; i < queue->size-1; i++){
			cout<<queue->stk[i] << " ";
		};
		for(i = 0; i < queue->rear; i++){
			cout<< queue->stk[i] << " ";
		};
	}else{
		for(i = 0; i < queue->size; i++){
			cout<<queue->stk[i] << " ";
		};
	};
	cout<<"\nfront: "<<queue->stk[queue->front] <<"\nrear: "<<queue->stk[queue->rear]<<"\n"<<divider<<endl;
	return;
};

obj *build_circular_queue(unsigned int size){
	obj *queue = new obj();
	queue->front = -1;
	queue->rear = -1;
	queue->size = size;
	queue->stk = new char[size];
	
	return queue;
};

int main(){
	obj *n = build_circular_queue(20);
	int opt = 0;
	char element;
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
