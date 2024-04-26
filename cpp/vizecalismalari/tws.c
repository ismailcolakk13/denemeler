#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
    int data;
    struct node* next;
};
int main(){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->next=(struct node*)malloc(sizeof(struct node));
    root->next->next=(struct node*)malloc(sizeof(struct node));
    root->data=15;
    root->next->data=20;
    root->next->next->data=25;
    printf("%d",root->data);

}