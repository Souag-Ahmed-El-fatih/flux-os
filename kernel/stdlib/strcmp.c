

/*
 * ===== Flux operating system ====
 * (2026-2027)
 * GNU GPL (v3.0)
 * ================================ 
 * creat by : Souag Ahmed El fatih
 * https://github.com/SouagAhmedElfatih/flux_os
 * 
 * File : C header
 * bit core File
 *
 * 
*/

#include <flux/stdint.h>


// هاذي الدوال قياسية تقدر تتكبتها او انك تستخرجها من مكتبات قياسية 
// Compare two strings
int strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const uint8_t *)s1 - *(const uint8_t *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    while (n != 0 && *s1 != '\0' && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0;
    }
    return *(const uint8_t *)s1 - *(const uint8_t  *)s2;
}


/*
    ملاحظة جد مهم للمبتدئين :
    عنجما نكتب 
    char n[] = "Hello";
    char *name = &n; 
    ثم 
    *name = 'h';
    ستصبح n = "hello"
    ثم اذا وضعنا 
    *name++;
    سينتقل للحرف ثاني اي انه تقدر تعدل في
    n[1]
    و هكذا و هذي طريقة هي نفس طريقة التالية :
    char n[] = "Hello";'
    char *name = &n;
    name[0] = 'h';
    نفس الطريقة لكن اولى تنفع اذا لم تكن تحتاج لاستخدام سلسة بشكل متكرر
    او تريد قراءتها.
*/