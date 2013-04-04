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
**    Emanuel Greisen
*/

/// \addtogroup clanDisplay_Collision clanDisplay Collision
/// \{

#pragma once

#include "../api_display.h"
#include <vector>

namespace clan
{

class Pointf;
class OutlineCircle;

/// \brief Math operations on outlines
///
///  <p>This class provides general methods for calulating things on outlines.</p> 
class OutlineMath
{
/// \name Operations
/// \{

 public:
	/// \brief Find minimum spanning circle for the set of points
	///
	/// \param points the points to calulate on
	static OutlineCircle minimum_enclosing_disc(
		const std::vector<Pointf> &points);
	static void minimum_enclosing_disc(
		OutlineCircle &smalldisc,
		const std::vector<Pointf> &points);

 private:
	static void minimum_disc_with_1point(
		OutlineCircle &smalldisc,
		const std::vector<Pointf> &points,
		unsigned int i);
	static void minimum_disc_with_2points(
		OutlineCircle &smalldisc,
		const std::vector<Pointf> &points ,
		unsigned int i,
		unsigned int j);
	static void minimum_disc_with_3points(
		OutlineCircle &smalldisc,
		const std::vector<Pointf> &points ,
		unsigned int i,
		unsigned int j,
		unsigned int k);

public:
	static void minimum_enclosing_sub_circle(
		OutlineCircle &smalldisc,
		const std::vector<Pointf> &points,
		float maxradius);
private:
	static void minimum_enclosing_sub_circle_with_1point(
		OutlineCircle &smalldisc,
		const std::vector<Pointf> &points);
	static void minimum_enclosing_sub_circle_with_2points(
		OutlineCircle &smalldisc,
		const std::vector<Pointf> &points,
		unsigned int j);
/// \}
};

}

/// \}
