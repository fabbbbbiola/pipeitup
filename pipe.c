#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  int parent[2];
  int child[2];
  int READ = 0;
  int WRITE = 1;
  pipe(parent);
  pipe(child);
  int f = fork();

  if (f == 0){
    close(parent[READ]);
    close(child[WRITE]);
    int r = 8;
    write(parent[WRITE], &r, sizeof(int));
    printf("parent sending: %d\n", r);
    int result;
    read(child[READ], &result, sizeof(int));
    printf("parent received: %d\n", result);
    
  }

  else{
    close(parent[WRITE]);
    close(child[READ]);
    int result;
    read(parent[READ], &result, sizeof(int));
    printf("child doing maths on: %d\n", result);
    int r = result / 2;
    write(child[WRITE], &r, sizeof(int));
  }

}
