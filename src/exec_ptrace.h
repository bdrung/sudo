/*
 * Copyright (c) 2022 Todd C. Miller <Todd.Miller@sudo.ws>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef SUDO_EXEC_PTRACE_H
#define SUDO_EXEC_PTRACE_H

#include <elf.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <asm/unistd.h>
#include <linux/audit.h>
#include <linux/ptrace.h>
#include <linux/seccomp.h>
#include <linux/filter.h>

/* Older systems may not support execveat(2). */
#ifndef __NR_execveat
# define __NR_execveat	-1
#endif

/* In case userland doesn't define __X32_SYSCALL_BIT. */
#if defined(__x86_64__) && !defined(__X32_SYSCALL_BIT)
# define __X32_SYSCALL_BIT 0x40000000
#endif

/* Align address to a (native) word boundary. */
#define WORDALIGN(_a)	(((_a) + (sizeof(long) - 1L)) & ~(sizeof(long) - 1L))

/*
 * See syscall(2) for a list of registers used in system calls.
 * For example code, see tools/testing/selftests/seccomp/seccomp_bpf.c
 *
 * The structs and registers vary among the different platforms.
 * We define user_regs_struct as the struct to use for gettings
 * and setting the general registers and define accessor
 * macros to get/set the individual struct members.
 *
 * The value of SECCOMP_AUDIT_ARCH is used when matching the architecture
 * in the seccomp(2) filter.
 */
#if defined(__x86_64__)
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_X86_64
# define X32_execve		__X32_SYSCALL_BIT + 520
# define X32_execveat		__X32_SYSCALL_BIT + 545
# define user_pt_regs		user_regs_struct
# define reg_syscall(x)		(x).orig_rax
# define reg_retval(x)		(x).rax
# define reg_sp(x)		(x).rsp
# define reg_arg1(x)		(x).rdi
# define reg_arg2(x)		(x).rsi
# define reg_arg3(x)		(x).rdx
# define reg_arg4(x)		(x).r10
#elif defined(__aarch64__)
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_AARCH64
# define reg_syscall(x)		(x).regs[8]	/* w8 */
# define reg_retval(x)		(x).regs[0]	/* x0 */
# define reg_sp(x)		(x).sp		/* sp */
# define reg_arg1(x)		(x).regs[0]	/* x0 */
# define reg_arg2(x)		(x).regs[1]	/* x1 */
# define reg_arg3(x)		(x).regs[2]	/* x2 */
# define reg_arg4(x)		(x).regs[3]	/* x3 */
#elif defined(__arm__)
/* Note: assumes arm EABI, not OABI */
/* Untested */
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_ARM
# define user_pt_regs		pt_regs
# define reg_syscall(x)		(x).ARM_r7
# define reg_retval(x)		(x).ARM_r0
# define reg_sp(x)		(x).ARM_sp
# define reg_arg1(x)		(x).ARM_r0
# define reg_arg2(x)		(x).ARM_r1
# define reg_arg3(x)		(x).ARM_r2
# define reg_arg4(x)		(x).ARM_r3
#elif defined (__hppa__)
/* Untested (should also support hppa64) */
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_PARISC
# define user_pt_regs		user_regs_struct
# define reg_syscall(x)		(x).gr[20]	/* r20 */
# define reg_retval(x)		(x).gr[28]	/* r28 */
# define reg_sp(x)		(x).gr[30]	/* r30 */
# define reg_arg1(x)		(x).gr[26]	/* r26 */
# define reg_arg2(x)		(x).gr[25]	/* r25 */
# define reg_arg3(x)		(x).gr[24]	/* r24 */
# define reg_arg4(x)		(x).gr[23]	/* r23 */
#elif defined(__i386__)
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_I386
# define user_pt_regs		user_regs_struct
# define reg_syscall(x)		(x).orig_eax
# define reg_retval(x)		(x).eax
# define reg_sp(x)		(x).esp
# define reg_arg1(x)		(x).ebx
# define reg_arg2(x)		(x).ecx
# define reg_arg3(x)		(x).edx
# define reg_arg4(x)		(x).esi
#elif defined(__powerpc64__)
/* Untested */
# if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_PPC64LE
# else
#  define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_PPC64
# endif
# define user_pt_regs		pt_regs
# define reg_syscall(x)		(x).gpr[0]	/* r0 */
# define reg_retval(x)		(x).gpr[3]	/* r3 */
# define reg_sp(x)		(x).gpr[1]	/* r1 */
# define reg_arg1(x)		(x).gpr[3]	/* r3 */
# define reg_arg2(x)		(x).gpr[4]	/* r4 */
# define reg_arg3(x)		(x).gpr[5]	/* r5 */
# define reg_arg4(x)		(x).gpr[6]	/* r6 */
#elif defined(__powerpc__)
/* Untested */
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_PPC
# define user_pt_regs		pt_regs
# define reg_syscall(x)		(x).gpr[0]	/* r0 */
# define reg_retval(x)		(x).gpr[3]	/* r3 */
# define reg_sp(x)		(x).gpr[1]	/* r1 */
# define reg_arg1(x)		(x).gpr[3]	/* r3 */
# define reg_arg2(x)		(x).gpr[4]	/* r4 */
# define reg_arg3(x)		(x).gpr[5]	/* r5 */
# define reg_arg4(x)		(x).gpr[6]	/* r6 */
#elif defined(__riscv) && __riscv_xlen == 64
/* Untested */
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_RISCV64
# define user_pt_regs		user_regs_struct
# define reg_syscall(x)		(x).a7
# define reg_retval(x)		(x).a0
# define reg_sp(x)		(x).sp
# define reg_arg1(x)		(x).a0
# define reg_arg2(x)		(x).a1
# define reg_arg3(x)		(x).a2
# define reg_arg4(x)		(x).a3
#elif defined(__s390x__)
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_S390X
# define user_pt_regs		s390_regs
# define reg_syscall(x)		(x).gprs[1]	/* r1 */
# define reg_retval(x)		(x).gprs[2]	/* r2 */
# define reg_sp(x)		(x).gprs[15]	/* r15 */
# define reg_arg1(x)		(x).gprs[2]	/* r2 */
# define reg_arg2(x)		(x).gprs[3]	/* r3 */
# define reg_arg3(x)		(x).gprs[4]	/* r4 */
# define reg_arg4(x)		(x).gprs[5]	/* r6 */
#elif defined(__s390__)
# define SECCOMP_AUDIT_ARCH	AUDIT_ARCH_S390
# define user_pt_regs		s390_regs
# define reg_syscall(x)		(x).gprs[1]	/* r1 */
# define reg_retval(x)		(x).gprs[2]	/* r2 */
# define reg_sp(x)		(x).gprs[15]	/* r15 */
# define reg_arg1(x)		(x).gprs[2]	/* r2 */
# define reg_arg2(x)		(x).gprs[3]	/* r3 */
# define reg_arg3(x)		(x).gprs[4]	/* r4 */
# define reg_arg4(x)		(x).gprs[5]	/* r6 */
#else
# error "Do not know how to find your architecture's registers"
#endif

/*
 * Compat definitions for running 32-bit binaries on 64-bit platforms.
 * We must define the register struct too since there is no way to
 * get it directly from the system headers.
 *
 * The value of SECCOMP_AUDIT_ARCH_COMPAT is used when matching the
 * architecture in the seccomp(2) filter.  We can tell when the compat
 * arch matched by inspecting the message returned by PTRACE_GETEVENTMSG.
 */
#if defined(__x86_64__)
struct i386_user_regs_struct {
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int esi;
    unsigned int edi;
    unsigned int ebp;
    unsigned int eax;
    unsigned int xds;
    unsigned int xes;
    unsigned int xfs;
    unsigned int xgs;
    unsigned int orig_eax;
    unsigned int eip;
    unsigned int xcs;
    unsigned int eflags;
    unsigned int esp;
    unsigned int xss;
};
# define SECCOMP_AUDIT_ARCH_COMPAT	AUDIT_ARCH_I386
# define COMPAT_execve			11
# define COMPAT_execveat		358
# define compat_user_pt_regs		i386_user_regs_struct
# define compat_reg_syscall(x)		(x).orig_eax
# define compat_reg_retval(x)		(x).eax
# define compat_reg_sp(x)		(x).esp
# define compat_reg_arg1(x)		(x).ebx
# define compat_reg_arg2(x)		(x).ecx
# define compat_reg_arg3(x)		(x).edx
# define compat_reg_arg4(x)		(x).esi
#elif defined(__arm__)
struct arm_pt_regs {
  unsigned int uregs[18];
};
# define SECCOMP_AUDIT_ARCH_COMPAT	AUDIT_ARCH_ARM
# define COMPAT_execve			11
# define COMPAT_execveat		387
# define compat_user_pt_regs		arm_pt_regs
# define compat_reg_syscall(x)		(x).uregs[7]	/* r7 */
# define compat_reg_retval(x)		(x).uregs[0]	/* r0 */
# define compat_reg_sp(x)		(x).uregs[13]	/* r13 */
# define compat_reg_arg1(x)		(x).uregs[0]	/* r0 */
# define compat_reg_arg2(x)		(x).uregs[1]	/* r1 */
# define compat_reg_arg3(x)		(x).uregs[2]	/* r2 */
# define compat_reg_arg4(x)		(x).uregs[3]	/* r3 */
#endif

struct sudo_ptrace_regs {
    union {
	struct user_pt_regs native;
#ifdef SECCOMP_AUDIT_ARCH_COMPAT
	struct compat_user_pt_regs compat;
#endif
    } u;
    unsigned int wordsize;
    bool compat;
};

#endif /* SUDO_EXEC_PTRACE_H */
