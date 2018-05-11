L'ensemble de notre projet se compile à l'aide d'un CMake. Il faut donc créer un répertoire build, depuis lequel les commandes à lancer pour compiler sont :
 $cmake .. 
 $make

Une fois compilé, le programme principal s'exécute à l'aide de la commande $./test  qui ouvre la fenêtre permettant de visualiser l'océan modélisé. Le modèle choisi, ainsi que ses paramètres, sont à définir dans le fichier main.cxx, à l'initialisation du paramètre wm.
