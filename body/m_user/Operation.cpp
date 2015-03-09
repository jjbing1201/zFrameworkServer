#include "Operation.h"

using namespace N_IOS; 

std::map<std::string, std::string> IOSOPERATION::operation_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data)
{
    /* Statement about result. */
    IOSSPELL iospell;
    IOSFUNCTION iosfunc;
    OPERATION_DEPEND depend; 
    std::map<std::string, std::string> result;

    /* Different Interface into Different part. */

operation_error:
    result["Status"]="false";
    result["Info"]="408";
    result["body"]="Operation return error.";
    return result;

operation_normal:
    result["Status"]="success";
    result["Info"]="200";
    result["body"]="success";
    return result;

    return result;
}
