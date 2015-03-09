#ifndef _SHOP_FORMAT_HEADER_H_
#define _SHOP_FORMAT_HEADER_H_

#include "shop_include.h"
#include "FormatDepand.h"

namespace N_SHOP
{
    class SHOPFORMAT : public FORMAT
    {
    protected:
        std::map<std::string, std::string> normal_format_inside(std::string interfaceName, std::map<std::string, std::string> data);

    public:
        SHOPFORMAT() {}
        virtual ~SHOPFORMAT() {}

        std::map<std::string, std::string> format_inter(\
                                   std::string interface, \
                                   std::map<std::string, std::string> data);
    
        std::map<std::string, std::string> format_inter_inherit(\
                                   std::string interface, \
                                   std::map<std::string, std::string> data);
    };
};

#endif /* _SHOP_FORMAT_HEADER_H_ */

