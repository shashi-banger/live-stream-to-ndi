#pragma once

#include <exception>
#include <boost/exception/all.hpp>
#include <boost/throw_exception.hpp>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <boost/stacktrace.hpp>

namespace ffmpeg {
struct ffmpeg_error_t : virtual boost::exception, virtual std::exception
{
};

using stacktrace_info_t = boost::error_info<struct tag_stacktrace_info, boost::stacktrace::stacktrace>;

}

#define THROW_ON_ERROR_STR_(call) #call
#define THROW_ON_ERROR_STR(call) THROW_ON_ERROR_STR_(call)

#define THROW_EXCEPTION(x)                                                                                      \
    ::boost::throw_exception(::boost::enable_error_info(x)                                                             \
                             << ::boost::throw_function(BOOST_CURRENT_FUNCTION) << ::boost::throw_file(__FILE__)       \
                             << ::boost::throw_line((int)__LINE__) << \
                             ffmpeg::stacktrace_info_t(::boost::stacktrace::stacktrace()))

#define FF_RET(ret, func)                                                                                              \
    if (ret < 0) {                                                                                                     \
        THROW_EXCEPTION(ffmpeg::ffmpeg_error_t()                                                        \
                               << boost::errinfo_api_function(func) \
                               << boost::errinfo_errno(AVUNERROR(ret)));                                               \
    }

#define FF(call)                                                                                                       \
    [&] {                                                                                                              \
        auto ret = call;                                                                                               \
        FF_RET(ret, THROW_ON_ERROR_STR(call));                                                                         \
    }()
