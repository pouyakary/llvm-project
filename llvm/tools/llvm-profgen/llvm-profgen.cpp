//===- llvm-profgen.cpp - LLVM SPGO profile generation tool -----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// llvm-profgen generates SPGO profiles from perf script ouput.
//
//===----------------------------------------------------------------------===//

#include "ErrorHandling.h"
#include "PerfReader.h"
#include "ProfileGenerator.h"
#include "ProfiledBinary.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/TargetSelect.h"

static cl::OptionCategory ProfGenCategory("ProfGen Options");

static cl::list<std::string> PerfTraceFilenames(
    "perfscript", cl::value_desc("perfscript"), cl::OneOrMore,
    llvm::cl::MiscFlags::CommaSeparated,
    cl::desc("Path of perf-script trace created by Linux perf tool with "
             "`script` command(the raw perf.data should be profiled with -b)"),
    cl::cat(ProfGenCategory));

static cl::opt<std::string> BinaryPath(
    "binary", cl::value_desc("binary"), cl::Required,
    cl::desc("Path of profiled binary, only one binary is supported."),
    cl::cat(ProfGenCategory));

extern cl::opt<bool> ShowDisassemblyOnly;

using namespace llvm;
using namespace sampleprof;

int main(int argc, const char *argv[]) {
  InitLLVM X(argc, argv);

  // Initialize targets and assembly printers/parsers.
  InitializeAllTargetInfos();
  InitializeAllTargetMCs();
  InitializeAllDisassemblers();

  cl::HideUnrelatedOptions({&ProfGenCategory, &getColorCategory()});
  cl::ParseCommandLineOptions(argc, argv, "llvm SPGO profile generator\n");

  if (ShowDisassemblyOnly) {
    (void)ProfiledBinary(BinaryPath);
    return EXIT_SUCCESS;
  }

  // Load binaries and parse perf events and samples
  std::unique_ptr<PerfReaderBase> Reader =
      PerfReaderBase::create(BinaryPath, PerfTraceFilenames);
  Reader->parsePerfTraces(PerfTraceFilenames);

  std::unique_ptr<ProfileGenerator> Generator =
      ProfileGenerator::create(Reader->getBinary(), Reader->getSampleCounters(),
                               Reader->getPerfScriptType());
  Generator->generateProfile();
  Generator->write();

  return EXIT_SUCCESS;
}
