//
// Created by tang on 24-2-18.
//
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char * const * argv) {

    // 收到SIGHUP后忽略信号
    //signal(SIGHUP,SIG_IGN);

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("fork() 进程出错\n");
    } else if (pid == 0) {
        // 子进程这个条件会满足
        printf("子进程开始执行\n");
        setsid();
        for (;;) {
            sleep(1);
            printf("子进程休息1秒\n");
        }
        return 0;
    } else {
        // 父进程走到这里
        for (;;) {
            sleep(1);
            printf("父进程休息1秒\n");
        }
        return 0;
    }



    printf("程序退出,再见\n");
    return 0;
}