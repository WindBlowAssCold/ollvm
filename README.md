# ollvm
ollvm based on llvm_15.0.1, Hikari-ollvm, Armariris.

https://llvm.org  
https://github.com/61bcdefg/Hikari-LLVM15  
https://github.com/GoSSIP-SJTU/Armariris  

# Build

**ollvm编译**

1. cmake构建ninja build

```bash
cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS="clang" -DCMAKE_BUILD_TYPE=Release -DLLVM_INCLUDE_TESTS=OFF 

#  使用vscmd-x86编译llvm-x86
#  使用vscmd-x64编译llvm-x64

# before llvm 15
-DLLVM_ENABLE_NEW_PASS_MANAGER=OFF
# 只编译x86架构
-DLLVM_TARGETS_TO_BUILD=X86
# 动态链接来链接LLVM库,节省空间
-DBUILD_SHARED_LIBS=On

cmake --build build -j16
```

2. 使用vs build

```bash
mkdir build
cd build
cmake -DLLVM_ENABLE_PROJECTS=clang -G "Visual Studio 15 2017" -A x64 -Thost=x64 ..\llvm -DLLVM_TARGETS_TO_BUILD=X86
```


## Usage

```bash
The following flags are supported

# Enable Bogus Control Flow
-mllvm -enable-bcf (√)

# Enable Control Flow Flattening
-mllvm -enable-fla (√)

#Enable Basic Block Spliting
-mllvm -enable-split (√)

#Enable Instruction Substitution
-mllvm -enable-sub (√)

#Enable Register-Based Indirect Branching
-mllvm -enable-indibran (√)

#Enable String Encryption
-mllvm -enable-sobf (√)

#Enable Constant Encryption
-mllvm -enable-constenc (√)
```

## Advance

### BogusControlFlow

```bash

-bcf_onlyjunkasm
# 在虚假块中只插入花指令

-bcf_junkasm
# 在虚假块中插入花指令，干扰IDA对函数的识别。默认关闭

-bcf_junkasm_minnum
# 在虚假块中花指令的最小数量。默认为2

-bcf_junkasm_maxnum
# 在虚假块中花指令的最大数量。默认为4

-bcf_createfunc
# 使用函数封装不透明谓词。默认关闭
```

### ConstantEncryption

```bash
# 修改自https://iosre.com/t/llvm-llvm/11132

# 对能够处理的指令中使用的常量数字(ConstantInt)进行异或加密

-enable-constenc
#启用ConstantEncryption。默认关闭

-constenc_times
# ConstantEncryption在每个函数混淆的次数。默认为1

-constenc_prob
# 每个指令被ConstantEncryption混淆的概率。默认为50

-constenc_togv
# 将常量数字(ConstantInt)替换为全局变量，以及把类型为整数的二进制运算符(BinaryOperator)的运算结果替换为全局变量。默认关闭

-constenc_subxor
# 替换ConstantEncryption的异或运算，使其变得更加复杂

```

### StringEncryption

```bash

-strcry_prob
# 每个字符串中每个byte被加密的概率。默认为100。这个功能是为了给一些需要的加密强度不高，但是重视体积的人。
```

### IndirectBranch

```bash
-indibran-use-stack
# 将跳转表的地址在Entry Block加载到栈中，每个基本块再从栈中读取。默认关闭

-indibran-enc-jump-target
# 加密跳转表和索引。默认关闭
```

-adhexrirpath
# AntiHooking PreCompiled IR文件的路径
```
