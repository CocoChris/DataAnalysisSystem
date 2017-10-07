/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_ORDER_IN_H_
#define _TFZQ_STP_TRADEOPT_ORDER_IN_H_

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

class Order_In
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

    Order_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    Order_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    Order_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)396;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)10;
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

    Order_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    Order_In &wrapForDecode(
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

    Order_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    Order_In &putTradingDay(const std::string& str)
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

    Order_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 15);
        return result;
    }

    Order_In &putInvestorID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 9, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t sessionIDId(void)
    {
        return 3;
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

    Order_In &sessionID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 24)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
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
         return 28;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 28)));
    }

    Order_In &frontID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 28)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t orderRefId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t orderRefSinceVersion(void)
    {
         return 0;
    }

    bool orderRefInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderRefSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderRefEncodingOffset(void)
    {
         return 32;
    }


    static const char *OrderRefMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderRefNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderRefMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderRefMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderRefEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t orderRefLength(void)
    {
        return 11;
    }

    const char *orderRef(void) const
    {
        return (m_buffer + m_offset + 32);
    }

    char orderRef(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderRef [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 32 + (index * 1))));
    }

    void orderRef(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderRef [E105]");
        }

        *((char *)(m_buffer + m_offset + 32 + (index * 1))) = (value);
    }

    std::uint64_t getOrderRef(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getOrderRef [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 32, length);
        return length;
    }

    Order_In &putOrderRef(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 32, src, 11);
        return *this;
    }

    std::string getOrderRefAsString() const
    {
        std::string result(m_buffer + m_offset + 32, 11);
        return result;
    }

    Order_In &putOrderRef(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 32, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t exchangeIDId(void)
    {
        return 6;
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
         return 43;
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
        return (m_buffer + m_offset + 43);
    }

    char exchangeID(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 43 + (index * 1))));
    }

    void exchangeID(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 43 + (index * 1))) = (value);
    }

    std::uint64_t getExchangeID(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getExchangeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 43, length);
        return length;
    }

    Order_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 43, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 43, 9);
        return result;
    }

    Order_In &putExchangeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 43, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t seatIDId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t seatIDSinceVersion(void)
    {
         return 0;
    }

    bool seatIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= seatIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t seatIDEncodingOffset(void)
    {
         return 52;
    }


    static const char *SeatIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char seatIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char seatIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char seatIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t seatIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t seatIDLength(void)
    {
        return 11;
    }

    const char *seatID(void) const
    {
        return (m_buffer + m_offset + 52);
    }

    char seatID(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for seatID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 52 + (index * 1))));
    }

    void seatID(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for seatID [E105]");
        }

        *((char *)(m_buffer + m_offset + 52 + (index * 1))) = (value);
    }

    std::uint64_t getSeatID(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getSeatID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 52, length);
        return length;
    }

    Order_In &putSeatID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 52, src, 11);
        return *this;
    }

    std::string getSeatIDAsString() const
    {
        std::string result(m_buffer + m_offset + 52, 11);
        return result;
    }

    Order_In &putSeatID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 52, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderLocalIDId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t orderLocalIDSinceVersion(void)
    {
         return 0;
    }

    bool orderLocalIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderLocalIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderLocalIDEncodingOffset(void)
    {
         return 63;
    }


    static const char *OrderLocalIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderLocalIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderLocalIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderLocalIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderLocalIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t orderLocalIDLength(void)
    {
        return 13;
    }

    const char *orderLocalID(void) const
    {
        return (m_buffer + m_offset + 63);
    }

    char orderLocalID(const std::uint64_t index) const
    {
        if (index >= 13)
        {
            throw std::runtime_error("index out of range for orderLocalID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 63 + (index * 1))));
    }

    void orderLocalID(const std::uint64_t index, const char value)
    {
        if (index >= 13)
        {
            throw std::runtime_error("index out of range for orderLocalID [E105]");
        }

        *((char *)(m_buffer + m_offset + 63 + (index * 1))) = (value);
    }

    std::uint64_t getOrderLocalID(char *dst, const std::uint64_t length) const
    {
        if (length > 13)
        {
             throw std::runtime_error("length too large for getOrderLocalID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 63, length);
        return length;
    }

    Order_In &putOrderLocalID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 63, src, 13);
        return *this;
    }

    std::string getOrderLocalIDAsString() const
    {
        std::string result(m_buffer + m_offset + 63, 13);
        return result;
    }

    Order_In &putOrderLocalID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 63, str.c_str(), 13);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t directionId(void)
    {
        return 9;
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
         return 76;
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
        return (*((char *)(m_buffer + m_offset + 76)));
    }

    Order_In &direction(const char value)
    {
        *((char *)(m_buffer + m_offset + 76)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t userIDId(void)
    {
        return 10;
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
         return 77;
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
        return (m_buffer + m_offset + 77);
    }

    char userID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for userID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 77 + (index * 1))));
    }

    void userID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for userID [E105]");
        }

        *((char *)(m_buffer + m_offset + 77 + (index * 1))) = (value);
    }

    std::uint64_t getUserID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getUserID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 77, length);
        return length;
    }

    Order_In &putUserID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 77, src, 15);
        return *this;
    }

    std::string getUserIDAsString() const
    {
        std::string result(m_buffer + m_offset + 77, 15);
        return result;
    }

    Order_In &putUserID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 77, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t tradingCodeId(void)
    {
        return 11;
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
         return 92;
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
        return (m_buffer + m_offset + 92);
    }

    char tradingCode(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradingCode [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 92 + (index * 1))));
    }

    void tradingCode(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for tradingCode [E105]");
        }

        *((char *)(m_buffer + m_offset + 92 + (index * 1))) = (value);
    }

    std::uint64_t getTradingCode(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getTradingCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 92, length);
        return length;
    }

    Order_In &putTradingCode(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 92, src, 15);
        return *this;
    }

    std::string getTradingCodeAsString() const
    {
        std::string result(m_buffer + m_offset + 92, 15);
        return result;
    }

    Order_In &putTradingCode(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 92, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t branchIDId(void)
    {
        return 12;
    }

    static SBE_CONSTEXPR const std::uint64_t branchIDSinceVersion(void)
    {
         return 0;
    }

    bool branchIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= branchIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t branchIDEncodingOffset(void)
    {
         return 107;
    }


    static const char *BranchIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char branchIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char branchIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char branchIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t branchIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t branchIDLength(void)
    {
        return 6;
    }

    const char *branchID(void) const
    {
        return (m_buffer + m_offset + 107);
    }

    char branchID(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for branchID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 107 + (index * 1))));
    }

    void branchID(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for branchID [E105]");
        }

        *((char *)(m_buffer + m_offset + 107 + (index * 1))) = (value);
    }

    std::uint64_t getBranchID(char *dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
             throw std::runtime_error("length too large for getBranchID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 107, length);
        return length;
    }

    Order_In &putBranchID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 107, src, 6);
        return *this;
    }

    std::string getBranchIDAsString() const
    {
        std::string result(m_buffer + m_offset + 107, 6);
        return result;
    }

    Order_In &putBranchID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 107, str.c_str(), 6);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t instrumentIDId(void)
    {
        return 13;
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
         return 113;
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
        return (m_buffer + m_offset + 113);
    }

    char instrumentID(const std::uint64_t index) const
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 113 + (index * 1))));
    }

    void instrumentID(const std::uint64_t index, const char value)
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E105]");
        }

        *((char *)(m_buffer + m_offset + 113 + (index * 1))) = (value);
    }

    std::uint64_t getInstrumentID(char *dst, const std::uint64_t length) const
    {
        if (length > 31)
        {
             throw std::runtime_error("length too large for getInstrumentID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 113, length);
        return length;
    }

    Order_In &putInstrumentID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 113, src, 31);
        return *this;
    }

    std::string getInstrumentIDAsString() const
    {
        std::string result(m_buffer + m_offset + 113, 31);
        return result;
    }

    Order_In &putInstrumentID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 113, str.c_str(), 31);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderPriceTypeId(void)
    {
        return 14;
    }

    static SBE_CONSTEXPR const std::uint64_t orderPriceTypeSinceVersion(void)
    {
         return 0;
    }

    bool orderPriceTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderPriceTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderPriceTypeEncodingOffset(void)
    {
         return 144;
    }


    static const char *OrderPriceTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderPriceTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderPriceTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderPriceTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderPriceTypeEncodingLength(void)
    {
        return 1;
    }

    char orderPriceType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 144)));
    }

    Order_In &orderPriceType(const char value)
    {
        *((char *)(m_buffer + m_offset + 144)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t combOffsetFlagId(void)
    {
        return 15;
    }

    static SBE_CONSTEXPR const std::uint64_t combOffsetFlagSinceVersion(void)
    {
         return 0;
    }

    bool combOffsetFlagInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= combOffsetFlagSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t combOffsetFlagEncodingOffset(void)
    {
         return 145;
    }


    static const char *CombOffsetFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char combOffsetFlagNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char combOffsetFlagMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char combOffsetFlagMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t combOffsetFlagEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t combOffsetFlagLength(void)
    {
        return 5;
    }

    const char *combOffsetFlag(void) const
    {
        return (m_buffer + m_offset + 145);
    }

    char combOffsetFlag(const std::uint64_t index) const
    {
        if (index >= 5)
        {
            throw std::runtime_error("index out of range for combOffsetFlag [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 145 + (index * 1))));
    }

    void combOffsetFlag(const std::uint64_t index, const char value)
    {
        if (index >= 5)
        {
            throw std::runtime_error("index out of range for combOffsetFlag [E105]");
        }

        *((char *)(m_buffer + m_offset + 145 + (index * 1))) = (value);
    }

    std::uint64_t getCombOffsetFlag(char *dst, const std::uint64_t length) const
    {
        if (length > 5)
        {
             throw std::runtime_error("length too large for getCombOffsetFlag [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 145, length);
        return length;
    }

    Order_In &putCombOffsetFlag(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 145, src, 5);
        return *this;
    }

    std::string getCombOffsetFlagAsString() const
    {
        std::string result(m_buffer + m_offset + 145, 5);
        return result;
    }

    Order_In &putCombOffsetFlag(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 145, str.c_str(), 5);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t combHedgeFlagId(void)
    {
        return 16;
    }

    static SBE_CONSTEXPR const std::uint64_t combHedgeFlagSinceVersion(void)
    {
         return 0;
    }

    bool combHedgeFlagInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= combHedgeFlagSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t combHedgeFlagEncodingOffset(void)
    {
         return 150;
    }


    static const char *CombHedgeFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char combHedgeFlagNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char combHedgeFlagMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char combHedgeFlagMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t combHedgeFlagEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t combHedgeFlagLength(void)
    {
        return 5;
    }

    const char *combHedgeFlag(void) const
    {
        return (m_buffer + m_offset + 150);
    }

    char combHedgeFlag(const std::uint64_t index) const
    {
        if (index >= 5)
        {
            throw std::runtime_error("index out of range for combHedgeFlag [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 150 + (index * 1))));
    }

    void combHedgeFlag(const std::uint64_t index, const char value)
    {
        if (index >= 5)
        {
            throw std::runtime_error("index out of range for combHedgeFlag [E105]");
        }

        *((char *)(m_buffer + m_offset + 150 + (index * 1))) = (value);
    }

    std::uint64_t getCombHedgeFlag(char *dst, const std::uint64_t length) const
    {
        if (length > 5)
        {
             throw std::runtime_error("length too large for getCombHedgeFlag [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 150, length);
        return length;
    }

    Order_In &putCombHedgeFlag(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 150, src, 5);
        return *this;
    }

    std::string getCombHedgeFlagAsString() const
    {
        std::string result(m_buffer + m_offset + 150, 5);
        return result;
    }

    Order_In &putCombHedgeFlag(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 150, str.c_str(), 5);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t coveredFlagId(void)
    {
        return 17;
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
         return 155;
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
        return (*((char *)(m_buffer + m_offset + 155)));
    }

    Order_In &coveredFlag(const char value)
    {
        *((char *)(m_buffer + m_offset + 155)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t limitPriceId(void)
    {
        return 18;
    }

    static SBE_CONSTEXPR const std::uint64_t limitPriceSinceVersion(void)
    {
         return 0;
    }

    bool limitPriceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= limitPriceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t limitPriceEncodingOffset(void)
    {
         return 156;
    }


    static const char *LimitPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double limitPriceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double limitPriceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double limitPriceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t limitPriceEncodingLength(void)
    {
        return 8;
    }

    double limitPrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 156)));
    }

    Order_In &limitPrice(const double value)
    {
        *((double *)(m_buffer + m_offset + 156)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t volumeTotalOriginalId(void)
    {
        return 19;
    }

    static SBE_CONSTEXPR const std::uint64_t volumeTotalOriginalSinceVersion(void)
    {
         return 0;
    }

    bool volumeTotalOriginalInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= volumeTotalOriginalSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t volumeTotalOriginalEncodingOffset(void)
    {
         return 164;
    }


    static const char *VolumeTotalOriginalMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t volumeTotalOriginalNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t volumeTotalOriginalMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t volumeTotalOriginalMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t volumeTotalOriginalEncodingLength(void)
    {
        return 4;
    }

    std::int32_t volumeTotalOriginal(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 164)));
    }

    Order_In &volumeTotalOriginal(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 164)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t timeConditionId(void)
    {
        return 20;
    }

    static SBE_CONSTEXPR const std::uint64_t timeConditionSinceVersion(void)
    {
         return 0;
    }

    bool timeConditionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= timeConditionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t timeConditionEncodingOffset(void)
    {
         return 168;
    }


    static const char *TimeConditionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char timeConditionNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char timeConditionMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char timeConditionMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t timeConditionEncodingLength(void)
    {
        return 1;
    }

    char timeCondition(void) const
    {
        return (*((char *)(m_buffer + m_offset + 168)));
    }

    Order_In &timeCondition(const char value)
    {
        *((char *)(m_buffer + m_offset + 168)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t volumeConditionId(void)
    {
        return 21;
    }

    static SBE_CONSTEXPR const std::uint64_t volumeConditionSinceVersion(void)
    {
         return 0;
    }

    bool volumeConditionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= volumeConditionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t volumeConditionEncodingOffset(void)
    {
         return 169;
    }


    static const char *VolumeConditionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char volumeConditionNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char volumeConditionMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char volumeConditionMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t volumeConditionEncodingLength(void)
    {
        return 1;
    }

    char volumeCondition(void) const
    {
        return (*((char *)(m_buffer + m_offset + 169)));
    }

    Order_In &volumeCondition(const char value)
    {
        *((char *)(m_buffer + m_offset + 169)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t minVolumeId(void)
    {
        return 22;
    }

    static SBE_CONSTEXPR const std::uint64_t minVolumeSinceVersion(void)
    {
         return 0;
    }

    bool minVolumeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= minVolumeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t minVolumeEncodingOffset(void)
    {
         return 170;
    }


    static const char *MinVolumeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t minVolumeNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t minVolumeMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t minVolumeMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t minVolumeEncodingLength(void)
    {
        return 4;
    }

    std::int32_t minVolume(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 170)));
    }

    Order_In &minVolume(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 170)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t contingentConditionId(void)
    {
        return 23;
    }

    static SBE_CONSTEXPR const std::uint64_t contingentConditionSinceVersion(void)
    {
         return 0;
    }

    bool contingentConditionInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= contingentConditionSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t contingentConditionEncodingOffset(void)
    {
         return 174;
    }


    static const char *ContingentConditionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char contingentConditionNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char contingentConditionMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char contingentConditionMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t contingentConditionEncodingLength(void)
    {
        return 1;
    }

    char contingentCondition(void) const
    {
        return (*((char *)(m_buffer + m_offset + 174)));
    }

    Order_In &contingentCondition(const char value)
    {
        *((char *)(m_buffer + m_offset + 174)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t stopPriceId(void)
    {
        return 24;
    }

    static SBE_CONSTEXPR const std::uint64_t stopPriceSinceVersion(void)
    {
         return 0;
    }

    bool stopPriceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= stopPriceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t stopPriceEncodingOffset(void)
    {
         return 175;
    }


    static const char *StopPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double stopPriceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double stopPriceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double stopPriceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t stopPriceEncodingLength(void)
    {
        return 8;
    }

    double stopPrice(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 175)));
    }

    Order_In &stopPrice(const double value)
    {
        *((double *)(m_buffer + m_offset + 175)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t requestIDId(void)
    {
        return 25;
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
         return 183;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 183)));
    }

    Order_In &requestID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 183)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t orderSysIDId(void)
    {
        return 26;
    }

    static SBE_CONSTEXPR const std::uint64_t orderSysIDSinceVersion(void)
    {
         return 0;
    }

    bool orderSysIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderSysIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderSysIDEncodingOffset(void)
    {
         return 187;
    }


    static const char *OrderSysIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderSysIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderSysIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderSysIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderSysIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t orderSysIDLength(void)
    {
        return 17;
    }

    const char *orderSysID(void) const
    {
        return (m_buffer + m_offset + 187);
    }

    char orderSysID(const std::uint64_t index) const
    {
        if (index >= 17)
        {
            throw std::runtime_error("index out of range for orderSysID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 187 + (index * 1))));
    }

    void orderSysID(const std::uint64_t index, const char value)
    {
        if (index >= 17)
        {
            throw std::runtime_error("index out of range for orderSysID [E105]");
        }

        *((char *)(m_buffer + m_offset + 187 + (index * 1))) = (value);
    }

    std::uint64_t getOrderSysID(char *dst, const std::uint64_t length) const
    {
        if (length > 17)
        {
             throw std::runtime_error("length too large for getOrderSysID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 187, length);
        return length;
    }

    Order_In &putOrderSysID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 187, src, 17);
        return *this;
    }

    std::string getOrderSysIDAsString() const
    {
        std::string result(m_buffer + m_offset + 187, 17);
        return result;
    }

    Order_In &putOrderSysID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 187, str.c_str(), 17);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderStatusId(void)
    {
        return 27;
    }

    static SBE_CONSTEXPR const std::uint64_t orderStatusSinceVersion(void)
    {
         return 0;
    }

    bool orderStatusInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderStatusSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderStatusEncodingOffset(void)
    {
         return 204;
    }


    static const char *OrderStatusMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderStatusNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderStatusMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderStatusMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderStatusEncodingLength(void)
    {
        return 1;
    }

    char orderStatus(void) const
    {
        return (*((char *)(m_buffer + m_offset + 204)));
    }

    Order_In &orderStatus(const char value)
    {
        *((char *)(m_buffer + m_offset + 204)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t orderTypeId(void)
    {
        return 28;
    }

    static SBE_CONSTEXPR const std::uint64_t orderTypeSinceVersion(void)
    {
         return 0;
    }

    bool orderTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderTypeEncodingOffset(void)
    {
         return 205;
    }


    static const char *OrderTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderTypeEncodingLength(void)
    {
        return 1;
    }

    char orderType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 205)));
    }

    Order_In &orderType(const char value)
    {
        *((char *)(m_buffer + m_offset + 205)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t volumeTradedId(void)
    {
        return 29;
    }

    static SBE_CONSTEXPR const std::uint64_t volumeTradedSinceVersion(void)
    {
         return 0;
    }

    bool volumeTradedInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= volumeTradedSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t volumeTradedEncodingOffset(void)
    {
         return 206;
    }


    static const char *VolumeTradedMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t volumeTradedNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t volumeTradedMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t volumeTradedMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t volumeTradedEncodingLength(void)
    {
        return 4;
    }

    std::int32_t volumeTraded(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 206)));
    }

    Order_In &volumeTraded(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 206)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t amountTradedId(void)
    {
        return 30;
    }

    static SBE_CONSTEXPR const std::uint64_t amountTradedSinceVersion(void)
    {
         return 0;
    }

    bool amountTradedInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= amountTradedSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t amountTradedEncodingOffset(void)
    {
         return 210;
    }


    static const char *AmountTradedMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double amountTradedNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double amountTradedMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double amountTradedMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t amountTradedEncodingLength(void)
    {
        return 8;
    }

    double amountTraded(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 210)));
    }

    Order_In &amountTraded(const double value)
    {
        *((double *)(m_buffer + m_offset + 210)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t volumeRemainId(void)
    {
        return 31;
    }

    static SBE_CONSTEXPR const std::uint64_t volumeRemainSinceVersion(void)
    {
         return 0;
    }

    bool volumeRemainInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= volumeRemainSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t volumeRemainEncodingOffset(void)
    {
         return 218;
    }


    static const char *VolumeRemainMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t volumeRemainNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t volumeRemainMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t volumeRemainMaxValue()
    {
        return 2147483647;
    }

    static SBE_CONSTEXPR const std::size_t volumeRemainEncodingLength(void)
    {
        return 4;
    }

    std::int32_t volumeRemain(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 218)));
    }

    Order_In &volumeRemain(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 218)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t insertDateId(void)
    {
        return 32;
    }

    static SBE_CONSTEXPR const std::uint64_t insertDateSinceVersion(void)
    {
         return 0;
    }

    bool insertDateInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= insertDateSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t insertDateEncodingOffset(void)
    {
         return 222;
    }


    static const char *InsertDateMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char insertDateNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char insertDateMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char insertDateMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t insertDateEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t insertDateLength(void)
    {
        return 9;
    }

    const char *insertDate(void) const
    {
        return (m_buffer + m_offset + 222);
    }

    char insertDate(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for insertDate [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 222 + (index * 1))));
    }

    void insertDate(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for insertDate [E105]");
        }

        *((char *)(m_buffer + m_offset + 222 + (index * 1))) = (value);
    }

    std::uint64_t getInsertDate(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getInsertDate [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 222, length);
        return length;
    }

    Order_In &putInsertDate(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 222, src, 9);
        return *this;
    }

    std::string getInsertDateAsString() const
    {
        std::string result(m_buffer + m_offset + 222, 9);
        return result;
    }

    Order_In &putInsertDate(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 222, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t insertTimeId(void)
    {
        return 33;
    }

    static SBE_CONSTEXPR const std::uint64_t insertTimeSinceVersion(void)
    {
         return 0;
    }

    bool insertTimeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= insertTimeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t insertTimeEncodingOffset(void)
    {
         return 231;
    }


    static const char *InsertTimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char insertTimeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char insertTimeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char insertTimeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t insertTimeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t insertTimeLength(void)
    {
        return 10;
    }

    const char *insertTime(void) const
    {
        return (m_buffer + m_offset + 231);
    }

    char insertTime(const std::uint64_t index) const
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for insertTime [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 231 + (index * 1))));
    }

    void insertTime(const std::uint64_t index, const char value)
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for insertTime [E105]");
        }

        *((char *)(m_buffer + m_offset + 231 + (index * 1))) = (value);
    }

    std::uint64_t getInsertTime(char *dst, const std::uint64_t length) const
    {
        if (length > 10)
        {
             throw std::runtime_error("length too large for getInsertTime [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 231, length);
        return length;
    }

    Order_In &putInsertTime(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 231, src, 10);
        return *this;
    }

    std::string getInsertTimeAsString() const
    {
        std::string result(m_buffer + m_offset + 231, 10);
        return result;
    }

    Order_In &putInsertTime(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 231, str.c_str(), 10);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t updateTimeId(void)
    {
        return 34;
    }

    static SBE_CONSTEXPR const std::uint64_t updateTimeSinceVersion(void)
    {
         return 0;
    }

    bool updateTimeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= updateTimeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t updateTimeEncodingOffset(void)
    {
         return 241;
    }


    static const char *UpdateTimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char updateTimeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char updateTimeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char updateTimeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t updateTimeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t updateTimeLength(void)
    {
        return 10;
    }

    const char *updateTime(void) const
    {
        return (m_buffer + m_offset + 241);
    }

    char updateTime(const std::uint64_t index) const
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for updateTime [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 241 + (index * 1))));
    }

    void updateTime(const std::uint64_t index, const char value)
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for updateTime [E105]");
        }

        *((char *)(m_buffer + m_offset + 241 + (index * 1))) = (value);
    }

    std::uint64_t getUpdateTime(char *dst, const std::uint64_t length) const
    {
        if (length > 10)
        {
             throw std::runtime_error("length too large for getUpdateTime [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 241, length);
        return length;
    }

    Order_In &putUpdateTime(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 241, src, 10);
        return *this;
    }

    std::string getUpdateTimeAsString() const
    {
        std::string result(m_buffer + m_offset + 241, 10);
        return result;
    }

    Order_In &putUpdateTime(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 241, str.c_str(), 10);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t cancelTimeId(void)
    {
        return 35;
    }

    static SBE_CONSTEXPR const std::uint64_t cancelTimeSinceVersion(void)
    {
         return 0;
    }

    bool cancelTimeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= cancelTimeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t cancelTimeEncodingOffset(void)
    {
         return 251;
    }


    static const char *CancelTimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char cancelTimeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char cancelTimeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char cancelTimeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t cancelTimeEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t cancelTimeLength(void)
    {
        return 10;
    }

    const char *cancelTime(void) const
    {
        return (m_buffer + m_offset + 251);
    }

    char cancelTime(const std::uint64_t index) const
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for cancelTime [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 251 + (index * 1))));
    }

    void cancelTime(const std::uint64_t index, const char value)
    {
        if (index >= 10)
        {
            throw std::runtime_error("index out of range for cancelTime [E105]");
        }

        *((char *)(m_buffer + m_offset + 251 + (index * 1))) = (value);
    }

    std::uint64_t getCancelTime(char *dst, const std::uint64_t length) const
    {
        if (length > 10)
        {
             throw std::runtime_error("length too large for getCancelTime [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 251, length);
        return length;
    }

    Order_In &putCancelTime(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 251, src, 10);
        return *this;
    }

    std::string getCancelTimeAsString() const
    {
        std::string result(m_buffer + m_offset + 251, 10);
        return result;
    }

    Order_In &putCancelTime(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 251, str.c_str(), 10);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderActionRefId(void)
    {
        return 36;
    }

    static SBE_CONSTEXPR const std::uint64_t orderActionRefSinceVersion(void)
    {
         return 0;
    }

    bool orderActionRefInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= orderActionRefSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t orderActionRefEncodingOffset(void)
    {
         return 261;
    }


    static const char *OrderActionRefMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char orderActionRefNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char orderActionRefMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char orderActionRefMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t orderActionRefEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t orderActionRefLength(void)
    {
        return 11;
    }

    const char *orderActionRef(void) const
    {
        return (m_buffer + m_offset + 261);
    }

    char orderActionRef(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderActionRef [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 261 + (index * 1))));
    }

    void orderActionRef(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderActionRef [E105]");
        }

        *((char *)(m_buffer + m_offset + 261 + (index * 1))) = (value);
    }

    std::uint64_t getOrderActionRef(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getOrderActionRef [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 261, length);
        return length;
    }

    Order_In &putOrderActionRef(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 261, src, 11);
        return *this;
    }

    std::string getOrderActionRefAsString() const
    {
        std::string result(m_buffer + m_offset + 261, 11);
        return result;
    }

    Order_In &putOrderActionRef(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 261, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t statusMsgId(void)
    {
        return 37;
    }

    static SBE_CONSTEXPR const std::uint64_t statusMsgSinceVersion(void)
    {
         return 0;
    }

    bool statusMsgInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= statusMsgSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t statusMsgEncodingOffset(void)
    {
         return 272;
    }


    static const char *StatusMsgMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char statusMsgNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char statusMsgMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char statusMsgMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t statusMsgEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t statusMsgLength(void)
    {
        return 81;
    }

    const char *statusMsg(void) const
    {
        return (m_buffer + m_offset + 272);
    }

    char statusMsg(const std::uint64_t index) const
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for statusMsg [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 272 + (index * 1))));
    }

    void statusMsg(const std::uint64_t index, const char value)
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for statusMsg [E105]");
        }

        *((char *)(m_buffer + m_offset + 272 + (index * 1))) = (value);
    }

    std::uint64_t getStatusMsg(char *dst, const std::uint64_t length) const
    {
        if (length > 81)
        {
             throw std::runtime_error("length too large for getStatusMsg [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 272, length);
        return length;
    }

    Order_In &putStatusMsg(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 272, src, 81);
        return *this;
    }

    std::string getStatusMsgAsString() const
    {
        std::string result(m_buffer + m_offset + 272, 81);
        return result;
    }

    Order_In &putStatusMsg(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 272, str.c_str(), 81);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t ownerTypeId(void)
    {
        return 38;
    }

    static SBE_CONSTEXPR const std::uint64_t ownerTypeSinceVersion(void)
    {
         return 0;
    }

    bool ownerTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= ownerTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t ownerTypeEncodingOffset(void)
    {
         return 353;
    }


    static const char *OwnerTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char ownerTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char ownerTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char ownerTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t ownerTypeEncodingLength(void)
    {
        return 1;
    }

    char ownerType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 353)));
    }

    Order_In &ownerType(const char value)
    {
        *((char *)(m_buffer + m_offset + 353)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t thirdReff1Id(void)
    {
        return 39;
    }

    static SBE_CONSTEXPR const std::uint64_t thirdReff1SinceVersion(void)
    {
         return 0;
    }

    bool thirdReff1InActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= thirdReff1SinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t thirdReff1EncodingOffset(void)
    {
         return 354;
    }


    static const char *ThirdReff1MetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char thirdReff1NullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char thirdReff1MinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char thirdReff1MaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t thirdReff1EncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t thirdReff1Length(void)
    {
        return 21;
    }

    const char *thirdReff1(void) const
    {
        return (m_buffer + m_offset + 354);
    }

    char thirdReff1(const std::uint64_t index) const
    {
        if (index >= 21)
        {
            throw std::runtime_error("index out of range for thirdReff1 [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 354 + (index * 1))));
    }

    void thirdReff1(const std::uint64_t index, const char value)
    {
        if (index >= 21)
        {
            throw std::runtime_error("index out of range for thirdReff1 [E105]");
        }

        *((char *)(m_buffer + m_offset + 354 + (index * 1))) = (value);
    }

    std::uint64_t getThirdReff1(char *dst, const std::uint64_t length) const
    {
        if (length > 21)
        {
             throw std::runtime_error("length too large for getThirdReff1 [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 354, length);
        return length;
    }

    Order_In &putThirdReff1(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 354, src, 21);
        return *this;
    }

    std::string getThirdReff1AsString() const
    {
        std::string result(m_buffer + m_offset + 354, 21);
        return result;
    }

    Order_In &putThirdReff1(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 354, str.c_str(), 21);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t thirdReff2Id(void)
    {
        return 40;
    }

    static SBE_CONSTEXPR const std::uint64_t thirdReff2SinceVersion(void)
    {
         return 0;
    }

    bool thirdReff2InActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= thirdReff2SinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t thirdReff2EncodingOffset(void)
    {
         return 375;
    }


    static const char *ThirdReff2MetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char thirdReff2NullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char thirdReff2MinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char thirdReff2MaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t thirdReff2EncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t thirdReff2Length(void)
    {
        return 21;
    }

    const char *thirdReff2(void) const
    {
        return (m_buffer + m_offset + 375);
    }

    char thirdReff2(const std::uint64_t index) const
    {
        if (index >= 21)
        {
            throw std::runtime_error("index out of range for thirdReff2 [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 375 + (index * 1))));
    }

    void thirdReff2(const std::uint64_t index, const char value)
    {
        if (index >= 21)
        {
            throw std::runtime_error("index out of range for thirdReff2 [E105]");
        }

        *((char *)(m_buffer + m_offset + 375 + (index * 1))) = (value);
    }

    std::uint64_t getThirdReff2(char *dst, const std::uint64_t length) const
    {
        if (length > 21)
        {
             throw std::runtime_error("length too large for getThirdReff2 [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 375, length);
        return length;
    }

    Order_In &putThirdReff2(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 375, src, 21);
        return *this;
    }

    std::string getThirdReff2AsString() const
    {
        std::string result(m_buffer + m_offset + 375, 21);
        return result;
    }

    Order_In &putThirdReff2(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 375, str.c_str(), 21);
        return *this;
    }

};
}
}
}
#endif
