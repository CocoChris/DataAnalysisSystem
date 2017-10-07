/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_MARGINRATE_IN_H_
#define _TFZQ_STP_TRADEOPT_MARGINRATE_IN_H_

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

class MarginRate_In
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

    MarginRate_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    MarginRate_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    MarginRate_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)101;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)9;
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

    MarginRate_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    MarginRate_In &wrapForDecode(
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

    MarginRate_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    MarginRate_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t investorIDId(void)
    {
        return 2;
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
         return 9;
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
        return (m_buffer + m_offset + 9);
    }

    char investorID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 9 + (index * 1))));
    }

    void investorID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for investorID [E105]");
        }

        *((char *)(m_buffer + m_offset + 9 + (index * 1))) = (value);
    }

    std::uint64_t getInvestorID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getInvestorID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 9, length);
        return length;
    }

    MarginRate_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 15);
        return result;
    }

    MarginRate_In &putInvestorID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 9, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t investorRangeId(void)
    {
        return 3;
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
         return 24;
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
        return (*((char *)(m_buffer + m_offset + 24)));
    }

    MarginRate_In &investorRange(const char value)
    {
        *((char *)(m_buffer + m_offset + 24)) = (value);
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
         return 25;
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
        return (m_buffer + m_offset + 25);
    }

    char exchangeID(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 25 + (index * 1))));
    }

    void exchangeID(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 25 + (index * 1))) = (value);
    }

    std::uint64_t getExchangeID(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getExchangeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 25, length);
        return length;
    }

    MarginRate_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 25, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 25, 9);
        return result;
    }

    MarginRate_In &putExchangeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 25, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t instrumentIDId(void)
    {
        return 5;
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
         return 34;
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
        return (m_buffer + m_offset + 34);
    }

    char instrumentID(const std::uint64_t index) const
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 34 + (index * 1))));
    }

    void instrumentID(const std::uint64_t index, const char value)
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E105]");
        }

        *((char *)(m_buffer + m_offset + 34 + (index * 1))) = (value);
    }

    std::uint64_t getInstrumentID(char *dst, const std::uint64_t length) const
    {
        if (length > 31)
        {
             throw std::runtime_error("length too large for getInstrumentID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 34, length);
        return length;
    }

    MarginRate_In &putInstrumentID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 34, src, 31);
        return *this;
    }

    std::string getInstrumentIDAsString() const
    {
        std::string result(m_buffer + m_offset + 34, 31);
        return result;
    }

    MarginRate_In &putInstrumentID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 34, str.c_str(), 31);
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
         return 65;
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
        return (*((char *)(m_buffer + m_offset + 65)));
    }

    MarginRate_In &coveredFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 65)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t optionTypeId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t optionTypeSinceVersion(void)
    {
         return 0;
    }

    bool optionTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= optionTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t optionTypeEncodingOffset(void)
    {
         return 66;
    }


    static const char *OptionTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char optionTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char optionTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char optionTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t optionTypeEncodingLength(void)
    {
        return 1;
    }

    char optionType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 66)));
    }

    MarginRate_In &optionType(const char value)
    {
        *((char *)(m_buffer + m_offset + 66)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t productClassId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t productClassSinceVersion(void)
    {
         return 0;
    }

    bool productClassInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= productClassSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t productClassEncodingOffset(void)
    {
         return 67;
    }


    static const char *ProductClassMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char productClassNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char productClassMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char productClassMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t productClassEncodingLength(void)
    {
        return 1;
    }

    char productClass(void) const
    {
        return (*((char *)(m_buffer + m_offset + 67)));
    }

    MarginRate_In &productClass(const char value)
    {
        *((char *)(m_buffer + m_offset + 67)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t longMarginRatioByMoneyId(void)
    {
        return 9;
    }

    static SBE_CONSTEXPR const std::uint64_t longMarginRatioByMoneySinceVersion(void)
    {
         return 0;
    }

    bool longMarginRatioByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= longMarginRatioByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t longMarginRatioByMoneyEncodingOffset(void)
    {
         return 68;
    }


    static const char *LongMarginRatioByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double longMarginRatioByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double longMarginRatioByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double longMarginRatioByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t longMarginRatioByMoneyEncodingLength(void)
    {
        return 8;
    }

    double longMarginRatioByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 68)));
    }

    MarginRate_In &longMarginRatioByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 68)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t longMarginRatioByVolumeId(void)
    {
        return 10;
    }

    static SBE_CONSTEXPR const std::uint64_t longMarginRatioByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool longMarginRatioByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= longMarginRatioByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t longMarginRatioByVolumeEncodingOffset(void)
    {
         return 76;
    }


    static const char *LongMarginRatioByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double longMarginRatioByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double longMarginRatioByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double longMarginRatioByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t longMarginRatioByVolumeEncodingLength(void)
    {
        return 8;
    }

    double longMarginRatioByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 76)));
    }

    MarginRate_In &longMarginRatioByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 76)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t shortMarginRatioByMoneyId(void)
    {
        return 11;
    }

    static SBE_CONSTEXPR const std::uint64_t shortMarginRatioByMoneySinceVersion(void)
    {
         return 0;
    }

    bool shortMarginRatioByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= shortMarginRatioByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t shortMarginRatioByMoneyEncodingOffset(void)
    {
         return 84;
    }


    static const char *ShortMarginRatioByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double shortMarginRatioByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double shortMarginRatioByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double shortMarginRatioByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t shortMarginRatioByMoneyEncodingLength(void)
    {
        return 8;
    }

    double shortMarginRatioByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 84)));
    }

    MarginRate_In &shortMarginRatioByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 84)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t shortMarginRatioByVolumeId(void)
    {
        return 12;
    }

    static SBE_CONSTEXPR const std::uint64_t shortMarginRatioByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool shortMarginRatioByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= shortMarginRatioByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t shortMarginRatioByVolumeEncodingOffset(void)
    {
         return 92;
    }


    static const char *ShortMarginRatioByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double shortMarginRatioByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double shortMarginRatioByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double shortMarginRatioByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t shortMarginRatioByVolumeEncodingLength(void)
    {
        return 8;
    }

    double shortMarginRatioByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 92)));
    }

    MarginRate_In &shortMarginRatioByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 92)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t isFloatId(void)
    {
        return 13;
    }

    static SBE_CONSTEXPR const std::uint64_t isFloatSinceVersion(void)
    {
         return 0;
    }

    bool isFloatInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= isFloatSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t isFloatEncodingOffset(void)
    {
         return 100;
    }


    static const char *IsFloatMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t isFloatNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t isFloatMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t isFloatMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t isFloatEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t isFloat(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 100)));
    }

    MarginRate_In &isFloat(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 100)) = (value);
        return *this;
    }
};
}
}
}
#endif
