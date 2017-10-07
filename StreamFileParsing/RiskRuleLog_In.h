/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_RISKRULELOG_IN_H_
#define _TFZQ_STP_TRADEOPT_RISKRULELOG_IN_H_

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

class RiskRuleLog_In
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

    RiskRuleLog_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    RiskRuleLog_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    RiskRuleLog_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)852;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)13;
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

    RiskRuleLog_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    RiskRuleLog_In &wrapForDecode(
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

    RiskRuleLog_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    RiskRuleLog_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t sequenceNoId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t sequenceNoSinceVersion(void)
    {
         return 0;
    }

    bool sequenceNoInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= sequenceNoSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t sequenceNoEncodingOffset(void)
    {
         return 9;
    }


    static const char *SequenceNoMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t sequenceNoNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t sequenceNoMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t sequenceNoMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t sequenceNoEncodingLength(void)
    {
        return 4;
    }

    std::int32_t sequenceNo(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 9)));
    }

    RiskRuleLog_In &sequenceNo(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 9)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t executeTimeId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t executeTimeSinceVersion(void)
    {
         return 0;
    }

    bool executeTimeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= executeTimeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t executeTimeEncodingOffset(void)
    {
         return 13;
    }


    static const char *ExecuteTimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char executeTimeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char executeTimeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char executeTimeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t executeTimeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t executeTimeLength(void)
    {
        return 10;
    }

    const char *executeTime(void) const
    {
        return (m_buffer + m_offset + 13);
    }

    char executeTime(const std::uint64_t index) const
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for executeTime [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 13 + (index * 1))));
    }

    void executeTime(const std::uint64_t index, const char value)
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for executeTime [E105]");
        }

        *((char *)(m_buffer + m_offset + 13 + (index * 1))) = (value);
    }

    std::uint64_t getExecuteTime(char *dst, const std::uint64_t length) const
    {
        if (length > 10)
        {
             throw std::runtime_error("length too large for getExecuteTime [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 13, length);
        return length;
    }

    RiskRuleLog_In &putExecuteTime(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 13, src, 10);
        return *this;
    }

    std::string getExecuteTimeAsString() const
    {
        std::string result(m_buffer + m_offset + 13, 10);
        return result;
    }

    RiskRuleLog_In &putExecuteTime(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 13, str.c_str(), 10);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t riskIdId(void)
    {
        return 4;
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
         return 23;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 23)));
    }

    RiskRuleLog_In &riskId(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 23)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t ruleCodeId(void)
    {
        return 5;
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
         return 27;
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
        return (m_buffer + m_offset + 27);
    }

    char ruleCode(const std::uint64_t index) const
    {
        if (index >= 129)
        {
            throw std::runtime_error("index out of range for ruleCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 27 + (index * 1))));
    }

    void ruleCode(const std::uint64_t index, const char value)
    {
        if (index >= 129)
        {
            throw std::runtime_error("index out of range for ruleCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 27 + (index * 1))) = (value);
    }

    std::uint64_t getRuleCode(char *dst, const std::uint64_t length) const
    {
        if (length > 129)
        {
             throw std::runtime_error("length too large for getRuleCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 27, length);
        return length;
    }

    RiskRuleLog_In &putRuleCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 27, src, 129);
        return *this;
    }

    std::string getRuleCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 27, 129);
        return result;
    }

    RiskRuleLog_In &putRuleCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 27, str.c_str(), 129);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t ruleNameId(void)
    {
        return 6;
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
         return 156;
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
        return (m_buffer + m_offset + 156);
    }

    char ruleName(const std::uint64_t index) const
    {
        if (index >= 51)
        {
            throw std::runtime_error("index out of range for ruleName [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 156 + (index * 1))));
    }

    void ruleName(const std::uint64_t index, const char value)
    {
        if (index >= 51)
        {
            throw std::runtime_error("index out of range for ruleName [E105]");
        }

        *((char *)(m_buffer + m_offset + 156 + (index * 1))) = (value);
    }

    std::uint64_t getRuleName(char *dst, const std::uint64_t length) const
    {
        if (length > 51)
        {
             throw std::runtime_error("length too large for getRuleName [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 156, length);
        return length;
    }

    RiskRuleLog_In &putRuleName(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 156, src, 51);
        return *this;
    }

    std::string getRuleNameAsString() const
    {
        std::string result(m_buffer + m_offset + 156, 51);
        return result;
    }

    RiskRuleLog_In &putRuleName(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 156, str.c_str(), 51);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t exchangeIDId(void)
    {
        return 7;
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
         return 207;
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
        return (m_buffer + m_offset + 207);
    }

    char exchangeID(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 207 + (index * 1))));
    }

    void exchangeID(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 207 + (index * 1))) = (value);
    }

    std::uint64_t getExchangeID(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getExchangeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 207, length);
        return length;
    }

    RiskRuleLog_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 207, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 207, 9);
        return result;
    }

    RiskRuleLog_In &putExchangeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 207, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t instrumentIDsId(void)
    {
        return 8;
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
         return 216;
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
        return (m_buffer + m_offset + 216);
    }

    char instrumentIDs(const std::uint64_t index) const
    {
        if (index >= 513)
        {
            throw std::runtime_error("index out of range for instrumentIDs [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 216 + (index * 1))));
    }

    void instrumentIDs(const std::uint64_t index, const char value)
    {
        if (index >= 513)
        {
            throw std::runtime_error("index out of range for instrumentIDs [E105]");
        }

        *((char *)(m_buffer + m_offset + 216 + (index * 1))) = (value);
    }

    std::uint64_t getInstrumentIDs(char *dst, const std::uint64_t length) const
    {
        if (length > 513)
        {
             throw std::runtime_error("length too large for getInstrumentIDs [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 216, length);
        return length;
    }

    RiskRuleLog_In &putInstrumentIDs(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 216, src, 513);
        return *this;
    }

    std::string getInstrumentIDsAsString() const
    {
        std::string result(m_buffer + m_offset + 216, 513);
        return result;
    }

    RiskRuleLog_In &putInstrumentIDs(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 216, str.c_str(), 513);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t investorIDId(void)
    {
        return 9;
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
         return 729;
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
        return (m_buffer + m_offset + 729);
    }

    char investorID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 729 + (index * 1))));
    }

    void investorID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E105]");
        }

        *((char *)(m_buffer + m_offset + 729 + (index * 1))) = (value);
    }

    std::uint64_t getInvestorID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getInvestorID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 729, length);
        return length;
    }

    RiskRuleLog_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 729, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 729, 15);
        return result;
    }

    RiskRuleLog_In &putInvestorID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 729, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderRefId(void)
    {
        return 10;
    }

    static SBE_CONSTEXPR const std::uint64_t orderRefSinceVersion(void)
    {
         return 0;
    }

    bool orderRefInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderRefSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderRefEncodingOffset(void)
    {
         return 744;
    }


    static const char *OrderRefMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderRefNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderRefMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderRefMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderRefEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t orderRefLength(void)
    {
        return 11;
    }

    const char *orderRef(void) const
    {
        return (m_buffer + m_offset + 744);
    }

    char orderRef(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderRef [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 744 + (index * 1))));
    }

    void orderRef(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderRef [E105]");
        }

        *((char *)(m_buffer + m_offset + 744 + (index * 1))) = (value);
    }

    std::uint64_t getOrderRef(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getOrderRef [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 744, length);
        return length;
    }

    RiskRuleLog_In &putOrderRef(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 744, src, 11);
        return *this;
    }

    std::string getOrderRefAsString() const
    {
        std::string result(m_buffer + m_offset + 744, 11);
        return result;
    }

    RiskRuleLog_In &putOrderRef(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 744, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t thresholdId(void)
    {
        return 11;
    }

    static SBE_CONSTEXPR const std::uint64_t thresholdSinceVersion(void)
    {
         return 0;
    }

    bool thresholdInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= thresholdSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t thresholdEncodingOffset(void)
    {
         return 755;
    }


    static const char *ThresholdMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double thresholdNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double thresholdMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double thresholdMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t thresholdEncodingLength(void)
    {
        return 8;
    }

    double threshold(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 755)));
    }

    RiskRuleLog_In &threshold(const double value)
    {
        *((double *)(m_buffer + m_offset + 755)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t calcValueId(void)
    {
        return 12;
    }

    static SBE_CONSTEXPR const std::uint64_t calcValueSinceVersion(void)
    {
         return 0;
    }

    bool calcValueInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= calcValueSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t calcValueEncodingOffset(void)
    {
         return 763;
    }


    static const char *CalcValueMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double calcValueNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double calcValueMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double calcValueMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t calcValueEncodingLength(void)
    {
        return 8;
    }

    double calcValue(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 763)));
    }

    RiskRuleLog_In &calcValue(const double value)
    {
        *((double *)(m_buffer + m_offset + 763)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t errorMsgId(void)
    {
        return 13;
    }

    static SBE_CONSTEXPR const std::uint64_t errorMsgSinceVersion(void)
    {
         return 0;
    }

    bool errorMsgInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= errorMsgSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t errorMsgEncodingOffset(void)
    {
         return 771;
    }


    static const char *ErrorMsgMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char errorMsgNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char errorMsgMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char errorMsgMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t errorMsgEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t errorMsgLength(void)
    {
        return 81;
    }

    const char *errorMsg(void) const
    {
        return (m_buffer + m_offset + 771);
    }

    char errorMsg(const std::uint64_t index) const
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for errorMsg [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 771 + (index * 1))));
    }

    void errorMsg(const std::uint64_t index, const char value)
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for errorMsg [E105]");
        }

        *((char *)(m_buffer + m_offset + 771 + (index * 1))) = (value);
    }

    std::uint64_t getErrorMsg(char *dst, const std::uint64_t length) const
    {
        if (length > 81)
        {
             throw std::runtime_error("length too large for getErrorMsg [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 771, length);
        return length;
    }

    RiskRuleLog_In &putErrorMsg(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 771, src, 81);
        return *this;
    }

    std::string getErrorMsgAsString() const
    {
        std::string result(m_buffer + m_offset + 771, 81);
        return result;
    }

    RiskRuleLog_In &putErrorMsg(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 771, str.c_str(), 81);
        return *this;
    }

};
}
}
}
#endif
