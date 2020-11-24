//
// Created by jaehyeon on 20. 11. 23.
//

#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <android/log.h>

#define ERROR -1
#define NOT_PRESSED -2
#define PERSISTING -3

JNIEXPORT jint JNICALL
Java_org_blockinger_game_WorkThread_getInputStatus(JNIEnv *env, jobject thiz, jint prev) {
    // check pushed button at every frame
    // ignore input that has same value from previous one.
    // only one button pushed : execute
    // two or more button pushed : execute last one;
    int fd, cnt = 0, last = -2;
    int input;
    unsigned char ret;
    unsigned char bytevalues[9];

    fd = open("/dev/pushbutton", O_RDWR);
    if (fd < 0) {
        printf("Error opening device\n");
        return ERROR;
    }

    ret = read(fd, &input, sizeof(int));
    if(ret < 0) {
        printf("Read error\n");
        return ERROR;
    }

    for(int i=0; i<9; i++) {
        bytevalues[i] = (input >> i) % 2;
        if(bytevalues[i]) {
            cnt++;
            last = i;
        }
    }

    close(fd);

    switch(cnt) {
        case 0 :
            return NOT_PRESSED;
        case 1 :
            if(last == prev) {
                return PERSISTING;
            } else {
                return last;
            }
        default :
            if(last == prev) {
                return PERSISTING;
            } else {
                return last;
            }
    }
}