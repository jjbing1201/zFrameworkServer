#include "Operation.h"

using namespace N_WORLD; 

std::map<std::string, std::string> WORLDOPERATION::operation_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data)
{
    /* Statement about result. */
    std::map<std::string, std::string> result;

    /* Different Interface into Different part. */
    if (interface == "ServerConnect")
    {
        /* Part 1. check platform. */
        if (data["platform"] == "ANDROID" or data["platform"] == "IOS") {}
        else 
            goto world_operation_error; 

        /* Part 2. check type. */
        INIReader reader("config.ini");

        std::string _type = reader.Get("METHOD", data["type"].c_str(), "-1");
        if (_type == "-1")
            goto world_operation_error;

        std::string server_version = reader.Get("SERVER_VERSION", "configserver"
, "0.0.000000");
        std::string client_version = reader.Get(data["platform"].c_str(), _type.
c_str(), "0.0.000000");

        /* Part 3. compare about version. */
        WORLDFUNCTION worldfunc;
        int compare_result = worldfunc.compare_version(\
                server_version, client_version, data["version"]);
        if ( compare_result == -1 )
        {
            goto world_operation_error;
        }

        goto world_operation_normal;
    }

world_operation_error:
    result["Status"]="false";
    result["Info"]="408";
    result["body"]="Operation return error.";
    return result;

world_operation_normal:
    result["Status"]="success";
    result["Info"]="200";
    result["body"]="success";
    return result;

    return result;
}
