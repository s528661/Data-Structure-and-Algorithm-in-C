#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Tnode {
  int data;
  struct Tnode *left;
  struct Tnode *right;
};

/* 木構造を構築する関数： データ x を木へ追加する */
void insert(struct Tnode **tp, int x) {
  struct Tnode *p;
  struct Tnode *tn;

  /* 新しくノードを 1 個用意しておく */
  tn = (struct Tnode *)malloc(sizeof(struct Tnode));
  tn->data = x;
  tn->left = tn->right = NULL;

  /*------------------------------------------------
     重要: ここでは (*tp) が tree と同じ意味を持つ
    ------------------------------------------------*/
  if (NULL == (*tp)) {
    (*tp) = tn; /* 木が空の場合 */
  } else {
    /* 木が空でない場合 */
    p = (*tp);

    while (1) {
      if (p->data < x) {
        if (NULL != p->right) { /* 右の子が存在する場合 */
          p = p->right; /* 右の子が存在している場合，そこから同じ処理を繰り返す
                         */
        } else {        /* 右の子が存在しない場合 */
          p->right = tn;
          break; /* while ループの終了 */
        }
      } else {
        if (NULL != p->left) { /* 左の子が存在する場合 */
          p = p->left; /* 左の子が存在している場合，そこから同じ処理を繰り返す
                        */
        } else {       /* 左の子が存在しない場合 */
          p->left = tn;
          break; /* while ループの終了 */
        }
      }
    }
  }
}

/* 実験 1 で作成：データ x が木に含まれているかどうかを調べる */
/* 含まれていれば 1, さもなくば 0 を返す */
int contains(struct Tnode *tree, int x) {
  struct Tnode *p;

  if (NULL == tree) {
    return 0; /* 木が空なので 0 を返す */
  }

  p = tree;
  while (1) {
    if (p->data == x) {
      return 1;
    }

    /* 上の insert 関数を参考に，この部分を埋めて完成させよ．*/
    else if (p->data < x) {
        if (NULL != p->right) { /* 右の子が存在する場合 */
          p = p->right; /* 右の子が存在している場合，そこから同じ処理を繰り返す
                         */
        } else {        /* 右の子が存在しない場合 */
          p->right = NULL;
          break; /* while ループの終了 */
        }
    } else {
        if (NULL != p->left) { /* 左の子が存在する場合 */
          p = p->left; /* 左の子が存在している場合，そこから同じ処理を繰り返す
                        */
        } else {       /* 左の子が存在しない場合 */
          p->left = NULL;
          break; /* while ループの終了 */
        }
    }
  }
  return 0;
}

/* 確保されたメモリを解放するための関数の宣言．main関数の後ろで定義 */
void freeTree(struct Tnode *tree);

int main(void) {
  struct Tnode *tree;
  int x;

  tree = NULL;
  printf("整数データを木構造に格納します\n");
  printf("いくつか入力してください(入力終りは -1)\n");
  while (1) {
    scanf("%d", &x);
    if (-1 == x) {
      break;
    }
    insert(&tree, x);
  }

  printf("整数データを木構造から探します\n");
  printf("いくつか入力してください(入力終りは -1)\n");
  while (1) {
    scanf("%d", &x);
    if (-1 == x) {
      break;
    }
    if (contains(tree, x) == 1) {
      printf(" %d はあります\n", x);
    } else {
      printf(" %d はありません\n", x);
    }
  }

  /* 確保されたメモリを解放する */
  freeTree(tree);

  return 0;
}

void freeTree(struct Tnode *tree) {
  assert(tree);

  if (tree->left) {
    freeTree(tree->left);
  }
  if (tree->right) {
    freeTree(tree->right);
  }

  tree->left = tree->right = NULL;
  free(tree);
}
