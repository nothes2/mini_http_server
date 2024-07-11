/**
 * @file main.c
 * @brief entrance of the whole projeect.
 * 
 * The pupose of this project is for a corss-platform mini-httpserver,
 * this program can handle basic request like post, get, etc .. and it 
 * also has route feature, it makes you access your static file easier!
 * I'm planning to add more feature in the future! thank you for using 
 * this program :>
 */

#include <stdio.h>

#include "main.h"

int main(int argc, char** argv) {
    char** arrEnv = getEnv();
    httpserver* server = createHttpserverByDefault();
    debug(server, false);
    return 0;
}
