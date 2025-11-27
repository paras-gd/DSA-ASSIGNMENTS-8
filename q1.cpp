#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node *l,*r; } Node;
Node* newnode(int v){ Node* p=malloc(sizeof(Node)); p->val=v; p->l=p->r=NULL; return p; }

void preorder(Node* r){ if(!r) return; printf("%d ",r->val); preorder(r->l); preorder(r->r); }
void inorder(Node* r){ if(!r) return; inorder(r->l); printf("%d ",r->val); inorder(r->r); }
void postorder(Node* r){ if(!r) return; postorder(r->l); postorder(r->r); printf("%d ",r->val); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node *root=NULL,*nodes[1000]; int idx=0;
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); nodes[idx++]=newnode(v); if(i==0) root=nodes[0]; if(i>0){
        int pi=(i-1)/2;
        if(2*pi+1==i) nodes[pi]->l=nodes[i]; else nodes[pi]->r=nodes[i];
    }}
    preorder(root); printf("\n");
    inorder(root); printf("\n");
    postorder(root); printf("\n");
    return 0;
}
