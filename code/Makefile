# TINYXML_USE_STL can be used to turn on STL support. NO, then STL
# will not be used. YES will include the STL files.
TINYXML_USE_STL := YES

CXX    := g++
LD     := g++

CXXFLAGS     := -Wall -Wno-format -std=c++11

ifeq (YES, ${TINYXML_USE_STL})
  DEFS := -DTIXML_USE_STL
endif

CXXFLAGS := ${CXXFLAGS} ${DEFS}

#****************************************************************************
# Targets of the build
#****************************************************************************

OUTPUT := belote

all: ${OUTPUT} clean


#****************************************************************************
# Source files
#****************************************************************************

SRCS := tinyxml.cpp tinyxmlparser.cpp tinyxmlerror.cpp tinystr.cpp Belote.cpp Carte.cpp Couleur.cpp Joueur.cpp JoueurHumain.cpp JoueurIA.cpp OutputXML.cpp PaquetCartes.cpp Valeur.cpp main.cpp

OBJS := $(addsuffix .o,$(basename ${SRCS}))

#****************************************************************************
# Output
#****************************************************************************

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${OBJS}

#****************************************************************************
# common rules
#****************************************************************************

# Rules for compiling source files to object files
%.o : %.cpp
	${CXX} -c ${CXXFLAGS} $< -o $@

clean:
	-rm -f core ${OBJS}
