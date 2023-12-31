#ifndef _OBFUSCATION_H_
#define _OBFUSCATION_H_

#include "llvm/Support/Timer.h"
#include "llvm/Transforms/Obfuscation/BogusControlFlow.h"
#include "llvm/Transforms/Obfuscation/ConstantEncryption.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/Flattening.h"
#include "llvm/Transforms/Obfuscation/IndirectBranch.h"
#include "llvm/Transforms/Obfuscation/Split.h"
#include "llvm/Transforms/Obfuscation/StringEncryption.h"
#include "llvm/Transforms/Obfuscation/Substitution.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"

namespace llvm {

class ObfuscationPass : public PassInfoMixin<ObfuscationPass> {
public:
  ObfuscationPass() {}
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &MAM);
  static bool isRequired() { return true; }
};

ModulePass *createObfuscationLegacyPass();
void initializeObfuscationPass(PassRegistry &Registry);

} // namespace llvm

#endif
