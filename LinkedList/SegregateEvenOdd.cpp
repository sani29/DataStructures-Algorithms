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
