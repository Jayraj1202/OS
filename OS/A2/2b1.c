#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
void bubbleSort(int arr[], int n) {
printf("\n Sorting Started \n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n-1; j++) {
if (arr[j] > arr[j+1]) {
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
printf("\n Sorting Completed! \n");
for (int i = 0; i < n; i++) {
printf("%d\n", arr[i]);
}
}
void tostring(char str[], int num) {
sprintf(str, "%d", num);
}
int main(int argc, char *argv[]) {
printf("\n This is the main process: ");
printf("\n Process Id: %d", getpid());
printf("\n Parent Id: %d", getppid());
int n;
printf("\n Enter the Number of elements:\n");
scanf("%d", &n);
int arr[n];
printf("Enter the Numbers:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
printf("\n\n Sorting Array using Bubble Sort:\n");
bubbleSort(arr, n);
printf("\n Forking the current process...\n");
pid_t cpid = fork();
if (cpid > 0) { // Parent process
printf("\n Parent is Running: ParentID: %d \n It's ID: %d \n", getppid(), getpid());
printf("\n Parent is waiting for child to complete...\n\n");
wait(NULL); // Wait for child process to finish
printf("\n Parent Exiting...\n");
} else if (cpid == 0) { // Child process
printf("\n Child is Running: ParentID: %d \n It's ID: %d \n", getppid(), getpid());
// Prepare arguments to pass to execv
char *arrChar[n+2];
arrChar[0] = "child";
for (int i = 0; i < n; i++) {
char *string = (char *)malloc(20 * sizeof(char));
tostring(string, arr[i]);
arrChar[i+1] = string;
}
arrChar[n+1] = NULL;
printf("\n Child Calling EXECV System Call...\n");
execv("./child.out", arrChar);
perror("execv failed");
exit(1);
} else {
printf("Error in fork()");
exit(1);
}
return 0;
}

