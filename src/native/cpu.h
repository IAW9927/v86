#pragma once

#include <stdint.h>

#include "shared.h"

void after_jump(void);
void diverged(void);
void branch_taken(void);
void branch_not_taken(void);
int32_t get_eflags(void);
int32_t translate_address_read(int32_t address);
int32_t translate_address_write(int32_t address);
int32_t read_imm8(void);
int32_t read_imm8s(void);
int32_t read_imm16(void);
int32_t read_imm32s(void);
bool is_osize_32(void);
bool is_asize_32(void);
int32_t get_seg(int32_t segment);
int32_t get_seg_prefix(int32_t default_segment);
int32_t get_seg_prefix_ds(int32_t offset);
int32_t get_seg_prefix_ss(int32_t offset);
int32_t get_seg_prefix_cs(int32_t offset);
int32_t modrm_resolve(int32_t modrm_byte);
uint32_t jit_hot_hash(uint32_t addr);
void generate_instruction(int32_t opcode);
void cycle_internal(void);
void run_prefix_instruction(void);
void jit_prefix_instruction(void);
void clear_prefixes(void);
void segment_prefix_op(int32_t seg);
void segment_prefix_op_jit(int32_t seg);
void do_many_cycles_unsafe(void);
void raise_exception(int32_t interrupt_nr);
void raise_exception_with_code(int32_t interrupt_nr, int32_t error_code);
void trigger_de(void);
void trigger_ud(void);
void trigger_nm(void);
void trigger_gp(int32_t code);
int32_t virt_boundary_read16(int32_t low, int32_t high);
int32_t virt_boundary_read32s(int32_t low, int32_t high);
void virt_boundary_write16(int32_t low, int32_t high, int32_t value);
void virt_boundary_write32(int32_t low, int32_t high, int32_t value);
int32_t safe_read8(int32_t addr);
int32_t safe_read16(int32_t addr);
int32_t safe_read32s(int32_t addr);
union reg64 safe_read64s(int32_t addr);
union reg128 safe_read128s(int32_t addr);
void safe_write8(int32_t addr, int32_t value);
void safe_write16(int32_t addr, int32_t value);
void safe_write32(int32_t addr, int32_t value);
void safe_write64(int32_t addr, int64_t value);
void safe_write128(int32_t addr, union reg128 value);
int32_t get_reg8_index(int32_t index);
int32_t read_reg8(int32_t index);
void write_reg8(int32_t index, int32_t value);
int32_t get_reg16_index(int32_t index);
int32_t read_reg16(int32_t index);
void write_reg16(int32_t index, int32_t value);
int32_t read_reg32(int32_t index);
void write_reg32(int32_t index, int32_t value);
void write_reg_osize(int32_t index, int32_t value);
int32_t read_mmx32s(int32_t r);
union reg64 read_mmx64s(int32_t r);
void write_mmx64(int32_t r, int32_t low, int32_t high);
void write_mmx_reg64(int32_t r, union reg64 data);
union reg64 read_xmm64s(int32_t r);
union reg128 read_xmm128s(int32_t r);
void write_xmm64(int32_t r, union reg64 data);
void write_xmm128(int32_t r, int32_t i0, int32_t i1, int32_t i2, int32_t i3);
void write_xmm_reg128(int32_t r, union reg128 data);
void clear_tlb(void);
void task_switch_test_mmx(void);
int32_t read_moffs(void);
int32_t get_real_eip(void);
int32_t get_stack_reg(void);
void set_stack_reg(int32_t value);
int32_t get_reg_asize(int32_t reg);
void set_ecx_asize(int32_t value);
void add_reg_asize(int32_t reg, int32_t value);
int32_t decr_ecx_asize(void);
uint64_t read_tsc(void);
