#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (int i = 0; i < len; i++) {
        printf("%.2x", start[i]);
//        printf("-");
    }
    printf("\n ");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main() {
    printf("Hello, World!\n");
    test_show_bytes(12345);
    /*  12345的十六进制0x00003039
     * 输出：
     * 39300000     由此可的mac为小端法机器
     * 00e44046
     * 58baeaeafe7f0000
     *
     *
     *
     */
    printf("Hello, World!\n");
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp,1);
    show_bytes(valp,2);
    show_bytes(valp,3);
    printf("Hello, World!3\n");
    const char *s= "abcdef";
    show_bytes((byte_pointer) s,strlen(s));
    return 0;
}
