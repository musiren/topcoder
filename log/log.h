#include <stdarg.h>

typedef enum LOG_LEVEL {
    LOG_FULL,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_MAX,
    LOG_INVALID = -1
} LOG_LEVEL;

void print_log(
    int level,
    const char *file,
    const char *func,
    int line,
    const char *format, ...);

#define log_debug(...)      print_log(LOG_DEBUG, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_info(...)       print_log(LOG_INFO, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_warning(...)    print_log(LOG_WARNING, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define log_error(...)      print_log(LOG_ERROR, __FILE__, __func__, __LINE__, __VA_ARGS__)
