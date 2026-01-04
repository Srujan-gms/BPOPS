#include<stdio.h>
#include<stdlib.h>

struct node {
char ssn[11], name[11], dept[12], desig[12];
int phno;
float sal;
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
NODE temp, FIRST = NULL, END = NULL;

NODE getnode() {
NODE x;
x = (NODE)malloc(sizeof(struct node));
return x;
}

void read() {
float sal;
int phno;
temp = getnode();
temp->llink = NULL;
temp->rlink = NULL;
printf("Enter SSN: ");
fgets(temp->ssn, sizeof(temp->ssn)*3, stdin);
printf("Enter Name: ");
fgets(temp->name, sizeof(temp->name)*3, stdin);
printf("Enter dept: ");
fgets(temp->dept, sizeof(temp->dept)*3, stdin);
printf("Enter designation: ");
fgets(temp->desig, sizeof(temp->desig)*3, stdin);
printf("Enter phno: ");
scanf("%d", &phno); 
temp->phno = phno;
printf("Enter salary: ");
scanf("%f", &sal);
temp->sal = sal;
}

void Create_DLL() {
int n, i = 0;
printf("Enter the number of Employees to be added: ");
scanf("%d", &n); getchar();
while (i != n) {
i++;
printf("Enter the details of the %d employee\n", i);
read();
if (FIRST == NULL) {
FIRST = temp;
END = temp;
} else {
END->rlink = temp;
temp->llink = END;
END = temp;
}
}
printf("Creation of DLL for %d is done", i);
}

void display_count() {
NODE temp1 = FIRST;
int count = 1;
if (temp1 == NULL) {
printf("the employee detail is NULL and count is 0\n");
} else {
printf("\nSSN\tName\tDept\tDesgn\tPhno\tSal\n");
while (temp1 != END) {
count++;
printf("\n%s\t%s\t%s\t%s\t%d\t%f\n", temp1->ssn, temp1->name, temp1->dept, temp1->desig, temp1->phno, temp1->sal);
temp1 = temp1->rlink;
}
printf("\n%s\t%s\t%s\t%s\t%d\t%f\n", temp1->ssn, temp1->name, temp1->dept, temp1->desig, temp1->phno, temp1->sal);
printf("the student count is %d\n", count);
}
}

void Insertionfront() {
printf("Enter the details of the employee\n");
read();
if (FIRST == NULL) {
FIRST = temp;
END = temp;
} else {
temp->rlink = FIRST;
FIRST->llink = temp;
FIRST = temp;
}
}

void Insertionend() {
printf("enter the deatils of the new employee\n");
read();
if (FIRST == NULL) {
FIRST = temp;
END = temp;
} else {
END->rlink = temp;
temp->llink = END;
END = temp;
}
}

void Deletionfront() {
NODE temp2;
if (FIRST == NULL) printf("List is empty\n");
else if (FIRST == END) {
printf("Record with %s SSN is deleted\n", FIRST->ssn);
FIRST = NULL; END = NULL;
} else {
temp2 = FIRST;
printf("Record with %s SSN is deleted\n", FIRST->ssn);
FIRST = FIRST->rlink;
FIRST->llink = NULL;
free(temp2);
}
}

void Deletionend() {
NODE temp2 = END;
if (temp2 == NULL) printf("List is empty\n");
else if (FIRST == END) {
printf("Record with %s SSN is deleted\n", FIRST->ssn);
FIRST = NULL; END = NULL;
} else {
printf("Record with %s SSN is deleted\n", END->ssn);
END = END->llink;
END->rlink = NULL;
free(temp2);
}
}

void demonstration() {
int choice;
while (1) {
printf("\n1.Insertion front\t2.Insertion end\t3.deletion front\t4.deletion end\t5.Display\t6.Exit\n");
scanf("%d", &choice); getchar();
switch (choice) {
case 1: Insertionfront(); break;
case 2: Insertionend(); break;
case 3: Deletionfront(); break;
case 4: Deletionend(); break;
case 5: display_count(); break;
case 6: return;
}
}
}

int main() {
int choice;
while (1) {
printf("\n1.create DLL\t2.Display\t3.Insert front\t4.Insert end\t5.Delete front\t6.Delete end\t7.dQueue Demo\t8.Exit\n");
scanf("%d", &choice); getchar();
switch (choice) {
case 1: Create_DLL(); break;
case 2: display_count(); break;
case 3: Insertionfront(); break;
case 4: Insertionend(); break;
case 5: Deletionfront(); break;
case 6: Deletionend(); break;
case 7: demonstration(); break;
case 8: exit(0);
}
}
return 0;
}