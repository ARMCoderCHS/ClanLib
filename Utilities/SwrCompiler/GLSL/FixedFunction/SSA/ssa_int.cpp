
#include "precomp.h"
#include "ssa_int.h"
#include "ssa_float.h"
#include "ssa_scope.h"
#include "llvm_include.h"

using namespace clan;

SSAInt::SSAInt()
: v(0)
{
}

SSAInt::SSAInt(int constant)
: v(0)
{
	v = llvm::ConstantInt::get(SSAScope::context(), llvm::APInt(32, constant, true));
}

SSAInt::SSAInt(SSAFloat f)
: v(0)
{
	v = SSAScope::builder().CreateFPToSI(f.v, llvm::Type::getInt32Ty(SSAScope::context()), SSAScope::hint());
}

SSAInt::SSAInt(llvm::Value *v)
: v(v)
{
}

llvm::Type *SSAInt::llvm_type()
{
	return llvm::Type::getInt32Ty(SSAScope::context());
}

SSAInt operator+(const SSAInt &a, const SSAInt &b)
{
	return SSAInt::from_llvm(SSAScope::builder().CreateAdd(a.v, b.v, SSAScope::hint()));
}

SSAInt operator-(const SSAInt &a, const SSAInt &b)
{
	return SSAInt::from_llvm(SSAScope::builder().CreateSub(a.v, b.v, SSAScope::hint()));
}

SSAInt operator*(const SSAInt &a, const SSAInt &b)
{
	return SSAInt::from_llvm(SSAScope::builder().CreateMul(a.v, b.v, SSAScope::hint()));
}

SSAInt operator/(const SSAInt &a, const SSAInt &b)
{
	return SSAInt::from_llvm(SSAScope::builder().CreateSDiv(a.v, b.v, SSAScope::hint()));
}

SSAInt operator%(const SSAInt &a, const SSAInt &b)
{
	return SSAInt::from_llvm(SSAScope::builder().CreateSRem(a.v, b.v, SSAScope::hint()));
}

SSAInt operator+(int a, const SSAInt &b)
{
	return SSAInt(a) + b;
}

SSAInt operator-(int a, const SSAInt &b)
{
	return SSAInt(a) - b;
}

SSAInt operator*(int a, const SSAInt &b)
{
	return SSAInt(a) * b;
}

SSAInt operator/(int a, const SSAInt &b)
{
	return SSAInt(a) / b;
}

SSAInt operator%(int a, const SSAInt &b)
{
	return SSAInt(a) % b;
}

SSAInt operator+(const SSAInt &a, int b)
{
	return a + SSAInt(b);
}

SSAInt operator-(const SSAInt &a, int b)
{
	return a - SSAInt(b);
}

SSAInt operator*(const SSAInt &a, int b)
{
	return a * SSAInt(b);
}

SSAInt operator/(const SSAInt &a, int b)
{
	return a / SSAInt(b);
}

SSAInt operator%(const SSAInt &a, int b)
{
	return a % SSAInt(b);
}

SSAInt operator<<(const SSAInt &a, int bits)
{
	return SSAInt::from_llvm(SSAScope::builder().CreateShl(a.v, bits, SSAScope::hint()));
}

SSAInt operator>>(const SSAInt &a, int bits)
{
	return SSAInt::from_llvm(SSAScope::builder().CreateLShr(a.v, bits, SSAScope::hint()));
}
