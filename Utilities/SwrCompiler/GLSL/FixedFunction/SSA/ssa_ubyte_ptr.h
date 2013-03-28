
#pragma once

#include "ssa_ubyte.h"
#include "ssa_int.h"
#include "ssa_vec4i.h"
#include "ssa_vec8s.h"
#include "ssa_vec16ub.h"

namespace llvm { class Value; }
namespace llvm { class Type; }

class SSAUBytePtr
{
public:
	SSAUBytePtr();
	explicit SSAUBytePtr(llvm::Value *v);
	static SSAUBytePtr from_llvm(llvm::Value *v) { return SSAUBytePtr(v); }
	static llvm::Type *llvm_type();
	SSAUBytePtr operator[](SSAInt index) const;
	SSAUByte load() const;
	SSAVec4i load_vec4ub() const;
	SSAVec8s load_vec8s() const;
	SSAVec16ub load_vec16ub() const;
	SSAVec16ub load_unaligned_vec16ub() const;
	void store(const SSAUByte &new_value);
	void store_vec4ub(const SSAVec4i &new_value);
	void store_vec16ub(const SSAVec16ub &new_value);
	void store_unaligned_vec16ub(const SSAVec16ub &new_value);

	llvm::Value *v;
};
