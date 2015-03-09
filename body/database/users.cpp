#include "users.h"

MIWA_USERS::MIWA_USERS()
{
    tablename="abb_main_users";
    column_one="user_id";
    column_two="user_type";
    column_three="user_basic_id";
    column_four="user_device_id";
    column_five="user_detail_id";
    column_six="user_post_id";
    column_seven="user_three_id";
    column_eight="user_backup";
}

std::map<std::string, std::string> MIWA_USERS::insert_USERS(std::string user_type, std::string user_basic_id, std::string user_device_id, std::string user_detail_id, std::string user_post_id, std::string user_three_id, std::string user_backup)
{
    /* 1. using bottom to get insert cmd. */
    std::map<std::string, std::string> result;

    /* 1.1 statement bottom using. */
    DAL_Bottom bottom;
    std::map<int, std::string> cmd;

    /* 1.2 combine vars. */
    std::vector<std::string> tmp;
    tmp.push_back("0");
    tmp.push_back(user_type);
    tmp.push_back(user_basic_id);
    tmp.push_back(user_device_id);
    tmp.push_back(user_detail_id);
    tmp.push_back(user_post_id);
    tmp.push_back(user_three_id);
    tmp.push_back(user_backup);

    cmd = bottom.insert_Bottom(tablename, tmp.size(), tmp);

    /* 2. get return of execute. */
    if (cmd[0] == "false")
    {
        result["Status"] = "failed";
        result["Info"] = "409";
        result["body"] = "<<< cmd >>> combine Error -> USERS INSERT.";
    }else{
        int getdo = datacon::GetInstance().mysql_execute(cmd[1]);
        if (getdo == 0)
        {
            result["Status"] = "success";
            result["Info"] = "200";
            result["body"] = "success";
            datacon::GetInstance().commit_result();
        }else{
            result["Status"] = "failed";
            result["Info"] = "408";
            result["body"] = "<<< cmd >>> Doing Failed -> USERS INSERT.";
        }
    }
    return result;
}

std::map<std::string, std::string> MIWA_USERS::update_USERS(const std::string &user_id, std::string user_type, std::string user_basic_id, std::string user_device_id, std::string user_detail_id, std::string user_post_id, std::string user_three_id, std::string user_backup)
{
    /* 1. statement return result. */
    std::map<std::string, std::string> result;

    /* 2. statement bottom using. */
    DAL_Bottom bottom;
            
    /* 3. combine cmd. */
    std::map<int, std::string> cmd;
        
    std::map<std::string, std::string> changevar;
    changevar[column_two] = user_type;
    changevar[column_three] = user_basic_id;
    changevar[column_four] = user_device_id;
    changevar[column_five] = user_detail_id;
    changevar[column_six] = user_post_id;
    changevar[column_seven] = user_three_id;
    changevar[column_eight] = user_backup;
    
    std::map<std::string, std::string> cmdvar;
    cmdvar[column_one] = user_id;
    
    cmd = bottom.update_direct_Bottom(tablename, changevar, "None", cmdvar);

    /* 4. get return. */
    if (cmd[0] == "false")
    {   
        result["Status"] = "failed";
        result["Info"] = "409";
        result["body"] = "<<< cmd >>> combine Error -> USERS UPDATE Single by doingid.";
    }else{
        int getdo = datacon::GetInstance().mysql_execute(cmd[1]);
        if (getdo == 0)
        {   
            result["Status"] = "success";
            result["Info"] = "200";
            result["body"] = "success";
            datacon::GetInstance().commit_result();
        }else{
            result["Status"] = "failed";
            result["Info"] = "408";
            result["body"] = "<<< cmd >>> Doing Failed -> USERS UPDATE.";
        }   
    }       
        
    return result;
}

std::map<std::string, std::string> MIWA_USERS::update_direct_USERS(const std::string &user_id, std::string which_column, std::string column_context)
{
    /* 1. statement return result. */
    std::map<std::string, std::string> result;

    /* 2. statement bottom using. */
    DAL_Bottom bottom;

    /* 3. combine cmd. */
    std::map<int, std::string> cmd;
    std::string get_judge_column;
    if (which_column == "2")
        get_judge_column = column_three;
    else if (which_column == "3")
        get_judge_column = column_four;
    else if (which_column == "4")
        get_judge_column = column_five;
    else if (which_column == "5")
        get_judge_column = column_six;
    else if (which_column == "6")
        get_judge_column = column_seven;
     
    cmd[0] = "success";
    cmd[1] = "update "+tablename+" set "+get_judge_column+" = "+
              column_context+" where "+column_one+" = "+user_id+";";


    /* 4. get return. */
    if (cmd[0] == "false")
    {
        result["Status"] = "failed";
        result["Info"] = "409";
        result["body"] = "<<< cmd >>> combine Error -> USERS UPDATE Single by doingid.";
    }else{
        int getdo = datacon::GetInstance().mysql_execute(cmd[1]);
        if (getdo == 0)
        {
            result["Status"] = "success";
            result["Info"] = "200";
            result["body"] = "success";
            datacon::GetInstance().commit_result();
        }else{
            result["Status"] = "failed";
            result["Info"] = "408";
            result["body"] = "<<< cmd >>> Doing Failed -> USERS UPDATE.";
        }
    }

    return result;
}

std::map<std::string, std::string> MIWA_USERS::select_by_userid(std::string user_id)
{
    /* 1. statement return result. */
    std::map<std::string, std::string> result;

    /* 2. statement bottom using. */
    BASE base;
    DAL_Bottom bottom;

    /* 3. combine cmd. */
    std::map<int, std::string> cmd;
    std::map<std::string, std::string> cmdvar;
    cmdvar[column_one]=user_id;

    cmd = bottom.select_direct_Bottom(tablename, "None", cmdvar);

    /* 4. get return. */
    if (cmd[0] == "false")
    {
        result["Status"] = "failed";
        result["Info"] = "409";
        result["body"] = "<<< cmd >>> combine Error -> MIWA_USERS SELECT Single by id";
    }else{
        std::string getcmddoing = datacon::GetInstance().get_execute_result(cmd[1]);
        int check_getcmddoing = base.doingjudge(getcmddoing);
        if (check_getcmddoing == 1)
        {
            result["Status"] = "failed";
            result["Info"] = "408";
            result["body"] = "<<< cmd >>> doing Error -> USERS SELECT Single by id";
        }else{
            result["Status"] = "success";
            result["Info"] = "200";
            result["body"] = getcmddoing;
        }
    }

    return result;
}

std::map<std::string, std::string> MIWA_USERS::select_by_backup(std::string user_backup)
{
    /* 1. statement return result. */
    std::map<std::string, std::string> result;
    
    /* 2. statement bottom using. */
    BASE base;
    DAL_Bottom bottom;
    
    /* 3. combine cmd. */
    std::map<int, std::string> cmd;
    std::map<std::string, std::string> cmdvar;
    cmdvar[column_eight]=user_backup;
    
    cmd = bottom.select_direct_Bottom(tablename, "None", cmdvar);
    
    /* 4. get return. */
    if (cmd[0] == "false")
    {
        result["Status"] = "failed";
        result["Info"] = "409";
        result["body"] = "<<< cmd >>> combine Error -> MIWA_USERS SELECT Single by id"; 
    }else{
        std::string getcmddoing = datacon::GetInstance().get_execute_result(cmd[1]);    
        int check_getcmddoing = base.doingjudge(getcmddoing);
        if (check_getcmddoing == 1)
        {
            result["Status"] = "failed";
            result["Info"] = "408";
            result["body"] = "<<< cmd >>> doing Error -> USERS SELECT Single by id";        
        }else{
            result["Status"] = "success";
            result["Info"] = "200";
            result["body"] = getcmddoing;
        }   
    }   
    
    return result;
}
