/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_QRYRISKRULE_IN_H_
#define _TFZQ_STP_TRADEOPT_QRYRISKRULE_IN_H_

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

class QryRiskRule_In
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

    QryRiskRule_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    QryRiskRule_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    QryRiskRule_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)133;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)21;
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

    QryRiskRule_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    QryRiskRule_In &wrapForDecode(
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

    static SBE_CONSTEXPR const std::uint16_t riskIdId(void)
    {
        return 1;
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
         return 0;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 0)));
    }

    QryRiskRule_In &riskId(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 0)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t ruleCodeId(void)
    {
        return 2;
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
         return 4;
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
        return (m_buffer + m_offset + 4);
    }

    char ruleCode(const std::uint64_t index) const
    {
        if (index >= 129)
        {
            throw std::runtime_error("index out of range for ruleCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 4 + (index * 1))));
    }

    void ruleCode(const std::uint64_t index, const char value)
    {
        if (index >= 129)
        {
            throw std::runtime_error("index out of range for ruleCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 4 + (index * 1))) = (value);
    }

    std::uint64_t getRuleCode(char *dst, const std::uint64_t length) const
    {
        if (length > 129)
        {
             throw std::runtime_error("length too large for getRuleCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 4, length);
        return length;
    }

    QryRiskRule_In &putRuleCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 4, src, 129);
        return *this;
    }

    std::string getRuleCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 4, 129);
        return result;
    }

    QryRiskRule_In &putRuleCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 4, str.c_str(), 129);
        return *this;
    }

};
}
}
}
#endif
