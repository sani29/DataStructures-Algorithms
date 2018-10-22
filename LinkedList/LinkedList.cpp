// Implementation of Linked List
#include <iostream>
using namespace std;
#include "Node.cpp"

void printIthNode(Node *head, int i) {
  Node *temp = head;
  int count=-1;
  while(temp!=NULL){
    count++;
    if(count == i){
      cout<<temp->data<<endl;
      return;
    }
    temp = temp->next;
  }
  return;
    
}

int length(Node *head) {
  int count=0;
  Node *temp = head;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
    return count;
}

int lengthR(Node *head){
	Node *temp =head;
	if(temp==NULL){
		return 0;
	}
	return 1 + lengthR(temp->next);
}

Node* takeInput_better(){
	//time complexity = O(n)
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
			//Or
			//tail = newNode;
		}
		cin>>data;
	}
	return head;
}

Node* takeInput(){
	//time complexity = O(n^2)
	int data;
	cin>>data;
	Node *head = NULL;
	while(data!=-1){
		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
		}
		else{
			Node *temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		cin>>data;
	}
	return head;
}

void print(Node *head) {
	//Node *temp = head;
	
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}

	/*
	temp = head;
		while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}*/
}

Node* insertNode(Node *head, int i, int data){
	Node *newNode = new Node(data);
	int count=0;
	Node *temp = head;
	if(i == 0){
		newNode->next = head;
		head = newNode;
		return head;
	}
	while(temp != NULL && count < i-1){
		temp = temp->next;
		count++;
	}
	if(temp!=NULL){
		Node *a = temp->next;
		temp->next = newNode;
		newNode->next = a;
	}
	// Or
	/*newNode->next = temp->next;
	temp->next = newNode;*/
	return head;
}

Node* insertNodeRec(Node *head, int i, int data){
	
	if(head==NULL){
		return head;
	}
	if(i==0){
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}
	Node* ans = insertNodeRec(head->next, i-1, data);
	head->next = ans;
	return head;
}
Node* deleteNode(Node *head, int i){
	int count=0;
	Node *temp = head;
	if(i == 0){
		head = head->next;
		delete temp;
		return head;
	}
	int len = length(head);
	if(i>=len){
		return head;
	}
	while(temp != NULL && count < i-1){
		temp = temp->next;
		count++;
	}
	Node* a = temp->next;
	Node* b = a->next;	
	if(temp!=NULL)
	{
		temp->next = b;
		delete a;
	}
	
	return head;
}

Node* deleteNodeRec(Node *head, int i){
	if(head==NULL){
		return head;
	}
	if(i==0){
		head = head->next;
	}
	Node* ans = deleteNodeRec(head->next, i-1);
	head->next = ans;
}

// 1 2 3 4 5 -1
int main() {
	Node *head = takeInput_better();
	print(head);
	//print length of LL
	/*cout<<length(head)<<endl;
	cout<<lengthR(head)<<endl;*/
	
	// Insert node at position i and data;
	/*int i1, data1;
	cin>>i1>>data1;
	head = insertNode(head, i1, data1);
	print(head);*/
	
	// Insert node recursively at position i2 and data2;
	/*int i2, data2;
	cin>>i2>>data2;
	head = insertNodeRec(head, i2, data2);
	print(head);*/
	
	// delete node at position i3
	/*int i3;
	cin>>i3;
	head = deleteNode(head, i3);
	print(head);*/
	
	// delete node recursively at position i4
	/*int i4;
	cin>>i4;
	head = deleteNodeRec(head, i4);
	print(head);*/
	
	//printIthNode(head, 3);
	
	// Statically
	/*Node n1(1);
	Node *head = &n1;
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	print(head);
	print(head);
	
	n1.next = &n2;
	cout << n1.data << " " << n2.data << endl;

	// Dynamically
	Node *n3 = new Node(10);
	Node *head = n3;	
	Node *n4 = new Node(20);
	n3 -> next = n4;
	*/	
}

