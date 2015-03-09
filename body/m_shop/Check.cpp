#include "Check.h"

using namespace N_SHOP;

std::map<std::string, std::string> SHOPCHECK::check_inside(\
                                std::map<std::string, std::string> data)
{
    /* Statement about return => result. */
    std::map<std::string, std::string> result;

    return result;
}

std::map<std::string, std::string> SHOPCHECK::check_inter(\
                                   std::string interface, \
                                   std::map<std::string, std::string> data)
{
    /* Statement about return => result. */
    std::map<std::string, std::string> result;

    /* <<< Into Interface. >>> */
    if (interface == "CommandShopHere")
    {
        std::map<std::string, std::string> general_check = normal_check_outside(data);
        if (general_check["Status"] != "success")
            goto general_check_error;
        else
            return general_check;
    }

general_check_error:
    result["Status"]="false";
    result["Info"]="408";
    result["body"]="general check error.";
    return result;


    return result;
}
