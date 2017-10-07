/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_INVESTORPOSITION_IN_H_
#define _TFZQ_STP_TRADEOPT_INVESTORPOSITION_IN_H_

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

class InvestorPosition_In
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

    InvestorPosition_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    InvestorPosition_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    InvestorPosition_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)257;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)6;
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

    InvestorPosition_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    InvestorPosition_In &wrapForDecode(
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

    InvestorPosition_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 15);
        return result;
    }

    InvestorPosition_In &putInvestorID(const std::string& str)
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

    InvestorPosition_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 15, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 15, 9);
        return result;
    }

    InvestorPosition_In &putExchangeID(const std::string& str)
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

    InvestorPosition_In &putInstrumentID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 24, src, 31);
        return *this;
    }

    std::string getInstrumentIDAsString() const
    {
        std::string result(m_buffer + m_offset + 24, 31);
        return result;
    }

    InvestorPosition_In &putInstrumentID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 24, str.c_str(), 31);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t coveredFlagId(void)
    {
        return 4;
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
         return 55;
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
        return (*((char *)(m_buffer + m_offset + 55)));
    }

    InvestorPosition_In &coveredFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 55)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t posiDirectionId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t posiDirectionSinceVersion(void)
    {
         return 0;
    }

    bool posiDirectionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= posiDirectionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t posiDirectionEncodingOffset(void)
    {
         return 56;
    }


    static const char *PosiDirectionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char posiDirectionNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char posiDirectionMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char posiDirectionMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t posiDirectionEncodingLength(void)
    {
        return 1;
    }

    char posiDirection(void) const
    {
        return (*((char *)(m_buffer + m_offset + 56)));
    }

    InvestorPosition_In &posiDirection(const char value)
    {
        *((char *)(m_buffer + m_offset + 56)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t tradingCodeId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t tradingCodeSinceVersion(void)
    {
         return 0;
    }

    bool tradingCodeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= tradingCodeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t tradingCodeEncodingOffset(void)
    {
         return 57;
    }


    static const char *TradingCodeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char tradingCodeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char tradingCodeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char tradingCodeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t tradingCodeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t tradingCodeLength(void)
    {
        return 15;
    }

    const char *tradingCode(void) const
    {
        return (m_buffer + m_offset + 57);
    }

    char tradingCode(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradingCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 57 + (index * 1))));
    }

    void tradingCode(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradingCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 57 + (index * 1))) = (value);
    }

    std::uint64_t getTradingCode(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getTradingCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 57, length);
        return length;
    }

    InvestorPosition_In &putTradingCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 57, src, 15);
        return *this;
    }

    std::string getTradingCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 57, 15);
        return result;
    }

    InvestorPosition_In &putTradingCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 57, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t tradingDayId(void)
    {
        return 7;
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
         return 72;
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
        return (m_buffer + m_offset + 72);
    }

    char tradingDay(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for tradingDay [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 72 + (index * 1))));
    }

    void tradingDay(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for tradingDay [E105]");
        }

        *((char *)(m_buffer + m_offset + 72 + (index * 1))) = (value);
    }

    std::uint64_t getTradingDay(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getTradingDay [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 72, length);
        return length;
    }

    InvestorPosition_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 72, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 72, 9);
        return result;
    }

    InvestorPosition_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 72, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t ydPositionId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t ydPositionSinceVersion(void)
    {
         return 0;
    }

    bool ydPositionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= ydPositionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t ydPositionEncodingOffset(void)
    {
         return 81;
    }


    static const char *YdPositionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double ydPositionNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double ydPositionMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double ydPositionMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t ydPositionEncodingLength(void)
    {
        return 8;
    }

    double ydPosition(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 81)));
    }

    InvestorPosition_In &ydPosition(const double value)
    {
        *((double *)(m_buffer + m_offset + 81)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t preMarginId(void)
    {
        return 9;
    }

    static SBE_CONSTEXPR const std::uint64_t preMarginSinceVersion(void)
    {
         return 0;
    }

    bool preMarginInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= preMarginSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t preMarginEncodingOffset(void)
    {
         return 89;
    }


    static const char *PreMarginMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double preMarginNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double preMarginMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double preMarginMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t preMarginEncodingLength(void)
    {
        return 8;
    }

    double preMargin(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 89)));
    }

    InvestorPosition_In &preMargin(const double value)
    {
        *((double *)(m_buffer + m_offset + 89)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t todayPositionId(void)
    {
        return 10;
    }

    static SBE_CONSTEXPR const std::uint64_t todayPositionSinceVersion(void)
    {
         return 0;
    }

    bool todayPositionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= todayPositionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t todayPositionEncodingOffset(void)
    {
         return 97;
    }


    static const char *TodayPositionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double todayPositionNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double todayPositionMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double todayPositionMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t todayPositionEncodingLength(void)
    {
        return 8;
    }

    double todayPosition(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 97)));
    }

    InvestorPosition_In &todayPosition(const double value)
    {
        *((double *)(m_buffer + m_offset + 97)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t totalPositionId(void)
    {
        return 11;
    }

    static SBE_CONSTEXPR const std::uint64_t totalPositionSinceVersion(void)
    {
         return 0;
    }

    bool totalPositionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= totalPositionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t totalPositionEncodingOffset(void)
    {
         return 105;
    }


    static const char *TotalPositionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double totalPositionNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double totalPositionMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double totalPositionMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t totalPositionEncodingLength(void)
    {
        return 8;
    }

    double totalPosition(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 105)));
    }

    InvestorPosition_In &totalPosition(const double value)
    {
        *((double *)(m_buffer + m_offset + 105)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t useMarginId(void)
    {
        return 12;
    }

    static SBE_CONSTEXPR const std::uint64_t useMarginSinceVersion(void)
    {
         return 0;
    }

    bool useMarginInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= useMarginSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t useMarginEncodingOffset(void)
    {
         return 113;
    }


    static const char *UseMarginMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double useMarginNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double useMarginMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double useMarginMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t useMarginEncodingLength(void)
    {
        return 8;
    }

    double useMargin(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 113)));
    }

    InvestorPosition_In &useMargin(const double value)
    {
        *((double *)(m_buffer + m_offset + 113)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t openVolumeId(void)
    {
        return 13;
    }

    static SBE_CONSTEXPR const std::uint64_t openVolumeSinceVersion(void)
    {
         return 0;
    }

    bool openVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= openVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t openVolumeEncodingOffset(void)
    {
         return 121;
    }


    static const char *OpenVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double openVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double openVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double openVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t openVolumeEncodingLength(void)
    {
        return 8;
    }

    double openVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 121)));
    }

    InvestorPosition_In &openVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 121)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t closeVolumeId(void)
    {
        return 14;
    }

    static SBE_CONSTEXPR const std::uint64_t closeVolumeSinceVersion(void)
    {
         return 0;
    }

    bool closeVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= closeVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t closeVolumeEncodingOffset(void)
    {
         return 129;
    }


    static const char *CloseVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double closeVolumeNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double closeVolumeMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double closeVolumeMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t closeVolumeEncodingLength(void)
    {
        return 8;
    }

    double closeVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 129)));
    }

    InvestorPosition_In &closeVolume(const double value)
    {
        *((double *)(m_buffer + m_offset + 129)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t settlementPriceId(void)
    {
        return 15;
    }

    static SBE_CONSTEXPR const std::uint64_t settlementPriceSinceVersion(void)
    {
         return 0;
    }

    bool settlementPriceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= settlementPriceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t settlementPriceEncodingOffset(void)
    {
         return 137;
    }


    static const char *SettlementPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double settlementPriceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double settlementPriceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double settlementPriceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t settlementPriceEncodingLength(void)
    {
        return 8;
    }

    double settlementPrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 137)));
    }

    InvestorPosition_In &settlementPrice(const double value)
    {
        *((double *)(m_buffer + m_offset + 137)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t preSettlementPriceId(void)
    {
        return 16;
    }

    static SBE_CONSTEXPR const std::uint64_t preSettlementPriceSinceVersion(void)
    {
         return 0;
    }

    bool preSettlementPriceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= preSettlementPriceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t preSettlementPriceEncodingOffset(void)
    {
         return 145;
    }


    static const char *PreSettlementPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double preSettlementPriceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double preSettlementPriceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double preSettlementPriceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t preSettlementPriceEncodingLength(void)
    {
        return 8;
    }

    double preSettlementPrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 145)));
    }

    InvestorPosition_In &preSettlementPrice(const double value)
    {
        *((double *)(m_buffer + m_offset + 145)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t commissionId(void)
    {
        return 17;
    }

    static SBE_CONSTEXPR const std::uint64_t commissionSinceVersion(void)
    {
         return 0;
    }

    bool commissionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= commissionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t commissionEncodingOffset(void)
    {
         return 153;
    }


    static const char *CommissionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double commissionNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double commissionMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double commissionMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t commissionEncodingLength(void)
    {
        return 8;
    }

    double commission(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 153)));
    }

    InvestorPosition_In &commission(const double value)
    {
        *((double *)(m_buffer + m_offset + 153)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t frozenCommissionId(void)
    {
        return 18;
    }

    static SBE_CONSTEXPR const std::uint64_t frozenCommissionSinceVersion(void)
    {
         return 0;
    }

    bool frozenCommissionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= frozenCommissionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t frozenCommissionEncodingOffset(void)
    {
         return 161;
    }


    static const char *FrozenCommissionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double frozenCommissionNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double frozenCommissionMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double frozenCommissionMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t frozenCommissionEncodingLength(void)
    {
        return 8;
    }

    double frozenCommission(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 161)));
    }

    InvestorPosition_In &frozenCommission(const double value)
    {
        *((double *)(m_buffer + m_offset + 161)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t frozenMarginId(void)
    {
        return 19;
    }

    static SBE_CONSTEXPR const std::uint64_t frozenMarginSinceVersion(void)
    {
         return 0;
    }

    bool frozenMarginInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= frozenMarginSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t frozenMarginEncodingOffset(void)
    {
         return 169;
    }


    static const char *FrozenMarginMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double frozenMarginNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double frozenMarginMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double frozenMarginMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t frozenMarginEncodingLength(void)
    {
        return 8;
    }

    double frozenMargin(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 169)));
    }

    InvestorPosition_In &frozenMargin(const double value)
    {
        *((double *)(m_buffer + m_offset + 169)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t openCostId(void)
    {
        return 20;
    }

    static SBE_CONSTEXPR const std::uint64_t openCostSinceVersion(void)
    {
         return 0;
    }

    bool openCostInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= openCostSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t openCostEncodingOffset(void)
    {
         return 177;
    }


    static const char *OpenCostMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double openCostNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double openCostMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double openCostMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t openCostEncodingLength(void)
    {
        return 8;
    }

    double openCost(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 177)));
    }

    InvestorPosition_In &openCost(const double value)
    {
        *((double *)(m_buffer + m_offset + 177)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t positionCostId(void)
    {
        return 21;
    }

    static SBE_CONSTEXPR const std::uint64_t positionCostSinceVersion(void)
    {
         return 0;
    }

    bool positionCostInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= positionCostSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t positionCostEncodingOffset(void)
    {
         return 185;
    }


    static const char *PositionCostMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double positionCostNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double positionCostMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double positionCostMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t positionCostEncodingLength(void)
    {
        return 8;
    }

    double positionCost(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 185)));
    }

    InvestorPosition_In &positionCost(const double value)
    {
        *((double *)(m_buffer + m_offset + 185)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t closeProfitId(void)
    {
        return 22;
    }

    static SBE_CONSTEXPR const std::uint64_t closeProfitSinceVersion(void)
    {
         return 0;
    }

    bool closeProfitInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= closeProfitSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t closeProfitEncodingOffset(void)
    {
         return 193;
    }


    static const char *CloseProfitMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double closeProfitNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double closeProfitMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double closeProfitMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t closeProfitEncodingLength(void)
    {
        return 8;
    }

    double closeProfit(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 193)));
    }

    InvestorPosition_In &closeProfit(const double value)
    {
        *((double *)(m_buffer + m_offset + 193)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t positionProfitId(void)
    {
        return 23;
    }

    static SBE_CONSTEXPR const std::uint64_t positionProfitSinceVersion(void)
    {
         return 0;
    }

    bool positionProfitInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= positionProfitSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t positionProfitEncodingOffset(void)
    {
         return 201;
    }


    static const char *PositionProfitMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double positionProfitNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double positionProfitMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double positionProfitMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t positionProfitEncodingLength(void)
    {
        return 8;
    }

    double positionProfit(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 201)));
    }

    InvestorPosition_In &positionProfit(const double value)
    {
        *((double *)(m_buffer + m_offset + 201)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t openAmountId(void)
    {
        return 24;
    }

    static SBE_CONSTEXPR const std::uint64_t openAmountSinceVersion(void)
    {
         return 0;
    }

    bool openAmountInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= openAmountSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t openAmountEncodingOffset(void)
    {
         return 209;
    }


    static const char *OpenAmountMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double openAmountNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double openAmountMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double openAmountMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t openAmountEncodingLength(void)
    {
        return 8;
    }

    double openAmount(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 209)));
    }

    InvestorPosition_In &openAmount(const double value)
    {
        *((double *)(m_buffer + m_offset + 209)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t closeAmountId(void)
    {
        return 25;
    }

    static SBE_CONSTEXPR const std::uint64_t closeAmountSinceVersion(void)
    {
         return 0;
    }

    bool closeAmountInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= closeAmountSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t closeAmountEncodingOffset(void)
    {
         return 217;
    }


    static const char *CloseAmountMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double closeAmountNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double closeAmountMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double closeAmountMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t closeAmountEncodingLength(void)
    {
        return 8;
    }

    double closeAmount(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 217)));
    }

    InvestorPosition_In &closeAmount(const double value)
    {
        *((double *)(m_buffer + m_offset + 217)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t longFrozenId(void)
    {
        return 26;
    }

    static SBE_CONSTEXPR const std::uint64_t longFrozenSinceVersion(void)
    {
         return 0;
    }

    bool longFrozenInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= longFrozenSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t longFrozenEncodingOffset(void)
    {
         return 225;
    }


    static const char *LongFrozenMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double longFrozenNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double longFrozenMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double longFrozenMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t longFrozenEncodingLength(void)
    {
        return 8;
    }

    double longFrozen(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 225)));
    }

    InvestorPosition_In &longFrozen(const double value)
    {
        *((double *)(m_buffer + m_offset + 225)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t longFrozenAmountId(void)
    {
        return 27;
    }

    static SBE_CONSTEXPR const std::uint64_t longFrozenAmountSinceVersion(void)
    {
         return 0;
    }

    bool longFrozenAmountInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= longFrozenAmountSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t longFrozenAmountEncodingOffset(void)
    {
         return 233;
    }


    static const char *LongFrozenAmountMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double longFrozenAmountNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double longFrozenAmountMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double longFrozenAmountMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t longFrozenAmountEncodingLength(void)
    {
        return 8;
    }

    double longFrozenAmount(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 233)));
    }

    InvestorPosition_In &longFrozenAmount(const double value)
    {
        *((double *)(m_buffer + m_offset + 233)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t shortFrozenId(void)
    {
        return 28;
    }

    static SBE_CONSTEXPR const std::uint64_t shortFrozenSinceVersion(void)
    {
         return 0;
    }

    bool shortFrozenInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= shortFrozenSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t shortFrozenEncodingOffset(void)
    {
         return 241;
    }


    static const char *ShortFrozenMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double shortFrozenNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double shortFrozenMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double shortFrozenMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t shortFrozenEncodingLength(void)
    {
        return 8;
    }

    double shortFrozen(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 241)));
    }

    InvestorPosition_In &shortFrozen(const double value)
    {
        *((double *)(m_buffer + m_offset + 241)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t shortFrozenAmountId(void)
    {
        return 29;
    }

    static SBE_CONSTEXPR const std::uint64_t shortFrozenAmountSinceVersion(void)
    {
         return 0;
    }

    bool shortFrozenAmountInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= shortFrozenAmountSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t shortFrozenAmountEncodingOffset(void)
    {
         return 249;
    }


    static const char *ShortFrozenAmountMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double shortFrozenAmountNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double shortFrozenAmountMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double shortFrozenAmountMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t shortFrozenAmountEncodingLength(void)
    {
        return 8;
    }

    double shortFrozenAmount(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 249)));
    }

    InvestorPosition_In &shortFrozenAmount(const double value)
    {
        *((double *)(m_buffer + m_offset + 249)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }
};
}
}
}
#endif
