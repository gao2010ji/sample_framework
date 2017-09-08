#ifndef _WORK_MANAGER_H_
#define _WORK_MANAGER_H_

#include "log4z.h"
#include "config.h"

class WorkManager
{
protected:
    WorkManager();
    ~WorkManager();

public:
    static WorkManager* GetInstance();
    int Init(const std::string &config);

private:
    std::string db_ip_;
    std::string db_user_;
    std::string db_pwd_;
    std::vector<int> vec_website_;
};

#endif
