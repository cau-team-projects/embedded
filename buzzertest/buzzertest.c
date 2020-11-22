#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define ON 0xFF
#define OFF 0x00

void func(int fd, int freq, int duration) {
    char state;
    int repeat = freq * duration;
    int uT = 1000000/freq;
    while(repeat-->0) {
        state = ON;
        write(fd, &state, sizeof(char));
        usleep(uT/2);
        state = OFF;
        write(fd, &state, sizeof(char));
        usleep(uT/2);
    }
}

int main(int argc, char **argv) {
    int fd = open("/dev/buzzer", O_RDWR);
    
    if(fd < 0) {
        printf("Error loading device.\n");
        return -1;
    }

    if(argc != 3) {
        printf("usage : buzzertest frequency duration\n");
        return -1;
    }

    int freq = atoi(argv[1]);
    int duration = atoi(argv[2]);

    func(fd, freq, duration);
    return 0;
}