/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_RSPINFO_IN_H_
#define _TFZQ_STP_TRADEOPT_RSPINFO_IN_H_

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

class RspInfo_In
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

    RspInfo_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    RspInfo_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    RspInfo_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)86;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)15;
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

    RspInfo_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    RspInfo_In &wrapForDecode(
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

    static SBE_CONSTEXPR const std::uint16_t errorIDId(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t errorIDSinceVersion(void)
    {
         return 0;
    }

    bool errorIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= errorIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t errorIDEncodingOffset(void)
    {
         return 0;
    }


    static const char *ErrorIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t errorIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t errorIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t errorIDMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t errorIDEncodingLength(void)
    {
        return 4;
    }

    std::int32_t errorID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 0)));
    }

    RspInfo_In &errorID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 0)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t isLastId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t isLastSinceVersion(void)
    {
         return 0;
    }

    bool isLastInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= isLastSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t isLastEncodingOffset(void)
    {
         return 4;
    }


    static const char *IsLastMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t isLastNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t isLastMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t isLastMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t isLastEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t isLast(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 4)));
    }

    RspInfo_In &isLast(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 4)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t errorMsgId(void)
    {
        return 3;
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
         return 5;
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
        return (m_buffer + m_offset + 5);
    }

    char errorMsg(const std::uint64_t index) const
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for errorMsg [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 5 + (index * 1))));
    }

    void errorMsg(const std::uint64_t index, const char value)
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for errorMsg [E105]");
        }

        *((char *)(m_buffer + m_offset + 5 + (index * 1))) = (value);
    }

    std::uint64_t getErrorMsg(char *dst, const std::uint64_t length) const
    {
        if (length > 81)
        {
             throw std::runtime_error("length too large for getErrorMsg [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 5, length);
        return length;
    }

    RspInfo_In &putErrorMsg(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 5, src, 81);
        return *this;
    }

    std::string getErrorMsgAsString() const
    {
        std::string result(m_buffer + m_offset + 5, 81);
        return result;
    }

    RspInfo_In &putErrorMsg(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 5, str.c_str(), 81);
        return *this;
    }

};
}
}
}
#endif
