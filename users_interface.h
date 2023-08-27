#ifndef USERS_INTERFACE_H
#define USERS_INTERFACE_H

void          users_interface();
command_to_do get_command    ();

void    all_commands();
void solve_quad_prog();
void  colour_changer();

void   clear_stdin   ();
colour get_new_colour();

const int  STR_CMP_SUCCESS  = 0;
const char TEST_FILE_NAME[] = "TEST_PARAMETERS.txt";

#endif /*USERS_INTERFACE_H*/
