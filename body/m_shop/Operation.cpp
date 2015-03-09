#include "Operation.h"

using namespace N_SHOP; 

std::map<std::string, std::string> SHOPOPERATION::operation_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data)
{
    /* Statement about result. */
    SHOPSPELL shopspell;
    SHOPFUNCTION shopfunc;
    OPERATION_DEPEND depend; 
    std::map<std::string, std::string> result;

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
