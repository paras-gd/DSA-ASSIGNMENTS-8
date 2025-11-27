#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{ int val; struct Node *l,*r; } Node;
Node* newn(int v){ Node* p=malloc(sizeof(Node)); p->val=v; p->l=p->r=NULL; return p; }

int isBSTUtil(Node* r,long minv,long maxv){ if(!r) return 1; if(r->val<=minv || r->val>=maxv) return 0; return isBSTUtil(r->l,minv,r->val) && isBSTUtil(r->r,r->val,maxv); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* nodes[1000]; for(int i=0;i<n;i++) nodes[i]=NULL;
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); if(v==INT_MIN) nodes[i]=NULL; else nodes[i]=newn(v); }
    for(int i=0;i<n;i++){
        if(!nodes[i]) continue;
        int l=2*i+1, r=2*i+2;
        if(l<n) nodes[i]->l = (nodes[l]==NULL? NULL: nodes[l]);
        if(r<n) nodes[i]->r = (nodes[r]==NULL? NULL: nodes[r]);
    }
    Node* root = nodes[0];
    printf(isBSTUtil(root, (long)INT_MIN-1, (long)INT_MAX+1) ? "True\n":"False\n");
    return 0;
}
