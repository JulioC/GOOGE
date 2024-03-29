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
	${OBJECTDIR}/Box.o \
	${OBJECTDIR}/PlayerSprite.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/ShotSong.o \
	${OBJECTDIR}/MapLayer.o \
	${OBJECTDIR}/FirstLevel.o \
	${OBJECTDIR}/Level.o \
	${OBJECTDIR}/CoinSprite.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shotsong

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shotsong: ../Engine/dist/Release/GNU-Linux-x86/engine

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shotsong: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shotsong ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Box.o: Box.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box.o Box.cpp

${OBJECTDIR}/PlayerSprite.o: PlayerSprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/PlayerSprite.o PlayerSprite.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/ShotSong.o: ShotSong.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/ShotSong.o ShotSong.cpp

${OBJECTDIR}/MapLayer.o: MapLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/MapLayer.o MapLayer.cpp

${OBJECTDIR}/FirstLevel.o: FirstLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/FirstLevel.o FirstLevel.cpp

${OBJECTDIR}/Level.o: Level.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/Level.o Level.cpp

${OBJECTDIR}/CoinSprite.o: CoinSprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Engine/includes -Iincludes -MMD -MP -MF $@.d -o ${OBJECTDIR}/CoinSprite.o CoinSprite.cpp

# Subprojects
.build-subprojects:
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shotsong

# Subprojects
.clean-subprojects:
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release clean
	cd ../Engine && ${MAKE}  -f Makefile CONF=Release clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
