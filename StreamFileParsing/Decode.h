#include <iostream>
#include <fstream>
#include "MessageHeader.h"
#include "Account_In.h"
#include "AdminCommand_In.h"
#include "CommissionRate_In.h"
#include "GatewayConfig_In.h"
#include "Instrument_In.h"
#include "Investor_In.h"
#include "InvestorPosition_In.h"
#include "InvestorPositionDtl_In.h"
#include "LoginReq_In.h"
#include "LogoutReq_In.h"
#include "MarginRate_In.h"
#include "Order_In.h"
#include "OrderCancelReq_In.h"
#include "OrderReq_In.h"
#include "QryAccount_In.h"
#include "QryCommissionRate_In.h"
#include "QryInstrument_In.h"
#include "QryMarginRate_In.h"
#include "QryOrder_In.h"
#include "QryPosition_In.h"
#include "QryRiskRule_In.h"
#include "QryTrade_In.h"
#include "RiskRule_In.h"
#include "RiskRuleLog_In.h"
#include "RspInfo_In.h"
#include "RspLogin_In.h"
#include "SeatGatewayAssign_In.h"
#include "Trade_In.h"
#include "TradeDate_In.h"
#include "TradingCode_In.h"

#include "MySQLManager.h"

using namespace std;
using namespace tfzq::stp::tradeopt;

#if defined(_WIN32)
		typedef signed char int8;
		typedef unsigned char uint8;
		typedef short int16;
		typedef unsigned short uint16;
		typedef int int32;
		typedef unsigned int uint32;
		typedef __int64 int64;
		typedef unsigned __int64 uint64;
#else 
		typedef signed char int8;
		typedef unsigned char uint8;
		typedef short int16;
		typedef unsigned short uint16;
		typedef int int32;
		typedef unsigned int uint32;
		typedef long long int64;
		typedef unsigned long long uint64;
#endif

#pragma pack(1)
//定义包头
struct PackageHeader
{
	char version;/**< 版本号	A*/
    char packageType;/**<REQ, REP */
    char chain;/**<报文链 LAST */
    char padding;
    int32 topicID; /*REQRSP TRADE*/
    int32 tID; /**信息正文类型 */
    int32 requestID; /**暂不启用 请求编号(由发送请求者维护，应答中会带回) */
    //int32 bodyLen;  
    int32 fieldCount;/** **/
    int32 frontID; //前置id
    //int64 sessionID; //会话编号
    int32 sessionID; //会话编号
    int32 time; //时间 //update
    int64 sequenceNo; /**<业务数据消息序号 */ 
    int64 lastSn;/**<业务消息上条序号 */
};

//定义域头
struct FieldHeader
{
    int32 fieldID;//小端字节序
    int32 fieldLength;//小端字节序
};
#pragma pack()

class Decoder
{
private:
    char* m_buffer;
    uint64 m_bufferLength;
    uint64 m_position;
    uint64 m_offset;
    //char** m_origin;
    void* m_origin;
    int32 m_tID;
    int32 m_fieldCount = 1;
    int32 m_fID;
	int32 m_fLength;
    int32 m_frontID; //update
    int32 m_sessionID; //update
    int32 m_time; //update

	int32 m_orderSource;//modified

	char m_TradingDay[9];

    int32 m_PackageHeader = 0;
    int32 m_FieldHeader = 0;
    int32 m_TradeDate = 0;
    int32 m_Instrument = 0;
    int32 m_Investor = 0;
    int32 m_TradingCode = 0;
    int32 m_Account = 0;
    int32 m_InvestorPosition = 0;
    int32 m_InvestorPositionDtl = 0;
    int32 m_CommissionRate = 0;
    int32 m_MarginRate = 0;
    int32 m_Order = 0;
    int32 m_Trade = 0;
    int32 m_RiskRule = 0;
    int32 m_RiskRuleLog = 0;
    int32 m_AdminCommand = 0;
    int32 m_RspInfo = 0;
    int32 m_LoginReq = 0;
    int32 m_LogoutReq = 0;
    int32 m_RspLogin = 0;
	int32 m_OrderReq = 0;
    int32 m_OrderCancelReq = 0;
    int32 m_QryRiskRule = 0;
    int32 m_QryInstrument = 0;
    int32 m_QryCommissionRate = 0;
    int32 m_QryMarginRate = 0;
    int32 m_QryOrder = 0;
    int32 m_QryTrade = 0;
    int32 m_QryAccount = 0;
    int32 m_QryPosition = 0;
    int32 m_SeatGatewayAssign = 0;
    int32 m_GatewayConfig = 0;

    MySQLManager *mysql;
    char sql[1024];


public:
    Decoder();
    void read(char* filename);

    void decodePackageHeader();
    void decodeFieldHeader();
    void decodeTradeDate();
    void decodeInstrument();
    void decodeInvestor();
    void decodeTradingCode();
    void decodeAccount();
    void decodeInvestorPosition();
    void decodeInvestorPositionDtl();
    void decodeCommissionRate();
    void decodeMarginRate();
    void decodeOrder();
    void decodeTrade();
    void decodeRiskRule();
    void decodeRiskRuleLog();
    void decodeAdminCommand();
    void decodeRspInfo();
    void decodeLoginReq();
    void decodeLogoutReq();
    void decodeRspLogin();
	void decodeOrderReq();
    void decodeOrderCancelReq();
    void decodeQryRiskRule();
    void decodeQryInstrument();
    void decodeQryCommissionRate();
    void decodeQryMarginRate();
    void decodeQryOrder();
    void decodeQryTrade();
    void decodeQryAccount();
    void decodeQryPosition();
    void decodeSeatGatewayAssign();
    void decodeGatewayConfig();


    void decode();
};