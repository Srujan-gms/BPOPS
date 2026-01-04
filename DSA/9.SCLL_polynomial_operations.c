#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
float cf;
int px, py, pz;
int flag;
struct node *link;
};
typedef struct node *NODE;

NODE getnode() {
NODE x = (NODE)malloc(sizeof(struct node));
if (x == NULL) { printf("out of memory\n"); exit(0); }
return x;
}

NODE insert_rear(float cf, int x, int y, int z, NODE head) {
NODE temp, cur;
temp = getnode();
temp->cf = cf; temp->px = x; temp->py = y; temp->pz = z; temp->flag = 0;
cur = head->link;
while (cur->link != head) cur = cur->link;
cur->link = temp;
temp->link = head;
return head;
}

void display(NODE head) {
NODE temp;
if (head->link == head) { printf("polynomial doesn't exist\n"); return; }
temp = head->link;
while (temp != head) {
printf("+ %.2fx^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);
temp = temp->link;
}
printf("\n");
}

NODE add_poly(NODE h1, NODE h2, NODE h3) {
NODE p1, p2;
int x1, y1, z1; float cf1, cf2, cf;
p1 = h1->link;
while (p1 != h1) {
x1 = p1->px; y1 = p1->py; z1 = p1->pz; cf1 = p1->cf;
p2 = h2->link;
while (p2 != h2) {
if (x1 == p2->px && y1 == p2->py && z1 == p2->pz) break;
p2 = p2->link;
}
if (p2 != h2) {
cf = cf1 + p2->cf; p2->flag = 1;
if (cf != 0) h3 = insert_rear(cf, x1, y1, z1, h3);
} else h3 = insert_rear(cf1, x1, y1, z1, h3);
p1 = p1->link;
}
p2 = h2->link;
while (p2 != h2) {
if (p2->flag == 0) h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
p2 = p2->link;
}
return h3;
}

NODE read_poly(NODE head) {
int i, n, px, py, pz; float cf;
printf("enter the no. of terms\n");
scanf("%d", &n);
for (i = 1; i <= n; i++) {
printf("enter coeff, px, py, pz: ");
scanf("%f%d%d%d", &cf, &px, &py, &pz);
head = insert_rear(cf, px, py, pz, head);
}
return head;
}

void polysum() {
NODE h1 = getnode(), h2 = getnode(), h3 = getnode();
h1->link = h1; h2->link = h2; h3->link = h3;
printf("Enter first polynomial:\n"); h1 = read_poly(h1);
printf("Enter second polynomial:\n"); h2 = read_poly(h2);
h3 = add_poly(h1, h2, h3);
display(h1); display(h2); printf("Sum: "); display(h3);
}

void represent_evaluate() {
NODE e1 = getnode(), temp;
int x, y, z; float sum = 0.0;
e1->link = e1;
e1 = read_poly(e1);
display(e1);
printf("Enter values for x, y, z: ");
scanf("%d%d%d", &x, &y, &z);
temp = e1->link;
while (temp != e1) {
sum += temp->cf * pow(x, temp->px) * pow(y, temp->py) * pow(z, temp->pz);
temp = temp->link;
}
printf("Total sum: %f\n", sum);
}

int main() {
int choice;
while (1) {
printf("\n1.Represent/Evaluate\t2.Add Two Poly\t3.Exit\nChoice: ");
scanf("%d", &choice);
switch (choice) {
case 1: represent_evaluate(); break;
case 2: polysum(); break;
case 3: exit(0);
}
}
return 0;
}