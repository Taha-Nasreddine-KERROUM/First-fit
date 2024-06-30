#include<stdio.h>

void FirstFit ( int *p, int pn, int *b, int bn, int *a ) {
    for ( int i = 0; i < pn; ++i )
        for ( int j = 0; j < bn; ++j )
            if ( b[j] >= p[i] && a[j] == -1 ) {
                b[j] -= p[i]; // subtract the size of the process from the block's
                a[j] = i; // i for the number of the process j for the num of the block
                          // to keep trackin which process is in which block
                break;
            }
}

int internal_Frag ( int *b, int bn ) {
    int frag = 0;
    for ( int i = 0; i < bn; ++i )
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
    
    FirstFit( p, pnum, b, bnum, alloc );
    
    
    printf("\nBlock Allocation:");
    for(int i = 0; i < bnum; i++) {
        printf("\nBlock %d -> ", i);
        if(alloc[i] != -1) {
            printf("Process %d", alloc[i]);
        } else {
            printf("free");
        }
    }
    
    printf("\n\nInternal Fragmentation: %d\n", internal_Frag(b, bnum));
    
    return 0;
}
