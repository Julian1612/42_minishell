#include <minishell.h>
#include <setjmp.h>
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

static void    set_termianl(void)
{
    struct termios    new_settings;

    if (tcgetattr(0, &new_settings))
        perror("minishell: tcsetattr");
    new_settings.c_lflag &= ~ECHOCTL;
    if (tcsetattr(0, 0, &new_settings))
        perror("minishell: tcsetattr");
}

void ft_signal_handler(int sig)
{
   // (void) siginfo;
   // (void) ignore;

   if (sig == 2)
   {
      write(1, "\n", 2);
      rl_on_new_line();
      rl_clear_history();
      rl_replace_line("", 0);
      rl_redisplay();
   }
   else if(sig == 3)
      rl_redisplay();
  return;
}

// int main(void)
// {
//    struct sigaction act;
//    act.sa_flags = SA_SIGINFO;
//    char *str;
//    act.sa_sigaction = ft_signal_handler;
//    sigaction(SIGQUIT, &act, 0);
//    sigaction(SIGINT, &act, 0);
//    ft_set_termianl();
//    while (1)
//    {
//       usleep(10);
//       str = readline("👉 ");
//       if (str == NULL)
//          exit(0);
//       free(str);
//    }
//    return 0;
// }
