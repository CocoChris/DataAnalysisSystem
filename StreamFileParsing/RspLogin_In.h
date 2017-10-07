/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_RSPLOGIN_IN_H_
#define _TFZQ_STP_TRADEOPT_RSPLOGIN_IN_H_

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

class RspLogin_In
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

    RspLogin_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    RspLogin_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    RspLogin_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)46;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)18;
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

    RspLogin_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    RspLogin_In &wrapForDecode(
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

    RspLogin_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    RspLogin_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t loginTimeId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t loginTimeSinceVersion(void)
    {
         return 0;
    }

    bool loginTimeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= loginTimeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t loginTimeEncodingOffset(void)
    {
         return 9;
    }


    static const char *LoginTimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char loginTimeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char loginTimeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char loginTimeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t loginTimeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t loginTimeLength(void)
    {
        return 10;
    }

    const char *loginTime(void) const
    {
        return (m_buffer + m_offset + 9);
    }

    char loginTime(const std::uint64_t index) const
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for loginTime [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 9 + (index * 1))));
    }

    void loginTime(const std::uint64_t index, const char value)
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for loginTime [E105]");
        }

        *((char *)(m_buffer + m_offset + 9 + (index * 1))) = (value);
    }

    std::uint64_t getLoginTime(char *dst, const std::uint64_t length) const
    {
        if (length > 10)
        {
             throw std::runtime_error("length too large for getLoginTime [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 9, length);
        return length;
    }

    RspLogin_In &putLoginTime(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 10);
        return *this;
    }

    std::string getLoginTimeAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 10);
        return result;
    }

    RspLogin_In &putLoginTime(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 9, str.c_str(), 10);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t userIDId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t userIDSinceVersion(void)
    {
         return 0;
    }

    bool userIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= userIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t userIDEncodingOffset(void)
    {
         return 19;
    }


    static const char *UserIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char userIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char userIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char userIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t userIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t userIDLength(void)
    {
        return 15;
    }

    const char *userID(void) const
    {
        return (m_buffer + m_offset + 19);
    }

    char userID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for userID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 19 + (index * 1))));
    }

    void userID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for userID [E105]");
        }

        *((char *)(m_buffer + m_offset + 19 + (index * 1))) = (value);
    }

    std::uint64_t getUserID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getUserID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 19, length);
        return length;
    }

    RspLogin_In &putUserID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 19, src, 15);
        return *this;
    }

    std::string getUserIDAsString() const
    {
        std::string result(m_buffer + m_offset + 19, 15);
        return result;
    }

    RspLogin_In &putUserID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 19, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t frontIDId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t frontIDSinceVersion(void)
    {
         return 0;
    }

    bool frontIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= frontIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t frontIDEncodingOffset(void)
    {
         return 34;
    }


    static const char *FrontIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t frontIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t frontIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t frontIDMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t frontIDEncodingLength(void)
    {
        return 4;
    }

    std::int32_t frontID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 34)));
    }

    RspLogin_In &frontID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 34)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sessionIDId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t sessionIDSinceVersion(void)
    {
         return 0;
    }

    bool sessionIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= sessionIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t sessionIDEncodingOffset(void)
    {
         return 38;
    }


    static const char *SessionIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t sessionIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t sessionIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t sessionIDMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t sessionIDEncodingLength(void)
    {
        return 4;
    }

    std::int32_t sessionID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 38)));
    }

    RspLogin_In &sessionID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 38)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t maxOrderRefId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t maxOrderRefSinceVersion(void)
    {
         return 0;
    }

    bool maxOrderRefInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= maxOrderRefSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t maxOrderRefEncodingOffset(void)
    {
         return 42;
    }


    static const char *MaxOrderRefMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t maxOrderRefNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t maxOrderRefMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t maxOrderRefMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t maxOrderRefEncodingLength(void)
    {
        return 4;
    }

    std::int32_t maxOrderRef(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 42)));
    }

    RspLogin_In &maxOrderRef(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 42)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }
};
}
}
}
#endif
