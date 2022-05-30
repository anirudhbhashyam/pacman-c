CC=gcc
SRC="src"
OBJ="obj"
INC="include"
CFLAGS="-Wall -I${INC}"
EXECUTABLE=app

if [[ ! -d ${SRC} ]] || [[ -z $(ls -A ${SRC}) ]]; then
	echo "ERROR: Source directory ${SRC} does not exist or is empty."
	exit 0
fi

if [[ ! -d ${INC} ]] || [[ -z $(ls -A ${INC}) ]]; then
	echo "ERROR: Include directory ${INC} does not exist or is empty."
	exit 0
fi

SOURCES=$(find $SRC -name "*.c" -type f)
OBJECTS=$(echo ${SOURCES//${SRC}/${OBJ}} | sed 's/\.c/\.o/g')

if [[ ! -d ${OBJ} ]]; then
	mkdir ${OBJ}
fi

function clean() {
	rm -rf ${OBJECTS} ${EXECUTABLE}
}

echo "Cleaning..."
$(clean)

echo "Making object files..."
for src_file in $SOURCES
do 
	${CC} ${CFLAGS} -c ${src_file} -o $(echo ${src_file//${SRC}/${OBJ}} | sed 's/\.c/\.o/')
done 

echo "Making executable...${EXECUTABLE}"
${CC} ${OBJECTS} -o ${EXECUTABLE}
