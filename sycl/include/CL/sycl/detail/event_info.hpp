//==---------------- event_info.hpp - SYCL event ---------------------------==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#pragma once

#include <CL/sycl/detail/common.hpp>
#include <CL/sycl/info/info_desc.hpp>

namespace cl {
namespace sycl {
namespace detail {

template <info::event_profiling Param> struct get_event_profiling_info {
  using RetType =
      typename info::param_traits<info::event_profiling, Param>::return_type;

  static RetType get(RT::PiEvent Event) {
    RetType Result = 0;
    // TODO catch an exception and put it to list of asynchronous exceptions
    PI_CALL(piEventGetProfilingInfo)(Event, cl_profiling_info(Param),
                                     sizeof(Result), &Result, nullptr);
    return Result;
  }
};

template <info::event Param> struct get_event_info {
  using RetType = typename info::param_traits<info::event, Param>::return_type;

  static RetType get(RT::PiEvent Event) {
    RetType Result = (RetType)0;
    // TODO catch an exception and put it to list of asynchronous exceptions
    PI_CALL(piEventGetInfo)(Event, cl_profiling_info(Param), sizeof(Result),
                            &Result, nullptr);
    return Result;
  }
};

} // namespace detail
} // namespace sycl
} // namespace cl
