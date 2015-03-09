#ifndef _INTERFACE_MASTER_
#define _INTERFACE_MASTER_

#define HTTP_RESPONSE_OK                "OK"
#define HTTP_RESPONSE_UNKNOWN           "Unknown"
#define HTTP_RESPONSE_BAD_REQUEST       "Bad Request"
#define HTTP_RESPONSE_NO_AUTH           "No Auth"
#define HTTP_RESPONSE_AUTH_FAILED       "Auth Failed"
#define HTTP_RESPONSE_FORBIDDEN         "Forbidden"
#define HTTP_RESPONSE_NOTFOUND          "Not Found"
#define HTTP_RESPONSE_SQL_INJECTION     "SQL Injection Var"
#define HTTP_RESPONSE_METHOD_NOT_ALLOW  "Method Not Allowed"
#define HTTP_RESPONSE_METHOD_NOT_FOUND  "Method Not Found"
#define HTTP_RESPONSE_OP_FAILED         "Operation Failed"
#define HTTP_RESPONSE_CMD_FAILED        "CMD Check Failed."
#define HTTP_RESPONSE_METHOD_CANCELD    "Interface has been canceled."
#define HTTP_RESPONSE_FATAL             "Internal Server Error"

typedef struct intefaceHandler
{
    char name[32];
    uint32 status;      // interface could be used or not
                        // 0 or cancel, 1 for support
    char package[2];    // dpart each of data.
    char version[13];
} _interHandler;

const _interHandler interfaceName[] =
{
    /* <<<<<<< Part 1. World For App >>>>>>>>>>>>>>> */
    {"ServerConnect", 1, "1", "0.1.140814"},
    {"ABBGetTelephoneToken", 1, "1", "0.1.140826"},
    {"ABBGetTelephoneTokenCheck", 1, "1", "0.1.140828"},
    {"ABBUploadLogAndTime", 1, "1", "0.1.140828"},
    {"ABBUploadTokenRecord", 1, "1", "0.1.140829"},
    {"ABBAPNSPush", 1, "1", "0.1.140829"},
    {"ABBUploadLogAndTimeSearch", 1, "1", "0.1.140904"},

    /* <<<<<<< Part 2. Process For App >>>>>>>>>>>> */
    {"ProcessSearchFirstSecond", 1, "1", "0.1.140826"},
    {"ProcessSearchThird", 1, "1", "0.1.140826"},
    {"ProcessSearchFourth", 1, "1", "0.1.140826"},
    {"UserRecordStatusOfChange", 1, "1", "0.1.140827"},
    {"UserRecordStatusOfSearch", 1, "1", "0.1.140827"},
    {"ProcessFirstSecondRecover", 1, "1", "0.1.140917"},
    {"ProcessSearchThirdRecover", 1, "1", "0.1.140918"},
    {"ProcessSearchFourthRecover", 1, "1", "0.1.140918"},

    /* <<<<<<< Part 3. BBS For MISQUARE >>>>>>>>>>> */
    {"BbsForumListSearch", 1, "1", "0.1.140829"},
    {"BbsForumThreadListSearch", 1, "1", "0.1.140829"},
    {"BbsSendPostListSearch", 1, "1", "0.1.140829"},
    {"BbsReqPostListSearch", 1, "1", "0.1.140829"},
    {"BbsSendPostResource", 1, "1", "0.1.140829"},
    {"BbsReqPostResource", 1, "1", "0.1.140829"},
	{"BbsUserPostSearch", 1, "1", "0.1.141010"},

    /* <<<<<<< Part 4. Method For User >>>>>>>>*/
    {"UnregisterUserTest", 1, "2", "0.1.140814"},
    {"BasicPropertyOperation", 1, "2", "0.1.140814"},
    {"ComplexPropertyHumanOp", 1, "2", "0.1.140814"},
    {"ComplexPropertyShopOp", 1, "2", "0.1.140814"},
    {"DeviceInformationOperation", 1, "2", "0.1.140815"},
    {"ThreeAuthorizedOperation", 1, "2", "0.1.140815"},
    {"PublicUserSearch", 1, "2", "0.1.140815"},
    {"MIWAUserLogin", 1, "2", "0.1.140821"},
    {"MIWAUserCareAdd", 1, "2", "0.1.140915"},
    {"MIWAUserCareSearch", 1, "2", "0.1.140915"},

    /* <<<<<<< Part 5. Method for Shop >>>>>>> */
    {"MIShopListSearch", 1, "3", "0.1.140820"},
    {"MIShopSearchDetailInform", 1, "3", "0.1.140821"},
    {"MIShopSearchDiscounts", 1, "3", "0.1.140821"},
    {"MIShopUserAssess", 1, "3", "0.1.140821"},
    {"MIShopSearchAssessList", 1, "3", "0.1.140821"},

    /* <<<<<<< Part 6. Upload Record. >>>>>>>*/
    {"UploadCommitToRecord", 1, "1", "0.1.140902"},
    {"UploadCommitToSearch", 1, "1", "0.1.140902"},
    {"UploadCommitToUserMain", 1, "1", "0.1.140902"},
    {"UploadCommitToSearchLog", 1, "1", "0.1.140902"},

	/* <<<<<<< Part 7. News for App >>>>>>>>*/
	{"NewsAddInto", 1, "1", "0.1.141011"},
	{"NewsAddLastOutside", 1, "1", "0.1.141011"},
	{"NewsListForUserSearch", 1, "1", "0.1.141011"},
	{"NewsListForUserSelf", 1, "1", "0.1.141014"}

};

#endif /* _INTERFACE_MASTER_ */
