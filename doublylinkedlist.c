#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *prev;
struct node *next;
};
struct node *head=NULL,*t=NULL;
struct node *new,*d;
int count=0;
void create()
{
int v;
new=(struct node *)malloc(sizeof(struct node));
if(new==NULL)
{
printf("List is empty");
}
else
{
printf("Enter the value to node:");
scanf("%d",&v);
new->data=v;
new->prev=NULL;
new->next=NULL;
}
}
void ins_beg()
{
create();
if(head==NULL)
{
head=new;
}
else{
new->next=head;
head->prev=new;
head=new;
}
printf("Node inserted at begining\n");
count++;
}
void ins_end(){
create();
t=head;
if(head==NULL){
head=new;
}
else{
while(t->next!=NULL)
{
t=t->next;
}
new->prev=t;
t->next=new;
}
printf("Node inserted at end\n");
count++;
}
void ins_pos(){
int pos,i;
t=head;
printf("Enter position to insert:");
scanf("%d",&pos);
if(pos==1){
ins_beg();}
else if(pos==count+1)
ins_end();
else if(pos<count+1)
{
create();
t=head;
for(i=1;i<pos-1;i++)
{
t=t->next;
}
new->prev=t;
new->next=t->next;
t->next=new;
printf("Node inserted in the given position %d\n",pos);
count++;
}
else{
printf("Wrong position");
}
}
void del_beg()
{
if(head==NULL)
{
printf("Linked list is empty\n");
}
else if(head->next==NULL)
{
d=head;
head=NULL;
free(d);
printf("Node deleted from begining\n");
count--;
}
else
{
d=head;
head=head->next;
free(d);
printf("Node deleted from begining\n");
count--;
}
}
void del_end()
{
if(head==NULL)
{
printf("\nLinked list is empty");
}
else if(head->next==NULL)
{
d=head;
head=NULL;
free(d);
printf("Node deleted from end\n");
count--;
}
else
{
d=head;
while(d->next!=NULL)
{
d=d->next;
}
d->prev->next=NULL;
free(d);
printf("Node deleted from end\n");
count--;
}

}
void del_pos()
{
int pos,i;
printf("Enter position to delete:");
scanf("%d",&pos);
if(head==NULL)
{
printf("\nLinked list is empty");
}
else if(pos==1)
{
del_beg();
}
else if(pos==count)
{
del_end();
}
else if(pos<=count)
{
d=head;
for(i=1;i<=pos-1;i++)
{
d=d->next;
}
d->prev->next=d->next;
d->next->prev=d->prev;
free(d);
printf("Node deleted from position %d\n",pos);
count--;
}
else
{
printf("\n Wrong position");
}
}


void display(){
if(head==NULL)
{
printf("\nLinked list is empty");
}
else
{
printf("Linked list is:\n");
t=head;
while(t!=NULL)
{
printf("%d\t",t->data);
t=t->next;
}
}
}
int main()
{
int ch;
printf("\nDoubly linked list...");
printf("\n1.Insertion from beginning \n2.Insertion from end \n3.Insertion at a particular position\n4.Deletion from beginning \n5.Deletion from end\n6.Deletion from a particular position\n7.Display \n8.Exit");
while(1)
{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:ins_beg();
break;
case 2:ins_end();
break;
case 3:ins_pos();
break;
case 4:del_beg();
break;
case 5:del_end();
break;
case 6:del_pos();
break;
case 7: display();
break;
case 8:printf("exit");
exit(0);
default:
printf("Wrong choice");
break;
}
}
return 0;
}
