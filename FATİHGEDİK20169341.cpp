#include <iostream>
#include<cstdlib>

using  namespace std ;
struct node 
 {
 	int data ;
 	struct node *next;
 	struct node *prev;
 };
 //Insert Functions
 struct node *  createNode (int);
 struct node * insertempty(struct node *header, int Data);
 struct node * insertFront(struct node *header, int Data);
 struct node * insertBack(struct node *header, int Data);
 void insertAfter (struct node *header, int Data );
 void deleteAfter (struct node *);
 
 void display(struct node *start);
 
 //Main Function
 int main(void)
 {
 	cout<<"Fatih Gedik 20169341"<<endl;
 	
 	struct node *start = NULL;
	start=insertempty(start,8);
	display(start);
 	start= insertFront (start,2);
 	display(start);
 	start=insertBack(start,9);
	display(start);		
 	insertAfter(start , 3);
 	display(start);
 	deleteAfter(start);
 	display(start);
 	
 


return 0;
}

//InsertAfter Function
void insertAfter(struct node *afterNode ,int data)
{
	struct node * temp = createNode(data);
	temp->next = afterNode->next;
	afterNode->next = temp;
	afterNode->prev = temp;
	
}

//InsertFront Function
struct node * insertFront(struct node *start, int Data)
{
if (start==NULL)
{
return start;
}
struct node * temp = createNode(Data);
temp->next = start;
temp-> prev = start;
start=temp;
return start;
}

//InsertBack Function
struct node * insertBack(struct node *start, int Data)
{
struct node * last = createNode(Data);
struct node * starttemp;
if (start->next== NULL)
{	start=last;
return start;}
starttemp=start;
while(starttemp->next != NULL)
starttemp=starttemp->next;
starttemp->next = last;
starttemp->prev = last;
starttemp=start;
return start;
}

//DeleteAfter  Function
void deleteAfter(struct node *afterNode)
{
	struct node * temp;
	if(afterNode->next==NULL || afterNode==NULL)
	return;
	temp = afterNode->next;
	afterNode->next=temp->next;
	free(temp);
	
	
}


//Display Function
void display(struct node *start)
{
if (start== NULL)
cout << "List is empty" << endl;
struct node *temp =start;
while (temp != NULL)
{
cout << temp->data << "  ---->  ";
temp=temp->next;
}
cout << endl;
}

//CreateNode Function
struct node * createNode(int item)
{
	struct node * temp;
	temp = (struct node *) malloc(sizeof(node));
	temp->data = item;
	temp->next = NULL;
	return temp;
	
	
	
} 
//Ýnsertempty Function	
struct node * insertempty(struct node *start, int Data)
{
if (start!=NULL)
{
return start;
}
struct node * temp = createNode(Data);
temp->next = start;
start=temp;
return start;
}
 	
