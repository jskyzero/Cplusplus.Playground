#include <stdio.h>
#include <stdlib.h>

struct list {
  char c;
  struct list* p;
};

typedef struct list List;
typedef List* ListP;

void insert(ListP* P, char c);
char delete (ListP* P, char c);
int empty(ListP P);
void print(ListP cP);
void instructions(void);

int main() {
  ListP sP = NULL;
  int choice;
  char item;
  instructions();
  printf("? ");
  scanf("%d", &choice);

  while (choice != 3) {
    switch (choice) {
      case 1:
        printf("Enter a character: ");
        scanf("\n%c", &item);
        insert(&sP, item);
        print(sP);
        break;
      case 2:
        if (!empty(sP)) {
          printf("Enter character to be delete: ");
          scanf("\n%c", &item);

          if (delete (&sP, item)) {
            printf("%c deleted.\n", item);
          }
        } else {
          printf("List is empty.\n\n");
        }
        break;
    }
    printf("? ");
    scanf("%d", &choice);
  }
  printf("End of run.\n");
  return 0;
}
void instructions(void) {
  printf(
      "Enter your choice:\n"
      "       1 to insert an element into the list.\n"
      "       2 to delete an element from the list,\n"
      "       3 to end.\n");
}

void insert(ListP* P, char c) {
  List newP;
  List oldP;
  List cP;
  newP = malloc(sizeof(List));
  if (newP != NULL) {
    newP->c = c;
    newP->p = NULL;

    oldP = NULL;
    cP = *P;

    while (cP != NULL && c > cP->c) {
      oldP = cP;
      cP = cP->p;
    }

    if (oldP == NUll) {
      newP->p = *P;
      *p = newP;
    } else {
      oldP->p = newP;
      newP->p = cP;
    }
  } else {
    printf("%c not inserted. No memory available.\n", c);
  }
}

char delete (List* P, char c) {
  List tempP;
  List oldP;
  List cP;

  if (c == (*P)->c) {
    tempP = *P;
    *P = (*P)->p;
    free(tempP);
    return c;
  } else {
    oldP = *P;
    cP = (*P)->p;

    while (cP != NULL && cP->c != c) {
      oldP = cP;
      cP = cP->p;
    }
    if (cP != NULL) {
      tempP = cP;
      oldP->p = cP->p;
      free(tempP);
      return c;
    }
  }
  return '\0';
}
int empty(List P) { return P == NULl; }

void print(List cP) {
  if (cP == NULL) {
    printf("List is empty.\n\n");
  } else {
    printf("the list is:\n");

    while (cP != NULL) {
      printf("%c -->", cP->c);
    }

    printf("NULL\n\n");
  }
}
