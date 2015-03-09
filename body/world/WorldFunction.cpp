#include "WorldFunction.h"

int WORLDFUNCTION::_compare_int(int _first, int _second)
{
    if (_first > _second)
    {
        return 0;
    }
    else if(_first == _second)
    {
        return 1;
    }
    else
    {
        return 2;
    }

    return -1;
}

int WORLDFUNCTION::_compare_version(std::vector<std::string> first, \
                                     std::vector<std::string> second)
{
    /* 1. compare big version */
    int _compare_result_big = _compare_int(atoi(first[0].c_str()), \
                                           atoi(second[0].c_str()) );
    if (_compare_result_big == 2 or _compare_result_big == -1)
    {
        return -1;
    }

    /* 2. compare small version. */
    int _compare_result_small = _compare_int(atoi(first[1].c_str()), \
                                             atoi(second[1].c_str()) ); 
    if (_compare_result_small == 2 or _compare_result_small == -1)
    {
        return -1;
    }

    /* 3. compare date version */
    int _compare_result_date = _compare_int(atoi(first[2].c_str()), \
                                            atoi(second[2].c_str()) );
    if (_compare_result_date == 2 or _compare_result_date == -1)
    {
        return -1;
    }

    return 0;
}

int WORLDFUNCTION::_compare_two_version(std::vector<std::string> first, \
                          std::vector<std::string> second)
{
    /* 1. compare big version */
    int _compare_result_big = _compare_int(atoi(first[0].c_str()), \
                                           atoi(second[0].c_str()) );    
    if (_compare_result_big != 1)
        return -1;

    /* 2. compare small version */
    int _compare_result_small = _compare_int(atoi(first[1].c_str()), \
                                             atoi(second[1].c_str()) );
    if (_compare_result_small != 1)
        return -1;

    return 0;
}

int WORLDFUNCTION::compare_big_version(std::string example, std::string input)
{
    std::vector<std::string> _example = split(example, ".");
    std::vector<std::string> _input = split(input, ".");

    return _compare_version(_example, _input);
}

int WORLDFUNCTION::compare_big_small_version(std::string example,  std::string input)
{
    std::vector<std::string> _example = split(example, ".");
    std::vector<std::string> _input = split(input, ".");

    return _compare_two_version(_example, _input);
}

int WORLDFUNCTION::compare_version(std::string server_version,\
                         std::string client_version,\
                         std::string user_client_version)
{
    /* compare server part (server_version and client_version) */
    std::vector<std::string> _server = split(server_version, ".");
    std::vector<std::string> _client = split(client_version, ".");
    std::vector<std::string> _user_client = split(user_client_version, ".");

    /* compare server_version and client_version */
    if ( (_compare_two_version(_server, _client)) == -1 )
    {
        return -1;
    }
     
    /* compare client_version and user_client_version */
    if ( (_compare_two_version(_client, _user_client)) == -1 )
    {
        return -1;
    }

    return 0;
}

std::string WORLDFUNCTION::get_autoincrement_line(std::map<std::string, std::string> data)
{
    /* 1. statement return using. */
    std::string result;

    /* 2. using vector to get first column. */
    std::vector<std::string> tmp = split(data["body"], "\r\n");
    std::vector<std::string> tmp_inform = split(tmp[1], "\t\t");

    /* 3. assignment. */
    result = tmp_inform[0];

    return result;
}


std::string WORLDFUNCTION::get_autoincrement_line(std::map<std::string, std::string> data, int line)
{
    /* 1. statement return using. */
    std::string result;

    /* 2. using vector to get first column. */
    std::vector<std::string> tmp = split(data["body"], "\r\n");
    std::vector<std::string> tmp_inform = split(tmp[line-1], "\t\t");

    /* 3. assignment. */
    result = tmp_inform[0];

    return result;
}

std::string WORLDFUNCTION::get_autoincrement_iline(std::map<std::string, std::string> data,int line)
{
    /* 1. statement return using. */
    std::string result;
        
    /* 2. using vector to get first column. */
    std::vector<std::string> tmp = split(data["body"], "\r\n");
    std::vector<std::string> tmp_inform = split(tmp[1], "\t\t");

    /* 3. assignment. */
    result = tmp_inform[line];

    return result;
}

std::string WORLDFUNCTION::get_autoincrement_iline(std::map<std::string, std::string> data, int row, int line)
{
    /* 1. statement return using. */
    std::string result;

    /* 2. using vector to get first column. */
    std::vector<std::string> tmp = split(data["body"], "\r\n");
    std::vector<std::string> tmp_inform = split(tmp[line], "\t\t");

    /* 3. assignment. */
    result = tmp_inform[row];

    return result;
}

void WORLDFUNCTION::mapPrint(std::map<std::string, std::string> data)
{
    std::map<std::string, std::string>::iterator it;
    for(it=data.begin(); it!=data.end(); it++)
    {
        std::cout << "key : " << it->first << " ###  value : " << it->second << std::endl;
    }

    return;
}

std::map<std::string, std::string> WORLDFUNCTION::get_map_of_table_column(std::map<std::string, std::string> data, std::string tablename, std::string quote)
{
    /* 1. statement return using. */
    std::map<std::string, std::string> result;

    /* 2. using vector to get column. */
    std::vector<std::string> tmp = split(data["body"], quote);
    std::vector<std::string> tmp_inform = split(tmp[1], "\t\t");
    
    if (tablename == "process_relation")
    {   
        result["auto_id"] = tmp_inform[0];
        result["main_process"] = tmp_inform[1];
        result["main_id"] = tmp_inform[2];
        result["child_id"] = tmp_inform[3];
        result["child_status"] = tmp_inform[4];
    }   
    else if (tablename == "process_basic")
    {
        result["auto_id"] = tmp_inform[0];
        result["process_name"] = tmp_inform[1];
        result["process_type"] = tmp_inform[2];
        result["process_extension"] = tmp_inform[3];
        result["process_extension_depend"] = tmp_inform[4];
        result["process_createtime"] = tmp_inform[5];
        result["process_priority"] = tmp_inform[6];
        result["process_pic"] = tmp_inform[7];
        result["process_context"] = tmp_inform[8];
    }
    else if (tablename == "process_four")
    {
        result["auto_id"] = tmp_inform[0];
        result["title"] = tmp_inform[1];
        result["context"] = tmp_inform[2];
        result["picture_url"] = tmp_inform[3];
        result["voice_url"] = tmp_inform[4];
    }
    else if (tablename == "abb_person_status")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_id"] = tmp_inform[1];
        result["type"] = tmp_inform[2];
        result["priority"] = tmp_inform[3];
        result["create_time"] = tmp_inform[4];
        result["context"] = tmp_inform[5];
    }
	else if (tablename == "bbs_forum_forum_above")
    {   
        result["bfid"] = tmp_inform[0];
        result["bf_playorder"] = tmp_inform[1];
        result["bf_name"] = tmp_inform[2];
        result["bf_createtime"] = tmp_inform[3];
        result["bf_ensure"] = tmp_inform[4];
	}
    else if (tablename == "bbs_forum_forum")
    {
        result["fid"] = tmp_inform[0];
        result["name"] = tmp_inform[1];
        result["status"] = tmp_inform[2];
        result["displayorder"] = tmp_inform[3];
        result["threads"] = tmp_inform[4];
        result["posts"] = tmp_inform[5];
        result["lastpost"] = tmp_inform[6];
    	result["forum_type_id"] = tmp_inform[7];
        result["forum_type_name"] = tmp_inform[8];
        result["forum_type_pic"] = tmp_inform[9];
		result["forum_type_above"] = tmp_inform[10];
    }
    else if (tablename == "bbs_forum_thread")
    {
        result["tid"] = tmp_inform[0];
        result["fid"] = tmp_inform[1];
        result["type"] = tmp_inform[2];
        result["status"] = tmp_inform[3];
        result["top"] = tmp_inform[4];
        result["author"] = tmp_inform[5];
        result["authorid"] = tmp_inform[6];
        result["subject"] = tmp_inform[7];
        result["createtime"] = tmp_inform[8];
        result["lastpost"] = tmp_inform[9];
        result["lastposter"] = tmp_inform[10];
        result["digest"] = tmp_inform[11];
        result["hot"] = tmp_inform[12];
    }
    else if (tablename == "bbs_forum_post_MIWA")
    {
        result["pid"] = tmp_inform[0];
        result["tid"] = tmp_inform[1];
        result["fid"] = tmp_inform[2];
        result["first"] = tmp_inform[3];
        result["author"] = tmp_inform[4];
        result["authorid"] = tmp_inform[5];
        result["touid"] = tmp_inform[6];
        result["toname"] = tmp_inform[7];
        result["subject"] = tmp_inform[8];
        result["createtime"] = tmp_inform[9];
        result["message"] = tmp_inform[10];
        result["userip"] = tmp_inform[11];
        result["position"] = tmp_inform[tmp_inform.size()-1];
    }
    else if (tablename == "bbs_forum_post_BINGEGE")
    {
        result["pid"] = tmp_inform[0];
        result["tid"] = tmp_inform[1];
        result["fid"] = tmp_inform[2];
        result["first"] = tmp_inform[3];
        result["author"] = tmp_inform[4];
        result["authorid"] = tmp_inform[5];
        result["subject"] = tmp_inform[7];
        result["createtime"] = tmp_inform[8];
        result["message"] = tmp_inform[9];
        result["userip"] = tmp_inform[10];
        result["position"] = tmp_inform[tmp_inform.size()-1];
    }
    else if (tablename == "abb_upload_record")
    {
        result["auto_id"] = tmp_inform[0];
        result["upload_id"] = tmp_inform[1];
        result["to_id"] = tmp_inform[2];
        result["file_name"] = tmp_inform[3];
        result["upload_type"] = tmp_inform[4];
        result["upload_time"] = tmp_inform[5];
    }
    else if (tablename == "log_upload")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_id"] = tmp_inform[1];
        result["create_time"] = tmp_inform[2];
        result["create_type"] = tmp_inform[3];
        result["log_context"] = tmp_inform[4];
    }
	else if (tablename == "news_main")
    {
        result["auto_id"] = tmp_inform[0];
        result["send_user_id"] = tmp_inform[1];
        result["send_user_nick_name"] = tmp_inform[2];
        result["send_context"] = tmp_inform[3];
        result["send_attachment"] = tmp_inform[4];
        result["send_time"] = tmp_inform[5];
        result["send_async"] = tmp_inform[6];
        result["send_backup"] = tmp_inform[7];
        result["send_user_icon"] = tmp_inform[8];
    }
	else if (tablename == "news_main_each_user")
    {
        result["auto_id"] = tmp_inform[0];
        result["main_id"] = tmp_inform[1];
        result["to_user_id"] = tmp_inform[2];
        result["async_time"] = tmp_inform[3];
        result["reach_not"] = tmp_inform[4];
    }
	
    return result;
}

std::map<std::string, std::string> WORLDFUNCTION::get_eachmap_of_table(std::string data, std::string tablename)
{
    /* 1. statement return using. */
    std::map<std::string, std::string> result;
    
    std::vector<std::string> tmp_inform = split(data, "\t\t");

    /* 2. using vector to get column. */
    if (tablename == "process_relation")
    {
        result["auto_id"] = tmp_inform[0];
        result["main_process"] = tmp_inform[1];
        result["main_id"] = tmp_inform[2];
        result["child_id"] = tmp_inform[3];
        result["child_status"] = tmp_inform[4];
    } 
    else if (tablename == "process_basic")
    {
        result["auto_id"] = tmp_inform[0];
        result["process_name"] = tmp_inform[1];
        result["process_type"] = tmp_inform[2];
        result["process_extension"] = tmp_inform[3];
        result["process_extension_depend"] = tmp_inform[4];
        result["process_createtime"] = tmp_inform[5];
        result["process_priority"] = tmp_inform[6];
        result["process_pic"] = tmp_inform[7];
        result["process_context"] = tmp_inform[8];
    }
    else if (tablename == "process_four")
    {
        result["auto_id"] = tmp_inform[0];
        result["title"] = tmp_inform[1];
        result["context"] = tmp_inform[2];
        result["picture_url"] = tmp_inform[3];
        result["voice_url"] = tmp_inform[4];
    }
    else if (tablename == "abb_person_status")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_id"] = tmp_inform[1];
        result["type"] = tmp_inform[2];
        result["priority"] = tmp_inform[3];
        result["create_time"] = tmp_inform[4];
        result["context"] = tmp_inform[5];
    }
	else if (tablename == "bbs_forum_forum_above")
    {
        result["bfid"] = tmp_inform[0];
        result["bf_playorder"] = tmp_inform[1];
        result["bf_name"] = tmp_inform[2];
        result["bf_createtime"] = tmp_inform[3];
        result["bf_ensure"] = tmp_inform[4];
    }
    else if (tablename == "bbs_forum_forum")
    {
        result["fid"] = tmp_inform[0];
        result["name"] = tmp_inform[1];
        result["status"] = tmp_inform[2];
        result["displayorder"] = tmp_inform[3];
        result["threads"] = tmp_inform[4];
        result["posts"] = tmp_inform[5];
        result["lastpost"] = tmp_inform[6];
        result["forum_type_id"] = tmp_inform[7];
        result["forum_type_name"] = tmp_inform[8];
        result["forum_type_pic"] = tmp_inform[9];
        result["forum_type_above"] = tmp_inform[10];
    }
    else if (tablename == "bbs_forum_thread")
    {
        result["tid"] = tmp_inform[0];
        result["fid"] = tmp_inform[1];
        result["type"] = tmp_inform[2];
        result["status"] = tmp_inform[3];
        result["top"] = tmp_inform[4];
        result["author"] = tmp_inform[5];
        result["authorid"] = tmp_inform[6];
        result["subject"] = tmp_inform[7];
        result["createtime"] = tmp_inform[8];
        result["lastpost"] = tmp_inform[9];
        result["lastposter"] = tmp_inform[10];
        result["digest"] = tmp_inform[11];
        result["hot"] = tmp_inform[12];
    }
    else if (tablename == "bbs_forum_post")
    {
        result["pid"] = tmp_inform[0];
        result["tid"] = tmp_inform[1];
        result["fid"] = tmp_inform[2];
        result["first"] = tmp_inform[3];
        result["author"] = tmp_inform[4];
        result["authorid"] = tmp_inform[5];
        result["subject"] = tmp_inform[7];
        result["createtime"] = tmp_inform[8];
        result["message"] = tmp_inform[9];
        result["userip"] = tmp_inform[10];
        result["position"] = tmp_inform[12];
#if 0
        result["touid"] = tmp_inform[6];
        result["toname"] = tmp_inform[7];
        result["subject"] = tmp_inform[8];
        result["createtime"] = tmp_inform[9];
        result["message"] = tmp_inform[10];
        result["userip"] = tmp_inform[11];
        result["status"] = tmp_inform[12];
        result["invisible"] = tmp_inform[13];
        result["position"] = tmp_inform[14];
#endif
    }
    else if (tablename == "bbs_forum_post_MIWA")
    {
        result["pid"] = tmp_inform[0];
        result["tid"] = tmp_inform[1];
        result["fid"] = tmp_inform[2];
        result["first"] = tmp_inform[3];
        result["author"] = tmp_inform[4];
        result["authorid"] = tmp_inform[5];
        result["subject"] = tmp_inform[8];
        result["createtime"] = tmp_inform[9];
        result["message"] = tmp_inform[10];
        result["userip"] = tmp_inform[11];
        result["position"] = tmp_inform[tmp_inform.size()-1];
    }
    else if (tablename == "bbs_forum_post_BINGEGE")
    {
        result["pid"] = tmp_inform[0];
        result["tid"] = tmp_inform[1];
        result["fid"] = tmp_inform[2];
        result["first"] = tmp_inform[3];
        result["author"] = tmp_inform[4];
        result["authorid"] = tmp_inform[5];
        result["subject"] = tmp_inform[7];
        result["createtime"] = tmp_inform[8];
        result["message"] = tmp_inform[9];
        result["userip"] = tmp_inform[10];
        result["position"] = tmp_inform[tmp_inform.size()-1];
    }
    else if (tablename == "abb_upload_record")
    {
        result["auto_id"] = tmp_inform[0];
        result["upload_id"] = tmp_inform[1];
        result["to_id"] = tmp_inform[2];
        result["backup_id"] = tmp_inform[3];
        result["file_name"] = tmp_inform[4];
        result["upload_type"] = tmp_inform[5];
        result["upload_time"] = tmp_inform[6];
    }
    else if (tablename == "log_upload")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_id"] = tmp_inform[1];
        result["create_time"] = tmp_inform[2];
        result["create_type"] = tmp_inform[3];
        result["log_context"] = tmp_inform[4];
    }
	else if (tablename == "news_main")
    {
        result["auto_id"] = tmp_inform[0];
        result["send_user_id"] = tmp_inform[1];
        result["send_user_nick_name"] = tmp_inform[2];
        result["send_context"] = tmp_inform[3];
        result["send_attachment"] = tmp_inform[4];
        result["send_time"] = tmp_inform[5];
        result["send_async"] = tmp_inform[6];
        result["send_backup"] = tmp_inform[7];
		result["send_user_icon"] = tmp_inform[8];
    }
	else if (tablename == "news_main_each_user")
    {
        result["auto_id"] = tmp_inform[0];
        result["main_id"] = tmp_inform[1];
        result["to_user_id"] = tmp_inform[2];
        result["async_time"] = tmp_inform[3];
        result["reach_not"] = tmp_inform[4];
    }
    return result;
}

std::string WORLDFUNCTION::map_to_json(std::map<std::string, std::string> data)
{
    Json::FastWriter fast_writer;

    Json::Value tmp;

    std::map<std::string, std::string>::iterator jsonit;
    for(jsonit=data.begin(); jsonit!=data.end(); jsonit++)
    {
        tmp[jsonit->first]=jsonit->second;
    }

    return fast_writer.write(tmp);
}
