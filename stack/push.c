#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/* 前回の実験 1 で作成 */
void printList( struct node* head ){
  /* 内容省略 */ 
  struct node* p; 
  p = head->next;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

/* 実験 1 で作成 */
void push( struct node* sp, int x ){
  /* 内容は自分で作る */
  struct node* p;
  p = sp->next;
  sp->next = (struct node*) malloc(sizeof(struct node) );
  (sp->next)->data = x;
  (sp->next)->next = p;
}

/* 確保されたメモリを解放するための関数の宣言．main関数の後ろで定義 */
void freeList( struct node* head );


int main(void){
  struct node* sp;

  /* 先頭にダミーノードを作っておく */
  sp = (struct node*) malloc(sizeof(struct node) );
  sp->next = NULL;

  push( sp, 16 );
  push( sp, 28 );
  push( sp, 100 );

  printList( sp );

  /* 確保されたメモリを解放する */
  freeList( sp );

  return 0;
}

void freeList(struct node* head)
{
  struct node* p;
  while (head) {
    p = head->next;
    free(head);
    head = p;
  }
}
