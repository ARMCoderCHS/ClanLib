/*
**  ClanLib SDK
**  Copyright (c) 1997-2012 The ClanLib Team
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

/// \addtogroup clanDisplay_Display clanDisplay Display
/// \{

#pragma once

#include <memory>
#include "../api_display.h"

namespace clan
{

class ProgramUniform_Impl;

/// \brief OpenGL program object uniform variable.
class CL_API_DISPLAY ProgramUniform
{
/// \name Construction
/// \{

public:
	/// \brief Constructs a null instance.
	ProgramUniform();

	/// \brief Constructs a ProgramUniform
	///
	/// \param name = String Ref
	/// \param size = value
	/// \param type = value
	/// \param location = value
	ProgramUniform(const std::string &name, int size, int type, int location);

	~ProgramUniform();

/// \}
/// \name Attributes
/// \{

public:
	/// \brief Returns true if this object is invalid.
	bool is_null() const { return !impl; }

	/// \brief Throw an exception if this object is invalid.
	void throw_if_null() const;

	/// \brief Get uniform name.
	std::string get_name() const;

	/// \brief Get uniform OpenGL type.
	int get_type() const;

	/// \brief Get uniform size.
	int get_size() const;

	/// \brief Get uniform location.
	int get_location() const;

/// \}
/// \name Operations
/// \{

public:

/// \}
/// \name Implementation
/// \{

private:
	std::shared_ptr<ProgramUniform_Impl> impl;
/// \}
};

}

/// \}
