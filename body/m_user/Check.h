#ifndef _IOS_CHECK_HEADER_
#define _IOS_CHECK_HEADER_

#include "ios_include.h"

namespace N_IOS
{
    class IOSCHECK : public CHECKDATA
    {
    protected:
        std::map<std::string, std::string> check_inside(std::map<std::string, std::string> data);

    public:
        IOSCHECK() {}
        virtual ~IOSCHECK() {}

        std::map<std::string, std::string> check_inter(std::string interface, \
                                   std::map<std::string, std::string> data);
    
    };

};

#endif /* _IOS_CHECK_HEADER_ */

