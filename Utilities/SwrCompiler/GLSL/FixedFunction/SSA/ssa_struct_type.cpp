
#include "precomp.h"
#include "ssa_struct_type.h"
#include "ssa_scope.h"

using namespace clan;

void SSAStructType::add_parameter(llvm::Type *type)
{
	elements.push_back(type);
}

llvm::Type *SSAStructType::llvm_type()
{
	return llvm::StructType::get(SSAScope::context(), elements, false);
}

llvm::Type *SSAStructType::llvm_type_packed()
{
	return llvm::StructType::get(SSAScope::context(), elements, true);
}
