#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node *l,*r; } Node;
Node* newn(int v){ Node* p=malloc(sizeof(Node)); p->val=v; p->l=p->r=NULL; return p; }
Node* insert(Node* r,int v){ if(!r) return newn(v); if(v<r->val) r->l=insert(r->l,v); else if(v>r->val) r->r=insert(r->r,v); return r; }
Node* findmin(Node* r){ while(r && r->l) r=r->l; return r; }
Node* delete(Node* r,int v){
    if(!r) return NULL;
    if(v<r->val) r->l=delete(r->l,v);
    else if(v>r->val) r->r=delete(r->r,v);
    else{
        if(!r->l){ Node* t=r->r; free(r); return t; }
        else if(!r->r){ Node* t=r->l; free(r); return t; }
        Node* t=findmin(r->r); r->val=t->val; r->r=delete(r->r,t->val);
    }
    return r;
}
int maxDepth(Node* r){ if(!r) return 0; int a=maxDepth(r->l), b=maxDepth(r->r); return 1 + (a>b?a:b); }
int minDepth(Node* r){ if(!r) return 0; if(!r->l) return 1+minDepth(r->r); if(!r->r) return 1+minDepth(r->l); int a=minDepth(r->l), b=minDepth(r->r); return 1 + (a<b?a:b); }

void inorder(Node* r){ if(!r) return; inorder(r->l); printf("%d ",r->val); inorder(r->r); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root=NULL;
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); root=insert(root,v); }
    int q; scanf("%d",&q);
    while(q--){
        int t; scanf("%d",&t);
        if(t==1){ int v; scanf("%d",&v); root=insert(root,v); }
        else if(t==2){ int v; scanf("%d",&v); root=delete(root,v); }
        else if(t==3) printf("%d\n", maxDepth(root));
        else if(t==4) printf("%d\n", minDepth(root));
        else if(t==5){ inorder(root); printf("\n"); }
    }
    return 0;
}
