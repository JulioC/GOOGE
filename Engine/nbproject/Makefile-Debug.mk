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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/sources/Scene.o \
	${OBJECTDIR}/sources/ImageManager.o \
	${OBJECTDIR}/sources/Object.o \
	${OBJECTDIR}/sources/Game.o \
	${OBJECTDIR}/sources/Log.o \
	${OBJECTDIR}/sources/Sprite.o \
	${OBJECTDIR}/sources/Surface.o \
	${OBJECTDIR}/sources/Text.o \
	${OBJECTDIR}/sources/Layer.o \
	${OBJECTDIR}/sources/VideoManager.o \
	${OBJECTDIR}/sources/Font.o \
	${OBJECTDIR}/sources/Vector.o \
	${OBJECTDIR}/sources/Label.o \
	${OBJECTDIR}/sources/TimeHandler.o \
	${OBJECTDIR}/sources/Image.o \
	${OBJECTDIR}/sources/InputManager.o \
	${OBJECTDIR}/sources/FontManager.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wall
CXXFLAGS=-Wall

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libengine.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libengine.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libengine.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libengine.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libengine.a

${OBJECTDIR}/sources/Scene.o: sources/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Scene.o sources/Scene.cpp

${OBJECTDIR}/sources/ImageManager.o: sources/ImageManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/ImageManager.o sources/ImageManager.cpp

${OBJECTDIR}/sources/Object.o: sources/Object.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Object.o sources/Object.cpp

${OBJECTDIR}/sources/Game.o: sources/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Game.o sources/Game.cpp

${OBJECTDIR}/sources/Log.o: sources/Log.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Log.o sources/Log.cpp

${OBJECTDIR}/sources/Sprite.o: sources/Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Sprite.o sources/Sprite.cpp

${OBJECTDIR}/sources/Surface.o: sources/Surface.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Surface.o sources/Surface.cpp

${OBJECTDIR}/sources/Text.o: sources/Text.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Text.o sources/Text.cpp

${OBJECTDIR}/sources/Layer.o: sources/Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Layer.o sources/Layer.cpp

${OBJECTDIR}/sources/VideoManager.o: sources/VideoManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/VideoManager.o sources/VideoManager.cpp

${OBJECTDIR}/sources/Font.o: sources/Font.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Font.o sources/Font.cpp

${OBJECTDIR}/sources/Vector.o: sources/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Vector.o sources/Vector.cpp

${OBJECTDIR}/sources/Label.o: sources/Label.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Label.o sources/Label.cpp

${OBJECTDIR}/sources/TimeHandler.o: sources/TimeHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/TimeHandler.o sources/TimeHandler.cpp

${OBJECTDIR}/sources/Image.o: sources/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/Image.o sources/Image.cpp

${OBJECTDIR}/sources/InputManager.o: sources/InputManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/InputManager.o sources/InputManager.cpp

${OBJECTDIR}/sources/FontManager.o: sources/FontManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} $@.d
	$(COMPILE.cc) -g -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/sources/FontManager.o sources/FontManager.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libengine.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
