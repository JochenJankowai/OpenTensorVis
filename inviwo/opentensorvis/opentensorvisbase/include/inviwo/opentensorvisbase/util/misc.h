/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2016-2020 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/

#pragma once

#include <inviwo/core/common/inviwo.h>

namespace inviwo {
namespace tensorutil {
namespace detail {
inline std::string getHTMLTableColumnString(const std::string& item,
                                            const std::string& hexColor = "#bbb") {
    return "  <td style='color:" + hexColor +
           ";padding-right:8px;'>"
           "  <span style=\"white-space: nowrap;\">" +
           item +
           "  </span>"
           "  </td>";
}

inline std::string getHTMLTableColumnSpanString(const std::string& item,
                                                const size_t numberOfColumnsToSpan) {
    return "  <td colspan=\"" + std::to_string(numberOfColumnsToSpan) +
           "\" style='color:#bbb;padding-right:8px;'>"
           "  <span style=\"white-space: nowrap;\">"
           "<strong>" +
           item +
           "</strong></span>"
           "</td>";
}
}  // namespace detail

inline std::string getHTMLTableRowString(const std::string& left, const std::string& right,
                                         const std::string& hexColor1 = "#bbb",
                                         const std::string& hexColor2 = "#bbb") {
    return "<tr>" + detail::getHTMLTableColumnString(left, hexColor1) +
           detail::getHTMLTableColumnString(right, hexColor2) + "</tr>";
}

template <std::size_t N, typename T>
inline std::string getHTMLTableRowString(const std::string& left,
                                         const glm::vec<N, T, glm::defaultp>& right) {
    return "<tr>" + detail::getHTMLTableColumnString(left) +
           detail::getHTMLTableColumnString(glm::to_string(right)) + "</tr>";
}

inline std::string getHTMLTableRowString(const std::string& left, const size_t right) {
    return "<tr>" + detail::getHTMLTableColumnString(left) +
           detail::getHTMLTableColumnString(std::to_string(right)) + "</tr>";
}

inline std::string getHTMLTableRowString(const std::string& left, const double right) {
    return "<tr>" + detail::getHTMLTableColumnString(left) +
           detail::getHTMLTableColumnString(std::to_string(right)) + "</tr>";
}

inline std::string getHTMLTableIntermediateHeaderString(const std::string& header,
                                                        size_t numberOfColumnsToSpan = 2) {
    return "<tr>" + detail::getHTMLTableColumnSpanString(header, numberOfColumnsToSpan) + "</tr>";
}

inline std::string colorToHTMLPreview(const dvec4& color) {
    return "<div style = \"background-color: rgba(" + std::to_string(color.r * 255) + "," +
           std::to_string(color.g * 255) + "," + std::to_string(color.b * 255) + "," +
           std::to_string(color.a * 255) + ");\">< / div>";
}

template <typename T>
T normalizeValue(const T& val, const T& minVal, const T& maxVal) {
    if (val >= maxVal) return T(1);
    if (val <= minVal) return T(0);
    return (val - minVal) / (maxVal - minVal);
}

template <typename T>
T denormalizeValue(const T& val, const T& minVal, const T& maxVal) {
    if (val <= T(0)) return minVal;
    if (val >= T(1)) return maxVal;
    return minVal + val * (maxVal - minVal);
}

template <typename T>
T nthRoot(T value, T n) {
    return std::pow(value, T(1) / n);
}



template <typename T>
std::string to_string(const T& list) {
    std::stringstream ss;
    ss << "[ ";

    if (list.empty()) {
        ss << ']';
        return ss.str();
    }

    for (const auto& val : list) {
        ss << std::to_string(val) << ", ";
    }

    auto str = ss.str();

    str[str.size() - 2] = ' ';
    str[str.size() - 1] = ']';

    return str;
}

template <typename T, size_t N>
std::string to_string(const std::array<T, N>& arr) {
    std::stringstream ss;
    ss << "[ ";

    for (size_t i{0}; i < N; ++i) {
        ss << std::to_string(arr[i]) << ", ";
    }

    auto str = ss.str();

    str[str.size() - 2] = ' ';
    str[str.size() - 1] = ']';

    return str;
}

}  // namespace tensorutil
}  // namespace inviwo
