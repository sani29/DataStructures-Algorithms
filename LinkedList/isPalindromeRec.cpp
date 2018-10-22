// Check whether Linked list is Palindrome or not recursively
#include <iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput_better(){
	int data;
	cin>>data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data!=-1){
		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = tail->next;
		}
		cin>>data;
	}
	return head;
}
bool isPalindromeUtil(Node** left, Node* right){
	if(right==NULL){
		return true;
	}
	
	bool ispl = isPalindromeUtil(left, right->next);
	if(ispl==false){
		return false;
	}
	
	bool ispl1 = (right->data == (*left)->data);
	*left = (*left)->next;
	return ispl1;
}
bool check_palindrome(Node* head)
{
    isPalindromeUtil(&head, head); 
	
}

void print(Node *head) {
	
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}

int main(){
	Node *head = takeInput_better();
	print(head);
	cout<<check_palindrome(head)<<endl;
	
}
