/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_COMMISSIONRATE_IN_H_
#define _TFZQ_STP_TRADEOPT_COMMISSIONRATE_IN_H_

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

class CommissionRate_In
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

    CommissionRate_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    CommissionRate_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    CommissionRate_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)181;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)8;
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

    CommissionRate_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    CommissionRate_In &wrapForDecode(
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

    CommissionRate_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    CommissionRate_In &putTradingDay(const std::string& str)
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

    CommissionRate_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 15);
        return result;
    }

    CommissionRate_In &putInvestorID(const std::string& str)
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

    CommissionRate_In &investorRange(const char value)
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

    CommissionRate_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 25, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 25, 9);
        return result;
    }

    CommissionRate_In &putExchangeID(const std::string& str)
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

    CommissionRate_In &putInstrumentID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 34, src, 31);
        return *this;
    }

    std::string getInstrumentIDAsString() const
    {
        std::string result(m_buffer + m_offset + 34, 31);
        return result;
    }

    CommissionRate_In &putInstrumentID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 34, str.c_str(), 31);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t productClassId(void)
    {
        return 6;
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
         return 65;
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
        return (*((char *)(m_buffer + m_offset + 65)));
    }

    CommissionRate_In &productClass(const char value)
    {
        *((char *)(m_buffer + m_offset + 65)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t directionId(void)
    {
        return 7;
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
         return 66;
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
        return (*((char *)(m_buffer + m_offset + 66)));
    }

    CommissionRate_In &direction(const char value)
    {
        *((char *)(m_buffer + m_offset + 66)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t offsetFlagId(void)
    {
        return 8;
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
         return 67;
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
        return (*((char *)(m_buffer + m_offset + 67)));
    }

    CommissionRate_In &offsetFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 67)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t coveredFlagId(void)
    {
        return 9;
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
         return 68;
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
        return (*((char *)(m_buffer + m_offset + 68)));
    }

    CommissionRate_In &coveredFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 68)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t stampTaxRateByMoneyId(void)
    {
        return 10;
    }

    static SBE_CONSTEXPR const std::uint64_t stampTaxRateByMoneySinceVersion(void)
    {
         return 0;
    }

    bool stampTaxRateByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= stampTaxRateByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t stampTaxRateByMoneyEncodingOffset(void)
    {
         return 69;
    }


    static const char *StampTaxRateByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double stampTaxRateByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double stampTaxRateByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double stampTaxRateByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t stampTaxRateByMoneyEncodingLength(void)
    {
        return 8;
    }

    double stampTaxRateByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 69)));
    }

    CommissionRate_In &stampTaxRateByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 69)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t stampTaxRateByVolumeId(void)
    {
        return 11;
    }

    static SBE_CONSTEXPR const std::uint64_t stampTaxRateByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool stampTaxRateByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= stampTaxRateByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t stampTaxRateByVolumeEncodingOffset(void)
    {
         return 77;
    }


    static const char *StampTaxRateByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double stampTaxRateByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double stampTaxRateByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double stampTaxRateByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t stampTaxRateByVolumeEncodingLength(void)
    {
        return 8;
    }

    double stampTaxRateByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 77)));
    }

    CommissionRate_In &stampTaxRateByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 77)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t transferFeeRateByMoneyId(void)
    {
        return 12;
    }

    static SBE_CONSTEXPR const std::uint64_t transferFeeRateByMoneySinceVersion(void)
    {
         return 0;
    }

    bool transferFeeRateByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= transferFeeRateByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t transferFeeRateByMoneyEncodingOffset(void)
    {
         return 85;
    }


    static const char *TransferFeeRateByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double transferFeeRateByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double transferFeeRateByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double transferFeeRateByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t transferFeeRateByMoneyEncodingLength(void)
    {
        return 8;
    }

    double transferFeeRateByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 85)));
    }

    CommissionRate_In &transferFeeRateByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 85)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t transferFeeRateByVolumeId(void)
    {
        return 13;
    }

    static SBE_CONSTEXPR const std::uint64_t transferFeeRateByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool transferFeeRateByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= transferFeeRateByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t transferFeeRateByVolumeEncodingOffset(void)
    {
         return 93;
    }


    static const char *TransferFeeRateByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double transferFeeRateByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double transferFeeRateByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double transferFeeRateByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t transferFeeRateByVolumeEncodingLength(void)
    {
        return 8;
    }

    double transferFeeRateByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 93)));
    }

    CommissionRate_In &transferFeeRateByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 93)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t handlingFeeByMoneyId(void)
    {
        return 14;
    }

    static SBE_CONSTEXPR const std::uint64_t handlingFeeByMoneySinceVersion(void)
    {
         return 0;
    }

    bool handlingFeeByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= handlingFeeByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t handlingFeeByMoneyEncodingOffset(void)
    {
         return 101;
    }


    static const char *HandlingFeeByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double handlingFeeByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double handlingFeeByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double handlingFeeByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t handlingFeeByMoneyEncodingLength(void)
    {
        return 8;
    }

    double handlingFeeByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 101)));
    }

    CommissionRate_In &handlingFeeByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 101)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t handlingFeeByVolumeId(void)
    {
        return 15;
    }

    static SBE_CONSTEXPR const std::uint64_t handlingFeeByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool handlingFeeByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= handlingFeeByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t handlingFeeByVolumeEncodingOffset(void)
    {
         return 109;
    }


    static const char *HandlingFeeByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double handlingFeeByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double handlingFeeByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double handlingFeeByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t handlingFeeByVolumeEncodingLength(void)
    {
        return 8;
    }

    double handlingFeeByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 109)));
    }

    CommissionRate_In &handlingFeeByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 109)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t adminFeeByMoneyId(void)
    {
        return 16;
    }

    static SBE_CONSTEXPR const std::uint64_t adminFeeByMoneySinceVersion(void)
    {
         return 0;
    }

    bool adminFeeByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= adminFeeByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t adminFeeByMoneyEncodingOffset(void)
    {
         return 117;
    }


    static const char *AdminFeeByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double adminFeeByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double adminFeeByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double adminFeeByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t adminFeeByMoneyEncodingLength(void)
    {
        return 8;
    }

    double adminFeeByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 117)));
    }

    CommissionRate_In &adminFeeByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 117)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t adminFeeByVolumeId(void)
    {
        return 17;
    }

    static SBE_CONSTEXPR const std::uint64_t adminFeeByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool adminFeeByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= adminFeeByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t adminFeeByVolumeEncodingOffset(void)
    {
         return 125;
    }


    static const char *AdminFeeByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double adminFeeByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double adminFeeByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double adminFeeByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t adminFeeByVolumeEncodingLength(void)
    {
        return 8;
    }

    double adminFeeByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 125)));
    }

    CommissionRate_In &adminFeeByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 125)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t tradeFeeByMoneyId(void)
    {
        return 18;
    }

    static SBE_CONSTEXPR const std::uint64_t tradeFeeByMoneySinceVersion(void)
    {
         return 0;
    }

    bool tradeFeeByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradeFeeByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradeFeeByMoneyEncodingOffset(void)
    {
         return 133;
    }


    static const char *TradeFeeByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double tradeFeeByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double tradeFeeByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double tradeFeeByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t tradeFeeByMoneyEncodingLength(void)
    {
        return 8;
    }

    double tradeFeeByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 133)));
    }

    CommissionRate_In &tradeFeeByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 133)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t tradeFeeByVolumeId(void)
    {
        return 19;
    }

    static SBE_CONSTEXPR const std::uint64_t tradeFeeByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool tradeFeeByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradeFeeByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradeFeeByVolumeEncodingOffset(void)
    {
         return 141;
    }


    static const char *TradeFeeByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double tradeFeeByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double tradeFeeByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double tradeFeeByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t tradeFeeByVolumeEncodingLength(void)
    {
        return 8;
    }

    double tradeFeeByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 141)));
    }

    CommissionRate_In &tradeFeeByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 141)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t clearingFeeByMoneyId(void)
    {
        return 20;
    }

    static SBE_CONSTEXPR const std::uint64_t clearingFeeByMoneySinceVersion(void)
    {
         return 0;
    }

    bool clearingFeeByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= clearingFeeByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t clearingFeeByMoneyEncodingOffset(void)
    {
         return 149;
    }


    static const char *ClearingFeeByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double clearingFeeByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double clearingFeeByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double clearingFeeByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t clearingFeeByMoneyEncodingLength(void)
    {
        return 8;
    }

    double clearingFeeByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 149)));
    }

    CommissionRate_In &clearingFeeByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 149)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t clearingFeeByVolumeId(void)
    {
        return 21;
    }

    static SBE_CONSTEXPR const std::uint64_t clearingFeeByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool clearingFeeByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= clearingFeeByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t clearingFeeByVolumeEncodingOffset(void)
    {
         return 157;
    }


    static const char *ClearingFeeByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double clearingFeeByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double clearingFeeByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double clearingFeeByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t clearingFeeByVolumeEncodingLength(void)
    {
        return 8;
    }

    double clearingFeeByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 157)));
    }

    CommissionRate_In &clearingFeeByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 157)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t otherFeeByVolumeId(void)
    {
        return 22;
    }

    static SBE_CONSTEXPR const std::uint64_t otherFeeByVolumeSinceVersion(void)
    {
         return 0;
    }

    bool otherFeeByVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= otherFeeByVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t otherFeeByVolumeEncodingOffset(void)
    {
         return 165;
    }


    static const char *OtherFeeByVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double otherFeeByVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double otherFeeByVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double otherFeeByVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t otherFeeByVolumeEncodingLength(void)
    {
        return 8;
    }

    double otherFeeByVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 165)));
    }

    CommissionRate_In &otherFeeByVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 165)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t otherFeeByMoneyId(void)
    {
        return 23;
    }

    static SBE_CONSTEXPR const std::uint64_t otherFeeByMoneySinceVersion(void)
    {
         return 0;
    }

    bool otherFeeByMoneyInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= otherFeeByMoneySinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t otherFeeByMoneyEncodingOffset(void)
    {
         return 173;
    }


    static const char *OtherFeeByMoneyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double otherFeeByMoneyNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double otherFeeByMoneyMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double otherFeeByMoneyMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t otherFeeByMoneyEncodingLength(void)
    {
        return 8;
    }

    double otherFeeByMoney(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 173)));
    }

    CommissionRate_In &otherFeeByMoney(const double value)
    {
        *((double *)(m_buffer + m_offset + 173)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
}
}
#endif
