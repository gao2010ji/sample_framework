#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "work_manager.h"

using namespace zsummer::log4z;

int main(int argc, char *argv[])
{
    ILog4zManager::getInstance()->setLoggerPath(LOG4Z_MAIN_LOGGER_ID, "./log");
    ILog4zManager::getInstance()->setLoggerLevel(LOG4Z_MAIN_LOGGER_ID, LOG_LEVEL_TRACE);
    //ILog4zManager::getInstance()->setLoggerDisplay(LOG4Z_MAIN_LOGGER_ID, false);
    ILog4zManager::getInstance()->start();

    WorkManager* work = WorkManager::GetInstance();
    if(work->Init("./config.ini") != 0)
    {
        printf("init failed\n");
        return -1;
    }

    return 0;
}