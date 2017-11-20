#include <stdlib.h>
#include <stdio.h>
#include <untistd.h>

int domaths( int n ){
  n *= 2;
  return n;
}

int main(){
  int desc[2];
  p = pipe(desc);
  // f = fork();

  if (p == 0 && f == 0){
    int r = rand() % 100;
    printf("[parent] sending: %d\n", r);
    printf("[child] doing maths on: %d\n", r);
    domaths(r);
    printf("[parent] received: %d\n", r);
    return 0;
    
  }

}
