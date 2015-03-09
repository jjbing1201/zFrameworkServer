#include "Serverreturn.h"

using namespace N_SHOP;

std::map<std::string, std::string> SHOPRETURN::serverreturn_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data)
{
    /* Statement about result. */
    SHOPSPELL shopspell;
    SHOPFUNCTION shopfunc;
    SERVERETURN_DEPEND depend; 
    std::map<std::string, std::string> result; 

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
