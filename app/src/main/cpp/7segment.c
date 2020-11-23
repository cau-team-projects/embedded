//
// Created by jaehyeon on 20. 11. 23.
//

#include <jni.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <android/log.h>

JNIEXPORT jint JNICALL
Java_org_blockinger_game_components_GameState_SSegWrite(JNIEnv *env, jobject thiz, jlong data) {
    int fd;
    unsigned char ret;
    unsigned char bytevalues[4];

    fd = open("/dev/7segment", O_RDWR);
    if (fd < 0) {
        printf("error loading device\n");
    }

    for(int i=3; i>=0; i--) {
        bytevalues[i] = data % 10;
        data /= 10;
    }

    ret = write(fd, bytevalues, 4);
    if (ret < 0) {
        printf("Write error\n");
    }

    close(fd);
    return 0;
}

JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_GameActivity_SSegWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd;
    unsigned char ret;
    unsigned char bytevalues[4];

    fd = open("/dev/7segment", O_RDWR);
    if (fd < 0) {
        printf("error loading device\n");
    }

    for(int i=3; i>=0; i--) {
        bytevalues[i] = data % 10;
        data /= 10;
    }

    ret = write(fd, bytevalues, 4);
    if (ret < 0) {
        printf("Write error\n");
    }

    close(fd);
    return 0;
}

JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_MainActivity_SSegWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd;
    unsigned char ret;
    unsigned char bytevalues[4];

    fd = open("/dev/7segment", O_RDWR);
    if (fd < 0) {
        printf("error loading device\n");
    }

    for(int i=3; i>=0; i--) {
        bytevalues[i] = data % 10;
        data /= 10;
    }

    ret = write(fd, bytevalues, 4);
    if (ret < 0) {
        printf("Write error\n");
    }

    close(fd);
    return 0;
}