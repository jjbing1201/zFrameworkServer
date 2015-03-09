#ifndef _DATABASE_USERS_
#define _DATABASE_USERS_

#include "include_db.h"

class MIWA_USERS 
{
private:
    std::string tablename;          // abb_main_users
    std::string column_one;         // user_id 
    std::string column_two;         // user_type
    std::string column_three;       // user_basic_id
    std::string column_four;        // user_device_id
    std::string column_five;        // user_detail_id
    std::string column_six;         // user_post_id
    std::string column_seven;       // user_three_id
    std::string column_eight;       // user_backup

public:
    MIWA_USERS();
    virtual ~MIWA_USERS() {}

    std::map<std::string, std::string> insert_USERS(std::string user_type, std::string user_basic_id, std::string user_device_id, std::string user_detail_id, std::string user_post_id, std::string user_three_id, std::string user_backup);

    std::map<std::string, std::string> update_USERS(const std::string &user_id, std::string user_type, std::string user_basic_id, std::string user_device_id, std::string user_detail_id, std::string user_post_id, std::string user_three_id, std::string user_backup);

    std::map<std::string, std::string> update_direct_USERS(const std::string &user_id, std::string which_column, std::string column_context);

    std::map<std::string, std::string> select_by_userid(std::string user_id);

    /* select user by random_number from user_backup. */
    std::map<std::string, std::string> select_by_backup(std::string user_backup);
};

#endif /* _DATABASE_USERS_ */

