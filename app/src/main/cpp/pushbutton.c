//
// Created by jaehyeon on 20. 11. 23.
//

#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <android/log.h>

#define UDELAY 1000000

int translate(int value) {
    unsigned char bytevalues[9];
    int cnt = 0;
    int last = -1;
    for(int i=0; i<9; i++) {
        bytevalues[i] = (value >> 2*i) % 2;
        cnt = bytevalues[i] ? cnt + 1 : cnt;
        last = bytevalues[i] ? i : last;
    }
    if(cnt == 0) {
        return 0;
    } else if (cnt == 1) {
        return last;
    }
}

JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_GameActivity_setInput(JNIEnv *env, jobject thiz) {
    int fd, flag;
    unsigned char ret;
    int value = 0;

    fd = open("/dev/pushbutton", O_RDWR);
    if(fd < 0) {
        printf("Error opening device\n");
    }

    while(1) {
        read(fd, &value, sizeof(int));
        flag = translate(value);
        if(flag != 0) break;
        else usleep(UDELAY);
    }

    return flag;
}

JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_ThreadForInput_setInput(JNIEnv *env, jobject thiz) {
    int fd, flag;
    unsigned char ret;
    int value = 0;

    fd = open("/dev/pushbutton", O_RDWR);
    if(fd < 0) {
        printf("Error opening device\n");
    }

    while(1) {
        read(fd, &value, sizeof(int));
        flag = translate(value);
        if(flag != 0) break;
        else usleep(UDELAY);
    }

    return flag;
}