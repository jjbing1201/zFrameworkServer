#ifndef _FORMAT_DEPEND_HEADER_IOS_
#define _FORMAT_DEPEND_HEADER_IOS_

#include "ios_include.h"

class IOSFORMAT_DEPAND
{
public:
    IOSFORMAT_DEPAND() {}
    virtual ~IOSFORMAT_DEPAND() {}

    std::map<std::string, std::string> normal_format(\
                                std::map<std::string, std::string> data);

    std::map<std::string, std::string> format_UnregisterUserTest(\
                               std::map<std::string, std::string> data);

};

#endif /* _FORMAT_DEPEND_HEADER_IOS_ */
 
