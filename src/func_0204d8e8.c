// NONMATCHING: base materialization / addressing (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Node { struct Node* next; struct Node* prev; };
struct List { struct Node* head; int count; };
struct Node* func_0204d8e8(struct List* l, struct Node* n){
  if(n->next == 0){
    if(l->head == n) l->head = 0;
    else n->prev->next = 0;
  } else {
    if(l->head == n){
      l->head = n->next;
      l->head->prev = 0;
    } else {
      n->next->prev = n->prev;
      n->prev->next = n->next;
    }
  }
  l->count = l->count - 1;
  return n;
}
