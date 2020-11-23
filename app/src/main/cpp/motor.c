//
// Created by jaehyeon on 20. 11. 23.
//

#include <stdio.h>
#include <jni.h>
#include <fcntl.h>
#include <unistd.h>
#include <android/log.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#define MOTOR_MAGIC 0xDB
#define MOTOR_SET_ACTION _IOW(MOTOR_MAGIC, 0, int)
#define MOTOR_SET_DIRECTION _IOW(MOTOR_MAGIC, 1, int)
#define MOTOR_SET_SPEED _IOW(MOTOR_MAGIC, 2, int)

#define CW 1
#define CCW -1
#define OFF 0

JNIEXPORT jint JNICALL
Java_org_blockinger_game_components_GameState_motorControl(JNIEnv *env, jobject thiz, jint data, jint data2) {
    // data = motor direction
    // data2 = speed, 0(fast)~255(slow)
    int fd;
    int action, direction, speed;

    fd = open("/dev/motor", O_RDWR);
    if(fd < 0) {
        printf("error opening device\n");
        return -1;
    }

    switch(data) {
        case CW :
            action = 1;
            direction = 1;
            speed = data2;
            ioctl(fd, MOTOR_SET_ACTION, &action, _IOC_SIZE(MOTOR_SET_ACTION));
            ioctl(fd, MOTOR_SET_DIRECTION, &direction, _IOC_SIZE(MOTOR_SET_DIRECTION));
            ioctl(fd, MOTOR_SET_SPEED, &speed, _IOC_SIZE(MOTOR_SET_SPEED));
            break;
        case CCW :
            action = 1;
            direction = 1;
            speed = data2;
            ioctl(fd, MOTOR_SET_ACTION, &action, _IOC_SIZE(MOTOR_SET_ACTION));
            ioctl(fd, MOTOR_SET_DIRECTION, &direction, _IOC_SIZE(MOTOR_SET_DIRECTION));
            ioctl(fd, MOTOR_SET_SPEED, &speed, _IOC_SIZE(MOTOR_SET_SPEED));
            break;
        case OFF :
            action = 0;
            ioctl(fd, MOTOR_SET_ACTION, &action, _IOC_SIZE(MOTOR_SET_ACTION));
    }

    ioctl(fd, MOTOR_SET_ACTION, &action, _IOC_SIZE(MOTOR_SET_ACTION));

    close(fd);
    return 0;
}

JNIEXPORT jint JNICALL
Java_org_blockinger_game_components_MotorTimer_motorControl(JNIEnv *env, jobject thiz, jint time, jint data,
                                                            jint data2) {
    // data = motor direction
    // data2 = speed, 0(fast)~255(slow)
    int fd;
    int action, direction, speed;

    fd = open("/dev/motor", O_RDWR);
    if(fd < 0) {
        printf("error opening device\n");
        return -1;
    }

    switch(data) {
        case CW :
            action = 1;
            direction = 1;
            speed = data2;
            ioctl(fd, MOTOR_SET_ACTION, &action, _IOC_SIZE(MOTOR_SET_ACTION));
            ioctl(fd, MOTOR_SET_DIRECTION, &direction, _IOC_SIZE(MOTOR_SET_DIRECTION));
            ioctl(fd, MOTOR_SET_SPEED, &speed, _IOC_SIZE(MOTOR_SET_SPEED));
            break;
        case CCW :
            action = 1;
            direction = 1;
            speed = data2;
            ioctl(fd, MOTOR_SET_ACTION, &action, _IOC_SIZE(MOTOR_SET_ACTION));
            ioctl(fd, MOTOR_SET_DIRECTION, &direction, _IOC_SIZE(MOTOR_SET_DIRECTION));
            ioctl(fd, MOTOR_SET_SPEED, &speed, _IOC_SIZE(MOTOR_SET_SPEED));
            break;
        case OFF :
            action = 0;
            ioctl(fd, MOTOR_SET_ACTION, &action, _IOC_SIZE(MOTOR_SET_ACTION));
    }

    close(fd);
    return 0;
}