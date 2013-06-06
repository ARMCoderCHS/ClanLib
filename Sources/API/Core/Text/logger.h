/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/


#pragma once

#include "../api_core.h"
#include "string_format.h"
#include "string_help.h"
#include "../System/mutex.h"

namespace clan
{
/// \addtogroup clanCore_Text clanCore Text
/// \{

/// \brief Logger interface.
class CL_API_CORE Logger
{
/// \name Construction
/// \{

public:
	/// \brief Constructs a logger.
	Logger();

	virtual ~Logger();

/// \}
/// \name Attributes
/// \{

public:
	/// \brief Pointers to currently enabled logger.
	static std::vector<Logger*> instances;

	/// \brief Logger mutex object.
	static Mutex mutex;

/// \}
/// \name Operations
/// \{

public:
	/// \brief Enable logger for logging.
	void enable();

	/// \brief Disable logging.
	void disable();

	/// \brief Log text.
	virtual void log(const std::string &type, const std::string &text);

/// \}
/// \name Implementation
/// \{

private:
/// \}
};

/// \brief Log text to logger.
///
CL_API_CORE void cl_log_event(const std::string &type, const std::string &text);

template <class Arg1>
void cl_log_event(const std::string &type, const std::string &format, Arg1 arg1)
{ StringFormat f(format); f.set_arg(1, arg1); cl_log_event(type, f.get_result()); }

template <class Arg1, class Arg2>
void cl_log_event(const std::string &type, const std::string &format, Arg1 arg1, Arg2 arg2)
{ StringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); cl_log_event(type, f.get_result()); }

template <class Arg1, class Arg2, class Arg3>
void cl_log_event(const std::string &type, const std::string &format, Arg1 arg1, Arg2 arg2, Arg3 arg3)
{ StringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); cl_log_event(type, f.get_result()); }

template <class Arg1, class Arg2, class Arg3, class Arg4>
void cl_log_event(const std::string &type, const std::string &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
{ StringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); cl_log_event(type, f.get_result()); }

template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
void cl_log_event(const std::string &type, const std::string &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
{ StringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); f.set_arg(5, arg5); cl_log_event(type, f.get_result()); }

template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6>
void cl_log_event(const std::string &type, const std::string &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
{ StringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); f.set_arg(5, arg5); f.set_arg(6, arg6); cl_log_event(type, f.get_result()); }

template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7>
void cl_log_event(const std::string &type, const std::string &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7)
{ StringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); f.set_arg(5, arg5); f.set_arg(6, arg6); f.set_arg(7, arg7); cl_log_event(type, f.get_result()); }

}

/// \}
