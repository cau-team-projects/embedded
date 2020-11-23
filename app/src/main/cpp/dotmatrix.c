//
// Created by jaehyeon on 20. 11. 23.
//

#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <android/log.h>

JNIEXPORT jint JNICALL
Java_org_blockinger_game_components_GameState_dotWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd;
    unsigned short ret;
    unsigned char val = data & 0xFF;

    fd = open("/dev/dotmatrix", O_RDWR);
    if(fd < 0) {
        printf("error opening device\n");
    }

    ret = write(fd, &val, 1);
    if(ret < 0) {
        printf("Write error\n");
    }

    close(fd);
    return 0;
}