#ifndef _IOS_FORMAT_HEADER_H_
#define _IOS_FORMAT_HEADER_H_

#include "ios_include.h"
#include "FormatDepand.h"

namespace N_IOS
{
    class IOSFORMAT : public FORMAT
    {
    protected:
        std::map<std::string, std::string> normal_format_inside(std::string interfaceName, std::map<std::string, std::string> data);

    public:
        IOSFORMAT() {}
        virtual ~IOSFORMAT() {}

        std::map<std::string, std::string> format_inter(\
                                   std::string interface, \
                                   std::map<std::string, std::string> data);
    
        std::map<std::string, std::string> format_inter_inherit(\
                                   std::string interface, \
                                   std::map<std::string, std::string> data);
    };
};

#endif /* _IOS_FORMAT_HEADER_H_ */

