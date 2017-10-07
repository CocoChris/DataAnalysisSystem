/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_INVESTORPOSITIONDTL_IN_H_
#define _TFZQ_STP_TRADEOPT_INVESTORPOSITIONDTL_IN_H_

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

class InvestorPositionDtl_In
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

    InvestorPositionDtl_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    InvestorPositionDtl_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    InvestorPositionDtl_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)171;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)7;
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

    InvestorPositionDtl_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    InvestorPositionDtl_In &wrapForDecode(
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

    static SBE_CONSTEXPR const std::uint16_t investorIDId(void)
    {
        return 1;
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
         return 0;
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
        return (m_buffer + m_offset + 0);
    }

    char investorID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 0 + (index * 1))));
    }

    void investorID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E105]");
        }

        *((char *)(m_buffer + m_offset + 0 + (index * 1))) = (value);
    }

    std::uint64_t getInvestorID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getInvestorID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 0, length);
        return length;
    }

    InvestorPositionDtl_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 15);
        return result;
    }

    InvestorPositionDtl_In &putInvestorID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t exchangeIDId(void)
    {
        return 2;
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
         return 15;
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
        return (m_buffer + m_offset + 15);
    }

    char exchangeID(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 15 + (index * 1))));
    }

    void exchangeID(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 15 + (index * 1))) = (value);
    }

    std::uint64_t getExchangeID(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getExchangeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 15, length);
        return length;
    }

    InvestorPositionDtl_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 15, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 15, 9);
        return result;
    }

    InvestorPositionDtl_In &putExchangeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 15, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t instrumentIDId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t instrumentIDSinceVersion(void)
    {
         return 0;
    }

    bool instrumentIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= instrumentIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t instrumentIDEncodingOffset(void)
    {
         return 24;
    }


    static const char *InstrumentIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char instrumentIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char instrumentIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char instrumentIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t instrumentIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t instrumentIDLength(void)
    {
        return 31;
    }

    const char *instrumentID(void) const
    {
        return (m_buffer + m_offset + 24);
    }

    char instrumentID(const std::uint64_t index) const
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 24 + (index * 1))));
    }

    void instrumentID(const std::uint64_t index, const char value)
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E105]");
        }

        *((char *)(m_buffer + m_offset + 24 + (index * 1))) = (value);
    }

    std::uint64_t getInstrumentID(char *dst, const std::uint64_t length) const
    {
        if (length > 31)
        {
             throw std::runtime_error("length too large for getInstrumentID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 24, length);
        return length;
    }

    InvestorPositionDtl_In &putInstrumentID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 24, src, 31);
        return *this;
    }

    std::string getInstrumentIDAsString() const
    {
        std::string result(m_buffer + m_offset + 24, 31);
        return result;
    }

    InvestorPositionDtl_In &putInstrumentID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 24, str.c_str(), 31);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t coveredFlagId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t coveredFlagSinceVersion(void)
    {
         return 0;
    }

    bool coveredFlagInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= coveredFlagSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t coveredFlagEncodingOffset(void)
    {
         return 55;
    }


    static const char *CoveredFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char coveredFlagNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char coveredFlagMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char coveredFlagMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t coveredFlagEncodingLength(void)
    {
        return 1;
    }

    char coveredFlag(void) const
    {
        return (*((char *)(m_buffer + m_offset + 55)));
    }

    InvestorPositionDtl_In &coveredFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 55)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t posiDirectionId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t posiDirectionSinceVersion(void)
    {
         return 0;
    }

    bool posiDirectionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= posiDirectionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t posiDirectionEncodingOffset(void)
    {
         return 56;
    }


    static const char *PosiDirectionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char posiDirectionNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char posiDirectionMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char posiDirectionMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t posiDirectionEncodingLength(void)
    {
        return 1;
    }

    char posiDirection(void) const
    {
        return (*((char *)(m_buffer + m_offset + 56)));
    }

    InvestorPositionDtl_In &posiDirection(const char value)
    {
        *((char *)(m_buffer + m_offset + 56)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t openDateId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t openDateSinceVersion(void)
    {
         return 0;
    }

    bool openDateInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= openDateSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t openDateEncodingOffset(void)
    {
         return 57;
    }


    static const char *OpenDateMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char openDateNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char openDateMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char openDateMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t openDateEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t openDateLength(void)
    {
        return 9;
    }

    const char *openDate(void) const
    {
        return (m_buffer + m_offset + 57);
    }

    char openDate(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for openDate [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 57 + (index * 1))));
    }

    void openDate(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for openDate [E105]");
        }

        *((char *)(m_buffer + m_offset + 57 + (index * 1))) = (value);
    }

    std::uint64_t getOpenDate(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getOpenDate [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 57, length);
        return length;
    }

    InvestorPositionDtl_In &putOpenDate(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 57, src, 9);
        return *this;
    }

    std::string getOpenDateAsString() const
    {
        std::string result(m_buffer + m_offset + 57, 9);
        return result;
    }

    InvestorPositionDtl_In &putOpenDate(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 57, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t tradeIDId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t tradeIDSinceVersion(void)
    {
         return 0;
    }

    bool tradeIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradeIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradeIDEncodingOffset(void)
    {
         return 66;
    }


    static const char *TradeIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char tradeIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char tradeIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char tradeIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t tradeIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t tradeIDLength(void)
    {
        return 21;
    }

    const char *tradeID(void) const
    {
        return (m_buffer + m_offset + 66);
    }

    char tradeID(const std::uint64_t index) const
    {
        if (index >= 21)
        {
            throw std::runtime_error("index out of range for tradeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 66 + (index * 1))));
    }

    void tradeID(const std::uint64_t index, const char value)
    {
        if (index >= 21)
        {
            throw std::runtime_error("index out of range for tradeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 66 + (index * 1))) = (value);
    }

    std::uint64_t getTradeID(char *dst, const std::uint64_t length) const
    {
        if (length > 21)
        {
             throw std::runtime_error("length too large for getTradeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 66, length);
        return length;
    }

    InvestorPositionDtl_In &putTradeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 66, src, 21);
        return *this;
    }

    std::string getTradeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 66, 21);
        return result;
    }

    InvestorPositionDtl_In &putTradeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 66, str.c_str(), 21);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t tradingCodeId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t tradingCodeSinceVersion(void)
    {
         return 0;
    }

    bool tradingCodeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradingCodeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradingCodeEncodingOffset(void)
    {
         return 87;
    }


    static const char *TradingCodeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char tradingCodeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char tradingCodeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char tradingCodeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t tradingCodeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t tradingCodeLength(void)
    {
        return 15;
    }

    const char *tradingCode(void) const
    {
        return (m_buffer + m_offset + 87);
    }

    char tradingCode(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradingCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 87 + (index * 1))));
    }

    void tradingCode(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradingCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 87 + (index * 1))) = (value);
    }

    std::uint64_t getTradingCode(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getTradingCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 87, length);
        return length;
    }

    InvestorPositionDtl_In &putTradingCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 87, src, 15);
        return *this;
    }

    std::string getTradingCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 87, 15);
        return result;
    }

    InvestorPositionDtl_In &putTradingCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 87, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t tradingDayId(void)
    {
        return 9;
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
         return 102;
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
        return (m_buffer + m_offset + 102);
    }

    char tradingDay(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for tradingDay [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 102 + (index * 1))));
    }

    void tradingDay(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for tradingDay [E105]");
        }

        *((char *)(m_buffer + m_offset + 102 + (index * 1))) = (value);
    }

    std::uint64_t getTradingDay(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getTradingDay [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 102, length);
        return length;
    }

    InvestorPositionDtl_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 102, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 102, 9);
        return result;
    }

    InvestorPositionDtl_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 102, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t volumeId(void)
    {
        return 10;
    }

    static SBE_CONSTEXPR const std::uint64_t volumeSinceVersion(void)
    {
         return 0;
    }

    bool volumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= volumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t volumeEncodingOffset(void)
    {
         return 111;
    }


    static const char *VolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t volumeNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t volumeMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t volumeMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t volumeEncodingLength(void)
    {
        return 4;
    }

    std::int32_t volume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 111)));
    }

    InvestorPositionDtl_In &volume(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 111)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t settlementPriceId(void)
    {
        return 11;
    }

    static SBE_CONSTEXPR const std::uint64_t settlementPriceSinceVersion(void)
    {
         return 0;
    }

    bool settlementPriceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= settlementPriceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t settlementPriceEncodingOffset(void)
    {
         return 115;
    }


    static const char *SettlementPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double settlementPriceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double settlementPriceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double settlementPriceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t settlementPriceEncodingLength(void)
    {
        return 8;
    }

    double settlementPrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 115)));
    }

    InvestorPositionDtl_In &settlementPrice(const double value)
    {
        *((double *)(m_buffer + m_offset + 115)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t preSettlementPriceId(void)
    {
        return 12;
    }

    static SBE_CONSTEXPR const std::uint64_t preSettlementPriceSinceVersion(void)
    {
         return 0;
    }

    bool preSettlementPriceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= preSettlementPriceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t preSettlementPriceEncodingOffset(void)
    {
         return 123;
    }


    static const char *PreSettlementPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double preSettlementPriceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double preSettlementPriceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double preSettlementPriceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t preSettlementPriceEncodingLength(void)
    {
        return 8;
    }

    double preSettlementPrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 123)));
    }

    InvestorPositionDtl_In &preSettlementPrice(const double value)
    {
        *((double *)(m_buffer + m_offset + 123)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t openPriceId(void)
    {
        return 13;
    }

    static SBE_CONSTEXPR const std::uint64_t openPriceSinceVersion(void)
    {
         return 0;
    }

    bool openPriceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= openPriceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t openPriceEncodingOffset(void)
    {
         return 131;
    }


    static const char *OpenPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double openPriceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double openPriceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double openPriceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t openPriceEncodingLength(void)
    {
        return 8;
    }

    double openPrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 131)));
    }

    InvestorPositionDtl_In &openPrice(const double value)
    {
        *((double *)(m_buffer + m_offset + 131)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t marginId(void)
    {
        return 14;
    }

    static SBE_CONSTEXPR const std::uint64_t marginSinceVersion(void)
    {
         return 0;
    }

    bool marginInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= marginSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t marginEncodingOffset(void)
    {
         return 139;
    }


    static const char *MarginMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double marginNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double marginMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double marginMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t marginEncodingLength(void)
    {
        return 8;
    }

    double margin(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 139)));
    }

    InvestorPositionDtl_In &margin(const double value)
    {
        *((double *)(m_buffer + m_offset + 139)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t marginRateId(void)
    {
        return 15;
    }

    static SBE_CONSTEXPR const std::uint64_t marginRateSinceVersion(void)
    {
         return 0;
    }

    bool marginRateInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= marginRateSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t marginRateEncodingOffset(void)
    {
         return 147;
    }


    static const char *MarginRateMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double marginRateNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double marginRateMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double marginRateMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t marginRateEncodingLength(void)
    {
        return 8;
    }

    double marginRate(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 147)));
    }

    InvestorPositionDtl_In &marginRate(const double value)
    {
        *((double *)(m_buffer + m_offset + 147)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t closeVolumeId(void)
    {
        return 16;
    }

    static SBE_CONSTEXPR const std::uint64_t closeVolumeSinceVersion(void)
    {
         return 0;
    }

    bool closeVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= closeVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t closeVolumeEncodingOffset(void)
    {
         return 155;
    }


    static const char *CloseVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double closeVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double closeVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double closeVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t closeVolumeEncodingLength(void)
    {
        return 8;
    }

    double closeVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 155)));
    }

    InvestorPositionDtl_In &closeVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 155)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t closeAmountId(void)
    {
        return 17;
    }

    static SBE_CONSTEXPR const std::uint64_t closeAmountSinceVersion(void)
    {
         return 0;
    }

    bool closeAmountInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= closeAmountSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t closeAmountEncodingOffset(void)
    {
         return 163;
    }


    static const char *CloseAmountMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double closeAmountNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double closeAmountMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double closeAmountMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t closeAmountEncodingLength(void)
    {
        return 8;
    }

    double closeAmount(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 163)));
    }

    InvestorPositionDtl_In &closeAmount(const double value)
    {
        *((double *)(m_buffer + m_offset + 163)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
}
}
#endif
