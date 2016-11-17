if [[ $# -ne 2 ]];
	then echo "Erreur d'argument";
	exit 1;
fi
if [[ -x $2 ]];
	then rm $2;
fi
if grep -q "#include <math.h>" $1;
	then gcc -Wall -Wextra -ansi $1 -o $2 -lm;
	else gcc -Wall -Wextra -ansi $1 -o $2;
fi
if [[ -x $2 ]];
	then ./$2;
	else echo $2 "n'a pas été executé car la compilation a échouée ou il existe déjà et ce n'est pas un exécutable";
fi