#include <setjmp.h>
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

int done = 0;

void exitHandler( int sig, siginfo_t *siginfo, void *ignore )
{
   // printf("%d\n", sig);
   if (sig == 2)
   {
      write(1, "\n", 2);
      rl_on_new_line();
      rl_clear_history();
      rl_replace_line("", 0);
      rl_redisplay();
      write(1, "\033[s", 3);
      write(1, "\033[A", 3);
      write(1, "\b", 3);
      write(1, "\033[0K", 4);
      write(1, "\033[u", 3);

   }
   else if(sig == 3)
   {
      // write(1, "\33[2K", 4);
      write(1, "\033[s", 3);
      rl_on_new_line();
      rl_clear_history();
      rl_replace_line("", 0);
      rl_redisplay();
      write(1, "\033[u", 3);
   }
  return;
}

int main(void)
{
   struct sigaction act;
   act.sa_flags = SA_SIGINFO;
   char *str;
   act.sa_sigaction = exitHandler;
   sigaction(SIGQUIT, &act, 0);
   sigaction(SIGINT, &act, 0);
   while (1)
   {
      usleep(10);
      str = readline("$> ");
      if (str == NULL)
         exit(0);
      free(str);
   }
   return 0;
}
