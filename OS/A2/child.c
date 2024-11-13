#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
printf("\n Child Process: Reversing the array passed as arguments...\n");
for (int i = argc - 1; i > 0; i--) {
printf("%s ", argv[i]);
}
printf("\n\n Array reversed successfully!\n");
return 0;
}
