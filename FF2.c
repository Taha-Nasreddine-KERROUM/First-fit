#include<stdio.h>

void FirstFit ( int *p, int *b, int *a ) {
    for ( int *P = p; *P; ++P )
        for ( int *B = b; *B; ++B )
            if ( *B >= *P && a[B - b] == -1 ) {
                *B -= *P;
                a[B - b] = P - p;
                break;
            }
}

int internal_Frag ( int *b ) {
    int frag = 0;
    for ( int i = 0; i < 10; ++i )
        if ( b[i] )
            frag += b[i];
    return frag;
}

int main() {
    int p[10] = {0}, b[10] = {0}, alloc[10],
        pnum, bnum;
        
    for(int i = 0; i < 10; i++)
        alloc[i] = -1;
        
    printf("- no of process: ");
    scanf("%d", &pnum);
    
    printf("- no of blocks: ");
    scanf("%d", &bnum);
    
    printf("- Size of each process:\n");
    for(int i = 0; i < pnum; i++) {
        printf("\tProcess %d: ", i);
        scanf("%d", p + i);
    }
    
    printf("- block sizes:\n");
    for(int i = 0; i < bnum; i++) {
        printf("\tBlock %d: ", i);
        scanf("%d", b + i);
    }
    
    FirstFit( p, b, alloc );
    
    
    printf("\nBlock Allocation:");
    for(int i = 0; i < bnum; i++) {
        printf("\nBlock %d -> ", i);
        if(alloc[i] != -1) {
            printf("Process %d", alloc[i]);
        } else {
            printf("free");
        }
    }
    
    printf("\n\nInternal Fragmentation: %d\n", internal_Frag(b));
    
    return 0;
}
