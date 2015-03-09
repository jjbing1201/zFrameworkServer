#ifndef _SHOP_CHECK_HEADER_
#define _SHOP_CHECK_HEADER_

#include "shop_include.h"

namespace N_SHOP
{
    class SHOPCHECK : public CHECKDATA
    {
    protected:
        std::map<std::string, std::string> check_inside(std::map<std::string, std::string> data);

    public:
        SHOPCHECK() {}
        virtual ~SHOPCHECK() {}

        std::map<std::string, std::string> check_inter(std::string interface, \
                                   std::map<std::string, std::string> data);
    
    };

};

#endif /* _SHOP_CHECK_HEADER_ */

