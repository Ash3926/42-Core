# Libft
### Technical Considerations:
- Declaring global variables is strictly forbidden.
- If you need helper functions to break down a more complex function, define them as static functions to restrict their scope to the appropriate file.
- All files must be placed at the root of your repository.
- Submitting unused files is not allowed.
- Every .c file must compile with the following flags: -Wall -Wextra -Werror.
- You must use the ar command to create your library. The use of libtool is strictly forbidden.
- Your libft.a must be created at the root of your repository.

Other Considerations, for the confused viewer:
- Each function must not use external functions unless stated otherwise.
- Norminette is applied, and the 42 Norme must be followed.

### How to run the program
- make/make all: creates the .o files and libft.a \n
- make clean: cleans .o files
- make fclean: cleans .o and libft.a files
- make bonus: creates the bonus .o files and adds them to libft.a
- make re: cleans all created files and remakes them (excluding bonus)
