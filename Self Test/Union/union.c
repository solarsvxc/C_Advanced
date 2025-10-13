#include <stdio.h>
#include <string.h>

// Khai báo một union có tên là Data
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    // Khởi tạo một biến union
    union Data data;

    printf("Kích thước của union Data: %zu bytes\n", sizeof(data));
    printf("----------------------------------------\n");

    // 1. Gán giá trị cho thành viên integer
    data.i = 10;
    printf("Gán data.i = 10\n");
    printf("data.i: %d\n", data.i);
    // Tại thời điểm này, truy cập các thành viên khác sẽ cho ra dữ liệu rác
    // vì bộ nhớ đang được diễn giải như một số nguyên.
    printf("data.f: %f (dữ liệu rác)\n\n", data.f);


    // 2. Gán giá trị cho thành viên float
    data.f = 220.5;
    printf("Gán data.f = 220.5\n");
    printf("data.f: %f\n", data.f);
    // Bây giờ, giá trị của data.i đã bị ghi đè và không còn là 10 nữa.
    printf("data.i: %d (dữ liệu rác)\n\n", data.i);


    // 3. Gán giá trị cho thành viên chuỗi ký tự
    strcpy(data.str, "Hello C");
    printf("Gán data.str = \"Hello C\"\n");
    printf("data.str: %s\n", data.str);
    // Cả data.i và data.f đều đã bị ghi đè.
    printf("data.f: %f (dữ liệu rác)\n", data.f);
    printf("data.i: %d (dữ liệu rác)\n", data.i);


    return 0;
}