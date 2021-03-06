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

#include "Core/precomp.h"
#include "API/Core/IOData/memory_device.h"
#include "iodevice_impl.h"
#include "iodevice_provider_memory.h"

namespace clan
{

/////////////////////////////////////////////////////////////////////////////
// MemoryDevice Construction:

MemoryDevice::MemoryDevice()
: IODevice(new IODeviceProvider_Memory())
{
}

MemoryDevice::MemoryDevice(DataBuffer &data)
: IODevice(new IODeviceProvider_Memory(data))
{
}

/////////////////////////////////////////////////////////////////////////////
// MemoryDevice Attributes:

const DataBuffer &MemoryDevice::get_data() const
{
	const IODeviceProvider_Memory *provider = dynamic_cast<const IODeviceProvider_Memory*>(impl->provider);
	return provider->get_data();
}

DataBuffer &MemoryDevice::get_data()
{
	IODeviceProvider_Memory *provider = dynamic_cast<IODeviceProvider_Memory*>(impl->provider);
	return provider->get_data();
}

/////////////////////////////////////////////////////////////////////////////
// MemoryDevice Operations:

/////////////////////////////////////////////////////////////////////////////
// MemoryDevice Implementation:

}
