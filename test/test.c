#include <stdio.h>

#include "unity.h"
#include "tools.h"

void setUp(void) 
{

}

void tearDown(void)
{

}

void test_env(void) 
{
    char** array = getEnv();
    printf("host: %s\nport: %s\n", array[0], array[1]);
}

int main()
{
    
}