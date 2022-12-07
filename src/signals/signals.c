#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

void	ft_set_termianl(void)
{
   struct termios    new_settings;

   if (tcgetattr(0, &new_settings))
       perror("minishell: tcsetattr");
   new_settings.c_lflag &= ~ECHOCTL;
   if (tcsetattr(0, 0, &new_settings))
       perror("minishell: tcsetattr");
}

void	ft_signal_handler(int sig, siginfo_t *siginfo, void *ignore)
{
  (void) siginfo;
  (void) ignore;

   if (sig == 2)
   {
      write(1, "\n", 2);
      rl_on_new_line();
      rl_clear_history();
      rl_replace_line("", 0);
      rl_redisplay();
      return ;
  }
  else if(sig == 3)
     rl_redisplay();
}

