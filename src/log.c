#include "log.h"

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_MSG_LEN 1024

void logi(const char* msg, ...) {
	char log_msg_buf[LOG_MSG_LEN] = {0};

	va_list args;
    va_start(args, msg);
	vsprintf(log_msg_buf, msg, args);
	va_end(args);

    fprintf(stderr, "INFO: %d: %s\n", getpid(), log_msg_buf);

    fflush(stderr);
}
