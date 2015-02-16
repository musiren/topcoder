#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>

#include "log.h"

#define LINE_MAX 1024
#define DEFAULT_LOG_LEVEL LOG_FULL

static const char *const log_level_table [] = { 
    [LOG_DEBUG]     = "debug",
    [LOG_INFO]      = "info",
    [LOG_WARNING]   = "warning",
    [LOG_ERROR]     = "error"
};

void print_log(
    int level,
    const char *file,
    const char *func,
    int line,
    const char *format, ...) {

    char buffer[LINE_MAX];
    struct timespec ts;

    va_list ap;

    va_start(ap, format);
    vsnprintf(buffer, sizeof(buffer), format, ap);
    va_end(ap);

    if (level >= DEFAULT_LOG_LEVEL) {
        clock_gettime(CLOCK_MONOTONIC, &ts);
        printf("[TOPCODER %7s] %6lu.%lu %s:%s(%d) %s\n", log_level_table[level], ts.tv_sec, ts.tv_nsec, file, func, line, buffer);
    }
}
