/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_PACKAGEHEADER_H_
#define _TFZQ_STP_TRADEOPT_PACKAGEHEADER_H_

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

class PackageHeader
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

    PackageHeader(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    PackageHeader(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    PackageHeader(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)48;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)99;
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

    PackageHeader &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    PackageHeader &wrapForDecode(
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

    static SBE_CONSTEXPR const std::uint16_t versionId(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t versionSinceVersion(void)
    {
         return 0;
    }

    bool versionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= versionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t versionEncodingOffset(void)
    {
         return 0;
    }


    static const char *VersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char versionNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char versionMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char versionMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t versionEncodingLength(void)
    {
        return 1;
    }

    char version(void) const
    {
        return (*((char *)(m_buffer + m_offset + 0)));
    }

    PackageHeader &version(const char value)
    {
        *((char *)(m_buffer + m_offset + 0)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t packageTypeId(void)
    {
        return 2;
    }

    static SBE_CONSTEXPR const std::uint64_t packageTypeSinceVersion(void)
    {
         return 0;
    }

    bool packageTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= packageTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t packageTypeEncodingOffset(void)
    {
         return 1;
    }


    static const char *PackageTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char packageTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char packageTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char packageTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t packageTypeEncodingLength(void)
    {
        return 1;
    }

    char packageType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 1)));
    }

    PackageHeader &packageType(const char value)
    {
        *((char *)(m_buffer + m_offset + 1)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t chainId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t chainSinceVersion(void)
    {
         return 0;
    }

    bool chainInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= chainSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t chainEncodingOffset(void)
    {
         return 2;
    }


    static const char *ChainMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char chainNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char chainMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char chainMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t chainEncodingLength(void)
    {
        return 1;
    }

    char chain(void) const
    {
        return (*((char *)(m_buffer + m_offset + 2)));
    }

    PackageHeader &chain(const char value)
    {
        *((char *)(m_buffer + m_offset + 2)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t paddingId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t paddingSinceVersion(void)
    {
         return 0;
    }

    bool paddingInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= paddingSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t paddingEncodingOffset(void)
    {
         return 3;
    }


    static const char *PaddingMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char paddingNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char paddingMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char paddingMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t paddingEncodingLength(void)
    {
        return 1;
    }

    char padding(void) const
    {
        return (*((char *)(m_buffer + m_offset + 3)));
    }

    PackageHeader &padding(const char value)
    {
        *((char *)(m_buffer + m_offset + 3)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t topicIDId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t topicIDSinceVersion(void)
    {
         return 0;
    }

    bool topicIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= topicIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t topicIDEncodingOffset(void)
    {
         return 4;
    }


    static const char *TopicIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t topicIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t topicIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t topicIDMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t topicIDEncodingLength(void)
    {
        return 4;
    }

    std::int32_t topicID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 4)));
    }

    PackageHeader &topicID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 4)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t tIDId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t tIDSinceVersion(void)
    {
         return 0;
    }

    bool tIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tIDEncodingOffset(void)
    {
         return 8;
    }


    static const char *TIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t tIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t tIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t tIDMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t tIDEncodingLength(void)
    {
        return 4;
    }

    std::int32_t tID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 8)));
    }

    PackageHeader &tID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 8)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t requestIDId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t requestIDSinceVersion(void)
    {
         return 0;
    }

    bool requestIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= requestIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t requestIDEncodingOffset(void)
    {
         return 12;
    }


    static const char *RequestIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t requestIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t requestIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t requestIDMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t requestIDEncodingLength(void)
    {
        return 4;
    }

    std::int32_t requestID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 12)));
    }

    PackageHeader &requestID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 12)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t fieldCountId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t fieldCountSinceVersion(void)
    {
         return 0;
    }

    bool fieldCountInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= fieldCountSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t fieldCountEncodingOffset(void)
    {
         return 16;
    }


    static const char *FieldCountMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t fieldCountNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t fieldCountMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t fieldCountMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t fieldCountEncodingLength(void)
    {
        return 4;
    }

    std::int32_t fieldCount(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 16)));
    }

    PackageHeader &fieldCount(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 16)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t frontIDId(void)
    {
        return 9;
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
         return 20;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 20)));
    }

    PackageHeader &frontID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 20)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sessionIDId(void)
    {
        return 10;
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
         return 24;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 24)));
    }

    PackageHeader &sessionID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 24)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t timeId(void)
    {
        return 11;
    }

    static SBE_CONSTEXPR const std::uint64_t timeSinceVersion(void)
    {
         return 0;
    }

    bool timeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= timeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t timeEncodingOffset(void)
    {
         return 28;
    }


    static const char *TimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t timeNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t timeMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t timeMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t timeEncodingLength(void)
    {
        return 4;
    }

    std::int32_t time(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 28)));
    }

    PackageHeader &time(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 28)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sequenceNoId(void)
    {
        return 12;
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
         return 32;
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

    static SBE_CONSTEXPR const std::int64_t sequenceNoNullValue()
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR const std::int64_t sequenceNoMinValue()
    {
        return -9223372036854775807L;
    }

    static SBE_CONSTEXPR const std::int64_t sequenceNoMaxValue()
    {
        return 9223372036854775807L;
    }

    static SBE_CONSTEXPR const std::size_t sequenceNoEncodingLength(void)
    {
        return 8;
    }

    std::int64_t sequenceNo(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::int64_t *)(m_buffer + m_offset + 32)));
    }

    PackageHeader &sequenceNo(const std::int64_t value)
    {
        *((std::int64_t *)(m_buffer + m_offset + 32)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t lastSnId(void)
    {
        return 13;
    }

    static SBE_CONSTEXPR const std::uint64_t lastSnSinceVersion(void)
    {
         return 0;
    }

    bool lastSnInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= lastSnSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t lastSnEncodingOffset(void)
    {
         return 40;
    }


    static const char *LastSnMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int64_t lastSnNullValue()
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR const std::int64_t lastSnMinValue()
    {
        return -9223372036854775807L;
    }

    static SBE_CONSTEXPR const std::int64_t lastSnMaxValue()
    {
        return 9223372036854775807L;
    }

    static SBE_CONSTEXPR const std::size_t lastSnEncodingLength(void)
    {
        return 8;
    }

    std::int64_t lastSn(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::int64_t *)(m_buffer + m_offset + 40)));
    }

    PackageHeader &lastSn(const std::int64_t value)
    {
        *((std::int64_t *)(m_buffer + m_offset + 40)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
}
}
#endif
