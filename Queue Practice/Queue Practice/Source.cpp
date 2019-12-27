#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

int A[3];
int front = -1;
int rear = -1;

Node* head = NULL;
Node* tail = NULL;

//Array Implementation
void enqueue(int x);
void dequeue();
int InFront();
bool IsEmpty();
bool IsFull();

//LL Implementation
void enqueueLL(int x);
void dequeueLL();
int InFrontLL();
bool IsEmptyLL();

int main() {

	//Array Implementation
	enqueue(2); // A=[2,]
	enqueue(5); // A=[2,5,]
	enqueue(7); // A=[2,5,7] // Array is full
	cout << InFront() << endl; //2
	dequeue();  // A=[,5,7,] 
	cout << InFront() << endl; //5
	enqueue(9); // A[0] is now 9
	dequeue();
	dequeue();
	cout << InFront() << endl; //9
	enqueue(10);
	dequeue();
	cout << InFront() << endl; //10

	//LL Implementation
	enqueueLL(2);
	enqueueLL(5);
	enqueueLL(7);
	cout << InFrontLL() << endl; //2
	dequeueLL();
	cout << InFrontLL() << endl; //5
	dequeueLL();
	cout << InFrontLL() << endl; //7

}

//Array Implementation
void enqueue(int x) { //Implement circular Array to maximize efficiency of Queue so spaces are reused before Empty
	Node* newNode = new Node();
	
	if (IsFull()) return;
	else if (IsEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		//rear = rear++;
		//Circular implementation
		rear = ((rear + 1) % size(A));
	}
		A[rear] = x;
}

void dequeue() {
	if (IsEmpty()) return;
	else if (front == rear) { //After Dequeue, array is empty so set both to -1
		front = -1;
		rear = -1;
	}
	else {
		//front++;
		//Circular implementation
		front = ((front + 1) % size(A));
	}
}

bool IsEmpty() {
	if (front == -1 and rear == -1) return true;
	else return false;
}

bool IsFull() {
	//if (rear == size(A) - 1) return true;
	//else return false;

	
	//circular implementation
	if (((rear + 1) % size(A)) == front) return true;
	else return false;
}

int InFront() {
	return A[front];
}

//LL Implementation
//Always enqueues from tail
void enqueueLL(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;

	if (IsEmptyLL()) {
		head = tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}
//always dequeues from head
void dequeueLL(){
	Node* temp = head;
	if (IsEmptyLL()) return;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		head = head->next;
	}
	delete temp;
}
int InFrontLL(){
	return head->data;
}
bool IsEmptyLL(){
	if (head == NULL && tail == NULL) return true;
	else return false;
}