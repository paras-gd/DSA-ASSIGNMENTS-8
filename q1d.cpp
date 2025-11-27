#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node *l,*r,*p; } Node;
Node* newn(int v,Node* parent){ Node* p=malloc(sizeof(Node)); p->val=v; p->l=p->r=NULL; p->p=parent; return p; }
Node* insert(Node* r,int v,Node* parent){ if(!r) return newn(v,parent); if(v<r->val) r->l=insert(r->l,v,r); else if(v>r->val) r->r=insert(r->r,v,r); return r; }
Node* minimum(Node* r){ while(r && r->l) r=r->l; return r; }
Node* search(Node* r,int x){ while(r){ if(r->val==x) return r; r = x<r->val? r->l : r->r; } return NULL; }
Node* successor(Node* x){
    if(!x) return NULL;
    if(x->r) return minimum(x->r);
    Node* y = x->p;
    while(y && x==y->r){ x=y; y=y->p; }
    return y;
}
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root=NULL;
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); root=insert(root,v,NULL); }
    int x; scanf("%d",&x);
    Node* node = search(root,x);
    Node* s = successor(node);
    printf(s? "%d\n" : "-1\n");
    return 0;
}
