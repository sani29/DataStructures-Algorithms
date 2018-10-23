/* Question -->
Given a Linked List of integers, 
write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. 
Also, keep the order of even and odd numbers same.

Example:

Input
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};
Node* takeInput_better(){
	// number of nodes
    int n;
    cin>>n;
    int data;
	Node *head = NULL;
	Node *tail = NULL;
	while(n--){
		// input data
	    cin>>data;
		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = tail->next;
		}
	}
	return head;
}

void print(Node *head) {
	
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout<<endl;
}

void segregateEvenOdd(Node** head)
{
	// Ending node of odd and even values list. 
  Node *odd = NULL, *even = NULL;
  // Node to traverse the list.
  Node *temp = *head;
  // Starting node of list having odd and even values.
  Node *oddStart = NULL, *evenStart = NULL; 
  while(temp!=NULL){
	int val = temp->data;
	// If current value is even, add 
    // it to even values list. 
    if(val%2==0){
      if(even==NULL){
        evenStart = temp;
        even = evenStart;
      }
      else{
        even->next = temp;
        even = even->next;
      }
    }
    // If current value is odd, add  
    // it to odd values list.
    else{
      if(odd==NULL){
        oddStart = temp;
        odd = oddStart;
      }
      else{
        odd->next = temp;
        odd = odd->next;
      }
    }
    // Move head pointer one step in forward direction   
    temp = temp->next;
  }
    // If either odd list or even list is empty, 
	// no change is required as all elements  
	// are either even or odd.
  if(oddStart == NULL || evenStart == NULL){ 
        return; 
    } 
    
   // Add odd list after even list. 
  even->next = oddStart;
  odd->next = NULL;
  
  // Modify head pointer to starting of even list.
  *head =  evenStart;
}

int main()
 {
 	// Number of test cases
     int t;
     cin>>t;
     while(t--){
         Node *head = takeInput_better();
         segregateEvenOdd(&head);
    	print(head);
     }
     
	
	return 0;
}
