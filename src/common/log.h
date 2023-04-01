#pragma once

#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>

using boost_sev_logger = ::boost::log::sources::wseverity_logger<boost::log::trivial::severity_level>;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(logger, boost_sev_logger)

#define COMMON_LOG(lvl) BOOST_LOG_SEV(::logger::get(), boost::log::trivial::severity_level::lvl)