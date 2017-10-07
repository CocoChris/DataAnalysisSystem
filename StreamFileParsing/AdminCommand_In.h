/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_ADMINCOMMAND_IN_H_
#define _TFZQ_STP_TRADEOPT_ADMINCOMMAND_IN_H_

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

class AdminCommand_In
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

    AdminCommand_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    AdminCommand_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    AdminCommand_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)299;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)14;
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

    AdminCommand_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    AdminCommand_In &wrapForDecode(
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

    AdminCommand_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    AdminCommand_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t adminCodeId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t adminCodeSinceVersion(void)
    {
         return 0;
    }

    bool adminCodeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= adminCodeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t adminCodeEncodingOffset(void)
    {
         return 9;
    }


    static const char *AdminCodeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char adminCodeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char adminCodeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char adminCodeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t adminCodeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t adminCodeLength(void)
    {
        return 33;
    }

    const char *adminCode(void) const
    {
        return (m_buffer + m_offset + 9);
    }

    char adminCode(const std::uint64_t index) const
    {
        if (index >= 33)
        {
            throw std::runtime_error("index out of range for adminCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 9 + (index * 1))));
    }

    void adminCode(const std::uint64_t index, const char value)
    {
        if (index >= 33)
        {
            throw std::runtime_error("index out of range for adminCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 9 + (index * 1))) = (value);
    }

    std::uint64_t getAdminCode(char *dst, const std::uint64_t length) const
    {
        if (length > 33)
        {
             throw std::runtime_error("length too large for getAdminCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 9, length);
        return length;
    }

    AdminCommand_In &putAdminCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 33);
        return *this;
    }

    std::string getAdminCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 33);
        return result;
    }

    AdminCommand_In &putAdminCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 9, str.c_str(), 33);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t valueId(void)
    {
        return 3;
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
         return 42;
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
        return (m_buffer + m_offset + 42);
    }

    char value(const std::uint64_t index) const
    {
        if (index >= 257)
        {
            throw std::runtime_error("index out of range for value [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 42 + (index * 1))));
    }

    void value(const std::uint64_t index, const char value)
    {
        if (index >= 257)
        {
            throw std::runtime_error("index out of range for value [E105]");
        }

        *((char *)(m_buffer + m_offset + 42 + (index * 1))) = (value);
    }

    std::uint64_t getValue(char *dst, const std::uint64_t length) const
    {
        if (length > 257)
        {
             throw std::runtime_error("length too large for getValue [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 42, length);
        return length;
    }

    AdminCommand_In &putValue(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 42, src, 257);
        return *this;
    }

    std::string getValueAsString() const
    {
        std::string result(m_buffer + m_offset + 42, 257);
        return result;
    }

    AdminCommand_In &putValue(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 42, str.c_str(), 257);
        return *this;
    }

};
}
}
}
#endif
