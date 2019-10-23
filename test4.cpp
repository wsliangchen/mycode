#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int fd[2];
void parentRead(int times) {
    char msg[100];
    memset(msg, '\0', sizeof(msg));
    ssize_t s = read(fd[0], msg, sizeof(msg));
    if (s <= 0)
        printf("read error!\n");
    printf("parent %d read: %s\n",times, msg);
}

int main() {
    int ret = pipe(fd);
    if (ret == -1) {
        printf("Open pipe error\n");
        return 1;
    }
    pid_t id_one = fork();
    if (id_one == 0) {     // child
        close(fd[0]);      //子进程关闭读指针
        char *p1 = "Child 1 is sendign a message!";
        write(fd[1], p1, strlen(p1) + 1);
    } else {               // parent
        parentRead(1);
    }
    pid_t id_two;          // son process 2 start
    if (id_one > 0) {
        id_two = fork();
        if (id_two == 0) { // child
            close(fd[0]);  //子进程关闭读指针
            char *p2 = "Child 2 is sendign a message!";
            write(fd[1], p2, strlen(p2) + 1);
        } else {           // parent
            close(fd[1]);  //父进程关闭写指针
            parentRead(2);
        }
    }

    return 0;
}
