#ifndef _IOS_SERVER_RETURN_HEADER_
#define _IOS_SERVER_RETURN_HEADER_

#include "ios_include.h"
#include "table_include.h"
#include "IosSpell.h"
#include "IosFunction.h"

#include "SDepend.h"

namespace N_IOS
{
    class IOSRETURN : public SERVERRETURN
    {
    public:
        IOSRETURN() {}
        virtual ~IOSRETURN() {}

        std::map<std::string, std::string> serverreturn_inherit(\
                            std::string interface, \
                            std::map<std::string, std::string> data);
    };
};

#endif /* _IOS_SERVER_RETURN_HEADER_ */
