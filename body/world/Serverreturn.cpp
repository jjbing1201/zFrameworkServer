#include "Serverreturn.h"

using namespace N_WORLD;

std::map<std::string, std::string> WORLDRETURN::serverreturn_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data)
{
    /* Statement about result. */
    std::map<std::string, std::string> result; 
    std::map<std::string, std::string> cresult;

    /* Different Interface into Different part. */
    if (interface == "ServerConnect")
    {
        WORLDFUNCTION worldfunc;

        uint32 i;
        uint32 count=0;
        int32 table_size = sizeof(interfaceName)/sizeof(_interHandler);
        for(i=0; i<table_size; i++)
        {
            // Get tmp version of each version
            std::string get_tmp_version = interfaceName[i].version;
            // compare tmpversion with user version
            int compare_result = worldfunc.compare_big_version(data["version"], get_tmp_version);
            if ( compare_result == 0 )
            {
                result[anytostr(count)] = interfaceName[i].name;
                count++;
            }
        }    

        if (count != 0)
        {
            result["Status"]="success";
            result["Info"]="200";
            result["body"]="success";
            return result;
        }
        else
            goto world_serverreturn_error;
    } 

world_serverreturn_error:
    result["Status"]="false";
    result["Info"]="408";
    result["body"]="World return error.";
    return result;

world_serverreturn_cover_error:
    cresult["Status"]="false";
    cresult["Info"]="408";
    cresult["body"]="World return error.";
    return cresult;    

world_serverreturn_normal:
    result["Status"]="success";
    result["Info"]="200";
    result["body"]="success";
    return result;
    
    return result;
}
