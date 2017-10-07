/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_GATEWAYCONFIG_IN_H_
#define _TFZQ_STP_TRADEOPT_GATEWAYCONFIG_IN_H_

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

class GatewayConfig_In
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

    GatewayConfig_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    GatewayConfig_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    GatewayConfig_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)175;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)30;
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

    GatewayConfig_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    GatewayConfig_In &wrapForDecode(
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

    GatewayConfig_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    GatewayConfig_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t gatewayIDId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t gatewayIDSinceVersion(void)
    {
         return 0;
    }

    bool gatewayIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= gatewayIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t gatewayIDEncodingOffset(void)
    {
         return 9;
    }


    static const char *GatewayIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t gatewayIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t gatewayIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t gatewayIDMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t gatewayIDEncodingLength(void)
    {
        return 4;
    }

    std::int32_t gatewayID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 9)));
    }

    GatewayConfig_In &gatewayID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 9)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t frontAddressId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t frontAddressSinceVersion(void)
    {
         return 0;
    }

    bool frontAddressInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= frontAddressSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t frontAddressEncodingOffset(void)
    {
         return 13;
    }


    static const char *FrontAddressMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char frontAddressNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char frontAddressMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char frontAddressMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t frontAddressEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t frontAddressLength(void)
    {
        return 32;
    }

    const char *frontAddress(void) const
    {
        return (m_buffer + m_offset + 13);
    }

    char frontAddress(const std::uint64_t index) const
    {
        if (index >= 32)
        {
            throw std::runtime_error("index out of range for frontAddress [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 13 + (index * 1))));
    }

    void frontAddress(const std::uint64_t index, const char value)
    {
        if (index >= 32)
        {
            throw std::runtime_error("index out of range for frontAddress [E105]");
        }

        *((char *)(m_buffer + m_offset + 13 + (index * 1))) = (value);
    }

    std::uint64_t getFrontAddress(char *dst, const std::uint64_t length) const
    {
        if (length > 32)
        {
             throw std::runtime_error("length too large for getFrontAddress [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 13, length);
        return length;
    }

    GatewayConfig_In &putFrontAddress(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 13, src, 32);
        return *this;
    }

    std::string getFrontAddressAsString() const
    {
        std::string result(m_buffer + m_offset + 13, 32);
        return result;
    }

    GatewayConfig_In &putFrontAddress(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 13, str.c_str(), 32);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t resumeTypeId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t resumeTypeSinceVersion(void)
    {
         return 0;
    }

    bool resumeTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= resumeTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t resumeTypeEncodingOffset(void)
    {
         return 45;
    }


    static const char *ResumeTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char resumeTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char resumeTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char resumeTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t resumeTypeEncodingLength(void)
    {
        return 1;
    }

    char resumeType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 45)));
    }

    GatewayConfig_In &resumeType(const char value)
    {
        *((char *)(m_buffer + m_offset + 45)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t flowPathId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t flowPathSinceVersion(void)
    {
         return 0;
    }

    bool flowPathInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= flowPathSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t flowPathEncodingOffset(void)
    {
         return 46;
    }


    static const char *FlowPathMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char flowPathNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char flowPathMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char flowPathMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t flowPathEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t flowPathLength(void)
    {
        return 128;
    }

    const char *flowPath(void) const
    {
        return (m_buffer + m_offset + 46);
    }

    char flowPath(const std::uint64_t index) const
    {
        if (index >= 128)
        {
            throw std::runtime_error("index out of range for flowPath [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 46 + (index * 1))));
    }

    void flowPath(const std::uint64_t index, const char value)
    {
        if (index >= 128)
        {
            throw std::runtime_error("index out of range for flowPath [E105]");
        }

        *((char *)(m_buffer + m_offset + 46 + (index * 1))) = (value);
    }

    std::uint64_t getFlowPath(char *dst, const std::uint64_t length) const
    {
        if (length > 128)
        {
             throw std::runtime_error("length too large for getFlowPath [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 46, length);
        return length;
    }

    GatewayConfig_In &putFlowPath(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 46, src, 128);
        return *this;
    }

    std::string getFlowPathAsString() const
    {
        std::string result(m_buffer + m_offset + 46, 128);
        return result;
    }

    GatewayConfig_In &putFlowPath(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 46, str.c_str(), 128);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t isDefaultId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t isDefaultSinceVersion(void)
    {
         return 0;
    }

    bool isDefaultInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= isDefaultSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t isDefaultEncodingOffset(void)
    {
         return 174;
    }


    static const char *IsDefaultMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t isDefaultNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t isDefaultMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t isDefaultMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t isDefaultEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t isDefault(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 174)));
    }

    GatewayConfig_In &isDefault(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 174)) = (value);
        return *this;
    }
};
}
}
}
#endif
