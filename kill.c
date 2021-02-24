#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

int main(int argc, char**argv) {
    if(seteuid(atoi(argv[1])) != 0) {
        printf("seteuid failed... %d", errno);
    }
    if(kill(-1, SIGTERM) != 0) {
    printf("kill failed...%d", errno);
    }

    return 0;
}
