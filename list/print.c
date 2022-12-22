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

int main(void){
  struct node* head;
  struct node* p;

  /* 最初にダミーノードを用意しておく */
  head = (struct node*) malloc(sizeof(struct node));
  head->next = NULL;

  /* 1 個目のノードを作成 */
  p = (struct node*) malloc(sizeof(struct node));
  p->data = 16;
  head->next = p;  

  /* 2 個目のノードを 1 個目のノードの後ろに作成 */
  p->next = (struct node*) malloc(sizeof(struct node));
  p = p->next;
  p->data = 28;

  /* 3 個目のノードを 2 個目のノードの後ろに作成 */
  p->next = (struct node*) malloc(sizeof(struct node));
  p = p->next;
  p->data = 100;

  /* 3 個目のノードでおしまいなので，next を NULL にする */
  p->next = NULL;

  /* リストの内容が順番に表示される */
  printList(head);

  /* 確保したメモリを解放する */
  while (head) {
    p = head->next;
    free(head);
    head = p;
  }

  return 0;
}
