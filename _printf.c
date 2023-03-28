#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    for (const char *p = format; *p; p++) {
        if (*p == '%') {
            switch (*(++p)) {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    for (const char *s = va_arg(args, const char *); *s; s++) {
                        count += putchar(*s);
                    }
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    return -1;
            }
        } else {
            count += putchar(*p);
        }
    }
    va_end(args);
    return count;
}

