#include "ShopFunction.h"

int SHOPFUNCTION::_compare_int(int _first, int _second)
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

int SHOPFUNCTION::_compare_version(std::vector<std::string> first, \
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

int SHOPFUNCTION::_compare_two_version(std::vector<std::string> first, \
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

int SHOPFUNCTION::compare_big_version(std::string example, std::string input)
{
    std::vector<std::string> _example = split(example, ".");
    std::vector<std::string> _input = split(input, ".");

    return _compare_version(_example, _input);
}

int SHOPFUNCTION::compare_big_small_version(std::string example,  std::string input)
{
    std::vector<std::string> _example = split(example, ".");
    std::vector<std::string> _input = split(input, ".");

    return _compare_two_version(_example, _input);
}

int SHOPFUNCTION::compare_version(std::string server_version,\
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

std::string SHOPFUNCTION::get_autoincrement_line(std::map<std::string, std::string> data)
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


std::string SHOPFUNCTION::get_autoincrement_line(std::map<std::string, std::string> data, int line)
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

std::string SHOPFUNCTION::get_autoincrement_iline(std::map<std::string, std::string> data,int line)
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

void SHOPFUNCTION::mapPrint(std::map<std::string, std::string> data)
{
    std::map<std::string, std::string>::iterator it;
    for(it=data.begin(); it!=data.end(); it++)
    {
        std::cout << "key : " << it->first << " ###  value : " << it->second << std::endl;
    }

    return;
}

std::map<std::string, std::string> SHOPFUNCTION::get_map_of_table_column(std::map<std::string, std::string> data, std::string tablename, std::string quote)
{
    /* 1. statement return using. */
    std::map<std::string, std::string> result;
    std::vector<std::string> tmp = split(data["body"], quote);
    std::vector<std::string> tmp_inform = split(tmp[1], "\t\t");

    /* 2. using vector to get column. */
    if (tablename == "shop_main")
    {
	result["shop_id"] = tmp_inform[0];
        result["shop_name"] = tmp_inform[1];
        result["shop_belong_name"] = tmp_inform[2];
        result["shop_signature"] = tmp_inform[3];
        result["shop_area"] = tmp_inform[4];
        result["shop_detail_area"] = tmp_inform[5];
        result["shop_auth"] = tmp_inform[6];
        result["shop_create_time"] = tmp_inform[7];
        result["shop_priority"] = tmp_inform[8];
        result["shop_satellite_x"] = tmp_inform[9];
        result["shop_satellite_y"] = tmp_inform[10];
        result["shop_phonenumber"] = tmp_inform[11];
        result["shop_detail_information"] = tmp_inform[12];
    }
    if (tablename == "shops_assess_stars_CALC")
    {
        result["allcount"] = tmp_inform[0];
        result["allstars"] = tmp_inform[1];
        result["averagestars"] = tmp_inform[2];
    }
    if (tablename == "shops_special_offers")
    {
        result["auto_id"] = tmp_inform[0];
        result["shop_id"] = tmp_inform[1];
        result["offer_start_time"] = tmp_inform[2];
        result["offer_end_time"] = tmp_inform[3];
        result["offer_title"] = tmp_inform[4];
        result["offer_context"] = tmp_inform[5];
    }

    return result;
}

std::map<std::string, std::string> SHOPFUNCTION::get_eachmap_of_table(std::string data, std::string tablename)
{
    /* 1. statement return using. */
    std::map<std::string, std::string> result;
    
    std::vector<std::string> tmp_inform = split(data, "\t\t");

    /* 2. using vector to get column. */
    if (tablename == "shop_main")
    {
        result["shop_id"] = tmp_inform[0];
        result["shop_name"] = tmp_inform[1];
        result["shop_belong_name"] = tmp_inform[2];
        result["shop_signature"] = tmp_inform[3];
        result["shop_area"] = tmp_inform[4];
        result["shop_detail_area"] = tmp_inform[5];
        result["shop_auth"] = tmp_inform[6];
        result["shop_create_time"] = tmp_inform[7];
        result["shop_priority"] = tmp_inform[8];
        result["shop_satellite_x"] = tmp_inform[9];
        result["shop_satellite_y"] = tmp_inform[10];
        result["shop_phonenumber"] = tmp_inform[11];
        result["shop_detail_information"] = tmp_inform[12];
    }   
    if (tablename == "shops_assess_stars_CALC")
    {
        result["allcount"] = tmp_inform[0];
        result["allstars"] = tmp_inform[1];
        result["averagestars"] = tmp_inform[2];
    }
    if (tablename == "shops_special_offers")
    {
        result["auto_id"] = tmp_inform[0];
        result["shop_id"] = tmp_inform[1];
        result["offer_start_time"] = tmp_inform[2];
        result["offer_end_time"] = tmp_inform[3];
        result["offer_title"] = tmp_inform[4];
        result["offer_context"] = tmp_inform[5];
    }
    if (tablename == "shops_assess_stars")
    {
        result["auto_id"] = tmp_inform[0];
        result["shop_id"] = tmp_inform[1];
        result["user_id"] = tmp_inform[2];
        result["context"] = tmp_inform[3];
        result["stars"] = tmp_inform[4];
        result["a_timestamp"] = tmp_inform[5];
    }

    return result;
}

std::string SHOPFUNCTION::map_to_json(std::map<std::string, std::string> data)
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
