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
	${OBJECTDIR}/PlayerSprite.o \
	${OBJECTDIR}/Stage.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Sample.o \
	${OBJECTDIR}/Body.o \
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
LDLIBSOPTIONS=../Engine/dist/Debug/GNU-Linux-x86/libengine.a -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sample

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sample: ../Engine/dist/Debug/GNU-Linux-x86/libengine.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sample: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sample ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/PlayerSprite.o: PlayerSprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Engine/includes -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/PlayerSprite.o PlayerSprite.cpp

${OBJECTDIR}/Stage.o: Stage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Engine/includes -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Stage.o Stage.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Engine/includes -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Sample.o: Sample.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Engine/includes -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sample.o Sample.cpp

${OBJECTDIR}/Body.o: Body.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Engine/includes -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Body.o Body.cpp

${OBJECTDIR}/Level.o: Level.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Engine/includes -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Level.o Level.cpp

# Subprojects
.build-subprojects:
	cd ../Engine && ${MAKE}  -f Makefile CONF=Debug
	cd ../Engine && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sample

# Subprojects
.clean-subprojects:
	cd ../Engine && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../Engine && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
