//
// Created by jaehyeon on 20. 11. 23.
//

#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/types.h>
#include <android/log.h>

#define DOTM_MAGIC 0xBC
#define DOTM_SET_ALL    _IOW(DOTM_MAGIC, 0, int)
#define DOTM_SET_CLEAR  _IOW(DOTM_MAGIC, 1, int)

#define CLEAR_ALL 7
#define SET_ALL 8

JNIEXPORT jint JNICALL
Java_org_blockinger_game_components_GameState_dotWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd;
    unsigned short ret;
    unsigned char val = data & 0xFF;

    fd = open("/dev/dotmatrix", O_RDWR);
    if(fd < 0) {
        printf("error opening device\n");
    }

    if(val < 7) {
        ret = write(fd, &val, 1);
        if(ret < 0) {
            printf("Write error\n");
        }
    } else {
        switch(val) {
            case CLEAR_ALL :
                ioctl(fd, DOTM_SET_CLEAR, NULL);
                break;
            case SET_ALL :
                ioctl(fd, DOTM_SET_ALL, NULL);
                break;
        }
    }

    close(fd);
    return 0;
}

JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_GameActivity_dotWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd;
    unsigned short ret;
    unsigned char val = data & 0xFF;

    fd = open("/dev/dotmatrix", O_RDWR);
    if(fd < 0) {
        printf("error opening device\n");
    }

    if(val < 7) {
        ret = write(fd, &val, 1);
        if(ret < 0) {
            printf("Write error\n");
        }
    } else {
        switch(val) {
            case CLEAR_ALL :
                ioctl(fd, DOTM_SET_CLEAR, NULL);
                break;
            case SET_ALL :
                ioctl(fd, DOTM_SET_ALL, NULL);
                break;
        }
    }

    close(fd);
    return 0;
}

JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_MainActivity_dotWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd;
    unsigned short ret;
    unsigned char val = data & 0xFF;

    fd = open("/dev/dotmatrix", O_RDWR);
    if(fd < 0) {
        printf("error opening device\n");
    }

    if(val < 7) {
        ret = write(fd, &val, 1);
        if(ret < 0) {
            printf("Write error\n");
        }
    } else {
        switch(val) {
            case CLEAR_ALL :
                ioctl(fd, DOTM_SET_CLEAR, NULL);
                break;
            case SET_ALL :
                ioctl(fd, DOTM_SET_ALL, NULL);
                break;
        }
    }

    close(fd);
    return 0;
}