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
**    Magnus Norddahl
*/

#pragma once

#include "API/Display/TargetProviders/graphic_context_provider.h"
#include "API/Display/Render/depth_stencil_state_description.h"

namespace clan
{

class D3DDepthStencilStateProvider : public DepthStencilStateProvider
{
public:
	D3DDepthStencilStateProvider(const ComPtr<ID3D11Device> &device, const DepthStencilStateDescription &desc);

	ComPtr<ID3D11DepthStencilState> state;

private:
	static D3D11_STENCIL_OP to_d3d_stencil_op(StencilOp stencil_op);
	static D3D11_COMPARISON_FUNC to_d3d_compare_func(CompareFunction func);
};

}
