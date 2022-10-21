#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

// To be completed for exercise 3
// ONLY CHANGE BODY OF THIS METHOD
int List::remove(int val)
{
	//stub - remove and replace with implementation
 //Test Place. Testing with Arrays.
 //Plan Use an Array to store data from linked list. Deleate Linked List. Then Create new list and copy stuff from array to there.
int count = 0;
int size = 0;
int i=0;

//Firstly, get counter
	Ex3Node*p = head;
	while (p != nullptr) {
		if (p->data == val){
		    count++;
		}
		
		else {
		    size++;
		}
		p = p->next;
	}

//Now array time
int array[size];

	Ex3Node*q = head;
	while (q != nullptr) {
		if (q->data != val){
		    array[i] = q->data;
		    i++;
		}
		q = q->next;
	}
    
    delete head;
    
    Ex3Node*final;
    
    for(int j; j<size; j++)
    {
        final.insert(array[j]);
    }
    
    return count;
}

// Constructors and destructor
// Creates an empty list
List::List()
{
	head = nullptr;
}

List::~List()
{
	deleteList();
}
// Copy constructor and overloaded assignment operator not implemented

// Mutators------------------
// PARAM: val = data to be inserted
// POST: inserts val at the front of the list
void List::insert(int val)
{
	Ex3Node* newNode = new Ex3Node(val, head);
	head = newNode;
}

// int remove - see top of file

// Helper method for destructor
// (and un-implemented overloaded assignment operator)
void List::deleteList()
{
	Ex3Node* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// Accessors
bool List::check(const vector<int> & v) const
{
	Ex3Node* p = head;
	for (int x : v) {
		if (p == nullptr || p->data != x) {
			return false;
		}
		p = p->next;
	}

	return (p == nullptr); // p != nullptr list contains unchecked datas
}
//I'm testing an idea. Is it possible to do excercise 3 using arrays to copy the data into a new linkedlist
// Prints the contents of the list starting from head
void List::print() const
{
	Ex3Node*p = head;
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
}

int main(){
    vector<int> vect;
 
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    List list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
   list.insert(10);
 int checker =  list.remove(10);
   // list.check();


   // bool checker = list.check(vect);
    std::cout << "counter = " << checker << endl;
    list.print();
}