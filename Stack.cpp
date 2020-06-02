#include<stdio.h>
#include<process.h>
#include<conio.h>
#define MAX_STACK 10
#define NIL -1
typedef struct stacktype
{
 int s1[MAX_STACK];
 int top;
}stack;
void main()
{
 int item,x,choice;
 stack s1;
 s1.top=NIL;
 void push(stack *,int);
 int pop(stack *);
 int peep(stack *);
 int is_overflow(stack *);
 int is_underflow(stack *);
while(1)
{
clrscr();
 printf("\n1 Push");
 printf("\n2 Pop");
 printf("\n3 Peep");
 printf("\n4 Exit");
 printf("\n Enter your choice");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
	 x=is_overflow(&s1);
	 if(x==1)
	 {
	  printf("Stack is overflow");
	 }
	 else
	 {
	  printf("Push the item");
	  scanf("%d",&item);
	  push(&s1,item);
	 }
	 break;
  case 2:
	 x=is_underflow(&s1);
	 if(x==1)
	 {
	  printf("Stack is underflow");
	 }
	 else
	 {
	  item=pop(&s1);
	  printf("popped item: %d",item);
	 }
	 break;
  case 3:
	 x=is_underflow(&s1);
	 if(x==1)
	 {
	  printf("Stack is underflow");
	 }
	 else
	 {
	  item=peep(&s1);
	  printf("item is: %d",item);
	 }
	 break;
  case 4:
	 exit(1);
	 break;
  default:
	 printf("Wrong integer");
 }

getch();
}
}
void push(stack *P,int item)
{
 P->top=P->top+1;
 P->s1[P->top]=item;
}
int pop(stack *P)
{
 int item;
 item=P->s1[P->top];
 P->top=P->top-1;
 return item;
}
int peep(stack *P)
{
 int item;
 item=P->s1[P->top];
}
int is_overflow(stack *P)
{
 if(P->top==MAX_STACK)
    return 1;
 else
    return 0;
}
int is_underflow(stack *P)
{
 if(P->top==NIL)
    return 1;
 else
    return 0;
}
