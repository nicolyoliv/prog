#include <stdio.h>
#include "empresa.h"



int main(){

int n;

scanf(" %d\n", &n);
tEmpresa** empresa = (tEmpresa**) malloc(n * sizeof(tEmpresa*));
for(int i = 0;i< n; i++){
    empresa[i]= CriaEmpresa();
    LeEmpresa(empresa[i]);
}

for(int i = 0;i< n; i++){
ImprimeEmpresa(empresa[i]);
printf("\n");
ApagaEmpresa(empresa[i]);
}
free(empresa);
    return 0;
}