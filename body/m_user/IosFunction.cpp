#include "IosFunction.h"

int IOSFUNCTION::_compare_int(int _first, int _second)
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

int IOSFUNCTION::_compare_version(std::vector<std::string> first, \
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

int IOSFUNCTION::_compare_two_version(std::vector<std::string> first, \
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

int IOSFUNCTION::compare_big_version(std::string example, std::string input)
{
    std::vector<std::string> _example = split(example, ".");
    std::vector<std::string> _input = split(input, ".");

    return _compare_version(_example, _input);
}

int IOSFUNCTION::compare_big_small_version(std::string example,  std::string input)
{
    std::vector<std::string> _example = split(example, ".");
    std::vector<std::string> _input = split(input, ".");

    return _compare_two_version(_example, _input);
}

int IOSFUNCTION::compare_version(std::string server_version,\
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

std::string IOSFUNCTION::get_autoincrement_line(std::map<std::string, std::string> data)
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


std::string IOSFUNCTION::get_autoincrement_line(std::map<std::string, std::string> data, int line)
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

std::string IOSFUNCTION::get_autoincrement_iline(std::map<std::string, std::string> data,int line)
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

void IOSFUNCTION::mapPrint(std::map<std::string, std::string> data)
{
    std::map<std::string, std::string>::iterator it;
    for(it=data.begin(); it!=data.end(); it++)
    {
        std::cout << "key : " << it->first << " ###  value : " << it->second << std::endl;
    }

    return;
}

std::map<std::string, std::string> IOSFUNCTION::get_map_of_table_column(std::map<std::string, std::string> data, std::string tablename, std::string quote)
{
    /* 1. statement return using. */
    std::map<std::string, std::string> result;

    std::vector<std::string> tmp = split(data["body"], quote);
    std::vector<std::string> tmp_inform = split(tmp[1], "\t\t");

    /* 2. using vector to get column. */
    if (tablename == "abb_main_users")
    {
        result["user_id"] = tmp_inform[0];
        result["user_type"] = tmp_inform[1];
        result["user_basic_id"] = tmp_inform[2];
        result["user_device_id"] = tmp_inform[3];
        result["user_detail_id"] = tmp_inform[4];
        result["user_post_id"] = tmp_inform[5];
        result["user_three_id"] = tmp_inform[6];
        result["user_backup"] = tmp_inform[7];
    }
    else if (tablename == "abb_basic_property")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_real_name"] = tmp_inform[1];
        result["user_sex"] = tmp_inform[2];
        result["user_idcard"] = tmp_inform[3];
        result["user_birthday"] = tmp_inform[4];
        result["user_height"] = tmp_inform[5];
    }
    else if (tablename == "abb_complex_property_human")
    {   
        result["auto_id"] = tmp_inform[0];
        result["user_account_name"] = tmp_inform[1];
        result["user_account_pass"] = tmp_inform[2];
        result["user_register_time"] = tmp_inform[3];
        result["user_last_login_time"] = tmp_inform[4];
        result["user_nick_name"] = tmp_inform[5];
        result["user_stay_area"] = tmp_inform[6];
        result["user_job"] = tmp_inform[7];
        result["user_marry_status"] = tmp_inform[8];
        result["user_signature"] = tmp_inform[9];
        result["user_exp"] = tmp_inform[10];
        result["user_lvl"] = tmp_inform[11];
        result["user_constellation"] = tmp_inform[12];
        result["user_telephone"] = tmp_inform[13];
        result["user_telephone_area"] = tmp_inform[14];
    }   
    else if (tablename == "abb_complex_property_shop")
    {
        result["auto_id"] = tmp_inform[0];
        result["shop_account_name"] = tmp_inform[1];
        result["shop_account_pass"] = tmp_inform[2];
        result["shop_register_time"] = tmp_inform[3];
        result["shop_last_login_time"] = tmp_inform[4];
        result["shop_names"] = tmp_inform[5];
        result["shop_stay_area"] = tmp_inform[6];
        result["shop_operate_status"] = tmp_inform[7];
        result["shop_signature"] = tmp_inform[8];
        result["shop_exp"] = tmp_inform[9];
        result["shop_lvl"] = tmp_inform[10];
        result["shop_part"] = tmp_inform[11];
        result["shop_part_property"] = tmp_inform[12];
        result["shop_telephone"] = tmp_inform[13];
        result["shop_telephone_area"] = tmp_inform[14];
    }
    else if (tablename == "abb_device_information")
    {
        result["auto_id"] = tmp_inform[0];
        result["device_platform"] = tmp_inform[1];
        result["device_run_version"] = tmp_inform[2];
        result["device_last_position"] = tmp_inform[3];
        result["device_last_position_time"] = tmp_inform[4];
    }
    else if (tablename == "abb_external_login")
    {
        result["auto_id"] = tmp_inform[0];
        result["external_platform"] = tmp_inform[1];
        result["external_platform_id"] = tmp_inform[2];
        result["external_name"] = tmp_inform[3];
        result["external_pic_url_one"] = tmp_inform[4];
        result["external_pic_url_two"] = tmp_inform[5];
    }
    else if (tablename == "relation_abb_friends")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_id"] = tmp_inform[1];
        result["opsite_id"] = tmp_inform[2];
        result["timestamp"] = tmp_inform[3];
        result["f_status"] = tmp_inform[4];
    }

    return result;
}

std::map<std::string, std::string> IOSFUNCTION::get_eachmap_of_table(std::string data, std::string tablename)
{
    /* 1. statement return using. */
    std::map<std::string, std::string> result;
    
    std::vector<std::string> tmp_inform = split(data, "\t\t");

    /* 2. using vector to get column. */
    if (tablename == "abb_main_users")
    {
        result["user_id"] = tmp_inform[0];
        result["user_type"] = tmp_inform[1];
        result["user_basic_id"] = tmp_inform[2];
        result["user_device_id"] = tmp_inform[3];
        result["user_detail_id"] = tmp_inform[4];
        result["user_post_id"] = tmp_inform[5];
        result["user_three_id"] = tmp_inform[6];
        result["user_backup"] = tmp_inform[7];
    }
    else if (tablename == "abb_basic_property")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_real_name"] = tmp_inform[1];
        result["user_sex"] = tmp_inform[2];
        result["user_idcard"] = tmp_inform[3];
        result["user_birthday"] = tmp_inform[4];
        result["user_height"] = tmp_inform[5];
    }
    else if (tablename == "abb_complex_property_human")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_account_name"] = tmp_inform[1];
        result["user_account_pass"] = tmp_inform[2];
        result["user_register_time"] = tmp_inform[3];
        result["user_last_login_time"] = tmp_inform[4];
        result["user_nick_name"] = tmp_inform[5];
        result["user_stay_area"] = tmp_inform[6];
        result["user_job"] = tmp_inform[7];
        result["user_marry_status"] = tmp_inform[8];
        result["user_signature"] = tmp_inform[9];
        result["user_exp"] = tmp_inform[10];
        result["user_lvl"] = tmp_inform[11];
        result["user_constellation"] = tmp_inform[12];
        result["user_telephone"] = tmp_inform[13];
        result["user_telephone_area"] = tmp_inform[14];
    }
    else if (tablename == "abb_complex_property_shop")
    {
        result["auto_id"] = tmp_inform[0];
        result["shop_account_name"] = tmp_inform[1];
        result["shop_account_pass"] = tmp_inform[2];
        result["shop_register_time"] = tmp_inform[3];
        result["shop_last_login_time"] = tmp_inform[4];
        result["shop_names"] = tmp_inform[5];
        result["shop_stay_area"] = tmp_inform[6];
        result["shop_operate_status"] = tmp_inform[7];
        result["shop_signature"] = tmp_inform[8];
        result["shop_exp"] = tmp_inform[9];
        result["shop_lvl"] = tmp_inform[10];
        result["shop_part"] = tmp_inform[11];
        result["shop_part_property"] = tmp_inform[12];
        result["shop_telephone"] = tmp_inform[13];
        result["shop_telephone_area"] = tmp_inform[14];
    }
    else if (tablename == "abb_device_information")
    {
        result["auto_id"] = tmp_inform[0];
        result["device_platform"] = tmp_inform[1];
        result["device_run_version"] = tmp_inform[2];
        result["device_last_position"] = tmp_inform[3];
        result["device_last_position_time"] = tmp_inform[4];
    }
    else if (tablename == "abb_external_login")
    {
        result["auto_id"] = tmp_inform[0];
        result["external_platform"] = tmp_inform[1];
        result["external_platform_id"] = tmp_inform[2];
        result["external_name"] = tmp_inform[3];
        result["external_pic_url_one"] = tmp_inform[4];
        result["external_pic_url_two"] = tmp_inform[5];
    }
    else if (tablename == "relation_abb_friends")
    {
        result["auto_id"] = tmp_inform[0];
        result["user_id"] = tmp_inform[1];
        result["opsite_id"] = tmp_inform[2];
        result["timestamp"] = tmp_inform[3];
        result["f_status"] = tmp_inform[4];
    }

    return result;
}

std::string IOSFUNCTION::map_to_json(std::map<std::string, std::string> data)
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
