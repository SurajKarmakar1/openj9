#ifndef VMJ9SERVER_H
#define VMJ9SERVER_H

#include "env/VMJ9.h"

class TR_J9ServerVM: public TR_J9VM
   {
public:
   TR_J9ServerVM(J9JITConfig *jitConfig, TR::CompilationInfo *compInfo, J9VMThread *vmContext)
      :TR_J9VM(jitConfig, compInfo, vmContext)
      {}

   virtual bool isAOT_DEPRECATED_DO_NOT_USE() override                   { return true; }
   virtual bool needClassAndMethodPointerRelocations() override          { return false; }
   virtual bool supportsCodeCacheSnippets() override                     { return false; }
   virtual bool canRelocateDirectNativeCalls() override                  { return false; }
   virtual bool inlinedAllocationsMustBeVerified() override              { return true; }
   virtual bool helpersNeedRelocation() override                         { return true; }
   virtual bool supportsEmbeddedHeapBounds() override                    { return false; }
   virtual bool supportsFastNanoTime() override                          { return false; }
   virtual bool needRelocationsForStatics() override                     { return true; }
   virtual bool forceUnresolvedDispatch() override                       { return true; }
   virtual bool nopsAlsoProcessedByRelocations() override                { return true; }
   virtual bool supportsGuardMerging() override                          { return false; }
   virtual bool canDevirtualizeDispatch() override                       { return false; }
   virtual bool storeOffsetToArgumentsInVirtualIndirectThunks() override { return true; }
   virtual bool callTargetsNeedRelocations() override                    { return true; }
   virtual bool doStringPeepholing() override                            { return false; }
   virtual bool hardwareProfilingInstructionsNeedRelocation() override   { return true; }
   virtual bool supportsMethodEntryPadding() override                    { return false; }
   virtual bool isBenefitInliningCheckIfFinalizeObject() override        { return true; }
   virtual bool needsContiguousAllocation() override                     { return true; }

   virtual bool traceableMethodsCanBeInlined() override                  { return true; }
   virtual bool methodsCanBeInlinedEvenIfEventHooksEnabled() override    { return true; }

   virtual bool isClassLibraryMethod(TR_OpaqueMethodBlock *method, bool vettedForAOT) override;
   virtual bool isClassLibraryClass(TR_OpaqueClassBlock *clazz) override;
   virtual TR_OpaqueClassBlock * getSuperClass(TR_OpaqueClassBlock *classPointer) override;
   virtual TR_Method * createMethod(TR_Memory *, TR_OpaqueClassBlock *, int32_t) override;
   virtual TR_ResolvedMethod * createResolvedMethod(TR_Memory * trMemory, TR_OpaqueMethodBlock * aMethod, TR_ResolvedMethod * owningMethod, TR_OpaqueClassBlock *classForNewInstance) override;
   virtual TR_ResolvedMethod * createResolvedMethodWithSignature(TR_Memory * trMemory, TR_OpaqueMethodBlock * aMethod, TR_OpaqueClassBlock *classForNewInstance,
                                                                 char *signature, int32_t signatureLength, TR_ResolvedMethod * owningMethod) override;
   virtual TR_YesNoMaybe isInstanceOf(TR_OpaqueClassBlock * a, TR_OpaqueClassBlock *b, bool objectTypeIsFixed, bool castTypeIsFixed, bool optimizeForAOT) override;
//   virtual bool isInterfaceClass(TR_OpaqueClassBlock *clazzPointer) override;
//   virtual bool isClassArray(TR_OpaqueClassBlock *) override;
//   virtual bool isClassFinal(TR_OpaqueClassBlock *) override;
//   virtual bool isAbstractClass(TR_OpaqueClassBlock *clazzPointer) override;
   virtual TR_OpaqueClassBlock * getSystemClassFromClassName(const char * name, int32_t length, bool isVettedForAOT) override;
   virtual bool isMethodEnterTracingEnabled(TR_OpaqueMethodBlock *method) override;
   virtual bool isMethodExitTracingEnabled(TR_OpaqueMethodBlock *method) override;
   virtual TR_OpaqueClassBlock * getClassClassPointer(TR_OpaqueClassBlock *objectClassPointer) override;
   virtual void * getClassLoader(TR_OpaqueClassBlock * classPointer) override;
   virtual TR_OpaqueClassBlock * getClassOfMethod(TR_OpaqueMethodBlock *method) override;
   virtual TR_OpaqueClassBlock * getBaseComponentClass(TR_OpaqueClassBlock * clazz, int32_t & numDims) override;
   virtual TR_OpaqueClassBlock * getLeafComponentClassFromArrayClass(TR_OpaqueClassBlock * arrayClass) override;
   virtual TR_OpaqueClassBlock * getClassFromSignature(const char *sig, int32_t length, TR_OpaqueMethodBlock *method, bool isVettedForAOT) override;
   virtual bool jitFieldsAreSame(TR_ResolvedMethod * method1, I_32 cpIndex1, TR_ResolvedMethod * method2, I_32 cpIndex2, int32_t isStatic) override;
   virtual bool jitStaticsAreSame(TR_ResolvedMethod *method1, I_32 cpIndex1, TR_ResolvedMethod *method2, I_32 cpIndex2) override;
   virtual TR_OpaqueClassBlock * getComponentClassFromArrayClass(TR_OpaqueClassBlock *arrayClass) override;
   virtual bool classHasBeenReplaced(TR_OpaqueClassBlock *) override;
   virtual bool classHasBeenExtended(TR_OpaqueClassBlock *) override;
   virtual bool compiledAsDLTBefore(TR_ResolvedMethod *) override;
//   virtual char * getClassNameChars(TR_OpaqueClassBlock *ramClass, int32_t & length) override;
   virtual uintptrj_t getOverflowSafeAllocSize() override;
   virtual bool isThunkArchetype(J9Method * method) override;
   virtual int32_t printTruncatedSignature(char *sigBuf, int32_t bufLen, TR_OpaqueMethodBlock *method) override;
//   virtual bool isPrimitiveClass(TR_OpaqueClassBlock * clazz) override;
   virtual bool isClassInitialized(TR_OpaqueClassBlock * clazz) override;
   virtual UDATA getOSRFrameSizeInBytes(TR_OpaqueMethodBlock * method) override;
   virtual int32_t getByteOffsetToLockword(TR_OpaqueClassBlock * clazz) override;
   virtual bool isString(TR_OpaqueClassBlock * clazz) override;
   virtual void * getMethods(TR_OpaqueClassBlock * clazz) override;
//   virtual uint32_t getNumMethods(TR_OpaqueClassBlock * clazz) override;
//   virtual uint32_t getNumInnerClasses(TR_OpaqueClassBlock * clazz) override;
   virtual bool isPrimitiveArray(TR_OpaqueClassBlock *clazz) override;
   virtual uint32_t getAllocationSize(TR::StaticSymbol *classSym, TR_OpaqueClassBlock *clazz) override;
   virtual TR_OpaqueClassBlock * getObjectClass(uintptrj_t objectPointer) override;
   virtual bool stackWalkerMaySkipFrames(TR_OpaqueMethodBlock *method, TR_OpaqueClassBlock *clazz) override;
   virtual bool hasFinalFieldsInClass(TR_OpaqueClassBlock *clazz) override;
   virtual const char *sampleSignature(TR_OpaqueMethodBlock * aMethod, char *buf, int32_t bufLen, TR_Memory *memory) override;
   virtual TR_OpaqueClassBlock * getHostClass(TR_OpaqueClassBlock *clazzOffset) override;
   virtual intptrj_t getStringUTF8Length(uintptrj_t objectPointer) override;
//   virtual uintptrj_t getPersistentClassPointerFromClassPointer(TR_OpaqueClassBlock *) override;
   virtual bool classInitIsFinished(TR_OpaqueClassBlock *) override;
   virtual TR_OpaqueClassBlock *getClassFromNewArrayType(int32_t arrayType) override;
   virtual bool isCloneable(TR_OpaqueClassBlock *clazzPointer) override;
   virtual bool canAllocateInlineClass(TR_OpaqueClassBlock *clazz) override;
   virtual TR_OpaqueClassBlock * getArrayClassFromComponentClass(TR_OpaqueClassBlock *componentClass) override;
   virtual J9Class * matchRAMclassFromROMclass(J9ROMClass *clazz, TR::Compilation *comp) override;
   virtual int32_t * getCurrentLocalsMapForDLT(TR::Compilation *comp) override;
   virtual uintptrj_t getReferenceFieldAtAddress(uintptrj_t fieldAddress) override;
   virtual uintptrj_t getVolatileReferenceFieldAt(uintptrj_t objectPointer, uintptrj_t fieldOffset) override;
   virtual int32_t getInt32FieldAt(uintptrj_t objectPointer, uintptrj_t fieldOffset) override;
   virtual int64_t getInt64FieldAt(uintptrj_t objectPointer, uintptrj_t fieldOffset) override;
   virtual void setInt64FieldAt(uintptrj_t objectPointer, uintptrj_t fieldOffset, int64_t newValue) override;
   virtual bool compareAndSwapInt64FieldAt(uintptrj_t objectPointer, uintptrj_t fieldOffset, int64_t oldValue, int64_t newValue) override;
   virtual intptrj_t getArrayLengthInElements(uintptrj_t objectPointer) override;
   virtual TR_OpaqueClassBlock * getClassFromJavaLangClass(uintptrj_t objectPointer) override;
   virtual UDATA getOffsetOfClassFromJavaLangClassField() override;
   virtual uintptrj_t getConstantPoolFromMethod(TR_OpaqueMethodBlock *method) override;
   virtual uintptrj_t getProcessID() override;
   virtual UDATA getIdentityHashSaltPolicy() override;
   virtual UDATA getOffsetOfJLThreadJ9Thread() override;
   virtual bool scanReferenceSlotsInClassForOffset(TR::Compilation *comp, TR_OpaqueClassBlock *clazz, int32_t offset) override;
   virtual int32_t findFirstHotFieldTenuredClassOffset(TR::Compilation *comp, TR_OpaqueClassBlock *clazz) override;
   virtual TR_OpaqueMethodBlock *getResolvedVirtualMethod(TR_OpaqueClassBlock * classObject, int32_t cpIndex, bool ignoreReResolve = true) override;
   virtual TR::CodeCache *getDesignatedCodeCache(TR::Compilation *comp) override;
   virtual uint8_t *allocateCodeMemory(TR::Compilation * comp, uint32_t warmCodeSize, uint32_t coldCodeSize, uint8_t ** coldCode, bool isMethodHeaderNeeded) override;
   virtual bool sameClassLoaders(TR_OpaqueClassBlock *, TR_OpaqueClassBlock *) override;
   virtual bool isUnloadAssumptionRequired(TR_OpaqueClassBlock *, TR_ResolvedMethod *) override;
   virtual void *setJ2IThunk(char *signatureChars, uint32_t signatureLength, void *thunkptr,  TR::Compilation *comp) override;
   virtual void scanClassForReservation (TR_OpaqueClassBlock *clazz, TR::Compilation *comp) override;
   virtual uint32_t getInstanceFieldOffset(TR_OpaqueClassBlock *clazz, char *fieldName, uint32_t fieldLen, char *sig, uint32_t sigLen, UDATA options) override;
   virtual int32_t getJavaLangClassHashCode(TR::Compilation *comp, TR_OpaqueClassBlock *clazz, bool &hashCodeComputed) override;
   virtual bool hasFinalizer(TR_OpaqueClassBlock *clazz) override;
   virtual uintptrj_t getClassDepthAndFlagsValue(TR_OpaqueClassBlock *clazz) override;
   virtual TR_OpaqueMethodBlock *getMethodFromName(char *className, char *methodName, char *signature, TR_OpaqueMethodBlock *callingMethod) override;
   virtual TR_OpaqueMethodBlock *getMethodFromClass(TR_OpaqueClassBlock *methodClass, char *methodName, char *signature, TR_OpaqueClassBlock *callingClass) override;
   virtual bool isClassVisible(TR_OpaqueClassBlock *sourceClass, TR_OpaqueClassBlock *destClass) override;
   };

#endif // VMJ9SERVER_H
