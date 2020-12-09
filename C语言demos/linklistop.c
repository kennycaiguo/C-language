#include<stdio.h>
#include<malloc.h>

typedef struct linkNode
{
      int data;
      struct linkNode* next;
}LinkNode,*pLinkNode;

pLinkNode creatLink(int data){
     pLinkNode head,tail,p;
     head = tail = (LinkNode*)malloc(sizeof(LinkNode));
     p = (LinkNode*)malloc(sizeof(LinkNode));
     head->next = tail;
     tail->next = NULL;
     p->data = data;
     p->next = NULL;
     tail->next = p;
     tail = p;
     return head;
}

LinkNode* addtotail(LinkNode* no,int data){
       
    return NULL;
}


int GetLinkLength(pLinkNode pl){
     int j = 0;
     while(pl->next!=NULL){
          j++;
          pl = pl->next;
     }
     return j;
}
void main(){
     /*int a[]={2,3,6,7,9,14,56,45,65,67};
     printf("length=%d",sizeof(a)/sizeof(a[0]));*/
     pLinkNode ln =(LinkNode*)malloc(sizeof(LinkNode));
     ln =addtotail(ln,33);
     ln =addtotail(ln,38);
     ln =addtotail(ln,53);
     while(ln->next!=NULL){
           ln = ln->next;
          printf("%d\n",ln->data);
         
     }
    // printf("length=%d",GetLinkLength(ln));
}