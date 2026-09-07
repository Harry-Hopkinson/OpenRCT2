/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include <compare>
#include <cstdio>

template<typename T, T TNullValue, typename TTag>
class TIdentifier
{
    enum class ValueType : T
    {
        null = TNullValue,
    } _handle;

private:
    explicit constexpr TIdentifier(const T index)
        : _handle{ static_cast<ValueType>(index) }
    {
    }

    explicit constexpr TIdentifier(const ValueType other)
        : _handle{ other }
    {
    }

public:
    using UnderlyingType = T;

    constexpr TIdentifier() = default;

    static constexpr TIdentifier getNull() noexcept
    {
        return TIdentifier{ ValueType::null };
    }

    static constexpr TIdentifier fromUnderlying(const T val) noexcept
    {
        return TIdentifier{ val };
    }

    constexpr T toUnderlying() const noexcept
    {
        return static_cast<T>(_handle);
    }

    // Support for static_cast<size_t>.
    explicit operator size_t() const noexcept
    {
        return static_cast<std::size_t>(toUnderlying());
    }

    constexpr bool isNull() const noexcept
    {
        return _handle == ValueType::null;
    }

    auto operator<=>(const TIdentifier&) const = default;
};
