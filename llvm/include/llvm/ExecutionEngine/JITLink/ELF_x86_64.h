//===--- ELF_x86_64.h - JIT link functions for ELF/x86-64 ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// jit-link functions for ELF/x86-64.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_EXECUTIONENGINE_JITLINK_ELF_X86_64_H
#define LLVM_EXECUTIONENGINE_JITLINK_ELF_X86_64_H

#include "llvm/ExecutionEngine/JITLink/JITLink.h"

namespace llvm {
namespace jitlink {

namespace ELF_x86_64_Edges {
enum ELFX86RelocationKind : Edge::Kind {
  Branch32 = Edge::FirstRelocation,
  Pointer64,
  PCRel32,
  PCRel32GOTLoad,
  PCRel32REXGOTLoad,
  PCRel64GOT,
  GOTOFF64,
  GOT64,
  Delta64,
};

} // end namespace ELF_x86_64_Edges

/// Create a LinkGraph from an ELF/x86-64 relocatable object.
///
/// Note: The graph does not take ownership of the underlying buffer, nor copy
/// its contents. The caller is responsible for ensuring that the object buffer
/// outlives the graph.
Expected<std::unique_ptr<LinkGraph>>
createLinkGraphFromELFObject_x86_64(MemoryBufferRef ObjectBuffer);

/// jit-link the given object buffer, which must be a ELF x86-64 object file.
void link_ELF_x86_64(std::unique_ptr<LinkGraph> G,
                     std::unique_ptr<JITLinkContext> Ctx);

/// Return the string name of the given ELF x86-64 edge kind.
const char *getELFX86RelocationKindName(Edge::Kind R);
} // end namespace jitlink
} // end namespace llvm

#endif // LLVM_EXECUTIONENGINE_JITLINK_ELF_X86_64_H
