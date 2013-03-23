
#include "precomp.h"
#include "ssa_vec4f_ptr.h"
#include "ssa_scope.h"
#include "llvm_include.h"

using namespace clan;

SSAVec4fPtr::SSAVec4fPtr()
: v(0)
{
}

SSAVec4fPtr::SSAVec4fPtr(llvm::Value *v)
: v(v)
{
}

llvm::Type *SSAVec4fPtr::llvm_type()
{
	return llvm::VectorType::get(llvm::Type::getFloatTy(SSAScope::context()), 4)->getPointerTo();
}

SSAVec4fPtr SSAVec4fPtr::operator[](SSAInt index) const
{
	return SSAVec4fPtr::from_llvm(SSAScope::builder().CreateGEP(v, index.v, SSAScope::hint()));
}

SSAVec4f SSAVec4fPtr::load() const
{
	return SSAVec4f::from_llvm(SSAScope::builder().CreateLoad(v, false, SSAScope::hint()));
}

SSAVec4f SSAVec4fPtr::load_unaligned() const
{
	return SSAVec4f::from_llvm(SSAScope::builder().Insert(new llvm::LoadInst(v, SSAScope::hint(), false, 4), SSAScope::hint()));
}

void SSAVec4fPtr::store(const SSAVec4f &new_value)
{
	SSAScope::builder().CreateStore(new_value.v, v, false);
}

void SSAVec4fPtr::store_unaligned(const SSAVec4f &new_value)
{
	llvm::Value *values[2] =
	{
		SSAScope::builder().CreateBitCast(v, llvm::Type::getFloatPtrTy(SSAScope::context())),
		new_value.v
	};
	SSAScope::builder().CreateCall(SSAScope::intrinsic(llvm::Intrinsic::x86_sse_storeu_ps), values);
}
