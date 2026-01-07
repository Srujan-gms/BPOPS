#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
char usn[16];
char name[64];
char branch[16];
int sem;
char phone_no[16];
struct student *link;
};
typedef struct student STUD;

STUD *read_data() {
char usn[16], name[64], branch[16], phone[16];
int sem;
STUD *temp;
temp = (STUD *)malloc(sizeof(STUD));
printf("Enter the Students Details:\n");
printf("Enter USN\n");
scanf("%15s", usn);
strncpy(temp->usn, usn, sizeof(temp->usn));
temp->usn[sizeof(temp->usn)-1] = '\0';
printf("Enter Name\n");
scanf("%63s", name);
strncpy(temp->name, name, sizeof(temp->name));
temp->name[sizeof(temp->name)-1] = '\0';
printf("Enter Branch \n");
scanf("%15s", branch);
strncpy(temp->branch, branch, sizeof(temp->branch));
temp->branch[sizeof(temp->branch)-1] = '\0';
printf("Enter Semester\n");
scanf("%d", &sem);
temp->sem = sem;
printf("Enter Phone Number\n");
scanf("%15s", phone);
strncpy(temp->phone_no, phone, sizeof(temp->phone_no));
temp->phone_no[sizeof(temp->phone_no)-1] = '\0';
temp->link = NULL;
return temp;
}

STUD *insert_front(STUD *first) {
STUD *temp;
temp = read_data();
temp->link = first;
return temp;
}

STUD *insert_end(STUD *first) {
STUD *temp, *prev;
temp = read_data();
if (first == NULL) return temp;
prev = first;
while (prev->link != NULL) prev = prev->link;
prev->link = temp;
return first;
}

STUD *delete_front(STUD *first) {
STUD *cur;
if (first == NULL) {
printf("List is empty\n");
return first;
}
cur = first;
first = first->link;
free(cur);
return first;
}

STUD *delete_end(STUD *first) {
STUD *prev, *cur;
if (first == NULL) {
printf("List is empty\n");
return first;
}
if (first->link == NULL) {
free(first);
return NULL;
}
prev = NULL;
cur = first;
while (cur->link != NULL) {
prev = cur;
cur = cur->link;
}
prev->link = NULL;
free(cur);
return first;
}

void display(STUD *first) {
STUD *temp;
int count = 0;
if (first == NULL) {
printf("List is empty\n");
return;
}
printf("USN\tNAME\tBRANCH\tSEM\tPHONE NO.\n");
temp = first;
while (temp != NULL) {
printf("%s\t%s\t%s\t%d\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phone_no);
temp = temp->link;
count++;
}
printf("The number of nodes in SLL=%d\n", count);
}

int main(void) {
int ch, i, n;
STUD *first = NULL;
// clrscr(); // Environment specific
printf("Creation of SLL of N Students\n");
printf("Enter the number of students\n");
scanf("%d", &n);
for (i = 1; i <= n; i++) first = insert_front(first);
printf("SLL Created Successfully!!!\n");
display(first);
while (1) {
printf("\n1.Display\t2.Insert End\t3:Delete End\n4.Insert Front\t5.Delete Front\t6.Exit\n");
printf("Enter the choice\n");
scanf("%d", &ch);
switch (ch) {
case 1: display(first); break;
case 2: first = insert_end(first); printf("Node Inserted at the End\n"); break;
case 3: first = delete_end(first); break;
case 4: first = insert_front(first); printf("Node Inserted at Front\n"); break;
case 5: first = delete_front(first); break;
case 6: exit(0); break;
default: printf("INVALID CHOICE !");
}
}
return 0;
}
