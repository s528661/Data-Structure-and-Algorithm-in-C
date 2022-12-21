#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/* 実験 1 で作成 */
void printList( struct node* head ){
  /* 内容は自分で作る */
  struct node* p;
  p = head->next;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

/* 実験 3 で作成 */
void append( struct node* head, int x ){
  /* 内容は実験テキストを参照 */
  struct node* p;
  p = head->next;
  if(p == NULL){
    p = (struct node*) malloc(sizeof(struct node));
    p->data = x;
    head->next = p; 
  }else{
    while(p->next != NULL){
        p = p->next;
    }
    p->next = (struct node*) malloc(sizeof(struct node));
    p = p->next;
    p->data = x;
    p->next = NULL;
    head = p;
  }
}

/* 実験 4 で作成 */
void delete( struct node* head ) {
  /* 内容は自分で作る */  
  struct node* p;
  struct node* q;

  if(head != NULL){
    if(head->next == NULL){
        p = head->next;
        free(head);
        head = p;
    }else{
        p = head;
        while(p->next != NULL){
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
        p = NULL;
        head = q;
    }
  }else{
    printf("*** エラー： リストは空です ***");
  }
}

int main(void){
  struct node* head, *p;

  /* 最初にダミーノードを用意しておく */
  head = (struct node*) malloc(sizeof(struct node));
  head->next = NULL;

  append( head, 16 );
  append( head, 28 );
  append( head, 100 );
  
  printf("== 初期状態 ==\n");
  printList( head );

  printf("\n== delete 1 回目 ==\n");
  delete( head );
  printList( head );

  printf("\n== delete 2 回目 ==\n");
  delete( head );
  printList( head );

  printf("\n== delete 3 回目 ==\n");
  delete( head );
  printList( head );

  printf("\n== delete 4 回目 ==\n");
  delete( head );
  printList( head );

  /* 確保したメモリを解放する */
  while (head) {
    p = head->next;
    free(head);
    head = p;
  }

  return 0;
}
