/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _TFZQ_STP_TRADEOPT_ACCOUNT_IN_H_
#define _TFZQ_STP_TRADEOPT_ACCOUNT_IN_H_

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

class Account_In
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

    Account_In(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    Account_In(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    Account_In(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)216;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)5;
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

    Account_In &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    Account_In &wrapForDecode(
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

    Account_In &putTradingDay(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 0, src, 9);
        return *this;
    }

    std::string getTradingDayAsString() const
    {
        std::string result(m_buffer + m_offset + 0, 9);
        return result;
    }

    Account_In &putTradingDay(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 0, str.c_str(), 9);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t accountIDId(void)
    {
        return 2;
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
         return 9;
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
        return (m_buffer + m_offset + 9);
    }

    char accountID(const std::uint64_t index) const
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for accountID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 9 + (index * 1))));
    }

    void accountID(const std::uint64_t index, const char value)
    {
        if (index >= 15)
        {
            throw std::runtime_error("index out of range for accountID [E105]");
        }

        *((char *)(m_buffer + m_offset + 9 + (index * 1))) = (value);
    }

    std::uint64_t getAccountID(char *dst, const std::uint64_t length) const
    {
        if (length > 15)
        {
             throw std::runtime_error("length too large for getAccountID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 9, length);
        return length;
    }

    Account_In &putAccountID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 9, src, 15);
        return *this;
    }

    std::string getAccountIDAsString() const
    {
        std::string result(m_buffer + m_offset + 9, 15);
        return result;
    }

    Account_In &putAccountID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 9, str.c_str(), 15);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t currencyIDId(void)
    {
        return 3;
    }

    static SBE_CONSTEXPR const std::uint64_t currencyIDSinceVersion(void)
    {
         return 0;
    }

    bool currencyIDInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= currencyIDSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t currencyIDEncodingOffset(void)
    {
         return 24;
    }


    static const char *CurrencyIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char currencyIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char currencyIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char currencyIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t currencyIDEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t currencyIDLength(void)
    {
        return 4;
    }

    const char *currencyID(void) const
    {
        return (m_buffer + m_offset + 24);
    }

    char currencyID(const std::uint64_t index) const
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for currencyID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 24 + (index * 1))));
    }

    void currencyID(const std::uint64_t index, const char value)
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for currencyID [E105]");
        }

        *((char *)(m_buffer + m_offset + 24 + (index * 1))) = (value);
    }

    std::uint64_t getCurrencyID(char *dst, const std::uint64_t length) const
    {
        if (length > 4)
        {
             throw std::runtime_error("length too large for getCurrencyID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 24, length);
        return length;
    }

    Account_In &putCurrencyID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 24, src, 4);
        return *this;
    }

    std::string getCurrencyIDAsString() const
    {
        std::string result(m_buffer + m_offset + 24, 4);
        return result;
    }

    Account_In &putCurrencyID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 24, str.c_str(), 4);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t accountNameId(void)
    {
        return 4;
    }

    static SBE_CONSTEXPR const std::uint64_t accountNameSinceVersion(void)
    {
         return 0;
    }

    bool accountNameInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= accountNameSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t accountNameEncodingOffset(void)
    {
         return 28;
    }


    static const char *AccountNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const char accountNameNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char accountNameMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char accountNameMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::size_t accountNameEncodingLength(void)
    {
        return 1;
    }

    static SBE_CONSTEXPR const std::uint64_t accountNameLength(void)
    {
        return 51;
    }

    const char *accountName(void) const
    {
        return (m_buffer + m_offset + 28);
    }

    char accountName(const std::uint64_t index) const
    {
        if (index >= 51)
        {
            throw std::runtime_error("index out of range for accountName [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 28 + (index * 1))));
    }

    void accountName(const std::uint64_t index, const char value)
    {
        if (index >= 51)
        {
            throw std::runtime_error("index out of range for accountName [E105]");
        }

        *((char *)(m_buffer + m_offset + 28 + (index * 1))) = (value);
    }

    std::uint64_t getAccountName(char *dst, const std::uint64_t length) const
    {
        if (length > 51)
        {
             throw std::runtime_error("length too large for getAccountName [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 28, length);
        return length;
    }

    Account_In &putAccountName(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 28, src, 51);
        return *this;
    }

    std::string getAccountNameAsString() const
    {
        std::string result(m_buffer + m_offset + 28, 51);
        return result;
    }

    Account_In &putAccountName(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 28, str.c_str(), 51);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t preDepositId(void)
    {
        return 5;
    }

    static SBE_CONSTEXPR const std::uint64_t preDepositSinceVersion(void)
    {
         return 0;
    }

    bool preDepositInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= preDepositSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t preDepositEncodingOffset(void)
    {
         return 79;
    }


    static const char *PreDepositMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double preDepositNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double preDepositMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double preDepositMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t preDepositEncodingLength(void)
    {
        return 8;
    }

    double preDeposit(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 79)));
    }

    Account_In &preDeposit(const double value)
    {
        *((double *)(m_buffer + m_offset + 79)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t preMarginId(void)
    {
        return 6;
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
         return 87;
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 87)));
    }

    Account_In &preMargin(const double value)
    {
        *((double *)(m_buffer + m_offset + 87)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t preBalanceId(void)
    {
        return 7;
    }

    static SBE_CONSTEXPR const std::uint64_t preBalanceSinceVersion(void)
    {
         return 0;
    }

    bool preBalanceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= preBalanceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t preBalanceEncodingOffset(void)
    {
         return 95;
    }


    static const char *PreBalanceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double preBalanceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double preBalanceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double preBalanceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t preBalanceEncodingLength(void)
    {
        return 8;
    }

    double preBalance(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 95)));
    }

    Account_In &preBalance(const double value)
    {
        *((double *)(m_buffer + m_offset + 95)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t balanceId(void)
    {
        return 8;
    }

    static SBE_CONSTEXPR const std::uint64_t balanceSinceVersion(void)
    {
         return 0;
    }

    bool balanceInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= balanceSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t balanceEncodingOffset(void)
    {
         return 103;
    }


    static const char *BalanceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double balanceNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double balanceMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double balanceMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t balanceEncodingLength(void)
    {
        return 8;
    }

    double balance(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 103)));
    }

    Account_In &balance(const double value)
    {
        *((double *)(m_buffer + m_offset + 103)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t depositId(void)
    {
        return 9;
    }

    static SBE_CONSTEXPR const std::uint64_t depositSinceVersion(void)
    {
         return 0;
    }

    bool depositInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= depositSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t depositEncodingOffset(void)
    {
         return 111;
    }


    static const char *DepositMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double depositNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double depositMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double depositMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t depositEncodingLength(void)
    {
        return 8;
    }

    double deposit(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 111)));
    }

    Account_In &deposit(const double value)
    {
        *((double *)(m_buffer + m_offset + 111)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t frozenMarginId(void)
    {
        return 10;
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
         return 119;
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 119)));
    }

    Account_In &frozenMargin(const double value)
    {
        *((double *)(m_buffer + m_offset + 119)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t frozenCommissionId(void)
    {
        return 11;
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
         return 127;
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 127)));
    }

    Account_In &frozenCommission(const double value)
    {
        *((double *)(m_buffer + m_offset + 127)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t frozenCashId(void)
    {
        return 12;
    }

    static SBE_CONSTEXPR const std::uint64_t frozenCashSinceVersion(void)
    {
         return 0;
    }

    bool frozenCashInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= frozenCashSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t frozenCashEncodingOffset(void)
    {
         return 135;
    }


    static const char *FrozenCashMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double frozenCashNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double frozenCashMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double frozenCashMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t frozenCashEncodingLength(void)
    {
        return 8;
    }

    double frozenCash(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 135)));
    }

    Account_In &frozenCash(const double value)
    {
        *((double *)(m_buffer + m_offset + 135)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t useMarginId(void)
    {
        return 13;
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
         return 143;
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 143)));
    }

    Account_In &useMargin(const double value)
    {
        *((double *)(m_buffer + m_offset + 143)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t commissionId(void)
    {
        return 14;
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
         return 151;
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 151)));
    }

    Account_In &commission(const double value)
    {
        *((double *)(m_buffer + m_offset + 151)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t withdrawQuotaId(void)
    {
        return 15;
    }

    static SBE_CONSTEXPR const std::uint64_t withdrawQuotaSinceVersion(void)
    {
         return 0;
    }

    bool withdrawQuotaInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= withdrawQuotaSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t withdrawQuotaEncodingOffset(void)
    {
         return 159;
    }


    static const char *WithdrawQuotaMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double withdrawQuotaNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double withdrawQuotaMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double withdrawQuotaMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t withdrawQuotaEncodingLength(void)
    {
        return 8;
    }

    double withdrawQuota(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 159)));
    }

    Account_In &withdrawQuota(const double value)
    {
        *((double *)(m_buffer + m_offset + 159)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t creditId(void)
    {
        return 16;
    }

    static SBE_CONSTEXPR const std::uint64_t creditSinceVersion(void)
    {
         return 0;
    }

    bool creditInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= creditSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t creditEncodingOffset(void)
    {
         return 167;
    }


    static const char *CreditMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double creditNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double creditMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double creditMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t creditEncodingLength(void)
    {
        return 8;
    }

    double credit(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 167)));
    }

    Account_In &credit(const double value)
    {
        *((double *)(m_buffer + m_offset + 167)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t availableId(void)
    {
        return 17;
    }

    static SBE_CONSTEXPR const std::uint64_t availableSinceVersion(void)
    {
         return 0;
    }

    bool availableInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= availableSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t availableEncodingOffset(void)
    {
         return 175;
    }


    static const char *AvailableMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double availableNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double availableMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double availableMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t availableEncodingLength(void)
    {
        return 8;
    }

    double available(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 175)));
    }

    Account_In &available(const double value)
    {
        *((double *)(m_buffer + m_offset + 175)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t closeProfitId(void)
    {
        return 18;
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
         return 183;
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 183)));
    }

    Account_In &closeProfit(const double value)
    {
        *((double *)(m_buffer + m_offset + 183)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t positionProfitId(void)
    {
        return 19;
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
         return 191;
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 191)));
    }

    Account_In &positionProfit(const double value)
    {
        *((double *)(m_buffer + m_offset + 191)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t cashInId(void)
    {
        return 20;
    }

    static SBE_CONSTEXPR const std::uint64_t cashInSinceVersion(void)
    {
         return 0;
    }

    bool cashInInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= cashInSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t cashInEncodingOffset(void)
    {
         return 199;
    }


    static const char *CashInMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double cashInNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double cashInMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double cashInMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t cashInEncodingLength(void)
    {
        return 8;
    }

    double cashIn(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 199)));
    }

    Account_In &cashIn(const double value)
    {
        *((double *)(m_buffer + m_offset + 199)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t cashOutId(void)
    {
        return 21;
    }

    static SBE_CONSTEXPR const std::uint64_t cashOutSinceVersion(void)
    {
         return 0;
    }

    bool cashOutInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= cashOutSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t cashOutEncodingOffset(void)
    {
         return 207;
    }


    static const char *CashOutMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const double cashOutNullValue()
    {
        return SBE_DOUBLE_NAN;
    }

    static SBE_CONSTEXPR const double cashOutMinValue()
    {
        return 4.9E-324;
    }

    static SBE_CONSTEXPR const double cashOutMaxValue()
    {
        return 1.7976931348623157E308;
    }

    static SBE_CONSTEXPR const std::size_t cashOutEncodingLength(void)
    {
        return 8;
    }

    double cashOut(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((double *)(m_buffer + m_offset + 207)));
    }

    Account_In &cashOut(const double value)
    {
        *((double *)(m_buffer + m_offset + 207)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t isDefaultId(void)
    {
        return 22;
    }

    static SBE_CONSTEXPR const std::uint64_t isDefaultSinceVersion(void)
    {
         return 0;
    }

    bool isDefaultInActingVersion(void)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
        return m_actingVersion >= isDefaultSinceVersion();
#pragma GCC diagnostic pop
    }

    static SBE_CONSTEXPR const std::size_t isDefaultEncodingOffset(void)
    {
         return 215;
    }


    static const char *IsDefaultMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint8_t isDefaultNullValue()
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR const std::uint8_t isDefaultMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t isDefaultMaxValue()
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR const std::size_t isDefaultEncodingLength(void)
    {
        return 1;
    }

    std::uint8_t isDefault(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 215)));
    }

    Account_In &isDefault(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 215)) = (value);
        return *this;
    }
};
}
}
}
#endif
