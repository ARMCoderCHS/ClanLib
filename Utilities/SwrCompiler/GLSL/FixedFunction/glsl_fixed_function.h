
#pragma once

#include "SSA/ssa_vec4f.h"
#include "SSA/ssa_vec4i.h"
#include "SSA/ssa_vec8s.h"
#include "SSA/ssa_vec16ub.h"
#include "SSA/ssa_int.h"
#include "SSA/ssa_ubyte_ptr.h"
#include "SSA/ssa_vec4f_ptr.h"
#include "SSA/ssa_vec4i_ptr.h"
#include "SSA/ssa_pixels.h"
#include "SSA/ssa_stack.h"
#include "SSA/ssa_barycentric_weight.h"
#include "llvm_include.h"

class GlslProgram;
class GlslCodeGen;

class GlslFixedFunction
{
public:
	GlslFixedFunction(GlslProgram &program, GlslCodeGen &vertex_codegen, GlslCodeGen &fragment_codegen);
	void codegen();
	static llvm::Type *get_sampler_struct(llvm::LLVMContext &context);

private:
	void codegen_draw_triangles(int num_vertex_in, int num_vertex_out);
	void codegen_calc_window_positions();
	void codegen_calc_polygon_face_direction();
	void codegen_calc_polygon_y_range();
	void codegen_update_polygon_edge();
	void codegen_texture();
	void codegen_normalize();
	void codegen_reflect();
	void codegen_max();
	void codegen_pow();
	void codegen_dot();
	void codegen_mix();

	struct OuterData
	{
		OuterData() : sampler() { }

		SSAInt start;
		SSAInt end;
		SSAInt input_width;
		SSAInt input_height;
		SSAInt output_width;
		SSAInt output_height;
		SSAUBytePtr input_pixels;
		SSAUBytePtr output_pixels_line;

		SSAVec4fPtr sse_left_varying_in;
		SSAVec4fPtr sse_right_varying_in;
		int num_varyings;
		SSAVec4f viewport_x;
		SSAVec4f viewport_rcp_half_width;
		SSAVec4f dx;
		SSAVec4f dw;
		SSAVec4f v1w;
		SSAVec4f v1x;

		llvm::Value *sampler;
	};

	void render_polygon(
		SSAInt input_width,
		SSAInt input_height,
		SSAUBytePtr input_data,
		SSAInt output_width,
		SSAInt output_height,
		SSAUBytePtr output_data,
		SSAInt viewport_x,
		SSAInt viewport_y,
		SSAInt viewport_width,
		SSAInt viewport_height,
		SSAInt num_vertices,
		std::vector<SSAVec4fPtr> fragment_ins,
		SSAInt core,
		SSAInt num_cores);

	void codegen_render_scanline(int num_varyings);
	void process_first_pixels(OuterData &outer_data, SSAStack<SSAInt> &stack_x, SSAStack<SSAVec4f> &stack_xnormalized);
	void process_last_pixels(OuterData &outer_data, SSAStack<SSAInt> &stack_x, SSAStack<SSAVec4f> &stack_xnormalized);
	void inner_block(OuterData &data, SSAVec4f xnormalized, SSAVec4f *out_frag_colors);
	void blend(SSAVec4f frag_colors[4], SSAVec16ub &dest);

	GlslProgram &program;
	GlslCodeGen &vertex_codegen;
	GlslCodeGen &fragment_codegen;
};
