#include <stdio.h>
#include <stdlib.h>

void heapify(int *a,int n,int i){
    int largest=i, l=2*i+1, r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest); }
}
void heapsort_inc(int *a,int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){ int t=a[0]; a[0]=a[i]; a[i]=t; heapify(a,i,0); }
}
void heapsort_dec(int *a,int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){ int t=a[0]; a[0]=a[i]; a[i]=t; heapify(a,i,0); }
    // result is increasing in a; reverse for decreasing
    for(int i=0;i<n/2;i++){ int t=a[i]; a[i]=a[n-1-i]; a[n-1-i]=t; }
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    int *a = malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int type; scanf("%d",&type);
    if(type==1) heapsort_inc(a,n);
    else heapsort_dec(a,n);
    for(int i=0;i<n;i++){ if(i) printf(" "); printf("%d",a[i]); }
    printf("\n");
    free(a);
    return 0;
}
