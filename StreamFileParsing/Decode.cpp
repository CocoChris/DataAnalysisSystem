#include "Decode.h"
#include <string>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

Decoder::Decoder() : m_buffer(nullptr), m_bufferLength(0), m_position(0), m_offset(4) {}

void Decoder::read(char* filename)
{
    ifstream file(filename, ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
		//char m_TradingDay[9];
		memcpy(m_TradingDay, filename + 15, 8);
		m_TradingDay[8] = '\0';
		//cout << "**************" << m_TradingDay << endl;

		m_bufferLength = file.tellg();
		m_buffer = new char[m_bufferLength];
		file.seekg(0, ios::beg);
		file.read(m_buffer, m_bufferLength);
		file.close();

		m_origin = static_cast<void *>(m_buffer);
		//m_origin = &m_buffer;
		cout << "the origin position is: " << m_origin << endl;
		cout << "the file content is in memory\n";
		cout << "the size of stream file is: " << m_bufferLength << endl;
		//cout << "buf now at: " << static_cast<const void *>(m_buffer) << endl;
		//m_position = &m_buffer - m_origin;
		m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
		cout << "buffer now at: " << m_position << endl;
		cout << endl;
	}
	else
		cout << "fail to open the file" << endl;
}

void Decoder::decodePackageHeader()
{
    PackageHeader pHeader;
    //m_buffer += m_fieldCount * m_offset;//去掉流文件的前4个字节
    m_buffer += m_offset;//去掉流文件的前4个字节
    memcpy(&pHeader, m_buffer, sizeof(pHeader));
    cout << "the size of PackageHeader is: " << sizeof(pHeader) << endl;
    m_tID = pHeader.tID;
    m_fieldCount = pHeader.fieldCount;
    m_frontID = pHeader.frontID; //update
    m_sessionID = pHeader.sessionID; //update
    m_time = pHeader.time; //update
    m_PackageHeader += 1;
    
    m_buffer += sizeof(pHeader);//移动buffer
    cout << "PackageHeader.version = " << pHeader.version << endl;
    cout << "PackageHeader.packageType = " << pHeader.packageType << endl;
    cout << "PackageHeader.chain = " << pHeader.chain << endl;
    cout << "PackageHeader.padding = " << pHeader.padding << endl;
    cout << "PackageHeader.topicID = " << pHeader.topicID << endl;
    cout << "PackageHeader.tID = " << pHeader.tID << endl;
    cout << "PackageHeader.requestID = " << pHeader.requestID << endl;
    //cout << "PackageHeader.bodyLen = " << pHeader.bodyLen << endl;
    cout << "PackageHeader.fieldCount = " << pHeader.fieldCount << endl;
    cout << "PackageHeader.frontID = " << pHeader.frontID << endl;
    cout << "PackageHeader.sessionID = " << pHeader.sessionID << endl;
    cout << "PackageHeader.time = " << m_time << endl;
    cout << "PackageHeader.sequenceNo = " << pHeader.sequenceNo << endl;
    cout << "PackageHeader.lastSn = " << pHeader.lastSn << endl;

    //m_position = &m_buffer - m_origin;
    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl;
}

void Decoder::decodeFieldHeader()
{
    //m_buffer += m_offset;
    FieldHeader fHeader;
    memcpy(&fHeader, m_buffer, sizeof(fHeader));
    cout << "the size of FieldHeader is: " << sizeof(fHeader) << endl;
    m_fID = fHeader.fieldID;
	m_fLength = fHeader.fieldLength;
    m_FieldHeader += 1;

    m_buffer += sizeof(fHeader);

    cout << "FieldHeader.fieldID = " << fHeader.fieldID << endl;
    cout << "FieldHeader.fieldLength = " << fHeader.fieldLength << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
	cout << "buffer now at: " << m_position << endl;
    //cout << "buffer now at: " << static_cast<const void *>(buf) << endl;
    cout << endl;
}

void Decoder::decodeTradeDate()
{
    //m_buffer += m_offset;
    TradeDate_In tradeDate(m_buffer, m_bufferLength);
    tradeDate.wrapForDecode(m_buffer, 0, tradeDate.sbeBlockLength(), tradeDate.sbeSchemaVersion(), tradeDate.encodedLength());
    cout << "the size of Message is: " << tradeDate.encodedLength() << endl;
    m_TradeDate += 1;
    m_buffer += tradeDate.encodedLength();

    cout << "TradeDate.TradingDay = " << tradeDate.tradingDay() << endl;
    cout << "TradeDate.SystemStatus = " << tradeDate.systemStatus() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeInstrument()
{
    //m_buffer += m_offset;
    Instrument_In instrument(m_buffer, m_bufferLength);
    instrument.wrapForDecode(m_buffer, 0, instrument.sbeBlockLength(), instrument.sbeSchemaVersion(), instrument.encodedLength());
    //cout << "the size is: " << sizeof(instrument) << endl;
    cout << "the size of Message is: " << instrument.encodedLength() << endl;
    m_Instrument += 1;
    m_buffer += instrument.encodedLength();

    cout << "Instrument.ExchangeID = " << instrument.exchangeID() << endl;
    cout << "Instrument.ProductID = " << instrument.productID() << endl;
    cout << "Instrument.InstrumentID = " << instrument.instrumentID() << endl;
    cout << "Instrument.InstrumentCode = " << instrument.instrumentCode() << endl;
    cout << "Instrument.InstrumentName = " << instrument.instrumentName() << endl; 
    cout << "Instrument.ProductClass = " << instrument.productClass() << endl;
    cout << "Instrument.VolumeMultiple = " << instrument.volumeMultiple() << endl; 
    cout << "Instrument.PriceTick = " << instrument.priceTick() << endl;  
    cout << "Instrument.OpenDate = " << instrument.openDate() << endl; 
    cout << "Instrument.ExpireDate = " << instrument.expireDate() << endl;
    cout << "Instrument.IsTrading = " << instrument.isTrading() << endl;  
    cout << "Instrument.ExecPrice = " << instrument.execPrice() << endl; 
    cout << "Instrument.UnitMargin = " << instrument.unitMargin() << endl;  
    cout << "Instrument.TradingDay = " << instrument.tradingDay() << endl;
    cout << "Instrument.ExerciseDay = " << instrument.exerciseDay() << endl;
	cout << "Instrument.MaxMarketOrderVolume = " << instrument.maxMarketOrderVolume() << endl;
	cout << "Instrument.MinMarketOrderVolume = " << instrument.minMarketOrderVolume() << endl;
	cout << "Instrument.MaxLimitOrderVolume = " << instrument.maxLimitOrderVolume() << endl;
	cout << "Instrument.MinLimitOrderVolume = " << instrument.minLimitOrderVolume() << endl;
    cout << "Instrument.UpperLimitPrice = " << instrument.upperLimitPrice() << endl;
    cout << "Instrument.LowerLimitPrice = " << instrument.lowerLimitPrice() << endl;
    cout << "Instrument.OptionType = " << instrument.optionType() << endl; 
    cout << "Instrument.BuyVolumeTick = " << instrument.buyVolumeTick() << endl; 
    cout << "Instrument.SellVolumeTick = " << instrument.sellVolumeTick() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeInvestor()
{
    //m_buffer += m_offset;
    Investor_In investor(m_buffer, m_bufferLength);
    investor.wrapForDecode(m_buffer, 0, investor.sbeBlockLength(), investor.sbeSchemaVersion(), investor.encodedLength());
    //cout << "the size is: " << sizeof(investor) << endl;
    cout << "the size of Message is: " << investor.encodedLength() << endl;
    m_Investor += 1;
    m_buffer += investor.encodedLength();

    cout << "Investor.TradingDay = " << investor.tradingDay() << endl;
    cout << "Investor.InvestorID = " << investor.investorID() << endl;
    cout << "Investor.AccountID = " << investor.accountID() << endl;
    cout << "Investor.Password = " << investor.password() << endl;
    cout << "Investor.InvestorName = " << investor.investorName() << endl; 
    cout << "Investor.InvestorType = " << investor.investorType() << endl;
    cout << "Investor.IDCardType = " << investor.iDCardType() << endl; 
    cout << "Investor.IDCardNo = " << investor.iDCardNo() << endl;  
    cout << "Investor.IsActive = " << investor.isActive() << endl; 
    cout << "Investor.GroupID = " << investor.groupID() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeTradingCode()
{
    //m_buffer += m_offset;
    TradingCode_In tradingCode(m_buffer, m_bufferLength);
    tradingCode.wrapForDecode(m_buffer, 0, tradingCode.sbeBlockLength(), tradingCode.sbeSchemaVersion(), tradingCode.encodedLength());
    //cout << "the size is: " << sizeof(tradingCode) << endl;
    cout << "the size of Message is: " << tradingCode.encodedLength() << endl;
    m_TradingCode += 1;
    m_buffer += tradingCode.encodedLength();

    cout << "TradingCode.TradingDay = " << tradingCode.tradingDay() << endl;
    cout << "TradingCode.InvestorID = " << tradingCode.investorID() << endl;
    cout << "TradingCode.ExchangeID = " << tradingCode.exchangeID() << endl;
    cout << "TradingCode.TradingCodeType = " << tradingCode.tradingCodeType() << endl;
    cout << "TradingCode.TradeCode = " << tradingCode.tradeCode() << endl; 
    cout << "TradingCode.BranchID = " << tradingCode.branchID() << endl;
    cout << "TradingCode.SeatID = " << tradingCode.seatID() << endl; 
    cout << "TradingCode.OptClientID = " << tradingCode.optClientID() << endl;  
    cout << "TradingCode.IsActive = " << tradingCode.isActive() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeAccount()
{
    //m_buffer += m_offset;
    Account_In account(m_buffer, m_bufferLength);
    account.wrapForDecode(m_buffer, 0, account.sbeBlockLength(), account.sbeSchemaVersion(), account.encodedLength());
    //cout << "the size is: " << sizeof(account) << endl;
    cout << "the size of Message is: " << account.encodedLength() << endl;
    m_Account += 1;
    m_buffer += account.encodedLength();

    cout << "Account.TradingDay = " << account.tradingDay() << endl;
    cout << "Account.AccountID = " << account.accountID() << endl;
    cout << "Account.CurrencyID = " << account.currencyID() << endl;
    cout << "Account.AccountName = " << account.accountName() << endl;
    cout << "Account.PreDeposit = " << account.preDeposit() << endl; 
    cout << "Account.PreMargin = " << account.preMargin() << endl;
    cout << "Account.PreBalance = " << account.preBalance() << endl; 
    cout << "Account.Balance = " << account.balance() << endl;  
    cout << "Account.Deposit = " << account.deposit() << endl; 
    cout << "Account.FrozenMargin = " << account.frozenMargin() << endl;
    cout << "Account.FrozenCommission = " << account.frozenCommission() << endl;  
    cout << "Account.FrozenCash = " << account.frozenCash() << endl; 
    cout << "Account.UseMargin = " << account.useMargin() << endl;  
    cout << "Account.Commission = " << account.commission() << endl;
    cout << "Account.WithdrawQuota = " << account.withdrawQuota() << endl;
    cout << "Account.Credit = " << account.credit() << endl;  
    cout << "Account.Available = " << account.available() << endl; 
    cout << "Account.CloseProfit = " << account.closeProfit() << endl;
    cout << "Account.PositionProfit = " << account.positionProfit() << endl;
    cout << "Account.CashIn = " << account.cashIn() << endl;
    cout << "Account.CashOut = " << account.cashOut() << endl;
    cout << "Account.IsDefault = " << account.isDefault() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeInvestorPosition()
{
    //m_buffer += m_offset;
    InvestorPosition_In investorPosition(m_buffer, m_bufferLength);
    investorPosition.wrapForDecode(m_buffer, 0, investorPosition.sbeBlockLength(), investorPosition.sbeSchemaVersion(), investorPosition.encodedLength());
    //cout << "the size is: " << sizeof(investorPosition) << endl;
    cout << "the size of Message is: " << investorPosition.encodedLength() << endl;
    m_InvestorPosition += 1;
    m_buffer += investorPosition.encodedLength();

    cout << "InvestorPosition.InvestorID = " << investorPosition.investorID() << endl;
    cout << "InvestorPosition.ExchangeID = " << investorPosition.exchangeID() << endl;
    cout << "InvestorPosition.InstrumentID = " << investorPosition.instrumentID() << endl; 
    cout << "InvestorPosition.CoveredFlag = " << investorPosition.coveredFlag() << endl;  
    cout << "InvestorPosition.PosiDirection = " << investorPosition.posiDirection() << endl; 
    cout << "InvestorPosition.TradingCode = " << investorPosition.tradingCode() << endl;
    cout << "InvestorPosition.TradingDay = " << investorPosition.tradingDay() << endl;  
    cout << "InvestorPosition.YdPosition = " << investorPosition.ydPosition() << endl; 
    cout << "InvestorPosition.PreMargin = " << investorPosition.preMargin() << endl;  
    cout << "InvestorPosition.TodayPosition = " << investorPosition.todayPosition() << endl;
    cout << "InvestorPosition.TotalPosition = " << investorPosition.totalPosition() << endl;
    cout << "InvestorPosition.UseMargin = " << investorPosition.useMargin() << endl;  
    cout << "InvestorPosition.OpenVolume = " << investorPosition.openVolume() << endl; 
    cout << "InvestorPosition.CloseVolume = " << investorPosition.closeVolume() << endl;
    cout << "InvestorPosition.SettlementPrice = " << investorPosition.settlementPrice() << endl;
    cout << "InvestorPosition.PreSettlementPrice = " << investorPosition.preSettlementPrice() << endl;
    cout << "InvestorPosition.Commission = " << investorPosition.commission() << endl;
    cout << "InvestorPosition.FrozenCommission = " << investorPosition.frozenCommission() << endl; 
    cout << "InvestorPosition.FrozenMargin = " << investorPosition.frozenMargin() << endl; 
    cout << "InvestorPosition.OpenCost = " << investorPosition.openCost() << endl; 
    cout << "InvestorPosition.PositionCost = " << investorPosition.positionCost() << endl; 
    cout << "InvestorPosition.CloseProfit = " << investorPosition.closeProfit() << endl;
    cout << "InvestorPosition.PositionProfit = " << investorPosition.positionProfit() << endl; 
    cout << "InvestorPosition.OpenAmount = " << investorPosition.openAmount() << endl; 
    cout << "InvestorPosition.CloseAmount = " << investorPosition.closeAmount() << endl; 
    cout << "InvestorPosition.LongFrozen = " << investorPosition.longFrozen() << endl; 
    cout << "InvestorPosition.LongFrozenAmount = " << investorPosition.longFrozenAmount() << endl; 
    cout << "InvestorPosition.ShortFrozen = " << investorPosition.shortFrozen() << endl; 
    cout << "InvestorPosition.ShortFrozenAmount = " << investorPosition.shortFrozenAmount() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeInvestorPositionDtl()
{
    //m_buffer += m_offset;
    InvestorPositionDtl_In investorPositionDtl(m_buffer, m_bufferLength);
    investorPositionDtl.wrapForDecode(m_buffer, 0, investorPositionDtl.sbeBlockLength(), investorPositionDtl.sbeSchemaVersion(), investorPositionDtl.encodedLength());
    //cout << "the size is: " << sizeof(investorPositionDtl) << endl;
    cout << "the size of Message is: " << investorPositionDtl.encodedLength() << endl;
    m_InvestorPositionDtl += 1;
    m_buffer += investorPositionDtl.encodedLength();

    cout << "InvestorPositionDtl.InvestorID = " << investorPositionDtl.investorID() << endl;
    cout << "InvestorPositionDtl.ExchangeID = " << investorPositionDtl.exchangeID() << endl;
    cout << "InvestorPositionDtl.InstrumentID = " << investorPositionDtl.instrumentID() << endl;
    cout << "InvestorPositionDtl.CoveredFlag = " << investorPositionDtl.coveredFlag() << endl; 
    cout << "InvestorPositionDtl.PosiDirection = " << investorPositionDtl.posiDirection() << endl;
    cout << "InvestorPositionDtl.OpenDate = " << investorPositionDtl.openDate() << endl; 
    cout << "InvestorPositionDtl.TradeID = " << investorPositionDtl.tradeID() << endl;  
    cout << "InvestorPositionDtl.TradingCode = " << investorPositionDtl.tradingCode() << endl;  
    cout << "InvestorPositionDtl.TradingDay = " << investorPositionDtl.tradingDay() << endl; 
    cout << "InvestorPositionDtl.Volume = " << investorPositionDtl.volume() << endl;  
    cout << "InvestorPositionDtl.SettlementPrice = " << investorPositionDtl.settlementPrice() << endl;
    cout << "InvestorPositionDtl.PreSettlementPrice = " << investorPositionDtl.preSettlementPrice() << endl;
    cout << "InvestorPositionDtl.OpenPrice = " << investorPositionDtl.openPrice() << endl;  
    cout << "InvestorPositionDtl.Margin = " << investorPositionDtl.margin() << endl; 
    cout << "InvestorPositionDtl.MarginRate = " << investorPositionDtl.marginRate() << endl;
    cout << "InvestorPositionDtl.CloseVolume = " << investorPositionDtl.closeVolume() << endl;
    cout << "InvestorPositionDtl.CloseAmount = " << investorPositionDtl.closeAmount() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl;  
}

void Decoder::decodeCommissionRate()
{
    //m_buffer += m_offset;
    CommissionRate_In commissionRate(m_buffer, m_bufferLength);
    commissionRate.wrapForDecode(m_buffer, 0, commissionRate.sbeBlockLength(), commissionRate.sbeSchemaVersion(), commissionRate.encodedLength());
    //cout << "the size is: " << sizeof(commissionRate) << endl;
    cout << "the size of Message is: " << commissionRate.encodedLength() << endl;
    m_CommissionRate += 1;
    m_buffer += commissionRate.encodedLength();

    cout << "CommissionRate.TradingDay = " << commissionRate.tradingDay() << endl;
    cout << "CommissionRate.InvestorID = " << commissionRate.investorID() << endl;
    cout << "CommissionRate.InvestorRange = " << commissionRate.investorRange() << endl;
    cout << "CommissionRate.ExchangeID = " << commissionRate.exchangeID() << endl;
    cout << "CommissionRate.InstrumentID = " << commissionRate.instrumentID() << endl; 
    cout << "CommissionRate.ProductClass = " << commissionRate.productClass() << endl;  
    cout << "CommissionRate.Direction = " << commissionRate.direction() << endl; 
    cout << "CommissionRate.OffsetFlag = " << commissionRate.offsetFlag() << endl;
    cout << "CommissionRate.CoveredFlag = " << commissionRate.coveredFlag() << endl; 
    cout << "CommissionRate.StampTaxRateByMoney = " << commissionRate.stampTaxRateByMoney() << endl;
    cout << "CommissionRate.stampTaxRateByVolume = " << commissionRate.stampTaxRateByVolume() << endl;
    cout << "CommissionRate.TransferFeeRateByMoney = " << commissionRate.transferFeeRateByMoney() << endl;
    cout << "CommissionRate.TransferFeeRateByVolume = " << commissionRate.transferFeeRateByVolume() << endl;
    cout << "CommissionRate.HandlingFeeByMoney = " << commissionRate.handlingFeeByMoney() << endl; 
    cout << "CommissionRate.handlingFeeByVolume = " << commissionRate.handlingFeeByVolume() << endl; 
    cout << "CommissionRate.AdminFeeByMoney = " << commissionRate.adminFeeByMoney() << endl; 
    cout << "CommissionRate.AdminFeeByVolume = " << commissionRate.adminFeeByVolume() << endl; 
    cout << "CommissionRate.TradeFeeByMoney = " << commissionRate.tradeFeeByMoney() << endl;
    cout << "CommissionRate.TradeFeeByVolume = " << commissionRate.tradeFeeByVolume() << endl; 
    cout << "CommissionRate.ClearingFeeByMoney = " << commissionRate.clearingFeeByMoney() << endl; 
    cout << "CommissionRate.ClearingFeeByVolume = " << commissionRate.clearingFeeByVolume() << endl; 
    cout << "CommissionRate.OtherFeeByMoney = " << commissionRate.otherFeeByMoney() << endl; 
    cout << "CommissionRate.OtherFeeByVolume = " << commissionRate.otherFeeByVolume() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeMarginRate()
{
    //m_buffer += m_offset;
    MarginRate_In marginRate(m_buffer, m_bufferLength);
    marginRate.wrapForDecode(m_buffer, 0, marginRate.sbeBlockLength(), marginRate.sbeSchemaVersion(), marginRate.encodedLength());
    //cout << "the size is: " << sizeof(marginRate) << endl;
    cout << "the size of Message is: " << marginRate.encodedLength() << endl;
    m_MarginRate += 1;
    m_buffer += marginRate.encodedLength();

    cout << "MarginRate.TradingDay = " << marginRate.tradingDay() << endl;
    cout << "MarginRate.InvestorID = " << marginRate.investorID() << endl;
    cout << "MarginRate.InvestorRange = " << marginRate.investorRange() << endl;
    cout << "MarginRate.ExchangeID = " << marginRate.exchangeID() << endl;
    cout << "MarginRate.InstrumentID = " << marginRate.instrumentID() << endl; 
    cout << "MarginRate.CoveredFlag = " << marginRate.coveredFlag() << endl; 
    cout << "MarginRate.OptionType = " << marginRate.optionType() << endl;
    cout << "MarginRate.ProductClass = " << marginRate.productClass() << endl;
    cout << "MarginRate.LongMarginRatioByMoney = " << marginRate.longMarginRatioByMoney() << endl;
    cout << "MarginRate.LongMarginRatioByVolume = " << marginRate.longMarginRatioByVolume() << endl;
    cout << "MarginRate.ShortMarginRatioByMoney = " << marginRate.shortMarginRatioByMoney() << endl; 
    cout << "MarginRate.ShortMarginRatioByVolume = " << marginRate.shortMarginRatioByVolume() << endl; 
    cout << "MarginRate.IsFloat = " << marginRate.isFloat() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeOrder()
{
    //m_buffer += m_offset;
    Order_In order(m_buffer, m_bufferLength);
    order.wrapForDecode(m_buffer, 0, order.sbeBlockLength(), order.sbeSchemaVersion(), order.encodedLength());
    //cout << "the size is: " << sizeof(order) << endl;
    cout << "the size of Message is: " << order.encodedLength() << endl;
    m_Order += 1;
    m_buffer += order.encodedLength();

    cout << "Order.TradingDay = " << order.tradingDay() << endl;
    cout << "Order.InvestorID = " << order.investorID() << endl;
    cout << "Order.SessionID = " << order.sessionID() << endl;
    cout << "Order.FrontID = " << order.frontID() << endl;
    cout << "Order.OrderRef = " << order.orderRef() << endl; 
    cout << "Order.ExchangeID = " << order.exchangeID() << endl;
    cout << "Order.SeatID = " << order.seatID() << endl; 
    cout << "Order.OrderLocalID = " << order.orderLocalID() << endl;  
    cout << "Order.Direction = " << order.direction() << endl; 
    cout << "Order.UserID = " << order.userID() << endl;
    cout << "Order.TradingCode = " << order.tradingCode() << endl;  
    cout << "Order.BranchID = " << order.branchID() << endl; 
    cout << "Order.InstrumentID = " << order.instrumentID() << endl;  
    cout << "Order.OrderPriceType = " << order.orderPriceType() << endl;
    cout << "Order.CombOffsetFlag = " << order.combOffsetFlag() << endl;
    cout << "Order.CombHedgeFlag = " << order.combHedgeFlag() << endl;  
    cout << "Order.CoveredFlag = " << order.coveredFlag() << endl; 
    cout << "Order.LimitPrice = " << order.limitPrice() << endl;
    cout << "Order.VolumeTotalOriginal = " << order.volumeTotalOriginal() << endl;
    cout << "Order.TimeCondition = " << order.timeCondition() << endl;
    cout << "Order.VolumeCondition = " << order.volumeCondition() << endl;
    cout << "Order.MinVolume = " << order.minVolume() << endl; 
    cout << "Order.ContingentCondition = " << order.contingentCondition() << endl; 
    cout << "Order.StopPrice = " << order.stopPrice() << endl; 
    cout << "Order.RequestID = " << order.requestID() << endl; 
    //cout << "Order.OrderSubmitStatus = " << order.orderSubmitStatus() << endl;
    cout << "Order.OrderSysID = " << order.orderSysID() << endl; 
    cout << "Order.OrderStatus = " << order.orderStatus() << endl; 
    cout << "Order.OrderType = " << order.orderType() << endl; 
    cout << "Order.VolumeTraded = " << order.volumeTraded() << endl; 
    cout << "Order.AmountTraded = " << order.amountTraded() << endl; 
    cout << "Order.VolumeRemain = " << order.volumeRemain() << endl; 
    cout << "Order.InsertDate = " << order.insertDate() << endl;
    cout << "Order.InsertTime = " << order.insertTime() << endl; 
	//cout << "Order.InsertTime = " << m_time << endl;
    cout << "Order.UpdateTime = " << order.updateTime() << endl;
    cout << "Order.CancelTime = " << order.cancelTime() << endl;  
    cout << "Order.OrderActionRef = " << order.orderActionRef() << endl;
    cout << "Order.StatusMsg = " << order.statusMsg() << endl;
    cout << "Order.OwnerType = " << order.ownerType() << endl; 
    cout << "Order.ThirdReff1 = " << order.thirdReff1() << endl;  
    cout << "Order.ThirdReff2 = " << order.thirdReff2() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 

	//m_buffer -= 1;

	if (m_tID == 0x5000 + 13)//modified
	{
		m_orderSource = 0;
	}
	else if (m_tID == 0x5000 + 8)
	{
		m_orderSource = 1;
	}
	else if (m_tID == 0x5000 + 11)
	{
		m_orderSource = 2;
	}
	else if (m_tID == 0x5000 + 15)
	{
		m_orderSource = 3;
	}
	else if (m_tID == 0x5000 + 16)
	{
		m_orderSource = 4;
	}
	else if (m_tID == 0x5000 + 34)
	{
		m_orderSource = 5;
	}

	cout << "order_source is: " << m_orderSource << endl;

	
	sprintf(sql, "insert into orders (trading_day, investor_id, session_id, front_id, order_ref, exchange_id, seat_id, order_local_id, direction, user_id, trading_code, branch_id, instrument_id, order_price_type, comb_offset_flag, comb_hedge_flag, covered_flag, limit_price, volume_total_original, time_condition, volume_condition, min_volume, contingent_condition, stop_price, request_id, order_sys_id, order_status, order_type, volume_traded, amount_traded, volume_remain, insert_date, insert_time, update_time, cancel_time, order_action_ref, status_msg, owner_type, third_reff1, third_reff2, order_source)\
					 	    values('%s', '%s', '%d', '%d', '%s', '%s', '%s', '%s', '%c', '%s', '%s', '%s', '%s', '%c', '%s', '%s', '%c', '%f', '%d', '%c', '%c', '%d', '%c', '%f', '%d', '%s', '%c', '%c', '%d', '%f', '%d', '%s', '%d', '%s', '%s', '%s', '%s', '%c', '%s', '%s', '%d')",
							order.tradingDay(),
							order.investorID(),
							order.sessionID(),
							order.frontID(),
							order.orderRef(),
							order.exchangeID(),
							order.seatID(),
							order.orderLocalID(),
							order.direction(),
							order.userID(),
							order.tradingCode(),
							order.branchID(),
							order.instrumentID(),
							order.orderPriceType(),
							order.combOffsetFlag(),
							order.combHedgeFlag(),
							order.coveredFlag(),
							order.limitPrice(),
							order.volumeTotalOriginal(),
							order.timeCondition(),
							order.volumeCondition(),
							order.minVolume(),
							order.contingentCondition(),
							order.stopPrice(),
							order.requestID(),
							//order.orderSubmitStatus(),
							order.orderSysID(),
							order.orderStatus(),
							order.orderType(),
							order.volumeTraded(),
							order.amountTraded(),
							order.volumeRemain(),
							order.insertDate(),
							//order.insertTime(),
							m_time,
							order.updateTime(),
							order.cancelTime(),
							order.orderActionRef(),
							order.statusMsg(),
							order.ownerType(),
							order.thirdReff1(),
							order.thirdReff2(),
							m_orderSource);
	//modified
	/*else
	{
		sprintf(sql, "insert into orders_new (trading_day, investor_id, session_id, front_id, order_ref, exchange_id, seat_id, order_local_id, direction, user_id, trading_code, branch_id, instrument_id, order_price_type, comb_offset_flag, comb_hedge_flag, covered_flag, limit_price, volume_total_original, time_condition, volume_condition, min_volume, contingent_condition, stop_price, request_id, order_sys_id, order_status, order_type, volume_traded, amount_traded, volume_remain, insert_date, insert_time, update_time, cancel_time, order_action_ref, status_msg, owner_type, third_reff1, third_reff2, order_source)\
					 					 		values('%s', '%s', '%d', '%d', '%s', '%s', '%s', '%s', '%c', '%s', '%s', '%s', '%s', '%c', '%s', '%s', '%c', '%f', '%d', '%c', '%c', '%d', '%c', '%f', '%d', '%s', '%c', '%c', '%d', '%f', '%d', '%s', '%d', '%s', '%s', '%s', '%s', '%c', '%s', '%s', '%d')",
												//order.tradingDay(),
												m_TradingDay,
												//order.investorID(),
												order.tradingCode(),
												order.sessionID(),
												order.frontID(),
												order.orderRef(),
												order.exchangeID(),
												order.seatID(),
												order.orderLocalID(),
												order.direction(),
												order.userID(),
												//order.tradingCode(),
												order.investorID(),
												order.branchID(),
												order.instrumentID(),
												order.orderPriceType(),
												order.combOffsetFlag(),
												order.combHedgeFlag(),
												order.coveredFlag(),
												order.limitPrice(),
												order.volumeTotalOriginal(),
												order.timeCondition(),
												order.volumeCondition(),
												order.minVolume(),
												order.contingentCondition(),
												order.stopPrice(),
												order.requestID(),
												//order.orderSubmitStatus(),
												order.orderSysID(),
												order.orderStatus(),
												order.orderType(),
												order.volumeTraded(),
												order.amountTraded(),
												order.volumeRemain(),
												order.insertDate(),
												//order.insertTime(),
												m_time,
												order.updateTime(),
												order.cancelTime(),
												order.orderActionRef(),
												order.statusMsg(),
												order.ownerType(),
												order.thirdReff1(),
												order.thirdReff2(),
												m_orderSource);
	}*/
    /*string sql = "insert into Order values(order.tradingDay(), 
                                           order.investorID(), 
                                           order.sessionID(), 
                                           order.frontID(),
                                           order.orderRef(),
                                           order.exchangeID(),
                                           order.seatID(),
                                           order.orderLocalID(),
                                           order.direction(),
                                           order.userID(),
                                           order.tradingCode(),
                                           order.branchID(),
                                           order.instrumentID(),
                                           order.orderPriceType(),
                                           order.combOffsetFlag(),
                                           order.combHedgeFlag(),
                                           order.coveredFlag(),
                                           order.limitPrice(),
                                           order.volumeTotalOriginal(),
                                           order.timeCondition(),
                                           order.volumeCondition(),
                                           order.minVolume(),
                                           order.contingentCondition(),
                                           order.stopPrice(),
                                           order.requestID(),
                                           order.orderSubmitStatus(),
                                           order.orderSysID(),
                                           order.orderStatus(),
                                           order.orderType(),
                                           order.volumeTraded(),
                                           order.amountTraded(),
                                           volumeRemain(),
                                           insertDate(),
                                           order.insertTime(),
                                           order.updateTime(),
                                           order.cancelTime(),
                                           order.orderActionRef(),
                                           order.statusMsg(),
                                           order.ownerType(),
                                           order.thirdReff1(),
                                           order.thirdReff2())";*/
    //cout << sql << endl; 
	mysql->insert(sql);
	/*if (m_orderSource != 0)
	{
		cout << "OrderSource: " << m_orderSource << endl;
		cout << "tID: " << m_tID << endl;
		system("PAUSE");
	}*/
}

void Decoder::decodeTrade()
{
    //m_buffer += m_offset;
    Trade_In trade(m_buffer, m_bufferLength);
    trade.wrapForDecode(m_buffer, 0, trade.sbeBlockLength(), trade.sbeSchemaVersion(), trade.encodedLength());
    //cout << "the size is: " << sizeof(trade) << endl;
    cout << "the size of Message is: " << trade.encodedLength() << endl;
    m_Trade += 1;
    m_buffer += trade.encodedLength();

    cout << "Trade.TradingDay = " << trade.tradingDay() << endl;
    cout << "Trade.InvestorID = " << trade.investorID() << endl;
    cout << "Trade.ExchangeID = " << trade.exchangeID() << endl;
    cout << "Trade.TradeID = " << trade.tradeID() << endl;  
    cout << "Trade.Direction = " << trade.direction() << endl; 
    cout << "Trade.TradingCode = " << trade.tradingCode() << endl;  
    cout << "Trade.SeatID = " << trade.seatID() << endl; 
    cout << "Trade.BranchID = " << trade.branchID() << endl; 
    cout << "Trade.InstrumentCode = " << trade.instrumentCode() << endl; 
    cout << "Trade.InstrumentID = " << trade.instrumentID() << endl;  
    cout << "Trade.UserID = " << trade.userID() << endl;
    cout << "Trade.RequestID = " << trade.requestID() << endl; 
    cout << "Trade.OrderSysID = " << trade.orderSysID() << endl;
    cout << "Trade.OrderLocalID = " << trade.orderLocalID() << endl; 
    cout << "Trade.OrderRef = " << trade.orderRef() << endl; 
    cout << "Trade.OffsetFlag = " << trade.offsetFlag() << endl; 
    cout << "Trade.CoveredFlag = " << trade.coveredFlag() << endl; 
    cout << "Trade.HedgeFlag = " << trade.hedgeFlag() << endl; 
    cout << "Trade.Price = " << trade.price() << endl; 
    cout << "Trade.Volume = " << trade.volume() << endl;
    cout << "Trade.TradeAmount = " << trade.tradeAmount() << endl; 
    cout << "Trade.TradeDate = " << trade.tradeDate() << endl;
    cout << "Trade.TradeTime = " << trade.tradeTime() << endl;  
    cout << "Trade.Commission = " << trade.commission() << endl;
    cout << "Trade.SequenceNo = " << trade.sequenceNo() << endl;
    cout << "Trade.OwnerType = " << trade.ownerType() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
    
    sprintf(sql, "insert into trade values('%s', '%s', '%s', '%s', '%c', '%s', '%s', '%s', '%s', '%s', '%s', '%d', '%s', '%s', '%s', '%c', '%c', '%c', '%f', '%d', '%f', '%s', '%s', '%f', '%d', '%c')",
            trade.tradeID(),
            trade.tradingDay(),
            trade.investorID(),
            trade.exchangeID(),
            trade.direction(),
            trade.tradingCode(),
            trade.seatID(),
            trade.branchID(),
            trade.instrumentCode(),
            trade.instrumentID(),
            trade.userID(),
            trade.requestID(),
            trade.orderSysID(),
            trade.orderLocalID(),
            trade.orderRef(),
            trade.offsetFlag(),
            trade.coveredFlag(),
            trade.hedgeFlag(),
            trade.price(),
            trade.volume(),
            trade.tradeAmount(),
            trade.tradeDate(),
            trade.tradeTime(),
            trade.commission(),
            trade.sequenceNo(),
            trade.ownerType());
    /*string sql = "insert into trade values(trade.tradeID(),
                                           trade.tradingDay(),
                                           trade.investorID(),
                                           trade.exchangeID(),
                                           trade.direction(),
                                           trade.tradingCode(),
                                           trade.seatID(),
                                           trade.branchID(),
                                           trade.instrumentCode(),
                                           trade.instrumentID(),
                                           trade.userID(),
                                           trade.requestID(),
                                           trade.orderSysID(),
                                           trade.orderLocalID(),
                                           trade.orderRef(),
                                           trade.offsetFlag(),
                                           trade.coveredFlag(),
                                           trade.hedgeFlag(),
                                           trade.price(),
                                           trade.volume(),
                                           trade.tradeAmount(),
                                           trade.tradeDate(),
                                           trade.tradeTime(),
                                           trade.commission(),
                                           trade.sequenceNo(),
                                           trade.ownerType())";*/
    //cout << sql << endl;
    mysql->insert(sql);
}

void Decoder::decodeRiskRule()
{
    //m_buffer += m_offset;
    RiskRule_In riskRule(m_buffer, m_bufferLength);
    riskRule.wrapForDecode(m_buffer, 0, riskRule.sbeBlockLength(), riskRule.sbeSchemaVersion(), riskRule.encodedLength());
    //cout << "the size is: " << sizeof(riskRule) << endl;
    cout << "the size of Message is: " << riskRule.encodedLength() << endl;
    m_RiskRule += 1;
    m_buffer += riskRule.encodedLength();

    cout << "RiskRule.TradingDay = " << riskRule.tradingDay() << endl;
    cout << "RiskRule.RiskId = " << riskRule.riskId() << endl;
    cout << "RiskRule.RuleCode = " << riskRule.ruleCode() << endl;
    cout << "RiskRule.ExchangeID = " << riskRule.exchangeID() << endl;
    cout << "RiskRule.InstrumentIDs = " << riskRule.instrumentIDs() << endl;  
    cout << "RiskRule.InstrumentRange = " << riskRule.instrumentRange() << endl;
    cout << "RiskRule.InstrumentControlFlag = " << riskRule.instrumentControlFlag() << endl;
    cout << "RiskRule.InvestorIDs = " << riskRule.investorIDs() << endl;  
    cout << "RiskRule.InvestorRange = " << riskRule.investorRange() << endl; 
    cout << "RiskRule.InvestorControlFlag = " << riskRule.investorControlFlag() << endl;
    cout << "RiskRule.RuleName = " << riskRule.ruleName() << endl;
    cout << "RiskRule.IsActive = " << riskRule.isActive() << endl;
    cout << "RiskRule.Value = " << riskRule.value() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeRiskRuleLog()
{
    //m_buffer += m_offset;
    RiskRuleLog_In riskRuleLog(m_buffer, m_bufferLength);
    riskRuleLog.wrapForDecode(m_buffer, 0, riskRuleLog.sbeBlockLength(), riskRuleLog.sbeSchemaVersion(), riskRuleLog.encodedLength());
    //cout << "the size is: " << sizeof(riskRuleLog) << endl;
    cout << "the size of Message is: " << riskRuleLog.encodedLength() << endl;
    m_RiskRuleLog += 1;
    m_buffer += riskRuleLog.encodedLength();

    cout << "RiskRuleLog.TradingDay = " << riskRuleLog.tradingDay() << endl;
    cout << "RiskRuleLog.ExecuteTime = " << riskRuleLog.executeTime() << endl;
    cout << "RiskRuleLog.RiskId = " << riskRuleLog.riskId() << endl;
    cout << "RiskRuleLog.RuleCode = " << riskRuleLog.ruleCode() << endl;
    cout << "RiskRuleLog.RuleName = " << riskRuleLog.ruleName() << endl;
    cout << "RiskRuleLog.ExchangeID = " << riskRuleLog.exchangeID() << endl;
    cout << "RiskRuleLog.InstrumentIDs = " << riskRuleLog.instrumentIDs() << endl;  
    cout << "RiskRuleLog.InvestorID = " << riskRuleLog.investorID() << endl;  
    cout << "RiskRuleLog.OrderRef = " << riskRuleLog.orderRef() << endl; 
    cout << "RiskRuleLog.Threshold = " << riskRuleLog.threshold() << endl;
    cout << "RiskRuleLog.CalcValue = " << riskRuleLog.calcValue() << endl;
    cout << "RiskRuleLog.ErrorMsg = " << riskRuleLog.errorMsg() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeAdminCommand()
{
    //m_buffer += m_offset;
    AdminCommand_In adminCommand(m_buffer, m_bufferLength);
    adminCommand.wrapForDecode(m_buffer, 0, adminCommand.sbeBlockLength(), adminCommand.sbeSchemaVersion(), adminCommand.encodedLength());
    //cout << "the size is: " << sizeof(adminCommand) << endl;
    cout << "the size of Message is: " << adminCommand.encodedLength() << endl;
    m_AdminCommand += 1;
    m_buffer += adminCommand.encodedLength();

    cout << "AdminCommand.TradingDay = " << adminCommand.tradingDay() << endl;
    cout << "AdminCommand.AdminCode = " << adminCommand.adminCode() << endl;
    cout << "AdminCommand.Value = " << adminCommand.value() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

/*string GBKToUTF8(const std::string& strGBK)
{
	string strOutUTF8 = "";
	WCHAR * str1;
	int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char * str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;
}

bool MBToUTF8(vector<char>& pu8, const char* pmb, int32 mLen)
{
	// convert an MBCS string to widechar   
	int32 nLen = MultiByteToWideChar(CP_ACP, 0, pmb, mLen, NULL, 0);

	WCHAR* lpszW = NULL;
	try
	{
		lpszW = new WCHAR[nLen];
	}
	catch (bad_alloc &memExp)
	{
		return false;
	}

	int32 nRtn = MultiByteToWideChar(CP_ACP, 0, pmb, mLen, lpszW, nLen);

	if (nRtn != nLen)
	{
		delete[] lpszW;
		return false;
	}
	// convert an widechar string to utf8  
	int32 utf8Len = WideCharToMultiByte(CP_UTF8, 0, lpszW, nLen, NULL, 0, NULL, NULL);
	if (utf8Len <= 0)
	{
		return false;
	}
	pu8.resize(utf8Len);
	nRtn = WideCharToMultiByte(CP_UTF8, 0, lpszW, nLen, &*pu8.begin(), utf8Len, NULL, NULL);
	delete[] lpszW;

	if (nRtn != utf8Len)
	{
		pu8.clear();
		return false;
	}
	return true;
}*/

void Decoder::decodeRspInfo()
{
    //m_buffer += m_offset;
    RspInfo_In rspInfo(m_buffer, m_bufferLength);
    rspInfo.wrapForDecode(m_buffer, 0, rspInfo.sbeBlockLength(), rspInfo.sbeSchemaVersion(), rspInfo.encodedLength());
    //cout << "the size is: " << sizeof(rspInfo) << endl;
    cout << "the size of Message is: " << rspInfo.encodedLength() << endl;
    m_RspInfo += 1;
    m_buffer += rspInfo.encodedLength();

    cout << "RspInfo.ErrorID = " << rspInfo.errorID() << endl;
    cout << "RspInfo.IsLast = " << rspInfo.isLast() << endl;
    cout << "RspInfo.ErrorMsg = " << rspInfo.errorMsg() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 

    sprintf(sql, "insert into rspinfo values('%d', '%d', '%s', '%s')", 
            rspInfo.errorID(),
            rspInfo.isLast(),
            rspInfo.errorMsg(),
			m_TradingDay);
	//string sqlStr = sql;
	//vector<char> sqlInsert;
	//string sqlInsert2;
	//string sqlInsert = GBKToUTF8(sqlStr);
	//MBToUTF8(sqlInsert, sqlStr.c_str(), 1024);
	//sqlInsert2.insert(sqlInsert2.begin(), sqlInsert.begin(), sqlInsert.end());
	
	mysql->insert(sql);
}

void Decoder::decodeLoginReq()
{
    //m_buffer += m_offset;
    LoginReq_In loginReq(m_buffer, m_bufferLength);
    loginReq.wrapForDecode(m_buffer, 0, loginReq.sbeBlockLength(), loginReq.sbeSchemaVersion(), loginReq.encodedLength());
    //cout << "the size is: " << sizeof(loginReq) << endl;
    cout << "the size of Message is: " << loginReq.encodedLength() << endl;
    m_LoginReq += 1;
    m_buffer += loginReq.encodedLength();

    cout << "LoginReq.UserID = " << loginReq.userID() << endl;
    cout << "LoginReq.Password = " << loginReq.password() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeLogoutReq()
{
    //m_buffer += m_offset;
    LogoutReq_In logoutReq(m_buffer, m_bufferLength);
    logoutReq.wrapForDecode(m_buffer, 0, logoutReq.sbeBlockLength(), logoutReq.sbeSchemaVersion(), logoutReq.encodedLength());
    //cout << "the size is: " << sizeof(logoutReq) << endl;
    cout << "the size of Message is: " << logoutReq.encodedLength() << endl;
    m_LogoutReq += 1;
    m_buffer += logoutReq.encodedLength();

    cout << "LogoutReq.UserID = " << logoutReq.userID() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl;    
}

void Decoder::decodeRspLogin()
{
    //m_buffer += m_offset;
    RspLogin_In rspLogin(m_buffer, m_bufferLength);
    rspLogin.wrapForDecode(m_buffer, 0, rspLogin.sbeBlockLength(), rspLogin.sbeSchemaVersion(), rspLogin.encodedLength());
    //cout << "the size is: " << sizeof(rspLogin) << endl;
    cout << "the size of Message is: " << rspLogin.encodedLength() << endl;
    m_RspLogin += 1;
    m_buffer += rspLogin.encodedLength();

    cout << "RspLogin.TradingDay = " << rspLogin.tradingDay() << endl;
    cout << "RspLogin.LoginTime = " << rspLogin.loginTime() << endl;
    cout << "RspLogin.UserID = " << rspLogin.userID() << endl;
    cout << "RspLogin.FrontID = " << rspLogin.frontID() << endl;
    cout << "RspLogin.SessionID = " << rspLogin.sessionID() << endl;  
    cout << "RspLogin.MaxOrderRef = " << rspLogin.maxOrderRef() << endl;
    
    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeOrderReq()
{
    //m_buffer += m_offset;
	//m_OrderReq += 1;
    OrderReq_In orderReq(m_buffer, m_bufferLength);
    orderReq.wrapForDecode(m_buffer, 0, orderReq.sbeBlockLength(), orderReq.sbeSchemaVersion(), orderReq.encodedLength());
    //cout << "the size is: " << sizeof(orderReq) << endl;
    cout << "the size of Message is: " << orderReq.encodedLength() << endl;
    //m_OrderReq += 1;
    m_buffer += orderReq.encodedLength();

    cout << "OrderReq.InvestorID = " << orderReq.investorID() << endl;
    cout << "OrderReq.InstrumentID = " << orderReq.instrumentID() << endl;
    cout << "OrderReq.OrderRef = " << orderReq.orderRef() << endl;
    cout << "OrderReq.ExchangeID = " << orderReq.exchangeID() << endl;
    cout << "OrderReq.OrderPriceType = " << orderReq.orderPriceType() << endl;  
    cout << "OrderReq.Direction = " << orderReq.direction() << endl;
    cout << "OrderReq.CombOffsetFlag = " << orderReq.combOffsetFlag() << endl;
    cout << "OrderReq.CombHedgeFlag = " << orderReq.combHedgeFlag() << endl;  
    cout << "OrderReq.CoveredFlag = " << orderReq.coveredFlag() << endl; 
    cout << "OrderReq.LimitPrice = " << orderReq.limitPrice() << endl;
    cout << "OrderReq.VolumeTotalOriginal = " << orderReq.volumeTotalOriginal() << endl;
    cout << "OrderReq.TimeCondition = " << orderReq.timeCondition() << endl;
    cout << "OrderReq.VolumeCondition = " << orderReq.volumeCondition() << endl;
    cout << "OrderReq.MinVolume = " << orderReq.minVolume() << endl;  
    cout << "OrderReq.ContingentCondition = " << orderReq.contingentCondition() << endl; 
    cout << "OrderReq.StopPrice = " << orderReq.stopPrice() << endl;
    cout << "OrderReq.RequestID = " << orderReq.requestID() << endl;
    cout << "OrderReq.ThirdReff1 = " << orderReq.thirdReff1() << endl;
    cout << "OrderReq.ThirdReff2 = " << orderReq.thirdReff2() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 

    if (m_tID == 0x5000 + 7)
    {
		m_OrderReq += 1;
        sprintf(sql, "insert into orderreq values('%s', '%s', '%s', '%s', '%c', '%c', '%s', '%s', '%c', '%f', '%d', '%c', '%c', '%d', '%c', '%f', '%d', '%s', '%s', '%d', '%d', '%d', '%d', '%s')",
                orderReq.investorID(), 
                orderReq.instrumentID(),
                orderReq.orderRef(),
                orderReq.exchangeID(),
                orderReq.orderPriceType(),
                orderReq.direction(),
                orderReq.combOffsetFlag(),
                orderReq.combHedgeFlag(),
                orderReq.coveredFlag(),
                orderReq.limitPrice(),
                orderReq.volumeTotalOriginal(),
                orderReq.timeCondition(),
                orderReq.volumeCondition(),
                orderReq.minVolume(),
                orderReq.contingentCondition(),
                orderReq.stopPrice(),
                orderReq.requestID(),
                orderReq.thirdReff1(),
                orderReq.thirdReff2(),
                m_frontID,
                m_sessionID,
                m_time,
                m_OrderReq + m_OrderCancelReq,
				m_TradingDay);
        mysql->insert(sql);
    } //update
}

void Decoder::decodeOrderCancelReq()
{
    //m_buffer += m_offset;
    OrderCancelReq_In orderCancelReq(m_buffer, m_bufferLength);
    orderCancelReq.wrapForDecode(m_buffer, 0, orderCancelReq.sbeBlockLength(), orderCancelReq.sbeSchemaVersion(), orderCancelReq.encodedLength());
    //cout << "the size is: " << sizeof(orderCancelReq) << endl;
    cout << "the size of Message is: " << orderCancelReq.encodedLength() << endl;

	m_buffer += orderCancelReq.encodedLength();

	cout << "OrderCancelReq.InvestorID = " << orderCancelReq.investorID() << endl;
	cout << "OrderCancelReq.InstrumentID = " << orderCancelReq.instrumentID() << endl;
	cout << "OrderCancelReq.OrderActionRef = " << orderCancelReq.orderActionRef() << endl;
	cout << "OrderCancelReq.OrderRef = " << orderCancelReq.orderRef() << endl;
	cout << "OrderCancelReq.FrontID = " << orderCancelReq.frontID() << endl;
	cout << "OrderCancelReq.SessionID = " << orderCancelReq.sessionID() << endl;
	cout << "OrderCancelReq.ExchangeID = " << orderCancelReq.exchangeID() << endl;
	cout << "OrderCancelReq.OrderSysID = " << orderCancelReq.orderSysID() << endl;
	cout << "OrderCancelReq.OrderLocalID = " << orderCancelReq.orderLocalID() << endl;

	m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
	cout << "buffer now at: " << m_position << endl;
	cout << endl;

	if (m_tID == 0x5000 + 9){
		m_OrderCancelReq += 1;

		sprintf(sql, "insert into ordercancelreq values('%s', '%s', '%s', '%s', '%d', '%d', '%s', '%s', '%s', '%d', '%s')",
			orderCancelReq.investorID(),
			orderCancelReq.instrumentID(),
			orderCancelReq.orderActionRef(),
			orderCancelReq.orderRef(),
			orderCancelReq.frontID(),
			orderCancelReq.sessionID(),
			orderCancelReq.exchangeID(),
			orderCancelReq.orderSysID(),
			orderCancelReq.orderLocalID(),
			m_OrderReq + m_OrderCancelReq,
			m_TradingDay);
		mysql->insert(sql);
	}
	/*else
	{
		sprintf(sql, "insert into ordercancelreq values('%s', '%s', '%s', '%s', '%d', '%d', '%s', '%s', '%s', '%d', '%s')",
			orderCancelReq.investorID(),
			orderCancelReq.instrumentID(),
			orderCancelReq.orderActionRef(),
			orderCancelReq.orderRef(),
			orderCancelReq.frontID(),
			orderCancelReq.sessionID(),
			orderCancelReq.exchangeID(),
			orderCancelReq.orderSysID(),
			orderCancelReq.orderLocalID(),
			0,//debug
			m_TradingDay);
		mysql->insert(sql);
	}*/ //modified
}

void Decoder::decodeQryRiskRule()
{
    //m_buffer += m_offset;
    QryRiskRule_In qryRiskRule(m_buffer, m_bufferLength);
    qryRiskRule.wrapForDecode(m_buffer, 0, qryRiskRule.sbeBlockLength(), qryRiskRule.sbeSchemaVersion(), qryRiskRule.encodedLength());
    //cout << "the size is: " << sizeof(qryRiskRule) << endl;
    cout << "the size of Message is: " << qryRiskRule.encodedLength() << endl;
    m_QryRiskRule += 1;
    m_buffer += qryRiskRule.encodedLength();

    cout << "QryRiskRule.RiskID = " << qryRiskRule.riskId() << endl;
    cout << "QryRiskRule.RuleCode = " << qryRiskRule.ruleCode() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeQryInstrument()
{
    //m_buffer += m_offset;
    QryInstrument_In qryInstrument(m_buffer, m_bufferLength);
    qryInstrument.wrapForDecode(m_buffer, 0, qryInstrument.sbeBlockLength(), qryInstrument.sbeSchemaVersion(), qryInstrument.encodedLength());
    //cout << "the size is: " << sizeof(qryInstrument) << endl;
    cout << "the size of Message is: " << qryInstrument.encodedLength() << endl;
    m_QryInstrument += 1;
    m_buffer += qryInstrument.encodedLength();

    cout << "QryInstrument.ExchangeID = " << qryInstrument.exchangeID() << endl;
    cout << "QryInstrument.InstrumentID = " << qryInstrument.instrumentID() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeQryCommissionRate()
{
    //m_buffer += m_offset;
    QryCommissionRate_In qryCommissionRate(m_buffer, m_bufferLength);
    qryCommissionRate.wrapForDecode(m_buffer, 0, qryCommissionRate.sbeBlockLength(), qryCommissionRate.sbeSchemaVersion(), qryCommissionRate.encodedLength());
    //cout << "the size is: " << sizeof(qryCommissionRate) << endl;
    cout << "the size of Message is: " << qryCommissionRate.encodedLength() << endl;
    m_QryCommissionRate += 1;
    m_buffer += qryCommissionRate.encodedLength();

    cout << "QryCommissionRate.InvestorID = " << qryCommissionRate.investorID() << endl;
    cout << "QryCommissionRate.ExchangeID = " << qryCommissionRate.exchangeID() << endl;
    cout << "QryCommissionRate.InstrumentID = " << qryCommissionRate.instrumentID() << endl; 
    cout << "QryCommissionRate.Direction = " << qryCommissionRate.direction() << endl; 
    cout << "QryCommissionRate.OffsetFlag = " << qryCommissionRate.offsetFlag() << endl;  
    cout << "QryCommissionRate.CoveredFlag = " << qryCommissionRate.coveredFlag() << endl; 
    cout << "QryCommissionRate.HedgeFlag = " << qryCommissionRate.hedgeFlag() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeQryMarginRate()
{
    //m_buffer += m_offset;
    QryMarginRate_In qryMarginRate(m_buffer, m_bufferLength);
    qryMarginRate.wrapForDecode(m_buffer, 0, qryMarginRate.sbeBlockLength(), qryMarginRate.sbeSchemaVersion(), qryMarginRate.encodedLength());
    //cout << "the size is: " << sizeof(qryMarginRate) << endl;
    cout << "the size of Message is: " << qryMarginRate.encodedLength() << endl;
    m_QryMarginRate += 1;
    m_buffer += qryMarginRate.encodedLength();

    cout << "QryMarginRate.InvestorID = " << qryMarginRate.investorID() << endl;
    cout << "QryMarginRate.ExchangeID = " << qryMarginRate.exchangeID() << endl;
    cout << "QryMarginRate.InstrumentID = " << qryMarginRate.instrumentID() << endl; 
    cout << "QryMarginRate.Direction = " << qryMarginRate.direction() << endl; 
    cout << "QryMarginRate.OffsetFlag = " << qryMarginRate.offsetFlag() << endl;  
    cout << "QryMarginRate.CoveredFlag = " << qryMarginRate.coveredFlag() << endl; 
    cout << "QryMarginRate.HedgeFlag = " << qryMarginRate.hedgeFlag() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeQryOrder()
{
    //m_buffer += m_offset;
    QryOrder_In qryOrder(m_buffer, m_bufferLength);
    qryOrder.wrapForDecode(m_buffer, 0, qryOrder.sbeBlockLength(), qryOrder.sbeSchemaVersion(), qryOrder.encodedLength());
    //cout << "the size is: " << sizeof(qryOrder) << endl;
    cout << "the size of Message is: " << qryOrder.encodedLength() << endl;
    m_QryOrder += 1;
    m_buffer += qryOrder.encodedLength();

    cout << "QryOrder.InvestorID = " << qryOrder.investorID() << endl;
    cout << "QryOrder.ExchangeID = " << qryOrder.exchangeID() << endl;
    cout << "QryOrder.InstrumentID = " << qryOrder.instrumentID() << endl; 
    cout << "QryOrder.OrderSysID = " << qryOrder.orderSysID() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeQryTrade()
{
    //m_buffer += m_offset;
    QryTrade_In qryTrade(m_buffer, m_bufferLength);
    qryTrade.wrapForDecode(m_buffer, 0, qryTrade.sbeBlockLength(), qryTrade.sbeSchemaVersion(), qryTrade.encodedLength());
    //cout << "the size is: " << sizeof(qryTrade) << endl;
    cout << "the size of Message is: " << qryTrade.encodedLength() << endl;
    m_QryTrade += 1;
    m_buffer += qryTrade.encodedLength();

    cout << "QryTrade.InvestorID = " << qryTrade.investorID() << endl;
    cout << "QryTrade.ExchangeID = " << qryTrade.exchangeID() << endl;
    cout << "QryTrade.InstrumentID = " << qryTrade.instrumentID() << endl; 
    cout << "QryTrade.TradeID = " << qryTrade.tradeID() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeQryAccount()
{
    //m_buffer += m_offset;
    QryAccount_In qryAccount(m_buffer, m_bufferLength);
    qryAccount.wrapForDecode(m_buffer, 0, qryAccount.sbeBlockLength(), qryAccount.sbeSchemaVersion(), qryAccount.encodedLength());
    //cout << "the size is: " << sizeof(qryAccount) << endl;
    cout << "the size of Message is: " << qryAccount.encodedLength() << endl;
    m_QryAccount += 1;
    m_buffer += qryAccount.encodedLength();

    cout << "QryAccount.InvestorID = " << qryAccount.investorID() << endl;

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeQryPosition()
{
    //m_buffer += m_offset;
    QryPosition_In qryPosition(m_buffer, m_bufferLength);
    qryPosition.wrapForDecode(m_buffer, 0, qryPosition.sbeBlockLength(), qryPosition.sbeSchemaVersion(), qryPosition.encodedLength());
    //cout << "the size is: " << sizeof(qryPosition) << endl;
    cout << "the size of Message is: " << qryPosition.encodedLength() << endl;
    m_QryPosition += 1;
    m_buffer += qryPosition.encodedLength();

    cout << "QryPosition.InvestorID = " << qryPosition.investorID() << endl;
    cout << "QryPosition.ExchangeID = " << qryPosition.exchangeID() << endl;
    cout << "QryPosition.InstrumentID = " << qryPosition.instrumentID() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeSeatGatewayAssign()
{
    //m_buffer += m_offset;
    SeatGatewayAssign_In seatGatewayAssign(m_buffer, m_bufferLength);
    seatGatewayAssign.wrapForDecode(m_buffer, 0, seatGatewayAssign.sbeBlockLength(), seatGatewayAssign.sbeSchemaVersion(), seatGatewayAssign.encodedLength());
    //cout << "the size is: " << sizeof(seatGatewayAssign) << endl;
    cout << "the size of Message is: " << seatGatewayAssign.encodedLength() << endl;
    m_SeatGatewayAssign += 1;
    m_buffer += seatGatewayAssign.encodedLength();

    cout << "SeatGatewayAssign.TradingDay = " << seatGatewayAssign.tradingDay() << endl;
    cout << "SeatGatewayAssign.SeatID = " << seatGatewayAssign.seatID() << endl;
    cout << "SeatGatewayAssign.SeatType = " << seatGatewayAssign.seatType() << endl; 
    cout << "SeatGatewayAssign.GatewayID = " << seatGatewayAssign.gatewayID() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decodeGatewayConfig()
{
    //m_buffer += m_offset;
    GatewayConfig_In gatewayConfig(m_buffer, m_bufferLength);
    gatewayConfig.wrapForDecode(m_buffer, 0, gatewayConfig.sbeBlockLength(), gatewayConfig.sbeSchemaVersion(), gatewayConfig.encodedLength());
    //cout << "the size is: " << sizeof(gatewayConfig) << endl;
    cout << "the size of Message is: " << gatewayConfig.encodedLength() << endl;
    m_GatewayConfig += 1;
    m_buffer += gatewayConfig.encodedLength();

    cout << "GatewayConfig.TradingDay = " << gatewayConfig.tradingDay() << endl;
    cout << "GatewayConfig.GatewayID = " << gatewayConfig.gatewayID() << endl;
    cout << "GatewayConfig.FrontAddress = " << gatewayConfig.frontAddress() << endl; 
    cout << "GatewayConfig.ResumeType = " << gatewayConfig.resumeType() << endl; 
    cout << "GatewayConfig.FlowPath = " << gatewayConfig.flowPath() << endl;  
    cout << "GatewayConfig.IsDefault = " << gatewayConfig.isDefault() << endl; 

    m_position = int(static_cast<void *>(m_buffer)) - int(m_origin);
    cout << "buffer now at: " << m_position << endl;
    cout << endl; 
}

void Decoder::decode()
{
    mysql = new MySQLManager("192.168.41.65", "admin", "admin1309", "das", 3306);
    mysql->initConnection();
    if (mysql->getConnectionStatus())
    {
        cout << "Connect successfully." << endl;
    }
    else
    {
        cout << "Failed to connect." << endl;
    }

	//m_buffer += m_offset/2;
    while(m_position < m_bufferLength - 1)
    {
        decodePackageHeader();
        //decodeFieldHeader();

        if (m_tID == 0x5000 + 1)
        {
            decodeFieldHeader();
            decodeLoginReq();
        }
        else if (m_tID == 0x5000 + 2)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 18)
                {
                    decodeRspLogin();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 5)
        {
            decodeFieldHeader();
            decodeLogoutReq();
        }
        else if (m_tID == 0x5000 + 6 || m_tID == 0x5000 + 18)
        {
            decodeFieldHeader();
            decodeRspInfo();
        }
        else if (m_tID == 0x5000 + 7)
        {
            decodeFieldHeader();
            decodeOrderReq();
        }
        else if (m_tID == 0x5000 + 8)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 10)//modified
                {
                    decodeOrder();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 9)
        {
            decodeFieldHeader();
            decodeOrderCancelReq();
        }
        else if (m_tID == 0x5000 + 11)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 10)//modified
                {
                    decodeOrder();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 13)
        {
            decodeFieldHeader();
            decodeOrder();
        }
        else if (m_tID == 0x5000 + 14)
        {
            decodeFieldHeader();
            decodeTrade();
        }
        else if (m_tID == 0x5000 + 15)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 10)//modified
                {
                    decodeOrder();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 16)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 10)//modified
                {
                    decodeOrder();
                    //decodeOrder();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 33)
        {
            decodeFieldHeader();
            decodeQryOrder();
        }
        else if (m_tID == 0x5000 + 34)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 10)
                {
                    decodeOrder();
                } 
                else if(m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 35)
        {
            decodeFieldHeader();
            decodeQryTrade();
        }
        else if (m_tID == 0x5000 + 36)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 11)
                {
                    decodeTrade();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 37)
        {
            decodeFieldHeader();
            decodeQryInstrument();
        }
        else if (m_tID == 0x5000 + 38)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 2)
                {
                    decodeInstrument();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 39)
        {
            decodeFieldHeader();
            decodeQryCommissionRate();
        }
        else if (m_tID == 0x5000 + 40)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 8)
                {
                    decodeCommissionRate();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 41)
        {
            decodeFieldHeader();
            decodeQryMarginRate();
        }
        else if (m_tID == 0x5000 + 42)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 9)
                {
                    decodeMarginRate();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 43)
        {
            decodeFieldHeader();
            decodeQryAccount();
        }
        else if (m_tID == 0x5000 + 44)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 5)
                {
                    decodeAccount();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 45)
        {
            decodeFieldHeader();
            decodeQryPosition();
        }
        else if (m_tID == 0x5000 + 46)
        {
            decodeFieldHeader();
            //decodePosition();
            decodeRspInfo();
        }

        else if (m_tID == 0x5000 + 65)
        {
            decodeFieldHeader();
            decodeRiskRule();
        }
        else if (m_tID == 0x5000 + 66)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 12)
                {
                    decodeRiskRule();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else if (m_tID == 0x5000 + 69)
        {
            decodeFieldHeader();
            decodeAdminCommand();
        }
        else if (m_tID == 0x5000 + 70)
        {
            for(int i = 0; i < m_fieldCount; i ++)
            {
                decodeFieldHeader();
                if (m_fID == 0x2000 + 14)
                {
                    decodeAdminCommand();
                } 
                else if (m_fID == 0x2000 + 15)
                {
                    decodeRspInfo();
                }
                //m_buffer -= m_offset;
            }
        }
        else
        {
            cout << "the tID is: " << m_tID << endl;
			for (int i = 0; i < m_fieldCount; i++)
			{
				decodeFieldHeader();
				m_buffer += m_fLength;
				//m_buffer -= m_offset;
			}

			//break;
        }
    }

    cout << "************Amount of Message************" << endl;
    cout << "PackageHeader: " << m_PackageHeader << endl;
    cout << "FieldHeader: " << m_FieldHeader << endl;
    cout << "TradeDate: " << m_TradeDate << endl;
    cout << "Instrument: " << m_Instrument << endl;
    cout << "Investor: " << m_Investor << endl;
    cout << "TradingCode: " << m_TradingCode << endl;
    cout << "Account: " << m_Account << endl;
    cout << "InvestorPosition: " << m_InvestorPosition << endl;
    cout << "InvestorPositionDtl: " << m_InvestorPositionDtl << endl;
    cout << "CommissionRate: " << m_CommissionRate << endl;
    cout << "MarginRate: " << m_MarginRate << endl;
    cout << "Order: " << m_Order << endl;
    cout << "Trade: " << m_Trade << endl;
    cout << "RiskRule: " << m_RiskRule << endl;
    cout << "RiskRuleLog: " << m_RiskRuleLog << endl;
    cout << "AdminCommand: " << m_AdminCommand << endl;
    cout << "RspInfo: " << m_RspInfo << endl;
    cout << "LoginReq: " << m_LoginReq << endl;
    cout << "LogoutReq: " << m_LogoutReq << endl;
    cout << "RspLogin: " << m_RspLogin << endl;
	cout << "OrderReq: " << m_OrderReq << endl;
    cout << "OrderCancelReq: " << m_OrderCancelReq << endl;
    cout << "QryRiskRule: " << m_QryRiskRule << endl;
    cout << "QryInstrument: " << m_QryInstrument << endl;
    cout << "QryCommissionRate: " << m_QryCommissionRate << endl;
    cout << "QryMarginRate: " << m_QryMarginRate << endl;
    cout << "QryOrder: " << m_QryOrder << endl;
    cout << "QryTrade: " << m_QryTrade << endl;
    cout << "QryAccount: " << m_QryAccount << endl;
    cout << "QryPosition: " << m_QryPosition << endl;
    cout << "SeatGatewayAssign: " << m_SeatGatewayAssign << endl;
    cout << "GatewayConfig: " << m_GatewayConfig << endl;
}