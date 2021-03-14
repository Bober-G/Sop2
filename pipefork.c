#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <limits.h>

int main(int argc, char **argv) {

    int t, n, r, b;

    if (argc != 5) {printf("Wrong arguments\n");return 0;}

    t = atoi(argv[1]); 
    n = atoi(argv[2]); 
    r = atoi(argv[3]); 
    b = atoi(argv[4]); 

    if (t < 50 || t > 500) { printf("Wrong first argument\n");return 0;}
    if (n < 3 || n > 30) {printf("Wrong second argument\n");return 0;}
    if (r < 0 || r > 100) { printf("Wrong third argument\n");return 0;}
    if (b < 1 || b > PIPE_BUF - 6) {printf("Wrong fourth argument\n");return 0;}

int fd1[2];
int fdm_1[2];
int fdm_2[2];
if (pipe(fd1) == -1){
    printf("error with pipe process 1");
    return 1;
}
    
int m1, m2;
int c1, c2;

m1 = fork();
printf ("%d\n", m1);

if (m1 == 0) {

    if (pipe(fdm_1) == -1){
    printf("error m1");
    c1=fork();
    printf ("%d\n", c1);
    if (c1 == 0) {sleep(1);_exit(0);}
    
    return 1;
}

} else {

    m2 = fork();
    printf ("%d\n", m2);


    if (m2 == 0) {

        if (pipe(fdm_2) == -1){
    printf("error with m2");
       c2 = fork();
       printf ("%d\n", c2);
       if (c2 == 0) 
    {
        sleep(1);
        _exit(0);
    }

    } else {
       
    }
}
}
}