#ifndef _SHOP_OPERATION_HEADER_
#define _SHOP_OPERATION_HEADER_

#include "shop_include.h"
#include "table_include.h"
#include "ShopSpell.h"
#include "ShopFunction.h"

#include "ODepend.h"

namespace N_SHOP
{
    class SHOPOPERATION : public OPERATION
    {
    public:
        SHOPOPERATION() {}
        virtual ~SHOPOPERATION() {}

        std::map<std::string, std::string> operation_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data);
    };
};

#endif /* _SHOP_OPERATION_HEADER_ */

