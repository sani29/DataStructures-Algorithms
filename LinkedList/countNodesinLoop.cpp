#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct Node *newNode(int key)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}
void append(struct Node** headRef, int data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = data;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
void printList(struct Node *tmp){
    while(tmp){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
}

int countNodes(struct Node *n) 
{ 
   int res = 1; 
   struct Node *temp = n; 
   while (temp->next != n) 
   { 
      res++; 
      temp = temp->next; 
   } 
   return res; 
} 
  
/* This function detects and counts loop 
   nodes in the list. If loop is not there 
   in then returns 0 */
int countNodesinLoop(struct Node *list) 
{ 
    struct Node  *slow_p = list, *fast_p = list; 
  
    while (slow_p && fast_p && fast_p->next) 
    { 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
  
        /* If slow_p and fast_p meet at some point 
           then there is a loop */
        if (slow_p == fast_p) 
            return countNodes(slow_p); 
    } 
  
    /* Return 0 to indiciate that ther is no loop*/
    return 0; 
}

/* Drier program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, tmp;
        cin>>n;
        struct Node *head = NULL;
        struct Node* temp;
        struct Node *s;
        struct Node *t;
        cin>>tmp;
        append(&head, tmp);
        s=head;
        for(int i=1; i<n; i++){
            cin>>tmp;
            append(&head, tmp);
        }
        /* Create a loop for testing */
        // srand(time(NULL));
        int c;
        cin>>c;
        if(c>0){
            //c=c-1;
            temp=head;
            t = head;
            while(t->next)t=t->next;
            while(c--)temp=temp->next;
            t->next=temp;
            // s->next=temp;
        }
        //printList(head);
        cout<<countNodesinLoop(head)<<endl;
	}
    return 0;
}
