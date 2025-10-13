#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *file_path = "shared_file.txt";
    int fd; // File descriptor
    struct flock lock;

    printf("WRITER (PID: %d): Đang cố gắng mở và khóa file...\n", getpid());

    // Mở file để đọc và ghi
    fd = open(file_path, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Không thể mở file");
        exit(1);
    }

    // Thiết lập khóa ghi độc quyền (exclusive lock)
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // Khóa toàn bộ file

    printf("WRITER (PID: %d): Đang chờ để khóa file...\n", getpid());

    // Yêu cầu khóa, F_SETLKW sẽ block cho đến khi khóa được cấp
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Không thể khóa file");
        close(fd);
        exit(1);
    }

    printf("WRITER (PID: %d): ĐÃ KHÓA FILE. Đang ghi...\n", getpid());

    // Ghi vào file
    const char *message = "Xin chào từ tiến trình ghi!\n";
    write(fd, message, strlen(message));

    // Giả vờ đang làm việc gì đó trong khi giữ khóa
    sleep(5);

    // Mở khóa file
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Không thể mở khóa file");
        close(fd);
        exit(1);
    }

    printf("WRITER (PID: %d): Đã mở khóa và đóng file.\n", getpid());
    close(fd);

    return 0;
}