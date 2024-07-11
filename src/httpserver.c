#include <stdlib.h>
#include <stdio.h>

#include "httpserver.h"

typedef struct HTTPServer_t
{
    char* host;
    int port;
}httpserver;

httpserver* createHttpserverByDefault() {
    httpserver* server = (httpserver*)malloc(sizeof(httpserver));
    structCheck(server);

    server->host = "localhost";
    server->port = 80;
    return server;

}

httpserver* createHttpserver(char* host, int port) {
    httpserver* server = (httpserver*)malloc(sizeof(httpserver));
    structCheck(server);

    server->host = host;
    server->port = port;
    return server;
}

char** getHttpserverInfo(httpserver* server) {
    structCheck(server);
    char** array = (char**)malloc(2 * sizeof(char**));

    if(array == NULL) {
        fprintf(stderr, "array memory allocation failed !");
    }

    array[0] = server->host;
    array[1] = (char*)(&(server->port));
    return array;
}

void freeHttpserver(httpserver* server) {
    structCheck(server);
    free(server);
}