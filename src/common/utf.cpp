/*
 * Copyright (c) 2011 Sveriges Television AB <info@casparcg.com>
 *
 * This file is part of CasparCG (www.casparcg.com).
 *
 * CasparCG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CasparCG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CasparCG. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Robert Nagy, ronag89@gmail.com
 */
#include "utf.h"

#pragma warning(push, 1)

#include <boost/locale.hpp>

std::wstring u16(const std::string& str)
{
    return boost::locale::conv::utf_to_utf<wchar_t>(str); // std::wstring(str.begin(), str.end());
}

std::wstring u16(const std::wstring& str) { return str; }

std::string u8(const std::wstring& str)
{
    return boost::locale::conv::utf_to_utf<char>(str); // std::string(str.begin(), str.end());
}

std::string u8(const std::string& str) { return str; }
