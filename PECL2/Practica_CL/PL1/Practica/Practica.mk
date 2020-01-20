##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Practica
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/marco/Desktop/Practica_CL/PL1
ProjectPath            :=C:/Users/marco/Desktop/Practica_CL/PL1/Practica
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=marco
Date                   :=11/12/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Practica.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cliente.cpp$(ObjectSuffix) $(IntermediateDirectory)/ColaCliente.cpp$(ObjectSuffix) $(IntermediateDirectory)/Programa.cpp$(ObjectSuffix) $(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) $(IntermediateDirectory)/Nodo.cpp$(ObjectSuffix) $(IntermediateDirectory)/NodoArbol.cpp$(ObjectSuffix) $(IntermediateDirectory)/ArbolBinario.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Cliente.cpp$(ObjectSuffix): Cliente.cpp $(IntermediateDirectory)/Cliente.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/Cliente.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cliente.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cliente.cpp$(DependSuffix): Cliente.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Cliente.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Cliente.cpp$(DependSuffix) -MM Cliente.cpp

$(IntermediateDirectory)/Cliente.cpp$(PreprocessSuffix): Cliente.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cliente.cpp$(PreprocessSuffix) Cliente.cpp

$(IntermediateDirectory)/ColaCliente.cpp$(ObjectSuffix): ColaCliente.cpp $(IntermediateDirectory)/ColaCliente.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/ColaCliente.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ColaCliente.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ColaCliente.cpp$(DependSuffix): ColaCliente.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ColaCliente.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ColaCliente.cpp$(DependSuffix) -MM ColaCliente.cpp

$(IntermediateDirectory)/ColaCliente.cpp$(PreprocessSuffix): ColaCliente.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ColaCliente.cpp$(PreprocessSuffix) ColaCliente.cpp

$(IntermediateDirectory)/Programa.cpp$(ObjectSuffix): Programa.cpp $(IntermediateDirectory)/Programa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/Programa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Programa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Programa.cpp$(DependSuffix): Programa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Programa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Programa.cpp$(DependSuffix) -MM Programa.cpp

$(IntermediateDirectory)/Programa.cpp$(PreprocessSuffix): Programa.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Programa.cpp$(PreprocessSuffix) Programa.cpp

$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix): Lista.cpp $(IntermediateDirectory)/Lista.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/Lista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lista.cpp$(DependSuffix): Lista.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Lista.cpp$(DependSuffix) -MM Lista.cpp

$(IntermediateDirectory)/Lista.cpp$(PreprocessSuffix): Lista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lista.cpp$(PreprocessSuffix) Lista.cpp

$(IntermediateDirectory)/Nodo.cpp$(ObjectSuffix): Nodo.cpp $(IntermediateDirectory)/Nodo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/Nodo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Nodo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Nodo.cpp$(DependSuffix): Nodo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Nodo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Nodo.cpp$(DependSuffix) -MM Nodo.cpp

$(IntermediateDirectory)/Nodo.cpp$(PreprocessSuffix): Nodo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Nodo.cpp$(PreprocessSuffix) Nodo.cpp

$(IntermediateDirectory)/NodoArbol.cpp$(ObjectSuffix): NodoArbol.cpp $(IntermediateDirectory)/NodoArbol.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/NodoArbol.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoArbol.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NodoArbol.cpp$(DependSuffix): NodoArbol.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NodoArbol.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NodoArbol.cpp$(DependSuffix) -MM NodoArbol.cpp

$(IntermediateDirectory)/NodoArbol.cpp$(PreprocessSuffix): NodoArbol.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NodoArbol.cpp$(PreprocessSuffix) NodoArbol.cpp

$(IntermediateDirectory)/ArbolBinario.cpp$(ObjectSuffix): ArbolBinario.cpp $(IntermediateDirectory)/ArbolBinario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marco/Desktop/Practica_CL/PL1/Practica/ArbolBinario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ArbolBinario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ArbolBinario.cpp$(DependSuffix): ArbolBinario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ArbolBinario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ArbolBinario.cpp$(DependSuffix) -MM ArbolBinario.cpp

$(IntermediateDirectory)/ArbolBinario.cpp$(PreprocessSuffix): ArbolBinario.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ArbolBinario.cpp$(PreprocessSuffix) ArbolBinario.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


