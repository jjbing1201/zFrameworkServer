#ifndef _SHOP_FUNCTION_HEADER_
#define _SHOP_FUNCTION_HEADER_

#include "shop_include.h"

class SHOPFUNCTION
{
protected:
    int _compare_int(int _first, int _second);

    int _compare_version(std::vector<std::string> first, std::vector<std::string> second);

    int _compare_two_version(std::vector<std::string> first, std::vector<std::string> second);



public:
    SHOPFUNCTION() {}
    virtual ~SHOPFUNCTION() {}

    std::string get_autoincrement_line(std::map<std::string, std::string> data);

    std::string get_autoincrement_line(std::map<std::string, std::string> data, int line);

    std::string get_autoincrement_iline(std::map<std::string, std::string> data,int line);

    void mapPrint(std::map<std::string, std::string> data);

    int compare_big_version(std::string, std::string);

    int compare_big_small_version(std::string,  std::string);

    int compare_version(std::string server_version,\
                         std::string client_version,\
                         std::string user_client_version);

    std::map<std::string, std::string> get_map_of_table_column(\
                std::map<std::string, std::string> data, \
                std::string tablename, std::string quote);

    std::map<std::string, std::string> get_eachmap_of_table(\
                std::string data, std::string tablename);

    std::string map_to_json(std::map<std::string, std::string> data); 
};

#endif /* _SHOP_FUNCTION_HEADER_ */

