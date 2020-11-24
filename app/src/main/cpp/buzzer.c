//
// Created by jaehyeon on 20. 11. 22.
//

#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <android/log.h>


JNIEXPORT jint JNICALL
Java_org_blockinger_game_activities_GameActivity_buzzerWrite(JNIEnv *env, jobject thiz, jint data) {
    int fd;
    unsigned char ret;
    int value = data == 0 ? 0 : 1;

    fd = open("/dev/buzzer", O_RDWR);
    if (fd < 0) {
        printf("error loading device\n");
        return -1;
    }

    write(fd, &value, 4);
    sleep(1);
    value = 0;
    write(fd, &value, 4);
    close(fd);

    return 0;
}