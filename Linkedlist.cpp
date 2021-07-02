#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>

typedef struct lklist    //self referencial structure for linear lklist
  {
    int info;
    struct lklist *next;
  }node;

 void main()
 {  int choice,item,after;
    node *head,*loc;  //starting pointer to point first node of lklist
    head=NULL;   //creation of empty linked list
    void insert_at_begenning(node **,int);
    void traversing(node *);
    void traverse_in_reverse(node *);
    void insert_at_end(node **,int);
    node * search(node *,int);
    void insert_after_element(node *,int,int);
    void delete_at_begenning(node **);
    void delete_at_end(node **);
    void delete_after_element(node **,int);
    void delete_entire_list(node **);

    while(1)
   {  clrscr();
      printf("Single linear linkedlist");
      printf("\n1.Insert in beginning");
      printf("\n2.Insert at the end\n3.Insert after element\n4.Searching");
      printf("\n5.Traversing\n6.Traversing in riverse order\n7.Delete at beginning");
      printf("\n8.Delete at end\n9.delete after element\n10.delete entire list\n11.exit");
      printf("\nEnter your choice");
      scanf("%d",&choice);
      switch(choice)
      {
	case 1: printf("Enter an item");
		scanf("%d",&item);
		insert_at_begenning(&head,item);   //call by pointer
		printf("Insertion done successfully");
		break;
	case 2: printf("Enter the item in end");
		scanf("%d",&item);
		insert_at_end(&head,item);
		break;
	case 3: printf("Enter item to be insert");
		scanf("%d",&item);
		printf("Enter value after which you want to insert");
		scanf("%d",&after);
		insert_after_element(head,item,after);
		break;
	case 4: printf("Enter item to be search");
		scanf("%d",&item);
		loc=search(head,item);
		if(loc!=NULL)
		 printf("Item found");
		else
		 printf("Item not found");
		break;
	case 5: if(head==NULL)
		{
		 printf("List is empty");
		}
		else
		{
		 traversing(head);
		}
		break;
	case 6: if(head==NULL)
		{
		 printf("List is empty");
		}
		else
		{
		traverse_in_reverse(head);
		}
		break;
	case 7: if(head==NULL)
		printf("List is empty");
		else
		delete_at_begenning(&head);
		break;
	case 8: delete_at_end(&head);
		break;
	case 9: printf("Enter the element to delete after");
		scanf("%d",&after);
		delete_after_element(&head,after);
		break;
	case 10:delete_entire_list(&head);
		break;
	case 11: exit(0);
	}//Switch
      getch();
   }
   //While
}//main()
void insert_at_begenning(node ** head,int item)
{
  node *ptr;
  ptr=(node *)malloc(sizeof(node));
  ptr->info=item;
  if(*head==NULL)
  {
   ptr->next=NULL;
  }
  else
  {
   ptr->next=*head;
  }
  *head=ptr;
}
void insert_at_end(node **head,int item)
{
 node *ptr,*loc;
 ptr=(node *)malloc(sizeof(node));
 ptr->info=item;
 ptr->next=NULL;
 if(*head==NULL)
 {
  *head=ptr;
 }
 else
 {
 for(loc=*head;loc->next!=NULL;loc=loc->next);
 }
 loc->next=ptr;
}

node * search(node *head,int item)
{
 node *loc;
 loc=head;
 while(loc!=NULL)
 {
  if(loc->info==item)
    return loc;
  else
    loc=loc->next;
  }
  return NULL;
}
void insert_after_element(node *head,int item,int after)
{
 node *ptr,*loc;
 loc=search(head,after);
 if(loc==NULL)
  printf("Search item is not found");
 ptr=(node *)malloc(sizeof(node));
 ptr->info=item;
 ptr->next=loc->next;
 loc->next=ptr;
}

void traversing(node *loc)
{
 while(loc!=NULL)
 {
  printf("%d->",loc->info);
  loc=loc->next;
}
}
void delete_at_begenning(node **head)
{
node *ptr;
ptr=*head;
if(ptr->next==NULL)
{
   *head=NULL;
}
else
{
   *head=(*head)->next;
   free(ptr);
}
}
void delete_at_end(node **head)
{
node *loc,*bptr;             //bptr=backfoot_pointer
loc=*head;
if(loc->next==NULL)
   *head=NULL;
else
   bptr=NULL;
while(loc->next!=NULL)
{
  bptr=loc;
  loc=loc->next;
}
bptr->next=NULL;
free(loc);
}
void delete_after_element(node **head,int after)
{
 node *ptr,*loc;
 loc=search(*head,after);
 if(loc==NULL)
     return;
 else if(loc->next!=NULL)
    {
     ptr=loc->next;
     loc->next=ptr->next;
     free(ptr);
    }
 else
     printf("Insufficient node");
 return;
}
void delete_entire_list(node **head)
{
 node *loc,*ptr;
 loc=*head;
 while(loc!=NULL)
 {
  ptr=loc;
  loc=loc->next;
  free(ptr);
 }
 *head=NULL;
}
void traverse_in_reverse(node *head)
{
 if(head==NULL)
  return;
 else
 {
  traverse_in_reverse(head->next);
  printf("%d->",head->info);
 }
}
