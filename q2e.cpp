#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node *l,*r; } Node;
Node* newn(int v){ Node* p=malloc(sizeof(Node)); p->val=v; p->l=p->r=NULL; return p; }
Node* insert(Node* r,int v){ if(!r) return newn(v); if(v<r->val) r->l=insert(r->l,v); else if(v>r->val) r->r=insert(r->r,v); return r; }
Node* search_rec(Node* r,int x){ if(!r) return NULL; if(r->val==x) return r; return x<r->val? search_rec(r->l,x) : search_rec(r->r,x); }
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root=NULL;
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); root=insert(root,v); }
    int x; scanf("%d",&x);
    Node* r = search_rec(root,x);
    printf(r? "Found\n":"NotFound\n");
    return 0;
}
