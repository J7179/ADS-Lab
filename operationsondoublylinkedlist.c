#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *prev;
struct node *next;
};

struct node *head = NULL, *t = NULL;
struct node *newNode, *d;
int count = 0;


void create();
void ins_beg();
void ins_end();
void ins_pos();
void del_beg();
void del_end();
void del_pos();
void display();  

void create() {
int v;
newNode = (struct node*)malloc(sizeof(struct node));
if (newNode == NULL) {
printf("Memory allocation failed!\n");
} else {
printf("Enter the value for node:\n");
scanf("%d", &v);
newNode->data = v;
newNode->prev = NULL;
newNode->next = NULL;
}
}

void ins_beg() {
create();
if (head == NULL) {
head = newNode;
} else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
printf("\nNode inserted at beginning\n");
count++;
}

void ins_end() {
create();
t = head;
if (head == NULL) {
head = newNode;
} else {
while (t->next != NULL) {
    t = t->next;
}
newNode->prev = t;
t->next = newNode;
}
printf("\nNode inserted at the end\n");
count++;
}

void ins_pos() {
int pos, i;
t = head;
printf("Enter position to insert:\n");
scanf("%d", &pos);

if (pos == 1) {
ins_beg();
} else if (pos == count + 1) {
ins_end();
} else if (pos > 1 && pos <= count) {
create();
for (i = 1; i < pos - 1; i++) {
    t = t->next;
}
newNode->prev = t;
newNode->next = t->next;
if (t->next != NULL) {
    t->next->prev = newNode;
}
t->next = newNode;
printf("\nNode inserted at position %d\n", pos);
count++;
} else {
printf("Invalid position\n");
}
}

void del_beg() {
if (head == NULL) {
printf("\nLinked list is empty\n");
} else if (head->next == NULL) {
d = head;
head = NULL;
free(d);
printf("\nNode deleted from beginning\n");
count--;
} else {
d = head;
head = head->next;
head->prev = NULL;
free(d);
printf("\nNode deleted from beginning\n");
count--;
}
display();
}

void del_end() {
if (head == NULL) {
printf("\nLinked list is empty\n");
} else if (head->next == NULL) {
d = head;
head = NULL;
free(d);
printf("\nNode deleted from end\n");
count--;
} else {
d = head;
while (d->next != NULL) {
    d = d->next;
}
d->prev->next = NULL;
free(d);
printf("\nNode deleted from end\n");
count--;
}
display();  
}

void del_pos() {
int pos, i;
printf("Enter position to delete:\n");
scanf("%d", &pos);

if (head == NULL) {
printf("\nLinked list is empty\n");
} else if (pos == 1) {
del_beg();
} else if (pos == count) {
del_end();
} else if (pos > 1 && pos < count) {
d = head;
for (i = 1; i < pos - 1; i++) {
    d = d->next;
}
struct node *temp = d->next;
d->next = temp->next;
if (temp->next != NULL) {
    temp->next->prev = d;
}
free(temp);
printf("\nNode deleted from position %d\n", pos);
count--;
} else {
printf("\nInvalid position\n");
}
display();  
}

void display() {
if (head == NULL) {
printf("\nLinked list is empty\n");
} else {
printf("Linked list is:\n");
t = head;
while (t != NULL) {
    printf("%d\t", t->data);
    t = t->next;
}
printf("\n");
}
}

int main() {
int ch;
printf("\nDoubly linked list operations\n");
printf("1. Insert at beginning\n2. Insert at end\n3. Insert at a specific position\n4. Delete from beginning\n5. Delete from end\n6. Delete from a specific position\n7. Display\n8. Exit\n");

while (1) {
printf("\nEnter your choice: ");
scanf("%d", &ch);

switch (ch) {
case 1:
ins_beg();
break;
case 2:
ins_end();
break;
case 3:
ins_pos();
break;
case 4:
del_beg();
break;
case 5:
del_end();
break;
case 6:
del_pos();
break;
case 7:
display();
break;
case 8:
printf("Exiting...\n");
exit(0);
default:
printf("Invalid choice, please try again.\n");
}
}
return 0;
}
