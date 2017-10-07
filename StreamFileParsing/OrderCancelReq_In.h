/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_ORDERCANCELREQ_IN_H_
#define _TFZQ_STP_TRADEOPT_ORDERCANCELREQ_IN_H_

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

class OrderCancelReq_In
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

    OrderCancelReq_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    OrderCancelReq_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    OrderCancelReq_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)115;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)20;
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

    OrderCancelReq_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    OrderCancelReq_In &wrapForDecode(
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

    OrderCancelReq_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 15);
        return result;
    }

    OrderCancelReq_In &putInvestorID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t instrumentIDId(void)
    {
        return 2;
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
         return 15;
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
        return (m_buffer + m_offset + 15);
    }

    char instrumentID(const std::uint64_t index) const
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 15 + (index * 1))));
    }

    void instrumentID(const std::uint64_t index, const char value)
    {
        if (index >= 31)
        {
            throw std::runtime_error("index out of range for instrumentID [E105]");
        }

        *((char *)(m_buffer + m_offset + 15 + (index * 1))) = (value);
    }

    std::uint64_t getInstrumentID(char *dst, const std::uint64_t length) const
    {
        if (length > 31)
        {
             throw std::runtime_error("length too large for getInstrumentID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 15, length);
        return length;
    }

    OrderCancelReq_In &putInstrumentID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 15, src, 31);
        return *this;
    }

    std::string getInstrumentIDAsString() const
    {
        std::string result(m_buffer + m_offset + 15, 31);
        return result;
    }

    OrderCancelReq_In &putInstrumentID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 15, str.c_str(), 31);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderActionRefId(void)
    {
        return 3;
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
         return 46;
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
        return (m_buffer + m_offset + 46);
    }

    char orderActionRef(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderActionRef [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 46 + (index * 1))));
    }

    void orderActionRef(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderActionRef [E105]");
        }

        *((char *)(m_buffer + m_offset + 46 + (index * 1))) = (value);
    }

    std::uint64_t getOrderActionRef(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getOrderActionRef [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 46, length);
        return length;
    }

    OrderCancelReq_In &putOrderActionRef(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 46, src, 11);
        return *this;
    }

    std::string getOrderActionRefAsString() const
    {
        std::string result(m_buffer + m_offset + 46, 11);
        return result;
    }

    OrderCancelReq_In &putOrderActionRef(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 46, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderRefId(void)
    {
        return 4;
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
         return 57;
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
        return (m_buffer + m_offset + 57);
    }

    char orderRef(const std::uint64_t index) const
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderRef [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 57 + (index * 1))));
    }

    void orderRef(const std::uint64_t index, const char value)
    {
        if (index >= 11)
        {
            throw std::runtime_error("index out of range for orderRef [E105]");
        }

        *((char *)(m_buffer + m_offset + 57 + (index * 1))) = (value);
    }

    std::uint64_t getOrderRef(char *dst, const std::uint64_t length) const
    {
        if (length > 11)
        {
             throw std::runtime_error("length too large for getOrderRef [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 57, length);
        return length;
    }

    OrderCancelReq_In &putOrderRef(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 57, src, 11);
        return *this;
    }

    std::string getOrderRefAsString() const
    {
        std::string result(m_buffer + m_offset + 57, 11);
        return result;
    }

    OrderCancelReq_In &putOrderRef(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 57, str.c_str(), 11);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t frontIDId(void)
    {
        return 5;
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
         return 68;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 68)));
    }

    OrderCancelReq_In &frontID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 68)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sessionIDId(void)
    {
        return 6;
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
         return 72;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 72)));
    }

    OrderCancelReq_In &sessionID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 72)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t exchangeIDId(void)
    {
        return 7;
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
         return 76;
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
        return (m_buffer + m_offset + 76);
    }

    char exchangeID(const std::uint64_t index) const
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 76 + (index * 1))));
    }

    void exchangeID(const std::uint64_t index, const char value)
    {
        if (index >= 9)
        {
            throw std::runtime_error("index out of range for exchangeID [E105]");
        }

        *((char *)(m_buffer + m_offset + 76 + (index * 1))) = (value);
    }

    std::uint64_t getExchangeID(char *dst, const std::uint64_t length) const
    {
        if (length > 9)
        {
             throw std::runtime_error("length too large for getExchangeID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 76, length);
        return length;
    }

    OrderCancelReq_In &putExchangeID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 76, src, 9);
        return *this;
    }

    std::string getExchangeIDAsString() const
    {
        std::string result(m_buffer + m_offset + 76, 9);
        return result;
    }

    OrderCancelReq_In &putExchangeID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 76, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderSysIDId(void)
    {
        return 8;
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
         return 85;
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
        return (m_buffer + m_offset + 85);
    }

    char orderSysID(const std::uint64_t index) const
    {
        if (index >= 17)
        {
            throw std::runtime_error("index out of range for orderSysID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 85 + (index * 1))));
    }

    void orderSysID(const std::uint64_t index, const char value)
    {
        if (index >= 17)
        {
            throw std::runtime_error("index out of range for orderSysID [E105]");
        }

        *((char *)(m_buffer + m_offset + 85 + (index * 1))) = (value);
    }

    std::uint64_t getOrderSysID(char *dst, const std::uint64_t length) const
    {
        if (length > 17)
        {
             throw std::runtime_error("length too large for getOrderSysID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 85, length);
        return length;
    }

    OrderCancelReq_In &putOrderSysID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 85, src, 17);
        return *this;
    }

    std::string getOrderSysIDAsString() const
    {
        std::string result(m_buffer + m_offset + 85, 17);
        return result;
    }

    OrderCancelReq_In &putOrderSysID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 85, str.c_str(), 17);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t orderLocalIDId(void)
    {
        return 9;
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
         return 102;
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
        return (m_buffer + m_offset + 102);
    }

    char orderLocalID(const std::uint64_t index) const
    {
        if (index >= 13)
        {
            throw std::runtime_error("index out of range for orderLocalID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 102 + (index * 1))));
    }

    void orderLocalID(const std::uint64_t index, const char value)
    {
        if (index >= 13)
        {
            throw std::runtime_error("index out of range for orderLocalID [E105]");
        }

        *((char *)(m_buffer + m_offset + 102 + (index * 1))) = (value);
    }

    std::uint64_t getOrderLocalID(char *dst, const std::uint64_t length) const
    {
        if (length > 13)
        {
             throw std::runtime_error("length too large for getOrderLocalID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 102, length);
        return length;
    }

    OrderCancelReq_In &putOrderLocalID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 102, src, 13);
        return *this;
    }

    std::string getOrderLocalIDAsString() const
    {
        std::string result(m_buffer + m_offset + 102, 13);
        return result;
    }

    OrderCancelReq_In &putOrderLocalID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 102, str.c_str(), 13);
        return *this;
    }

};
}
}
}
#endif
