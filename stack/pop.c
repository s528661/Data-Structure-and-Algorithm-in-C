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


/* 実験 2 で作成 */
/* スタックが空（ダミーノードのみ）ならば 1 を
   さもなくば 0 を return する */
int is_empty( struct node* sp ){
  /* 内容は自分で作る */
  if(sp->next == NULL){
    return 1;
  }else{
    return 0;
  }
}

/* 実験 2 で作成 */
int pop( struct node* sp ){
  struct node* p;
  int x;

  if ( is_empty( sp ) ){
    printf(" *** スタックは空です ***\n");
    return -1;
  }

  p = sp->next;
  x = p->data;

  /* これ以降の部分は自分で作る */  
  p = p->next;
  free(sp->next);
  sp->next = p;

  return x;
}

int main(void){
  struct node* sp;

  /* 先頭にダミーノードを作っておく */
  sp = (struct node*) malloc(sizeof(struct node) );
  sp->next = NULL;

  push( sp, 16 );
  push( sp, 28 );
  push( sp, 100 );

  printList( sp );

  while ( !is_empty( sp ) ){
    printf("スタックは空でありません\n");
    printf("取り出したデータ = %d\n\n", pop( sp ) );
    printList(sp);
  }
  printf("スタックが空になりました\n");

  pop( sp );

  /* 確保されたメモリを解放する */
  free( sp );
  
  return 0;
}
