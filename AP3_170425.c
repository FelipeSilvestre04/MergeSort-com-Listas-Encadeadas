#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Lista {
  int dado;
  struct Lista *prox;
} TLista;

typedef TLista *PLista;


PLista inicializa() {
  return NULL;
}

PLista insere(PLista lista, int dado) {
  PLista novo = (PLista)malloc(sizeof(TLista));
  novo->dado = dado;
  novo->prox = NULL;

  if (lista == NULL) {
    return novo;
  } else {
    PLista atual = lista;
    for(atual = lista; atual->prox != NULL; atual=atual->prox);
    atual->prox = novo;
    return lista;
  }
}

PLista divide(PLista lista, int fim) {
  PLista divisa1 = lista;
  for (int i = 0; divisa1 != NULL && i < fim - 1; i++, divisa1 = divisa1->prox);
  if (divisa1 == NULL) {
    return NULL;
  }
  PLista divisa2 = divisa1->prox;
  divisa1->prox = NULL;
  return divisa2;
}

void print(PLista k) {
  PLista l = k;
  while (l != NULL) {
    printf("%d ", l->dado);
    l = l->prox;
  }
}

PLista concat(PLista lista1, PLista lista2) {
  // Percorrer lista2 e inserir elementos em lista1
  while (lista2 != NULL) {
    lista1 = insere(lista1, lista2->dado);
    lista2 = lista2->prox;
  }
  return lista1;
}


PLista merge(PLista p, PLista q) {
  if (p == NULL) return q;
  if (q == NULL) return p;

  PLista r = NULL;
  PLista *ptr = &r;

  while (p != NULL && q != NULL) {
    if (p->dado <= q->dado) {
      *ptr = p;
      p = p->prox;
    } else {
      *ptr = q;
      q = q->prox;
    }
    ptr = &(*ptr)->prox;
  }

  *ptr = (p == NULL) ? q : p;
  
  return r;
}




PLista merge_sort(PLista p, int t, int r, int *contador) {
  (*contador)++;
  if (t < r) {
    int m = t + (r - t) / 2;
    PLista q = divide(p, m - t + 1);
    PLista p1 = merge_sort(p, t, m, contador);
    PLista p2 = merge_sort(q, m + 1, r, contador);
    return merge(p1, p2);
  }
  return p;
}

int main() {
  PLista lista;
  int n;
  lista = inicializa();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    lista = insere(lista, num);
  }
  int k = 0;
  //print(lista);
  PLista ordena;
  ordena = merge_sort(lista, 0, n , &k);
// ordena = divide(lista, n/2);
  print(ordena);
  k = 
printf("\n%i", (int)log2(k));
  return 0;
}
