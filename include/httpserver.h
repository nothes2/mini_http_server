#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "tools.h"

typedef struct HTTPServer_t httpserver;

httpserver* createHttpserver(char* host, int port);
httpserver* createHttpserverByDefault();

char** getHttpserverInfo(httpserver* server);

void freeHttpserver(httpserver* httpserver);

#endif