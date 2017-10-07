/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_INVESTOR_IN_H_
#define _TFZQ_STP_TRADEOPT_INVESTOR_IN_H_

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

class Investor_In
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

    Investor_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    Investor_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    Investor_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)280;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)3;
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

    Investor_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    Investor_In &wrapForDecode(
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

    Investor_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    Investor_In &putTradingDay(const std::string& str)
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

    Investor_In &putInvestorID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 15);
        return *this;
    }

    std::string getInvestorIDAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 15);
        return result;
    }

    Investor_In &putInvestorID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 9, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t accountIDId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t accountIDSinceVersion(void)
    {
         return 0;
    }

    bool accountIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= accountIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t accountIDEncodingOffset(void)
    {
         return 24;
    }


    static const char *AccountIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char accountIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char accountIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char accountIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t accountIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t accountIDLength(void)
    {
        return 15;
    }

    const char *accountID(void) const
    {
        return (m_buffer + m_offset + 24);
    }

    char accountID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for accountID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 24 + (index * 1))));
    }

    void accountID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for accountID [E105]");
        }

        *((char *)(m_buffer + m_offset + 24 + (index * 1))) = (value);
    }

    std::uint64_t getAccountID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getAccountID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 24, length);
        return length;
    }

    Investor_In &putAccountID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 24, src, 15);
        return *this;
    }

    std::string getAccountIDAsString() const
    {
        std::string result(m_buffer + m_offset + 24, 15);
        return result;
    }

    Investor_In &putAccountID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 24, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t passwordId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t passwordSinceVersion(void)
    {
         return 0;
    }

    bool passwordInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= passwordSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t passwordEncodingOffset(void)
    {
         return 39;
    }


    static const char *PasswordMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char passwordNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char passwordMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char passwordMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t passwordEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t passwordLength(void)
    {
        return 41;
    }

    const char *password(void) const
    {
        return (m_buffer + m_offset + 39);
    }

    char password(const std::uint64_t index) const
    {
        if (index >= 41)
        {
            throw std::runtime_error("index out of range for password [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 39 + (index * 1))));
    }

    void password(const std::uint64_t index, const char value)
    {
        if (index >= 41)
        {
            throw std::runtime_error("index out of range for password [E105]");
        }

        *((char *)(m_buffer + m_offset + 39 + (index * 1))) = (value);
    }

    std::uint64_t getPassword(char *dst, const std::uint64_t length) const
    {
        if (length > 41)
        {
             throw std::runtime_error("length too large for getPassword [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 39, length);
        return length;
    }

    Investor_In &putPassword(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 39, src, 41);
        return *this;
    }

    std::string getPasswordAsString() const
    {
        std::string result(m_buffer + m_offset + 39, 41);
        return result;
    }

    Investor_In &putPassword(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 39, str.c_str(), 41);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t investorNameId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t investorNameSinceVersion(void)
    {
         return 0;
    }

    bool investorNameInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= investorNameSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t investorNameEncodingOffset(void)
    {
         return 80;
    }


    static const char *InvestorNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char investorNameNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char investorNameMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char investorNameMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t investorNameEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t investorNameLength(void)
    {
        return 81;
    }

    const char *investorName(void) const
    {
        return (m_buffer + m_offset + 80);
    }

    char investorName(const std::uint64_t index) const
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for investorName [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 80 + (index * 1))));
    }

    void investorName(const std::uint64_t index, const char value)
    {
        if (index >= 81)
        {
            throw std::runtime_error("index out of range for investorName [E105]");
        }

        *((char *)(m_buffer + m_offset + 80 + (index * 1))) = (value);
    }

    std::uint64_t getInvestorName(char *dst, const std::uint64_t length) const
    {
        if (length > 81)
        {
             throw std::runtime_error("length too large for getInvestorName [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 80, length);
        return length;
    }

    Investor_In &putInvestorName(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 80, src, 81);
        return *this;
    }

    std::string getInvestorNameAsString() const
    {
        std::string result(m_buffer + m_offset + 80, 81);
        return result;
    }

    Investor_In &putInvestorName(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 80, str.c_str(), 81);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t investorTypeId(void)
    {
        return 6;
    }

    static SBE_CONSTEXPR const std::uint64_t investorTypeSinceVersion(void)
    {
         return 0;
    }

    bool investorTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= investorTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t investorTypeEncodingOffset(void)
    {
         return 161;
    }


    static const char *InvestorTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char investorTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char investorTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char investorTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t investorTypeEncodingLength(void)
    {
        return 1;
    }

    char investorType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 161)));
    }

    Investor_In &investorType(const char value)
    {
        *((char *)(m_buffer + m_offset + 161)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t iDCardTypeId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t iDCardTypeSinceVersion(void)
    {
         return 0;
    }

    bool iDCardTypeInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= iDCardTypeSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t iDCardTypeEncodingOffset(void)
    {
         return 162;
    }


    static const char *IDCardTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char iDCardTypeNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char iDCardTypeMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char iDCardTypeMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t iDCardTypeEncodingLength(void)
    {
        return 1;
    }

    char iDCardType(void) const
    {
        return (*((char *)(m_buffer + m_offset + 162)));
    }

    Investor_In &iDCardType(const char value)
    {
        *((char *)(m_buffer + m_offset + 162)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t iDCardNoId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t iDCardNoSinceVersion(void)
    {
         return 0;
    }

    bool iDCardNoInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= iDCardNoSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t iDCardNoEncodingOffset(void)
    {
         return 163;
    }


    static const char *IDCardNoMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char iDCardNoNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char iDCardNoMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char iDCardNoMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t iDCardNoEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t iDCardNoLength(void)
    {
        return 101;
    }

    const char *iDCardNo(void) const
    {
        return (m_buffer + m_offset + 163);
    }

    char iDCardNo(const std::uint64_t index) const
    {
        if (index >= 101)
        {
            throw std::runtime_error("index out of range for iDCardNo [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 163 + (index * 1))));
    }

    void iDCardNo(const std::uint64_t index, const char value)
    {
        if (index >= 101)
        {
            throw std::runtime_error("index out of range for iDCardNo [E105]");
        }

        *((char *)(m_buffer + m_offset + 163 + (index * 1))) = (value);
    }

    std::uint64_t getIDCardNo(char *dst, const std::uint64_t length) const
    {
        if (length > 101)
        {
             throw std::runtime_error("length too large for getIDCardNo [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 163, length);
        return length;
    }

    Investor_In &putIDCardNo(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 163, src, 101);
        return *this;
    }

    std::string getIDCardNoAsString() const
    {
        std::string result(m_buffer + m_offset + 163, 101);
        return result;
    }

    Investor_In &putIDCardNo(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 163, str.c_str(), 101);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t isActiveId(void)
    {
        return 9;
    }

    static SBE_CONSTEXPR const std::uint64_t isActiveSinceVersion(void)
    {
         return 0;
    }

    bool isActiveInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= isActiveSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t isActiveEncodingOffset(void)
    {
         return 264;
    }


    static const char *IsActiveMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t isActiveNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t isActiveMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t isActiveMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t isActiveEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t isActive(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 264)));
    }

    Investor_In &isActive(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 264)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t groupIDId(void)
    {
        return 10;
    }

    static SBE_CONSTEXPR const std::uint64_t groupIDSinceVersion(void)
    {
         return 0;
    }

    bool groupIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= groupIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t groupIDEncodingOffset(void)
    {
         return 265;
    }


    static const char *GroupIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char groupIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char groupIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char groupIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t groupIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t groupIDLength(void)
    {
        return 15;
    }

    const char *groupID(void) const
    {
        return (m_buffer + m_offset + 265);
    }

    char groupID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for groupID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 265 + (index * 1))));
    }

    void groupID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for groupID [E105]");
        }

        *((char *)(m_buffer + m_offset + 265 + (index * 1))) = (value);
    }

    std::uint64_t getGroupID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getGroupID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 265, length);
        return length;
    }

    Investor_In &putGroupID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 265, src, 15);
        return *this;
    }

    std::string getGroupIDAsString() const
    {
        std::string result(m_buffer + m_offset + 265, 15);
        return result;
    }

    Investor_In &putGroupID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 265, str.c_str(), 15);
        return *this;
    }

};
}
}
}
#endif
