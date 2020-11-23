//
// Created by jaehyeon on 20. 11. 23.
//

#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <android/log.h>
#include <sys/types.h>
#include <stdlib.h>

#define UDELAY 10000

/*
JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_GameActivity_setInput(JNIEnv *env, jobject thiz) {
    int fd;
    unsigned char ret;
    pid_t pid;

    fd = open("/dev/pushbutton", O_RDWR);
    if(fd < 0) {
        printf("Error opening device\n");
    }

    switch(pid = fork()) {
        case -1 :
            // fork failed

    }
    return fd;
}

 */