/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_QRYCOMMISSIONRATE_IN_H_
#define _TFZQ_STP_TRADEOPT_QRYCOMMISSIONRATE_IN_H_

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

class QryCommissionRate_In
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

    QryCommissionRate_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    QryCommissionRate_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    QryCommissionRate_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)59;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)23;
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

    QryCommissionRate_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    QryCommissionRate_In &wrapForDecode(
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

    QryCommissionRate_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 15);
        return result;
    }

    QryCommissionRate_In &putInvestorID(const std::string& str)
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

    QryCommissionRate_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 15, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 15, 9);
        return result;
    }

    QryCommissionRate_In &putExchangeID(const std::string& str)
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

    QryCommissionRate_In &putInstrumentID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 24, src, 31);
        return *this;
    }

    std::string getInstrumentIDAsString() const
    {
        std::string result(m_buffer + m_offset + 24, 31);
        return result;
    }

    QryCommissionRate_In &putInstrumentID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 24, str.c_str(), 31);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t directionId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t directionSinceVersion(void)
    {
         return 0;
    }

    bool directionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= directionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t directionEncodingOffset(void)
    {
         return 55;
    }


    static const char *DirectionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char directionNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char directionMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char directionMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t directionEncodingLength(void)
    {
        return 1;
    }

    char direction(void) const
    {
        return (*((char *)(m_buffer + m_offset + 55)));
    }

    QryCommissionRate_In &direction(const char value)
    {
        *((char *)(m_buffer + m_offset + 55)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t offsetFlagId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t offsetFlagSinceVersion(void)
    {
         return 0;
    }

    bool offsetFlagInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= offsetFlagSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t offsetFlagEncodingOffset(void)
    {
         return 56;
    }


    static const char *OffsetFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char offsetFlagNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char offsetFlagMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char offsetFlagMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t offsetFlagEncodingLength(void)
    {
        return 1;
    }

    char offsetFlag(void) const
    {
        return (*((char *)(m_buffer + m_offset + 56)));
    }

    QryCommissionRate_In &offsetFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 56)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t coveredFlagId(void)
    {
        return 6;
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
         return 57;
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
        return (*((char *)(m_buffer + m_offset + 57)));
    }

    QryCommissionRate_In &coveredFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 57)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t hedgeFlagId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t hedgeFlagSinceVersion(void)
    {
         return 0;
    }

    bool hedgeFlagInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= hedgeFlagSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t hedgeFlagEncodingOffset(void)
    {
         return 58;
    }


    static const char *HedgeFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char hedgeFlagNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char hedgeFlagMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char hedgeFlagMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t hedgeFlagEncodingLength(void)
    {
        return 1;
    }

    char hedgeFlag(void) const
    {
        return (*((char *)(m_buffer + m_offset + 58)));
    }

    QryCommissionRate_In &hedgeFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 58)) = (value);
        return *this;
    }
};
}
}
}
#endif
