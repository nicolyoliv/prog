#include <stdio.h>


int main(){

    int n;
int y=0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
                y++;
                printf("%d ", y);
            }
 printf("\n");
    }
    return 0;
}