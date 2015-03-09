#ifndef _IOS_OPERATION_HEADER_
#define _IOS_OPERATION_HEADER_

#include "ios_include.h"
#include "table_include.h"
#include "IosSpell.h"
#include "IosFunction.h"

#include "ODepend.h"

namespace N_IOS
{
    class IOSOPERATION : public OPERATION
    {
    public:
        IOSOPERATION() {}
        virtual ~IOSOPERATION() {}

        std::map<std::string, std::string> operation_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data);
    };
};

#endif /* _IOS_OPERATION_HEADER_ */

