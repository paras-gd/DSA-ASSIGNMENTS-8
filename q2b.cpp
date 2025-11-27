#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node *l,*r; } Node;
Node* newn(int v){ Node* p=malloc(sizeof(Node)); p->val=v; p->l=p->r=NULL; return p; }
Node* insert(Node* r,int v){ if(!r) return newn(v); if(v<r->val) r->l=insert(r->l,v); else if(v>r->val) r->r=insert(r->r,v); return r; }
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root=NULL;
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); root=insert(root,v); }
    if(!root){ printf("-1\n"); return 0; }
    Node* t=root;
    while(t->r) t=t->r;
    printf("%d\n", t->val);
    return 0;
}
