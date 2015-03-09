#include "Serverreturn.h"

using namespace N_IOS;

std::map<std::string, std::string> IOSRETURN::serverreturn_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data)
{
    /* Statement about result. */
    IOSSPELL iospell;
    IOSFUNCTION iosfunc;
    SERVERETURN_DEPEND depend; 
    std::map<std::string, std::string> result; 

    /* Different Interface into Different part. */

serverreturn_error:
    result["Status"]="false";
    result["Info"]="408";
    result["body"]="m_user serverreturn return error.";
    return result;

serverreturn_normal:
    result["Status"]="success";
    result["Info"]="200";
    result["body"]="success";
    return result;
    
    return result;
}
