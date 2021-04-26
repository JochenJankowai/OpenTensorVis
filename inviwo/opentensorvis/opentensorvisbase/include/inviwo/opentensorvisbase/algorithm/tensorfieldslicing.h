/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2019-2020 Inviwo Foundation
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

#include <inviwo/opentensorvisbase/opentensorvisbasemoduledefine.h>
#include <inviwo/opentensorvisbase/datastructures/tensorfield2d.h>
#include <inviwo/opentensorvisbase/datastructures/tensorfield3d.h>
#include <inviwo/core/common/inviwo.h>
#include <inviwo/core/datastructures/geometry/geometrytype.h>

namespace inviwo {
namespace detail {
IVW_MODULE_OPENTENSORVISBASE_API std::shared_ptr<TensorField2D> getSlice2D(
    std::shared_ptr<const TensorField3D> inTensorField, const CartesianCoordinateAxis axis,
    const size_t sliceNumber);

IVW_MODULE_OPENTENSORVISBASE_API std::shared_ptr<TensorField3D> getSlice3D(
    std::shared_ptr<const TensorField3D> inTensorField, const CartesianCoordinateAxis axis,
    const size_t sliceNumber);
}  // namespace detail

template <unsigned int N>
auto slice(std::shared_ptr<const TensorField3D> inTensorField, const CartesianCoordinateAxis axis,
           const size_t sliceNumber) {
    if constexpr (N == 2) {
        return detail::getSlice2D(inTensorField, axis, sliceNumber);
    } else {
        return detail::getSlice3D(inTensorField, axis, sliceNumber);
    }
}
}  // namespace inviwo
