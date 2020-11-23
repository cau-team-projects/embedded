//
// Created by gon on 20. 11. 23.
//

#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <android/log.h>

#define LCD_MAGIC 0x8D
#define LCD_SET_CURSOR_POS _IOW(LCD_MAGIC, 0, int)

JNIEXPORT jint JNICALL
Java_org_blockinger_game_jni_Jni_lcdWrite(JNIEnv *env, jobject thiz, jstring data, jstring data2) {
    int fd, pos;
    fd = open("/dev/lcd", O_WRONLY);
    if (fd < 0) {
        fprintf(stderr, "error opening device\n");
        return -1;
    }

    const char *data_str = (*env)->GetStringUTFChars(env, data, NULL);
    const char *data2_str = (*env)->GetStringUTFChars(env, data2, NULL);
    size_t data_len = (*env)->GetStringUTFLength(env, data);
    size_t data2_len = (*env)->GetStringUTFLength(env, data);

    pos = 0;
    ioctl(fd, LCD_SET_CURSOR_POS, &pos, _IOC_SIZE(LCD_SET_CURSOR_POS));
    write(fd, data_str, data_len);
    pos = 16;
    ioctl(fd, LCD_SET_CURSOR_POS, &pos, _IOC_SIZE(LCD_SET_CURSOR_POS));
    write(fd, data2_str, data2_len);
    (*env)->ReleaseStringUTFChars(env, data, data_str);
    (*env)->ReleaseStringUTFChars(env, data2, data2_str);
    close(fd);
    return 0;
}