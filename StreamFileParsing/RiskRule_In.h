/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_RISKRULE_IN_H_
#define _TFZQ_STP_TRADEOPT_RISKRULE_IN_H_

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

class RiskRule_In
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

    RiskRule_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    RiskRule_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    RiskRule_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)1234;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)12;
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

    RiskRule_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    RiskRule_In &wrapForDecode(
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

    RiskRule_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    RiskRule_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t riskIdId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t riskIdSinceVersion(void)
    {
         return 0;
    }

    bool riskIdInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= riskIdSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t riskIdEncodingOffset(void)
    {
         return 9;
    }


    static const char *RiskIdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t riskIdNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t riskIdMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t riskIdMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t riskIdEncodingLength(void)
    {
        return 4;
    }

    std::int32_t riskId(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 9)));
    }

    RiskRule_In &riskId(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 9)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t ruleCodeId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t ruleCodeSinceVersion(void)
    {
         return 0;
    }

    bool ruleCodeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= ruleCodeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t ruleCodeEncodingOffset(void)
    {
         return 13;
    }


    static const char *RuleCodeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char ruleCodeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char ruleCodeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char ruleCodeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t ruleCodeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t ruleCodeLength(void)
    {
        return 129;
    }

    const char *ruleCode(void) const
    {
        return (m_buffer + m_offset + 13);
    }

    char ruleCode(const std::uint64_t index) const
    {
        if (index >= 129)
        {
            throw std::runtime_error("index out of range for ruleCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 13 + (index * 1))));
    }

    void ruleCode(const std::uint64_t index, const char value)
    {
        if (index >= 129)
        {
            throw std::runtime_error("index out of range for ruleCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 13 + (index * 1))) = (value);
    }

    std::uint64_t getRuleCode(char *dst, const std::uint64_t length) const
    {
        if (length > 129)
        {
             throw std::runtime_error("length too large for getRuleCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 13, length);
        return length;
    }

    RiskRule_In &putRuleCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 13, src, 129);
        return *this;
    }

    std::string getRuleCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 13, 129);
        return result;
    }

    RiskRule_In &putRuleCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 13, str.c_str(), 129);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t exchangeIDId(void)
    {
        return 4;
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
         return 142;
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
        return (m_buffer + m_offset + 142);
    }

    char exchangeID(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 142 + (index * 1))));
    }

    void exchangeID(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 142 + (index * 1))) = (value);
    }

    std::uint64_t getExchangeID(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getExchangeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 142, length);
        return length;
    }

    RiskRule_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 142, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 142, 9);
        return result;
    }

    RiskRule_In &putExchangeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 142, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t instrumentIDsId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t instrumentIDsSinceVersion(void)
    {
         return 0;
    }

    bool instrumentIDsInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= instrumentIDsSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t instrumentIDsEncodingOffset(void)
    {
         return 151;
    }


    static const char *InstrumentIDsMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char instrumentIDsNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char instrumentIDsMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char instrumentIDsMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t instrumentIDsEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t instrumentIDsLength(void)
    {
        return 513;
    }

    const char *instrumentIDs(void) const
    {
        return (m_buffer + m_offset + 151);
    }

    char instrumentIDs(const std::uint64_t index) const
    {
        if (index >= 513)
        {
            throw std::runtime_error("index out of range for instrumentIDs [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 151 + (index * 1))));
    }

    void instrumentIDs(const std::uint64_t index, const char value)
    {
        if (index >= 513)
        {
            throw std::runtime_error("index out of range for instrumentIDs [E105]");
        }

        *((char *)(m_buffer + m_offset + 151 + (index * 1))) = (value);
    }

    std::uint64_t getInstrumentIDs(char *dst, const std::uint64_t length) const
    {
        if (length > 513)
        {
             throw std::runtime_error("length too large for getInstrumentIDs [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 151, length);
        return length;
    }

    RiskRule_In &putInstrumentIDs(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 151, src, 513);
        return *this;
    }

    std::string getInstrumentIDsAsString() const
    {
        std::string result(m_buffer + m_offset + 151, 513);
        return result;
    }

    RiskRule_In &putInstrumentIDs(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 151, str.c_str(), 513);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t instrumentRangeId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t instrumentRangeSinceVersion(void)
    {
         return 0;
    }

    bool instrumentRangeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= instrumentRangeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t instrumentRangeEncodingOffset(void)
    {
         return 664;
    }


    static const char *InstrumentRangeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char instrumentRangeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char instrumentRangeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char instrumentRangeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t instrumentRangeEncodingLength(void)
    {
        return 1;
    }

    char instrumentRange(void) const
    {
        return (*((char *)(m_buffer + m_offset + 664)));
    }

    RiskRule_In &instrumentRange(const char value)
    {
        *((char *)(m_buffer + m_offset + 664)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t instrumentControlFlagId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t instrumentControlFlagSinceVersion(void)
    {
         return 0;
    }

    bool instrumentControlFlagInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= instrumentControlFlagSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t instrumentControlFlagEncodingOffset(void)
    {
         return 665;
    }


    static const char *InstrumentControlFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t instrumentControlFlagNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t instrumentControlFlagMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t instrumentControlFlagMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t instrumentControlFlagEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t instrumentControlFlag(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 665)));
    }

    RiskRule_In &instrumentControlFlag(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 665)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t investorIDsId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t investorIDsSinceVersion(void)
    {
         return 0;
    }

    bool investorIDsInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= investorIDsSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t investorIDsEncodingOffset(void)
    {
         return 666;
    }


    static const char *InvestorIDsMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char investorIDsNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char investorIDsMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char investorIDsMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t investorIDsEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t investorIDsLength(void)
    {
        return 257;
    }

    const char *investorIDs(void) const
    {
        return (m_buffer + m_offset + 666);
    }

    char investorIDs(const std::uint64_t index) const
    {
        if (index >= 257)
        {
            throw std::runtime_error("index out of range for investorIDs [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 666 + (index * 1))));
    }

    void investorIDs(const std::uint64_t index, const char value)
    {
        if (index >= 257)
        {
            throw std::runtime_error("index out of range for investorIDs [E105]");
        }

        *((char *)(m_buffer + m_offset + 666 + (index * 1))) = (value);
    }

    std::uint64_t getInvestorIDs(char *dst, const std::uint64_t length) const
    {
        if (length > 257)
        {
             throw std::runtime_error("length too large for getInvestorIDs [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 666, length);
        return length;
    }

    RiskRule_In &putInvestorIDs(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 666, src, 257);
        return *this;
    }

    std::string getInvestorIDsAsString() const
    {
        std::string result(m_buffer + m_offset + 666, 257);
        return result;
    }

    RiskRule_In &putInvestorIDs(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 666, str.c_str(), 257);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t investorRangeId(void)
    {
        return 9;
    }

    static SBE_CONSTEXPR const std::uint64_t investorRangeSinceVersion(void)
    {
         return 0;
    }

    bool investorRangeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= investorRangeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t investorRangeEncodingOffset(void)
    {
         return 923;
    }


    static const char *InvestorRangeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char investorRangeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char investorRangeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char investorRangeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t investorRangeEncodingLength(void)
    {
        return 1;
    }

    char investorRange(void) const
    {
        return (*((char *)(m_buffer + m_offset + 923)));
    }

    RiskRule_In &investorRange(const char value)
    {
        *((char *)(m_buffer + m_offset + 923)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t investorControlFlagId(void)
    {
        return 10;
    }

    static SBE_CONSTEXPR const std::uint64_t investorControlFlagSinceVersion(void)
    {
         return 0;
    }

    bool investorControlFlagInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= investorControlFlagSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t investorControlFlagEncodingOffset(void)
    {
         return 924;
    }


    static const char *InvestorControlFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t investorControlFlagNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t investorControlFlagMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t investorControlFlagMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t investorControlFlagEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t investorControlFlag(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 924)));
    }

    RiskRule_In &investorControlFlag(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 924)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t ruleNameId(void)
    {
        return 11;
    }

    static SBE_CONSTEXPR const std::uint64_t ruleNameSinceVersion(void)
    {
         return 0;
    }

    bool ruleNameInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= ruleNameSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t ruleNameEncodingOffset(void)
    {
         return 925;
    }


    static const char *RuleNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char ruleNameNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char ruleNameMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char ruleNameMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t ruleNameEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t ruleNameLength(void)
    {
        return 51;
    }

    const char *ruleName(void) const
    {
        return (m_buffer + m_offset + 925);
    }

    char ruleName(const std::uint64_t index) const
    {
        if (index >= 51)
        {
            throw std::runtime_error("index out of range for ruleName [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 925 + (index * 1))));
    }

    void ruleName(const std::uint64_t index, const char value)
    {
        if (index >= 51)
        {
            throw std::runtime_error("index out of range for ruleName [E105]");
        }

        *((char *)(m_buffer + m_offset + 925 + (index * 1))) = (value);
    }

    std::uint64_t getRuleName(char *dst, const std::uint64_t length) const
    {
        if (length > 51)
        {
             throw std::runtime_error("length too large for getRuleName [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 925, length);
        return length;
    }

    RiskRule_In &putRuleName(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 925, src, 51);
        return *this;
    }

    std::string getRuleNameAsString() const
    {
        std::string result(m_buffer + m_offset + 925, 51);
        return result;
    }

    RiskRule_In &putRuleName(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 925, str.c_str(), 51);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t isActiveId(void)
    {
        return 12;
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
         return 976;
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
        return (*((std::uint8_t *)(m_buffer + m_offset + 976)));
    }

    RiskRule_In &isActive(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 976)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t valueId(void)
    {
        return 13;
    }

    static SBE_CONSTEXPR const std::uint64_t valueSinceVersion(void)
    {
         return 0;
    }

    bool valueInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= valueSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t valueEncodingOffset(void)
    {
         return 977;
    }


    static const char *ValueMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char valueNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char valueMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char valueMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t valueEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t valueLength(void)
    {
        return 257;
    }

    const char *value(void) const
    {
        return (m_buffer + m_offset + 977);
    }

    char value(const std::uint64_t index) const
    {
        if (index >= 257)
        {
            throw std::runtime_error("index out of range for value [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 977 + (index * 1))));
    }

    void value(const std::uint64_t index, const char value)
    {
        if (index >= 257)
        {
            throw std::runtime_error("index out of range for value [E105]");
        }

        *((char *)(m_buffer + m_offset + 977 + (index * 1))) = (value);
    }

    std::uint64_t getValue(char *dst, const std::uint64_t length) const
    {
        if (length > 257)
        {
             throw std::runtime_error("length too large for getValue [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 977, length);
        return length;
    }

    RiskRule_In &putValue(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 977, src, 257);
        return *this;
    }

    std::string getValueAsString() const
    {
        std::string result(m_buffer + m_offset + 977, 257);
        return result;
    }

    RiskRule_In &putValue(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 977, str.c_str(), 257);
        return *this;
    }

};
}
}
}
#endif
