#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/sources/Scene.o \
	${OBJECTDIR}/sources/Object.o \
	${OBJECTDIR}/sources/Game.o \
	${OBJECTDIR}/sources/Log.o \
	${OBJECTDIR}/sources/Sprite.o \
	${OBJECTDIR}/sources/Layer.o \
	${OBJECTDIR}/sources/VideoManager.o \
	${OBJECTDIR}/sources/Vector.o \
	${OBJECTDIR}/sources/Image.o \
	${OBJECTDIR}/sources/InputManager.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/engine

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/engine: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/engine ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/sources/Scene.o: sources/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Scene.o sources/Scene.cpp

${OBJECTDIR}/sources/Object.o: sources/Object.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Object.o sources/Object.cpp

${OBJECTDIR}/sources/Game.o: sources/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Game.o sources/Game.cpp

${OBJECTDIR}/sources/Log.o: sources/Log.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Log.o sources/Log.cpp

${OBJECTDIR}/sources/Sprite.o: sources/Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Sprite.o sources/Sprite.cpp

${OBJECTDIR}/sources/Layer.o: sources/Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Layer.o sources/Layer.cpp

${OBJECTDIR}/sources/VideoManager.o: sources/VideoManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/VideoManager.o sources/VideoManager.cpp

${OBJECTDIR}/sources/Vector.o: sources/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Vector.o sources/Vector.cpp

${OBJECTDIR}/sources/Image.o: sources/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Image.o sources/Image.cpp

${OBJECTDIR}/sources/InputManager.o: sources/InputManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/InputManager.o sources/InputManager.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/engine

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
