#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "work_manager.h"

using namespace zsummer::log4z;
using namespace phxrpc;

WorkManager::WorkManager()
{

}

WorkManager::~WorkManager()
{

}

WorkManager* WorkManager::GetInstance()
{
    static WorkManager p;
    return &p;
}

int WorkManager::Init(const std::string &config)
{
    Config cfg;
    if(!cfg.InitConfig(config.c_str()))
    {
        LOGFMTE("read config file: %s", config.c_str());
        return -1;
    }

    char value[512] = { 0 };
    char default_value[] = "error";

    cfg.ReadItem("MYSQL", "ip", value, sizeof(value), default_value);
    assert(strcmp(value, default_value) != 0);
    db_ip_ = value;

    cfg.ReadItem("MYSQL", "user", value, sizeof(value), default_value);
    assert(strcmp(value, default_value) != 0);
    db_user_ = value;

    cfg.ReadItem("MYSQL", "password", value, sizeof(value), default_value);
    assert(strcmp(value, default_value) != 0);
    db_pwd_ = value;

    cfg.ReadItem("WEBSITE", "website", value, sizeof(value), default_value);
    assert(strcmp(value, default_value) != 0);
    printf("%s", value);
    try
    {
        std::stringstream ss;
        ss.str(value);
        std::string item;
        while(std::getline(ss, item, ','))
        {
            vec_website_.push_back(std::stoi(item));
        }
    }
    catch(const std::exception &e)
    {
        LOGFMTE("split website failed: %s", e.what());
        return -1;
    }

    LOGFMTD("ip = %s, user = %s, password = %s", db_ip_.c_str(), db_user_.c_str(), db_pwd_.c_str());
    for(const auto &x : vec_website_)
    {
        LOGFMTD("website = %d", x);
    }
    LOGFMTD("init success");
    return 0;
}
