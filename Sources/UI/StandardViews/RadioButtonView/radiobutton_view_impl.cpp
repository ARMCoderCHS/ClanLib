/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
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
**    Harry Storbacka
**    Magnus Norddahl
**    Mark Page
*/

#include "UI/precomp.h"
#include "API/UI/StandardViews/radiobutton_view.h"
#include "API/UI/Style/style_property_parser.h"
#include "API/Display/2D/path.h"
#include "API/Display/System/timer.h"
#include "API/Display/2D/brush.h"
#include "API/UI/Events/pointer_event.h"
#include <algorithm>
#include "radiobutton_view_impl.h"

namespace clan
{

	void RadioButtonView_Impl::update_state()
	{
		bool target_hot = false;
		bool target_disabled = false;
		bool target_pressed = false;

		if (_state_disabled)
		{
			target_disabled = true;
		}
		else if (_state_pressed)
		{
			target_pressed = true;
		}
		else if (_state_hot)
		{
			target_hot = true;
		}

		radio->set_state_cascade("hot", target_hot);
		radio->set_state_cascade("pressed", target_pressed);
		radio->set_state_cascade("disabled", target_disabled);
	}

	void RadioButtonView_Impl::on_pointer_press(PointerEvent &e)
	{
		if (_state_disabled)
			return;
		_state_pressed = true;
		update_state();
	}

	void RadioButtonView_Impl::on_pointer_release(PointerEvent &e)
	{
		if (_state_disabled)
			return;
		_state_pressed = false;
		update_state();
	}
}

