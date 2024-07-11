#ifndef TOOLS_H
#define TOOLS_H

#include "httpserver.h"

enum Boolean{
    false,
    true
};

void debug(httpserver* server);
char** getEnv();
void stringArrayCheck(char** arr);
void structCheck(void* stc);
#endif