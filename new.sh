echo "Nombre del trabajo/proyecto:"
read project
echo "Nombre del programa:"
read program
# echo "Nombre del archivo .cpp:"
# read file

mkdir -p -- ./$project/$program
touch ./$project/$program/main.cpp

echo "#include <iostream>" >> ./$project/$program/main.cpp
echo "using namespace std;" >> ./$project/$program/main.cpp
echo "" >> ./$project/$program/main.cpp
echo "int main() {" >> ./$project/$program/main.cpp
echo "    return 0;" >> ./$project/$program/main.cpp
echo "}" >> ./$project/$program/main.cpp

echo "Archivo creado en ./$project/$program/main.cpp"