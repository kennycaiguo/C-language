#include<stdio.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* next;
    
}Node;

Node* createList(){
    Node *first,*second,*third;//定义链表节点变量
    first =(Node*) malloc(sizeof(Node));//给节点变量分配内存空间
    second =(Node*) malloc(sizeof(Node));//给节点变量分配内存空间
    third =(Node*) malloc(sizeof(Node));//给节点变量分配内存空间 
    third->next = NULL;
    third->data = 30;
    second->next =third;
    second->data=20;
    first->next = second;
    first->data =10;
    return first;
}

void showNodes(Node *n){
  Node *pn =n;
  while(pn!=NULL){
      printf("node data:%d\n",pn->data);
       pn=pn->next;
       
  }
}
int main() {
    Node *pn =createList();
    showNodes(pn);
    return 0;
}