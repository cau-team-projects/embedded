//
// Created by jaehyeon on 20. 11. 22.
//

#include <jni.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <android/log.h>


JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_MainActivity_ledWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd, ret;
    short value = data & 0xFF;

    fd = open("/dev/led", O_RDWR);

    if(fd < 0) {
        printf("error loading device.\n");
        return -1;
    }

    ret = write(fd, &value, sizeof(short));
    if(ret < 0) {
        printf("Write Error\n");
        return -1;
    }
    close(fd);
    return 0;
}