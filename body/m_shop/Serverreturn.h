#ifndef _SHOP_SERVER_RETURN_HEADER_
#define _SHOP_SERVER_RETURN_HEADER_

#include "shop_include.h"
#include "table_include.h"
#include "ShopSpell.h"
#include "ShopFunction.h"

#include "SDepend.h"

namespace N_SHOP
{
    class SHOPRETURN : public SERVERRETURN
    {
    public:
        SHOPRETURN() {}
        virtual ~SHOPRETURN() {}

        std::map<std::string, std::string> serverreturn_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data);
    };
};

#endif /* _SHOP_SERVER_RETURN_HEADER_ */
