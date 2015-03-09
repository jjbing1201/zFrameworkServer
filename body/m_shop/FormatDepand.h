#ifndef _FORMAT_DEPEND_HEADER_SHOP_
#define _FORMAT_DEPEND_HEADER_SHOP_

#include "shop_include.h"

class SHOPFORMAT_DEPAND
{
public:
    SHOPFORMAT_DEPAND() {}
    virtual ~SHOPFORMAT_DEPAND() {}

    std::map<std::string, std::string> normal_format(std::map<std::string, std::string> data);
};

#endif /* _FORMAT_DEPEND_HEADER_SHOP_ */
 
