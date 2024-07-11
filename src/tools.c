            /**
             * @file tools.c
             * @brief This file contains the all tool function, for the program, just like
             *        `debug()` and gets os type.
             *
             *  TODO: need to write some description comments here XD
             */

            #include <stdio.h>
            #include <stdlib.h>

            #include "tools.h"

            #if defined(_WIN32)
            #define OS 0
            #elif defined(__APPLE__)
            #define OS 1
            #elif defined(__linux__)
            #define OS 2
            #else
            #error "Unsupported operating system"
            #endif

            #if OS == 0
            #include <windows.h>
            #endif

            void debug(httpserver *server)
            {
                if (server == 0)
                {
                    fprintf(stderr, "ERROR: server is not exists!");
                    return;
                }

                char **info = getHttpserverInfo(server);

                printf("=======server info=======\n");
                printf("hostname: \t\t%s", info[0]);
                printf("port: \t\t%s", info[1]);
            }

            char **getEnv()
            {
            #if OS == 0
                char *buffer[1024];
                DWORD hostname = GetEnvironmentVariable("hostname", buffer, sizeof(buffer));
                DWORD port = GetEnvironmentVariable("port", buffer, sizeof(buffer));
                if (hostname == 0 || port == 0)
                {
                    fprintf(stderr, "PATH environment variable not found. \n");
                    exit(1);
                }

                char **array = (char **)malloc(sizeof(2 * (char *)));
                stringArrayCheck(array);
                array[0] = hostname;
                array[1] = port;
                return array;
            #else
                char *host = getenv("hostname");
                char *port = getenv("port");

                if (host == NULL || port == NULL)
                {
                    fprintf(stderr, "environment variable not found. \n");
                    exit(1);
                }

                char **array = (char **)malloc(2 * sizeof(char *));
                stringArrayCheck(array);                                                        

                array[0] = host;
                array[1] = port;

                return array;
            #endif
            }

            void stringArrayCheck(char **arr)
            {
                if (arr == 0)
                {
                    fprintf(stderr, "string array memory allocation failed ! \n");
                    exit(1);
                }
            }

            void structCheck(void* stc)
            {
                if(stc == NULL)
                {
                    fprintf(stderr, "struct memory allocation failed ! \n");
                    exit(1);
                }
            }