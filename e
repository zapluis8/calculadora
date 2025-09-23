#!/bin/bash #shebal con que se va a ejecutar el scrip

./create_project.sh proyecto #verificar el código compilar

#verificar si se asigna el nomrbe del proyecto
if[$# -eq 0]; then #si el valor es igual a 0 entonces no hay parametros
	echo "Error : Debe proporcionar el nombre del proyecto"
	echo "PE: $0 <nombre_proyecto>"
	eit 1
fi

NOMBRE_PROYECTO=$1 #Nombre del primer parámetro
DIR_PROYECTO="./$NOMBRE_PROYECTO" #obtenemos el nombre del proyecto $ para obtener el valor 

echo "Pro:'$NOMBRE_PROYECTO' " #Sustituir el valor dentro de una cadena
echo "Dir:'$DIR_PROYECTO'"

#Verificando que el directorio exista
if[-d "$DIR_PROYECTO"] then;
	echo"Error: El directorio '$NOMBRE_PROYECTO' ya existe"
	exit 1
fi

#Crear el directorio principal del proyecto
echo "Creando proyecto : $NOMBRE_PROYECTO"
mkdir -p "$DIR_PROYECTO" #-p para crear la ruta completa

#Crear los subdirectorios
mkdir -p "$DIR_PROYECTO/build"
mkdir -p "$DIR_PROYECTO/include"
mkdir -p "$DIR_PROYECTO/src"

#Crear el archivo CMakeLists
cat > "$DIR_PROYECTO/CMakeLists.txt" <<EOF 
cmake_minimun_required(VERSION 3.15)
Project($NOMBRE_PROYECTO)

#coNFIGURARNDO ESTANDAR EN C++
set(CMAKE_CXX_STANDAR 17)
set(CMAKE_CXX_STANDAR_REQUIRED ON)

#Configuracion del directorio de salida
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/bin)

#Incluir los headers
include_directories(include)

#Difinir archivos fuente
file(GLOB SOURCES "src/*.cpp)

#Crear el ejecutable
add_executable(\${PROJECT_NAME} \${SOURCES}) #\$ escapamos para tomar los otros 

target_include_directories(\${PROJECT_NAME} PUBLIC include)
EOF

#Creando el main con hola mundo
cat > "$DIR_PROYECTO/src/main.cpp" <<EOF

#include <iostream>
using namespace std;

int main(){

cout<<"Hola mundo automatico";

return 0;

}
EOF

#Crear scrip de build
cat > "$DIR_PROYECTO/compilar.sh" << EOF
#!/bin/bash //shebal con que se va a ejecutar el scrip
cd build && cmake .. && make
EOF

#Hacer compilar.sh ejecutable

chmod +x " $DIR_PROYECTO/compilar.sh"

echo "Proyecto '$NOMBRE_PROYECTO' creado exitosamente!"
echo "Estructura del proyecto
tree "$DIR_PROYECTO"

echo "Para compilar ejecutar: "
echo "./$NOMBRE_PROYECTO/compilar.sh "
