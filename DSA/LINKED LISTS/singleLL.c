#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert_beg(struct node *);
void insert_end(struct node *);
void del_beg();
void del_end();
void traverse();

void insert_beg(struct node *new1) {
    if(head==NULL)
    head = new1;
    else {
        new1->next = head;
        head = new1;
    }
}
void insert_end(struct node *new1) {
    struct node *temp=head;
    if(head==NULL){
        head = new1;
    }
    else {
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new1;
    }
}
void del_beg() {
    if(head==NULL)
    printf("No elements to delete \n");
    else
    head = head->next;
}
void del_end() {
    struct node *temp,*temp1;
    temp = head;
    temp1 = head;
    if(head==NULL)
    printf("No elements to delete \n");
    else
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp1->next != temp){
        temp1 = temp1->next;
    }
    temp1->next = NULL;
    free(temp);
    temp = NULL;
}
void traverse() {
    struct node *temp=head;
    if(head==NULL)
    printf("Underflow");
    else {
        while(temp!= NULL) {
           printf("%d",temp->data);
           temp = temp->next; 
        printf("\n"); 
        }
    }
}
int main() {
    int choice;
    struct node *new1;
    while(1){
        printf("\n 1.Insert-beg 2.Insert-end 3.Delete-beg 4.Delete-end 5.Traverse 6.Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            new1 = (struct node*)malloc(sizeof(struct node));
            printf("Enter the value :"); 
            scanf("%d",&new1->data);
            new1->next=NULL;
            insert_beg(new1);
            break;
            
            case 2:
            new1 = (struct node*)malloc(sizeof(struct node));
            printf("Enter the value :"); 
            scanf("%d",&new1->data);
            new1->next=NULL;
            insert_end(new1);
            break;
            
            case 3:
            del_beg();
            break;
            
            case 4:
            del_end();
            break;
            
            case 5:
            traverse();
            break;
            
            case 6:
            exit(1);
            break;
            
            default:
            printf("Wrong choice, enter again");
        }
    }
}