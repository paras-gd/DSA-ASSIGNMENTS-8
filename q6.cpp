#include <stdio.h>
#include <stdlib.h>

typedef struct Heap{ int *a, sz, cap; } Heap;
Heap* create(int c){ Heap* h=malloc(sizeof(Heap)); h->a=malloc(c*sizeof(int)); h->sz=0; h->cap=c; return h; }
void swap(int *x,int *y){ int t=*x; *x=*y; *y=t; }
void push(Heap* h,int v){ if(h->sz==h->cap){ h->cap*=2; h->a=realloc(h->a,h->cap*sizeof(int)); } h->a[h->sz++]=v; int i=h->sz-1; while(i && h->a[(i-1)/2] > h->a[i]){ swap(&h->a[(i-1)/2], &h->a[i]); i=(i-1)/2; } }
int top(Heap* h){ return h->sz? h->a[0] : -1; }
int pop(Heap* h){ if(h->sz==0) return -1; int ret=h->a[0]; h->a[0]=h->a[--h->sz]; int i=0; while(1){ int l=2*i+1, r=2*i+2, s=i; if(l<h->sz && h->a[l]<h->a[s]) s=l; if(r<h->sz && h->a[r]<h->a[s]) s=r; if(s==i) break; swap(&h->a[i], &h->a[s]); i=s; } return ret; }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Heap* h=create(16);
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); push(h,v); }
    int q; scanf("%d",&q);
    while(q--){
        int t; scanf("%d",&t);
        if(t==1){ int v; scanf("%d",&v); push(h,v); }
        else if(t==2) printf("%d\n", pop(h));
        else if(t==3) printf("%d\n", top(h));
    }
    return 0;
}
