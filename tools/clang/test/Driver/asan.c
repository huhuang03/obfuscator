// RUN: %clang     -target i386-unknown-unknown -faddress-sanitizer %s -S -emit-llvm -o - | FileCheck %s
// RUN: %clang -O1 -target i386-unknown-unknown -faddress-sanitizer %s -S -emit-llvm -o - | FileCheck %s
// RUN: %clang -O2 -target i386-unknown-unknown -faddress-sanitizer %s -S -emit-llvm -o - | FileCheck %s
// RUN: %clang -O3 -target i386-unknown-unknown -faddress-sanitizer %s -S -emit-llvm -o - | FileCheck %s
// Verify that -faddress-sanitizer invokes asan instrumentation.

// rdar://11496765
// -faddress-sanitizer is not currently supported.
// XFAIL: *

int foo(int *a) { return *a; }
// CHECK: __asan_init