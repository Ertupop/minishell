chmod 755 minishell
printf "\n\n\t\t\t\t\033[31;01m __  __ _____ _   _ _____  _____ _    _ ______ _      _      \033[00m\n"
printf "\t\t\t\t\033[31;01m|  \/  |_   _| \ | |_   _|/ ____| |  | |  ____| |    | |     \033[00m\n"
printf "\t\t\t\t\033[31;01m| \  / | | | |  \| | | | | (___ | |__| | |__  | |    | |     \033[00m\n"
printf "\t\t\t\t\033[31;01m| |\/| | | | | . \` | | |  \___ \|  __  |  __| | |    | |     \033[00m\n"
printf "\t\t\t\t\033[31;01m| |  | |_| |_| |\  |_| |_ ____) | |  | | |____| |____| |____ \033[00m\n"
printf "\t\t\t\t\033[31;01m|_|  |_|_____|_| \_|_____|_____/|_|  |_|______|______|______|\033[00m\n"
printf "\t\t\t\t\033[34;01m\t\t\t\t\t\t BY JULE-MER\033[00m\n\n"

#TESTS WITH ONLY 1 CMD AND ARGS
printf "\033[35;01m\n\t\t\t\t\t\tTESTS WITH ONLY 1 CMD AND ARGS\033[00m\n"

#TEST 1
printf "\033[32;01mTEST 1:\033[00m\n\n"
echo "echo" | ./minishell

#TEST 2
printf "\033[32;01m\n\nTEST 2:\033[00m\n\n"
echo "echo coucou" | ./minishell

#TEST 3
printf "\033[32;01m\n\nTEST 3:\033[00m\n\n"
echo "echo coucou toi" | ./minishell

#TEST 4
printf "\033[32;01m\n\nTEST 4:\033[00m\n\n"
echo "echo coucou toi ca" | ./minishell

#TEST 5
printf "\033[32;01m\n\nTEST 5:\033[00m\n\n"
echo "echo coucou toi ca va" | ./minishell

#TEST 6
printf "\033[32;01m\n\nTEST 6:\033[00m\n\n"
echo "echo coucou toi ca va ?" | ./minishell


#TESTS WITH ONLY 1 CMD, ARGS AND FILES
printf "\033[35;01m\n\n\n\t\t\t\t\t\tTESTS WITH ONLY 1 CMD, ARGS AND FILES\033[00m\n"

#TEST 1
printf "\033[32;01mTEST 1:\033[00m\n\n"
echo "echo > ici" | ./minishell

#TEST 2
printf "\033[32;01m\n\nTEST 2:\033[00m\n\n"
echo "echo > toi coucou > ici" | ./minishell

#TEST 3
printf "\033[32;01m\n\nTEST 3:\033[00m\n\n"
echo "echo coucou > ici toi" | ./minishell

#TEST 4
printf "\033[32;01m\n\nTEST 4:\033[00m\n\n"
echo "echo > ici coucou toi ca" | ./minishell

#TEST 5
printf "\033[32;01m\n\nTEST 5:\033[00m\n\n"
echo "echo coucou toi ca va > ici" | ./minishell

#TEST 6
printf "\033[32;01m\n\nTEST 6:\033[00m\n\n"
echo "echo coucou toi ca va > ici ?" | ./minishell
