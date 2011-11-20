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
	${OBJECTDIR}/Stage.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Tile.o \
	${OBJECTDIR}/Bomber.o \
	${OBJECTDIR}/Level.o


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
LDLIBSOPTIONS=../Engine/dist/Release/GNU-Linux-x86/engine -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bomber

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bomber: ../Engine/dist/Release/GNU-Linux-x86/engine

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bomber: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bomber ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Stage.o: Stage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/Stage.o Stage.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Tile.o: Tile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tile.o Tile.cpp

${OBJECTDIR}/Bomber.o: Bomber.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bomber.o Bomber.cpp

${OBJECTDIR}/Level.o: Level.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/Level.o Level.cpp

# Subprojects
.build-subprojects:
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bomber

# Subprojects
.clean-subprojects:
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release clean
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
