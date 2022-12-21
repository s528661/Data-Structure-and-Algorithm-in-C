#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/* 実験 1 で作成 */
void printList( struct node* head ) {
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


int main(void){
  struct node* head;
  int x;
  struct node* p;

  /* 最初にダミーノードを用意しておく */
  head = (struct node*) malloc(sizeof(struct node));
  head->next = NULL;

  printf("値を繰り返し入力して下さい（-1で終了）: \n");
  /* 内容は自分で作る： */
  /*  scanf で値を読み込みながら append でその値をリストに追加 */
  /* （ヒント）while 文で繰り返す */
  while(scanf("%d", &x)){
    if (x == -1){
        break;
    }
    append(head, x);
  }
  printList(head);

  /* 確保したメモリを解放する */
  while (head) {
    p = head->next;
    free(head);
    head = p;
  }

  return 0;
}
