#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/* 実験 2 で作成 */
int search( struct node* head, int x ){
  /* 内容は自分で作る */
  int i;
  struct node* p;

  i = 1;
  p = head->next;
  while(p != NULL){
    if(p->data == x){
        return i;
    }
    p = p->next;
    i++;
  }

  return -1;
}

int main(void){
  struct node* head;
  struct node* p;
  int n, x;

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

  /* x を読み込み，それがリスト内の何番目にあるか調べる */
  printf("目的の値を入力して下さい > ");
  scanf("%d", &x);

  n = search(head, x);
  if ( -1 == n ){
     printf("%d は見つかりませんでした\n", x);
  }
  else{
     printf("%d は %d 番目に見つかりました\n", x, n);
  }

  /* 確保したメモリを解放する */
  while (head) {
    p = head->next;
    free(head);
    head = p;
  }

  return 0;
}
