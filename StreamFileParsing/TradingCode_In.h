/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_TRADINGCODE_IN_H_
#define _TFZQ_STP_TRADEOPT_TRADINGCODE_IN_H_

#if defined(SBE_HAVE_CMATH)
/* cmath needed for std::numeric_limits<double>::quiet_NaN() */
#  include <cmath>
#  define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#  define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#else
/* math.h needed for NAN */
#  include <math.h>
#  define SBE_FLOAT_NAN NAN
#  define SBE_DOUBLE_NAN NAN
#endif

#if __cplusplus >= 201103L
#  include <cstdint>
#  include <string>
#  include <cstring>
#endif

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#else
#  define SBE_CONSTEXPR
#endif

#include <sbe/sbe.h>


using namespace sbe;

namespace tfzq {
namespace stp {
namespace tradeopt {

class TradingCode_In
{
private:
    char *m_buffer;
    std::uint64_t m_bufferLength;
    std::uint64_t *m_positionPtr;
    std::uint64_t m_offset;
    std::uint64_t m_position;
    std::uint64_t m_actingBlockLength;
    std::uint64_t m_actingVersion;

    inline void reset(
        char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        m_buffer = buffer;
        m_offset = offset;
        m_bufferLength = bufferLength;
        m_actingBlockLength = actingBlockLength;
        m_actingVersion = actingVersion;
        m_positionPtr = &m_position;
        position(offset + m_actingBlockLength);
    }

public:

    TradingCode_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    TradingCode_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    TradingCode_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)78;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)4;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeSchemaId(void)
    {
        return (std::uint16_t)1;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeSchemaVersion(void)
    {
        return (std::uint16_t)1;
    }

    static SBE_CONSTEXPR const char * sbeSemanticType(void)
    {
        return "";
    }

    std::uint64_t offset(void) const
    {
        return m_offset;
    }

    TradingCode_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    TradingCode_In &wrapForDecode(
         char *buffer, const std::uint64_t offset, const std::uint64_t actingBlockLength,
         const std::uint64_t actingVersion, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, actingBlockLength, actingVersion);
        return *this;
    }

    std::uint64_t position(void) const
    {
        return m_position;
    }

    void position(const std::uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        m_position = position;
    }

    std::uint64_t encodedLength(void) const
    {
        return position() - m_offset;
    }

    char *buffer(void)
    {
        return m_buffer;
    }

    std::uint64_t actingVersion(void) const
    {
        return m_actingVersion;
    }

    static SBE_CONSTEXPR const std::uint16_t tradingDayId(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t tradingDaySinceVersion(void)
    {
         return 0;
    }

    bool tradingDayInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradingDaySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradingDayEncodingOffset(void)
    {
         return 0;
    }


    static const char *TradingDayMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char tradingDayNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char tradingDayMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char tradingDayMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t tradingDayEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t tradingDayLength(void)
    {
        return 9;
    }

    const char *tradingDay(void) const
    {
        return (m_buffer + m_offset + 0);
    }

    char tradingDay(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for tradingDay [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 0 + (index * 1))));
    }

    void tradingDay(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for tradingDay [E105]");
        }

        *((char *)(m_buffer + m_offset + 0 + (index * 1))) = (value);
    }

    std::uint64_t getTradingDay(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getTradingDay [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 0, length);
        return length;
    }

    TradingCode_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    TradingCode_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t investorIDId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t investorIDSinceVersion(void)
    {
         return 0;
    }

    bool investorIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= investorIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t investorIDEncodingOffset(void)
    {
         return 9;
    }


    static const char *InvestorIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char investorIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char investorIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char investorIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t investorIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t investorIDLength(void)
    {
        return 15;
    }

    const char *investorID(void) const
    {
        return (m_buffer + m_offset + 9);
    }

    char investorID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 9 + (index * 1))));
    }

    void investorID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E105]");
        }

        *((char *)(m_buffer + m_offset + 9 + (index * 1))) = (value);
    }

    std::uint64_t getInvestorID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getInvestorID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 9, length);
        return length;
    }

    TradingCode_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 15);
        return result;
    }

    TradingCode_In &putInvestorID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 9, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t exchangeIDId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t exchangeIDSinceVersion(void)
    {
         return 0;
    }

    bool exchangeIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= exchangeIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t exchangeIDEncodingOffset(void)
    {
         return 24;
    }


    static const char *ExchangeIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char exchangeIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char exchangeIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char exchangeIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t exchangeIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t exchangeIDLength(void)
    {
        return 9;
    }

    const char *exchangeID(void) const
    {
        return (m_buffer + m_offset + 24);
    }

    char exchangeID(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 24 + (index * 1))));
    }

    void exchangeID(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 24 + (index * 1))) = (value);
    }

    std::uint64_t getExchangeID(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getExchangeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 24, length);
        return length;
    }

    TradingCode_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 24, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 24, 9);
        return result;
    }

    TradingCode_In &putExchangeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 24, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t tradingCodeTypeId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t tradingCodeTypeSinceVersion(void)
    {
         return 0;
    }

    bool tradingCodeTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradingCodeTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradingCodeTypeEncodingOffset(void)
    {
         return 33;
    }


    static const char *TradingCodeTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char tradingCodeTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char tradingCodeTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char tradingCodeTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t tradingCodeTypeEncodingLength(void)
    {
        return 1;
    }

    char tradingCodeType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 33)));
    }

    TradingCode_In &tradingCodeType(const char value)
    {
        *((char *)(m_buffer + m_offset + 33)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t tradeCodeId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t tradeCodeSinceVersion(void)
    {
         return 0;
    }

    bool tradeCodeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradeCodeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradeCodeEncodingOffset(void)
    {
         return 34;
    }


    static const char *TradeCodeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char tradeCodeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char tradeCodeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char tradeCodeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t tradeCodeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t tradeCodeLength(void)
    {
        return 15;
    }

    const char *tradeCode(void) const
    {
        return (m_buffer + m_offset + 34);
    }

    char tradeCode(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradeCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 34 + (index * 1))));
    }

    void tradeCode(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradeCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 34 + (index * 1))) = (value);
    }

    std::uint64_t getTradeCode(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getTradeCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 34, length);
        return length;
    }

    TradingCode_In &putTradeCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 34, src, 15);
        return *this;
    }

    std::string getTradeCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 34, 15);
        return result;
    }

    TradingCode_In &putTradeCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 34, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t branchIDId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t branchIDSinceVersion(void)
    {
         return 0;
    }

    bool branchIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= branchIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t branchIDEncodingOffset(void)
    {
         return 49;
    }


    static const char *BranchIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char branchIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char branchIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char branchIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t branchIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t branchIDLength(void)
    {
        return 6;
    }

    const char *branchID(void) const
    {
        return (m_buffer + m_offset + 49);
    }

    char branchID(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for branchID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 49 + (index * 1))));
    }

    void branchID(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for branchID [E105]");
        }

        *((char *)(m_buffer + m_offset + 49 + (index * 1))) = (value);
    }

    std::uint64_t getBranchID(char *dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
             throw std::runtime_error("length too large for getBranchID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 49, length);
        return length;
    }

    TradingCode_In &putBranchID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 49, src, 6);
        return *this;
    }

    std::string getBranchIDAsString() const
    {
        std::string result(m_buffer + m_offset + 49, 6);
        return result;
    }

    TradingCode_In &putBranchID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 49, str.c_str(), 6);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t seatIDId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t seatIDSinceVersion(void)
    {
         return 0;
    }

    bool seatIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= seatIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t seatIDEncodingOffset(void)
    {
         return 55;
    }


    static const char *SeatIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char seatIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char seatIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char seatIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t seatIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t seatIDLength(void)
    {
        return 11;
    }

    const char *seatID(void) const
    {
        return (m_buffer + m_offset + 55);
    }

    char seatID(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for seatID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 55 + (index * 1))));
    }

    void seatID(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for seatID [E105]");
        }

        *((char *)(m_buffer + m_offset + 55 + (index * 1))) = (value);
    }

    std::uint64_t getSeatID(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getSeatID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 55, length);
        return length;
    }

    TradingCode_In &putSeatID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 55, src, 11);
        return *this;
    }

    std::string getSeatIDAsString() const
    {
        std::string result(m_buffer + m_offset + 55, 11);
        return result;
    }

    TradingCode_In &putSeatID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 55, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t optClientIDId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t optClientIDSinceVersion(void)
    {
         return 0;
    }

    bool optClientIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= optClientIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t optClientIDEncodingOffset(void)
    {
         return 66;
    }


    static const char *OptClientIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char optClientIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char optClientIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char optClientIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t optClientIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t optClientIDLength(void)
    {
        return 11;
    }

    const char *optClientID(void) const
    {
        return (m_buffer + m_offset + 66);
    }

    char optClientID(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for optClientID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 66 + (index * 1))));
    }

    void optClientID(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for optClientID [E105]");
        }

        *((char *)(m_buffer + m_offset + 66 + (index * 1))) = (value);
    }

    std::uint64_t getOptClientID(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getOptClientID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 66, length);
        return length;
    }

    TradingCode_In &putOptClientID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 66, src, 11);
        return *this;
    }

    std::string getOptClientIDAsString() const
    {
        std::string result(m_buffer + m_offset + 66, 11);
        return result;
    }

    TradingCode_In &putOptClientID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 66, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t isActiveId(void)
    {
        return 9;
    }

    static SBE_CONSTEXPR const std::uint64_t isActiveSinceVersion(void)
    {
         return 0;
    }

    bool isActiveInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= isActiveSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t isActiveEncodingOffset(void)
    {
         return 77;
    }


    static const char *IsActiveMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t isActiveNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t isActiveMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t isActiveMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t isActiveEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t isActive(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 77)));
    }

    TradingCode_In &isActive(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 77)) = (value);
        return *this;
    }
};
}
}
}
#endif
